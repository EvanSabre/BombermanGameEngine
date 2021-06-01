# Usage:
# FIND_PACKAGE(boost REQUIRED)
# [...] # TARGET_LINK_LIBRARIES(target_name boost) CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
set(boost_DIR ${PROJECT_SOURCE_DIR}/cmake)

if (NOT boost_FOUND)
        INCLUDE(FetchContent)

        FetchContent_Declare(
          boost
          URL https://github.com/boostorg/boost/archive/refs/heads/master.zip
        )
        FetchContent_GetProperties(boost)

if (NOT boost_POPULATED)
        SET(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(boost)
        SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

        ADD_SUBDIRECTORY(${boost_SOURCE_DIR} ${boost_BINARY_DIR})
        SET(boost_FOUND TRUE)
  endif()
endif() 