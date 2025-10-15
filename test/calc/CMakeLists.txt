add_executable(calc_test calc_test.cpp)
target_link_libraries(calc_test PRIVATE calc)
add_test_suite(calc_test)
enable_coverage(calc)
