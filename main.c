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
void buildCart(){
    for (int i = 0; i < _MENU_INDEX; i++)
    {
       char * name = _MENU[i].Name;
       _CART[_CART_INDEX].id = _CART_INDEX;
       _CART[_CART_INDEX].Name = name;
       _CART[_CART_INDEX].quantity = 0;
       _CART_INDEX += 1;
    }
}
void showCart(){
    for (int i = 0; i < _CART_INDEX; i++)
    {
        printf("[%d] %-50s %-12d \n",_CART[_CART_INDEX].Name, _CART[_CART_INDEX].quantity);
    }
}

int main(){

    
    readMenuFile("menu.txt");
    system("CLS");
    buildCart();
    char * input[50];
    int quantity=0;
    while (input!="cancel" && input !="done")
    {
        showMenu();
        printf("Enter item number to add it into the cart");
        printf("Enter done to finish orders\n");
        printf("Enter cancel to cancel orders\n");
        printf("Enter cart to see what is inside the cart \n");
        printf("Input: ");
        scanf("%s",input);
        if(input!="cancel" && input !="done" && input != "cart"){
            printf("Enter Quantity: ");
            scanf("%s",input);
        }
        if(input == "cart"){
            showCart();
        }
        system("CLS");
    }
    

}