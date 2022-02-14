//
// Created by Clayton Manchac on 1/29/22.
//

#ifndef INC_22S_PA01_KAS_AND_CLAYTON_PAINTING_H
#define INC_22S_PA01_KAS_AND_CLAYTON_PAINTING_H

#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <iomanip>

class Painting {
private:
    //variables needed. all information about paintings
    int height;
    int width;
    float price;
    float ppuw; // price per unit width
    int id;
public:
    //getters and setters
    void setHeight(int);
    int getHeight();
    void setWidth(int);
    int getWidth();
    void setPrice(float);
    float getPrice();
    void setPPUW(float);
    float getPPUW();
    void setID(int);
    int getID();

    //constructors
    Painting();
    Painting(int, int, float, int);
};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_PAINTING_H
