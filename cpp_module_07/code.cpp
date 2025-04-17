#include <iostream>
#include <sstream>
#include <cstdlib>

template <typename T>
T func(T *a, T s)
{

	std::cout <<a[0]<<std::endl;
	std::cout <<a[1]<<std::endl;
	return (a[2]);
}

int main()
{
	std::string array[3];
	array[0] = "hello";
	array[1] = "world";
	array[2] = "sdfs";

	func<std::string>(array, "df");
}