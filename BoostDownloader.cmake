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
