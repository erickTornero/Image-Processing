CXX ?= g++

CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv)
LDFLAGS += $(shell pkg-config --libs --static opencv)

all: opencv_example

opencv_example: main.o; $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

opencv_example_test: test.o; $(CXX) $< -o $@ $(LDFLAGS)


clean: ; rm -f main.o opencv_example

exec:
	./opencv_example
.PHONY=exec