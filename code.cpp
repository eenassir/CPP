#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <sstream>
#include <fstream>

struct t_list
{
	int i;
	std::string str;
};

int get_values(int scal)
{
	return rand() % 10;
}
int main()
{
	// std::map<std::string, t_list> ll;
	// t_list mem;

	// mem.i = 10;
	// mem.str = "hello";

	// std::cout <<mem.i<<" "<<mem.str<<std::endl;

	// ll.insert(std::make_pair("one", mem));

	// std::cout <<ll["one"].i<<std::endl <<" "<< ll["one"].str<<std::endl;
	// std::cout <<mem.str.substr(3, 5);

	// std::stringstream kk;

	// kk << 2001;
	// kk << "-";
	// kk << 04;
	// kk << "-";
	// kk << 14;

	// std::string str;

	// kk >> str;
	// std::cout <<str<<std::endl;

	std::string str = "2010-30-12";
}
