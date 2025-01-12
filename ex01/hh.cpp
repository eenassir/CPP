#include <iostream>

void f()
{
	system("leaks a.out");
}

int main()
{
	std::string line;
	std::getline(std::cin, line, 'g');
	std::cout <<line;
}