#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Software Status
	static const char STATUS[] =  "Beta";
	static const char STATUS_SHORT[] =  "b";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 39;
	static const long REVISION  = 184;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 210;
	#define RC_FILEVERSION 1,0,39,184
	#define RC_FILEVERSION_STRING "1, 0, 39, 184\0"
	static const char FULLVERSION_STRING [] = "1.0.39.184";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 52;

}
#endif //VERSION_H
