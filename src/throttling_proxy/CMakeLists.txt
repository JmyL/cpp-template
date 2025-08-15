find_package(Boost REQUIRED COMPONENTS system)

add_executable(throttling_proxy throttling_proxy.cpp)
target_link_libraries(throttling_proxy PRIVATE Boost::system)
