# Makefile for python rdtscp() module

.PHONY: all clean run

ALL = rdtscp_module.so

all: ${ALL}

clean:
	rm -rf ${ALL} ./build

rdtscp_module.so: rdtscp_module.c setup.py
	python3.6 setup.py build_ext --inplace

run: rdtscp_module.so
	python3.6 test.py