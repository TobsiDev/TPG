add_library(input 
            inputManager.h
            inputManager.cpp
            )

target_include_directories(input PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")