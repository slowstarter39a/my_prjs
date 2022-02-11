
cmake_minimum_required (VERSION 3.1)  

add_executable(helloworld helloworld.c)

install (TARGETS helloworld DESTINATION bin)
