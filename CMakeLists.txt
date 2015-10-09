cmake_minimum_required(VERSION 2.8.7)
project(TestSWIG)

#use -m64 for production release builds!
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -stdlib=libc++ -Wall -fPIC")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -m64  -std=c++14 -m64 -stdlib=libc++ -pedantic -mtune=native -g -Ofast -fPIC -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS " -m64 -g -lc++abi -pthreads")
################################################
#add sources to blobs
file(GLOB CPP_LIBRARY_SOURCES
        "CPP/Library/**"
        )

file(GLOB CSHARP_WRAPPER_SOURCES
        "CSharp/CSharpWrapper/*.cxx"
        )

set(CPP_LIBRARY_SOURCE_FILES
        ${CPP_LIBRARY_SOURCES}
        )

set(CSHARP_WRAPPER_SOURCE_FILES
        ${CSHARP_WRAPPER_SOURCES}
        )

################################################
#add includes
include_directories(CPP)
include_directories(CPP/Library)
include_directories(CSharp/CSharpWrapper)

################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/${CMAKE_BUILD_TYPE}/")

# for executables
set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Build/${CMAKE_BUILD_TYPE}/")
# for shared libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/${CMAKE_BUILD_TYPE}/")
# for static libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build/${CMAKE_BUILD_TYPE}/")

#################################################
#add projects
add_library(Library STATIC ${CPP_LIBRARY_SOURCE_FILES})
add_library(CSharpWrapper SHARED ${CSHARP_WRAPPER_SOURCE_FILES})
#add dependencies (what depends on what)
target_link_libraries(CSharpWrapper Library)
