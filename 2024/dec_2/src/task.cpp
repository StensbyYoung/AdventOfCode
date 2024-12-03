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

  int element{};
  std::string line{};
  while (std::getline(file, line))
  {
    std::istringstream iss(line);
    Report_T report{};

    while (iss >> element)
    {
      report.Elements.push_back(element);
    }

    SetOrder(&report);
    m_Reports.push_back(report);
  }

  file.close();
}

void Task::RunTask1()
{
  std::cout << "--- Running Task 1 ---" << std::endl;

  for (auto& report : m_Reports)
  {
    bool unsafe{};
    
    for (int i = 0; i < report.Elements.size() - 1; ++i)
    {
      if (report.Elements[i] == report.Elements[i + 1])
      {
        unsafe = true;
        report.Order = Order_T::None;
      }

      switch (report.Order)
      {
        case Order_T::Ascending:
          if (((report.Elements[i + 1] - report.Elements[i]) > 3) ||
               (report.Elements[i + 1] < report.Elements[i]))
          {
            unsafe = true;
          }
          break;
        case Order_T::Descending:
          if (((report.Elements[i] - report.Elements[i + 1]) > 3) ||
               (report.Elements[i] < report.Elements[i + 1]))
          {
            unsafe = true;
          }
          break;
        case Order_T::None:
          [[fallthrough]];
        default:
          break; 
      }
    }

    if (!unsafe)
    {
      ++m_SafeReports;
    }
    else
    {
      m_MarkedReports.push_back(report);
    }
  }

  std::cout << "Number of safe reports: " << m_SafeReports << std::endl;
}

void Task::RunTask2()
{
  std::cout << "--- Running Task 2 ---" << std::endl;

  std::cout << "Marked Reports: " << std::endl;
  for (auto& report : m_MarkedReports)
  {
    for (auto& element : report.Elements)
    {
      std::cout << element;
    }
    std::cout << std::endl;

    int index{};
    while (index < report.Elements.size())
    {
      Report_T tempReport{};
      for (int i = 0; i < report.Elements.size(); ++i)
      {
        int element = report.Elements[i];
        if (i != index)
        {
          tempReport.Elements.push_back(element);
        }
      }

      if (!RemovalMadeSafe(tempReport))
      {
        ++index;
      }
      else
      {
        ++m_SafeReports;
        break;
      }
    }
  }

  std::cout << "Number of safe reports: " << m_SafeReports << std::endl;
}

void Task::SetOrder(Report_T* report)
{
  if (report->Elements[0] < report->Elements[1])
  {
    report->Order = Order_T::Ascending;
  }
  else if (report->Elements[1] < report->Elements[0])
  {
    report->Order = Order_T::Descending;
  }
  else 
  {
    report->Order = Order_T::None;
  }
}

bool Task::RemovalMadeSafe(Report_T& modifiedReport)
{
  bool unsafe{};
  SetOrder(&modifiedReport);

  for (int i = 0; i < modifiedReport.Elements.size() - 1; ++i)
  {
    if (modifiedReport.Elements[i] == modifiedReport.Elements[i + 1])
    {
      unsafe = true;
      modifiedReport.Order = Order_T::None;
    }

    switch (modifiedReport.Order)
    {
      case Order_T::Ascending:
        if (((modifiedReport.Elements[i + 1] - modifiedReport.Elements[i]) > 3) ||
             (modifiedReport.Elements[i + 1] < modifiedReport.Elements[i]))
        {
          unsafe = true;
        }
        break;
      case Order_T::Descending:
        if (((modifiedReport.Elements[i] - modifiedReport.Elements[i + 1]) > 3) ||
             (modifiedReport.Elements[i] < modifiedReport.Elements[i + 1]))
        {
          unsafe = true;
        }
        break;
      case Order_T::None:
        [[fallthrough]];
      default:
        break; 
    }
  }
  
  return !unsafe;
}