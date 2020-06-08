CC=gcc
LIBS=-lwiringPi
EXEC=serial_rfid

all: $(EXEC)
	chmod u+x serial_rfid.sh

serial_rfid:
	$(CC) $(LIBS) -o $@ serial_rfid.c

.PHONY: clean

clean:
	rm -rf serial_rfid
