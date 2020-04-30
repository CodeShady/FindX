/*
      ___                     ___          _____          ___     
     /  /\      ___          /__/\        /  /::\        /__/|    
    /  /:/_    /  /\         \  \:\      /  /:/\:\      |  |:|    
   /  /:/ /\  /  /:/          \  \:\    /  /:/  \:\     |  |:|    
  /  /:/ /:/ /__/::\      _____\__\:\  /__/:/ \__\:|  __|__|:|    
 /__/:/ /:/  \__\/\:\__  /__/::::::::\ \  \:\ /  /:/ /__/::::\____
 \  \:\/:/      \  \:\/\ \  \:\~~\~~\/  \  \:\  /:/     ~\~~\::::/
  \  \::/        \__\::/  \  \:\  ~~~    \  \:\/:/       |~~|:|~~ 
   \  \:\        /__/:/    \  \:\         \  \::/        |  |:|   
    \  \:\       \__\/      \  \:\         \__\/         |  |:|   
     \__\/                   \__\/                       |__|/    

     By: CodeShady

*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>

using namespace std;

// Variables
vector<string> arguments;

// GEOMETRY VARIABLES
bool is3D = false;
bool unitFind = false;
int width;
int height;
int depth;



void answer(double answer) {
	cout << std::fixed << std::setprecision(2) << "Answer: " << answer << endl;
}


// Functions
void isUnitFind(int &i, bool &found) {
    if (unitFind) {
        if (is3D) {
            // 3D Object
            if(arguments[i] == "-w" || arguments[i] == "--width") {
                width = stoi(arguments[i+1]);
            }
            if(arguments[i] == "-h" || arguments[i] == "--height") {
                height = stoi(arguments[i+1]);
            }
            if(arguments[i] == "-d" || arguments[i] == "--depth") {
                depth = stoi(arguments[i+1]);
            }

        } else {
            // 2D object
            if(arguments[i] == "-w" || arguments[i] == "--width") {
                width = stoi(arguments[i+1]);
            }
            if(arguments[i] == "-h" || arguments[i] == "--height") {
                height = stoi(arguments[i+1]);
            }
        }
    }

    if (unitFind && is3D && width && height && depth) {
        answer((width * height) * depth);
        found = true;
    }
    else if (unitFind && !is3D && width && height) {
        answer(width * height);
        found = true;
    }
}


double chainMath(string op) {
	// Op = operator
	double finalMath = 0.0;
	
	for (int i = 1; i < arguments.size(); i++) {
		// Check if this is the first loop		
		if (i == 1) {
			finalMath = stoi(arguments[i]);
			continue;
		}
		// Continue?
		if (op == "+") { finalMath += stoi(arguments[i]); }
		else if (op == "-") { finalMath -= stoi(arguments[i]); }
		else if (op == "/") { finalMath /= stoi(arguments[i]); }
		else if (op == "*") { finalMath *= stoi(arguments[i]); }
		else {
			cout << "Error with your syntax! Are you feeling okay?" << endl;
			exit(-1);
		}

		// Return Value If Finished	
		if (i == arguments.size()-1) { return finalMath; }
	}
	
	cout << "Error with your syntax! Are you feeling okay?" << endl;
	exit(-1);
	return -1;
}


int parseArgs() {
    bool found = false;

    for (int i=0;i<arguments.size();i++) {
        // If answer was found, BREAK!
        if (found) {
            break;
        }

        // Is 3D?
        if (arguments[i] == "--3d") {
            is3D = true;
        }

        // Volume calculation
        else if (arguments[i] == "--volume" || arguments[i] == "--vol") {
            // Geometry Unitfind/Volume find
            unitFind = true;
        }

        // Addition
        else if (arguments[i] == "-a" || arguments[i] == "--addition") {
            answer(chainMath("+"));
            found = true;
        }

        // Subtraction
        else if (arguments[i] == "-s" || arguments[i] == "--subtraction") {
            answer(chainMath("-"));
            found = true;
        }

        // Division
        else if (arguments[i] == "-d" || arguments[i] == "--division") {
            	answer(chainMath("/"));
		found = true;
        }

        // Multiplication
        else if (arguments[i] == "-m" || arguments[i] == "--multiplication") {
	        answer(chainMath("*"));    
		found = true;
        }

        isUnitFind(i, found);

    }

    if (found) {
        return 0;
    } else {
        return -1;
    }
}



int main(int argc, const char * argv[]) {
    
    int x;
    int angle;
    bool usingArgs;

    // Arguments
    if (argc == 1) {
        usingArgs = false; // No arguments were passed
    } else {
        usingArgs = true; // Arguments were passed
    }

    if (usingArgs) {
        // Using arguments
        
        for (int i = 1; i < argc; ++i) {
            arguments.push_back(argv[i]);
        }

        // Parse arguments
        int answer = parseArgs();

        if (answer == -1) {
            cout << "Unable to find answer!\nMaybe wrong arguments passed in command?" << endl;
        }

    } else {
        // Not using arguments
        cout << "Oops! That's not a valid command!" << endl;
        return -1;
        
    }
    
    return 0;
}
