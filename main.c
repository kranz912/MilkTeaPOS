#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        _CART[_CART_INDEX].id       = _CART_INDEX;
        _CART[_CART_INDEX].Name     = name;
        _CART[_CART_INDEX].quantity = 0;
        _CART_INDEX                += 1;
    }
}
void showCart()
{
    for (int i = 0; i < _CART_INDEX; i++)
    {
        printf("%-50s %-12d \n", _CART[i].Name, _CART[i].quantity);
    }
}

void showMainMenu()
{
    printf("[menu]\t\tShow Menu\n[cart]\t\tView Cart\n[add]\t\tAdd Items\n[done]\t\tFinish Orders\n[cancel]\t\tCancel Order\n");
}

int scan_int(char * Message){
    
    char _NUM    =  0;

    while (1)
    {
        printf("%s", Message);
        
        scanf("%s",&_NUM);
        
        getch();
        
        if(isdigit(_NUM))
        {
            printf("\n");
            return _NUM;
        }
        
        else
        {
            printf("\nInvalid Input \n");
        }
    }
}



void addItem(){
    
    showMenu();
    
    int _ITEM_NUMBER =  scan_int("Enter Item Number: ");
    int _QUANTITY    =  scan_int("Enter Quantity: ");

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