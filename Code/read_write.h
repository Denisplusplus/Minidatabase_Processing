#ifndef _READ_WRITE_H_
#define _READ_WRITE_H_

#include "passenger.h"


int passenger_read_txt(Passenger *p, FILE *in);
int  passenger_read_bin(Passenger *p, FILE *in);
void passenger_write_bin(Passenger *p, FILE *out);
void passenger_print(Passenger *p);

#endif
