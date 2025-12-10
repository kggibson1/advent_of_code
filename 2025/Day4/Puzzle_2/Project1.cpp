#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <vector>

// A global grid would be really useful which I can get with classes, just dont feel I have proper c++ foundation yet to move onto that

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

	// track positions of rolls to be removed at the end of each iteration
	std::vector<std::pair<int, int>> remove_positions;

	// while rolls are still being removed in the previous iteration
	// rely on remove_positions being empty to break loop, which is why while(true) is okay
	while (true) {

		// reset the positions to be set to 0
		remove_positions.clear();

		// Iterating using indexes over 2d vector
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				//std::cout << paper_rolls[i][j] << " ";

				// if position is a roll check if its accessible
				if (paper_rolls[i][j] == 1) {

					// check roll is accessible
					if (count_surrounding_rolls(paper_rolls, i, j) < 4) {
						no_accessible_rolls += 1;

						// track the positions of any rolls removed
						remove_positions.push_back({ i, j });
					}
				}
			}
			//std::cout << std::endl;
		}

		// break loop if no rolls where removed
		if (remove_positions.size() == 0) { 
			
			break; 
		
		}

		// change any rolls that were removed value from 1 to 0
		for (std::pair<int, int> pos : remove_positions) {
			int i = pos.first;
			int j = pos.second;
			paper_rolls[i][j] = 0;
		}

		std::cout << no_accessible_rolls << '\n';
	
	}

	// check indivdual characters - looks good
	//std::cout << paper_rolls[10][0] << '\n' << paper_rolls[0].size();

	std::cout << no_accessible_rolls;

	return 0;

}

