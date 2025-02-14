#include <iostream>

int main(int ac, char **av)
{
	std::string str = av[1];

	switch (str[0])
	{
		case 'D':
			std::cout <<"debug\n";
		case 'I':
			std::cout <<"intfo\n";
		case 'W':
			std::cout <<"warning\n";
		case 'E':
			std::cout <<"error\n";
			break ;
		default:
			std::cout <<"no member\n";
			break ;
	}
}