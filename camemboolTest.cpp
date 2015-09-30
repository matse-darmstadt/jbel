/*
 * camemboolTest.cpp
 *
 *  Created on: 30.09.2015
 *      Author: bkra
 */

#include "camembool.h"
#include <iostream>
#include <functional>

using namespace std;
typedef unsigned char uchar;


#define CHEESE true
#define AIR false

// asserts
int testCounter = 0;
int testFailCounter = 0;

void assertTrue(bool testValue, string testName) {
	cout << testName << ":\t" << (testValue ? "TRUE" : "FALSE") << endl;
	if (!testValue) {
		testFailCounter++;
	}
	testCounter++;
}

void assertEqual(bool testValue, bool expectedValue, string testName) {
	cout << testName << ":\t" << (testValue ? "TRUE" : "FALSE") << endl;
	if (testValue != expectedValue) {
		testFailCounter++;
	}
	testCounter++;
}


void printTestSummary() {
	cout << "Number of tests: " << testCounter << "\t"
		<< "SUCCESSFUL tests: " << (testCounter - testFailCounter) << "\t"
		<< "FAILED tests: " << testFailCounter << endl;
}

class CamemboolTest {


public:

	Camembool getAllCheese(uchar size) {

		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					cube[x][y][z] = CHEESE;
				}
			}
		}
		return Camembool(cube, size);
	}

	Camembool getAllAir(uchar size) {

		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					cube[x][y][z] = AIR;
				}
			}
		}
		return Camembool(cube, size);
	}

	Camembool getCubeWithHoleInMiddle(uchar size) {
		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					if (x == size/2 && z == size/2)
						cube[x][y][z] = AIR;
					else
						cube[x][y][z] = CHEESE;
				}
			}
		}
		return Camembool(cube, size);
	}
	Camembool createCamembool(unsigned char size,
								function<bool(uchar x, uchar y, uchar z)> cheeseGenerator) {

		bool*** cube = new bool**[size];
		for (uchar z = 0; z < size; z++) {
			cube[z] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[z][y] = new bool[size];
				for (uchar x = 0; x < size; x++) {
					cube[z][y][x] = cheeseGenerator(x, y, z);
				}
			}
		}

		return Camembool(cube, size);
	}



	void testCheckBoundary() {

		Camembool c = createCamembool(5, [this](uchar x, uchar y, uchar z) {
			return true;
		});

		char segment[] = { 2, 2, 3 };
		cout << c.CheckBoundary(segment) << endl;
	}

	void testGetNeighbours() {

		Camembool c = getAllCheese(5);

		char segment[] = { 0,0,0 };
		uchar* neighbourCoords;
		uchar numberOfNeighbours;
		c.GetNeighbours(segment, neighbourCoords, numberOfNeighbours);
		assertTrue(numberOfNeighbours == 0, "Test::GetNeighbours::allCheeseCube::");

		for (uchar number = 0 ; number < numberOfNeighbours ; number++) {

		}

	}

	void testWalkPath() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testGetEntryPoint() {

		Camembool c = getAllCheese(5);
		char* result = c.GetEntryPoint();
		assertTrue(result == nullptr, "Test::GetEntryPoint::allCheeseCube::null");

		c = getCubeWithHoleInMiddle(5);
		assertTrue(c.cube[2][0][2] == AIR, "Test::GetEntryPoint::middleHoleCube::singleValidPoint");
	}

	void testCountPathSteps() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testCheckSegmentBelow() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testVerifyStep() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}


};

int main() {
	CamemboolTest test;

    auto func = [] () { cout << "Hello world" << endl; };
    func(); // now call the function

	test.testCheckBoundary();

	test.testGetNeighbours();

	test.testGetEntryPoint();

	printTestSummary();
}

