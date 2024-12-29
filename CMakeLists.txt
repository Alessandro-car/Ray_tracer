cmake_minimum_required(VERSION 3.1.0...3.27.0)

PROJECT(RAY_TRACER)

#Source
set( RAY_TRACER
	src/main.c
	src/color.c
	src/vec3.c
)

include_directories(src)

#Specific compiler flags below

message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPIlER_ID})
message (STATUS "Release flags: " ${CMAKE_CXX_FLAGS_RELEASE})
message (STATUS "Debug flags: " ${CMAKE_CXX_FLAGS_DEBUG})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options("/W4")
	add_compile_options("/we 4265")
	add_compile_options("/we 5204")
	add_compile_options("/wd 4100")
elseif (CMAKE_CXX_COMPIlER_ID STREQUAL "GNU")
	add_compile_options(-Wnon-virtual-dtor)
	add_compile_options(-Wreorder)
	add_compile_options(-Wmaybe-uninitialized)
	add_compile_options(-Wunused-variable)
elseif (CMAKE_CXX_COMPIlER_ID MATCHES "Clang")
	add_compile_options(-Wnon-virtual-dtor)
	add_compile_options(-Wreorder)
	add_compile_options(-Wsometimes-uninitialized)
	add_compile_options(-Wunused-variable)
endif()

#Executables
add_executable(ray_tracing ${RAY_TRACER})
target_link_libraries(ray_tracing m)
