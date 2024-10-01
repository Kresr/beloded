#include <iostream> 
#include <iomanip>
float my_func(float x) {
	return (2 - pow (x,2) + x);
}
int main()
{
	setlocale(LC_CTYPE, "RUS");
	float a = 8, b = 12, x, e = 0.0001;
	do {
		x = (a + b) / 2;
		if  (my_func(x) * my_func(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	} while (abs(a - b) > 2 * e);
	printf("%.4f", x);
	return 0;
}
