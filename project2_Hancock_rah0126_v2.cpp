//	Ronnie Hancock
//	904159448
//	project2_Hancock_rah0126_v2.cpp

//	
//	g++ project2_Hancock_rah0126_v2.cpp -o output
//	./output

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <random>
#include <ctime>
//#include <NDEBUG>

using namespace std;

//	Constant Definitions ****************************

const int numberRuns = 10000;
const int A_hit_chance = 33;
const int B_hit_chance = 50;


//	Declairation of Functions ****************************

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive, bool& Aaron_first_turn);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);

//	Declairations of Drivers ****************************

void test_at_least_two_alive();
void test_Aaron_shoots1();
void test_Aaron_shoots2();
void test_Bob_shoots();
void test_Charlie_shoots();

// Declairation of Tests ****************************

int strategy1();
void strategy2();
void comparison();

//	Main ****************************

int main(){
	cout << "*** Welcome to Ronnie's Truel of Fates Simulator ***" << endl;
	test_at_least_two_alive();
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	test_Aaron_shoots1();
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	test_Bob_shoots();
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	test_Charlie_shoots();
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	test_Aaron_shoots2();
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	strategy1();
	

	strategy2();

	return 0;
}

//	Defined Functions ****************************

bool Aaron_first_turn = true;
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){
	if(A_alive && B_alive == true){
		return true;
	}else if(A_alive && C_alive == true){
		return true;
	}else if(B_alive && C_alive == true){
		return true;
	}else{
		return false;
	}
}
void Aaron_shoots1(bool& B_alive, bool& C_alive){
	if(C_alive == true){
		if(rand() % 100 <= A_hit_chance){C_alive = false;}
	}else if(B_alive == true){
		if(rand() % 100 <= A_hit_chance){B_alive = false;}
	}
}
void Aaron_shoots2(bool& B_alive, bool& C_alive, bool& Aaron_first_turn){
	if(Aaron_first_turn == true){
		Aaron_first_turn = false;
	}else if(C_alive == true){
		if(rand() % 100 <= A_hit_chance){C_alive = false;}
	}else if(B_alive == true){
		if(rand() % 100 <= A_hit_chance){B_alive = false;}
	}
}
void Bob_shoots(bool& A_alive, bool& C_alive){
	if(C_alive == true){
		if(rand() % 100 <= B_hit_chance){C_alive = false;}
	}else if(A_alive == true){
		if(rand() % 100 <= B_hit_chance){A_alive = false;}
	}
}
void Charlie_shoots(bool& A_alive, bool& B_alive){
	if(B_alive == true){
		B_alive = false;
	}else if(A_alive == true){
		A_alive = false;
	}
}

//	Define Test Drivers ****************************

