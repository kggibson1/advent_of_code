/*

#include <iostream> //for text output
//#include <ifstream> // for reading files
#include <fstream> // for reading and writing to files
#include <string>
#include <typeinfo> // for checking variable types

//#define max_lines 1000 // i dont like this hard coding method but ill do it for now

using namespace std; //For anything that comes from the std namespace, you don’t need to write std:: in front of it (e.g std::string)

// had previous error where the main function in my hello world file was causing conflicts with the main function here - remember global variables within a single project matter!!
int main() {

	
	// Read from the text file
	std::string filename; // dont need the std:: due to using namespace std; but will include for knowledge just now

	ifstream file; // type of variable used to read a file, it isnt connected to a file yet (from fstream)

	// connect a file to ifstream object to read in
	filename = "input1.txt";

	file.open(filename);

	// exit with error message if problem opening the file (uneccesary for purpose but good to learn)

	if (file.fail()) // if file doesnt successfully open
	{
		std::cout << "Could not read file" << endl; // string prints, endl prints a new line and flushes the output buffer (in this case filename), each << adds something to the stream

		return 1; // let the operating system (OS) know that the code failed 
	}

	//std::string array[max_lines];
	std::string line; // use to hold the number of lines

	// define puzzle start point
	int current_position;
	current_position = 50;

	// track how many zeros the dial lands on after a move
	//int zeros = 0;

	// track how many times the dial passes zero during turns
	int zero_crossings = 0;
	int wraps = 0;

	while (getline(file, line)) // while there are lines from file to read
	{
		//cout << line[0] << endl; // print each line plus start a new line

		// parse each line for direction (R & L) and number of moves
		std::string direction;
		direction = line[0];

		std::string no_moves;
		no_moves = line.substr(1);

		// \n prints new line without flushing buffer
		//cout << direction << "\n" << no_moves << endl;

		// convert number of moves into integer
		int no_moves_int = std::stoi(no_moves);

		// check integer conversion was successful
		//std::cout << typeid(no_moves_int).name() << '\n'; // need #include <typeinfo>


		// check all moves are now less than 99
		//std::cout << no_moves_int << endl;

		// if dial must move to the right
		if (direction == "R")
		{
			// find how many times the dial clicks past 0 during rotation
			wraps = (current_position + no_moves_int) / 100; // integer division in c++ discards the remainder

			//std::cout << zero_crossings << endl;

			current_position = (current_position + no_moves_int) % 100; // as there are 100 positions including 0

		}

		// if dial must move to the left
		if (direction == "L")
		{
			//wraps = (no_moves_int - current_position + 99) / 100; // we add 99 to avoid undercounting

			//current_position = (current_position - no_moves_int) % 100;

			// fix any negative values
			//if (current_position < 0)
			//{
				//current_position += 100;
			//}

			// number of times the dial passes 0
			wraps = (no_moves_int - current_position + 99) / 100;
			current_position = (current_position - no_moves_int) % 100;

			// fix any negative values
			if (current_position < 0) 
			{
				current_position += 100;
			}
		}

		// how many times the dial passes 0
		zero_crossings += wraps;

		//cout << current_position << endl;


	}

	std::cout << "Number of times dial lands and passes zero: " << zero_crossings;


	// its convention to return 0 for successfully run code in c++ so the OS knows that it ran successfully
	return 0; 
}

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string filename = "input1.txt";
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "Could not read file" << endl;
		return 1;
	}

	string line;
	int position = 50;       // starting dial position
	int zero_count = 0;      // number of times the dial points at 0

	while (getline(file, line)) {

		char direction = line[0];
		int moves = stoi(line.substr(1));

		// simulate the rotation click by click
		for (int i = 0; i < moves; i++) {
			if (direction == 'R') {
				position = (position + 1) % 100;
			}
			else if (direction == 'L') {
				position = (position - 1 + 100) % 100;
			}

			// count zero whenever the dial points at 0
			if (position == 0) zero_count++;
		}
	}

	cout << "Number of times dial points at zero: " << zero_count << endl;

	return 0;
}



