include(CPM)
CPMAddPackage(
  NAME benchmark
  GITHUB_REPOSITORY google/benchmark
  VERSION 1.5.2
  OPTIONS "BENCHMARK_ENABLE_TESTING Off"
)

# if(benchmark_ADDED)
#   # enable c++11 to avoid compilation errors
#   set_target_properties(benchmark PROPERTIES CXX_STANDARD 11)
# endif()

macro(AddBenchmark target)
  target_link_libraries(${target} PRIVATE benchmark::benchmark_main)
endmacro()
