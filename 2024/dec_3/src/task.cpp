#include "../include/task.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>

Task::Task()
{
  std::filesystem::path inputPath = std::filesystem::current_path().parent_path() / "data" / "input.txt";
  std::ifstream file(inputPath.c_str());

  if (!file)
  {
    std::cout << "Failed to open file" << std::endl;
  }

  file.close();
}

void Task::RunTask1()
{
  std::cout << "--- Running Task 1 ---" << std::endl;
}

void Task::RunTask2()
{
  std::cout << "--- Running Task 2 ---" << std::endl;
}
