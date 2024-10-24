#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Software Status
	static const char STATUS[] =  "Beta";
	static const char STATUS_SHORT[] =  "b";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 40;
	static const long REVISION  = 238;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 238;
	#define RC_FILEVERSION 1,0,40,238
	#define RC_FILEVERSION_STRING "1, 0, 40, 238\0"
	static const char FULLVERSION_STRING [] = "1.0.40.238";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 52;

}
#endif //VERSION_H
