
#pragma once

#include <string>
#include <iostream>

namespace testcls
{

class TestClass {
    public:
	TestClass(int cnt_val=0, std::string str_val="");
	~TestClass();

	int counter;
	std::string string_val;

	void set_counter(int val)
	{
		prv_counter = val;
	}

	int get_counter(void) const
	{
		return prv_counter;
	}

    private:
	int prv_counter;

}; // class TestClass

} // namespace testcls
