#include <iostream>
#include <stdexcept>
#include <fstream>

class interface
{
	protected:
		std::string name;
		int i;
	public:
		interface(std::string _name) : name (_name), i(16){
		}
		virtual std::string const &getName() const{
			std::cout <<"dfdfds"<<std::endl;
			return (name);
		}
		int getI(){
			return (i);
		}
		virtual void print() = 0;		
};

class concrete : public interface
{
	private:
		int j;
	public:
		concrete(const std::string & name) : interface(name), j(0){
		}
		// virtual std::string const &getName() const{
		// 	return (name);
		// }
		void print() {
			std::cout <<getName()<<std::endl;
			std::cout <<getI()<<std::endl;
		}
};

int main()
{
	concrete mem("make");
	std::cout <<mem.getName() <<std::endl;
	mem.print();
}
