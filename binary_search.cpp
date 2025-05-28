#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vect;

	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(6);
	vect.push_back(8);
	vect.push_back(9);
	vect.push_back(10);
	vect.push_back(61);

	std::vector<int>::iterator it = vect.begin();
	int key = 1;
	size_t size, mid, i;

	size =  vect.size();
	mid = size;

	while (mid != -1)
	{
		mid = mid / 2;
		if (vect[mid - 1] == key)
		{
			std::cout <<"the index of the key is "<<mid<<std::endl;
			return (0); 
		}
		else if (vect[(size - mid) - 1] ==  key)
		{
			std::cout <<"the index of the key is "<<(size - mid)<<std::endl;
			return (0);
		}
		if (mid == 0)
		{
			std::cout <<"the element isn't founded"<<std::endl;
			return (0);
		}
	}





}
