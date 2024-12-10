#include "../include/task.hpp"

Task::Task()
{
  std::filesystem::path inputPath = std::filesystem::current_path().parent_path() / "data" / "input.txt";
  m_File = std::ifstream(inputPath.c_str());

  if (!m_File)
  {
    std::cout << "Failed to open file" << std::endl;
  }
}

Task::~Task()
{
  m_File.close();
}

void Task::RunTask1()
{
  std::cout << "--- Running Task 1 ---" << std::endl;
  
  std::string line{};
  while (std::getline(m_File, line))
  {
    int index = 0;
    while ((index = line.find(m_CompareString, index + 1)) != line.npos)
    {
      m_PossibleIndices.push_back(index);
    }

    for(auto& i : m_PossibleIndices)
    {
      int startIndex = i + 4;
      int commaIndex = line.find(',', startIndex);
      int endIndex = line.find(')', startIndex);

      if ((commaIndex != line.npos) &&
          (commaIndex - startIndex <= 3) &&
          (endIndex != line.npos) &&
          (endIndex - commaIndex <= 4))
      {        
        std::string num1string{};
        for (int i = startIndex; i < commaIndex; ++i)
        {
          num1string += line[i];
        }

        std::string num2string{};
        for (int i = commaIndex + 1; i < endIndex; ++i)
        {
          num2string += line[i];
        }

        int num1;
        int num2;
        try
        {
          num1 = std::stoi(num1string);
          num2 = std::stoi(num2string);
          m_Sum += (num1 * num2);
        }
        catch(const std::invalid_argument& e)
        {
          std::cerr << e.what() << '\n';
        }
      }
    }

    std::cout << "Final sum: " << m_Sum << std::endl;
  }
}

void Task::RunTask2()
{
  std::cout << "--- Running Task 2 ---" << std::endl;
}
