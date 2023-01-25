#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define S21_PI 3.1415926535897932384626433
#define EXP 2.718281828459045235360287471352662
#define LIMITFORCYCLE 5000
#define S21_EPS 1e-100
#define DBLMAX 1.7976931348623157E+308
#define S21_EXP 2.718281828459045235360287471352662
#define S21_INF 1.0 / 0.0
#define S21_NINF -S21_INF
#define S21_NAN __builtin_nanf("0x7FC00000")
#define S21_ISNAN(x) __builtin_isnan(x)
#define S21_ISINF(x) __builtin_isinf(x)
#define S21_INT_MAX  2147483647

int s21_abs(int x); // ++
long double s21_acos(double x); // ++
long double s21_asin(double x); // ++
long double s21_atan(double x); // ++
long double s21_ceil(double x); // ++
long double s21_cos(double x); // ++
long double s21_exp(double x); // +
long double s21_fabs(double x); // ++
long double s21_floor(double x); // ++
long double s21_fmod(double x, double y); // ++
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x); // ++
long double s21_sqrt(double x); // +
long double s21_tan(double x); // ++
long double s21_factorial(int x);
int s21_abs(int x);

double reader(double x);

#endif  // SRC_S21_MATH_H_
