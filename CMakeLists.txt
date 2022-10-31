cmake_minimum_required(VERSION 3.20)

project(fsoe_slave VERSION 0.1.0 DESCRIPTION "C FSM based on lookup tables")

option(ENABLE_TESTING "Enable Unit Tests" ON)

set(CMAKE_C_CLANG_TYDY clang-tidy; -header-filter=.; -checks=*, -llvmlibc-restrict-system-libc-header,-llvm-header-guard;)

add_executable(${PROJECT_NAME} "main.cpp")

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif(ENABLE_TESTING)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
  )