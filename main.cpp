#include <iostream>
#include <vector>


int len(const char *str)
{
	if (*(str) == '\0')
		return (0);
	return (len(str + 1) + 1);
}

void display(std::vector<int> v)
{
	std::vector<int>::iterator it;

	it = v.begin();

	for (; it != v.end(); it++)
	{
		std::cout <<*it<<std::endl;
	}
}

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(5);
	v.push_back(66);
	v.push_back(33);
	v.push_back(88);
	v.push_back(54);
	int o = 1;
	int i = 1;
	v.insert(v.begin() + 2, 99);
	display(v);
}
