#include "array_list_int.h"

#include <stdlib.h> /* For malloc and free */

#define MAGIC 314159265

struct array_list_int{
  int *a;
  int size;
  int capacity;
  int magic;
};

/* Internal functions */

/* Check if the pointer actually points to a valid array_list_int struc */
int ali_check_type(array_list_int ali){
  if (ali->magic!=MAGIC){
    return 0;
  } else {
    return 1;
  }
}

/* Increase capacity size of the array_list_int internal storage */
int ali_realloc(array_list_int ali){
  /* TODO: */
  ali->capacity++;
  int *x = (int*)malloc(sizeof(int)*ali->capacity);
  int i;
  for (i = 0; i < ali->size; ++i) {
    x[i] = ali->a[i];
  }

  free(ali->a);

  ali->a = x;

  return x ? 1 : 0;
/* Realloc could not allocate new memory */
}


/* External (public) functions.
 * + Defined in array_list_int.h file
 */

/* creates new instance of a dynamic array */
array_list_int ali_create(){
  array_list_int ali= (array_list_int)malloc(sizeof(struct array_list_int));
  ali->a = (int*)malloc(sizeof(int)*4);
  ali->size=0;
  ali->capacity=4;
  ali->magic=MAGIC;
  return ali;
}

/* Gets the element at index 'index' */
int ali_get(array_list_int ali, int index){
  if (!ali_check_type(ali))
    return 0;
  if (index<0 || index>=ali->size){
    return 0;
  }
  return ali->a[index];
}

/* Adds elemento 'i' to the end of the dynamic array */
unsigned int ali_push_back(array_list_int ali, int i){
  if (!ali_check_type(ali))
    return 0;
  if (ali->size == ali->capacity)
    if (!ali_realloc(ali))
      return ali->size;
  ali->a[ali->size++]=i;
  return ali->size;
}

/* Removes last element of dynamic array 'ali'
 *
 * PROBLEMA: Quando ali não for um ponteiro válido???
 */
unsigned int ali_pop_back(array_list_int ali){
  if (!ali_check_type(ali))
    return 0;
if (ali->size == 0)
    return 0;
  return --(ali->size);
}


/* Gets number of int elements stored in 'ali' */
unsigned int ali_size(array_list_int ali){
  if (!ali_check_type(ali))
    return 0;
  return ali->size;
}


/*
 * TODO:
*/
int ali_find(array_list_int ali, int element){
  int i, elementIndex = -1;
  if(!ali_check_type(ali)){
    return 0;
  }
    for(i=0;i < ali->size; i++){
      if((ali -> a[i]) == element){
        elementIndex =  i;

      }

  }
return elementIndex;
}

/**
 * TODO:
 */
int ali_insert_at(array_list_int ali, int index, int value){
  if (!ali_check_type(ali) || index < 0 || index >= ali->size)
    return -1;
  if (ali->size == ali->capacity)
    if (!ali_realloc(ali))
      return -1;

  int i = ali->capacity+1;

  while (i-->index)
    ali->a[i] = ali->a[i-1];

  ali->size++;
  ali->a[index] = value;

  return ali->size;


}

/**
 * TODO:
 */
int ali_remove_from(array_list_int ali, int index){
  int i;
  if(!ali_check_type(ali) || index < 0 || index > (ali -> size))
      return 0;
    for(i = index+1; i < (ali -> size);i++){
        if(i < (ali -> size))
        ali -> a[i-1] = ali -> a[i];

    }
return --(ali->size);


}

/**
 * TODO: */
unsigned int ali_capacity(array_list_int ali){
  if(!ali_check_type(ali)){
      return 0;

  }
      return ali -> capacity;

}


/**
 * TODO: */
double ali_percent_occuped(array_list_int ali){
  double percent = 0.0;
  if(!ali_check_type(ali)){
    return 0.0;
  }
  else{
    if(ali -> size != 0){
      percent = ((ali->capacity) / (ali -> size)) * 100 ;
      return percent;
    }

  }

}

/* Release memory used by the struct and invalidate it. */
void ali_destroy(array_list_int ali){
  free(ali->a);
  ali->size=0;
  ali->capacity=0;
  ali->magic=0;
}
