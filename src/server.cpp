#include "server.hpp"

Server::Server() {}

Server::~Server() {}

bool Server::startServer() { return _db.init() && _rest.init(); }
