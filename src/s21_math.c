#include "s21_math.h"

#include <math.h>

int main() {
  double x = -S21_INT_MAX - 1;
  double y = 1;
  long double e = 0;
  long double e1 = 0;
  e = s21_pow(x, y);
  e1 = pow(x, y);
  printf("Func = %Lf\nOrig = %Lf\n", e, e1);
  return 0;
}

long double s21_pow(double base, double exp) {
  long double result = 1, temp = base;
  //    long long int tempForExpInt = (long long int)exp;
  if (exp == 0) {
    result = 1;
  } else if (S21_ISNAN(base) && exp != 0) {
    result = S21_NAN;
  } else if (base == 1) {
    result = 1;
  } else if ((long int)exp == exp) {
    if (exp > 0) {
      for (; exp >= 1; exp--) {
        result *= base;
      }
    } else {
      for (; exp <= -1; exp++) {
        result /= base;
      }
    }
  } else {
    if (temp < 0) {
      temp = -temp;
      result = s21_exp(exp * s21_log(temp));
      if (s21_fmod(exp, 2) != 0) {
        result = -result;
      }
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}

long double s21_acos(double x) {
  long double result = 0;
  if (S21_ISINF(x) || S21_ISNAN(x)) {
    result = S21_NAN;
  } else {
    if (x == 1) {
      result = 0;
    } else if (x == 0) {
      result = S21_PI / 2;
    } else if (x == -1) {
      result = S21_PI;
    } else if (x > 0 && x < 1) {
      result = s21_atan(sqrt(1 - pow(x, 2)) / x);
    } else if (x < 0 && x > -1) {
      result = S21_PI + s21_atan(sqrt(1 - pow(x, 2)) / x);
    } else if (x > 1 || x < -1) {
      result = S21_NAN;
    }
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  int minCounter = 1;
  if (S21_ISNAN(x) || S21_ISINF(x)) {
    result = S21_NAN;
  } else {
    if (x == 0) {
      result = 0;
    } else if (x == 1) {
      result = S21_PI / 2;
    } else if (x == -1) {
      result = -S21_PI / 2;
    } else if (x > 1 || x < -1) {
      result = S21_NAN;
    } else {
      long double temp = (long double)x;
      if (temp < 0) {
        minCounter = -1;
        temp = -temp;
      }
      result = s21_atan((temp) / (sqrt(1 - pow(x, 2))));
      result = result * minCounter;
    }
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  int minCounter = 1;
  if (S21_ISNAN(x)) {
    result = S21_NAN;
  } else if (S21_ISINF(x)) {
    if (x < 0) {
      result = -S21_PI / 2;
    } else {
      result = S21_PI / 2;
    }
  } else {
    long double temp = (long double)x;
    if (temp < 0) {
      temp = -temp;
      minCounter = -1;
    }
    if (temp == 1) {
      temp = S21_PI / 4;
      result = temp * minCounter;
    } else if (temp < 1) {
      for (int i = 0; i < 10000; i++) {
        result += (pow(-1, i) * pow(temp, 1 + 2 * i)) / (1 + (2 * i));
      }
      result = result * minCounter;
    } else {
      for (int i = 0; i < 10000; i++) {
        result += (pow(-1, i) * pow(temp, -1 - 2 * i)) / (1 + (2 * i));
      }
      result = ((S21_PI / 2) - result) * minCounter;
    }
  }
  return result;
}

long double s21_ceil(double x) {
  long double temp = 0;
  if (S21_ISINF(x) || x == 0 || x == DBLMAX || x == S21_NINF) {
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
  if (S21_ISINF(x) || S21_ISNAN(x)) {
    result = S21_NAN;
  } else {
    x = reader(x);
    result = s21_sin((S21_PI / 2) - x);
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1, addValue = 1, cntr = 1;
  if (x == S21_NINF) {
    result = 0;
  } else if (S21_ISNAN(x)) {
    result = S21_NAN;
  } else {
    while (s21_fabs(addValue) > S21_EPS) {
      addValue *= x / cntr;
      cntr += 1;
      result += addValue;
      if (result > DBLMAX) {
        result = S21_INF;
        break;
      }
    }
  }
  return result;
}

long double s21_fabs(double x) { return (x < 0) ? x * -1 : x; }

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_floor(double x) {
  long double temp = 0;
  if (S21_ISINF(x) || x == 0 || x == DBLMAX || x == S21_NINF) {
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
  if (S21_ISINF(x) || x == S21_NINF || S21_ISNAN(x) || S21_ISNAN(y)) {
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
  long double result = 0, temp = 0;

  if (x >= 0) {
    if (x == 0) {
      result = (long double)-S21_INF;
    } else if (x == 1) {
      result = 0;
    } else {
      for (; x >= S21_EXP; x /= S21_EXP, i++) continue;
      for (int j = 0; j < 100; j++) {
        temp = result;
        result = temp + 2 * (x - s21_exp(temp)) / (x + s21_exp(temp));
      }
      /* Итенрационный метод Галея, источник ниже(формула в конце)
       https://wikicsu.ru/wiki/natural_logarithm */
    }
    result += i;
  } else {
    result = (long double)S21_NAN;
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0, temp = x, i = 1;
  if (S21_ISNAN(x) || S21_ISINF(x)) {
    temp = S21_NAN;
  } else {
    x = (long double)reader(x);
    result = x;
    temp = x;
    while (s21_fabs(result / temp) > S21_EPS) {
      result = -1 * result * x * x / (2 * i * (2 * i + 1));
      i += 1;
      temp += result;
    }
  }
  return temp;
}

long double s21_sqrt(double x) {
  // Метод половинного деления
  long double result = 0;
  long double left = 0, right = (x < 1) ? 1 : x, mid = 0;

  if (x > 0) {
    mid = (left + right) / 2;
    while ((mid - left) > S21_EPS) {
      if (mid * mid > x) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (right + left) / 2;
    }
    result = mid;
  } else {
    result = (long double)S21_NAN;
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0;
  if (S21_ISINF(x) || S21_ISNAN(x)) {
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
