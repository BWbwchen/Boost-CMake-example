cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
project(code
        VERSION 1.0
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 17)

set(BOOST_VERSION 1.81.0)
set(BOOST_INCLUDE_LIBRARIES system program_options)
add_executable(${PROJECT_NAME} main.cpp)

include("${CMAKE_SOURCE_DIR}/BoostDownloader.cmake")

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options)
target_include_directories(${PROJECT_NAME}
    PUBLIC ${Boost_INCLUDE_DIRS}
)
