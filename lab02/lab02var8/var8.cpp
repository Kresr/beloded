#include <iostream>
void main()
{
	double s, t, x = 0.1, j = 12, y = 5e6;
	s = 0.4 * x - 1 / j * tan(y);
	t = s - sin(s);
	std::cout << " s= " << s;
	std::cout << " t= " << t;
}