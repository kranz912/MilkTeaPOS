#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructures.c"
#define Classic_Pearl

int  _MENU_INDEX = 0;


struct Menu * _MENU;

void Push(struct MenuItem item){
    printf("%f \n",item.Name);
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

void readMenuFile(char *location){
    FILE* stream = fopen(location,"r");    
    char line[1024];
    while (fgets(line,1024, stream))
    {
        char * tmp = strdup(line);
        char * name=getfield(tmp,1);
        float price = strtod(getfield(tmp,2),NULL);
        struct MenuItem item = {name, price};
        Push(item);
    }
    
}

void printItem(int index){
    printf("[%d] \t %s \t %f",index, _MENU->MenuItem[index].Name, _MENU->MenuItem[index].Price);
}

int main(){
   // struct Menu *Menu;
    readMenuFile("menu.txt");
    printf("%f", _MENU->MenuItem[0].Name);
    //printf("%f",Menu->MenuItem[0].Price);
    printf("hello world");
    printItem(0);



}
