#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    if ((fptr = fopen("C:\\Users\\Justin\\Documents\\ucf\\cop3223\\temperatures.txt", "r")) != NULL) {
        int num_temps;
        fscanf(fptr, "%d", &num_temps);
        printf("numtemps: %d\n", num_temps);
        while (num_temps) {
            for (int j = 0; j < num_temps; j++) {
                float temp;
                fscanf(fptr, "%f", &temp);
                printf("temp: %.1f\n", temp);
            }
            fscanf(fptr, "%d", &num_temps);
        }
        printf("num_temp: %d\n", num_temps);
    } else {
        printf("Error! opening file");
        exit(1);
    }

    // Program exits if the file pointer returns NULL.
    return 0;
}