void test_at_least_two_alive(){
	bool A_alive;
	bool B_alive;
	bool C_alive;
	cout << "Unit Testing 1: Function - at_least_two_alive()" << endl;
	

	cout << "	Case 1: Aaron alive, Bob alive, Charlie alive" << endl;
	A_alive = true; B_alive = true; C_alive = true;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == true);
	cout << "		Case passed ..." << endl;


	cout << "	Case 2: Aaron dead, Bob alive, Charlie alive" << endl;
	A_alive = false; B_alive = true; C_alive = true;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == true);
	cout << "		Case passed ..." << endl;


	cout << "	Case 3: Aaron alive, Bob dead, Charlie alive"<< endl;
	A_alive = true; B_alive = false; C_alive = true;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == true);
	cout << "		Case passed ..." << endl;


	cout << "	Case 4: Aaron alive, Bob alive, Charlie dead" << endl;
	A_alive = false; B_alive = true; C_alive = false;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == false);
	cout << "		Case passed ..." << endl;


	cout << "	Case 5: Aaron dead, Bob dead, Charlie alive" << endl;
	A_alive = false; B_alive = false; C_alive = true;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == false);
	cout << "		Case passed ..." << endl;

	cout << "	Case 6: Aaron dead, Bob alive, Charlie dead" << endl;
	A_alive = false; B_alive = true; C_alive = false;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == false);
	cout << "		Case passed ..." << endl;


	cout << "	Case 7: Aaron alive, Bob dead, Charlie dead" << endl;
	A_alive = true; B_alive = false; C_alive = false;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == false);
	cout << "		Case passed ..." << endl;


	cout << "	Case 8: Aaron dead, Bob dead, Charlie dead" << endl;
	A_alive = false; B_alive = false; C_alive = false;
	assert(at_least_two_alive(A_alive, B_alive, C_alive) == false);
	cout << "		Case passed ..." << endl;
}
void test_Aaron_shoots1(){
	bool B_alive;
	bool C_alive;
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive" << endl;
	cout << "	Case 1: Bob alive, Charlie alive" << endl;
	B_alive = true; C_alive = true;
	while(B_alive == true && C_alive == true){
		Aaron_shoots1(B_alive, C_alive);
	}
	assert(C_alive == false);
	cout << "		Aaron is shooting at Charlie" << endl;


	cout << "	Case 2: Bob dead, Charlie alive" << endl;
	B_alive = false; C_alive = true;
	while(C_alive == true){
		Aaron_shoots1(B_alive, C_alive);
	}
	assert(C_alive == false);
	cout << "		Aaron is shooting at Charlie" << endl;
	

	cout << "	Case 3: Bob alive, Charlie dead" << endl;
	B_alive = true; C_alive = false;
	while(B_alive == true){
		Aaron_shoots1(B_alive, C_alive);
	}
	assert(B_alive == false);
	cout << "		Aaron is shooting at Bob" << endl;
}
void test_Bob_shoots(){
	bool A_alive;
	bool C_alive;
	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)" << endl;
	cout << "	Case 1: Aaron alive, Charlie alive" << endl;
	A_alive = true; C_alive = true;
	while(C_alive == true){
		Bob_shoots(A_alive, C_alive);
	}
	assert(C_alive == false);
	cout << "		Bob is shooting at Charlie" << endl;


	cout << "	Case 1: Aaron dead, Charlie alive" << endl;
	A_alive = true; C_alive = true;
	while(C_alive == true){
		Bob_shoots(A_alive, C_alive);
	}
	assert(C_alive == false);
	cout << "		Bob is shooting at Charlie" << endl;


	cout << "	Case 1: Aaron alive, Charlie dead" << endl;
	A_alive = true; C_alive = true;
	while(A_alive == true){
		Bob_shoots(A_alive, C_alive);
	}
	assert(C_alive == false);
	cout << "		Bob is shooting at Aaron" << endl;
}
void test_Charlie_shoots(){
	bool A_alive;
	bool B_alive;
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)" << endl;
	cout << "	Case 1: Aaron alive, Bob alive" << endl;
	A_alive = true; B_alive = true;
	Charlie_shoots(A_alive, B_alive);
	assert(B_alive == false);
	cout << "		Charlie is shooting at Bob" << endl;


	cout << "	Case 2: Aaron dead, Bob alive" << endl;
	A_alive = false; B_alive = true;
	while(B_alive == true){
		Aaron_shoots1(A_alive, B_alive);
	}
	assert(B_alive == false);
	cout << "		Charlie is shooting at Bob" << endl;


	cout << "	Case 3: Aaron dead, Bob dead" << endl;
	A_alive = true; B_alive = false;
	while(A_alive == true){
		Aaron_shoots1(A_alive, B_alive);
	}
	assert(A_alive == false);
	cout << "		Charlie is shooting at Bob" << endl;
}
void test_Aaron_shoots2(){
	bool B_alive = true;
	bool C_alive = true;
	bool Aaron_first_turn = true;
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)" << endl;
	cout << "	Case 1: Bob alive, Charlie alive" << endl;
	Aaron_shoots2(B_alive, C_alive, Aaron_first_turn);
	assert(Aaron_first_turn == false);
	cout << "		Aaron intentionally missed his first shot" << endl;
	cout << "		Both Bob and Charlie are alive." << endl;
	

	cout << "	Case 2: Bob dead, Charlie alive" << endl;
	B_alive = false; C_alive = true;
	while(C_alive == true){
		Aaron_shoots2(B_alive, C_alive, Aaron_first_turn);
	}
	assert(C_alive == false);
	cout << "		Aaron is shooting at Charlie" << endl;
	

	cout << "	Case 3: Bob alive, Charlie dead" << endl;
	B_alive = true; C_alive = false;
	while(B_alive == true){
		Aaron_shoots2(B_alive, C_alive, Aaron_first_turn);
	}
	assert(B_alive == false);
	cout << "		Aaron is shooting at Bob" << endl;
}

