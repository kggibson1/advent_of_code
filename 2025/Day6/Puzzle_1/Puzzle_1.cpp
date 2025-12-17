#include <iostream>
#include <fstream> //for reading in files
#include <string>
#include <vector>
#include <cctype> 

/* Check if a string contains any digit 

const is read only, s is passed by reference (Efficient and idiomatic C++), not copied (which is expensive)

unsigned
--------

unsigned char can store values from 0 to 255

signed char typically stores -128 to 127

char may be either signed or unsigned (implementation-defined)
unsigned prevents undefined behaviour

*/
bool contains_digit(const std::string& s) {

	for (unsigned char ch : s)
		if (std::isdigit(ch)) return true;
	return false;
}

std::vector<long long> separate_string_int(const std::string& s) {

	std::vector<long long> integers; // vector to store separated integers

	std::string current; // allow string addition of characters

	for (int j = 0; j < s.size(); j++) {

		// check if character is a digit
		if (!std::isdigit(static_cast<unsigned char>(s[j]))) {

			if (!current.empty()) {

			integers.push_back(std::stoll(current));
			
			} // convert current to integer, push to integers vector

			// clear current
			current = "";
		}

		else {
			current += s[j]; // string addition 
		}

		//std::cout << integers[0] << std::endl;

		//return integers;

	}

	// push last number
	if (!current.empty()) { 
		integers.push_back(std::stoi(current));
	}

	//std::cout << integers[0] << std::endl;

	return integers;
}

/*
TO COMMENT
*/
std::vector<char> separate_string_char(const std::string& s) {
	std::vector<char> ops;

	for (char ch : s) {
		if (!std::isspace(static_cast<unsigned char>(ch))) {
			ops.push_back(ch);
		}
	}

	return ops;
}

int main() {

	std::string filename = "input.txt";
	std::ifstream file; // create ifstream item, allows file to be connected from the stream
	file.open(filename);

	// check file opened 
	if (file.fail()) {

		std::cout << "Could not read file" << std::endl;

		return 1; // lets OS know that program didnt run correctly
	}

	std::string line;

	std::vector<std::vector<long long>> numbers;
	std::vector<char> operators;

	// track if we have reached final line of file (where the operators lie)
	//bool at_operators = false;

	while (getline(file, line)) {

		// check if line is digits or the operators line
		if (contains_digit(line)) {

			numbers.push_back(separate_string_int(line));
		}

		// this wouldnt usually be the safest way to do this but given the input file this should be fine
		else { operators = separate_string_char(line); }
		
	}

	//std::cout << numbers[0][0] << std::endl;

	// store each columns arithmatic sum
	std::vector<long long> solutions;

	// numbers dimensions
	int column_size = numbers.size();
	int row_size = numbers[0].size();

	std::cout << column_size << " " << row_size << std::endl;

	std::cout << operators.size() << std::endl;

	// loop over operators 
	for (int i = 0; i < operators.size(); i++) {
	
		char column_operator = operators[i];

		long long solution = numbers[0][i];

		std::cout << column_operator << " " << solution << std::endl;
		 

		// loop over input file columns, doing each operator individually
		for (int k = 1; k < column_size; k++) {
		
			if (column_operator == '+') {
			
				solution += numbers[k][i];

			}

			if (column_operator == '*') {

				solution *= numbers[k][i];

			}
		
		}

		solutions.push_back(solution);
	}

	long long sum = 0;

	for (int x = 0; x < solutions.size(); x++) {
	
		sum += solutions[x];
	}

	std::cout << sum << std::endl;

	// should loop 4 times, each time adding (or the desired maths operation) the next number in solution
	//for (int i = 1; i < numbers.size(); i++) {
		
		
		
	//}

}