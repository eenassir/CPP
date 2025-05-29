#include <iostream>
#include <vector>

void display(std::vector<int> vect)
{
	std::vector<int>::iterator it;

	it = vect.begin();
	for (; it != vect.end(); it++)
	{
		std::cout <<*it<<std::endl;
	}
}

int main()
{
	std::vector<int> vect;

	vect.push_back(1);
	vect.push_back(3);
	vect.push_back(5);
	vect.push_back(7);
	vect.push_back(9);
	vect.push_back(11);
	vect.push_back(13);

	std::vector<int>::iterator it = vect.begin();
	int key = 15;
	size_t size, mid, i;

	size_t left, right;
	left = 0;
	right = vect.size();

	while (left < right)
	{
		mid = (left + right) / 2;
		if (vect[mid] == key)
		{
			break ;
		}
		else if (vect[mid] <  key)
		{
			left = mid + 1;
		}
		else
			right = mid;
	}
	display(vect);
	std::cout <<left<<std::endl;
	std::cout <<right<<std::endl;
	vect.insert((vect.begin() + left), key);
	std::cout <<"the element didn't founded"<<std::endl;
	display(vect);
	return (-1);
}
