//
// Created by Kas Taghavi on 1/27/22.
//
#include <iostream>
#include <cstring>
#include "Driver.h"
//using namespace std;

int main(int argc, char** argv){

    if(argc == 1) {
        std::cout << "no input " << endl;
    } else {

        ifstream input(argv[1]);
        ifstream test(argv[1]);

        string str = argv[1];
        int pos = str.find('.');
        int pos2 = str.find_last_of('/');
        string sub = str.substr(pos2+1, pos - 6);

        ofstream brute(sub+"-bruteforce.txt");
        ofstream highvalue(sub+"-highvalue.txt");
        ofstream custom(sub+"-custom.txt");

        Driver d;
        d.readInputBruteForce(input, brute);
        d.readInput(test, highvalue, custom);

        brute.close();
        highvalue.close();
        custom.close();
    }
}