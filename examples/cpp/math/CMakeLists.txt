# Copyright 2018 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# cmake build file for C++ math example.
# Assumes protobuf and gRPC have been installed using cmake.
# See cmake_externalproject/CMakeLists.txt for all-in-one cmake build
# that automatically builds all the dependencies before building math.

cmake_minimum_required(VERSION 3.5.1)

project(Math C CXX)

include(../cmake/common.cmake)

# Proto file
get_filename_component(math_proto "../../protos/math.proto" ABSOLUTE)
get_filename_component(math_proto_path "${math_proto}" PATH)

# Generated sources
set(math_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/math.pb.cc")
set(math_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/math.pb.h")
set(math_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/math.grpc.pb.cc")
set(math_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/math.grpc.pb.h")
add_custom_command(
      OUTPUT "${math_proto_srcs}" "${math_proto_hdrs}" "${math_grpc_srcs}" "${math_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${math_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${math_proto}"
      DEPENDS "${math_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# math_grpc_proto
add_library(math_grpc_proto
  ${math_grpc_srcs}
  ${math_grpc_hdrs}
  ${math_proto_srcs}
  ${math_proto_hdrs})
target_link_libraries(math_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

# Targets math_(client|server)
foreach(_target
  math_client math_server)
  add_executable(${_target} "${_target}.cc")
  target_link_libraries(${_target}
    math_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()
