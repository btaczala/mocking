#include "server.hpp"

#include "databaseinterface.h"
#include "serverinterface.h"

namespace interface {
Server::Server(ServerInterface* server, DatabaseInterface* db)
    : _server(server), _db(db) {}

Server::~Server() {}

bool Server::startServer() {
    _server->startServer();
    return _db->initConnection();
}

}  // namespace interface
