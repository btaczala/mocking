#ifndef SERVERMOCK_HPP_CUZYOIX4
#define SERVERMOCK_HPP_CUZYOIX4

#include <gmock/gmock.h>

#include "server_crtp.h"
#include "serverinterface.h"

struct ServerMock : public ServerInterface {
    MOCK_METHOD0(startServer, bool());
};

namespace crtp {
struct ServerMock : public ServerIf<ServerMock> {
     MOCK_METHOD0(startServer, void());
};
}  // namespace crtp

#endif /* end of include guard: SERVERMOCK_HPP_CUZYOIX4 */
