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
    bool startServer() {
        _server.startServer();
        return _db.initConnection();
    }

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

namespace type_erasure {

struct Server {
    template <typename ServerImpl, typename Database>
    Server(ServerImpl&& t, Database&& d) {
        _startServer = [&t]() { t.startServer(); };
        _initConnection = [&d]() { return d.initConnection(); };
    }

    bool startServer() {
        _startServer();
        return _initConnection();
    }

   private:
    std::function<void()> _startServer;
    std::function<bool()> _initConnection;
};

}  // namespace type_erasure

#endif /* end of include guard: SERVER_HPP_VNMSIJM5 */
