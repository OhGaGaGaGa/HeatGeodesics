project(mesh)

add_library(${PROJECT_NAME} src/vertex.cpp src/edge.cpp src/face.cpp)
add_library(sub::mesh ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    thirdparty
)
