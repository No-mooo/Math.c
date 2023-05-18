#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(test_s21_abs) {
    ck_assert_int_eq(s21_abs(MAX_LONG_NEG_INT), abs(MAX_LONG_NEG_INT));
    ck_assert_int_eq(s21_abs(MAX_LONG_POS_INT), abs(MAX_LONG_POS_INT));
    ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(test_s21_acos) {
    ck_assert_ldouble_eq_tol(s21_acos(0.701305), acos(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_acos(-0.701305), acos(-0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 0.000001);
}
END_TEST

START_TEST(test_s21_asin) {
    ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_asin(0.701305), asin(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_asin(-0.701305), asin(-0.701305), 0.000001);
}
END_TEST

START_TEST(test_s21_atan) {
    ck_assert_ldouble_eq_tol(s21_atan(-7.905605), atan(-7.905605), 0.000001);
    ck_assert_ldouble_eq_tol(s21_atan(0.701305), atan(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_atan(11.701305), atan(11.701305), 0.000001);
}
END_TEST

START_TEST(test_s21_ceil) {
    ck_assert_ldouble_eq_tol(s21_ceil(MAX_NEG_DOUBLE), ceil(MAX_NEG_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_ceil(-7.905605), ceil(-7.905605), 0.000001);
    ck_assert_ldouble_eq_tol(s21_ceil(0.701305), ceil(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_ceil(25.123), ceil(25.123), 0.000001);
    ck_assert_ldouble_eq_tol(s21_ceil(11.701305), ceil(11.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_ceil(11.0555), ceil(11.0555), 0.000001);
    ck_assert_int_eq(s21_ceil(MAX_LONG_NEG_INT), ceil(MAX_LONG_NEG_INT));
    ck_assert_int_eq(s21_ceil(MAX_LONG_POS_INT), ceil(MAX_LONG_POS_INT));
    ck_assert_ldouble_nan(ceil(S21_NAN));
    ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(test_s21_cos) {
    ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(0.287611), cos(0.287611), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(2), cos(2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(-2), cos(-2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(5), cos(5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_cos(-5), cos(-5), 0.000001);
}
END_TEST

START_TEST(test_s21_exp) {
    ck_assert_ldouble_eq_tol(s21_exp(MAX_NEG_DOUBLE), exp(MAX_NEG_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(-7.905605), exp(-7.905605), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(0.701305), exp(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(25.123), exp(25.123), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(11.701305), exp(11.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(10), exp(10), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(-11), exp(-11), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_exp(-99), exp(-99), 0.000001);
    ck_assert_int_eq(s21_exp(710), exp(710));
    ck_assert_int_eq(s21_exp(S21_INF), exp(S21_INF));
}
END_TEST

START_TEST(test_s21_fabs) {
    ck_assert_ldouble_eq_tol(s21_fabs(MAX_NEG_DOUBLE), fabs(MAX_NEG_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fabs(-7.905605), fabs(-7.905605), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fabs(0.701305), fabs(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fabs(0), fabs(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fabs(11.701305), fabs(11.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fabs(MAX_LONG_NEG_INT), fabs(MAX_LONG_NEG_INT), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fabs(MAX_LONG_POS_INT), fabs(MAX_LONG_POS_INT), 0.000001);
}
END_TEST

START_TEST(test_s21_floor) {
    ck_assert_ldouble_eq_tol(s21_floor(MAX_NEG_DOUBLE), floor(MAX_NEG_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(-7.905605), floor(-7.905605), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(0.701305), floor(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(25.123), floor(25.123), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(25.0123), floor(25.0123), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(11.701305), floor(11.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(MAX_LONG_NEG_INT), floor(MAX_LONG_NEG_INT), 0.000001);
    ck_assert_ldouble_eq_tol(s21_floor(MAX_LONG_POS_INT), floor(MAX_LONG_POS_INT), 0.000001);
}
END_TEST

START_TEST(test_s21_fmod) {
    ck_assert_ldouble_eq_tol(s21_fmod(MAX_NEG_DOUBLE, 3.1), fmod(MAX_NEG_DOUBLE, 3.1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(-7.905605, 1.3), fmod(-7.905605, 1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(0.701305, 1.3), fmod(0.701305, 1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(25.123, 1.3), fmod(25.123, 1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(25, -1.3), fmod(25, -1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(-25, -1.3), fmod(-25, -1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(11, 3), fmod(11, 3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(0, 3), fmod(0, 3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_fmod(10, 10), fmod(10, 10), 0.000001);
}
END_TEST

START_TEST(test_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(MAX_POS_DOUBLE), log(MAX_POS_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_log(MAX_NEG_DOUBLE), log(MAX_NEG_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_log(0.701305), log(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_log(25.123), log(25.123), 0.0000001);
    ck_assert_ldouble_eq_tol(s21_log(11.701305), log(11.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_log(2), log(2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_log(999999999999999999), log(999999999999999999), 0.000001);
}
END_TEST

START_TEST(test_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(MAX_NEG_DOUBLE, 3.1), pow(MAX_NEG_DOUBLE, 3.1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_pow(0.701305, 1.3), pow(0.701305, 1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_pow(25.123, 1.3), pow(25.123, 1.3), 0.000001);
    ck_assert_ldouble_eq_tol(s21_pow(11.701305, 1.3), pow(11.701305, 1.3), 0.000001);
    ck_assert_ldouble_nan(s21_pow(-7.905605, 1.3));
    ck_assert_ldouble_nan(pow(-7.905605, 1.3));
    ck_assert_ldouble_nan(s21_pow(-7.905605, -1.3));
    ck_assert_ldouble_nan(pow(-7.905605, -1.3));
    ck_assert_ldouble_infinite(s21_pow(MAX_POS_DOUBLE, 3.1));
    ck_assert_ldouble_infinite(pow(MAX_POS_DOUBLE, 3.1));
}
END_TEST

START_TEST(test_s21_sin) {
    ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(0.287611), sin(0.287611), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(2), sin(2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(-2), sin(-2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(5), sin(5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sin(-5), sin(-5), 0.000001);
}
END_TEST

START_TEST(test_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(MAX_NEG_DOUBLE), sqrt(MAX_NEG_DOUBLE), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.701305), sqrt(0.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sqrt(25.123), sqrt(25.123), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sqrt(11.701305), sqrt(11.701305), 0.000001);
    ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 0.000001);
}
END_TEST

START_TEST(test_s21_tan) {
    ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(0.287611), tan(0.287611), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(2), tan(2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(-2), tan(-2), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(5), tan(5), 0.000001);
    ck_assert_ldouble_eq_tol(s21_tan(-5), tan(-5), 0.000001);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Math tests");
    SRunner *sr = srunner_create(s1);
    int nf;

    TCase *tc1_1 = tcase_create("Abs test");
    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_s21_abs);

    TCase *tc2_1 = tcase_create("Acos test");
    suite_add_tcase(s1, tc2_1);
    tcase_add_test(tc2_1, test_s21_acos);

    TCase *tc3_1 = tcase_create("Asin test");
    suite_add_tcase(s1, tc3_1);
    tcase_add_test(tc3_1, test_s21_asin);

    TCase *tc4_1 = tcase_create("Atan test");
    suite_add_tcase(s1, tc4_1);
    tcase_add_test(tc4_1, test_s21_atan);

    TCase *tc5_1 = tcase_create("Ceil test");
    suite_add_tcase(s1, tc5_1);
    tcase_add_test(tc5_1, test_s21_ceil);

    TCase *tc6_1 = tcase_create("Cos test");
    suite_add_tcase(s1, tc6_1);
    tcase_add_test(tc6_1, test_s21_cos);

    TCase *tc7_1 = tcase_create("Exp test");
    suite_add_tcase(s1, tc7_1);
    tcase_add_test(tc7_1, test_s21_exp);

    TCase *tc8_1 = tcase_create("Fabs test");
    suite_add_tcase(s1, tc8_1);
    tcase_add_test(tc8_1, test_s21_fabs);

    TCase *tc9_1 = tcase_create("Floor test");
    suite_add_tcase(s1, tc9_1);
    tcase_add_test(tc9_1, test_s21_floor);

    TCase *tc10_1 = tcase_create("Fmod test");
    suite_add_tcase(s1, tc10_1);
    tcase_add_test(tc10_1, test_s21_fmod);

    TCase *tc11_1 = tcase_create("Log test");
    suite_add_tcase(s1, tc11_1);
    tcase_add_test(tc11_1, test_s21_log);

    TCase *tc12_1 = tcase_create("Pow test");
    suite_add_tcase(s1, tc12_1);
    tcase_add_test(tc12_1, test_s21_pow);

    TCase *tc13_1 = tcase_create("Sin test");
    suite_add_tcase(s1, tc13_1);
    tcase_add_test(tc13_1, test_s21_sin);

    TCase *tc14_1 = tcase_create("Sqrt test");
    suite_add_tcase(s1, tc14_1);
    tcase_add_test(tc14_1, test_s21_sqrt);

    TCase *tc15_1 = tcase_create("Tan test");
    suite_add_tcase(s1, tc15_1);
    tcase_add_test(tc15_1, test_s21_tan);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
