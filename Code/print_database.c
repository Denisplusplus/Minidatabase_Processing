#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "passenger.h"
#include "read_write.h"

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");

    if (argc != 2) {
        printf("Usage:\n\t./print DB_FILE\n");
        exit(0);
    }

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Passenger p;

    while (passenger_read_bin(&p, in)) {
        passenger_print(&p);
    }

    fclose(in);

    return 0;
}
