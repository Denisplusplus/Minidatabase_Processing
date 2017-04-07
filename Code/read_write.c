#include <stdio.h>
#include <stdlib.h>

#include "passenger.h"
#include "read_write.h"

int passenger_read_txt(Passenger *p, FILE *in)
{
    fscanf(in, "%s", p->surname);
    fscanf(in, "%s", p->initials);
    fscanf(in, " %lf", &(p->baggage_quantity));
    fscanf(in, "%d", &(p->baggage_weight));
    fscanf(in, "%s", p->destination);
    fscanf(in, "%s", p->time);
    fscanf(in, "%c", &(p->transplants));
    fscanf(in, "%c", &(p->children));
    return !feof(in);
}

void passenger_write_bin(Passenger *p, FILE *out)
{
    fwrite(p->surname,  sizeof(char), SIZE_SURNAME, out);
    fwrite(p->initials, sizeof(char), SIZE_INITIALS, out);
    fwrite(&(p->baggage_quantity), sizeof(int), 1, out);
    fwrite(&(p->baggage_weight), sizeof(double), 1, out);
    fwrite(p->destination, sizeof(char), SIZE_DESTINATION, out);
    fwrite(p->time, sizeof(char), SIZE_TIME, out);
    fwrite(&(p->transplants), sizeof(char), 1, out);
    fwrite(&(p->children), sizeof(char), 1, out);

}

void passenger_print(Passenger *p)
{
	printf("Name: %s %s\n", p->surname, p->initials);
    printf("Amount of stuff: %d\n", p->baggage_quantity);
    printf("Baggage weight: %lf\n", p->baggage_weight);
    printf("Departure time: %s\n", p->time);
    printf("Transplants: %c\n", p->transplants);
    printf("Children: %c\n", p->children);
    

    printf("\n");


}