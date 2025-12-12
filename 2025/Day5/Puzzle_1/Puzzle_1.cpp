#include <fstream> //reading files
#include <iostream> // for cout
#include <string> //getline


// function that is run when script built and ran, int tells us about the integer type return? (!!! Check this)
int main() {

	// read in input file
	std::string filename = "input.txt";
	std::ifstream file; // create ifstream item, allows file to be connected from the stream
	file.open(filename);

	// check file opened 
	if (file.fail()) {
	
		std::cout << "Could not read file" << std::endl;

		return 1; // lets OS know that program didnt run correctly
	}

	// store single range at a time as read in from the input file
	std::string range;

	// read in ranges
	while (std::getline(file, range)) {

		std::cout << range << std::endl;
		
		// check to see if blank line present (end of ranges)
		if (!range.size()) {
		
			break;
		}
	
	}




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