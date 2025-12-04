#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric> // for std::iota
#include <vector> // to include vectors

// checks input string to see if its made of repeating pattern of numbers.
// const means string cannot be edited within function
// std::string is defining the type of s, this must be done
// & provides a reference to s for the function instead of copying the string, which is ideal for when you have larger strings.

// turns out I got the logic wrong on this one, only looking for numbers where the first half = second half, will write another function for this
// at least it was a good learning exercise XD
bool check_repetition(const std::string& s) {

	// get string size
	int n = s.size();

	// loop over substrings of the ID number, up to half the length of the full string,
	// otherwise it can't be a repeating pattern
	// n/2 returns an int, instead of float, ++len means +1 to len after each loop iteration
	for (int len = 1; len <= n / 2; ++len) {

		// check if substring can evenly divide the string
		// if FALSE, substring cannot be the repeating pattern if one exists
		if (n % len == 0) {

			// define substring to be checked for repetition in s
			std::string pattern = s.substr(0, len);

			// boolean which will be switched to false if pattern is not found to be a repetitive pattern
			bool match = true;

			// check for substring match in all repeated blocks
			// starting from n[0] to n[len], then n[len+1] to n[len+len] and so on,
			// check if these chunks of n match the pattern
			for (int i = 0; i < n; i += len) {

				// if chunk of n doesn't match the pattern, the substring being checked
				// is not a repeated pattern, move onto next substring
				if (s.substr(i, len) != pattern) {
					match = false;
					break; // leave loop, move onto next substring
				}

			} // end inner for loop

			// if match remains true, the string consists of a repeating pattern
			// function returns true (hence bool type)
			if (match) {
				return true;
			}

		} // end if(n % len == 0)

	} // end outer for loop

	// if no repeating pattern found return false
	return false;
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

			bool repetition = check_repetition(str);

			if (repetition == true) {

				invalid_ID_total += n;
			}

		}

	}

	// print total invalid ID
	std::cout << invalid_ID_total; // 11323661261



}