cmake_minimum_required(VERSION 3.5)

project(running_circle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(running_circle main.cpp
    core.h core.cpp)

target_link_libraries(running_circle PRIVATE sfml-graphics)
target_link_libraries(running_circle PRIVATE sfml-window)
target_link_libraries(running_circle PRIVATE sfml-system)
target_compile_features(running_circle  PRIVATE cxx_std_17)

include(GNUInstallDirs)
install(TARGETS running_circle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
