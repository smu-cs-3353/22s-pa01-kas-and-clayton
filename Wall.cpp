//
// Created by Clayton Manchac on 1/29/22.
//

#include "Wall.h"

//constructors
Wall::Wall() {
    totalPrice = 0;
    widthRemaining = 0;
}
Wall::Wall(int w) {
    totalPrice = 0;
    widthRemaining = w;
}
Wall::~Wall() {
    delete totalPrice;
    delete widthRemaining;
    delete pList;
}

void Wall::addPainting(Painting p) {
    pList.push_back(p)
    totalPrice += p.getPrice;
    widthRemaining -= p.getWidth();
}
float Wall::getTotalPrice() {
    return totalPrice;
}
float Wall::getWidthRemaining() {
    return widthRemaining;
}
void Wall::print(ofstream &file) {
    file << "$" << totalPrice << endl;
    for (int i = 0; i < pList.size(); i++) {
        file << pList.at(i).getID() << " " << pList.at(i).getPrice() << " " << pList.at(i).getWidth() << " " pList.at(i).getHeight() << endl;
    }
}
int Wall::getNumPaintings() {
    for (int i = 0; i < pList.size(); i++) {
        numPaintings++;
    }
    return numPaintings;
}
