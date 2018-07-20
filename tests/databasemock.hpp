#ifndef DATABASEMOCK_HPP_QOEC7PQV
#define DATABASEMOCK_HPP_QOEC7PQV

#include <gmock/gmock.h>

#include "databaseinterface.h"

#include "server_crtp.h"

namespace interface {
struct DatabaseMock : public DatabaseInterface {
    MOCK_METHOD0(initConnection, bool());
};

}  // namespace interface

namespace crtp {
struct DatabaseMock : public DatabaseInterface<DatabaseMock> {
    MOCK_METHOD0(initConnection, bool());
};
};  // namespace crtp

#endif /* end of include guard: DATABASEMOCK_HPP_QOEC7PQV */
