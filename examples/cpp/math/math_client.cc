/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "math.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientWriter;
using grpc::ClientReaderWriter;
using grpc::Status;
using math::MathOperations;
using math::Multiplicands;
using math::Addends;
using math::Result;

class MathOperationsClient {
 public:
  MathOperationsClient(std::shared_ptr<Channel> channel)
      : stub_(MathOperations::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.

  int64_t Multiplication(const int32_t& number1, const int32_t& number2) {
    // Data we are sending to the server
    Multiplicands request;
    request.set_multiplicand1(number1);
    request.set_multiplicand2(number2);

    // Container for the data we expect from the server
    Result reply;

    // Container for the client. It could be used to convey extra information to 
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    //The actual RPC
    Status status = stub_->Multiplication(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.mathresult();
    } else {
      // std::cout << status.error_code() << ": " << status.error_message()
      //           << std::endl;
      return 0;
    }
  }

  int64_t nthTriangularNumber() {
    int count = 10;
    int32_t counter = 1;
    Addends addend;
    ClientContext context;
    Result result;
    std::unique_ptr<ClientWriter<Addends>> writer(
        stub_->nthTriangularNumber(&context, &result));
    for(int i = 0; i < count; ++i) {
        addend.set_addend(counter++);
        if (!writer->Write(addend)) {
          //Broken stream
          break;
        }
    }
    writer->WritesDone();
    Status status = writer->Finish();
    if (status.ok()) {
      return result.mathresult();
    }
    else {
      std::cout << "Error writing to gRPC client stream" << std::endl;
      return 0;
    }
  }

  void AdditionPlusFive(std::vector<int64_t>& num) {
    ClientContext context;
    std::shared_ptr<ClientReaderWriter<Addends, Result>> stream(
      stub_->AdditionPlusFive(&context));
    
    for (int64_t number : num) {
      Addends addend;
      Result result;
      addend.set_addend(number);
      stream->Write(addend);
      if (stream->Read(&result)) {
        std::cout << result.mathresult() << std::endl;
      }
    }
    stream->WritesDone();
    Status status = stream->Finish();
    if (!status.ok()) {
      std::cout << "AdditionPlusFive rpc failed." << std::endl;
    }
  }

 private:
  std::unique_ptr<MathOperations::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target="
                  << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
    target_str = "localhost:50051";
  }
  MathOperationsClient mathr(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

  int64_t multiplicationResult = mathr.Multiplication(19, 100);
  int64_t nthTriNumResult = mathr.nthTriangularNumber();

  std::cout << "Mulitplication should be 190, is : " << multiplicationResult << std::endl;
  std::cout << "nthTriangularNumber should be 55, is : " << nthTriNumResult << std::endl;

  std::vector<int64_t> nums{0,10,20,30,40,50};
  mathr.AdditionPlusFive(nums);
  return 0;
}
