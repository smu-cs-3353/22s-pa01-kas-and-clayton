//
// Created by Kas Taghavi on 1/27/22.
//
#include <iostream>
#include <cstring>
#include "Driver.h"
//using namespace std;

int main(int argc, char** argv){

    if(argc == 1) {
        std::cout << "Enter Query: " << endl;
    } else {
        ifstream input(argv[1]);
        ofstream brute("output/test-bruteforce.txt");
        ofstream highvalue("output/test-highvalue.txt");
        ofstream custom("output/test-custom.txt");

        Driver d;

        d.readInput(input, brute, highvalue, custom);
    }
}