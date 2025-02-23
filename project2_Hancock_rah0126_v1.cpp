//	Ronnie Hancock
//	904159448
//	project2_Hancock_rah0126_v1.cpp
//	g++ project2_Hancock_rah0126_v1.cpp -o output
//	./output

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <random>
#include <ctime>


using namespace std;


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
	if((C_alive == true) && (rand() % 100 <= 33)){
		C_alive = false;
	}else if((B_alive == true) && (rand() % 100 <= 33)){
		B_alive = false;
	}
}
void Aaron_shoots2(bool& B_alive, bool& C_alive){
	if(Aaron_first_turn == true){
		Aaron_first_turn = false;
	}else if((C_alive == true) && (rand() % 100 <= 33)){
		C_alive = false;
	}else if((B_alive == true) && (rand() % 100 <= 33)){
		B_alive = false;
	}
}
void Bob_shoots(bool& A_alive, bool& C_alive){
	if((C_alive == true) && (rand() % 100 <= 50)){
		C_alive = false;
	}else if((A_alive == true) && (rand() % 100 <= 50)){
		A_alive = false;
	}
}
void Charlie_shoots(bool& A_alive, bool& B_alive){
	if(B_alive == true){
		B_alive = false;
	}else if(A_alive == true){
		A_alive = false;
	}
}