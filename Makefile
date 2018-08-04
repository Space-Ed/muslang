PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = music-parser.o
CFLAGS = -std=c++11

ifeq ($(BUILD_MODE),debug)
CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
CFLAGS += -O2
else
$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	music-parser

music-parser:	$(OBJS)
	$(CXX) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr music-parser $(OBJS)
