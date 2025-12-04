#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric> // for std::iota
#include <vector> // to include vectors

// checks if a number is made of a number repeated twice, e.g 1212 is a repetition of 12 or 12341234 is a repetition of 1234
bool check_repetition_twice(const std::string& s) {
	
	// get size of string
	int n = s.size();

	// check if length of string is even
	if (n % 2 != 0) {

		return false;
	}

	// get half of string length
	int half = n / 2;

	// compare first half and second half of string
	return s.substr(0, half) == s.substr(half, half); // returns true if the halves match, false is they dont
}


int main() {

	// define file variable and file name
	std::string filename;
	filename = "input1.txt";

	// open file with fstream
	std::ifstream file;
	file.open(filename);

	std::string line;
	std::getline(file, line);   // read the entire line

	//std::cout << line;

	// split line by , delimeter
	std::string range; // temp variable to store split string range

	// !! need to understand this more
	std::stringstream ss(line); // create stringstream object to create a stream to the line of ranges

	char delimeter = ','; // delimeter in input1.txt

	long long invalid_ID_total = 0; // will use to track running total of invalid ID's, use long long as some of the invalid ID's are much larger than the 32bit that an int can hold

	// split into the ranges
	while (getline(ss, range, delimeter)) {

		//std::cout << range << std::endl; // dont need \n as endl already provides a new line

		// split range into max and min values
		//int l_lim, u_lim; // variables to store the upper and lower limits of the ID tag range
		long long l_lim, u_lim; // was getting some parsing errors as some of the range values didnt fit into a 32 bit int, so need to use long long variable type to allow those numbers to be stored

		char dash; // temp variable used when separating range string

		// use string stream to seperate range string into variables
		std::stringstream ss_range(range); // Putting into a stringstream object so that the string can be input as if it were a command prompt input 
		// range is now in the stream and can be read as such

		// assign variables and check they are being type assigned correctly, check delimeter was dash (not necessary but done for learning purposes)
		if (!(ss_range >> l_lim >> dash >> u_lim) || dash != '-') {
			std::cerr << "Invalid range: \"" << range << "\"\n"; // print error if variables not assigned correctly
			continue;
		}

		// remove this line to avoid double parsing now that check for variable assignment was added above
		// read string from stream (ss) and assign variables as such
		//ss_range >> l_lim >> dash >> u_lim; // l_lim is defined as in integer thus >> parses ss until it find a character that isnt an integer. Then keeps parsing until it no longer find a char for the dash variable, then moves back to an integer for u_lim due to its in definition.

		// confirm correct values are being assigned to range edges
		// std::cout << l_lim << "\n" << u_lim << std::endl;

		// create array of integers within each range, including edge numbers
		//std::vector<int> numbers(u_lim - l_lim + 1); // +1 to ensure vector size big enough to include range limits
		std::vector<long long> numbers(u_lim - l_lim + 1); // probably best to just loop over the numbers next time instead of using a vector, way more memory efficient

		// create sequence starting at l_lim, add +1 to l_lim until numbers is full (end number should be u_lim)
		std::iota(numbers.begin(), numbers.end(), l_lim); // should work but need to parse the max and min ranges from the ranges

		// c++ doesnt have overload (alt function) for << for printing vectors, cant convert numbers into something printable, can only print single values from the vector or will need to loop over to print the whole thing
		//std::cout << numbers[0] << ", " << numbers[-1] << std::endl;

		// print vector
		//for (int n : numbers) {
		//	std::cout << n << " ";
		//}
		//std::cout << std::endl;

		// loop over numbers and determine if 

		for (long long n : numbers) {

			// convert value to string and get length
			std::string str = std::to_string(n); // convert int to string
			
			bool repetition = check_repetition_twice(str);

			if (repetition == true) {
			
				invalid_ID_total += n;
			}
			
		}

	}

	// print total invalid ID
	std::cout << invalid_ID_total;



}