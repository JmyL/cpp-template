include(GrpcProtobuf)
add_proto_target(rg_grpc_proto route_guide.proto)

# find_package(absl CONFIG REQUIRED)

add_library(route_guide_helper helper.h helper.cc)
target_link_libraries(
    route_guide_helper
    rg_grpc_proto
    absl::flags
    absl::flags_parse
    absl::log
    absl::log_initialize
)

foreach(
    _target
    route_guide_client
    route_guide_server
    route_guide_callback_client
    route_guide_callback_server
)
    add_executable(${_target} "${_target}.cc")
    target_link_libraries(
        ${_target}
        rg_grpc_proto
        route_guide_helper
        absl::flags
        absl::flags_parse
        absl::log
        absl::log_initialize
    )
    # include(CppCheck)
    # add_cppcheck(${_target})
    # if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    #     set(SANITIZE_ADDRESS ON)
    #     # set(SANITIZE_MEMORY ON)
    #     # set(SANITIZE_THREAD ON)
    #     # set(SANITIZE_UNDEFINED ON)
    #     find_package(Sanitizers)
    #     # sanitizer_add_blacklist_file("blacklist.txt")
    #     add_sanitizer(${_target})
    # endif()
endforeach()
