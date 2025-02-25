#include <iostream>
#include <iomanip>

class point
{
	private:
		int i;
		int x;
		int y;
		int z;
	public:
		point(int v0 = 0, int v1 = 0, int v2 = 0, int v3 = 0) : i(v0), x(v1), y(v2), z(v3){}
		point operator+(const point &other) const
		{
			return point(i + other.i, x + other.x, y + other.y, z + other.z);
		}
		point operator/(const point &other) const
		{
			return point(i / other.i, x / other.x, y / other.y, z / other.z);
		}
		void desplay() const
		{
			std::cout << i<<"\n";
			std::cout << x<<"\n";
			std::cout << y<<"\n";
			std::cout << z<<"\n";
			std::cout <<"\n";
		}
};

int main()
{
	point p1(1, 2, 3, 4);
	p1.desplay();
	point p2(5, 6, 7, 8);
	p2.desplay();
	p1 = p1 + p2;
	p1.desplay();
}