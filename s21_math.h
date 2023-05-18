#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_NAN 0.0 / 0.0  // s21nan != nan
#define S21_INF 1.0 / 0.0
#define MAX 1.7E+308
#define MIN 1.7E-308
#define PR 1e-16
#define S21_PI 3.1415926535897932384650288
#define S21_PI2 1.570796326794896558
#define S21_PI3 1.047197551196597853
#define MAX_LONG_NEG_INT -2147483647
#define MAX_LONG_POS_INT 2147483647
#define MAX_POS_DOUBLE 1.79769313486231571E+308
#define MAX_NEG_DOUBLE 2.2250738585072014E-308
#define S21_ATAN_1 0.463647609000806
#define S21_ATAN_2 0.785398163397448
#define S21_ATAN_3 0.982793723247329
#define E_10 2.302585092994046
#define E_2 0.6931471805599453

long int s21_abs(int x);
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

int s21_fact(int x);
long double s21_simplepow(double base, double exp);

#endif  // SRC_S21_MATH_H_
