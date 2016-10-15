cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

GET_FILENAME_COMPONENT(BRANCH ${CMAKE_CURRENT_SOURCE_DIR} NAME)
PROJECT(${BRANCH})
SET(TARGET_NAME ${BRANCH})

set( ENV{CL} /MP )

enable_testing ()

add_subdirectory(3rdParty/gtest-1.7.0)
add_subdirectory(3rdParty/gtest-1.8.0)

add_subdirectory(sampleTest)
