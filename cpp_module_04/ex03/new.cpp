#include <iostream>
#include <cstdlib>

class base
{
	private:
		int *ptr;
	public:
		base()
		{
			ptr = new int;
			std::cout <<"def_called\n";
		}
		base(const int i)
		{
			std::cout <<"co_called\n";
			this->ptr = new int;
			*this->ptr = i;
		}
		base (const base &mem)
		{
			std::cout <<"copy_called\n";
			this->ptr = new int(*mem.ptr);
		}

		base &operator=(const base &mem)
		{
			if (this == &mem)
				return (*this);
			delete this->ptr;
			ptr = new int(*mem.ptr);
			return (*this);
		}
		~base()
		{
			delete this->ptr;
		}
};

void f()
{
	system("leaks a.out");
}

int main()
{
	atexit(f);
	base c;
	base a(4);
	base b(a);
}