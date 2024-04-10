project(io)

add_library(${PROJECT_NAME} src/obj.cpp src/vtk.cpp)
add_library(sub::io ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    thirdparty
)
