# Specify the minimum version.
cmake_minimum_required(VERSION 3.7)

# Specify the project name.
project(myapp)

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

set(
  PROG_SRCS
  source/mainwindow.cpp
  source/observer.h
  source/main.h
  test/mytest.cpp
)

# Request the required wxWidgets libs.
find_package(wxWidgets COMPONENTS core base xrc REQUIRED)

# Include the wxWidgets use file to initialize various settings.
include(${wxWidgets_USE_FILE})

add_executable(mytest ${PROG_SRCS}) # add this executable

target_link_libraries(mytest PRIVATE gtest) # link google test to this executable
target_link_libraries(mytest PRIVATE ${wxWidgets_LIBRARIES})


# Add sources.
set(
  PROG_SRCS
  source/main.cpp
  source/mainwindow.cpp
  source/observer.h
  source/main.h
)

# Request the required wxWidgets libs.
find_package(wxWidgets COMPONENTS core base xrc REQUIRED)

# Include the wxWidgets use file to initialize various settings.
include(${wxWidgets_USE_FILE})

# Specify what is needed to create the main target.
add_executable(${PROJECT_NAME} ${PROG_SRCS})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


# Specify how to install the binary.
install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)





