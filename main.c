//#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "pwd.h"
#include "ls.h"
#include "exec.h"
#include "ll.h"
//#include "env.h"
#define BUFFER_SIZE 1<<16 // zdefiniowanie stałej BUFFER przechowującej nasze dane 
#define ARR_SIZE         1<<16

/* parsowanie poleceń*/
void parse_args(char *buffer, char** args, size_t args_size, size_t *nargs)
{
    char *buf_args[args_size]; 
    char **cp;
    char *wbuf;
    size_t i, j;
    
    wbuf=buffer;
    buf_args[0]=buffer;
    args[0] =buffer;
    
    for(cp=buf_args; (*cp=strsep(&wbuf, " \n\t")) != NULL ;){
        if ((*cp != '\0') && (++cp >= &buf_args[args_size]))
            break;
    }
    
    for (j=i=0; buf_args[i]!=NULL; i++){
        if(strlen(buf_args[i])>0)
            args[j++]=buf_args[i];
    }
    
    *nargs=j;
    args[j]=NULL;
}

/*funkcja główna*/
int main(int argc, char *argv[], char *envp[])
{
printf("***************************************************************** \n");
printf("*                 Powlokę wykonali:                             * \n");
printf("*                 Piotr Rzęzawa Grupa 11D Nr Albumu 2177        * \n");
printf("*                 Aleksandra Bykowska Grupa 11E Nr Albumu 2230  * \n");
printf("*                 Sebastian Ostrowski Grupa 11D Nr Albumu 2389  * \n");
printf("*                 Grzegorz Kur Grupa 11D Nr Albumu 2351         * \n");
printf("***************************************************************** \n");
printf("*                 Polecenia Powloki:                            * \n");
printf("*                 pwd- wyświetla w jakim katalogu jesteśmy      * \n");
printf("*                 cd- cd+[nazwa katalogu]- przejście do katalogu* \n");
printf("*    ls- wyświetla zawartość katalogu ls+[nazwa katalogu]       * \n");
printf("*    ll - wyświetla zawartośc katalogu i uprawnienia            * \n");
printf("*    execl -uruchomienie programu                               * \n");
printf("*    env- wyświetla zmienne środowiskowe                        * \n");
printf("*    exit- wyjście                                              * \n");
printf("***************************************************************** \n");
   
    char buffer[BUFFER_SIZE]; // rozmiar buffora
    char *args[ARR_SIZE]; //rozmiar tablicy

    int *ret_status;
    size_t nargs;
    pid_t pid;
    
    while(1){
        printf("powloka~$ "); //prompt
        fgets(buffer, BUFFER_SIZE, stdin);
        parse_args(buffer, args, ARR_SIZE, &nargs);
        if (nargs==0) continue;
        if (!strcmp(args[0], "exit" )) exit(0); //wbudowane polecenie exit
        if (!strcmp(args[0], "cd" )) { //wbudowane polecenie cd 
                        chdir(args[1]);

                        continue;
                        }
/*wywołanie funkcji pwd*/
if (!strcmp(args[0], "pwd" ))
{

pwd();
continue; 
}
/*wywołanie funkcji ls*/
if (!strcmp(args[0], "ls" ))
{
if(args[1]==NULL)
{
ls(argc, argv);
}
if(args[1]!=NULL){
	char miejsce[256]; //deklaracja tablicy o wielkości 256 znaków  
	getcwd(miejsce, 256); //getcwd podaje aktualny katalog roboczy w tym wypadku przypisujemy go do tablicy miejsce 
	chdir(args[1]); 
	ls(argc, argv); //wywołanie funkcji ls 
	chdir(miejsce); //zmiana katalogu domowego na miejsce podane przez użytkownika
}
continue; 
}
/*wywołanie funkcji exec */
if (!strcmp(args[0], "execl"))
{

exec ();  ;
continue; 
}
/*wywołanie funkcji ll*/
if (!strcmp(args[0], "ll" ))
{

ll(argc, argv);
continue; 
}


if (!strcmp(args[0],"env")){
    int i = 0;
    for (i = 0; i < 4; i++)
        if (args[i] == NULL) {
            printf("Missing argument %d. \n Usage: setenv [Name] [value] [flag]\n", i);
            return 0;
        }
	printf("Ustawiłem zmienną %s na %s z flagą %s \n",args[1],args[2],args[3]);
     	setenv(args[1], args[2], (int) args[3]);
continue;

}

if (!strcmp(args[0],"getEnv")){

printf("Env %s, %s \n",args[1],getenv(args[1]));
continue;
}


/*forkowanie*/
      pid = fork();
        if (pid){
            pid = wait(ret_status);
        } else {
            if(execvp(args[0], args)) {
                puts(strerror(errno));
                exit(127);

           }
        }
    }
    return 0;
}
