#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructures.c"

int  _MENU_INDEX = 0;

struct MenuItem _MENU[2048];

void Push(struct MenuItem item){
    _MENU[_MENU_INDEX] = item;
    _MENU_INDEX +=1;
  
}


struct chart
{
    int menuitem;
    int quantity;
};



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
int main(){

    
    readMenuFile("menu.txt");
    system("CLS");
     //intf("%s\n", &_MENU->MenuItem[20].Name);
    for (int i = 0; i < _MENU_INDEX; i++)
    {
        /* code */
        printItem(i);

    }
    int input =0;
    int quantity=0;
    while (input!=999)
    {
   
        /* code */
        printf("Enter Customer's Order:\n");
        printf("(Enter 999 to finish orders)\n");
        printf("%-13s %s \n", "Product","Quantity");
        scanf("%d",&input);
        //scanf("\t %d",&quantity);
       
    }
    

}