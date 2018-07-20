#ifndef SERVER_HPP_VNMSIJM5
#define SERVER_HPP_VNMSIJM5

#include <functional>
#include <memory>

#include "databaseinterface.h"
#include "serverinterface.h"

namespace interface {

struct Server {
    Server(ServerInterface* server, DatabaseInterface* db);

    ~Server();
    bool startServer();

   private:
    std::unique_ptr<ServerInterface> _server;
    std::unique_ptr<DatabaseInterface> _db;
};

}  // namespace interface

#endif /* end of include guard: SERVER_HPP_VNMSIJM5 */
