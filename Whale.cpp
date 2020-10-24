/*
 * Whale.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#include "Whale.h"
//default constuctor
Whale::Whale() {
	sub = "Whale";
}

Whale::Whale(int nursing)
	:Mammal(nursing) {
	sub = "Whale";
}

