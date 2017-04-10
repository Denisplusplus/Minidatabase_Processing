#include <stdio.h>
#include <stdlib.h>

#include "passenger.h"
#include "read_write.h"
#include "actions.h"

void task(int argc, char *argv[])
{
    FILE *in = fopen(argv[2], "r");
    int parameter;
    scanf("%d", &parameter);
    if (argc != 3) {
        printf("Something went wrong. Use key -help to find the solution\n");
        exit(2);
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
}

void data_base_generate(int argc, char *argv[])
{
    FILE *in  = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "w");

    if (argc != 4) {
        printf("Invalid argument set. Use key -help to find the solution\n");
        exit(3);
    } 

    if (!in || !out) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Passenger p;

    while (passenger_read_txt(&p, in)) {
        passenger_write_bin(&p, out);
    }
    
    
    fclose(in);
    fclose(out);

    
}

void data_base_print(int argc, char *argv[])
{
    FILE *in = fopen(argv[2], "r");

    if (argc != 3) {
        printf("Something went wrong. Use key -help to find the solution\n");
        exit(2);
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

    
}

void help()
{
	printf("This program is used for to work with mini-database.\n");
	printf("Use key -generate [FILENAME.txt][BASENAME.bin] to create data base from txt file\n");
	printf("	-print [BASENAME.bin] to output database on the screen\n");
	printf("	-task [BASENAME.bin] to solve the following task:\n");
    printf("        Find passengers whose baggage's weight differs\n");
    printf("        from maximal weight in 'parameter' that you is\n");  
    printf("        required to input \n");
}