cmake_minimum_required(VERSION 3.0.0)
project(physics_engine VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Eigen3 REQUIRED) # find the eigen package

include_directories(${EIGEN3_INCLUDE_DIR}) # this is optional
include_directories(include) # include the include folder in this cmake environment (check how we include the .h without needing to reference the include folder)

add_library(physics_engine src/physics_engine.cpp) # creating a static library .a file
target_link_libraries(physics_engine Eigen3::Eigen) # linking eigen to our library

add_executable(example1 examples/example1.cpp) # creating an example
target_link_libraries(example1 physics_engine) # linking our example with our library
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Note:
# You will find all the output in the build folder!
# have a nice day!
