#include <iostream>

int main() {
    double *fry = (double *)malloc(sizeof(double) * 100);
    for (int i = 0; i < 100; i++) {
        if (i == 0)
            std::cout << fry[0] << std::endl;
    }
    free(fry);
    free(fry);
    return 0;
}