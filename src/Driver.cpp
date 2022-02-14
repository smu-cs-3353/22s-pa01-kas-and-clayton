//
// Created by Clayton Manchac on 1/29/22.
//

#include "Driver.h"


using namespace std::chrono;

vector<Wall> Driver::getList() {
//    return wList;
}

void Driver::sortWList() {
    //sort using one of the sort functions in DESCENDING ORDER
}
Wall Driver::getTopWall() {
//    return wList.at(0);
}
void Driver::readInputBruteForce(ifstream &bruteFile, ofstream &Brute) {
    wallWidth = 0;
    int wallHeight = 0;
    int numPaintings = 0;
    float price = 0;
    int pWidth = 0;
    int pHeight = 0;
    int pID = 0;
    smallestWidth = 1000000;

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

        if (pWidth < smallestWidth) {
            smallestWidth = pWidth;
        }
    }

        auto start = high_resolution_clock::now();
        bruteForce(Brute, numPaintings);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
        cout<<"Time that it takes for the brute force algo to get executed in seconds: "<<duration.count()<<endl;

}

void Driver::readInput(ifstream& file, ofstream &highvalue, ofstream &custom) {
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
    cout<<"number of paintings: " << numPaintings<<endl;

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

//    if (numPaintings <= 30) {
//        auto start = high_resolution_clock::now();
//        bruteForce(brute, numPaintings);
//        auto stop = high_resolution_clock::now();
//        auto duration = duration_cast<seconds>(stop - start);
//        cout<<"Time that it takes for the brute force algo to get executed: "<<duration.count()<<endl;
//    }
    auto start1 = high_resolution_clock::now();
    mostExpFirst(highvalue);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout<<"Time that it takes for the most expensive to algo get executed in milliseconds: "<<duration1.count()<<endl;

    auto start2 = high_resolution_clock::now();
    ppUnitWidth(custom);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout<<"Time that it takes for the custom algo to get executed in milliseconds: "<<duration2.count()<<endl;
}

void Driver::bruteForce(ofstream &file, int count) {
    generateSubsets(count);
    int max = 0;
    int cost = 0;
    for (int i = 0; i < wListTotal.size(); i++) {
        if (wListTotal.at(i) > wListTotal.at(max) && wListWidth.at(i) < wallWidth) {
            max = i;
            cost = wListTotal.at(i);
        }
    }

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

    wallVec.print(file);


}

void Driver::mostExpFirst(ofstream &file) {
    int availableWidth = wallWidth;
    Wall wallVec;

    //sorts in most exp to least exp order
    quicksort(pList, 0, pList.size()-1, 1);

    for (int i = 0; i < pList.size(); i++) {
        if (availableWidth == 0)
            break;
        if (pList.at(i).getWidth() > availableWidth)
            continue;
        cout<<i<<endl;
        wallVec.addPainting(pList.at(i));
        availableWidth -= pList.at(i).getWidth();
    }

    wallVec.print(file);
}

void Driver::ppUnitWidth(ofstream &file) {
    int availableWidth = wallWidth;
    Wall wallVec;

    //sorts in most exp to least exp order in terms of ppuw
    quicksort(pList, 0, pList.size()-1, 2);
    for (int i = 0; i < pList.size(); i++) {
        if (availableWidth == 0)
            break;
        if (pList.at(i).getWidth() > availableWidth)
            continue;
        cout<<i<<endl;
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
        if (algo == 1) {
            int p = partitionMEF(vec,start,end);
            quicksort(vec,start,p-1, 1);
            quicksort(vec,p+1,end, 1);
        } else if (algo == 2) {
            int p = partitionPPU(vec,start,end);
            quicksort(vec,start,p-1, 2);
            quicksort(vec,p+1,end, 2);
        }
    }
}

//referenced from https://towardsdatascience.com/a-guide-to-scraping-html-tables-with-pandas-and-beautifulsoup-7fc24c331cf7
void Driver::generateSubsets(int count) {
    vector<int> temp;
    int totalCost;
    int totalWidth;
    for (int i = 0; i < pow(2,count); i++) {
        totalCost = 0;
        totalWidth = 0;
        temp.clear();
        for (int j = 0; j < count; j++) {
            if ((i & (1 << j)) != 0) {
                temp.push_back(pList.at(j).getID());
                totalCost += pList.at(j).getPrice();
                totalWidth += pList.at(j).getWidth();
            }
        }
        wList.push_back(temp);
        wListTotal.push_back(totalCost);
        wListWidth.push_back(totalWidth);
    }
}

//void Driver::output(ofstream &file, Wall list) {
//    file << "$" << list.getTotalPrice() << endl;
//    for (int i = 0; i < list.getNumPaintings(); i++) {
//        file << list.at(i)
//    }
//    list.print(file);
//}
void Driver::read(ifstream& file, ofstream &brute, ofstream &highvalue, ofstream &custom) {
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

    if (numPaintings <= 30) {
        auto start = high_resolution_clock::now();
        bruteForce(brute, numPaintings);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
        cout<<"Time that it takes for the brute force algo to get executed: "<<duration.count()<<endl;
    }
    auto start1 = high_resolution_clock::now();
    mostExpFirst(highvalue);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout<<"Time that it takes for the most expensive to algo get executed: "<<duration1.count()<<endl;

    auto start2 = high_resolution_clock::now();
    ppUnitWidth(custom);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout<<"Time that it takes for the custom algo to get executed: "<<duration2.count()<<endl;
}
