cmake_minimum_required(VERSION 3.20.0)
project(
  Calc
  VERSION 1.0.0
  LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(ExportCompileCommands)
include(NoInSourceBuilds)
include(SetReleaseAsDefault)
include(UseCcache)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src bin)
include(CTest)
add_subdirectory(test)
