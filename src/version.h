#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 24;
	static const long REVISION  = 118;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 33;
	#define RC_FILEVERSION 1,0,24,118
	#define RC_FILEVERSION_STRING "1, 0, 24, 118\0"
	static const char FULLVERSION_STRING [] = "1.0.24.118";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 24;
	

}
#endif //VERSION_H
