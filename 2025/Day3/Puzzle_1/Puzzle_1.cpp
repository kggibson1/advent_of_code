#include <iostream>
#include <fstream>
#include <string>

// finds largest single integer in a larger integer
// number is not modified outside the original function
int find_max_value(std::string number_str) {

	long long number = std::stoi(number_str);

	int max_digit = 0; //use to store max digit when looping through number later

	// isolate each digit of number and test if its larger than the current max digit
	while (number > 0) {

		// isolate final digit in the number
		long long remainder = number % 10;

		if (remainder > max_digit) {
			max_digit = remainder; // remainder is the largest digit thus far
		}

		// remove last digit from number, to begin testing the next digit
		number /= 10; // c++ only returns integers in division so will remove the number returned from the modulus

		//std::cout << number << "\n";

	}

	// print the maximum digit
	std::cout << "Max digit is " << max_digit << "\n";

	// convert to string 
	//std::string max_digit_str = std::to_string(max_digit);

	return max_digit;

}


// do we put int because its going to be an integer output?
// “this function returns an integer status code,” not “this function outputs an integer.” i.e return 0 meaning its run successfully
int main() {

	// string as this is what the input will be
	std::string test = "994783256"; // tested larger values, reminded me about the long long variable type to replace int so that the larger numbers in the input work

	// find the largest digit in the number
	int max_digit = find_max_value(test);
	std::string max_digit_str = std::to_string(max_digit);
	//std::cout << max_digit;

	// find index of first occurance of the number
	int index = test.find(max_digit_str); // get first occurance of the max digit in the number

	// slice number from that index to the end
	//int len = test.size();

	std::cout << test << "\n" << max_digit << "\n" << index << "\n";

	// cut number from max_digit + 1 to end
	std::string splice = test.substr(index + 1);
	//std::cout << splice; // check splice is done as expected

	// get largest value after the occurance of the first value
	int second_digit = find_max_value(splice);
	std::string second_digit_str = std::to_string(second_digit);

	std::string joltage = max_digit_str + second_digit_str;

	std::cout << joltage;






	
}