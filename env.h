int env(char *argsList) {
    int i = 0;
    for (i = 0; i < 4; i++)
        if (argsList[i] == NULL) {
            printf("Missing argument %d. \n Usage: setenv [Name] [value] [flag]\n", i);
            return 0;
        }
    return setenv(argsList[1], argsList[2], (int) argsList[3]);
}
