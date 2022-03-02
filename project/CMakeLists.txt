cmake_minimum_required(VERSION 3.0.0)
project(TextRPG VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(src) # Adds a subfolder here

# If you have to include lib's via vcpkg
# you can add them here

add_executable(TextPG main.cpp)
target_link_libraries(TextPG PRIVATE src input)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)