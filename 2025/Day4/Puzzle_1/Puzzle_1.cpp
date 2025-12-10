#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <vector>

/*
// once I learn more about classes I feel this problem would be simpler solved in them (assuming they behave logically the same as in Python)
// count the number of rolls surrounding a paper roll in position i, j. Discrete boundary conditions
int count_surrounding_rolls(std::vector<std::vector<int>> vec, int i, int j) {

	// get size of vector grid for boundary conditions
	int rows = vec.size();    
	int cols = vec[0].size();    

	// deal with boundaries
	// is the position on the first vector row
	if (i == 0) {
		int n2 = vec[i][j + 1];
		int n3 = vec[i + 1][j + 1];
		int n5 = vec[i + 1][j];
		int n7 = vec[i][j - 1];
		int n8 = vec[i + 1][j - 1];

		// top left corner
		if (j == 0) {
			int n2 = vec[i][j + 1];
			int n3 = vec[i + 1][j + 1];
			int n5 = vec[i + 1][j];
		}

		// top right corner
		if (j == cols - 1) {
			int n5 = vec[i + 1][j];
			int n7 = vec[i][j - 1];
			int n8 = vec[i + 1][j - 1];
		}

		// count number of neighbouring positions with paper
		int no_paper_neighbours = n2 + n3 + n5 + n7 + n8;
		return no_paper_neighbours;

	}

	// last row
	if (i == rows - 1) {
		int n1 = vec[i - 1][j + 1];
		int n2 = vec[i][j + 1];
		int n4 = vec[i - 1][j];
		int n6 = vec[i - 1][j - 1];
		int n7 = vec[i][j - 1];

		// bottom left corner
		if (j == 0) {
			int n1 = vec[i - 1][j + 1];
			int n2 = vec[i][j + 1];
			int n4 = vec[i - 1][j];
		}

		// bottom right corner
		if (j == cols - 1) {
			int n4 = vec[i - 1][j];
			int n6 = vec[i - 1][j - 1];
			int n7 = vec[i][j - 1];
		}

		// count number of neighbouring positions with paper
		int no_paper_neighbours = n1 + n2 + n4 + n6 + n7;
		return no_paper_neighbours;

	}

	else {
		// anything not on the edge of the grid
		// determine if each neighbour is an empty space or paper roll
		int n1 = vec[i - 1][j + 1];
		int n2 = vec[i][j + 1];
		int n3 = vec[i + 1][j + 1];
		int n4 = vec[i - 1][j];
		int n5 = vec[i + 1][j];
		int n6 = vec[i - 1][j - 1];
		int n7 = vec[i][j - 1];
		int n8 = vec[i + 1][j - 1];

		// count number of live neighbours(1 = alive, 0 = dead)
		int no_paper_neighbours = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;
		return no_paper_neighbours;
	}

	//return no_paper_neighbours;

}

int count_surrounding_rolls_2(std::vector<std::vector<int>> vec, int i, int j) {

	int rows = vec.size();
	int cols = vec[0].size();

	// declare all neighbour variables first (initially zero)
	int n1 = 0, n2 = 0, n3 = 0;
	int n4 = 0, n5 = 0;
	int n6 = 0, n7 = 0, n8 = 0;

	// TOP ROW
	if (i == 0) {

		// top-left corner
		if (j == 0) {
			n2 = vec[i][j + 1];
			n3 = vec[i + 1][j + 1];
			n5 = vec[i + 1][j];
		}

		// top-right corner
		else if (j == cols - 1) {
			n4 = 0; // nothing above
			n6 = 0; // nothing above-left
			n7 = vec[i][j - 1];
			n8 = vec[i + 1][j - 1];
			n5 = vec[i + 1][j];
		}

		// top edge (not corner)
		else {
			n2 = vec[i][j + 1];
			n3 = vec[i + 1][j + 1];
			n5 = vec[i + 1][j];
			n7 = vec[i][j - 1];
			n8 = vec[i + 1][j - 1];
		}

		return n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;
	}

	// BOTTOM ROW
	if (i == rows - 1) {

		// bottom-left corner
		if (j == 0) {
			n1 = vec[i - 1][j + 1];
			n2 = vec[i][j + 1];
			n4 = vec[i - 1][j];
		}

		// bottom-right corner
		else if (j == cols - 1) {
			n4 = vec[i - 1][j];
			n6 = vec[i - 1][j - 1];
			n7 = vec[i][j - 1];
		}

		// bottom edge (not corner)
		else {
			n1 = vec[i - 1][j + 1];
			n2 = vec[i][j + 1];
			n4 = vec[i - 1][j];
			n6 = vec[i - 1][j - 1];
			n7 = vec[i][j - 1];
		}

		return n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;
	}

	// INTERIOR (your original case)
	n1 = vec[i - 1][j + 1];
	n2 = vec[i][j + 1];
	n3 = vec[i + 1][j + 1];
	n4 = vec[i - 1][j];
	n5 = vec[i + 1][j];
	n6 = vec[i - 1][j - 1];
	n7 = vec[i][j - 1];
	n8 = vec[i + 1][j - 1];

	return n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;
}
*/

