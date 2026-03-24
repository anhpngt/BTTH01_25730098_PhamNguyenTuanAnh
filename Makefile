# Compiler and flags
CXX = g++               # use g++ to compile C++
CXXFLAGS = -Wall -std=c++17

# Pattern rule: compile and immediately run
# e.g. `make bai1` compiles bai1.cpp -> ./bai1, then runs it
#   $< = the first dependency (bai1.cpp)
#   $@ = the target name (bai1)
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	./$@

# Remove all compiled binaries
clean:
	rm -f bai[0-9]*

help:
	@echo "Usage:"
	@echo "  make baiN     - compile and run baiN.cpp"
	@echo "  make clean    - remove all compiled binaries"
	@echo ""
	@echo "Examples:"
	@echo "  make bai1"
	@echo "  make bai2"
