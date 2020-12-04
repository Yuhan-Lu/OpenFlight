CXX = clang++
LD = clang++
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
CXXFLAGS = -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi
DEPFILE_FLAGS = -MMD -MP
OBJS_DIR = .objs
EXE = main

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/cs225
	
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

OBJS = airlines.o airports.o planes.o routes.o airlineFlow.o main.o utils.o

OBJS += cs225/graph.o

$(EXE): $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS))
	$(LD) $(filter-out $<, $^) $(LDFLAGS) -o $@

clean : 
	rm -rf $(EXE) $(OBJS_DIR) *.o
	
clear :
	rm -rf $(EXE) $(OBJS_DIR) *.o

.PHONY : clean clear
