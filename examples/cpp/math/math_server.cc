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

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/math.grpc.pb.h"
#else
#include "math.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using math::MathOperations;
using math::Multiplicands;
using math::Result;
using math::Addends;

// Logic and data behind the server's behavior.
class MathOperationsServiceImpl final : public MathOperations::Service {
  Status Multiplication(ServerContext* context, const Multiplicands* request,
                        Result* reply) override {
    std::string prefix("Hello ");
    reply->set_mathresult(request->multiplicand1() + request->multiplicand2());
    return Status::OK;
  }

  Status nthTriangularNumber(ServerContext* context, ServerReader<Addends>* reader,
                             Result* reply ) override {
    Addends addend;
    reply->set_mathresult(0);
    int64_t sum = 0;

    while(reader->Read(&addend)) {
      sum += addend.addend();
      std::cout << "Sum is: " << sum << std::endl;
    }
    reply->set_mathresult(sum);
    return Status::OK;
  }

  Status AdditionPlusFive(ServerContext* context,
                          ServerReaderWriter<Result, Addends>* stream) override {
    Addends addend;
    Result result;
    int32_t num = 0;
    while(stream->Read(&addend)) {
      result.set_mathresult(addend.addend() + 5);
      stream->Write(result);
    }
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  MathOperationsServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
