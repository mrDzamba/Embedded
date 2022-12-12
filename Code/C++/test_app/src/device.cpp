#include "device.hpp"

using namespace devices;

Device::Device(string name, string address, string description)
	: _name(name)
	, _address(address)
	, _description(description)
{
	initialized = false;
	if ((_name != "") && (_address != "") && (_description != "")) {
		initialized = true;
	}

	printf("Device\t%s\t%s\t%s\tInitialized = %s. \n", _name.c_str(),
	       _address.c_str(), _description.c_str(),
	       initialized ? "true" : "false");
}
Device::~Device()
{
	initialized = false;
	printf("Goodbuy from %s and Device %s.\n", __func__, _name.c_str());
}

int Device1::func(int a, int b)
{
	return a + b;
}

int Device2::func(int a, int b)
{
	return a - b;
}

int Device3::func(int a, int b)
{
	return a * b;
}

int Device4::func(int a, int b)
{
	return a % b;
}
