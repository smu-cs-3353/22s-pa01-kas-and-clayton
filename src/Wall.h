//
// Created by Clayton Manchac on 1/29/22.
//

#ifndef INC_22S_PA01_KAS_AND_CLAYTON_WALL_H
#define INC_22S_PA01_KAS_AND_CLAYTON_WALL_H

#include "Painting.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;


class Wall {
private:
    vector<Painting> pList;
    float totalPrice;
    float widthRemaining;
    int numPaintings;
public:
    //constructors
    Wall();
    Wall(int);
    //~Wall();

    //methods
    void addPainting(Painting);
    float getTotalPrice();
    float getWidthRemaining();
    void print(ofstream&);
    int getNumPaintings();
//    void setWidthWall(int);
};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_WALL_H
