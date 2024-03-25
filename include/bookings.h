#ifndef BOOKINGS_H
#define BOOKINGS_H

typedef struct Booking {
    int booking_ID ;
    int pet_ID ;
    char in_date[11] ;
    char in_time[8] ;
    char out_date[11] ;
    char out_time[8] ;
    float day_rate ;
} Booking ;

Booking *Create_Booking(int bID, int pID, char *in_date, char
    *in_time, char *out_date, char *out_time, float rate) ;
void Free_Booking(Booking *booking_ptr) ;

#endif /* BOOKINGS_H */