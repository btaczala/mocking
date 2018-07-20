#include <benchmark/benchmark.h>

#include "server.hpp"

namespace {
std::string random_string(size_t length) {
    auto randchar = []() -> char {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}
}  // namespace

bool actual_sever_start() { return random_string(2) == "ab"; }

namespace interface {
struct ServerMock : public ServerInterface {
   public:
    bool startServer() override { return actual_sever_start(); }
};
struct DatabaseMock : public DatabaseInterface {
    bool initConnection() override { return actual_sever_start(); }
};
}  // namespace interface

namespace crtp {
struct ServerMock : public ServerInterface<ServerMock> {
    bool startServer() { return actual_sever_start(); }
};

struct DatabaseMock : public DatabaseInterface<DatabaseMock> {
    bool initConnection() { return actual_sever_start(); }
};
}  // namespace crtp

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


BENCHMARK(BM_interface);
BENCHMARK(BM_crtp);
BENCHMARK_MAIN();
