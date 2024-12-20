#include <iostream>

void foo(std::string& name)
{
	name = "hey";
}

int main()
{
	std::string arg = "world";
	foo(arg);
	std::cout << arg;

}