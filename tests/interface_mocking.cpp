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
    EXPECT_ANY_THROW(s.startServer());
}

struct ServerCrtp : public ::testing::Test {
    crtp::Server<crtp::ServerMock, crtp::DatabaseMock> _server;
};

TEST_F(ServerCrtp, server_cannot_start) {
    ON_CALL(_server.serverInterface(), startServer)
        .WillByDefault(::testing::Throw(std::runtime_error("")));
    EXPECT_ANY_THROW(_server.startServer());
}

struct ServerTypeErasure : public ::testing::Test {
    ServerTypeErasure() : _server(srvMock, dMock) {}
    type_erasure::Server _server;
    type_erasure::ServerMock srvMock;
    type_erasure::DatabaseMock dMock;
};

TEST_F(ServerTypeErasure, server_cannot_start) {
    ON_CALL(srvMock, startServer)
        .WillByDefault(::testing::Throw(std::runtime_error("")));
    EXPECT_ANY_THROW(_server.startServer());
}
