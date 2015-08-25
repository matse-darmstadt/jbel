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
	bool cube[][][];
private:
	// returns an array of 3 chars which represent coordinates
	// we're not gonna use cubes larger than 256, are we?
	char* GetEntryPoint(cube* cheese);
	// returns the number of steps taken until
	int CountPathSteps(int counter);
	// bad pun on bouillon
	void PourBoollon(char* entrypoint);
	
	
};
