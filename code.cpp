#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <sstream>
#include <fstream>

int get_values(int scal)
{
	return rand() % 10;
}
int main()
{
	std::ifstream infile("data.csv");
	if (infile.fail())
		return (1);
	std::map<std::string, double> map;
	std::string buffer;

		double h = 2;
	while (getline(infile, buffer))
	{
		int i = 0;
		h++;
		char tmp[11];
		for(; buffer[i] && buffer[i] != ','; i++)
		{
			tmp[i] = buffer[i];
		}
		std::string tmp_buff = tmp;
		map.insert(std::pair<std::string, double>(tmp_buff, h));
		std::cout <<h<<" "<<tmp_buff<<std::endl;
	}

}

// template<typename T>
// void iter()

// int main()
// {
// }

// class Awesome
// {
// 	public:
// 		Awesome(): _n(0){}
// 		Awesome(int n): _n(n){}

// 		Awesome &operator=(Awesome &a) {_n = a._n; return (*this);}

// 		bool operator==(Awesome const &rhs) const {return (this->_n ==rhs._n);}
// 		bool operator!=(Awesome const &rhs) const {return (this->_n != rhs._n);}
// 		bool operator>(Awesome const &rhs) const {return (this->_n > rhs._n);}
// 		bool operator<(Awesome const &rhs) const {return (this->_n < rhs._n);}
// 		bool operator>=(Awesome const &rhs) const {return (this->_n >= rhs._n);}
// 		bool operator<=(Awesome const &rhs) const {return (this->_n <= rhs._n);}
// 		int get_n() const{return (_n);}
// 	private:
// 		int _n;
// };

// std::ostream &operator<<(std::ostream &o, const Awesome &a){o << a.get_n(); return (o);}

// int main()
// {
// 	Awesome a(2), b(4);
	
// 	swap(a, b);
// 	std::cout <<a<<" "<<b<<std::endl;
// 	std::cout <<max(a,b)<<std::endl;
// 	std::cout <<min(a,b)<<std::endl;
// 	return (0);
// }

// class Awesome
// {
// 	private:
// 		int _n;
// 	public:
// 		Awesome(void) : _n(42){return ;}
// 		int get(void) const {return (this->_n);}
// };

// std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {o << rhs.get();return (o);}

// template<typename T>
// void print(T const &x)
// {
// 	std::cout <<x<<std::endl;
// }

// int main()
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome l[2];

// 	iter(tab, 5, print);
// 	iter(l, 5, print);
// }