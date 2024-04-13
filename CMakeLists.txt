cmake_minimum_required(VERSION 3.14)

project(TelephoneBook
    VERSION 0.0.1
    LANGUAGES CXX
)

set(PROJECT_NAMESPACE telephone_book)
set(BUILD_TESTS TRUE)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake.macros/base.cmake)

AUTO_BUILD_RESOURCES_QT5()

find_package(Qt5 COMPONENTS Core Qml Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install-root
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Qml Qt5::Widgets TelephoneBookModel TelephoneBookView)

PARSE_SUBDIRECTORIES(
    Model
    View
    Tests
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
