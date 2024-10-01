#include <iostream>
#include <cmath>

float equation1(float x) {
    return (2 - pow(x, 2) + x);
}

float equation2(float x) {
    return (pow(sin(x), 2) - 0.2);
}

float bisectionMethod(float (*equation)(float), float a, float b, float epsilon, int maxIterations) {
    float x;
    int iteration = 0;

    do {
        x = (a + b) / 2;

        if (equation(x) * equation(a) <= 0) {
            b = x;
        }
        else {
            a = x;
        }

        iteration++;
    } while (fabs(a - b) > 2 * epsilon && iteration < maxIterations);

    return x;
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    float a, b;
    const float epsilon = 0.001;  
    int maxIterations;

    std::cout << "Введите начальное значение a: ";
    std::cin >> a;

    std::cout << "Введите начальное значение b: ";
    std::cin >> b;

    std::cout << "Введите максимальное количество итераций n: ";
    std::cin >> maxIterations;

    
    std::cout << "Уравнение 1: 2 - x^2 + x = 0" << std::endl;
    float root1 = bisectionMethod(equation1, 1, 3, epsilon, maxIterations);
    std::cout << "Корень уравнения 1: " << root1 << std::endl << std::endl;

   
    std::cout << "Уравнение 2: sin^2(x) + 0.2 = 0" << std::endl;
    float root2 = bisectionMethod(equation2, 0, 2, epsilon, maxIterations);
    std::cout << "Корень уравнения 2: " << root2 << std::endl;

    return 0;
}


