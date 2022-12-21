#include <stdio.h>
#include <math.h>

#define pi 3.1415926535897932384626433832795028841971693993751058209749445923
#define limitForCycle 5000

int s21_abs(int x);
long double s21_acos(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(int x);

int main() {
    
    double x = 41264412.123457;
    
//    printf("%lf\n", pow(x, 5.2));
//    printf("%Lf\n",  s21_pow(x, 5.2));
    
    return 0;
}

int s21_abs(int x) { return (x < 0) ? x * -1 : x; }

//long double s21_acos(double x) {}

//long double s21_asin(double x) {}

long double s21_atan(double x) {
    long double result = 0;
    if (s21_fabs(x) < 1) {
        for (int i = 0; i < limitForCycle; i++) {
            result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
        }
    } else {
        for (int i = 0; i < limitForCycle + 2000; i++) {
            result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
        }
        result = pi * s21_sqrt(x * x) / (2 * x) - result;
    }
    return result;
}

//long double s21_ceil(double x) {}

//long double s21_cos(double x) {

//}

//long double s21_exp(double x) {}

long double s21_fabs(double x) { return (x < 0) ? x * -1 : x; }

//long double s21_floor(double x) {}

//long double s21_fmod(double x) {}

//long double s21_log(double x) {}

long double s21_pow(double base, double exp) {
    long double result = 0;
    for (int i = 0; i > exp; i++) {
        result += base;
    }
    return result;
}

long double s21_sin(double x) {
    long double result = 0;
    for (;x < -2 * pi || 2 * pi < x;) {
        if (x > 2 * pi) {
            x -= 2 * pi;
        } else {
            x += 2 * pi;
        }
    }
    for (int i = 0; i < 500; i++) {
        result += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_factorial(2 * i + 1);
    }
    return result;
}

long double s21_sqrt(double x) {
    long double result = 0;
    for (int i = 0; i < limitForCycle; i++) {
        result = (s21_pow(-1, i) * s21_pow((-1 + x), i) * (-(1/2))) / s21_factorial(i);
    }
    return result;
}

//long double s21_tan(double x) {}

long double s21_factorial(int x) {
    long double result = 0;
    if (x < 0) {
        result = 0;
    } else if ( x == 0) {
        result = 1;
    } else {
        result = x * s21_factorial(x - 1);
    }
    return result;
}
