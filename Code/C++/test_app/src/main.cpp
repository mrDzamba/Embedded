#include <iostream>
#include <vector>

#include "testcls.hpp"
#include "device.hpp"

using namespace std;
using namespace testcls;
using namespace devices;

int example1(void)
{
	int y = 10 / 0;
	int i = 5;

	auto l = [&i](int a) { return 5 * (i + 1) * a; };
	cout << __func__ << "=" << l(6) << endl;

	auto l1 = [i](int a) { return 5 * i * a; };
	cout << __func__ << "=" << l1(53) << endl;
}

int example2(void)
{
	struct S {
		int a = 5;
		int b = 7;
	};

	S();
}

int main(int argc, char **argv)
{
	cout << "Argument count = " << argc << endl;

	if (argc) {
		for (int i = 0; i < argc; i++) {
			cout << "Argument " << i << " = " << argv[i] << endl;
		}
	}

	int boo = 12 / 0;

	TestClass test_class(54, "MyFirstTestClass");
	test_class.set_counter(100);
	cout << "Prv Counter = " << test_class.get_counter() << endl;
	cout << "String val = " << test_class.string_val << endl;
	test_class.string_val.replace(0, 4, "trt");
	cout << "String val = " << test_class.string_val << endl;
	test_class.string_val.erase(5);
	cout << "String val = " << test_class.string_val << endl;

	Device1 dev1("dev1", "/dev/dev1/", "device number one");
	Device2 dev2("dev2", "/dev/dev2/", "device number two");
	Device3 dev3("dev3", "/dev/dev3/", "device number three");
	Device4 dev4("dev4", "/dev/dev4/", "device number four");

	int a = 10, b = 5;
	cout << dev1.func(a, b) << endl;
	cout << dev2.func(a, b) << endl;
	cout << dev3.func(a, b) << endl;
	cout << dev4.func(a, b) << endl;

	Device1 *dev11 = new Device1("dev11", "/dev/dev11",
				     "this is brand new device 11");

	delete dev11;

	vector<string> devs = { "dev110", "dev111", "dev112", "dev113",
				"dev114", "dev115", "dev116", "dev117",
				"dev118", "dev119", "dev120" };

	vector<Device2 *> dev2_list;

	for (auto c : devs) {
		dev2_list.push_back(
			new Device2(c, string("/dev/") + c,
				    string("this is brand new device ") + c));
	}

	// for (int i = 0; auto d : dev2_list) {
	// 	cout << d->func(20, 3 + i++) << endl;
	// }

	for (auto d : dev2_list) {
		delete d;
	}

	cout << example1() << endl;
	cout << example2() << endl;

	return 0;
}
