#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#define SIZE_SURNAME 20
#define SIZE_INITIALS 4
#define SIZE_DESTINATION 30
#define SIZE_TIME 8
typedef struct {
  char surname[SIZE_SURNAME];
  char initials[SIZE_INITIALS];
  int baggage_quantity;
  double baggage_weight;
  char destination[SIZE_DESTINATION];
  char time[SIZE_TIME];
  char transplants;
  char children;
} Passenger;

#endif
