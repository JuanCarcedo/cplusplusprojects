#pragma once
// Include any include that you want to use.
#include <vector>
#include <iostream>
#include <iomanip>  // To print beauty like cout << fixed << setprecision(2); 2 decimals
using namespace std;

// Control functions ================================
void control_menu_program();  // Main for menu
void main_menu(vector<int>& v_integers);
void control_print(const vector<int>& v_integers);
void control_new_number(vector<int>& v_integers);
void control_mean_calculation(const vector<int>& v_integers);
void control_get_smallest(const vector<int>& v_integers);
void control_get_largest(const vector<int>& v_integers);
void control_default();
void quit_system(bool &running);
// -- Print to console
void print_main_menu(const vector<string>& MENU);
void print_vector(const vector<int>& v_integers);
// -- Modify vector
void add_number(vector<int>& v_integers, int new_number);
// -- Calculations
double calculate_mean(const vector<int>& v_integers);
int get_smallest_number(const vector<int>& v_integers);
int get_largest_number(const vector<int>& v_integers);
