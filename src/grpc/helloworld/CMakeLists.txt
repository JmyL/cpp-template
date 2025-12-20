include(GrpcProtobuf)
add_proto_target(helloworld_proto helloworld.proto)

foreach(
    _target
    greeter_client
    greeter_server
    greeter_callback_client
    greeter_callback_server
    greeter_async_client
    greeter_async_client2
    greeter_async_server
)
    add_executable(${_target} "${_target}.cc")
    target_link_libraries(
        ${_target}
        helloworld_proto
        absl::flags
        absl::flags_parse
        absl::log
        absl::log_initialize
    )
endforeach()