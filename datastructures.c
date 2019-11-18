struct MenuItem {
    char *Name;
    float Price;
};
struct Menu {
    struct MenuItem *MenuItem[2048];
};
