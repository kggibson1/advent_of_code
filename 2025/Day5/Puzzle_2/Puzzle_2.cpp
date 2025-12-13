#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm> // for sort

int main() {

	std::string range1 = "235185441269656-237391022191511";
	std::string range2 = "236582027246318-238330044306851";

	// read in ranges
	// read in input file
	std::string filename = "input.txt";
	std::ifstream file; // create ifstream item, allows file to be connected from the stream
	file.open(filename);

	// check file opened 
	if (file.fail()) {

		std::cout << "Could not read file" << std::endl;

		return 1; // lets OS know that program didnt run correctly
	}

	// store single line at a time as read in from the input file
	std::string line;

	// make pair vector for ranges, easier to sort in order
	std::vector<std::pair<long long, long long>> ranges;

	// read in ranges
	while (std::getline(file, line)) {

		//std::cout << line << std::endl;

		// check to see if blank line present (end of ranges, start of ID's).
		if (!line.size()) {

			break; // avoid continuing into ID's, not needed
		}

		// separate IDs from input file into upper and lower ID limits
		long long upper_id;
		long long lower_id;
		char dash;

		// create string stream object to assign upper and lower limits for each ID range
		std::stringstream ss(line);

		// if variables arent assigned correctly from ID range in string stream
		if (!(ss >> lower_id >> dash >> upper_id)) {

			std::cout << "Failed to read ID limits" << std::endl;

		}
		
		// add limits to vector
		ranges.push_back({lower_id, upper_id});

	}

	// sort ranges by order of the lower limit
	std::sort(ranges.begin(), ranges.end());

	// limits of current combined range (not possible to create random unique numbers if both intially set to 0)
	long long upper_lim = ranges[0].second;
	long long lower_lim = ranges[0].first;

	// store combined larger ranges containing only unique numbers when compared to every other range
	std::vector<long long> combined_upper_limits;
	std::vector<long long> combined_lower_limits;

	// loop over ranges, combine to make larger ranges of unique numbers (easier to process later)
	for (int i = 1; i < ranges.size(); i++) {
	
		// current ranges
		long long up_current = ranges[i].second;
		long long low_current = ranges[i].first;

		// Check if range is encapsulated within current combined range, if so, ignore it (no additional unique values)
		if (up_current <= upper_lim) { continue; } // move onto next range, low_current >= lower_lim will always be the case due to sorting

		// check if ranges overlap, low_current >= lower_lim will always be the case due to sorting
		// accounts for touching ranges e.g 10-15 and 16-20
		if (low_current <= upper_lim + 1) {
		
			upper_lim = std::max(upper_lim, up_current);
			continue; // move on as the combined range has been expanded
		}

		// check if current range is outwith the already established combined one
		// if so, store the established combined range and create a new one to begin again from
		if (low_current > upper_lim) {
		
			// push current limits to correct vectors
			combined_upper_limits.push_back(upper_lim);
			combined_lower_limits.push_back(lower_lim);

			// set current range as starting point for building new combined range
			upper_lim = up_current;
			lower_lim = low_current;
		
		}
	
	}

	// push final limits
	combined_upper_limits.push_back(upper_lim);
	combined_lower_limits.push_back(lower_lim);
	
	long long fresh_ids = 0;

	// count how many IDs are within the combined ranges
	for (int j = 0; j < combined_upper_limits.size(); j++) {
	
		fresh_ids += combined_upper_limits[j] - combined_lower_limits[j] + 1; // +1 as ranges are inclusive of edges
	}

	//std::cout << combined_lower_limits[0] << "-" << combined_upper_limits[0];
	std::cout << "number of fresh ids: " << fresh_ids;
}

