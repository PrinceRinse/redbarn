#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/clients.h"

// Max string lengths for Client member vars
const int client_fname_max_len = 15 ;
const int client_lname_max_len = 20 ;
const int client_address_max_len = 35 ;
const int client_city_max_len = 20 ;

// Client constructor
Client *Create_Client(int cID, char *lname, char *fname1, char *fname2,
    char *addr, char *cty, char *state, char *zip, char *ph, char *emcy) {
    
    Client *client_ptr = malloc(sizeof(Client)) ;
    if (client_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Client\n") ;
        return NULL ;
    }
    // Set NULL to avoid undefined behavior when calling Free_Client()
    client_ptr->last_name = NULL ;
    client_ptr->first_name1 = NULL ;
    client_ptr->first_name2 = NULL ;
    client_ptr->address = NULL ;
    client_ptr->city = NULL ;

    client_ptr->client_ID = cID ;

    client_ptr->last_name = malloc(Utils_min(strlen(lname) + 1, client_lname_max_len)) ;
    if (client_ptr->last_name == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Client member last_name\n") ;
        Free_Client(client_ptr) ;
    }
    Utils_strcpy_trunc(client_ptr->last_name, lname, client_lname_max_len) ;

    client_ptr->first_name1 = malloc(Utils_min(strlen(fname1) + 1, client_fname_max_len)) ;
    if (client_ptr->first_name1 == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Client member first_name1\n") ;
        Free_Client(client_ptr) ;
    }
    Utils_strcpy_trunc(client_ptr->first_name1, fname1, client_fname_max_len) ;

    client_ptr->first_name2 = malloc(Utils_min(strlen(fname2) + 1, client_fname_max_len)) ;
    if (client_ptr->first_name2 == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Client member first_name2\n") ;
        Free_Client(client_ptr) ;
    }
    Utils_strcpy_trunc(client_ptr->first_name2, fname2, client_fname_max_len) ;

    client_ptr->address = malloc(Utils_min(strlen(addr) + 1, client_address_max_len)) ;
    if (client_ptr->address == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Client member address\n") ;
        Free_Client(client_ptr) ;
    }
    Utils_strcpy_trunc(client_ptr->address, addr, client_address_max_len) ;

    client_ptr->city = malloc(Utils_min(strlen(cty) + 1, client_city_max_len)) ;
    if (client_ptr->city == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Client member city\n") ;
        Free_Client(client_ptr) ;
    }
    Utils_strcpy_trunc(client_ptr->city, cty, client_city_max_len) ;

    Utils_strcpy_trunc(client_ptr->state, state, 3) ;
    Utils_strcpy_trunc(client_ptr->zip, zip, 6) ;
    Utils_strcpy_trunc(client_ptr->phone, ph, 16) ;
    Utils_strcpy_trunc(client_ptr->emergency, emcy, 16) ;

    return client_ptr ;
}

// Client destructor
void Free_Client(Client *client_ptr) {
    free(client_ptr->last_name) ;
    free(client_ptr->first_name1) ;
    free(client_ptr->first_name2) ;
    free(client_ptr->address) ;
    free(client_ptr->city) ;
    free(client_ptr) ;
}