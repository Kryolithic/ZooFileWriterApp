/*
 * Mammal.h
 *
 *  Created on: Oct 15, 2020
 *      Author: kryok
 */
#include "Animal.h"
#ifndef MAMMAL_H_
#define MAMMAL_H_
//declaring class mammal as derived class of Animal
class Mammal : public Animal {
	//declaring public members
	public:
		std::string sub;
		Mammal(); //default constructor
		Mammal(int nursing); //constructor for nursing variable
		std::string GetType(); //function to GetType
		std::string GetSubType(); //function to GetSubType
		int GetNurse(); //function to get nursing status
		void PrintInfo(); //PrintInfo() function
	private:
		int nurse; //private variable nursing for mammal class
};

#endif /* MAMMAL_H_ */
