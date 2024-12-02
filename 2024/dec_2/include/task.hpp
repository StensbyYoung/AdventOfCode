#pragma once
#include <vector>

class Task
{
  public:
    Task();
    ~Task() = default;

    void RunTask1();
    void RunTask2();

  private:
    std::vector<std::vector<int>> m_Reports{};
};