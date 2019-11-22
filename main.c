#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datastructures.c"
#include <ctype.h>


int                 _MENU_INDEX         = 0;
int                 _CART_INDEX         = 0;
struct MenuItem     _MENU[2048];
struct CartItems    _CART[2048];
char    _INPUT[50];

void Push(struct MenuItem item)
{
    _MENU[_MENU_INDEX]  = item;
    _MENU_INDEX        += 1;
}

const char *getfield(char *line, int num)
{
    
    const char *token    = strtok(line, ",\n");;
          int  cursor    = 0;
    if (num >= cursor)
    {
        while (token != NULL)
        {
            if (cursor != num)
            {
                token = strtok(NULL, ",\n");
            }
            else
            {
                return token;
            }
            cursor++;
        }
    }
    return NULL;
}

void readMenuFile(char *location)
{
    FILE *stream = fopen(location, "r");
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char *name              = getfield(strdup(line), 0);
        char *strprice          = getfield(strdup(line), 1);
        float price             = strtof(strprice, NULL);
        struct MenuItem item    = {name, price};
        Push(item);
    }
}

void printItem(int index)
{
    printf("[%d] %-50s %-12f \n", index, _MENU[index].Name, _MENU[index].Price);
}
float getItemPrice(int index)
{
    return _MENU[index].Price;
}
void showMenu()
{
    for (int i = 0; i < _MENU_INDEX; i++)
    {
        printItem(i);
    }
}
void buildCart()
{
    for (int i = 0; i < _MENU_INDEX; i++)
    {
        char *name                  = _MENU[i].Name;
        _CART[_CART_INDEX].Name     = name;
        _CART[_CART_INDEX].Quantity = 0;
        _CART_INDEX                += 1;
    }
}
void showCart()
{
    for (int i = 0; i < _CART_INDEX; i++)
    {   
         printf("%-50s %-12d \n", _CART[i].Name, _CART[i].Quantity);
        
    }
}

void showMainMenu()
{
    printf("%-20s %-20s \n","[menu]","Show Menu");
    printf("%-20s %-20s \n","[cart]","View Cart");
    printf("%-20s %-20s \n","[add]","Add Items");
    printf("%-20s %-20s \n","[done]","Finish Order");
    printf("%-20s %-20s \n","[cancel]","Cancel Order");
}

bool isInt(char _c[]){
    for (int i = 0; _c[i]!='\0'; i++)
    {
        /* code */
        if(!isdigit(_c[i])){
             return false;
        }
    }
    return true;

}

int scan_int(char * Message,bool isItem){
    
    char _NUM[2049];

    while (1)
    {
        printf("%s", Message);
        
        scanf("%s",_NUM);

        printf("%s isdigit %d",_NUM,isInt(_NUM));
        if(isInt(_NUM))
        {   
            int _ret =atoi(_NUM);
            if(_ret>=0){
                if(isItem){
                    if(_ret<_CART_INDEX){
                        return _ret;
                    }
                }
                else{
                    return _ret;
                }
            }
         
        }
        printf("\nInvalid Input \n");
        
    }
}



void addItem()
{
    showMenu();

    int _ITEM_NUMBER              =  scan_int("Enter Item Number: ",true);

    int _QUANTITY                 =  scan_int("Enter Quantity: ", false);

    _CART[_ITEM_NUMBER].Quantity +=  _QUANTITY;
}


int main()
{

    readMenuFile("menu.txt");
    
    system("CLS");
    
    buildCart();

    int     _ISCANCELLED    = 0;
    int     _ISDONE         = 0;
    int     _VIEWCART       = 0;
    int     _VIEWMENU       = 0;
    int     _ADDITEM        = 0;
    
    while (!_ISCANCELLED && !_ISDONE)
    {
        showMainMenu();

        printf("Input: ");
        scanf("%s", _INPUT);

        _ISCANCELLED    = !strcmp(_INPUT, "cancel");
        _ISDONE         = !strcmp(_INPUT, "done");
        _VIEWCART       = !strcmp(_INPUT, "cart");
        _VIEWMENU       = !strcmp(_INPUT, "menu");
        _ADDITEM        = !strcmp(_INPUT, "add");
        
        system("CLS");
        
        if (_ADDITEM)
        {   
            addItem();
        }
        
        else if (_VIEWCART)
        {
            showCart();
            getch();
        }

        else if (_VIEWMENU)
        {
            showMenu();
            getch();
        }
        else if(_ISDONE){

        }

        else{
            printf("Invalid Input");
        }
        
        system("CLS");
    }
}