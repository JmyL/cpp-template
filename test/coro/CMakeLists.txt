CPMAddPackage(
    NAME cppcoro
    GITHUB_REPOSITORY andreasbuhr/cppcoro
    GIT_TAG f05170f
)

add_executable(coro_test coro_test.cpp)
target_link_libraries(coro_test PRIVATE cppcoro)
add_test_suite(coro_test)