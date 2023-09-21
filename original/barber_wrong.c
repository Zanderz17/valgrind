#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define SILLAS 10

int cli=0;
int bar=0;
int mutex=1;
int esperando = SILLAS;

void espera(int *sem){
	while (*sem == 0) continue;
	(*sem)--;
}

void atiende(int *sem){
	(*sem)++;
}

void *barbero (void *num){
	while (1){
		espera(&cli);
		printf("Hay %d clientes en la sala\n",SILLAS-esperando);
		if (esperando<SILLAS)
			esperando++;
			atiende(&bar);
			printf("Barbero cortando cabello\n");
		sleep(3);
	}
}

void *cliente (void *num){
	while (1){
		sleep(2);
		if (esperando>0){
			esperando--;
			atiende(&cli);
		}
	}
}


int main(){
	pthread_t thr[2];
	pthread_create (&thr[0], NULL, barbero, NULL);
	pthread_create (&thr[1], NULL, cliente, NULL);
	int i=0;
	for(i ; i<2; i++){
		pthread_join(thr[i],NULL);
	}
}
