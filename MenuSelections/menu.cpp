/*******************************
* author: Juan Carcedo
* date: 2023
* Details:
*	Replicate a simple main menu and user interactions.
*******************************/
#include "menu.h"

// Main call -----------------------
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

// Control functions ==============================
void control_print(const vector<int>& v_integers){
	if (v_integers.empty()) {
				cout << "[] - the list is empty" << endl;
	}
	else {
		print_vector(v_integers);
	}
}

void control_new_number(vector<int>& v_integers) {
	int new_number{};

	cout << "Input number to add: ";
	cin >> new_number;
	
	if (new_number){
		add_number(v_integers, new_number);
		cout << new_number << " added" << endl;
	} else {
		cout << "Not a valid option." << endl;
	}
	
}

void control_mean_calculation(const vector<int>& v_integers) {
	if (v_integers.empty()) {
		cout << "Unable to calculate mean -- no data" << endl;
	}
	else {
		cout << "The mean is: "
			<< calculate_mean(v_integers) << endl;
	}
}

void control_get_smallest(const vector<int>& v_integers){
	if (v_integers.empty()) {
		cout << "Unable to determine the smallest number -- no data" << endl;
	}
	else {
		cout << "The smallest number is "
			 << get_smallest_number(v_integers) << endl;
	}
}

void control_get_largest(const vector<int>& v_integers){
	if (v_integers.empty()) {
		cout << "Unable to determine the largest number -- no data" << endl;
	}
	else {
		cout << "The largest number is "
	 		 << get_largest_number(v_integers) << endl;
	}
}

// Default action if no choice selected
void control_default(){
	cout << "Unknown selection, please try again" << endl;
}


// Support functions ==============================

// Get new number into the vector
void add_number(vector<int>& v_integers, int new_number) {
	v_integers.push_back(new_number);
}

double calculate_mean(const vector<int>& v_integers) {
	int number_calculator{ 0 };
	double mean{0.0};

	for (auto item : v_integers) {
		number_calculator += item;
	}
	
	mean = static_cast<double>(number_calculator) / v_integers.size();

	return mean;
}

int get_smallest_number(const vector<int>& v_integers) {
	int number_calculator {INT_MAX};

	for (auto item : v_integers) {
		if (item < number_calculator) {
			number_calculator = item;
		}
	}

	return number_calculator;
}

int get_largest_number(const vector<int>& v_integers) {
	int number_calculator{ INT_MIN };

	for (auto item : v_integers) {
		if (item > number_calculator) {
			number_calculator = item;
		}
	}

	return number_calculator;
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

// change status of running to false - Here for future additions
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
			control_print(v_integers);
			break;

		case 'a':
		case 'A':
			// Add number
			control_new_number(v_integers);
			break;

		case 'm':
		case 'M':
			// Calculate mean
			control_mean_calculation(v_integers);
			break;

		case 's':
		case 'S':
			// Get smallest number
			control_get_smallest(v_integers);
			break;

		case 'l':
		case 'L':
			// Get largest number
			control_get_largest(v_integers);
			break;

		case 'q':
		case 'Q':
			quit_system(running);
			break;

		default:
			control_default();
		}
	}
}
