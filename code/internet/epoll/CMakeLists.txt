cmake_minimum_required(VERSION 3.10)
include(ExternalProject)
project(epoll_example)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
add_compile_options(-O0 -Werror)
ExternalProject_Add(
    common_lib
    URL ${CMAKE_CURRENT_SOURCE_DIR}/../common/
    DOWNLOAD_NO_EXTRACT 1
    CONFIGURE_COMMAND cmake -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX} .
    BUILD_COMMAND make  
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND make install 
)

include_directories(${CMAKE_INSTALL_PREFIX}/include)
link_directories(${CMAKE_INSTALL_PREFIX}/lib)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)
set(LIBS pthread common_lib.a)
foreach(CPP_SOURCE ${SOURCES})
    get_filename_component(CPP_SOURCE_WE ${CPP_SOURCE} NAME_WE)
    add_executable(${CPP_SOURCE_WE} ${CPP_SOURCE})
    add_dependencies(${CPP_SOURCE_WE} common_lib)
    target_link_libraries(${CPP_SOURCE_WE} ${LIBS})
    install(TARGETS ${CPP_SOURCE_WE} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)
endforeach()
