//
// Created by Clayton Manchac on 1/29/22.
//

#include "Painting.h"

//constructors
Painting::Painting() {
    height = 0;
    width = 0;
    price = 0;
    ppuw = 0; //price per unit width
    id = 0;
}
Painting::Painting(int h, int w, float p, int i) {
    height = h;
    width = w;
    price = p;
    ppuw = p/w;
    id = i;
}
//Painting::~Painting() {
//    delete height;
//    delete width;
//    delete price;
//    delete ppuw;
//    delete id;
//}

//getters and setters
void Painting::setHeight(int h) {
    height = h;
}
int Painting::getHeight() {
    return height;
}
void Painting::setWidth(int w) {
    width = w;
}
int Painting::getWidth() {
    return width;
}
void Painting::setPrice(float p) {
    price = p;
}
float Painting::getPrice() {
    return price;
}
void Painting::setPPUW(float ppUnit) {
    ppuw = ppUnit;
}
float Painting::getPPUW() {
    return ppuw;
}
void Painting::setID(int i) {
    id = i;
}
int Painting::getID() {
    return id;
}


