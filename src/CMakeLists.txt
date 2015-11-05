set(TbUT_SRCS
TbUTCluster.cpp
TbUTCluster.h
TbUTClusterCreator.cpp
TbUTClusterCreator.h
TbUTIClusterCreator.h
TbUTITresholdProvider.h
TbUTRawData.cpp
TbUTRawData.h
TbUTSensor.cpp
TbUTSensor.h
)

# Declare the library
add_library(TbUT STATIC
    ${TbUT_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(TbUT PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
