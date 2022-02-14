//
// Created by Clayton Manchac on 1/29/22.
//

#include "Driver.h"

using namespace std::chrono;

//bruteforce read in algorithm - limit to only 25 paintings because it takes too long
void Driver::readInputBruteForce(ifstream &bruteFile, ofstream &Brute) {
    wallWidth = 0;
    int wallHeight = 0;
    int numPaintings = 0;
    float price = 0;
    int pWidth = 0;
    int pHeight = 0;
    int pID = 0;
    smallestWidth = 1000000;

    //read in variables from input files and create painting objects
    bruteFile >> wallWidth;
    bruteFile >> wallHeight;
    bruteFile >> numPaintings;
    if (numPaintings > 25){
        numPaintings = 25;
    }

    for (int i = 0; i < numPaintings; i++) {
        bruteFile >> pID;
        bruteFile >> price;
        bruteFile >> pWidth;
        bruteFile >> pHeight;

        Painting artwork(pHeight, pWidth, price, pID);
        pList.push_back(artwork);

        //set smallest painting width
        if (pWidth < smallestWidth) {
            smallestWidth = pWidth;
        }
    }

        //start clock and call algorithm to time it
        auto start = high_resolution_clock::now();
        bruteForce(Brute, numPaintings);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
        cout<<"Time that it takes for the brute force algo to get executed in seconds: "<<duration.count()<<endl;

}

//read input file for other algorithms as they are much faster than bruteforce
void Driver::readInput(ifstream& file, ofstream &highvalue, ofstream &custom) {
    wallWidth = 0;
    int wallHeight = 0;
    int numPaintings = 0;
    float price = 0;
    int pWidth = 0;
    int pHeight = 0;
    int pID = 0;
    smallestWidth = 1000000;

    //read in variables from input files and create painting objects
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

    //start clock and call most expensive first algorithm to time it
    auto start1 = high_resolution_clock::now();
    mostExpFirst(highvalue);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout<<"Time that it takes for the most expensive to algo get executed in milliseconds: "<<duration1.count()<<endl;

    //start clock and call custom algorithm to time it
    auto start2 = high_resolution_clock::now();
    ppUnitWidth(custom);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout<<"Time that it takes for the custom algo to get executed in milliseconds: "<<duration2.count()<<endl;
}

//actual bruteforce algorithm that generates all subsets of n paintings (2^n)
void Driver::bruteForce(ofstream &file, int count) {
    generateSubsets(count);
    int max = 0;
    int cost = 0;

    //order all subsets (list of walls) in order from most expensive to least
    for (int i = 0; i < wListTotal.size(); i++) {
        if (wListTotal.at(i) > wListTotal.at(max) && wListWidth.at(i) < wallWidth) {
            max = i;
            cost = wListTotal.at(i);
        }
    }

//    search through the list of paintings and find the paintings that belong on the most
//    expensive wall. add them to a wall object to then be printed
    Painting tempPaint;
    Wall wallVec(wallWidth);
    for (int i = 0; i < wList.at(max).size(); i++) {
        for (int j = 0; j < pList.size(); j++) {
            if (pList.at(j).getID() == wList.at(max).at(i)) {
                tempPaint = pList.at(j);
                wallVec.addPainting(tempPaint);
            }
        }
    }

//    print the wall
    wallVec.print(file);
}

//most expensive first algorithm. sort paintings by value and put on wall in that order
void Driver::mostExpFirst(ofstream &file) {
    int availableWidth = wallWidth;
    Wall wallVec;

    //sorts in most expensive to least expensive order
    quicksort(pList, 0, pList.size()-1, 1);

    //loop through the sorted list. if there is room on the wall for the painting, add it
    for (int i = 0; i < pList.size(); i++) {
        if (availableWidth == 0) //if remaining width == zero, no more room on wall and break
            break;
        if (pList.at(i).getWidth() > availableWidth)
            continue;

        //add the paintings to the wall and decrease remaining width
        wallVec.addPainting(pList.at(i));
        availableWidth -= pList.at(i).getWidth();
    }

    //print out the wall to the highvalue output txt file
    wallVec.print(file);
}

// custom algorithm. sort in order of price per unit width variable as it captures value per
// unit of space taken up
void Driver::ppUnitWidth(ofstream &file) {
    int availableWidth = wallWidth;
    Wall wallVec;

    //sorts in most exp to least exp order in terms of ppuw
    quicksort(pList, 0, pList.size()-1, 2);
    for (int i = 0; i < pList.size(); i++) {
        if (availableWidth == 0) //if remianing width is 0, wall is full so break
            break;
        if (pList.at(i).getWidth() > availableWidth)
            continue;

        //add the paintings to the wall and decrease remaining width
        wallVec.addPainting(pList.at(i));
        availableWidth -= pList.at(i).getWidth();
    }

    //print out the wall to the custom output txt file
    wallVec.print(file);
}

//partition function for the most expensive first algorithm. sort by price
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

//partition function for the custom (price per unit width) algorithm. sort by ppuw
//referenced from https://slaystudy.com/c-vector-quicksort/
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

//actual quicksort algo that sorts the vectors by either price of ppuw
//quick sort algorithm referenced from https://slaystudy.com/c-vector-quicksort/
void Driver::quicksort(vector<Painting> &vec, int start, int end, int algo) {
    if (start < end){
        if (algo == 1) { //ranking by Most expensive first
            int p = partitionMEF(vec,start,end);
            quicksort(vec,start,p-1, 1);
            quicksort(vec,p+1,end, 1);
        } else if (algo == 2) { //else if ranking by price per unit width
            int p = partitionPPU(vec,start,end);
            quicksort(vec,start,p-1, 2);
            quicksort(vec,p+1,end, 2);
        }
    }
}

//generate all possible subsets for n paintings -> 2^n subsets - increases exponentially
//referenced from https://towardsdatascience.com/a-guide-to-scraping-html-tables-with-pandas-and-beautifulsoup-7fc24c331cf7
void Driver::generateSubsets(int count) {
    vector<int> temp;
    int totalCost;
    int totalWidth;
    for (int i = 0; i < pow(2,count); i++) {
        totalCost = 0;
        totalWidth = 0;
        //clear temp vector
        temp.clear();

        //binary swapping
        for (int j = 0; j < count; j++) {
            if ((i & (1 << j)) != 0) {
                //creating a subset of the set by adding paintings and calculating cost and width
                temp.push_back(pList.at(j).getID());
                totalCost += pList.at(j).getPrice();
                totalWidth += pList.at(j).getWidth();
            }
        }
        //parallel vectors to store info rather than objects -> faster algorithm
        wList.push_back(temp);
        wListTotal.push_back(totalCost);
        wListWidth.push_back(totalWidth);
    }
}

