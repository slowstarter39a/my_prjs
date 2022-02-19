cmake_minimum_required (VERSION 3.1)  

add_executable(sample-application sample_application.c)

install (TARGETS sample-application DESTINATION bin)
