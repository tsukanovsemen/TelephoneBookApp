project(TelephoneBookTests
    VERSION 0.0.1
    LANGUAGES CXX
)

AUTO_BUILD_RESOURCES_QT5()

set(BUILD_TESTS TRUE)

if(BUILD_TESTS)
    enable_testing()

    PARSE_SUBDIRECTORIES(
        contact_tests
    )
endif()
