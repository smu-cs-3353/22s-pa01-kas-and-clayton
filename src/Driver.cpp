//
// Created by Clayton Manchac on 1/29/22.
//

#include "Driver.h"

vector<Wall> Driver::getList() {
    return wList;
}
void Driver::sortWList() {
    //sort using one of the sort functions in DESCENDING ORDER
}
Wall Driver::getTopWall() {
    return wList.at(0);
}
void Driver::readInput(ifstream& file, ofstream &brute, ofstream &highvalue, ofstream &custom) {
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

        if (pWidth < smallestWidth) {
            smallestWidth = pWidth;
        }
    }

    if (numPaintings <= 5) {
        bruteForce(brute);
    }

    mostExpFirst(highvalue);
    ppUnitWidth(custom);
}

void Driver::bruteForce(ofstream &file) {

}

void Driver::mostExpFirst(ofstream &file) {
    sortPList(2); //sorts in most exp to least exp order

    int availableWidth = wallWidth;
    Wall wallVec;

    quicksort(pList, 0, pList.size()-1, 1);

    for (int i = 0; i < pList.size(); i++) {
        if (pList.at(i).getWidth() > availableWidth)
            continue;
        wallVec.addPainting(pList.at(i));
        availableWidth -= pList.at(i).getWidth();
    }

    wallVec.print(file);
}

void Driver::ppUnitWidth(ofstream &file) {
    sortPList(3); //sorts in most exp to least exp order in terms of ppuw

    int availableWidth = wallWidth;
    Wall wallVec;

    quicksort(pList, 0, pList.size()-1, 2);

    for (int i = 0; i < pList.size(); i++) {
        if (pList.at(i).getWidth() > availableWidth)
            continue;
        wallVec.addPainting(pList.at(i));
        availableWidth -= pList.at(i).getWidth();
    }

    wallVec.print(file);
}

//taken from https://slaystudy.com/c-vector-quicksort/
int Driver::partitionMEF(vector<Painting> &vec, int start, int end) {
    int pivot = end;
    int j = start;
    for(int i=start;i<end;++i){
        if(vec[i].getPrice() > vec[pivot].getPrice()){
            swap(vec[i],vec[j]);
            ++j;
        }
    }
    swap(vec[j],vec[pivot]);
    return j;
}

//referenced from above
int Driver::partitionPPU(vector<Painting> &vec, int start, int end) {
    int pivot = end;
    int j = start;
    for(int i=start;i<end;++i){
        if(vec[i].getPPUW() > vec[pivot].getPPUW()){
            swap(vec[i],vec[j]);
            ++j;
        }
    }
    swap(vec[j],vec[pivot]);
    return j;
}

void Driver::quicksort(vector<Painting> &vec, int start, int end, int algo) {
    if(start < end){
        if (algo = 1) {
            int p = partitionMEF(vec,start,end);
            quicksort(vec,start,p-1, 1);
            quicksort(vec,p+1,end, 1);
        } else if (algo = 2) {
            int p = partitionPPU(vec,start,end);
            quicksort(vec,start,p-1, 2);
            quicksort(vec,p+1,end, 2);
        }
    }
}

//void Driver::output(ofstream &file, Wall list) {
//    file << "$" << list.getTotalPrice() << endl;
//    for (int i = 0; i < list.getNumPaintings(); i++) {
//        file << list.at(i)
//    }
//    list.print(file);
//}
