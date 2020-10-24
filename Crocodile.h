/*
 * Crocodile.h
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"
//class Crocodile derived class of Oviparous
class Crocodile: public Oviparous {
public:
	Crocodile(); //default constuctor
	Crocodile(int eggs);
};

#endif /* CROCODILE_H_ */
