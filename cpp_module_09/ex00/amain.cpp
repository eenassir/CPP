#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <set>

int main(int ac, char **av)
{
	std::ifstream infile(av[1]);

	char tmp[1]*;

	char l[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

	tmp[0] = l;

	std::cout <<tmp[0]<<std::endl;
}
