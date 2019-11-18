#include <stdio.h>
#include <string.h>
#include<limits.h> 
#define Classic_Pearl

int  _MENU_INDEX = 0;
struct MenuItem {
    char Item[50];
    float Price;
};
struct Menu {
    struct MenuItem MenuItem[INT_MAX];
};



void Push(struct Menu *_menu,struct MenuItem item){
    printf("%f",item.Price);
    _menu->MenuItem[_MENU_INDEX] = item;
    _MENU_INDEX +=1;
}

int main(){
    struct Menu *Menu;

    printf("%f",Menu->MenuItem[0].Price);
    printf("hello world");
}
