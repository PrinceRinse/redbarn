#include <stdio.h>
#include <string.h>
#include "../include/csv.h"
#include "../include/bookings.h"
#include "../include/clients.h"
#include "../include/dogs.h"
#include "../include/version.h"
#include "../include/utils.h"

enum Write_Types {
    BOOKING,
    CLIENT,
    DOG
} ;

// Write struct member variables to corresponding CSV file in dat/ using libcsv
// Must open file as binary with read/write permissions, "r+b"
int Write_Struct_Data(FILE *file_ptr, void *struct_ptr, int type) {
    switch (type) {
        case BOOKING :
            Booking *booking_ptr = (Booking *) struct_ptr ;
            
            
            /* TODO: Booking member var writes */


            break ;

        case CLIENT :
            Client *client_ptr = (Client *) struct_ptr ;

            char buf[12] ; // buffer used to convert int to string
            snprintf(buf, sizeof buf, "%d", client_ptr->client_ID) ;
            csv_fwrite(file_ptr, buf, strlen(buf)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->last_name, strlen(client_ptr->last_name)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->first_name1, strlen(client_ptr->first_name1)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->first_name2, strlen(client_ptr->first_name2)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->address, strlen(client_ptr->address)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->city, strlen(client_ptr->city)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->state, strlen(client_ptr->state)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->zip, strlen(client_ptr->zip)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->phone, strlen(client_ptr->phone)) ;
            fputc(',', file_ptr) ;
            csv_fwrite(file_ptr, client_ptr->emergency, strlen(client_ptr->emergency)) ;
            fputc('\n', file_ptr) ;
            break ;

        case DOG :
            Dog *dog_ptr = (Dog *) struct_ptr ;


            /* TODO: Dog member var writes */


            break ;
    }

    return 0 ;
}

int main() {
    //Dog *dog_ptr = Create_Dog(0, 0, "Fifi", "yorkie", "blk", 'F', "12/15/2021", 0, 35.0) ;
    //Client *test_client_ptr = Create_Client(0, "Johnson", "Mark", "",
    //"399 Crimson Ct", "Harveysburg", "OH", "45400", "5136661234", "9378414135") ;

    

    clrscr() ;
    printf(YLW "--------+--------+-------- " RED "RedBarn KennelMgr " CYN "v%u.%02u.%02u" YLW " --------"
        "+--------+--------\n", MAJOR_VERSION, MINOR_VERSION, REVISION) ;
    printf("\n") ;
    // ASCII art by Joan Stark, via https://github.com/oldcompcz/jgs
    printf("                                             " WHT "+&-\n"
        "                  " RED ",------. ,-----.         " WHT "_.-^-._    .--.\n"
        "                  " RED "|  .--. '|  |) /_     " WHT ".-'   _   '-. |__|\n"
        "                  " RED "|  '--'.'|  .-.  \\   " WHT "/     |_|     \\|  |\n"
        "                  " RED "|  |\\  \\ |  '--' /  " WHT "/               \\  |\n"
        "                  " RED "`--' '--'`------'  " WHT "/|     _____     |\\ |\n"
        "                                      |    |==|==|    |  |\n"
        "                  |---|---|---|---|---|    |--|--|    |  |\n"
        "                  |---|---|---|---|---|    |==|==|    |  | jgs\n"
        "                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n") ;
    printf("\n") ;
    printf(YLW "--------+--------+--------+--------+--------+--------+--------+--------+--------\n" RESET) ;


    // TODO: add PATH vars?
    FILE *client_file_ptr ;
    client_file_ptr = fopen("./dat/clients.csv", "r+b") ; // open bin for libcsv
    if (client_file_ptr == NULL) {
        client_file_ptr = fopen("./dat/clients.csv", "w+b") ;
        if (client_file_ptr == NULL) {
            fprintf(stderr, "Failed to create file\n") ;
            return 1 ;
        }
    }
    // +1 array sizes to fit newline when reading with fgets()
    char buf[6+1] ;
    int cID ;
    char lname[20+1] ;
    char fname1[15+1] ;
    char fname2[15+1] ;
    char addr[35+1] ;
    char cty[20+1] ;
    char state[3+1] ;
    char zip[6+1] ;
    char ph[16+1] ;
    char emcy[16+1] ;

    /* BUFFER IS CONTAMINATED WHEN FGETS() READS A STRING LARGER THAN ITS
    ALLOTED SIZE. This is not user-safe, use only for testing           */
    printf("Enter client ID: ") ;
    fgets(buf, sizeof buf, stdin) ;
    cID = strtol(buf, NULL, 10) ;
    printf("Enter last name: ") ;
    fgets(lname, sizeof lname, stdin) ;
    lname[strcspn(lname, "\r\n")] = 0 ; // discard newline
    printf("Enter first name, 1/2: ") ;
    fgets(fname1, sizeof fname1, stdin) ;
    fname1[strcspn(fname1, "\r\n")] = 0 ;
    printf("Enter first name, 2/2: ") ;
    fgets(fname2, sizeof fname2, stdin) ;
    fname2[strcspn(fname2, "\r\n")] = 0 ;
    printf("Enter street address: ") ;
    fgets(addr, sizeof addr, stdin) ;
    addr[strcspn(addr, "\r\n")] = 0 ;
    printf("Enter city: ") ;
    fgets(cty, sizeof cty, stdin) ;
    cty[strcspn(cty, "\r\n")] = 0 ;
    printf("Enter state abbreviation (ex. OH): ") ;
    fgets(state, sizeof state, stdin) ;
    state[strcspn(state, "\r\n")] = 0 ;
    printf("Enter 5-digit zip code: ") ;
    fgets(zip, sizeof zip, stdin) ;
    zip[strcspn(zip, "\r\n")] = 0 ;
    printf("Enter phone number: ") ;
    fgets(ph, sizeof ph, stdin) ;
    ph[strcspn(ph, "\r\n")] = 0 ;
    printf("Enter emergency number: ") ;
    fgets(emcy, sizeof emcy, stdin) ;
    emcy[strcspn(emcy, "\r\n")] = 0 ;

    Client *test_client_ptr = Create_Client(cID, lname, fname1, fname2, addr,
    cty, state, zip, ph, emcy) ;

    fseek(client_file_ptr, 0, SEEK_END) ; // move to end of file to append entry
    Write_Struct_Data(client_file_ptr, test_client_ptr, CLIENT) ;

    fclose(client_file_ptr) ;
    //free(dog_ptr) ;
    return 0 ;
}