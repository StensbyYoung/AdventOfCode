#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Task
{
  public:
    Task();
    ~Task();

    void RunTask1();
    void RunTask2();

  private:
    std::ifstream    m_File;
    std::string      m_CompareString{"mul("};
    std::vector<int> m_PossibleIndices{};
    int              m_Sum{};
};