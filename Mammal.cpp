/*
 * Mammal.cpp
 *
 *  Created on: Oct 15, 2020
 *      Author: kryok
 */
#include <vector>
#include <iostream>
#include "Animal.h"
#include "Mammal.h"

using namespace std;
//default constructor
Mammal::Mammal() {
	sub = "";
	type = "Mammal";
	nurse = 0;
}
//constructor to set nurse value to nursing
Mammal::Mammal(int nursing) {
	sub = "";
	type = "Mammal";
	nurse = nursing;
}
//getter for type
std::string Mammal::GetType() {
	return type;
}
//getter for sub
std::string Mammal::GetSubType() {
	return sub;
}
//PrintInfo() function to display animal data
void Mammal::PrintInfo() {
	cout << right << setfill('0') <<
	    setw(6) << code;
	cout << left << setfill(' ') <<
	    setw(10) << " " <<
	    setw(16) << name <<
	    setw(16) << type <<
	    setw(16) << sub <<
	    setw(10) << "0" <<
	    setw(10) << nurse <<
	       std::endl;
}
//getter for nurse
int Mammal::GetNurse() {
	return nurse;
}
