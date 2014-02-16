#include <stdio.h>
#include <unistd.h>

int exec()//int /argc, char *argv[])
{
DIR *dir = opendir("."); //otwarcie katalogu
	if(dir){
	 struct dirent *ent;
int ret;
char parametr; //dekklaracja zmiennej parametr w której będzie zapisana ścieżka
printf("sciezka? \n");
scanf("%s", parametr, NULL);//czekanie na podanie ścieżki przez użytkownika
ret = execl(parametr," ",NULL);
printf("failed ret = %d\n", ret);
}
}

