/*
 * camembool.cpp
 *
 *  Created on: 30.09.2015
 *      Author: bkra
 */
#include "camembool.h"

Camembool::Camembool(unsigned char size): cube(nullptr), size(size), path(nullptr) {
}
Camembool::Camembool(bool*** cube, unsigned char size): cube(cube), size(size), path(nullptr) {
}
Camembool::~Camembool() {
}

void Camembool::RipenFixedCube() {
}
void Camembool::RipenRandomCube() {
}
void Camembool::RipenCustomCube(bool*** cube) {
}
void Camembool::PourBoollon(char* coord) {
}


unsigned char* Camembool::GetEntryPoint() {

	unsigned char x, z;
	x = 0;
	z = 0;
	while (x != size || z != size)
	{
		if (cube[x++][0][z++] == false)
		{
			unsigned char* segment = new unsigned char[3];
			segment[0] = x;
			segment[1] = 0;
			segment[2] = z;
			return segment;
		}
	}
	return nullptr;
}


unsigned int Camembool::CountPathSteps() {
	return 0;
}
bool Camembool::CheckSegmentBelow(unsigned char* coord) {
	return true;
}
void Camembool::GetNeighbours(unsigned char* coord, unsigned char*& neighbourCoords,
		unsigned char& numberOfValidNeighbours) {
}
bool Camembool::WalkPath() {
	return true;
}
bool Camembool::VerifyStep(unsigned char* curr, unsigned char* next) {
	return true;
}
bool Camembool::CheckBoundary(unsigned char* coord) {
	return true;
}

