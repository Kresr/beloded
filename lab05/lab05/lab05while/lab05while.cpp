#include <iostream> 
#include <iomanip>


int main()
{
	setlocale(LC_CTYPE, "Russian");

	double v, w, b = -5.4, m = 4, u = 0.005e-4, k;
	k = 3;

	while (k <= 4) {


		v = u + b - 2 * sqrt(0.7 * k + m);
		w = 100 * exp(-0.2 * u) - log(8.1 * u);

		printf("v = %5.3f\t", v);
		printf("w = %5.3f\n", w);
		k += 0.2;
	}

	return 0;
}