//	Define Tests ****************************

int strategy1(){
	bool A_alive = true; int A_wins = 0;
	bool B_alive = true; int B_wins = 0;
	bool C_alive = true; int C_wins = 0;
	float percentA;
	float percentB;
	float percentC;

	cout << "Ready to test strategy 1 (run " << numberRuns << " times):" << endl;
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	for(int i = 0; i < numberRuns; i++){
		while(at_least_two_alive(A_alive, B_alive, C_alive)){
			if(A_alive){
				Aaron_shoots1(B_alive, C_alive);
			}
			if(B_alive){
				Bob_shoots(A_alive, C_alive);
			}
			if(C_alive){
				Charlie_shoots(A_alive, B_alive);
			}
		}
		if(A_alive){A_wins++;}else if(B_alive){B_wins++;}else{C_wins++;}
		A_alive = true; B_alive = true; C_alive = true;
	}
	percentA = 100.0 * A_wins / numberRuns;
	percentB = 100.0 * B_wins / numberRuns;
	percentC = 100.0 * C_wins / numberRuns;
	cout.precision(4);
	cout << showpoint;
	cout << "Aaron won " << A_wins << "/" << numberRuns << " truels or " << percentA << "%" << endl;
	cout << "Bob won " << B_wins << "/" << numberRuns << " truels or " << percentB << "%" << endl;
	cout << "Charlie won " << C_wins << "/" << numberRuns << " truels or " << percentC << "%" << endl;
	return A_wins;
}
void strategy2(){
	bool A_alive = true; int A_wins = 0;
	bool B_alive = true; int B_wins = 0;
	bool C_alive = true; int C_wins = 0;
	bool Aaron_first_turn = true;
	float percentA;
	float percentB;
	float percentC;
	cout << endl;
	cout << "Ready to test strategy 2 (run " << numberRuns << " times):" << endl;
	// Pause Command for Linux Terminal
	cout << "Press Enter to continue...";
	cin.ignore().get();

	for(int i = 0; i < numberRuns; i++){
		while(at_least_two_alive(A_alive, B_alive, C_alive)){
			if(A_alive){
				Aaron_shoots2(B_alive, C_alive, Aaron_first_turn);
			}
			if(B_alive){
				Bob_shoots(A_alive, C_alive);
			}
			if(C_alive){
				Charlie_shoots(A_alive, B_alive);
			}
		}
		if(A_alive){A_wins++;}else if(B_alive){B_wins++;}else{C_wins++;}
		A_alive = true; B_alive = true; C_alive = true; Aaron_first_turn = true;
	}
	percentA = 100.0 * A_wins / numberRuns;
	percentB = 100.0 * B_wins / numberRuns;
	percentC = 100.0 * C_wins / numberRuns;
	cout.precision(4);
	cout << showpoint;
	cout << "Aaron won " << A_wins << "/" << numberRuns << " truels or " << percentA << "%" << endl;
	cout << "Bob won " << B_wins << "/" << numberRuns << " truels or " << percentB << "%" << endl;
	cout << "Charlie won " << C_wins << "/" << numberRuns << " truels or " << percentC << "%" << endl;
	cout << "\nStrategy 2 is better than strategy 1." << endl;
}
void comparison(){
}















