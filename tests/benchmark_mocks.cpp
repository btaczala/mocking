#include <benchmark/benchmark.h>
#include <gtest/gtest.h>

#include "databasemock.hpp"
#include "servermock.hpp"

#include "server.hpp"
struct ServerTests : public ::testing::Test {
    ServerTests()
        : srvMock(new interface::ServerMock),
          dbMock(new interface::DatabaseMock),
          s(srvMock, dbMock) {}
    interface::ServerMock* srvMock;
    interface::DatabaseMock* dbMock;
    interface::Server s;
};

TEST_F(ServerTests, ok) { s.startServer(); }

void BM_interface_gmock(benchmark::State& state) {
    interface::ServerMock* srvMock{new interface::ServerMock};
    interface::DatabaseMock* dbMock{new interface::DatabaseMock};
    interface::Server s{srvMock, dbMock};

    EXPECT_CALL(*dbMock, initConnection())
        .WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*srvMock, startServer())
        .WillRepeatedly(::testing::Return(true));

    for (auto _ : state) {
        benchmark::DoNotOptimize(s.startServer());
    }
}

void BM_crtp_gmock(benchmark::State& state) {
    crtp::Server<crtp::ServerMock, crtp::DatabaseMock> s;

    EXPECT_CALL(s.serverInterface(), startServer())
        .Times(::testing::AtLeast(1));
    EXPECT_CALL(s.databaseInterface(), initConnection())
        .Times(::testing::AtLeast(1));

    for (auto _ : state) {
        benchmark::DoNotOptimize((s.startServer()));
    }
}

void BM_type_erasure_gmock(benchmark::State& state) {
    type_erasure::ServerMock sMock;
    type_erasure::DatabaseMock dMock;
    type_erasure::Server s{sMock, dMock};

    EXPECT_CALL(dMock, initConnection())
        .WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(sMock, startServer()).WillRepeatedly(::testing::Return(true));

    for (auto _ : state) {
        benchmark::DoNotOptimize(s.startServer());
    }
}

BENCHMARK(BM_interface_gmock);
BENCHMARK(BM_crtp_gmock);
BENCHMARK(BM_type_erasure_gmock);
BENCHMARK_MAIN();
