#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "data_gen/db.h"
#include "models/LSE/lse.h"

int main(int argc, char *argv[]) {
    bool isRandom = false;
    int svalue = 5000;
    int opt;

    while ((opt = getopt(argc, argv, ":s:r")) != -1) {
        switch (opt) {
        case 'r': isRandom = true; break;
        case 's': if(atoi(optarg)) { svalue = atoi(optarg); break; }
        case ':': 
                printf("option [-s] needs a positive integer value\n"); 
                break; 
        case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
        default:
            printf("Usage: %s [-s size of dataset] [-r]\n", argv[0]);
            printf("-r to randomize the dataset. Default is an ordered dataset.");
            printf("-s to define dataset size. Default is 5000, max is LONG_MAX.");
            exit(EXIT_FAILURE);
        }
    };

    int* array = generate_DB(svalue, isRandom);
    benchmark_LSE(array, svalue, isRandom);
}