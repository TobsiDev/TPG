add_library(src 
            menu.h
            menu.cpp
            )

add_subdirectory(inputSystem)
target_link_libraries(input)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inputSystem)
target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
