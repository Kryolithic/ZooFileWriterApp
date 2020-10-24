/*
 * Bat.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#include "Bat.h"

Bat::Bat() {
	sub = "Bat"; //setting sub to Bat for sub type
}

Bat::Bat(int nursing)
	:Mammal(nursing) { //inheriting constructor from Mammal
	sub = "Bat";
}

