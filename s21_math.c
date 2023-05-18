#include "s21_math.h"

long int s21_abs(int x) {
    if (x < 0) {
        x = x * (-1);
    }
    return x;
}

long double s21_acos(double x) {
    long double res = 0.0;

    if (x != x || x > 1.0 || x < -1.0) {
        res = S21_NAN;
    } else if (x == 1) {
        res = 0;
    } else if (x == -1) {
        res = S21_PI;
    } else {
        res = (S21_PI / 2) - s21_asin(x);
    }

    return res;
}

long double s21_asin(double x) {
    long double res = 0.0;

    if (x != x || x > 1.0 || x < -1.0) {
        res = S21_NAN;
    } else if (x == 1) {
        res = S21_PI / 2;
    } else if (x == -1) {
        res = -(S21_PI / 2);
    } else {
        res = s21_atan(x / s21_sqrt(1 - x * x));
    }

    return res;
}

long double s21_atan(double x) {
    long double res = 0.0;

    if (x != x) {
        res = -S21_NAN;
    } else if (x == S21_INF) {
        res = S21_PI / 2;
    } else if (x == -S21_INF) {
        res = -(S21_PI / 2);
    } else {
        int minus = 0;
        if (x < 0) {
            x *= -1;
            minus = 1;
        }
        if (x >= 0 && x <= 0.4375) {
            for (int n = 0; n < 100; ++n) {
                res += (s21_pow(-1, n) * s21_pow(x, (2 * n + 1))) / (2 * n + 1);
            }
        }
        if (x > 0.4375 && x <= 0.6875) {
            res = S21_ATAN_1 + s21_atan((x - 0.5) / (1 + x / 2));
        }
        if (x > 0.6875 && x <= 1.1875) {
            res = S21_ATAN_2 + s21_atan((x - 1) / (1 + x));
        }
        if (x > 1.1875 && x <= 2.4375) {
            res = S21_ATAN_3 + s21_atan((x - 1.5) / (1 + 1.5 * x));
        }
        if (x > 2.4375) {
            res = (S21_PI / 2) + s21_atan(-1 / x);
        }
        if (minus) res *= -1;
    }

    return res;
}

long double s21_ceil(double x) {
    long double ans;
    if (x < 0) {
        x = (int)x;
        ans = (long double)x;
    } else if (x > 0) {
        if ((int)x == x) {
            ans = x;
        } else {
            ans = (int)x + 1;
        }
    } else if (x == S21_INF || x == -S21_INF) {
        ans = x;
    } else if (x != x) {
        ans = S21_NAN;
    } else {
        ans = 0;
    }

    return ans;
}

long double s21_cos(double x) {
    long double sum;
    if (x != x) {
        sum = -S21_NAN;
    } else if (x == S21_INF || x == -S21_INF) {
        sum = -S21_NAN;
    } else {
        if (x < 0) {
            x *= -1;
        }
        while (x >= 2 * S21_PI) {
            x -= 2 * S21_PI;
        }
        x = S21_PI2 - x;
        sum = s21_sin(x);
    }
    return sum;
}

int s21_fact(int x) {
    int answer = 1;

    for (int i = 1; i <= x; i++) {
        answer = answer * i;
    }

    return answer;
}

long double s21_exp(double x) {
    double sum = 1.0;
    double fa = 1.0;

    if (x != x) {
        sum = -S21_NAN;
    } else if (x == S21_INF) {
        sum = x;
    } else if (x == -S21_INF) {
        sum = 0;
    } else if (x < -709) {
        sum = 0;
    } else if (x > 709) {
        sum = S21_INF;
    } else if (x != 0) {
        if (x > 0) {
            for (double i = 1.0; fa >= PR; i++) {
                fa = fa * (x / i);
                sum = sum + fa;
            }
        } else {
            x = x * (-1);
            for (double i = 1.0; fa >= PR; i++) {
                fa = fa * (x / i);
                sum = sum + fa;
            }
            sum = 1 / sum;
        }
    } else {
        sum = 1;
    }

    return sum;
}

long double s21_fabs(double x) {
    if (x < 0) {
        x = x * (-1);
    }

    return x;
}

long double s21_floor(double x) {
    long double ans;

    if (x < 0) {
        if ((int)x == x) {
            ans = x;
        } else {
            ans = (int)x - 1;
        }
    } else if (x > 0) {
        x = (int)x;
        ans = (long double)x;
    } else if (x == S21_INF || x == -S21_INF) {
        ans = x;
    } else if (x != x) {
        ans = S21_NAN;
    } else {
        ans = 0;
    }

    return ans;
}

