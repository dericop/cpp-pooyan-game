#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

#define MAX_PERSONAJES 4
#define MAX_GLOBOS 4
#define TIEMPO 60

/*
* Estructuras y prototipos
*/

typedef struct 
{
	int x;
	int y;
} Flecha;

typedef struct
{
	int id;
	int puntaje;
	int x;
	int y;
	char usuario; // m para máquina, u para usuario
	Flecha flecha;
} Personaje;

typedef struct
{
	int id;
	int x;
	int y;
} Globo;

/*void *funPersonajes(Personaje *);
void *funGlobos(Globo *);
void *contTiempo(void *);*/
void crearHilos(pthread_t *, pthread_t *);
void iniciarJuego(pthread_t *, pthread_t *, pthread_t *);
void iniciarGlobales();

/*
* Variables globales
*/
Personaje personajes[MAX_PERSONAJES];
Globo *globos;//[MAX_GLOBOS];
int valTiempo;
int dirMem;
pthread_mutex_t mutex;

/*
* main
*/
int main(int argc, char const *argv[])
{	
	pthread_t hilosPer[MAX_PERSONAJES];
	pthread_t hilosGlobos[MAX_GLOBOS];
	pthread_t hiloTiempo;

	iniciarGlobales();
	
	/*
	* liberar recursos
	*/
	shmdt(globos);
	shmctl(dirMem, IPC_RMID, 0);
	pthread_mutex_destroy(&mutex);
	return 0;
}

void *funPersonajes(Personaje *p){
	while(valTiempo>0){
		/* condiciones de disparo */
		
		/*Funciones a llamar para cuando se efectue el disparo
		*
		if(pthread_mutex_lock(*mutex)==0){
			//animar flecha y verificar colisión con alguno de los globos
			pthread_mutex_unlock(*mutex);
		}
		*/
	}

	pthread_exit(NULL);
}

void *funGlobos(Globo *g){
	while(valTiempo>0){
		/* modificar coordenadas x,y */
	}

	pthread_exit(NULL);
}

void *contTiempo(void *args){
	while(valTiempo>0){
		valTiempo--;
		sleep(1);
	}
}

void crearHilos(pthread_t *hilosPer, pthread_t *hilosGlobos){
	int i;
	for(i=0;i<MAX_PERSONAJES;++i){
		pthread_create(&hilosPer[i], NULL, (void *) &funPersonajes, (void *) &personajes[i]);
	}

	for(i=0;i<MAX_GLOBOS;++i){
		pthread_create(&hilosGlobos[i], NULL, (void *) &funGlobos, (void *) &globos[i]);
	}
}

void iniciarJuego(pthread_t *hilosPer, pthread_t *hilosGlobos, pthread_t *hiloTiempo){
	pthread_create(hiloTiempo, NULL, &contTiempo, NULL);

	pthread_join(*hiloTiempo, NULL);

	int i;
	for(i=0;i<MAX_PERSONAJES;++i){
		pthread_join(hilosPer[i], NULL);
	}

	for(i=0;i<MAX_GLOBOS;++i){
		pthread_join(hilosGlobos[i], NULL);
	}

	/*
	* liberar recursos
	*/
	shmdt(globos);
	shmctl(dirMem, IPC_RMID, 0);
	pthread_mutex_destroy(&mutex);
}

void iniciarGlobales(const char *arg){
	valTiempo=TIEMPO;
	int i;

	for(i=0;i<MAX_PERSONAJES;++i){
		personajes[i].id=i;
		personajes[i].usuario='m';
	}

	i=-1;

	do {
		printf("Seleccione personaje (1, 2, 3 ó 4): ");
		scanf("%d", &i);
	}while(i<1 || i>4);

	personajes[i-1].usuario='u';

	if((dirMem=shmget(ftok(arg, 'K'), sizeof(globos)*MAX_GLOBOS, IPC_CREAT | 0600))==-1){
		perror("shmget");
		exit(-1);
	}

	if((globos=shmat(dirMem, 0, 0))==((void *)-1)){
		perror("shmat");
		exit(-1);
	}

	for(i=0;i<MAX_GLOBOS;++i){
		globos[i].id=i;
	}

	pthread_mutex_init(&mutex, NULL);
}