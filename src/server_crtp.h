#ifndef SERVER_CRTP_H_EFOAUXM9
#define SERVER_CRTP_H_EFOAUXM9

#include <type_traits>

namespace crtp {

template <typename T>
struct ServerIf {
    typedef T ImplT;

    void startServer() { static_cast<T*>(this)->startServer(); }
    void nonMockableFunction() {}
};

template <typename T>
struct DatabaseIf {};

template <typename S, typename D>
struct Server {
    void startServer() { _server.startServer(); }

    const S& serverInterface() const noexcept { return _server; }

    static_assert(
        std::is_same<typename ServerIf<S>::ImplT, typename S::ImplT>::value, "");

   private:
    S _server;
    DatabaseIf<D> _db;
};

}  // namespace crtp

#endif /* end of include guard: SERVER_CRTP_H_EFOAUXM9 */
