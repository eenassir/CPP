#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sys/time.h>

template<typename T>
void g(T &list)
{
	typedef typename T::iterator iter;
	iter it = list.begin();
	for (; it != list.end(); it++)
	{
		std::cout <<*it<<" ";
	}
}

// Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
std::vector<size_t> generateJacobsthal(size_t max_needed)
{
	std::vector<size_t> jacobsthal;
	if (max_needed == 0) return jacobsthal;
	
	jacobsthal.push_back(0);
	if (max_needed == 1) return jacobsthal;
	
	jacobsthal.push_back(1);
	
	size_t prev2 = 0, prev1 = 1;
	while (true)
	{
		size_t next = prev1 + 2 * prev2;
		if (next > max_needed) break;
		jacobsthal.push_back(next);
		prev2 = prev1;
		prev1 = next;
	}
	return jacobsthal;
}

// Generate optimal insertion order using Jacobsthal sequence
std::vector<size_t> generateInsertionOrder(size_t pend_size)
{
	std::vector<size_t> order;
	if (pend_size == 0) return order;
	
	std::vector<size_t> jacobsthal = generateJacobsthal(pend_size);
	std::vector<bool> inserted(pend_size, false);
	
	// Insert elements in Jacobsthal order
	for (size_t i = 1; i < jacobsthal.size(); i++)
	{
		size_t jacob_num = jacobsthal[i];
		if (jacob_num > 0 && jacob_num <= pend_size)
		{
			// Insert from jacobsthal[i] down to jacobsthal[i-1] + 1
			size_t start = (i > 1) ? jacobsthal[i-1] + 1 : 1;
			for (size_t j = jacob_num; j >= start && j >= 1; j--)
			{
				if (!inserted[j-1])
				{
					order.push_back(j-1);
					inserted[j-1] = true;
				}
			}
		}
	}
	
	// Insert any remaining elements
	for (size_t i = 0; i < pend_size; i++)
	{
		if (!inserted[i])
		{
			order.push_back(i);
		}
	}
	
	return order;
}

template<typename T>
void binary_insertion(T &vect, int nbr, size_t search_limit)
{
	size_t left, right, mid;
	left = 0;
	right = (search_limit < vect.size()) ? search_limit : vect.size();
	
	while (left < right)
	{
		mid = (left + right) / 2;
		if (vect[mid] == nbr)
			break;
		else if (vect[mid] < nbr)
			left = mid + 1;
		else
			right = mid;
	}
	vect.insert(vect.begin() + left, nbr);
}

template<typename T>
void merge(T & vect)
{
	if (vect.size() <= 1)
		return;
	
	// Handle the case of exactly 2 elements
	if (vect.size() == 2)
	{
		if (vect[0] > vect[1])
		{
			int tmp = vect[0];
			vect[0] = vect[1];
			vect[1] = tmp;
		}
		return;
	}
	
	int straggler;
	bool has_straggler = false;
	if (vect.size() % 2 != 0)
	{
		has_straggler = true;
		straggler = vect.back();
		vect.pop_back();
	}
	
	// Create pairs and ensure larger element is first in each pair
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vect.size(); i += 2)
	{
		int a = vect[i];
		int b = vect[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	
	// Create temporary container with larger elements for recursive sorting
	T larger_elements;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		larger_elements.push_back(pairs[i].first);
	}
	
	// Recursively sort the larger elements
	merge(larger_elements);
	
	// Build main chain (sorted larger elements) and pend chain (smaller elements)
	T main_chain = larger_elements;
	T pend_chain;
	
	// Reconstruct pairs in the order of sorted larger elements
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == main_chain[i])
			{
				pend_chain.push_back(pairs[j].second);
				break;
			}
		}
	}
	
	// Insert first element of pend_chain at the beginning
	if (!pend_chain.empty())
	{
		main_chain.insert(main_chain.begin(), pend_chain[0]);
		pend_chain.erase(pend_chain.begin());
	}
	
	// Use Jacobsthal sequence for optimal insertion order
	std::vector<size_t> insertion_order = generateInsertionOrder(pend_chain.size());
	
	for (size_t i = 0; i < insertion_order.size(); i++)
	{
		size_t idx = insertion_order[i];
		if (idx < pend_chain.size())
		{
			// Calculate search limit: position of corresponding larger element + inserted elements so far
			size_t search_limit = idx + i + 2; // +1 for the first inserted element, +1 for current position
			binary_insertion(main_chain, pend_chain[idx], search_limit);
		}
	}
	
	// Insert straggler if it exists
	if (has_straggler)
	{
		binary_insertion(main_chain, straggler, main_chain.size());
	}
	
	vect = main_chain;
}

