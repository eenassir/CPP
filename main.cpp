#include <iostream>
#include <vector>


int len(const char *str)
{
	if (*(str) == '\0')
		return (0);
	return (len(str + 1) + 1);
}

int main()
{
	// std::cout <<len("hello world");
	std::vector<int> l;

	l.push_back(1);
	std::cout <<*(l.end() - 1)<<std::endl;
}