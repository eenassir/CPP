#include <iostream>
#include <vector>

int find_p(std::vector<int> & vect, int tmp)
{
	if (vect.size() == 0)
		return(0);

	size_t pos = 0, size = vect.size(), middle = 0;
	bool odd = 0;

	if (tmp < vect.at(pos))
		return (1);

	if (*(vect.end() - 1) < tmp)
		return (size + 1);

	pos = middle = size / 2;
	odd = (size % 2) ? 1 : 0;
	while (middle)
	{
		middle /= 2;
		if (tmp < vect[pos - 1])
			pos -= middle;
		if (odd)
		{
			pos++;
			if (vect[pos - 1] > tmp)
				return (pos);
			else
				pos += middle;
		}
		else
			pos += middle;
		odd = (middle % 2) ? 1 : 0;
	}
	return (pos);
}

void merge(std::vector<int> & vect)
{
	if (vect.size() == 1)
		return ;
	std::vector<int>::iterator it;
	std::vector<int> tmp;

	size_t i = 0, size = vect.size() / 2;

	while (i < size)
	{
		tmp.push_back(vect.back());
		vect.pop_back();
		i++;
	}
	merge(vect);
	it = tmp.begin();
	for (; it != tmp.end(); it++)
	{
		vect.insert((vect.begin() + (find_p(vect, *it) - 1)), *it);
	}
}

void display(std::vector<int> vect)
{
	std::vector<int>::iterator it = vect.begin();

	while (it != vect.end())
	{
		std::cout <<*it << " ";
		it++;
	}
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> vect;

	vect.push_back(8);
	vect.push_back(15);
	vect.push_back(2);
	vect.push_back(11);
	vect.push_back(6);
	vect.push_back(0);
	std::cout <<"befor "<<std::endl, display(vect);
	merge(vect);
	std::cout <<"after "<<std::endl, display(vect);
}
