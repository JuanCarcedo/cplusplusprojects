/*******************************
* author: Juan Carcedo
* date: 2023
* Details:
*	Replicate a simple main menu and user interactions.
*******************************/
#include "menu.h"

// Main call
void control_menu_program() {
	// Declarations
	vector<int> v_integers{ 1, 2, 3, 4, 5 };

	// Set precision during cout
	cout << fixed << setprecision(2);

	// Run program
	main_menu(v_integers);

	// End of program
	cout << "See you next time! \n-- Closing program." << endl;
}

// Support functions ==============================

// Get new number into the vector
void add_number(vector<int>& v_integers) {
	int new_number{};

	cout << "Input number to add: ";
	cin >> new_number;
	
	v_integers.push_back(new_number);
	
	cout << new_number << " added" << endl;
}

void calculate_mean(const vector<int>& v_integers) {
	int number_calculator{ 0 };

	for (auto item : v_integers) {
		number_calculator += item;
	}

	cout << "The mean is: "
		<< static_cast<double>(number_calculator) / v_integers.size()
		<< endl;
}

void get_smallest_number(const vector<int>& v_integers) {
	int number_calculator {INT_MAX};

	for (auto item : v_integers) {
		if (item < number_calculator) {
			number_calculator = item;
		}
	}

	cout << "The smallest number is " << number_calculator << endl;
}

void get_largest_number(const vector<int>& v_integers) {
	int number_calculator{ INT_MIN };

	for (auto item : v_integers) {
		if (item > number_calculator) {
			number_calculator = item;
		}
	}

	cout << "The largest number is " << number_calculator << endl;
}

void print_vector(const vector<int>& v_integers) {
	cout << "[ ";
	for (auto item : v_integers) {
		cout << item << " ";
	}
	cout << "]" << endl;
}

void print_main_menu(const vector<string>& MENU) {
	cout << endl;

	for (string menu_item : MENU) {
		cout << menu_item;
	}
}

// change status of running to false
void quit_system(bool& running) {
	running = false;
}

// Control the main loop/menu from program
void main_menu(vector<int>& v_integers) {
	// Declarations
	const vector<string> MENU{
		"P - Print numbers\n",
		"A - Add a number\n",
		"M - Display mean of the numbers\n",
		"S - Display the smallest number\n",
		"L - Display the largest number\n",
		"Q - Quit\n",
		"Enter your choice: "
	};

	bool running{ true };  // Check the status of program
	char user_selection{};
	
	// Main loop
	while (running) {
		// Print menu
		print_main_menu(MENU);

		cin >> user_selection;

		// Check options
		switch (user_selection) {

		case'p':
		case'P':
			// Print vector
			if (v_integers.empty()) {
				cout << "[] - the list is empty" << endl;
			}
			else {
				print_vector(v_integers);
			}
			
			break;

		case 'a':
		case 'A':
			// Add number
			add_number(v_integers);
			
			break;

		case 'm':
		case 'M':
			// Calculate mean
			if (v_integers.empty()) {
				cout << "Unable to calculate mean -- no data" << endl;
			}
			else {
				calculate_mean(v_integers);
			}

			break;

		case 's':
		case 'S':
			// Get smallest number
			if (v_integers.empty()) {
				cout << "Unable to determine the smallest number -- no data" << endl;
			}
			else {
				get_smallest_number(v_integers);
			}

			break;

		case 'l':
		case 'L':
			// Get largest number
			if (v_integers.empty()) {
				cout << "Unable to determine the largest number -- no data" << endl;
			}
			
			else {
				get_largest_number(v_integers);
			}
			
			break;

		case 'q':
		case 'Q':
			quit_system(running);
			break;

		default:
			cout << "Unknown selection, please try again" << endl;
		}
	}
}
