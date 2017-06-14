#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#define SIZE_STR 24
typedef struct {
	char surname[SIZE_STR];
	char initials[SIZE_STR];
	int baggage_quantity;
	int baggage_weight;
	char destination[SIZE_STR];
	char time[SIZE_STR];
	char transplants;
	char children;
} Passenger;

#endif
