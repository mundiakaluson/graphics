cmake_minimum_required(VERSION 3.10)

project(graphics)

add_executable(graphics
	src/main.c
)

find_package(SDL2 REQUIRED)

target_include_directories(graphics
	PUBLIC ${SDL2_INCLUDE_HEADERS}
)

if (WIN32 AND NOT MSVC)
	target_link_libraries(graphics PUBLIC ${SDL2_LIBRARIES} mingw32)
else()
	target_link_libraries(graphics PUBLIC ${SDL2_LIBRARIES})
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE_INTERNAL "")
