################################################################################
# Google Test Setup - BEGIN ####################################################
################################################################################

download_project(
    PROJ                googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             release-1.8.1
    ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

################################################################################
# Google Test Setup - END ######################################################
################################################################################

function(add_unit_test test_name sources_var libs_var)
    set(unit_test_name unit_${test_name})

    add_executable(
        ${unit_test_name}
        ${${sources_var}}
    )

    set_target_properties(
        ${unit_test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/bin
    )

    target_link_libraries(
        ${unit_test_name}
        PUBLIC ${${libs_var}}
        PRIVATE gtest gmock_main
    )

    add_test(NAME ${unit_test_name} COMMAND ${PROJECT_SOURCE_DIR}/test/bin/${unit_test_name})
endfunction(add_unit_test)

function(_add_lib lib_name sources_var directory)
    add_library(
        ${lib_name}
        ${${sources_var}}
    )

    target_include_directories(
        ${lib_name}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE ${gtest_SOURCE_DIR}/include
        PRIVATE ${gmock_SOURCE_DIR}/include
    )

    set_target_properties(
        ${lib_name}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${directory}/lib
    )
endfunction(_add_lib)

function(add_test_lib test_lib_name sources_var)
    _add_lib(
        ${test_lib_name}
        ${sources_var}
        test
    )
endfunction(add_test_lib)

function(add_mock_lib mck_lib_name sources_var)
    _add_lib(
        ${mck_lib_name}
        ${sources_var}
        mck
    )
endfunction(add_mock_lib)
