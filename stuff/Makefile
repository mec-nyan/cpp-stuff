IN = stuff.cpp
OUT = stuff.o
COMPILER_FLAGS = -std=c++23 -Wall -Werror -Wpedantic

$(OUT): $(IN)
	@g++-16 -o $(OUT) $(COMPILER_FLAGS) $(IN) 

run: $(OUT)
	@if [ -e ./$(OUT) ]; then ./$(OUT); fi

clean:
	@if [ -e ./$(OUT) ]; then rm ./$(OUT); fi
	@if [ -e .//test ]; then rm .//test; fi

test:
	@g++-16 -o /test $(COMPILER_FLAGS) / 
	@./tests/test
