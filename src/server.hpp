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

namespace crtp {

template <typename S, typename D>
struct Server {
    bool startServer() { return _server.startServer() && _db.initConnection(); }

    S& serverInterface() noexcept { return _server; }
    D& databaseInterface() noexcept { return _db; }

    static_assert(std::is_same<typename ServerInterface<S>::ImplT,
                               typename S::ImplT>::value,
                  "S must derive from ServerIf");
   private:
    S _server;
    D _db;
};

};  // namespace crtp

#endif /* end of include guard: SERVER_HPP_VNMSIJM5 */
