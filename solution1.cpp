#include <iostream> //for text output
//#include <ifstream> // for reading files
#include <fstream> // for reading and writing to files
#include <string>

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

	while (getline(file, line)) // while there are lines from file to read
	{	
		//cout << line[0] << endl; // print each line plus start a new line

		// parse each line for direction (R & L) and number of moves
		std::string direction;
		direction = line[0];

		std::string no_moves;
		no_moves = line.substr(1);

		// \n prints new line without flushing buffer
		cout << direction << "\n" << no_moves << endl;

		// convert number of moves into integer
		int no_moves_int = std::stoi(no_moves);




	}



	return 0; // its convention to return 0 for successfully run code in c++ so the OS knows that it ran successfully
}