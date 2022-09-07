# cmake ../
# cmake --build ./
# Minimun to CMake
cmake_minimum_required(VERSION 3.5)

# Name your project
project(webScrapping)
set(EXECUTABLE_NAME "webScrapping")


# Use the standar for C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add external library
find_package(Poco REQUIRED COMPONENTS Foundation Net NetSSL)
include_directories(${POCO_INCLUDE_DIR})

# In  clude your files
file(
  GLOB_RECURSE
  source_files
  src/*
)
# Name the programme and add files to your project
add_executable(
  ${EXECUTABLE_NAME}
  ${source_files}
)

# End the includes
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${Poco_LIBRARIES})
