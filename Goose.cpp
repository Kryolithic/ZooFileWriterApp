/*
 * Goose.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#include "Goose.h"
//default constuctor
Goose::Goose() {
	sub = "Goose";
}

Goose::Goose(int eggs)
	:Oviparous(eggs) {
	sub = "Goose";
}