long double s21_fmod(double x, double y) {
    long double answ = x;

    if (y == 0) {
        answ = S21_NAN;
    } else if (x < 0 && y > 0) {
        int n = x / y * (-1);
        answ = -answ;
        for (int i = n; i > 0; i--) {
            answ = answ - y;
        }
        answ = answ * (-1);
    } else if (y < 0 && x > 0) {
        y = -y;
        int n = x / y;
        for (int i = n; i > 0; i--) {
            answ = answ - y;
        }
    } else {
        int n = x / y;
        for (int i = n; i > 0; i--) {
            answ = answ - y;
        }
    }

    return answ;
}

long double s21_log(double x) {
    long double Ln10 = 2.30258509299;
    long double Ln2 = 0.69314718056;
    long double Result = 0;
    int Count10 = 0;
    int Count2 = 0;
    int Precizion = 50;

    if (x < 0) {
        Result = S21_NAN;
    } else if (x == 0) {
        Result = -S21_INF;
    } else if (x == S21_INF) {
        Result = S21_INF;
    } else if (x >= 0.2) {
        while (x > 10) {
            x /= 10;
            Count10++;
        }
        while (x >= 2) {
            x /= 2;
            Count2++;
        }
        double Bracket = (x - 1) / (x + 1);
        for (int i = 1; i <= Precizion; i++) {
            long double Sum = 2 * (1. / (i * 2 - 1) * s21_simplepow(Bracket, i * 2 - 1));
            Result += Sum;
        }
        Result = Count10 * Ln10 + Count2 * Ln2 + Result;
    } else {
        while (x < 1) {
            x *= 10;
            Count10++;
        }
        double Bracket = (x - 1) / (x + 1);
        for (int i = 1; i <= Precizion * 2.5; i++) {
            long double Sum = 2 * (1. / (i * 2 - 1) * s21_simplepow(Bracket, i * 2 - 1));
            Result += Sum;
        }
        Result = Result - Count10 * Ln10;
    }

    return Result;
}

long double s21_simplepow(double base, double exp) {
    double x = base;

    if (exp > 0) {
        for (int i = exp; i > 1; i--) {
            base = base * x;
        }
    } else {
        base = 1;
    }

    return base;
}

long double s21_pow(double base, double exp) {
    long double Lnbase = s21_log(base);
    long double Y = exp * Lnbase;
    long double x = base;

    if (exp > 0) {
        if (base > 0) {
            base = s21_exp(Y);
        } else if (base < 0) {
            if ((long int)exp == exp) {
                for (int i = exp; i > 1; i--) {
                    base = base * x;
                }
            } else {
                base = S21_NAN;
            }
        } else {
            base = 0;
        }
    } else if (exp < 0) {
        if (base > 0) {
            Y = Y * -1;
            base = s21_exp(Y);
            base = 1 / base;
        } else if (base < 0) {
            if ((long int)exp == exp) {
                base = base * x;
                base = 1 / base;
            } else {
                base = S21_NAN;
            }
        } else {
            base = 0;
        }
    } else if (exp == 0) {
        base = 1;
    } else if (exp == -S21_INF || exp == S21_INF) {
        if (base * (-1) < 1) {
            base = 0;
        } else if (base * (-1) == 1) {
            base = 1;
        } else {
            if (exp == -S21_INF) {
                base = 0;
            } else {
                base = S21_INF;
            }
        }
    } else {
        base = -S21_NAN;
    }

    return base;
}

long double s21_sin(double x) {
    long double sum = x;
    int n = 3;
    int znack = -1;
    int tr = 1;
    if (x != x) {
        sum = -S21_NAN;
    } else if (x == S21_INF || x == -S21_INF) {
        sum = -S21_INF;
    } else if (x >= -S21_PI3 && x <= S21_PI3) {
        for (int i = 0; i < 5; i++) {
            sum = sum + znack * s21_simplepow(x, n) / s21_fact(n);
            n = n + 2;
            znack = znack * (-1);
        }
    } else {
        if (x < 0) {
            x = x * (-1);
            tr = -1;
        }
        while (x > S21_PI2) {
            x = x - S21_PI;
            tr = tr * (-1);
        }
        sum = x;
        for (int i = 0; i < 5; i++) {
            sum = sum + znack * (long double)(s21_simplepow(x, n) / s21_fact(n));
            n = n + 2;
            znack = znack * (-1);
        }
        sum = sum * tr;
    }
    return sum;
}

long double s21_sqrt(double x) {
    long double s = s21_pow(x, 0.5);  // x = √a = a^(1/2)

    return s;
}

long double s21_tan(double x) {
    long double res = 0.0;

    if (x != x) {
        res = -S21_NAN;
    } else if (x == S21_INF || x == -S21_INF) {
        res = -S21_NAN;
    } else if (x != 0.0) {
        long double sinx = s21_sin(x), cosx = s21_cos(x);
        if (cosx == 0) {
            if (sinx > 0)
                res = S21_INF;
            else if (sinx < 0)
                res = -S21_INF;
        } else {
            res = sinx / cosx;
        }
    } else {
        res = x;
    }
    return res;
}
