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
    int smallestWidth; //smallest Painting in set to fit on wall
    int wallWidth; //width of wall

    //parallel vectors to store info rather than objects -> faster algorithm
    vector<vector<int>> wList; //wall list by ID
    vector<int> wListTotal; // wall list by total cost
    vector<int> wListWidth; //wall list by width
    vector<Painting> pList; //vector of all the paintings to be potentially put on wall
public:

    //read input files for the algorithms
    void readInput(ifstream&, ofstream&, ofstream&);
    void readInputBruteForce(ifstream&, ofstream&);

    //actual algorithm declaration
    void bruteForce(ofstream&, int);
    void mostExpFirst(ofstream&);
    void ppUnitWidth(ofstream&);

    //sorting and generating subsets declarations
    int partitionMEF(vector<Painting>&, int, int);
    int partitionPPU(vector<Painting>&, int, int);
    void quicksort(vector<Painting>&, int, int, int);
    void generateSubsets(int);
};


#endif //INC_22S_PA01_KAS_AND_CLAYTON_DRIVER_H
