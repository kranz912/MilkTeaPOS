#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructures.c"

int  _MENU_INDEX = 0;


void Push(struct Menu *_MENU,struct MenuItem *item){
    _MENU->MenuItem[_MENU_INDEX] = item;
    _MENU_INDEX +=1;
}

const char * getfield (char * line, int num){
    const char * token;
    for (token = strtok(line, ";"); token && *token; token = strtok(NULL, ";\n"))
    {
        if(!--num){
            return token;
        }
    }
    return NULL;
}

void readMenuFile(struct Menu *_MENU,char *location){
    FILE* stream = fopen(location,"r");    
    char line[1024];
    while (fgets(line,1024, stream))
    {
        char * tmp = strdup(line);
        char * name=getfield(tmp,1);
        float price = strtod(getfield(tmp,2),NULL);
        printf("%s",name);
    }
    
}

void printItem(struct Menu *_MENU,int index){
    printf("[%d] \t %s \t %f",index, *_MENU->MenuItem[index]->Name, _MENU->MenuItem[index]->Price);
}

int main(){
    struct Menu *_MENU;

    readMenuFile(_MENU,"menu.txt");
    printf("%s", *_MENU->MenuItem[0]->Name);
    printf("hello world");
    printItem(_MENU,0);



}
