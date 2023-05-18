CC=gcc
GCOV = -fprofile-arcs -ftest-coverage
FILE_LIB = s21_math
FILE1 = s21_math_test

OS = $(shell uname)

ifeq ($(OS),Darwin)
	LIBS=-lcheck
	OPEN=open
else
    LIBS=-lcheck -lpthread -lrt -lm -lsubunit
	OPEN=xdg-open
endif


all: clean s21_math.a

s21_math.a:
	$(CC) -c s21_math.c -o s21_math.o
	ar rcs s21_math.a s21_math.o
test: s21_math.a
	$(CC) -c s21_math_test.c -o s21_math_test.o
	$(CC) s21_math_test.o s21_math.o $(LIBS) -o s21_math_test
	./s21_math_test

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.dSYM *.info report CPPLINT.cfg s21_math_test
check:
	@# cpp check
	@echo "\033[31m--------- CPPCHECK --------- \n\033[0m"
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

	@#style test
	@echo "\n\033[31m--------- STYLE TEST --------- \n\033[32m"
	@python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

	@#leaks test
	@echo "\n\033[31m--------- LEAKS TEST --------- \n\033[0m\n"
	@CK_FORK=no leaks --atExit -- ./s21_math_test
	@make clean
gcov_report: s21_math.a
	$(CC) $(GCOV) s21_math_test.c $(LIBS) s21_math.c -o $(FILE_LIB)

	./$(FILE_LIB)
	lcov -t "s21_math_test" -o $(FILE_LIB).info -c -d .
	genhtml -o report $(FILE_LIB).info
	$(OPEN) ./report/index.html
