all: prob1 prob2 prob3 prob4 prob5

prob1: prob1.c
	gcc -g prob1.c -o prob1

prob2: prob2.c
	gcc -g prob2.c -o prob2

prob3: prob3.c
	gcc -g prob3.c -o prob3

prob4: prob4.c
	gcc -g prob4.c -o prob4

prob5: prob5.c
	gcc -g prob5.c -o prob5

clean:
	rm -f prob1 prob2 prob3 prob4 prob5
