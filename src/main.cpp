//
// Created by Kas Taghavi on 1/27/22.
//
#include <iostream>
#include <cstring>
#include "Driver.h"
//using namespace std;

int main(int argc, char** argv){

    //check to make sure program has arguments
    if(argc == 1) {
        std::cout << "Please provide an input file." << endl;
    } else { //program has arguments. open input and output txt files
        ifstream inputBrute(argv[1]);
        ifstream input(argv[1]);

        string str = argv[1];
        int pos = str.find('.');
        int pos2 = str.find_last_of('/');
        string sub = str.substr(pos2+1, pos - 6);

        ofstream brute(sub + "-bruteforce.txt");
        ofstream highvalue(sub + "-highvalue.txt");
        ofstream custom(sub + "-custom.txt");

        //create driver object and call algorithms to read input
        Driver d;
        d.readInputBruteForce(inputBrute, brute);
        d.readInput(input, highvalue, custom);

        //close all files
        brute.close();
        highvalue.close();
        custom.close();
    }
}