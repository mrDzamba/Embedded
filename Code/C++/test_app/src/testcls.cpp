
#include "testcls.hpp"
#include "device.hpp"

namespace testcls
{
TestClass::TestClass(int cnt_val, std::string str_val)
	: counter(cnt_val)
	, string_val(str_val)
{
	printf("Welcome to %s.\n", __func__);
	for (size_t i = 0; i < 10; i++) {
		for (size_t j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (size_t i = 10; i > 0; i--) {
		for (size_t j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("Counter = %d\n", counter);
}

TestClass::~TestClass(void)
{
	printf("Goodbuy from %s.\n", __func__);
}

} // namespace testcls


