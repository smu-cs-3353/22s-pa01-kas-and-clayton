//
// Created by Clayton Manchac on 1/29/22.
//

#include "Wall.h"

//constructors
Wall::Wall() {
    totalPrice = 0;
    widthRemaining = 0;
    numPaintings = 0;
}
//overlaoded constructor
Wall::Wall(int w) {
    totalPrice = 0;
    widthRemaining = w;
    numPaintings = 0;
}

//add a painting to the wall (vector of paintings). decrease the width remaining
void Wall::addPainting(Painting p) {
    pList.push_back(p);
    totalPrice += p.getPrice();
    widthRemaining -= p.getWidth();
    numPaintings++;
}

//get total price of the wall
float Wall::getTotalPrice() {
    return totalPrice;
}

//get the width remaining of the wall
float Wall::getWidthRemaining() {
    return widthRemaining;
}

//print out to an output file that is passed in. value at the top followed by
//painting id, cost, width, and height
void Wall::print(ofstream &file) {
    file << "$" << totalPrice << endl;
    for (int i = 0; i < pList.size(); i++) {
        file << pList.at(i).getID() << " " << pList.at(i).getPrice() << " " << pList.at(i).getWidth() << " ";
        file << pList.at(i).getHeight() << endl;
    }
}

//get the number of paintings on the wall
int Wall::getNumPaintings() {
    for (int i = 0; i < pList.size(); i++) {
        numPaintings++;
    }
    return numPaintings;
}
