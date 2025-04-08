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
	int *array = new int[3];
	int *n;

	array[0] = 1;
	array[5] = 17;
	std::cout <<array[0]<<std::endl;
	std::cout <<array[5]<<std::endl;

}
