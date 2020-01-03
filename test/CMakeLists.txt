FILE(GLOB TEST_FILES *.cpp)
FILE(GLOB SOURCE_FILES ../src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})