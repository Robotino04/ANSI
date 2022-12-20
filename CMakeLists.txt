cmake_minimum_required(VERSION 3.0)

project(ANSI)

add_library(ANSI STATIC "src/ANSI.cpp")

target_include_directories(ANSI PUBLIC "include/")