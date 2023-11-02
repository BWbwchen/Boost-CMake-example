cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
project(code
        VERSION 1.0
        LANGUAGES CXX
        )

set(CMAKE_CXX_STANDARD 17)

set(BOOST_VERSION 1.81.0)
set(BOOST_INCLUDE_LIBRARIES system program_options)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
# Set(FETCHCONTENT_QUIET FALSE)
message(STATUS "Downloading Boost... it may cost some time")
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-${BOOST_VERSION}/boost-${BOOST_VERSION}.7z
    DOWNLOAD_EXTRACT_TIMESTAMP true
    USES_TERMINAL_DOWNLOAD TRUE
    GIT_PROGRESS TRUE
    DOWNLOAD_NO_EXTRACT FALSE
)
FetchContent_MakeAvailable(Boost)

file(GLOB Boost_INCLUDE_DIR LIST_DIRECTORIES true ${Boost_SOURCE_DIR}/libs/*/include)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options)
target_include_directories(${PROJECT_NAME}
    PUBLIC ${Boost_INCLUDE_DIR}
)
