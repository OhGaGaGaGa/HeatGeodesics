project(heat)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(heat PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    sub::cli
    sub::io
    thirdparty
)

# target_sources(${PROJECT_NAME} PUBLIC
#     src/main.cpp
# )