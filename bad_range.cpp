#include "bad_range.h"
#include <iostream>
using namespace std;

const char* bad_range::what() const noexcept
{
	return "Bad range exception ";
}