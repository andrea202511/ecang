#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 31;
	static const long REVISION  = 145;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 37;
	#define RC_FILEVERSION 1,0,31,145
	#define RC_FILEVERSION_STRING "1, 0, 31, 145\0"
	static const char FULLVERSION_STRING [] = "1.0.31.145";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 31;
	

}
#endif //VERSION_H
