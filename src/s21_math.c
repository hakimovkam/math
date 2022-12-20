#include <stdio.h>

int s21_abs(int x);
long double s21_acos(double x);

int main() {
    printf("%d\n", s21_abs(-5));
    return 0;
}

int s21_abs(int x) { return (x < 0) ? x * -1 : x; }

int s21_acos(double x) {
    
}


