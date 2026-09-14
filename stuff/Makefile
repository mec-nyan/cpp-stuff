CXX = g++-16

CXXFLAGS = -std=c++23 -Wall -Wextra -Wpedantic -Werror -fmodules

PROGRAM = app
OBJECTS = main.o Beans.o
CACHE = gcm.cache/std.gcm

.PHONY: all run clean std

# Default target:
all: $(PROGRAM)

# Build the standard library module:
std: $(CACHE)

# As a target:
$(CACHE):
	@$(CXX) $(CXXFLAGS) -fsearch-include-path -fmodule-only -c bits/std.cc

# Compile module "Beans":
Beans.o: Beans.cpp $(CACHE)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# main imports both 'std' and 'Beans':
main.o: main.cpp Beans.o $(CACHE)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the executable:
$(PROGRAM): $(OBJECTS)
	@$(CXX) $^ -o $@

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	@rm $(PROGRAM) $(OBJECTS)

clean-all:
	@rm -rf $(PROGRAM) $(OBJECTS) gcm.cache
