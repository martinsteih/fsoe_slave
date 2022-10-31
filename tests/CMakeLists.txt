add_executable(unit_tests "main.cpp")

target_link_libraries(unit_tests gtest pthread)

include(GoogleTest)

gtest_discover_tests(unit_tests)