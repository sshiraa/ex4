//
// Created by shira on 13.1.2020.
//

#define PORT 5600

#include "ClientHandler.h"
struct serverData {
  int port;
  int socketfd;
  bool active;
  ClientHandler *clientHandler;
};
#include "MySerialServer.h"
#include <strings.h>
//#include "readWrite"
//#include <vector>
//typedef void * (*THREADFUNCPTR)(void *);

int accept(int socketfd) {
  sockaddr_in clientSocket;
  int clientLength;
  // accepting a client
  int clientSocketFd = ::accept(socketfd, (struct sockaddr *) &clientSocket,
                                (socklen_t *) &clientLength);

  if (clientSocketFd == -1) {
    std::cerr << "Error accepting client" << std::endl;
    return -4;
  }
  return clientSocketFd;
  //reading from client
  //thread thread1(&MySerialServer::readWriteProtocol, this, client_socket);
  //thread thread1(&ClientHandler::handleClient, this->clientHandler, client_socket);
  //this->threadVector.push_back(thread1);
  //thread1.detach();
}

void *handleThreadFunc(void* args) {
  struct serverData *serverData = (struct serverData *)args;
  while (serverData->active) {
    //setting timeout
    struct timeval tv;
    tv.tv_sec = 120;
    if(setsockopt(serverData->socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*) &tv, sizeof(tv)) < 0)
      std::cerr << "setsockopt failed\n" << std::endl;
    int id = accept(serverData->socketfd);
    //readWrite
    serverData->clientHandler->handleClient(id);//add clientSocket from readWrite
/*    //setting timeout
    struct timeval tv;
    tv.tv_sec = 120;
    if(setsockopt(serverData->socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*) &tv, sizeof(tv)) < 0)
      std::cerr << "setsockopt failed\n" << std::endl;*/
  }
  delete serverData;
  return nullptr;
}

void * MySerialServer::handleThread(void* args) {
  struct serverData *serverData = (struct serverData *)args;
  pthread_t pthread1;
  pthread_create(&pthread1, nullptr, handleThreadFunc, serverData);
  return 0;
}

int MySerialServer::open(int port, ClientHandler *clientHandler) {
  //create socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
    return -1;
  }

  //bind socket to IP address
  this->address.sin_family = AF_INET;
  this->address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  this->address.sin_port = htons(port);

  /*// we first need to create the sockaddr obj.
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(PORT);
  //we need to convert our number
  // to a number that the network understands.
   */


  //the actual bind command
  if (bind(socketfd, (struct sockaddr *) &this->address, sizeof(this->address)) == -1) {
    std::cerr << "Could not bind the socket to an IP" << std::endl;
    return -2;
  }

  //making socket listen to the port
  if (listen(socketfd, 1) == -1) { //can also set to SOMAXCON (max connections)
    std::cerr << "Error during listening command" << std::endl;
    return -3;
  } else {
    std::cout << "Server is now listening ..." << std::endl;
  }

  struct serverData *serverData = new struct serverData;
  serverData->socketfd = this->socketfd;
  serverData->active = this->active;
  serverData->clientHandler = clientHandler;
  serverData->port = port;
  this->handleThread(serverData);
  //pthread_t handleThread;
  //pthread_create(&handleThread, nullptr, handleThreadFunc, serverData);


//  this->threadStart(serverData);
  return 0;
}//end open func




//close(socketfd); //closing the listening socket
