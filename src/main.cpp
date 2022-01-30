//
// Created by Kas Taghavi on 1/27/22.
//
#include <iostream>
#include <cstring>
#include "Driver.h"
using namespace std;

int main(int argc, char** argv){
    std::cout << "Enter Query: " << endl;

    ifstream input(argv[1]);
    ofstream brute("test-bruteforce.txt");
    ofstream highvalue("test-highvalue.txt");
    ofstream custom("test-custom.txt");

    Driver drive;

    drive.readInput(input, brute, highvalue, custom);
}