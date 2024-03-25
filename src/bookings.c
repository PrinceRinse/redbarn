#include <stdlib.h>
#include <stdio.h>
#include "../include/utils.h"
#include "../include/bookings.h"

// Booking constructor
Booking *Create_Booking(int bID, int pID, char *in_date, char
    *in_time, char *out_date, char *out_time, float rate) {
    
    Booking *booking_ptr = malloc(sizeof(Booking)) ;
    if (booking_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Booking\n") ;
        return NULL ;
    }

    booking_ptr->booking_ID = bID ;
    booking_ptr->pet_ID = pID ;
    Utils_strcpy_trunc(booking_ptr->in_date, in_date, 11) ;
    Utils_strcpy_trunc(booking_ptr->in_time, in_time, 8) ;
    Utils_strcpy_trunc(booking_ptr->out_date, out_date, 11) ;
    Utils_strcpy_trunc(booking_ptr->out_time, out_time, 8) ;
    booking_ptr->day_rate = rate ;

    return booking_ptr ;
}

// Booking destructor
void Free_Booking(Booking *booking_ptr) {
    free(booking_ptr) ;
}