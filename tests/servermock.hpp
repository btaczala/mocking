#ifndef SERVERMOCK_HPP_CUZYOIX4
#define SERVERMOCK_HPP_CUZYOIX4

#include <gmock/gmock.h>

#include "serverinterface.h"

namespace interface {
struct ServerMock : public ServerInterface {
    MOCK_METHOD0(startServer, bool());
};
}  // namespace interface


#endif /* end of include guard: SERVERMOCK_HPP_CUZYOIX4 */
