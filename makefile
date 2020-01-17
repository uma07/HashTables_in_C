# This is a makefile for the execution of hash & main files in this directory

main       : main.o hash.o
		gcc -o main hash.o main.o -lm

main.o     : main.c hash.h
		gcc -c main.c

hash.o     : hash.c hash.h
		gcc -c hash.c
