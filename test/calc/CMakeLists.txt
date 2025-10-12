add_executable(calc_test calc_test.cpp)
target_link_libraries(calc_test PRIVATE calc)
addtests(calc_test)
enablecoverage(calc)
