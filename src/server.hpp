#ifndef SERVER_HPP_VNMSIJM5
#define SERVER_HPP_VNMSIJM5

#include <functional>
#include <memory>

struct Database {
    bool init() { return true; }
};
struct RestServer {
    bool init() { return true; }
};

struct Server {
    Server();

    ~Server();
    bool startServer();

   private:
    Database _db;
    RestServer _rest;
};

#endif /* end of include guard: SERVER_HPP_VNMSIJM5 */
