#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 0;
pthread_mutex_t mutex;

void* increase(void* var){
    pthread_mutex_lock(&mutex);
    global_var++;
    pthread_mutex_unlock(&mutex);
    printf(global_var);
    return var;
}

int main(){
  pthread_t thr[5];
  pthread_mutex_init(&mutex, NULL);
  int x = 0;
  for(x;x < 5;x++){
    pthread_create(&thr[x], NULL, increase, NULL);
  }
  int y = 0;
  for(y;y < 5;y++){
    pthread_join(thr[y], NULL);
}
    return 0;
}