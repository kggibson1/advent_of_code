#include <fstream>
#include <iostream> // for cout

// function that is run when script built and ran, int tells us about the integer type return? (!!! Check this)
bool main() {

	// testing logic for determining if test value is between range down - up.
	long long test = 238330044306852;

	long long down = 236582027246318;
	long long up = 238330044306851;

	// check test is within range
	if (test > down) {

		//std::cout << upper_diff << std::endl;

		if (test < up) {

			//return true;

			std::cout << "True";
		}

		else { std::cout << "False"; }
	}

	else { std::cout << "False"; }

	return 0; // exit code, 0 says it ran fine

}