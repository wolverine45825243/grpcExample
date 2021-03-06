#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "../core/GreeterClientCli.h"

#include <greeting.grpc.pb.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using example::GreetingRequest;
using example::GreetingReply;

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 8000). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  GreeterClientCli greeter(grpc::CreateChannel("localhost:8000", grpc::InsecureChannelCredentials()));

  std::cout << "Insert name: ";
  std::string user;
  std::getline(std::cin, user);

  std::string reply = greeter.hello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
