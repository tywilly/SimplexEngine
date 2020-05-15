cmake_minimum_required(VERSION 3.10)

project(SimplexEngine VERSION 1.0)

# Global vars
set( SE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

# Include GLEW
add_subdirectory( ${SE_DIR}/extern/GLEW/build/cmake )

# Include GLFW
add_subdirectory( ${SE_DIR}/extern/glfw )

# Set source files
set( SE_PUBLIC_HEADERS ${SE_DIR}/include/Common.h ${SE_DIR}/include/Entity.h ${SE_DIR}/include/GameObject.h ${SE_DIR}/include/Mesh.h ${SE_DIR}/include/Renderer.h ${SE_DIR}/include/SceneManager.h
	${SE_DIR}/include/Shader.h ${SE_DIR}/include/SimplexEngine.h)

set( SE_SRC ${SE_DIR}/src/Main.cpp ${SE_DIR}/src/Entity.cpp ${SE_DIR}/src/GameObject.cpp ${SE_DIR}/src/Mesh.cpp ${SE_DIR}/src/Renderer.cpp ${SE_DIR}/src/SceneManager.cpp ${SE_DIR}/src/Shader.cpp
	${SE_DIR}/src/SimplexEngine.cpp)

add_executable(SimplexEngine ${SE_PUBLIC_HEADERS} ${SE_SRC})

# Add include dirs
target_include_directories(SimplexEngine PUBLIC ${SE_DIR}/include )

# Link libraries
target_link_libraries(SimplexEngine glew_s)
target_link_libraries(SimplexEngine glfw)
