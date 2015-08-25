class Camembool
{
public:
	// Constructor
	// will have to make sure the sides are cheese only
	Camembool();
	// Destructor (mouse breathing air and eating cheese?)
	~Camembool();
	// the cheese cube: a 3d bool array
	// nxnxn (a cube, duh!)
	// or maybe leave dimensions optional in case of cheese slices? (i.e. 2d)
	bool cube [][][];
	// the dimension of the cube (i.e. length of the edges)
	char dimensions;
private:
	// fills the cube with cheese and air in a fixed pattern 
	cube* RipenFixedCube();
	// fills the cube with cheese and air in a random pattern
	// probably not going to be used
	cube* RipenRandomCube();
	// lets the user decide the pattern of the cheese cube
	// implementation/arguments unclear
	// probably not going to be used as well
	cube* RipenCustomCube();
	// returns an array of 3 chars which represent segments
	// we're not gonna use cubes larger than 256, are we?
	char* GetEntryPoint(cube* cheese);
	// returns the number of steps taken until
	// can be used recursively for recursiveness' sake
	int CountPathSteps(int counter);
	// bad pun on bouillon
	// initiates the search of a path through the cube
	void PourBoollon(char* coord);
	// determines what the segment below the coordinates is made off
	bool CheckPointBelow(char* coord);
	// returns the 3x3 cube around the coordinates
	cube* GetNeighbours(char* coord);
	// an array of coordinates (char[x][3]) that represents the path through the cube
	char* [] WalkPath();
	// verifies if the intended step is valid
	bool VerifyStep(char* curr, char* next);
	// takes a look at the neighbours at the coordinates to make sure we're not leaving the cube's boundaries
	bool CheckBoundary(char* coord);
};
