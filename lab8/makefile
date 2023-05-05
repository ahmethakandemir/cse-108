all: clear compile run clean

clean:
	@rm -f test1
	@rm -f test2
	@rm -f test3
compile: 
	@gcc part1.c -o test1 -lm
	@gcc part2.c -o test2 -lm
	@gcc part3.c -o test3 -lm
run:
	@echo part1 starts!
	@./test1
	@echo part1 end, part 2 starts!
	@./test2
	@echo part2 end, part 3 starts
	@./test3
clear:
	clear
part1:
	@gcc part1.c -o test1 -lm
	@./test1
	@rm -f test1
part2:
	@gcc part2.c -o test2 -lm
	@./test2
	@rm -f test2
part3:
	@gcc part3.c -o test3 -lm
	@./test3
	@rm -f test3
