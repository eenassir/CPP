#include <iostream>
#include <string>

 class Base
 {
	public:
		virtual ~Base()
		{

		}
 };

 class A : public Base {};

 class B : public Base {};


int main()
{
	Base * ptr;

	ptr = new A;
	std::cout <<dynamic_cast<B*>(ptr);

}