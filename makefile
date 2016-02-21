all:
	g++ `pkg-config --cflags opencv` proc.cpp -o out `pkg-config --libs opencv`