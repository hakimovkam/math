#include "s21_math.h"

#include <math.h>

int main() {
  double x = 12;
  double y = 0.1;
  long double e = 0;
  long double e1 = 0;
//   e = s21_tan(y);
  e1 = atan(y);
  printf("Func = %Lf\nOrig = %Lf\n", e, e1);
  return 0;
}

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
  long double temp = 0;
  if (x == S21_INF || x == 0 || x == DBLMAX || x == S21_NINF) {
    temp = x;
  } else {
    temp = s21_fabs(x);
    if (temp > 0) {
      temp = s21_abs((long long int)x);
      if (temp != s21_fabs(x)) {
        if (x > 0) {
          temp += 1;
        } else {
          temp = -temp;
        }
      } else {
        temp = x;
      }
    } else {
      temp = S21_NAN;
    }
  }
  return temp;
}

long double s21_cos(double x) {
  long double result = 0;
  if (x == S21_INF || x == S21_NAN) {
    result = S21_NAN;
  } else {
    x = reader(x);
    result = s21_sin((S21_PI / 2) - x);
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1, addValue = 1, cntr = 1;

  while (s21_fabs(addValue) > EPS) {
    addValue *= x / cntr;
    cntr += 1;
    result += addValue;
    if (result > DBLMAX) {
      result = INFINITY;
      break;
    }
  }

  return result;
}

long double s21_fabs(double x) { return (x < 0) ? x * -1 : x; }

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_floor(double x) {
  long double temp = 0;
  if (x == S21_INF || x == 0 || x == DBLMAX || x == S21_NINF) {
    temp = x;
  } else {
    temp = s21_fabs(x);
    if (temp > 0) {
      temp = s21_abs((long long int)x);
      if (temp != s21_fabs(x)) {
        if (x < 0) {
          temp -= 1;
        }
      } else {
        temp = x;
      }
    } else {
      temp = S21_NAN;
    }
  }
  return temp;
}

long double s21_fmod(double x, double y) {
  long long int mod = 0;
  long double res = 0;
  int minCounter = 1;
  if (x == S21_INF || x == S21_NINF || x == S21_NAN || y == S21_NAN) {
    res = S21_NAN;
  }
  if (x < 0) {
    minCounter = -1;
    x = s21_fabs(x);
  }
  if (y < 0) {
    y = s21_fabs(y);
  }
  if (y == 0) {
    res = S21_NAN;
  } else if (x == y) {
    res = 0;
  } else if (x < y) {
    res = x * minCounter;
  } else {
    mod = x / y;
    res = ((long double)x - mod * (long double)y) * minCounter;
  }
  return res;
}

long double s21_log(double x) {
  int i = 0;
  long double result = 0, compareNumber = 0;

  if (x == 0) {
    result = (long double)-INFINITY;
  } else if (x == 1) {
    result = 0;
  } else {
    for (; x > -EXP; x /= EXP, i++) continue;
    for (int j = 0; j < 100; j++) {
      //            printf("и");
      compareNumber = result;
      result = compareNumber +
               2 * (x - s21_exp(compareNumber)) / (x + s21_exp(compareNumber));
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
    temp = -temp;
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
  long double result = 0, temp = x, i = 1.;
  if (x == S21_NAN || x == S21_INF) {
    temp = S21_NAN;
  } else {
    x = (long double)reader(x);
    result = x;
    temp = x;
    while (s21_fabs(result / temp) > EPS) {
      result = -1 * result * x * x / (2 * i * (2 * i + 1));
      i += 1.;
      temp += result;
    }
  }
  return temp;
}

long double s21_sqrt(double x) {
  // Метод половинного деления
  long double result = 0;
  long double left = 0, right = (x < 1) ? 1 : x, mid = 0;

  mid = (right + left) / 2;

  while ((mid - left) > EPS) {
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
  long double result = 0;
  if (x == S21_INF || x == S21_NAN) {
    result = S21_NAN;
  } else {
    x = reader(x);
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_factorial(int x) {
  long double result = 1;
  if (x < 0) {
    result = 0;
  } else if (x == 0) {
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
  while (x > S21_PI || x < -S21_PI) {
    x += x > S21_PI ? -2 * S21_PI : 2 * S21_PI;
  }
  return x;
}
