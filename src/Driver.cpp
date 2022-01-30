//
// Created by Clayton Manchac on 1/29/22.
//

#include "Driver.h"

vector<WalL> Driver::getList() {
    return wList;
}
void Driver::sortList() {
    //sort using one of the sort functions in DESCENDING ORDER
}
Wall Driver::getTopWall() {
    return wList.at(0);
}
void readInput(ifstream& file) {
    wallWidth = 0;
    int wallHeight = 0;
    int numPaintings = 0;
    float price = 0;
    int pWidth = 0;
    int pHeight = 0;
    int pID = 0;
    smallestWidth = 1000000;

    file >> wallWidth;
    file >> wallHeight;
    file >> numPaintings;

    for (int i = 0; i < numPaintings; i++) {
        file >> pID;
        file >> price;
        file >> pWidth;
        file >> pHeight;

        Painting artwork(pHeight, pWidth, price, pID);
        pList.push_back(artwork);

        if (width < smallestWidth) {
            smallestWidth = width;
        }
    }
}

void Driver::bruteForce() {

}

vector<Painting> Driver::mostExpFirst() {
    sortPList(2); //sorts in most exp to least exp order

    int availableWidth = wallWidth;
    Wall wallVec;

    for (int i = 0; i < pList.size(); i++) {
        if (pList.at(i).width > availableWidth)
            continue;
        wallVec.push_back(pList.at(i))
        availableWidth -= pList.at(i).getWidth();
    }

    wallvec.print(file);
}

vector<Painting> Driver::ppUnitWidth(ofstream &file) {
    sortPList(3); //sorts in most exp to least exp order in terms of ppuw

    int availableWidth = wallWidth;
    Wall wallVec;

    for (int i = 0; i < pList.size(); i++) {
        if (pList.at(i).width > availableWidth)
            continue;
        wallVec.addPainting(pList.at(i))
        availableWidth -= pList.at(i).getWidth();
    }

    wallvec.print(file);
}

//void Driver::output(ofstream &file, Wall list) {
//    file << "$" << list.getTotalPrice() << endl;
//    for (int i = 0; i < list.getNumPaintings(); i++) {
//        file << list.at(i)
//    }
//    list.print(file);
//}

