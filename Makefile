CFLAGS=-std=c++23 -pedantic
CLI_PARAMS=-f build.toml
run:
	clang++ $(CFLAGS) main.cpp -o azoth && ./azoth
