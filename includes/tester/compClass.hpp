#ifndef COMPCLASS_HPP
# define COMPCLASS_HPP

#include <iostream>
#include <string>
# include "./bvaletteTester_defines.hpp"

struct compClass {
bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

#endif
