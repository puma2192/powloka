#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

#include <sys/stat.h>

int ll(int argc, char *argv[]) {
    DIR *dir = opendir(".");
    if (dir) {
        struct dirent *ent;
                if (1 == 1) {
            while ((ent = readdir(dir)) != NULL) {
                
                
                struct stat buff;
                if (!stat(ent->d_name, &buff)) {

                    printf((S_ISDIR(buff.st_mode)) ? "d" : "-");
                    printf((buff.st_mode & S_IRUSR) ? "r" : "-");
                    printf((buff.st_mode & S_IWUSR) ? "w" : "-");
                    printf((buff.st_mode & S_IXUSR) ? "x" : "-");
                    printf((buff.st_mode & S_IRGRP) ? "r" : "-");
                    printf((buff.st_mode & S_IWGRP) ? "w" : "-");
                    printf((buff.st_mode & S_IXGRP) ? "x" : "-");
                    printf((buff.st_mode & S_IROTH) ? "r" : "-");
                    printf((buff.st_mode & S_IWOTH) ? "w" : "-");
                    printf((buff.st_mode & S_IXOTH) ? "x" : "-");
                }
		printf("\t%s\t\n",  ent->d_name);
                       
                
            }
        } else if (argc == 2 && strcmp(argv[1], "l")) {
            while ((ent = readdir(dir)) != NULL) {

                printf("%d\t\t%s\t\t%d\t\n", (int) ent->d_ino, ent->d_name, ent->d_type);
            }
        } else {
            printf("error");
        }
        printf("\n");
    } else {
        fprintf(stderr, "Error\n");
    }
    return 0;
}
