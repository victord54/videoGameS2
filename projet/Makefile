CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = param.h sdl2-light.h graphic.h game_event.h
SRC = main.c sdl2-light.c graphic.c game_event.c
OBJ = $(SRC:%.c=%.o)

INC_TESTS = param.h game_event.h
SRC_TESTS = tests.c game_event.c
OBJ_TESTS = $(SRC_TESTS:%.c=%.o)

PROG = spacecorridor

PROG_TEST = tests

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

spacecorridor: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

test: $(OBJ_TESTS)
	gcc $(CFLAGS) $(OBJ_TESTS) $(LDFLAGS) -o $@	

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG) $(PROG_TEST) 
	rm -rf latex html