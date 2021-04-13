CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = param.h sdl2-light.h graphic.h game_data.h handle_event.h sdl2-ttf-light.h leaderboard.h menu_graphic.h menu_data.h
SRC = main.c sdl2-light.c graphic.c game_data.c handle_event.c sdl2-ttf-light.c leaderboard.c
OBJ = $(SRC:%.c=%.o)

INC_TESTS = param.h game_data.h
SRC_TESTS = tests.c game_data.c
OBJ_TESTS = $(SRC_TESTS:%.c=%.o)

PROG = spacecorridor

PROG_TEST = test

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

spacecorridor: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

test: $(OBJ_TESTS)
	gcc $(CFLAGS) $(OBJ_TESTS) $(LDFLAGS) -o $@	

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex
	mv latex/refman.pdf refman.pdf


clean:
	rm -f *~ *.o $(PROG) $(PROG_TEST)
	rm -rf latex html