/*
takes i and j position to check in the vector grid, computes the positions of the 8 adjacent neighbours
checks those positions are within the grid, checks if a roll of paper is contained within each adjacent position,
returns int of total adjacent rolls.
*/
int count_surrounding_rolls(std::vector<std::vector<int>> vec, int i, int j) {

	// Get the number of rows and columns in 2D vector
	int rows = vec.size();
	int cols = vec[0].size();

	// number of neighbouring cells with paper
	int no_paper_neighbours = 0;

	/*
		indexing of 8 neighbouring cells

			  (i-1,j-1)  (i-1,j)  (i-1,j+1)
			  (i  ,j-1)  ( i ,j)  (i  ,j+1)
			  (i+1,j-1)  (i+1,j)  (i+1,j+1)

		di = -1 means "one row up"
		di =  0 means "same row"
		di = +1 means "one row down"

		Same idea for dj and columns.
	*/

	for (int di = -1; di <= 1; di++) {     // loop through row offsets
		for (int dj = -1; dj <= 1; dj++) { // loop through column offsets

			// ignore i, j as it isnt a neighbour
			if (di == 0 && dj == 0)
				continue;

			// Compute the actual coordinates of the neighbour
			int ni = i + di;  // neighbour row
			int nj = j + dj;  // neighbour column

			/*
				Make sure (ni, nj) is inside the grid.

				Without this check, positions like:
					(i-1, j-1) when i=j=0 (top-left corner)
				would go outside the vector and abort
			*/
			if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
				// Add the neighbour’s value (0 or 1)
				no_paper_neighbours += vec[ni][nj];
			}

			// ignore if outside grid
		}
	}

	return no_paper_neighbours;
}




int main() {

	// Read from the text file
	std::string filename; // dont need the std:: due to using namespace std; but will include for knowledge just now

	std::ifstream file; // type of variable used to read a file, it isnt connected to a file yet (from fstream)

	// connect a file to ifstream object to read in
	filename = "input.txt";

	file.open(filename);

	// exit with error message if problem opening the file (uneccesary for purpose but good to learn)
	if (file.fail()) // if file doesnt successfully open
	{
		std::cout << "Could not read file" << std::endl; // string prints, endl prints a new line and flushes the output buffer (in this case filename), each << adds something to the stream

		return 1; // let the operating system (OS) know that the code failed 
	}

	// temp variable to store each 
	std::string line;

	// store line previous to the one being parsed
	//std::string line_above;

	// establish vector for appending char lines into, 
	// vector used over array as vector size can be changed whereas arrays cannot be
	std::vector<std::vector<int>> paper_rolls;

    // establish grid
    while (getline(file, line)) {
        
        //std::cout << line << '\n' << std::endl;

		std::vector<int> row;

		// read each character, ignoring space delimeter
		for (char& c : line) {
			if (c != ' ') {

				// check if paper_roll is present, if so char becomes 1
				if (c == '@') {
				
					row.push_back(1);
				}

				// if no roll present, char is 0
				else { row.push_back(0); }
			}
		}

		// add row to vector
		paper_rolls.push_back(row);    
    }

	// std::cout has no template to print vectors to command prompt
	//std::cout << paper_rolls;

	int rows = paper_rolls.size();
	int cols = paper_rolls[0].size();

	// keep count of number of rolls accessible by forklift
	int no_accessible_rolls = 0;

	// Iterating using indexes over 2d vector
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//std::cout << paper_rolls[i][j] << " ";

			// if position is a roll check if its accessible
			if (paper_rolls[i][j] == 1) {

				// check roll is accessible
				if (count_surrounding_rolls(paper_rolls, i, j) < 4) {
					no_accessible_rolls += 1;
				}
			}
		}
		//std::cout << std::endl;
	}

	// check indivdual characters - looks good
	//std::cout << paper_rolls[10][0] << '\n' << paper_rolls[0].size();
	
	std::cout << no_accessible_rolls;

	return 0;

}

