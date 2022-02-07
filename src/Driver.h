//
// Created by Clayton Manchac on 1/29/22.
//

#ifndef INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H
#define INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H

#include <iostream>
#include <fstream>
#include "Wall.h"
#include "Painting.h"

class Driver {
private:
    int count;
    int smallestWidth;
    int wallWidth;
    vector<Wall> wList;
    vector<Painting> pList;
public:
    vector<Wall> getList();
    void sortPList(int); // int decides how to sort -> in descending order but based on what? 1 = brute force,
                         // 2 = mostExpFirst (based on price), 3 = ppUnitWidth (based on ppuw)
    void sortWList(); //sort by most expensive walls
    Wall getTopWall();

    void readInput(ifstream&, ofstream&, ofstream&, ofstream&);
    void bruteForce(ofstream&);
    void mostExpFirst(ofstream&);
    void ppUnitWidth(ofstream&);

    int partitionMEF(vector<Painting>&, int, int);
    int partitionPPU(vector<Painting>&, int, int);
    void quicksort(vector<Painting>&, int, int, int);
};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H