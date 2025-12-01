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

	while (getline(file, line)) 
	{	
		cout << line << endl;
	}

	//int lines = 0;

	/*
	// keep reading file until reach its end. While we are not at the end of the file.
	while (!file.eof()) 
	{
		// read each line from the file and add it to the array at index lines
		std::getline(file, array[lines]);
		lines++; // add 1 to lines
	
	}
	*/

	return 0; // its convention to return 0 for successfully run code in c++ so the OS knows that it ran successfully
}