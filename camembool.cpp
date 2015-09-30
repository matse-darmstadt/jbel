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
	char* Camembool::GetEntryPoint(){char* segment = new char[3]; return segment;}
	int Camembool::CountPathSteps(){return 0;}
	bool Camembool::CheckSegmentBelow(char* coord){return true;}
	void Camembool::GetNeighbours(char* coord, unsigned char*& neighbourCoords, unsigned char& numberOfValidNeighbours){}
	bool Camembool::WalkPath(){return true;}
	bool Camembool::VerifyStep(char* curr, char* next){return true;}
	bool Camembool::CheckBoundary(char* coord){return true;}


