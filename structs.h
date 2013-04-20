#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
struct bullets
{
    int x_coor;
    int y_coor;
    int damage;
};
struct enemies
{
    int x;
    int y;
    bool left;
    int health;
    bool kill;
};
#endif // STRUCTS_H_INCLUDED
