project(ContactTests
    LANGUAGES CXX
)

enable_testing()

find_package(Qt5 COMPONENTS Test REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ContactTests contact_tests.cpp)
add_test(NAME ContactTests COMMAND ContactTests)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Test TelephoneBookModel)


