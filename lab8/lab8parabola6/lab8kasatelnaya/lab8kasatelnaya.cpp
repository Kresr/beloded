#include <iostream> 
#include <iomanip>
float my_func(float x) {
	return (2 - pow(x,2) + x) ;
}
float my_funcz(float x) {
	return((-(2 * x)) + 1);
}
int main()
{
	float a = 8, b = 12, x, x1, e = 0.0001;
	if  (my_func(a) * my_funcz(b) > 0) {
		x1 = a;
	}
	else {
		x1 = b;
	}
	do {
		x = x1;
		x1 = x - my_func(x) / my_funcz(x);
	} while (abs(x1 - x) > e);

	printf("%.4f", x1);

	return 0;
}
