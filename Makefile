FLAGS=-g3 -O0

mydbg: main.c
	gcc $(FLAGS) -o mydbg main.c

.PHONY: clean

clean:
	rm -rf mydbg
