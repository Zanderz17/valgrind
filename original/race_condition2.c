#include <pthread.h>

int global_var = 0;

void* increase(void* var){
    global_var++;
}

int main(){
  pthread_t thr[5];
  int x = 0;
  for(x;x < 5;x++){
    pthread_create(&thr[x], NULL, increase, NULL);
  }
  int y = 0;
  for(y ;y < 5;y++){
    pthread_join(thr[y], NULL);
}

    return 0;
}