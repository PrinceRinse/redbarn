#ifndef DOGS_H
#define DOGS_H

typedef struct Dog {
    int pet_ID ;
    int owner_ID ;
    char *dog_name ;
    char *dog_breed ;
    char color[4] ;
    char sex ;
    char birth_date[11] ;
    int vet_ID ;
    float day_rate ;
} Dog ;

Dog *Create_Dog(int pID, int oID, char *name, char *breed, char
    *color, char sex, char *bd, int vID, float rate) ;
void Free_Dog(Dog *dog_ptr) ;

#endif /* DOGS_H */