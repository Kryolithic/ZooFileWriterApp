/*
 * Animal.h
 *
 *  Created on: Oct 15, 2020
 *      Author: kryok
 */
#include <string>
#include <iostream>
#include <iomanip>
#ifndef ANIMAL_H_
#define ANIMAL_H_
//declaring class Animal
class Animal {
	//public variables for code, name, type
	public:
		std::string name;
		int code;
		std::string type;
		Animal() {};

		virtual std::string getSubType() { return ""; }; //virtual function getSubType ()

		virtual void PrintInfo() {}; //virtual function PrintInfo()
};

#endif /* ANIMAL_H_ */
