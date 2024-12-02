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
    std::vector<int> m_List1{};
    std::vector<int> m_List2{};    
};