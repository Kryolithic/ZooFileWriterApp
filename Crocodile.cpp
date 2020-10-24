/*
 * Crocodile.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#include "Crocodile.h"
//default constructor
Crocodile::Crocodile() {
	sub = "Crocodile";
}

Crocodile::Crocodile(int eggs)
	:Oviparous(eggs) { //inheriting Oviparous constructor
	sub = "Crocodile";
}

