#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#define SIZE_SURNAME 50
#define SIZE_INITIALS 50
#define SIZE_DESTINATION 50
#define SIZE_TIME 50
typedef struct {
  char surname[SIZE_SURNAME];
  char initials[SIZE_INITIALS];
  int baggage_quantity;
  int baggage_weight;
  char destination[SIZE_DESTINATION];
  char time[SIZE_TIME];
  char transplants;
  char children;
} Passenger;

#endif