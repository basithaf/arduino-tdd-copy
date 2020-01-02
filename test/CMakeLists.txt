include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} testdefault.cpp test_rules.cpp test_board.cpp ../src/rules.cpp ../src/board.cpp)
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})