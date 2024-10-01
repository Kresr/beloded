#include <iostream>
void main()
{
	double z, u, c = 1.4, x = 0.2e-4, y = 0.5;
	z = exp(c * x) / y + 3;
	
	u = sqrt( pow (z,3) - 0.1 * z);
	

	std::cout << " z= " << z;

	std::cout << " u= " << u;
}
