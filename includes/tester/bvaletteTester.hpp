#ifndef BVALETTETESTER_HPP
# define BVALETTETESTER_HPP

#include <list>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <math.h>
#include <unistd.h>
#include <iostream>

# include "./bvaletteTester_defines.hpp"

class failedTest :  public std::exception {};

bool	testBool(bool b = false, const char * file = NULL, int const lineNo = -1, int const loopIter = -1);

bool 	more_than_100 (const int& value);
bool 	more_than_10 (const int& value);
bool 	less_or_eq_10 (const int& value);
bool 	smaller_than ( int first, int second);
bool 	greater_than ( int first, int second);
bool 	same_integral_part (double first, double second);
// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

#endif
