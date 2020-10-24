/*
 * Bat.h
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#ifndef BAT_H_
#define BAT_H_

#include "Mammal.h"
//class Bat derived from Mammal;
class Bat: public Mammal {
public:
	Bat(); //default constructor
	Bat(int nursing); //contructor for nursing
};

#endif /* BAT_H_ */
