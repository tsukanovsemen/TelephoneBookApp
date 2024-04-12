project(ContactTests
    LANGUAGES CXX
)

enable_testing()

find_package(Qt5 COMPONENTS Test REQUIRED)

AUTO_BUILD_RESOURCES_QT5()

add_executable(ContactTests contact_tests.cpp)
add_test(NAME ContactTests COMMAND ContactTests)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install-root
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Test TelephoneBookModel)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})


