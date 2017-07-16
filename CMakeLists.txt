cmake_minimum_required(VERSION 3.0)
project(Incandescent)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif()

include_directories(Containers Tests)
file(GLOB FOLDER_CONTAINERS Containers/**)
file(GLOB FOLDER_TESTS Tests/**)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          License.md
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("Containers" FILES ${FOLDER_CONTAINERS})
source_group("Tests"      FILES ${FOLDER_TESTS})

add_executable(${PROJECT_NAME} ${FOLDER_CONTAINERS} ${FOLDER_TESTS} ${PROJECT_CONFIGS})
target_link_libraries(${PROJECT_NAME})
