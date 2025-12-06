#include <iostream>
#include <fstream>
#include <string>

// finds largest single integer in a larger integer
// number is not modified outside the original function
int find_max_value(std::string number_str) {

	int number = std::stoi(number_str);

	int max_digit = 0; //use to store max digit when looping through number later

	// isolate each digit of number and test if its larger than the current max digit
	while (number > 0) {

		// isolate final digit in the number
		int remainder = number % 10;

		if (remainder > max_digit) {
			max_digit = remainder; // remainder is the largest digit thus far
		}

		// remove last digit from number, to begin testing the next digit
		number /= 10; // c++ only returns integers in division so will remove the number returned from the modulus

		//std::cout << number << "\n";

	}

	// print the maximum digit
	std::cout << "Max digit is " << max_digit << "\n";

	return max_digit;

}


// do we put int because its going to be an integer output?
// “this function returns an integer status code,” not “this function outputs an integer.” i.e return 0 meaning its run successfully
int main() {

	// string as this is what the input will be
	std::string test = "834921";

	// find the largest digit in the number
	int max_digit = find_max_value(test);
	std::cout << max_digit;

	// find index of first occurance of the number



	
}