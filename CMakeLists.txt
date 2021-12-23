cmake_minimum_required(VERSION 3.20)
project(untitled5)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled5 main.cpp Oyuncu.cpp Oyuncu.h Takim.cpp Takim.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/NewAd.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/NewSoyad.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/NewSuperLig1.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#add_executable(untitled5 deneme.cpp)