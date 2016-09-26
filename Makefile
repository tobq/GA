OUT=GA
FLAGS= 
DEPS=GA.h

compile: $(DEPS)
	gcc GA.c -o $(OUT) $(FLAGS)
	
run: $(OUT)
	./$(OUT)
