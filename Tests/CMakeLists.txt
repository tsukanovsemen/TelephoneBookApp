project(TelephoneBookTests
    VERSION 0.0.1
    LANGUAGES CXX
)

AUTO_BUILD_RESOURCES_QT5()

INCLUDE_SOURCES(${PROJECT_NAME})

set(BUILD_TESTS TRUE)

add_library(${PROJECT_NAME} STATIC
    ${SOURCES}
    ${HEADERS}
)

find_package(Qt5 COMPONENTS Test REQUIRED)

if(BUILD_TESTS)
    enable_testing()

    PARSE_SUBDIRECTORIES(
        contact_tests
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Test TelephoneBookModel)
