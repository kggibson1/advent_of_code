#include <iostream> 
#include <fstream> 
#include <string>

int main() {

    // read in file
    std::ifstream file("input.txt");
    std::string line;

    int total_joltage = 0;

    // find max joltage of each line seperately
    while (getline(file, line)) {

        // for this set of batteries
        int max_joltage = 0;

        // Find the largest two-digit number in this line by looping over all possible pairs
        for (size_t i = 0; i < line.size() - 1; i++) { 
            
            // first digit
            int digit1 = line[i] - '0'; // convert from ascii to digit 

            // second digit
            for (size_t j = i + 1; j < line.size(); j++) {

                int digit2 = line[j] - '0';

                // get joltage from current pair
                int joltage = digit1*10 + digit2;

                // if this joltage is greater than the current max, replace it
                if (joltage > max_joltage) {
                    max_joltage = joltage;
                }
            }
        }

        // add to joltage running total
        total_joltage += max_joltage;
    }

    // print final joltage
    std::cout << "Summed Joltage is " << total_joltage << std::endl;
}
