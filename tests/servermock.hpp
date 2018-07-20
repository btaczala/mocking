#ifndef SERVERMOCK_HPP_CUZYOIX4
#define SERVERMOCK_HPP_CUZYOIX4

#include <gmock/gmock.h>

#include "serverinterface.h"

namespace interface {
struct ServerMock : public ServerInterface {
    MOCK_METHOD0(startServer, bool());
};
}  // namespace interface

namespace crtp {
struct ServerMock : public ServerInterface<ServerMock> {
    MOCK_METHOD0(startServer, bool());
};
}  // namespace crtp

#endif /* end of include guard: SERVERMOCK_HPP_CUZYOIX4 */
