file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testTbUT ${SRCS})

TARGET_LINK_LIBRARIES(testTbUT
    TbUT
    libgtest
    libgmock
)

add_test(NAME testTbUT
         COMMAND testTbUT)
