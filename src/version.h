#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 29;
	static const long REVISION  = 164;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 45;
	#define RC_FILEVERSION 1,0,29,164
	#define RC_FILEVERSION_STRING "1, 0, 29, 164\0"
	static const char FULLVERSION_STRING [] = "1.0.29.164";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 35;
	

}
#endif //VERSION_H
