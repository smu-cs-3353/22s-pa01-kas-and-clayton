//
// Created by Clayton Manchac on 1/29/22.
//

#ifndef INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H
#define INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H

#include <iostream>
#include <fstream>
#include <math.h>
#include "Wall.h"
#include "Painting.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <iomanip>
#include <time.h>
#include <chrono>

class Driver {
private:
    int smallestWidth;
    int wallWidth;
    vector<vector<int>> wList;
    vector<int> wListTotal;
    vector<int> wListWidth;
    vector<Painting> pList;
public:

    void readInput(ifstream&, ofstream&, ofstream&);
    void readInputBruteForce(ifstream&, ofstream&);
    void bruteForce(ofstream&, int);
    void mostExpFirst(ofstream&);
    void ppUnitWidth(ofstream&);

    int partitionMEF(vector<Painting>&, int, int);
    int partitionPPU(vector<Painting>&, int, int);
    void quicksort(vector<Painting>&, int, int, int);
    void generateSubsets(int);
};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H
