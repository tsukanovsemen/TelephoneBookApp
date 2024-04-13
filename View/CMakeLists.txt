project(TelephoneBookView
    VERSION 0.0.1
    LANGUAGES CXX
)

set(PROJECT_NAMESPACE telephone_book)

AUTO_BUILD_RESOURCES_QT5()

INCLUDE_SOURCES(${PROJECT_NAME})

add_library(${PROJECT_NAME}
    SHARED
    ${HEADERS}
    ${SOURCES}
    ${RESOURCES}
)

GENERATE_EXPORT_HEADERS(TARGET ${PROJECT_NAME} DIR include)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install-root
)

set(QT_REQUIRED_COMPONENTS
    Core
    Widgets
    QuickControls2
    Qml
    QuickWidgets
    Quick
)

FIND_AND_LINK_QT(TARGET
    ${PROJECT_NAME}
    QT_COMPONENTS
    ${QT_REQUIRED_COMPONENTS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE TelephoneBookModel)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
