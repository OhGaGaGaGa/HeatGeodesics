project (cli)

add_library(${PROJECT_NAME} INTERFACE)
add_library(sub::cli ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)