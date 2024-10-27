#include <iostream>
#include <cstring>
#include <iomanip>
#include "tableoutput.h"
#include "taylorrow.h"

void tkach::outputRow(double start, size_t maxkolvo, const double error)
{
  const size_t setwx = 13;
  const char *errormsg = "<MATH ERROR>";
  const size_t error_len = std::strlen(errormsg) + 5;
  std::cout << std::fixed;
  std::cout << std::setw(setwx) << std::setprecision(1) <<  start;
  std::cout << " ";
  try
  {
    std::cout << std::setw(setwx)  << std::setprecision(4) <<  tkach::coshTaylor(start, maxkolvo, error) << " ";
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(error_len) << "<MATH ERROR>";
    std::cout << " ";
  }
  std::cout << std::setw(setwx) << std::setprecision(4) << tkach::stdCosh(start);
  std::cout << "\n";
}
