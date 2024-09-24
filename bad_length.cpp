#include "bad_length.h"
#include <iostream>
using namespace std;

const char* bad_length::what() const noexcept
{
	return "Bad length exception ";
}
