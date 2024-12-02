#include "../include/task.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <algorithm>

Task::Task()
{
  std::filesystem::path inputPath = std::filesystem::current_path().parent_path() / "data" / "input.txt";
  std::ifstream file(inputPath.c_str());

  if (!file)
  {
    std::cout << "Failed to open file" << std::endl;
  }

  for (int a, b; file >> a >> b;)
  {
    m_List1.push_back(a);
    m_List2.push_back(b);
  }

  std::sort(m_List1.begin(), m_List1.end());
  std::sort(m_List2.begin(), m_List2.end());

  file.close();
}

void Task::RunTask1()
{
  int totalDistance{};

  for (int i = 0; i < m_List1.size(); ++i)
  {
    totalDistance += std::abs(m_List1[i] - m_List2[i]);
  }

  std::cout << "Total Distance: " << totalDistance << std::endl;
}

void Task::RunTask2()
{
  int similarityScore{};
  int count{};

  for (auto& firstId : m_List1)
  {
    count = 0;
    for (auto& secondId : m_List2)
    {
      if (firstId == secondId)
      {
        ++count;
      }
    }

    similarityScore += (firstId * count);
  }

  std::cout << "Similarity Score: " << similarityScore << std::endl;
}