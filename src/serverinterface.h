#ifndef SERVERINTERFACE_H_ABWSB4LN
#define SERVERINTERFACE_H_ABWSB4LN

namespace interface {
struct ServerInterface {
    virtual ~ServerInterface() {}
    virtual bool startServer() = 0;
};

}  // namespace interface

#include <boost/tti/tti.hpp>
namespace crtp {

BOOST_TTI_HAS_MEMBER_FUNCTION(startServer);

template <typename T>
struct ServerInterface {
    typedef T ImplT;

    ServerInterface() {
        static_assert(has_member_function_startServer<T, bool>::value, "Type T has to have startServer");
    }

    void startServer() { static_cast<T*>(this)->startServer(); }
    void nonMockableFunction() {}
};

}  // namespace crtp

#endif /* end of include guard: SERVERINTERFACE_H_ABWSB4LN */
