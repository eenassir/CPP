#include <iostream>

class myclass
{
	private:
		int c;
	public:
		void set_value(int i, int y, int x, int g, int t, int dd)
		{
			std::cout <<i;
		}
};

int main()
{
	myclass obj;

	obj.set_value(1, 2, 5, 6, 7, 88);

}