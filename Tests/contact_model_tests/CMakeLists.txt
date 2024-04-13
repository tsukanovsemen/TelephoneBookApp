project(ContactModelTests
    LANGUAGES CXX
)

enable_testing()

find_package(Qt5 COMPONENTS Test REQUIRED)

AUTO_BUILD_RESOURCES_QT5()

INCLUDE_SOURCES(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
        ${SOURCES}
)

add_test(NAME ContactModelTests COMMAND ContactModelTests)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install-root
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Test TelephoneBookModel)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})


