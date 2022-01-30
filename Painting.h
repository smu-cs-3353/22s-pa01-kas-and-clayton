//
// Created by Clayton Manchac on 1/29/22.
//

#ifndef INC_22S_PA01_KAS_AND_CLAYTON_PAINTING_H
#define INC_22S_PA01_KAS_AND_CLAYTON_PAINTING_H

class Painting {
private:
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

    //constructor
    Painting();
    Painting(int, int, float, int);
    ~Painting();

    //anything else

};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_PAINTING_H
