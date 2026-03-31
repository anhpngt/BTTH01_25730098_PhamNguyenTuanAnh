SRCS := $(wildcard *.cpp)
TARGETS := $(SRCS:.cpp=)

.PHONY: help $(TARGETS)
help:
	@echo "Usage: make <number>"
	@echo "  make 1 		# Compile and run exercise 1"
	@echo "  make 2 		# Compile and run exercise 2"
	@echo "  make 3 		# Compile and run exercise 3"
	@echo "  etc..."

$(TARGETS):
	g++ -o $@ $@.cpp && ./$@
