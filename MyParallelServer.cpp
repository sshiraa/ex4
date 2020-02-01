//
// Created by shira on 29.1.2020.
//

#include "MyParallelServer.h"


struct info {
  int sock;
  ClientHandler *clientHandler;
};

int MyParallelServer::open(int port, ClientHandler* clientHandler) {
  this->port = port;
  this->clientHandler = clientHandler;
  int server_fd;
  struct sockaddr_in address{};
  this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  int n = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(int));
  if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    perror("socket bind");
    exit(1);
  }

  if (listen(sockfd, 5) == -1) {
    perror("socket listen");
    exit(1);
  }
  start();
}

void MyParallelServer::stop() {
  while (!this->threads.empty()) {
    pthread_join(this->threads.top(), nullptr);
    this->threads.pop();
  }
  toStop = true;
}

void *MyParallelServer::startThreadClient(void *params) {
  auto data = (info *) params;
  data->clientHandler->handleClient(data->sock);
}

void MyParallelServer::start() {
  sockaddr_in address{};
  int addrlen = sizeof(address);

  timeval timeout;
  //int newSocket;
  while (!this->toStop) {
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    int newSocket = ::accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
    if (newSocket < 0) {
      if (errno == EWOULDBLOCK || errno == EAGAIN) {
        cout << "Timeout" << endl;
        stop();
        break;
      }
      perror("accept");
      exit(EXIT_FAILURE);
    }
    cout << "Accepted client" << endl;
    setsockopt(newSocket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    auto data = new info;
    data->clientHandler = this->clientHandler;
    data->sock = newSocket;
    pthread_t trid;
    if (pthread_create(&trid, nullptr, startThreadClient, data) < 0) {
      perror("error on creating thread");
      exit(1);
    }
    this->threads.push(trid);
  }
  close(this->sockfd);
}

/*

struct serverData {
  int port;
  int socketfd;
  bool active;
  ClientHandler *clientHandler;
};

int MyParallelServer::open(int port, ClientHandler *client_handler) {
  if (!(*is_close)) {
    throw "Server already open";
  }
  int clilen;
  struct sockaddr_in serv_addr, cli_addr;
  if (new_clients_thread != nullptr) {
    delete (new_clients_thread);
    new_clients_thread = nullptr;
  }

  */
/* First call to socket() function *//*

  sockettfed = socket(AF_INET, SOCK_STREAM, 0);

  if (sockettfed < 0) {
    throw SERVER_ERROR;
  }

  */
/* Initialize socket structure *//*

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);

  */
/* Now bind the host address using bind() call.*//*

  if (bind(sockettfed, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    throw SERVER_ERROR;
  }

  */
/* Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection
  *//*


  listen(sockettfed, listen_num);

  if (sockettfed < 0) {
    throw SERVER_ERROR;
  }
  */
/* Accept actual connection from the client *//*


  struct ServerArguments *argu = new ServerArguments(sockettfed, client_handler, cli_addr, clilen, is_close);
  auto f = [](void *argu) {
    bool is_time_set = false;
    struct ServerArguments *arguments = (ServerArguments *) argu;
    int sockfd = arguments->socket_id;
    struct sockaddr_in cli_addr = arguments->cli_addr;
    int clilen = arguments->clilen;
    ClientHandler *client_handler = arguments->client_handler;
    volatile bool *is_close = arguments->is_close;
    delete (arguments);

    thread *t;
    std::vector<thread *> threads;
    std::vector<int> sockets;
    //create fuction for the client handler's thread
    auto cf = [](void *argumen) {
      struct ClientArguments *arguments = (ClientArguments *) argumen;
      int sockfd = arguments->socket_id;
      ClientHandler *client_handler = arguments->client_handler;
      delete (arguments);
      SocketManager socket_manager(sockfd);
      client_handler->handleClient(socket_manager.getSockfd());//////////////////
    };
    while (!(*is_close)) {
      int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
      if (!is_time_set) {
        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
      }
      if (newsockfd < 0) {
        (*is_close) = true;
        break;
      }
      timeval timeout2;
      timeout2.tv_sec = 10;
      timeout2.tv_usec = 0;
      setsockopt(newsockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout2, sizeof(timeout2));
      ClientArguments *argus = new ClientArguments(client_handler, newsockfd);

      t = new thread(cf, (void *) argus);
      t->detach();
      threads.push_back(t);
      sockets.push_back(newsockfd);

    }
    for (thread *handler_thread : threads) {
      if (handler_thread->joinable()) {
        handler_thread->join();
      }
      delete handler_thread;
    }
    for (int sock : sockets) {
      close(sock);
    }


    close(sockfd);
    return nullptr;
  };
  (*is_close) = false;
  new_clients_thread = new thread(f, (void *) argu);
  new_clients_thread->detach();


}


void MyParallelServer::stop() {
  (*is_close) = true;
  if (new_clients_thread->joinable()) {
    new_clients_thread->join();
  }
  delete (new_clients_thread);
  new_clients_thread = nullptr;

}

MyParallelServer::MyParallelServer() : listen_num(SOMAXCONN), new_clients_thread(nullptr) {
  is_close = new bool;
  (*is_close) = true;
}

MyParallelServer::MyParallelServer(int listen_num) : listen_num(listen_num), new_clients_thread(nullptr) {
  is_close = new bool;
  (*is_close) = true;
}


MyParallelServer::~MyParallelServer() {
  if (new_clients_thread != nullptr) {
    delete (new_clients_thread);
    new_clients_thread = nullptr;
  }

}
*/
