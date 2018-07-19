#include <benchmark/benchmark.h>

#include "server.hpp"

namespace interface {
struct ServerMock : public ServerInterface {
   public:
    bool startServer() override { return true; }
};
struct DatabaseMock : public DatabaseInterface {
    bool initConnection() override { return false; }
};
}  // namespace interface

namespace crtp {
struct ServerMock : public ServerInterface<ServerMock> {
    void startServer() {}
};

struct DatabaseMock : public DatabaseInterface<DatabaseMock> {
    bool initConnection() { return false; }
};
}  // namespace crtp

namespace type_erasure {
struct ServerMock {
    void startServer() {}
};

struct DatabaseMock {
    bool initConnection() { return false; }
};
}  // namespace type_erasure

void BM_interface(benchmark::State& state) {
    interface::ServerMock* srvMock{new interface::ServerMock};
    interface::DatabaseMock* dbMock{new interface::DatabaseMock};
    interface::Server s{srvMock, dbMock};

    for (auto _ : state) {
        benchmark::DoNotOptimize((s.startServer()));
    }
}

void BM_crtp(benchmark::State& state) {
    crtp::Server<crtp::ServerMock, crtp::DatabaseMock> s;
    for (auto _ : state) {
        benchmark::DoNotOptimize((s.startServer()));
    }
}

void BM_type_erasure(benchmark::State& state) {
    type_erasure::ServerMock sMock;
    type_erasure::DatabaseMock dMock;
    type_erasure::Server s{sMock, dMock};

    for (auto _ : state) {
        benchmark::DoNotOptimize((s.startServer()));
    }
}

BENCHMARK(BM_interface);
BENCHMARK(BM_crtp);
BENCHMARK(BM_type_erasure);

BENCHMARK_MAIN();
