#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <sstream>
#include <fstream>

void printarray(int *tab, int size)
{
	int i = 0;
	std::cout << "----------------<>-----------" << std::endl;
	for (; i < size / 4; i++)
	{
		std::cout << ">" << tab[i] << std::endl;
	}
	std::cout << "----------------<>-----------" << std::endl;
}

// void merge(int *tab, int size)
// {
// 	if (size / 4 <= 1)
// 		return ;
// 	int tmp1[size / 8];
// 	int tmp2[size / 4 - size / 8];

// 	int i = 0;
// 	for (; i < size / 8; i++)
// 	{
// 		tmp1[i] = tab[i];
// 	}
// 	int j = 0;
// 	for (; i < size / 4; i++)
// 	{
// 		tmp2[j] = tab[i];
// 		j++;
// 	}

// 	printarray(tmp1, sizeof(tmp1));
// 	printarray(tmp2, sizeof(tmp2));
// 	merge(tmp1, sizeof(tmp1));
// 	merge(tmp2, sizeof(tmp2));
// }

std::vector<int> merge(std::vector< std::vector<int> > l)
{
	if (l.size() <= -1)
		return (*l.begin());
	std::vector<int> tmp1;
	std::vector<int> tmp2;
	std::vector<int>::iterator it;

	it = l.begin()->begin();
	int i = 0;
	for (; it != l.begin()->end();)
	{
		std::cout << *it << std::endl;
		it++;
		i++;
	}
	return (*l.begin());
}

int m(std::vector<int> &vect)
{	
	std::vector<int>::iterator it;
	int i = 0;
	it = vect.end();
	it--;

	std::vector<int> k;
	if (vect.size() == 1 || k.size() == 1)
	{
		if (*(vect.end() - 1) < m(vect))
		vect.push_back(m(vect));
	}
	for (;it != vect.begin() &&  i < 7 / 2; it--, i++)
	{
		k.push_back(*it);
		vect.pop_back();
	}
	// it = vect.begin();
	// std::cout <<"------------------------"<<std::endl;
	// for (;it != vect.end();it++)
	// {
	// 	std::cout<<*it<<std::endl;
	// }


	// it = k.begin();
	// std::cout <<"-------------------------"<<std::endl;
	// for (;it != k.end();it++)
	// {
	// 	std::cout<<*it<<std::endl;
	// }
	// std::cout <<"-------------------------"<<std::endl;
	
	return (*vect.begin());
}

int main(int ac, char **av)
{
	std::vector<int> vect;

	vect.push_back(2);
	vect.push_back(11);
	vect.push_back(40);
	vect.push_back(1);
	vect.push_back(0);
	vect.push_back(4);
	vect.push_back(21);

	m(vect);

	std::vector<int>::iterator it;

	it = vect.begin();
	std::cout <<"------------------------"<<std::endl;
	for (;it != vect.end();it++)
	{
		std::cout<<*it<<std::endl;
	}
}