#ifndef SERVER_HPP_VNMSIJM5
#define SERVER_HPP_VNMSIJM5

#include <memory>

class ServerInterface;
class DatabaseInterface;

struct Server {
    Server(ServerInterface* server, DatabaseInterface* db);

    ~Server();
    void startServer();

   private:
    std::unique_ptr<ServerInterface> _server;
    std::unique_ptr<DatabaseInterface> _db;
};

namespace crtp {
};

#endif /* end of include guard: SERVER_HPP_VNMSIJM5 */
