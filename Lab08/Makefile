file1 = Temperature
file2 = FootballScore

all: $(file1) $(file2)

$(file1): Temperature.o
	gcc Temperature.o -o $(file1).exe

$(file2): FootballScore.o
	gcc FootballScore.o -o $(file2).exe

Temperature.o: Temperature.c 
	gcc -c Temperature.c

FootballScore.o: FootballScore.c
	gcc -c FootballScore.c



clean:
	rm -rf *.o
	rm -rf *.exe

