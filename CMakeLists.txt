cmake_minimum_required(VERSION 3.20.0)
project(
  Calc
  VERSION 1.0.0
  LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(ExportCompileCommands)
include(NoInSourceBuilds)
include(SetReleaseAsDefault)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Check if CMAKE_BUILD_TYPE is set, if not, default to Release

add_subdirectory(src bin)
include(CTest)
add_subdirectory(test)

# include(Install)
