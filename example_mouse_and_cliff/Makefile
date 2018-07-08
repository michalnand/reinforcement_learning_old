ELF = bin/example_mouse_and_cliff.elf

LIBS_RL=../libs_rl
LIBS_NN=$(HOME)/programming/nn_lib

INC+= -I.
INC+= -I$(LIBS_RL)
INC+= -I$(LIBS_NN)/libs_nn
INC+= -I$(LIBS_NN)/libs_common


LIBS+= $(LIBS_RL)/libs_rl.a
LIBS+= $(LIBS_NN)/libs_nn/libs_nn.a
LIBS+= $(LIBS_NN)/libs_common/libs_common.a

CC = g++
CU = nvcc
LD = g++
OBJCOPY = objcopy
OBJDUMP = objdump
SIZE = size

# DEGUBFLAGS = -g -pg

CFLAGS = $(DEGUBFLAGS) -O2 -Os -s -Wall -Wextra -pedantic -std=c++17 $(INC)

LDFLAGS = $(DEGUBFLAGS) -lstdc++fs -lm -lpthread -pthread -std=c++17 -lglut -lGL -lGLU -lX11 -ljsoncpp -L/usr/local/cuda/lib64 -lcuda -lcudart


SRCS+= $(shell find -name '*.cpp')


OBJS = $(SRCS:.cpp=.o)

all: $(ELF)
	$(SIZE) $(ELF)

$(ELF): $(LIBS) $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm $(OBJS) -rf
	rm $(ELF) -rf
