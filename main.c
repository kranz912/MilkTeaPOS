#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructures.c"

int  _MENU_INDEX = 0;
int  _CART_INDEX = 0;
struct MenuItem _MENU[2048];
struct CartItems _CART[2048]; 
void Push(struct MenuItem item){
    _MENU[_MENU_INDEX] = item;
    _MENU_INDEX +=1;
  
}


const char * getfield (char * line, int num){
    const char * token;
    int cursor =0;
    token = strtok(line,",\n");
    if(num>=cursor){
        while(token!=NULL){
            if(cursor!=num){
                token =strtok (NULL,",\n");
            }
            else{
                return token;
            }
            cursor++;
        }

    }
    return NULL;
}

void readMenuFile(char *location){
    FILE* stream = fopen(location,"r");    
    char line[1024];
    while (fgets(line,1024, stream))
    {
        char * name=getfield(strdup(line),0);
        char * strprice = getfield(strdup(line),1);
        float price =  strtof(strprice,NULL);
    
        struct MenuItem item = {name, price};
        Push(item);
    }
    
}

void printItem(int index){
    printf("[%d] %-50s %-12f \n",index, _MENU[index].Name, _MENU[index].Price);
}
float getItemPrice(int index){
    return _MENU[index].Price;
}
void showMenu(){
    for (int i = 0; i < _MENU_INDEX; i++)
    {
        printItem(i);

    }
}
int main(){

    
    readMenuFile("menu.txt");
    system("CLS");

    char * input[50];
    int quantity=0;
    while (input!="cancel" || input !="done")
    {
        showMenu();
        printf("(Enter done to finish orders)\n");
        printf("(Enter cancel to cancel orders)\n");
        printf("Enter Item Number: ");
        scanf("%s",input);
        if(input!="cancel" || input !="done"){
            printf("Enter Quantity: ");
            scanf("%s",input);
        }
        system("CLS");
    }
    

}