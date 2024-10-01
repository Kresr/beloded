#include <iostream> 
#include <iomanip>
float my_func(float x) {
	return (5 - pow(x,2));
}
int main()
{
	float  s, a = 8, b = 12, h, x, n = 200;
	h = (b - a) /  n;
	x = a;
	s = 0; 
	do {
		s = s + h * (my_func(x) + my_func(x + h)) / 2;
		x = x + h;

	} while (x < (b - h));
	printf("%f", s);
	return 0;
}
