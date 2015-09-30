/*
 * camembool.cpp
 *
 *  Created on: 30.09.2015
 *      Author: bkra
 */
#include "camembool.h"

	Camembool::Camembool(unsigned char size){}
	Camembool::Camembool(bool*** cube){}
	Camembool::~Camembool(){}

	void Camembool::RipenFixedCube(){}
	void Camembool::RipenRandomCube(){}
	void Camembool::RipenCustomCube(bool*** cube){}
	void Camembool::PourBoollon(char* coord){}
	char* Camembool::GetEntryPoint(){}
	int Camembool::CountPathSteps(){}
	bool Camembool::CheckSegmentBelow(char* coord){}
	bool* Camembool::GetNeighbours(char* coord){}
	bool Camembool::WalkPath(){}
	bool Camembool::VerifyStep(char* curr, char* next){}
	bool Camembool::CheckBoundary(char* coord){}


