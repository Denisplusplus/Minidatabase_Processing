#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "passenger.h"
#include "read_write.h"


int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    int parameter;
    scanf("%d", &parameter);
    if (argc != 2) {
        printf("Usage:\n\t./print DB_FILE\n");
        exit(0);
    }

    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Passenger p;

    int weight_max= -1;
	while (passenger_read_bin(&p, in)) {
  	    if ((p.baggage_weight) > weight_max ) {
    		weight_max = (p.baggage_weight);
    	}    
    }
    printf("%d\n", weight_max);

    rewind(in);  
  	while (passenger_read_bin(&p, in)) {
  		if(abs(p.baggage_weight- weight_max) < parameter) {
        	passenger_print(&p);
  		}
    }
   
    fclose(in);

    return 0;
}