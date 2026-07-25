LIB = s21_string.a

CC = gcc
FLAGS_C = -Wall -Werror -Wextra -std=c11
FLAGS_END = -lm -lcheck -lsubunit
FLAGS_LEAK = --leak-check=full --show-leak-kinds=all

MAKELIB = ar
FLAGS_LIB = rcs

SRC_MAIN = $(wildcard *.c)
OBJ_MAIN = $(patsubst %.c, %.o, $(SRC_MAIN))

SRC_TESTS = $(wildcard tests/*.c)
OBJ_TESTS = $(patsubst %.c, %.o, $(SRC_TESTS))

#__________________________________________________________

all: s21_string.a

s21_string.a : $(SRC_MAIN)
	$(CC) $(FLAGS_C) -c $(SRC_MAIN)
	$(MAKELIB) $(FLAGS_LIB) $@ $(OBJ_MAIN)
	ranlib $@

test : clean $(SRC_TESTS) s21_string.a
	$(CC) $(FLAGS_C) $(SRC_TESTS) $(LIB) -o test.out $(FLAGS_END)
	./test.out

gcov_report: FLAGS_C += -coverage
gcov_report: clean test
	gcov -f $(SRC_MAIN)
	mkdir report
	./test.out
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --output-directory ./report

clang:
	clang-format -i *.c *.h tests/*.c tests/*.h

valgrind:
	valgrind $(FLAGS_LEAK) ./test.out

clean:
	rm -f *.o *.a
	rm -f test.out
	rm -f *.gcno *.gcda *.info *.gcov
	rm -fr report