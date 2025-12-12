#include <fstream> //reading files
#include <iostream> // for cout
#include <string> //getline
#include <vector>
#include <sstream> // for string stream


// function that is run when script built and ran, int tells us about the integer type return? (!!! Check this)
int main() {

	// read in input file
	std::string filename = "input.txt";
	std::ifstream file; // create ifstream item, allows file to be connected from the stream
	file.open(filename);

	// check file opened 
	if (file.fail()) {
	
		std::cout << "Could not read file" << std::endl;

		return 1; // lets OS know that program didnt run correctly
	}

	// read and store ID values to check
	bool check = false; // check if blank line has been hit, indicated that ID's are now present in getline

	std::vector<std::string> ids;

	// store single line at a time as read in from the input file
	std::string line;

	// read in ranges
	while (std::getline(file, line)) {
		
		// check to see if blank line present (end of ranges, start of ID's).
		// indicate this has happened by switching check boolean to true
		if (!line.size()) {
			
			check = true;
			continue; // prevent blank line being pushed to vector
		}

		// if blank line has been passed, store ID's in vector
		if (check == true) {
			
			//std::cout << "True" << '\n' << line << std::endl;
			ids.push_back(line);
		}
	
	}

	// close file
	file.clear();
	file.seekg(0);

	// loop through ID ranges, checking if the stored ID's are present within any of the ranges
	int no_fresh_ingredients = 0;
	std::vector<bool> counted(ids.size(), false); // check if ID has already been counted

	while (std::getline(file, line)) {
	
		// check to see if blank line has been reached, end of ID ranges
		// we dont need to read any further - break while loop
		if (!line.size()) {

			break;
		}

		// separate IDs from input file into upper and lower ID limits
		long long upper_id; // long long may backfire as I havent got a check for if the while int was read (I assume abort would be thrown if not?)
		long long lower_id;
		char dash;

		// create string stream object to assign upper and lower limits for each ID range
		std::stringstream ss(line);

		// if variables arent assigned correctly from ID range in string stream
		if (!(ss >> lower_id >> dash >> upper_id)) {
		
			std::cout << "Failed to read ID limits" << std::endl;
		
		}

		//std::cout << lower_id << " " << upper_id << std::endl;

		// loop through ids and check if they are present within current range
		for (int i = 0; i < ids.size(); i++) {

			// check if id has already been checked as fresh
			if (counted[i] == true) {
				continue;
			}

			// convert string id to long long
			long long id_convert;
			id_convert = std::stoll(ids[i]);
			
			// check id within range 
			if (id_convert >= lower_id && id_convert <= upper_id) {
				
				// ingredient is fresh if within range
				no_fresh_ingredients += 1;
				counted[i] = true; // mark that id has been marked fresh, avoid double counting
			}
		}
	}

	std::cout << "No_fresh ingredients = " << no_fresh_ingredients << std::endl;

	return 0; // exit code, 0 says it ran fine

}