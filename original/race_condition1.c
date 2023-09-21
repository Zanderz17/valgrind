#include <pthread.h>

int var = 0; //important variable

void* child_function ( void* arg ) {
   var++; //also modify important variable
   return NULL;
}

int main ( void ) {
   pthread_t child;
   pthread_create(&child, NULL, child_function, NULL);
   var++; //modify important variable
   pthread_join(child, NULL);
   return 0;
}