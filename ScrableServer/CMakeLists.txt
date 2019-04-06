cmake_minimum_required(VERSION 3.13)
project(ScrableServer)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost COMPONENTS system REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAGS ON)
find_package(Threads)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    set (Boost_USE_STATIC_LIBS ON)

endif()

add_executable(ScrableServer main.cpp con_handler.cpp con_handler.h Server.cpp Server.h VerificadorPal.cpp VerificadorPal.cpp TrJSON.cpp TrJSON.h juego.cpp juego.h Lista.h)
if(Boost_FOUND)

    target_link_libraries(ScrableServer ${Boost_LIBRARIES})
    target_link_libraries(ScrableServer ${CMAKE_THREAD_LIBS_INIT})
endif()