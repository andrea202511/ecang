#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 34;
	static const long REVISION  = 219;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 67;
	#define RC_FILEVERSION 1,0,34,219
	#define RC_FILEVERSION_STRING "1, 0, 34, 219\0"
	static const char FULLVERSION_STRING [] = "1.0.34.219";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 45;

}
#endif //VERSION_H
