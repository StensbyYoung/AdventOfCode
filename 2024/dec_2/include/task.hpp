#pragma once
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>

enum class Order_T
{
  Ascending,
  Descending,
  None
};

struct Report_T
{
  std::vector<int> Elements{};
  Order_T          Order{Order_T::None};            
};

class Task
{
  public:
    Task();
    ~Task() = default;

    void RunTask1();
    void RunTask2();

  private:
    void SetOrder(Report_T* report);
    bool IsReportUnsafe(Report_T& modifiedReport);

    std::vector<Report_T> m_Reports{};
    std::vector<Report_T> m_MarkedReports{};
    int                   m_NumSafe{};
    int                   m_NumSafeAfterModify{};
};