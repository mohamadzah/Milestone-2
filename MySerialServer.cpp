//
// Created by zahalka on 13/01/2020.
//

#include "MySerialServer.h"

MySerialServer::MySerialServer() {
    closeServer = true;
}

void MySerialServer::open(int port, ClientHandler *c) {
    //create a thread and detach the start process.
    thread t1(start, port, c);
    t1.detach();
}

//create additional function that will create a socket
void MySerialServer::start(int port, ClientHandler *c) {
    int socketSC = socket(AF_INET, SOCK_STREAM, 0);
    //check if socket open
    if (socketSC == -1) {
        cerr << "Couldn't create socket!" << endl;
        exit(1);
    }

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
    while (true) {
        listen(socketSC, 5);
        int cl = sizeof(clin);
        int newSC = accept(socketSC, (struct sockaddr *) &clin, (socklen_t *) &cl);
        if (newSC < 0) {
            cout << "Error" << endl;
        }
        //call the handleClient and send the socket to read.
        c->handleClient(newSC);
    }
}

void MySerialServer::close() {
    closeServer = true;
}
