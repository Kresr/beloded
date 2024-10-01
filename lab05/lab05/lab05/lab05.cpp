#include <iostream> 
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double v, w, b = -5.4, m = 4, u = 0.005e-4, k, i;
	for (i = 0; i < 4; i++)
	{
		printf("Введите k:");
		scanf_s("%le", &k);
		v = u + b - 2 * sqrt(0.7 * k + m);
		w = 100 * exp(-0.2 * u) - log(8.1 * u);
		printf("v = %5.3f\t", v);
		printf("w = %5.3f\n", w);
	}

	return (0);
}