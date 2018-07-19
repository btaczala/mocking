#include "server.hpp"

#include "databaseinterface.h"
#include "serverinterface.h"

namespace interface {
Server::Server(ServerInterface* server, DatabaseInterface* db)
    : _server(server), _db(db) {}

Server::~Server() {}

bool Server::startServer() {
    return _db->initConnection() && _server->startServer();
}

}  // namespace interface
