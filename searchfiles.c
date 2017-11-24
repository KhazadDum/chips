long int FindFile(FILE* log, char *catalog,char *mask)
{
    static long int counter = 0;
    WIN32_FIND_DATA findFileData;
    char buf[1024];
    strcpy(buf,catalog);
    strcat(buf,"\\");
    strcat(buf,mask);
    HANDLE hFind = FindFirstFile(buf, &findFileData);
    if (hFind!=INVALID_HANDLE_VALUE) {
        do {
            if((!(findFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))&&strcmp(findFileData.cFileName,".")&&strcmp(findFileData.cFileName,"..")) {
                strcpy(buf,catalog);
                strcat(buf,"\\");
                strcat(buf,findFileData.cFileName);
                counter++;
                if(log){
                    fprintf(log,"¹%d: %s\n",counter,buf);
                }
                printf("%s\n",buf);

            }

        } while(FindNextFile(hFind,&findFileData));
    }
    strcpy(buf,catalog);
    strcat(buf,"\\*");
    hFind = FindFirstFile(buf,&findFileData);
    if(hFind!=INVALID_HANDLE_VALUE) {
        while(FindNextFile(hFind,&findFileData)) {
            if((findFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) &&strcmp(findFileData.cFileName,".")&&strcmp(findFileData.cFileName,"..")) {
                strcpy(buf,catalog);
                strcat(buf,"\\");
                strcat(buf,findFileData.cFileName);
                FindFile(log,buf,mask);
            }
        }
        FindClose(hFind);
    }
    return counter;
}

