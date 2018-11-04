CC = gcc
CFLAGS = -Wall

all: p11 p12 p21 p22

p11 :
	$(CC) $(CFLAGS) -o main p11.c src/main.c -Iinclude

p12 :
	$(CC) $(CFLAGS) -o main p12.c src/main.c -Iinclude

p21 :
	$(CC) $(CFLAGS) -o main p21.c src/main.c -Iinclude

p22 :
	$(CC) $(CFLAGS) -o main p22.c src/main.c -Iinclude

clean : 
	rm bin/*