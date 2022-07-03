cmake_minimum_required(VERSION 3.22)
project(kata)
include(battle/CMakeLists.txt)

set(KATA_DISABLE_WARNINGS true)
run_kata(kata
        tests.cpp
        solution.h
)

