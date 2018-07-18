#include <gtest/gtest.h>
#include <stdexcept>

#include "src/server.hpp"

#include "databasemock.hpp"
#include "servermock.hpp"

#include "server_crtp.h"

struct ServerTests : public ::testing::Test {
    Server s{new ServerMock, new DatabaseMock};
};

TEST_F(ServerTests, server_cannot_start) { EXPECT_ANY_THROW(s.startServer()); }

struct ServerCrtp : public ::testing::Test {
    crtp::Server<crtp::ServerMock, crtp::DatabaseMock> _server;
};

TEST_F(ServerCrtp, server_cannot_start) {
    ON_CALL(_server.serverInterface(), startServer)
        .WillByDefault(::testing::Throw(std::runtime_error("")));
    EXPECT_ANY_THROW(_server.startServer());
}
