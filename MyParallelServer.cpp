//
// Created by zahalka on 13/01/2020.
//

#include "MyParallelServer.h"

MyParallelServer::MyParallelServer() {}
/**
 * start the handling client process.
 * @param port
 * @param c
 */
void start2(int port, ClientHandler *c) {
    c->handleClient(port);
}

void MyParallelServer::open(int port, ClientHandler *c) {
    int socketSC = socket(AF_INET, SOCK_STREAM, 0);
    //check if socket open
    if (socketSC == -1) {
        cerr << "Couldn't create socket!" << endl;
        exit(1);
    }
    this->serverSocket = socketSC;

    sockaddr_in address, clin;
    address.sin_family = AF_INET;
    //use any to specify ip address
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    //try to bind the socket.
    if (bind(socketSC, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Couldn't bind the socket" << endl;
        exit(1);
    }
    //begin listening to accept multiple clients.
    //we will stay listening until client connects.
    listen(socketSC, SOMAXCONN);
    int i = 1;
    struct timeval tv;
    struct timeval tvCl;

    while (true) {
        int cl = sizeof(clin);
        this->argument->c = c->Clone();
        tv.tv_usec = 0;
        tv.tv_sec = 120;
        setsockopt(socketSC,SOL_SOCKET,SO_RCVTIMEO, (const char *) &tv, sizeof(tv));
        int newSC = accept(socketSC, (struct sockaddr *) &clin, (socklen_t *) &cl);
        //time out.
        if (newSC < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            } else {
                cout << "Error" << endl;
                break;
            }
        }

        cout << "Connected to client " << i  << endl;
        //add the function that executes start to a thread, then add thread to vector of threads.
        this->argument->newSC = newSC;
        tvCl.tv_usec = 0;
        tvCl.tv_sec = 0;
        setsockopt(newSC,SOL_SOCKET,SO_RCVTIMEO, (const char *) &tvCl, sizeof(tvCl));
        //threads.
        this->threadVector.emplace_back(&start2, newSC, c->Clone());
        //push sockets to close later
        sockets.push_back(newSC);
        i++;
    }
    joinT();
}

void * MyParallelServer::start(void * argument) {
   // struct threadArgument * arg =  (struct threadArgument *) argument;
   // arg->c->handleClient(arg->newSC);
    return nullptr;
}

void MyParallelServer::close() {
    //closing sockets
    ::close(serverSocket);
    for (auto & i : sockets) {
        ::close(i);
    }
}

MyParallelServer::~MyParallelServer() = default;

/**
 * if thread can be joined, join
 */
void MyParallelServer::joinT() {
    for (auto & i : threadVector) {
        if (i.joinable()) {
            i.join();
        }
    }
    //call the close functions to close sockets.
    MyParallelServer::close();
}
