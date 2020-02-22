find_package(Threads)

add_executable(cyboto
    main.cpp
    physical_components_manager.cpp
    functions_manager.cpp
    emergency_situation_manager.cpp
    physical_component.cpp
    base_function.cpp
    core.cpp
    base_component.cpp
    parsers.cpp
    common.cpp
    event_manager.cpp
    trigger.cpp
    function_factory.cpp
)

target_link_libraries(cyboto Threads::Threads)

