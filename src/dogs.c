#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/dogs.h"

// Max string lengths for Dog member vars
const int dog_name_max_len = 20 ;
const int dog_breed_max_len = 30 ;

// Dog constructor
Dog *Create_Dog(int pID, int oID, char *name, char *breed, char
    *color, char sex, char *bd, int vID, float rate) {
    
    Dog *dog_ptr = malloc(sizeof(Dog)) ;
    if (dog_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Dog\n") ;
        return NULL ;
    }
    // Set NULL to avoid undefined behavior when calling Free_Dog()
    dog_ptr->dog_name = NULL ;
    dog_ptr->dog_breed = NULL ;

    dog_ptr->pet_ID = pID ;
    dog_ptr->owner_ID = oID ;

    dog_ptr->dog_name = malloc(Utils_min(strlen(name) + 1, dog_name_max_len)) ;
    if (dog_ptr->dog_name == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Dog member dog_name\n") ;
        Free_Dog(dog_ptr) ;
        return NULL ;
    }
    Utils_strcpy_trunc(dog_ptr->dog_name, name, dog_name_max_len) ;

    dog_ptr->dog_breed = malloc(Utils_min(strlen(breed) + 1, dog_breed_max_len)) ;
    if (dog_ptr->dog_breed == NULL) {
        fprintf(stderr, "Memory allocation failed for struct Dog member dog_breed\n") ;
        Free_Dog(dog_ptr) ;
        return NULL ;
    }
    Utils_strcpy_trunc(dog_ptr->dog_breed, breed, dog_breed_max_len) ;

    Utils_strcpy_trunc(dog_ptr->color, color, 4) ;
    dog_ptr->sex = sex ;
    Utils_strcpy_trunc(dog_ptr->birth_date, bd, 11) ;
    dog_ptr->vet_ID = vID ;
    dog_ptr->day_rate = rate ;

    return dog_ptr ;
}

// Dog destructor
void Free_Dog(Dog *dog_ptr) {
    free(dog_ptr->dog_name) ;
    free(dog_ptr->dog_breed) ;
    free(dog_ptr) ;
}