int main(int ac, char **av)
{
	if (ac <= 1)
		return (std::cerr <<"Error"<<std::endl, 1);
	std::string buffer(av[1]);
	for (size_t i = 2; av[i] ; i++)
	{
		buffer.push_back(' ');
		for(size_t j = 0; av[i][j]; j++)
			buffer.push_back(av[i][j]);
	}
	for (size_t i = 0; i < buffer.size(); i++)
	{
		if (!(buffer[i] >= '0' && buffer[i] <= '9') && (buffer[i] != ' ' && buffer[i] != '+'))
			return (std::cerr<<"Error"<<std::endl, 1);
		if (buffer[i] == '+' && buffer[i + 1] == '+')
			return (std::cerr<<"Error"<<std::endl, 1);
		if ((buffer[i] >= '0' && buffer[i] <= '9') && buffer[i + 1] == '+')
			return (std::cerr<<"Error"<<std::endl, 1);
	}
	for (size_t i = 0; i < buffer.size(); i++)
		(buffer[i] == '+') && (buffer[i] = ' ');
	std::stringstream tmp;
	int nbr, count;
	std::deque<int> cont_d;
	std::vector<int> cont_v;
	for (size_t i = 0; i < buffer.size(); i++)
	{
		count = 0;
		for (; buffer[i] && buffer[i] == ' '; i++){}
		size_t s = i;
		for(; buffer[s] && (buffer[s] >= '0' && buffer[s] <= '9'); s++, count++){}
		if (count == 0) continue; // Skip if no digits found
		char buffer_tmp[count + 1];
		size_t y = 0;
		for (; buffer[i] && (buffer[i] >= '0' && buffer[i] <= '9'); i++, y++)
			buffer_tmp[y] = buffer[i];
		buffer_tmp[y] = '\0';
		tmp.clear();
		std::string ll(buffer_tmp);
		tmp << ll;
		tmp >> nbr;
		if (tmp.fail())
			return (std::cerr<<"Error"<<std::endl, 1);
		cont_d.push_back(nbr);
		cont_v.push_back(nbr);
		i--; // Adjust for the outer loop increment
	}
	
	// Check for duplicates
	for (size_t i = 0; i < cont_v.size(); i++)
	{
		for (size_t j = i + 1; j < cont_v.size(); j++)
		{
			if (cont_v[i] == cont_v[j])
				return (std::cerr<<"Error"<<std::endl, 1);
		}
	}
	
	std::cout <<"Before : ", g(cont_v), std::cout<<std::endl;
	timeval start, end;
	gettimeofday(&start, NULL);
	merge(cont_v);
	gettimeofday(&end, NULL);
	double dur_us = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	std::cout <<"After : ", g(cont_v), std::cout<<std::endl;
	std::cout <<"Time to process a range of "<<cont_v.size()<<" element with std::vector<int> : "<<std::fixed<<std::setprecision(5)<<dur_us<<"us"<<std::endl;
	gettimeofday(&start, NULL);
	merge(cont_d);
	gettimeofday(&end, NULL);
	dur_us = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
	std::cout <<"Time to process a range of "<<cont_d.size()<<" element with std::deque<int> : "<<std::fixed<<std::setprecision(5)<<dur_us<<"us"<<std::endl;
}