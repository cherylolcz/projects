TARGET_GAME = tetris
TARGET_TEST = testus
VERSION     = 1.0

CC = gcc

# ФЛАГИ
FLAGS_COMPILE  = -Wall -Werror -Wextra -std=c11
FLAGS_NCURS    = -lncurses
FLAGS_LEAK     = --leak-check=full --show-leak-kinds=all
FLAGS_CHECK    = -lcheck -lm -lpthread -lrt -lsubunit
FLAGS_GCOV     = -fprofile-arcs -ftest-coverage

# ДИРЕКТОРИИ
DIR_BRICK_GAME = brick_game/tetris
DIR_GUI        = gui/cli
DIR_CONTROLLER = brick_game/tetris/controller
DIR_TEST       = tests
DIR_REPORT     = report
DIR_BUILD      = build
DIR_DOCS       = documentation
DIR_GAME       = BrickGame\ v$(VERSION)\ aka\ Tetris
DIR_DIST   	   = dist


# ИСХОДНЫЕ ФАЙЛЫ
SRC_BRICK_GAME = $(wildcard $(DIR_BRICK_GAME)/*.c)
SRC_GUI        = $(wildcard $(DIR_GUI)/*.c)
SRC_CONTROLLER = $(wildcard $(DIR_CONTROLLER)/*.c)
SRC_GAME       = $(SRC_BRICK_GAME) $(SRC_GUI) $(SRC_CONTROLLER)

SRC_GAME_FUNCS = $(SRC_BRICK_GAME) $(SRC_CONTROLLER)
SRC_TEST       = $(wildcard $(DIR_TEST)/*.c)

# ОБЪЕКТНЫЕ ФАЙЛЫ (в build/)
OBJ_GAME       = $(patsubst %.c, $(DIR_BUILD)/%.o, $(SRC_GAME))
OBJ_GAME_FUNCS = $(patsubst %.c, $(DIR_BUILD)/%.o, $(SRC_GAME_FUNCS))
OBJ_TEST       = $(patsubst %.c, $(DIR_BUILD)/%.o, $(SRC_TEST))

.PHONY: all clean test gcov_report clang_check clang_fix leak_test leak_game

all: $(TARGET_GAME)

test: all $(TARGET_TEST)

$(TARGET_GAME): $(OBJ_GAME)
	$(CC) $(FLAGS_COMPILE) $(FLAGS_GCOV) $(OBJ_GAME) -o $(TARGET_GAME) $(FLAGS_NCURS)

$(TARGET_TEST): $(OBJ_TEST) $(OBJ_GAME_FUNCS)
	$(CC) $(FLAGS_COMPILE) $(FLAGS_GCOV) $(OBJ_TEST) $(OBJ_GAME_FUNCS) -o $(TARGET_TEST) $(FLAGS_CHECK)

$(DIR_BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS_COMPILE) $(FLAGS_GCOV) -c $< -o $@

dvi:
	cd $(DIR_DOCS) && pdflatex documentation.tex

dist:
	@mkdir -p $(DIR_DIST)
	tar --exclude='./dist' \
	    --exclude='*.o' \
	    --exclude='tests' \
	    --exclude='documentation' \
	    --exclude='state_diagrama.png' \
		--exclude='BrickGame v1.0 aka Tetris' \
		--exclude='.gitkeep' \
	    -czf dist/$(DIR_GAME)-$(VERSION).tar.gz .

gcov_report: clean $(TARGET_TEST)
	./$(TARGET_TEST)
	mkdir -p $(DIR_REPORT)
	lcov --capture --directory $(DIR_BUILD) --output-file $(DIR_REPORT)/coverage.info
	lcov --remove $(DIR_REPORT)/coverage.info "$(DIR_TEST)/*" -o $(DIR_REPORT)/coverage.info
	genhtml $(DIR_REPORT)/coverage.info --output-directory $(DIR_REPORT)

install: all
	mkdir -p $(DIR_GAME)
	mv $(TARGET_GAME) $(DIR_GAME)/
	@echo "Тетрис установлен!"

uninstall:
	rm -f $(DIR_GAME)/$(TARGET_GAME)

clang_check:
	clang-format -n $(DIR_BRICK_GAME)/*.c $(DIR_BRICK_GAME)/*.h \
				  $(DIR_GUI)/*.c $(DIR_GUI)/*.h \
				  $(DIR_CONTROLLER)/*.c $(DIR_CONTROLLER)/*.h \
				  $(DIR_TEST)/*.c $(DIR_TEST)/*.h

clang_fix:
	clang-format -i $(DIR_BRICK_GAME)/*.c $(DIR_BRICK_GAME)/*.h \
				  $(DIR_GUI)/*.c $(DIR_GUI)/*.h \
				  $(DIR_CONTROLLER)/*.c $(DIR_CONTROLLER)/*.h \
				  $(DIR_TEST)/*.c $(DIR_TEST)/*.h

leak_game: clean all
	valgrind $(FLAGS_LEAK) ./$(TARGET_GAME)

leak_test: clean test
	valgrind $(FLAGS_LEAK) ./$(TARGET_TEST)

clean:
	rm -rf $(DIR_BUILD) $(DIR_REPORT) \
		   $(TARGET_GAME) $(TARGET_TEST) \
		   $(DIR_GAME)/*.bin *.bin \
		   $(DIR_DIST)
