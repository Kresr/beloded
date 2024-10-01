#include <iostream>

int main() {
    int i, a, b;

    for (i = 99; i >= 10; i--) {
        a = i / 10;
        b = i % 10;

        if (a != b) {
            printf("%d ", i);
        }
    }

    return 0;
}