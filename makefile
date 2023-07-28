CC = gcc
CFLAGS = -Wall -Wextra

SRC = socialScores_C.c
EXE = socialScores_C

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXE)
