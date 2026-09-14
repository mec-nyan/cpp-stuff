# CXX = g++-16
CXX = clang++-21

CXXFLAGS = -std=c++23 -Wall -Wextra -Wpedantic -Werror

MODULE = Beans
MODULE_SRC = Beans.cppm
MODULE_BMI = $(MODULE).pcm
MODULE_OBJ = $(MODULE).o

PROGRAM = app

OBJECTS = main.o Beans.o

.PHONY: all run clean # std

all: $(PROGRAM)

$(MODULE_BMI): $(MODULE_SRC)
	@$(CXX) $(CXXFLAGS) --precompile $< -o $@

$(MODULE_OBJ): $(MODULE_SRC) $(MODULE_BMI)
	@$(CXX) $(CXXFLAGS) -fmodule-file=$(MODULE)=$(MODULE_BMI) -c $< -o $@
	
main.o: main.cpp $(MODULE_BMI)
	@$(CXX) $(CXXFLAGS) -fmodule-file=$(MODULE)=$(MODULE_BMI) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $@

run: $(PROGRAM)
	@./$(PROGRAM)

clean:
	@rm -f $(PROGRAM) $(OBJECTS) $(MODULE_BMI)
