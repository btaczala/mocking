#include <gtest/gtest.h>
#include <stdexcept>

#include "src/server.hpp"

#include "databasemock.hpp"
#include "servermock.hpp"

#include "server_crtp.h"

struct ServerTests : public ::testing::Test {
    ServerTests()
        : srvMock(new interface::ServerMock),
          dbMock(new interface::DatabaseMock),
          s(srvMock, dbMock) {}
    interface::ServerMock* srvMock;
    interface::DatabaseMock* dbMock;
    interface::Server s;
};

TEST_F(ServerTests, ok) {
    EXPECT_CALL(*dbMock, initConnection()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*srvMock, startServer()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(s.startServer());
}

TEST_F(ServerTests, server_cannot_start) {
    ON_CALL(*srvMock, startServer)
        .WillByDefault(::testing::Throw(std::runtime_error("")));
    EXPECT_CALL(*dbMock, initConnection).WillOnce(::testing::Return(true));
    EXPECT_ANY_THROW(s.startServer());
}
