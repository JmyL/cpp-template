add_library(calc_obj OBJECT calc.cpp)
target_include_directories(calc_obj INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
set_target_properties(calc_obj PROPERTIES
    PUBLIC_HEADER src/calc/calc.h
    POSITION_INDEPENDENT_CODE 1
)

add_library(calc_shared SHARED)
target_link_libraries(calc_shared calc_obj)
add_library(calc_static STATIC)
target_link_libraries(calc_static calc_obj)

include(Coverage)
CleanCoverage(calc_static)
include(Format)
Format(calc_static .)
include(CppCheck)
AddCppCheck(calc_obj)
include(ClangTidy)
AddClangTidy(calc_obj)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
set(SANITIZE_ADDRESS ON)
# set(SANITIZE_MEMORY ON)
# set(SANITIZE_THREAD ON)
# set(SANITIZE_UNDEFINED ON)
find_package(Sanitizers)
# sanitizer_add_blacklist_file("blacklist.txt")
add_sanitizers(calc_obj)
endif()
include(Doxygen)
Doxygen(calc src/calc)
