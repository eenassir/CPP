#include <iostream>
#include <sstream>

void show(int value)
{
	std::cout <<value;
}

int main()
{
	int i;
	// i = 0;

	// for (;;i++)
	// {
	// 	if (i >= 5)
	// 		break ;
	// 	std::cout <<i<<std::endl;
	// }
	// std::cout <<"---------------------------"<<std::endl;
	// std::cout <<"---------------------------"<<std::endl;
	// std::cout <<"---------------------------"<<std::endl;
	// std::cout <<i<<std::endl;
	std::string str = "56456";
	std::stringstream tmp;
	tmp << str.c_str();
}