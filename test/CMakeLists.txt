INCLUDE_DIRECTORIES(../src /usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

ADD_EXECUTABLE(CTypeContainTest test_main.cpp vector_test.hpp)

TARGET_LINK_LIBRARIES(CTypeContainTest gtest)

ADD_CUSTOM_COMMAND(TARGET CTypeContainTest POST_BUILD COMMAND CTypeContainTest)
