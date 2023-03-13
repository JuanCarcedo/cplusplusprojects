#pragma once
// Include any include that you want to use.
#include <vector>
#include <iostream>
#include <iomanip>  // To print beauty like cout << fixed << setprecision(2); 2 decimals
using namespace std;

// Control menu-user ================================
void control_menu_program();  // Main for menu
void main_menu(vector<int>& v_integers);
void quit_system(bool &running);
// -- Print to console
void print_main_menu(const vector<string>& MENU);
void print_vector(const vector<int>& v_integers);
// -- Modify vector
void add_number(vector<int>& v_integers);
// -- Other calculations related to the vector
void calculate_mean(const vector<int>& v_integers);
void get_smallest_number(const vector<int>& v_integers);
void get_largest_number(const vector<int>& v_integers);
