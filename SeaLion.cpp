/*
 * SeaLion.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: kryok
 */

#include "SeaLion.h"
//default constuctor
SeaLion::SeaLion() {
	sub = "SeaLion";
}

SeaLion::SeaLion(int nursing)
	:Mammal(nursing) {
	sub = "SeaLion";
}
