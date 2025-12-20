#ifdef linux
#undef linux
#endif

#include <cppcoro/io_service.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all.hpp>

#include <iostream>


cppcoro::task<int> example_coro_1() { co_return 2; }

cppcoro::task<int> example_coro() { co_return 42 - co_await example_coro_1(); }

int main() {
    cppcoro::io_service ioService;
    std::cout << cppcoro::sync_wait(example_coro()) << std::endl;
    return 0;
}