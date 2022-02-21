add_library(src 
            menu.h
            menu.cpp
            )

target_include_directories(src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

#target_link_libraries(src)