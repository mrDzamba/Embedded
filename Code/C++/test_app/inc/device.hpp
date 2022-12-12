
#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace devices
{

class Device {
    public:
	bool initialized;

	Device(string name, string address, string description);
	~Device();

    private:
	int init();
	int destroy();

	string _name;
	string _address;
	string _description;

}; // class Device

class Device1 : public Device {
    public:
	Device1(string name, string address, string description)
		: Device(name, address, description)
	{
	}
	int func(int a, int b);
};

class Device2 : public Device {
    public:
	Device2(string name, string address, string description)
		: Device(name, address, description)
	{
	}
	int func(int a, int b);
};

class Device3 : public Device {
    public:
	Device3(string name, string address, string description)
		: Device(name, address, description)
	{
	}
	int func(int a, int b);
};

class Device4 : public Device {
    public:
	Device4(string name, string address, string description)
		: Device(name, address, description)
	{
	}
	int func(int a, int b);
};

} // namespace devices
