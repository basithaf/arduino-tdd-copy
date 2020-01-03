include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(${PROJECT_NAME} testdefault.cpp test_rules.cpp test_board.cpp test_game.cpp ../src/rules.cpp ../src/board.cpp arduino.cpp)
target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})