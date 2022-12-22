#include <stdio.h>
#include <math.h>

#define pi 3.1415926535897932384626433832795028841971693993751058209749445923
#define exponent 2.7182818284590452353602874713526624977572470936999595749669676277
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
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(int x);

int main() {
    
    double x = -41264412.123457;
  
    printf("%f", log(0));
    
//    printf("%lf\n", pow(x, 5.1));
//    printf("%Lf\n",  s21_pow(x, 5.1));
    
    return 0;
}

int s21_abs(int x) { return (x < 0) ? x * -1 : x; }

long double s21_acos(double x) {
    long double result = 0;
    return result;
}

long double s21_asin(double x) {
    long double result = 0;
    return result;
}

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

long double s21_ceil(double x) {
    long double temp = (long long int)x;
    if (s21_fabs(x) > 0 && x != temp) {
        if (x > 0) {
            temp += 1;
        }
    }
    return temp;
}

long double s21_cos(double x) {
    long double result = 0;
    return result;

}

long double s21_exp(double x) {
    long double result = 0;
    return result;
}


long double s21_fabs(double x) { return (x < 0) ? x * -1 : x; }

long double s21_floor(double x) {
    long double temp = (long long int)x;
    if (s21_fabs(x - temp) > 0 && s21_fabs(x) > 0) {
        if (x < 0) {
            temp += 1;
        }
    }
    return temp;
}

long double s21_fmod(double x, double y) {
    long double result = 0;
    return result;
}

long double s21_log(double x) {
    int i = 0;
    long double result = 0, compareNumber = 0;
    
    if (x == 0) {
        result = (long double) -INFINITY;
    } else if (x == 1) {
        result = 0;
    } else {
        for (;x >- exponent; x /= expnent, i++) continue;
        for (int j = 0; j < 100; j++) {
            compareNumber = result;
            result = compareNumber + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
        }
// Итенрационный метод Галея
// Источник ниже(формула в конце)
// https://wikicsu.ru/wiki/natural_logarithm
    }
    result += i;
    return result;
}



long double s21_pow(double base, double exp) {
    long double result = 1, temp = base;
    long long int tempForExpInt = (long long int)exp;

    if (temp < 0) {
        temp = - temp;
        result = s21_exp(exp * s21_log(temp));
        if (s21_fmod(exp, 2) != 0) {
            result = -result;
        }
    } else {
        result = s21_exp(exp * s21_log(base));
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
// Метод половинного деления
    long double result = 0;
    for (int i = 0; i < limitForCycle; i++) {
        result = (s21_pow(-1, i) * s21_pow((-1 + x), i) * (-(1/2))) / s21_factorial(i);
    }
    return result;
}

long double s21_tan(double x) {
    long double result = 0;
    return result;
}

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
