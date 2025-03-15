#include  <iostream>

class myclass
{
	public:
		myclass(){std::cout << "default\n";}
		myclass(const myclass& cpy){std::cout << "copy constructor\n";}
		myclass& operator=(const myclass& cpy) {std::cout << "assignment operator\n"; return (*this);}
};

int main()
{
	myclass obj1;
	myclass obj2;
	obj2 = obj1;

}