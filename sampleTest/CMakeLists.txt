PROJECT(sampleTest)

if(WIN32)
else(WIN32)
	LIST(APPEND CMAKE_CXX_FLAGS -std=c++14)
endif(WIN32)

ADD_EXECUTABLE(sampleTest-170 main.cpp)
ADD_EXECUTABLE(sampleTest-180 main.cpp)

TARGET_LINK_LIBRARIES(sampleTest-170 gtest-1.7.0)
TARGET_LINK_LIBRARIES(sampleTest-180 gtest-1.8.0)