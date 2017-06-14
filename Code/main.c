#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "passenger.h"
#include "read_write.h"
#include "actions.h"


int main(int argc, char **argv) {
     
    if(argc <= 1) {
         printf("An error occurred. Use key -help to find the solution\n");
         exit (1);
     }
     if(!strcmp(argv[1], "-help")) {
         help();
     } else if(!strcmp(argv[1], "-generate")) {
         data_base_generate(argc, argv);
     } else if(!strcmp(argv[1], "-print")) {
         data_base_print(argc, argv);    
     } else if(!strcmp(argv[1], "-task")) {
         task(argc, argv); 
     } else {
         printf("Unknown parameter: '%s'. Use key -help to find the solution\n", argv[1]);
         exit (2);
     }	


	return 0;
}
