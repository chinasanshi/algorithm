
#override表示变量以Makefile中的定义为准，会忽略make命令行中的定义
#override filename := structure
filename := structure
file_expand := cc

CXXFLAGS := -std=c++11
debug :=
LDFLAGS :=
#build_flags := -std=c++98


$(filename):$(filename).o
	@$(CXX) $(CXXFLAGS) $(debug) $(LDFLAGS) $(filename).o -o $(filename)
	@$(RM) $(filename).o
$(filename).o:$(filename).cc
	@$(CXX) -Wall $(CXXFLAGS) $(debug) -c $(filename).$(file_expand) -o $(filename).o

.PHONY: clean
clean:
	@-$(RM) $(filename) $(filename).o
	@echo "clean" $(filename) $(filename)".o"
