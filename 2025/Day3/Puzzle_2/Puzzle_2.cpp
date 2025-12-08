#include <iostream>
#include <fstream>
#include <string>

// allows return of a string
// find the largest joltage_length size integer within a test string, assuming that test.size() > joltage_length. WITHOUT rearranging the order of test
std::string find_joltage(std::string test, int joltage_length) {

	// 1st line in input file
	//std::string test = "2412122322321222252222221622332222221521261431723112634211232223232132154222214222211332229222231222";
	int no_digits = test.size();

	//std::cout << no_digits;

	// no_digits to make up the joltage value
	//int joltage_length = 12;

	// size_t is a variable type representing sizes of objects, lengths of containers, and array indexes (unassigned variable type).
	// loop over the whole number, from the beginning to 12 digits away from the end, search for largest number in this range
	//std::string substring = test.substr(0, no_digits - joltage_length); // isolate possible starting numbers for joltage

	// find largest number in starting positions

	//std::cout << substring << " " << substring.size() << std::endl;
	std::string joltage = "";
	int first_digit = 0; // index of digit to start iterations from
	// size_t is a variable type representing sizes of objects, lengths of containers, and array indexes (unassigned variable type).
	for (size_t i = 0; i < joltage_length; ++i) {

		// how many digits still to find
		int remaining = joltage_length - joltage.size() - 1; // -1 to account for indexing starting at 0

		// largest value found
		char largest = '0';
		int best_index = first_digit;

		// find largest digit where there is enough room after the chosen digit to choose the rest
		for (int j = first_digit; j < no_digits - remaining; j++) {

			// convert from acsii to int
			//int current_digit = test[j] - '0';

			if (test[j] > largest) {

				largest = test[j];
				best_index = j; // so that next search references from here
			}

		}

		// add best number to current solution
		joltage += largest; // char addition is 1+1 = 11
		//std::cout << joltage << '\n';
		first_digit = best_index + 1;

	}

	return joltage;
}


int main() {

	//std::string test = "2412122322321222252222221622332222221521261431723112634211232223232132154222214222211332229222231222";
	//int k = 12;

	//std::cout << find_joltage(test, k);

	// read in file
	std::ifstream file("input.txt");
	std::string line;

	long long total_joltage = 0;
	int joltage_length = 12;

	// find max joltage of each line seperately
	while (getline(file, line)) {
		
		// get string total joltage and covert to long long for correct addition
		total_joltage += stoll(find_joltage(line, joltage_length));

	}

	std::cout << "Total Joltage is " << total_joltage; //168027167146027



}
