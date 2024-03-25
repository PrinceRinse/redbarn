#ifndef CLIENTS_H
#define CLIENTS_H

typedef struct Client {
    int client_ID ;
    char *last_name ;
    char *first_name1 ;
    char *first_name2 ;
    char *address ;
    char *city ;
    char state[3] ;
    char zip[6] ;
    char phone[16] ;
    char emergency[16] ;
} Client ;

Client *Create_Client(int cID, char *lname, char *fname1, char *fname2,
    char *addr, char *cty, char *state, char *zip, char *ph, char *emcy) ;
void Free_Client(Client *client_ptr) ;

#endif /* CLIENTS_H */