#pragma once
#include <exception>
using namespace std;

class bad_range : public exception
{
public:
	virtual const char* what() const noexcept override;
};

