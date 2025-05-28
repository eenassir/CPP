#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <sstream>
#include <fstream>

// void insert_values(std::vector<int> & vect, std::vector<int> & k)
// {
// 	std::vector<int>::iterator it;
// 	size_t size;
//
// 	it = k.begin();
// 	for (; it != k.end(); it++)
// 	{
// 		if (vect.back() < *it)
// 		{
// 			vect.push_back(*it);
// 		}
// 		else
// 		{
// 			size = vect.size();
// 			while (size > 0)
// 			{
// 				size = size / 2;
// 				if (vect.at(size) > *it)
// 				{
// 					vect.insert((vect.begin() + size), *it);
// 					break ;
// 				}
// 			}
//
// 		}
// 	}
// }

void m(std::vector<int> &vect)
{	
	std::vector<int>::iterator it;
	int i = 0;
	it = vect.end();
	it--;

	std::vector<int> k;


	if (vect.size() <= 1)
		return ;
	size_t size = vect.size();
	for (;it != vect.begin() && i < size / 2; it--, i++)
	{
		k.push_back(*it);
		vect.pop_back();
	}
	m(vect);
	m(k);
	it = k.end();
	it--;
	size = vect.size();
	i = 0;

	for (; it != (k.begin() - 1); it--)
	{
		if (vect.back() < *it)
			vect.push_back(*it);
		else if (vect.at(0) > *it)
		{
			size = vect.size();
			while (size > 0)
			{
				size = size / 2;
				if (vect.at(size) > *it)
				{
					vect.insert((vect.begin() + size), *it);
					break ;
				}
				else if (vect.at(size) < *it)
				{
					vect.insert((vect.begin() + size), *it);
					break ;
				}
			}
		}
	}
}

int main(int ac, char **av)
{
	std::vector<int> vect;
	// std::vector<int> k;

	vect.push_back(2);
	vect.push_back(11);
	vect.push_back(40);
	vect.push_back(1);
	vect.push_back(0);
	vect.push_back(4);
	vect.push_back(21);
	vect.push_back(99);
	vect.push_back(88);
	m(vect);
	// معكم ولو بجلس علي الجمر عادي | أغنية الحلقة 29 | كش ملك
	// vect.push_back(0);
	// k.push_back(2);
	// k.push_back(21);
	// k.push_back(100);
	// k.push_back(20);
	// k.push_back(20);
	// k.push_back(10);
	std::vector<int>::iterator it;

	it = vect.begin();
	for (; it != vect.end(); it++)
	{
		std::cout <<*it<<std::endl;
	}
}
