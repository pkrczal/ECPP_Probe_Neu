cmake_minimum_required(VERSION 3.21)
project(ECPP_Probe_Neu)

set(CMAKE_CXX_STANDARD 14)

add_executable(ECPP_Probe_Neu main.cpp PlayField.cpp PlayField.h MetaData.cpp MetaData.h FileIO.h)
