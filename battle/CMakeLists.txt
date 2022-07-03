cmake_minimum_required(VERSION 3.22)

function(run_kata KATA_TARGET KATA_SOURCES)
    set(CMAKE_CXX_STANDARD 17)
    include(FetchContent REQUIRED)

    FetchContent_Declare(
            igloo
            GIT_REPOSITORY https://github.com/codewars/igloo.git
            GIT_TAG        v2.2.0
    )

    FetchContent_Declare(
            snowhouse
            GIT_REPOSITORY https://github.com/codewars/snowhouse.git
            GIT_TAG        v5.0.0
    )

    # workarounds for broken igloo cmake
    FetchContent_GetProperties(igloo)
    if(NOT igloo_POPULATED)
        FetchContent_Populate(igloo)
    endif()

    FetchContent_MakeAvailable(igloo snowhouse)

    # workarounds for broken igloo and snowhouse libraries
    if (${KATA_DISABLE_WARNINGS})
        message("turning off some compiler options that produce warnings in igloo")
        add_compile_options(
                -Wall
                -Wpedantic
                -Wno-deprecated-declarations
                -Wno-delete-abstract-non-virtual-dtor
                -Wno-delete-non-abstract-non-virtual-dtor
                -Wno-overloaded-virtual
        )
    endif()

    include_directories(${igloo_SOURCE_DIR}/ ${snowhouse_SOURCE_DIR}/include)

    add_executable(${KATA_TARGET}
            battle/main.cpp
            ${KATA_SOURCES}
    )

    add_custom_target(run
            ALL
            USES_TERMINAL
            DEPENDS ${KATA_TARGET}
            COMMAND ${KATA_TARGET} --output=color
    )
endfunction()