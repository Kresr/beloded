#include <iostream> 
#include <iomanip>
float my_func(float x) {
	return (1 + pow(x, 3));
}

int main()
{
	float i, s1, s2, a = 1, z, b = 5, h, x, n = 200;


	h = (b - a) / (2 * n);
	x = a + 2 * h;
	s1 = 0;
	s2 = 0;
	i = 1;
	do {
		s2 = s2 + my_func(x);
		x = x + h;
		s1 = s1 + my_func(x);
		x = x + h;
		i += 1;
	} while (i < n);

	z = h / 3 * (my_func(a) + 4 * my_func(h + a) + 4 * s1 + 2 * s2 + my_func(b));

	printf("%f", z);


	return 0;
}