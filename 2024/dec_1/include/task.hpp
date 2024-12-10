#pragma once
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <algorithm>

class Task
{
  public:
    Task();
    ~Task() = default;

    void RunTask1();
    void RunTask2();

  private:
    std::vector<int> m_List1{};
    std::vector<int> m_List2{};    
};