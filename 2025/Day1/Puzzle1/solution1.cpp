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
		cout << "Could not read file" << endl; // string prints, endl prints a new line and flushes the output buffer (in this case filename), each << adds something to the stream

		return 1; // let the operating system (OS) know that the code failed 
	}

	//std::string array[max_lines];
	std::string line; // use to hold the number of lines

	// define puzzle start point
	int current_position;
	current_position = 50;

	// track how many zeros the dial lands on after a move
	int zeros = 0;

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

		// can just do this when doing the directional if statements, saves lines
		/*
		// find number of moves equivalent to moving just once around the dial
		if (no_moves_int > 99)
		{
			no_moves_int = no_moves_int % 99; // modulo is the goat in all languages
		}*/

		// check all moves are now less than 99
		//std::cout << no_moves_int << endl;

		// if dial must move to the right
		if (direction == "R") 
		{
			current_position = (current_position + no_moves_int)%100; // as there are 100 positions including 0
		}

		// if dial must move to the left
		if (direction == "L")
		{
			current_position = (current_position - no_moves_int)%100;

			// fix any negative values
			if (current_position < 0) 
			{
				current_position += 100;
			}
		}

		//cout << current_position << endl;

		if (current_position == 0) 
		{
			zeros += 1; // had it as =+ before which assigns the variable as the positive value of the number, explaining why my solution was 1 before
		}
		

	}

	cout << "Number of times dial lands on zero: " << zeros;


	// its convention to return 0 for successfully run code in c++ so the OS knows that it ran successfully
	return 0;
	}