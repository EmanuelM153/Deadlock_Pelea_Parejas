#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t aceptóSuError, pidióPerdon;

void* pedirPerdon(void *arg) {
	char *persona = arg;
	printf("%s: Esperando que acepte su error...\n", persona);

	sem_wait(&aceptóSuError);

	printf("%s: Perdooon\n", persona);
	sem_post(&pidióPerdon);

	return NULL;
}

void* aceptarError(void *arg) {
	char *persona = arg;
	printf("%s: Esperando que pida perdón...\n", persona);

	sem_wait(&pidióPerdon);

	printf("%s: Acepto mi error\n", persona);
	sem_post(&aceptóSuError);

	return NULL;
}

int main() {
	pthread_t hombre, mujer;

	sem_init(&aceptóSuError, 0, 0);
	sem_init(&pidióPerdon, 0, 0);

	srand(time(NULL));

	printf("@!#?@!\n");
	sleep(1);
	printf("-------------------\n");
	printf("Discusión acabada\n");

	if (rand() % 2) {
		pthread_create(&hombre, NULL, pedirPerdon, "👨");
		pthread_create(&mujer, NULL, aceptarError, "👩");
	} else {
		pthread_create(&mujer, NULL, pedirPerdon, "👩");
		pthread_create(&hombre, NULL, aceptarError, "👨");
	}

	pthread_join(hombre, NULL);
	pthread_join(mujer, NULL);

	sem_destroy(&pidióPerdon);
	sem_destroy(&aceptóSuError);
	return 0;
}
