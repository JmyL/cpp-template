add_executable(san_test san_test.cpp)
AddTests(san_test)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
set(SANITIZE_ADDRESS ON)
# set(SANITIZE_MEMORY ON)
# set(SANITIZE_THREAD ON)
set(SANITIZE_UNDEFINED ON)
find_package(Sanitizers)
# sanitizer_add_blacklist_file("blacklist.txt")
add_sanitizers(san_test)
endif()
