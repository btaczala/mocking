#ifndef DATABASEMOCK_HPP_QOEC7PQV
#define DATABASEMOCK_HPP_QOEC7PQV

#include <gmock/gmock.h>

#include "databaseinterface.h"

#include "server_crtp.h"

struct DatabaseMock : public DatabaseInterface {
    MOCK_METHOD0(initConnection, bool());
};

namespace crtp {
struct DatabaseMock : public DatabaseIf<DatabaseMock> {};
};  // namespace crtp

#endif /* end of include guard: DATABASEMOCK_HPP_QOEC7PQV */
