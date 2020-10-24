/*
 * Oviparous.h
 *
 *  Created on: Oct 15, 2020
 *      Author: kryok
 */
#include "Animal.h"
#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_
//class Oviparous derived from Animal
class Oviparous : public Animal {
	//declaring public members
	public:
		std::string sub;
		Oviparous();
		Oviparous(int eggs);
		std::string GetType();
		std::string GetSubType();
		int GetEggs();
		void PrintInfo();\
	private:
		int numEggs; //private variable for number of eggs exclusing to Oviparous type
};

#endif /* OVIPAROUS_H_ */
