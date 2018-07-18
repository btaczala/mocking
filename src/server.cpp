#include "server.hpp"

#include "databaseinterface.h"
#include "serverinterface.h"

Server::Server(ServerInterface* server, DatabaseInterface* db)
    : _server(server), _db(db) {}

Server::~Server() {}

void Server::startServer() {
    _db->initConnection();
    _server->startServer();
}
