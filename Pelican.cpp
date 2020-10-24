/*
 * Pelican.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#include "Pelican.h"
//default constuctor
Pelican::Pelican() {
	sub = "Pelican";
}

Pelican::Pelican(int eggs)
	:Oviparous(eggs) {
	sub = "Pelican";
}

