enable_testing()

include(CPM)
CPMAddPackage(
  NAME gtest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.15.2
  OPTIONS
      "INSTALL_GTEST OFF"
      "INSTALL_GMOCK OFF"
      "gtest_force_shared_crt ON"
)

include(GoogleTest)
include(Coverage)
include(Memcheck)

macro(AddTests target)
  AddCoverage(${target})
  target_link_libraries(${target} PRIVATE gtest_main gmock)
  gtest_discover_tests(${target}
     EXTRA_ARGS --gtest_color=yes
     PROPERTIES ENVIRONMENT "ASAN_OPTIONS=color=always")

  AddMemcheck(${target})
endmacro()
