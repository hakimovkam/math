#include "s21_math.h"
#include <math.h>

int main() {
  
    double x = 456.1357;
    double y = 2;
    
    printf("%Lf\n%lf\n", s21_sin(y), sin(y));
    
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
    x = reader(x);
    return s21_sin((pi / 2) - x);

}

long double s21_exp(double x) {
    long double result = 1, addValue = 1, cntr =1;
        
    while (s21_fabs(addValue) > eps) {
        addValue *= x / cntr;
        cntr += 1;
        result += addValue;
        if (result > dblMax) {
            result = INFINITY;
            break;
        }
    }
    

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
    long long int mod = 0;
    mod = x / y;
    return (long double)x - mod * (long double)y; 
}

long double s21_log(double x) {
    int i = 0;
    long double result = 0, compareNumber = 0;
    
    if (x == 0) {
        result = (long double) -INFINITY;
    } else if (x == 1) {
        result = 0;
    } else {
        for (;x >- exponent; x /= exponent, i++) continue;
        for (int j = 0; j < 100; j++) {
//            printf("и");
            compareNumber = result;
            result = compareNumber + 2 * (x - s21_exp(compareNumber)) / (x + s21_exp(compareNumber));
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
//    long long int tempForExpInt = (long long int)exp;

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
    x = (long double)reader(x);
    long double result = x, temp = x, i = 1.;
    
    while (s21_fabs(result) > eps) {
        result = -1 * result * x * x / (2 * i * (2* i +1));
        i += 1.;
        temp += result;
    }
    return temp;
}

long double s21_sqrt(double x) {
// Метод половинного деления
    long double result = 0;
    long double left = 0, right = (x < 1) ? 1 : x, mid = 0;
    
    mid = (right + left) / 2;
    
    while ((mid - left) > eps) {
        if (mid * mid > x) {
            right = mid;
        } else {
            left = mid;
        }
        mid = (right + left) / 2;
    }
    return mid;
}

long double s21_tan(double x) {
    x = reader(x);
    return s21_sin(x) / s21_cos(x);
}

long double s21_factorial(int x) {
    long double result = 1;
    if (x < 0) {
        result = 0;
    } else if ( x == 0) {
        result = 1;
    } else {
        for (int i = x; i != 0; i -= 1) {
            result *= i;
        }
    }
    return result;
}


// Возвращает x в промежутке между -pi и pi
double reader(double x) {
    while (x > pi || x < -pi) {
        x += x > pi ? -2 * pi : 2 * pi;
    }
    return x;
}
