/*
 * Oviparous.cpp
 *
 *  Created on: Oct 15, 2020
 *      Author: kryok
 */
using namespace std;
#include <iostream>
#include "Oviparous.h"
//default constructor
Oviparous::Oviparous() {
	sub = "";
	type = "Oviparous";
	numEggs = 0;
}
//constructor to set numEggs equal to eggs
Oviparous::Oviparous(int eggs) {
	sub = "";
	type = "Oviparous";
	numEggs = eggs;

}
//getter for type
std::string Oviparous::GetType() {
	return type;
}
//PrintInfo() function to display animal data
void Oviparous::PrintInfo() {
	cout << right << setfill('0') <<
	    setw(6) << code;
	cout << left <<setfill(' ')<<
	    setw(10)<< " "<<
	    setw(16) << name <<
	    setw(16) << type <<
	    setw(16) << sub <<
	    setw(10) << numEggs <<
	    setw(10) << "0" <<
	    std::endl;
}
//getter for numEggs
int Oviparous::GetEggs() {
	return numEggs;
}
//getter for sub
std::string Oviparous::GetSubType() {
	return sub;
}
