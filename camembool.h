class camembool
{
public:
	// Constructor
	// will have to make sure the sides are cheese only
	camembool();
	// Destructor
	~camembool();
	// the cheese cube: a 3d bool array
	// nxnxn (a cube, duh!)
	bool cube [][][];
private:
	// returns an array of 3 chars which represent coordinates
	// we're not gonna use cubes larger than 256, are we?
	char* GetEntryPoint();
};
