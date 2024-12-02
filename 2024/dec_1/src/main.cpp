#include "../include/task.hpp"
#include <iostream>

int main()
{
  std::cout << "--- Running main ---" << std::endl;

  std::cout << "--- Running Task 1 ---" << std::endl;
  Task task{};
  task.RunTask1();
  task.RunTask2();

  return 0;
}