#include <iostream>
#include <vector>

int main()
{
	std::vector<int> array;


	array.push_back(23);
	array.push_back(1);
	// array.push_back(10);
	// array.push_back(5);
	// array.push_back(2);
	// array.push_back(2);

	size_t  size = array.size(), i = 0, j = 0;
	int tmp;

	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	std::vector<int>::iterator it = array.begin();

	for (; it != array.end(); it++)
	{
		std::cout <<*it<<std::endl;
	}
}
