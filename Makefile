
all:
	cd libs_rl && make -j4
	cd example_mouse_and_cliff && make -j4

clean:
	cd libs_rl && make clean
	cd example_mouse_and_cliff && make clean
