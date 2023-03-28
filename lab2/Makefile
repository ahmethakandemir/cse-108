all: compile run clean

compile: 
	@gcc part1.c -o test1 -lm
	@gcc part2.c -o test2

run: 
	@./test1
	@./test2
clean:
	@rm -f test1
	@rm -f test2
clear:
	clear
part1:
	@gcc part1.c -o test1 -lm
	@./test1
	@rm -f test1
part2:
	@gcc part2.c -o test2
	@./test2
	@rm -f test2