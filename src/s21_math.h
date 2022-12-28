#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define pi 3.1415926535897932384626433
#define exponent 2.718281828459045235360287471352662
#define limitForCycle 5000
#define eps 1e-9
#define dblMax 1.7976931348623157E+308

int s21_abs(int x); // +
long double s21_acos(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x); // +
long double s21_cos(double x); // +
long double s21_exp(double x); // +
long double s21_fabs(double x); // +
long double s21_floor(double x); // +
long double s21_fmod(double x, double y); // +
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x); // +
long double s21_sqrt(double x); // +
long double s21_tan(double x); // +
long double s21_factorial(int x);

double reader(double x);

#endif  // SRC_S21_MATH_H_
