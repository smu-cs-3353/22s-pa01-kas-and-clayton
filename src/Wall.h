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
    vector<Painting> pList; //vector of paintings to be on the wall
    float totalPrice; //total price of the wall
    float widthRemaining; //available space left on the wall
    int numPaintings; //number of paintings on the wall
public:
    //constructors
    Wall();
    Wall(int);

    //methods to be used
    void addPainting(Painting);
    float getTotalPrice();
    float getWidthRemaining();
    void print(ofstream&);
    int getNumPaintings();
};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_WALL_H
