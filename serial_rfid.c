#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main (int argc, char *argv[]) {
    int fd;
    int i = 0;
    int xor = -1;
    int rawDataArray[13] = {-1};

    if (argc != 2) {
        printf("Usage: %s <serial_port>", argv[0]);
        return 1;
    }

    if ((fd = serialOpen(argv[1], 9600)) < 0) {
        fprintf(stderr, "Unable to open '%s': %s\n", argv[1], strerror (errno));
        printf("Try to TODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
        return 2;
    }

    if (wiringPiSetup() == -1) {
        fprintf(stderr, "Unable to start WiringPi: %s\n", strerror (errno));
        return 3;
    }

    while (1) {
        delay(10);
        while (serialDataAvail(fd)) {
            rawDataArray[i] = serialGetchar(fd); /*Putting integers one by one in an array*/
            /*fflush(stdout);*/
            i++;

            if (i == 13) {

                xor = rawDataArray[1]^rawDataArray[2]^rawDataArray[3]^rawDataArray[4]^rawDataArray[5]^rawDataArray[6]^rawDataArray[7]^rawDataArray[8]^rawDataArray[9]^rawDataArray[10]; /*Computing checksum*/
                if (rawDataArray[0] != 170 || rawDataArray[1] != 15 || rawDataArray[2] != 8 || rawDataArray[3] != 0 || rawDataArray[12] != 187 || xor != rawDataArray[11]) { /*Checking data*/
                    fprintf(stderr, "Erreur lors de la vérification des données !\n");
                    return 4;
                }

                for (i = 0; i < 13; i++) {
                    printf("%.2X", rawDataArray[i]);
                    if (i != 12) {
                        printf(" ");
                     } else {
                         printf("\n");
                         return 0;
                     }
                }

                i=0;
            }
        }
    }
}