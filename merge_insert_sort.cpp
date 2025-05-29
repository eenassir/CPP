#include <iostream>
#include <vector>
#include <deque>

void display(std::vector<int> vect)
{
	std::vector<int>::iterator it;

	it = vect.begin();
	// std::cout <<"------------------------------------------"<<std::endl;
	for (; it != vect.end(); it++)
	{
		std::cout <<*it<<std::endl;
	}
	std::cout <<"------------------------------------------"<<std::endl;
}

void binary_search(std::vector<int> &vect, int nbr)
{
	size_t left, right, mid;

	left = 0;
	right = vect.size();

	while (left < right)
	{
		mid = (left + right) / 2;
		if (vect[mid] == nbr)
			break ;
		else if (vect[mid] < nbr)
			left = mid + 1;
		else
			right = mid;
	}
	vect.insert(vect.begin() + left, nbr);
}
void merge(std::vector<int> & vect)
{
	if (vect.size() <= 2)
		return ;
	std::vector< std::vector<int> > collect;
	std::vector<int>::iterator it;
	size_t size = vect.size() / 2, i = 0;
	while (i < size)
	{
		std::vector<int> k;
		k.push_back(vect.back());
		vect.pop_back();
		k.push_back(vect.back());
		vect.pop_back();
		collect.push_back(k);
		i++;
	}
	i = 0;
	for (; i <  collect.size(); i++)
	{
		if (collect[i][0] < collect[i][1])
		{
			int tmp = collect[i][0];
			collect[i][0] = collect[i][1];
			collect[i][1] = tmp;
		}
	}
	std::vector<int> main_chain;
	std::vector<int> pain_chain;
	i = 0;
	std::vector< std::vector<int> >::iterator itt = collect.begin();
	for (; itt != collect.end(); itt++)
	{
		pain_chain.push_back(itt->back());
		itt->pop_back();
		main_chain.push_back(itt->back());
		itt->pop_back();
	}
	merge(main_chain);
	if (main_chain[0] > main_chain[1])
	{
		int tmp = main_chain[0];
		main_chain[0] = main_chain[1];
		main_chain[1] = tmp;
	}
	// display(main_chain);
	it = pain_chain.begin();
	for (; it != pain_chain.end(); it++)
	{
		binary_search(main_chain, *it);
	}
	// display(main_chain);
	vect = main_chain;
	i = 0;
	for (; i <  vect.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vect[i] < vect[j])
			{
				int tmp = vect[j];
				vect[j] = vect[i];
				vect[i] = tmp;
			}
		}
	}
}


int main()
{
	std::vector<int> vect;

	vect.push_back(1);
	vect.push_back(3);

	vect.push_back(2);
	vect.push_back(16);

	vect.push_back(4);
	vect.push_back(4);
	
	vect.push_back(41);

	vect.push_back(6);

	vect.push_back(7);
	vect.push_back(14);


	merge(vect);
	// binary_search(vect, 5);
	display(vect);
}
