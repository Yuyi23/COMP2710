//Yueyi Gao
//yzg0032
//hw3_yzg0032.cpp
//I received no help at all.

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include<ctime>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive */
/* B_alive indicates whether Bob is alive */
/* C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */

void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/

void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change C_alive into false if Charlie is killed.
*/

void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* B_alive indicates whether Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change B_alive into false if Bob is killed.
*/

void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/

void test_at_least_two_alive(void);

//Constants
const int TOTAL = 10000;
const int APRO = 33;
const int BPRO = 50;
const int CPRO = 100;

int main() {
	srand(time(0));
	cout << "*** Welcome to the Duel Simulator ***"<<endl;
	test_at_least_two_alive(); //Test function
	cout << "Press Enter to continue...";
	cin.get(); //Pause Command for Linux Terminal
	cout << "Ready to test strategy 1 (run 10000 times):"<<endl;
	cout << "Press Enter to continue...";
	cin.get(); //Pause Command for Linux Terminal

	//Stratege 1
	int a_times = 0;
	int b_times = 0;
	int c_times = 0;
	for (int i = 0; i < TOTAL;i++) {
		bool a_alive = true;
		bool b_alive = true;
		bool c_alive = true;
		while (at_least_two_alive(a_alive, b_alive, c_alive)) {
			if (a_alive == true) {
				Aaron_shoots1(b_alive, c_alive);
			}
	        if (b_alive == true) {
				Bob_shoots(a_alive, c_alive);
			}
			if (c_alive == true) {
				Charlie_shoots(a_alive, b_alive);
			}
		}
		if (a_alive==true) {
			a_times++;
		}
		else if (b_alive==true) {
			b_times++;
		}
		else {
			c_times++;
		}
	}
	double a_prob = ((double)(a_times) / TOTAL) * 100;
	double b_prob = ((double)(b_times) / TOTAL) * 100;
	double c_prob = ((double)(c_times) / TOTAL) * 100;
	cout << "Aaron won " << a_times << "/10000 duels or " << a_prob << "%" << endl;
	cout << "Bob won " << b_times << "/10000 duels or " << b_prob << "%" << endl;
	cout << "Charlie won " << c_times << "/10000 duels or " << c_prob << "%" << endl<<endl;
	
	//Stratege 2 
	cout << "Ready to test strategy 2 (run 10000 times):"<<endl;
	cout << "Press Enter to continue...";
	cin.get(); //Pause Command for Linux Terminal
	int a_times2 = 0;
	int b_times2 = 0;
	int c_times2 = 0;
	for (int i = 0; i < TOTAL; i++) {
		bool a_alive = true;
		bool b_alive = true;
		bool c_alive = true;
		while (at_least_two_alive(a_alive, b_alive, c_alive)) {
			if (a_alive == true) {
				Aaron_shoots2(b_alive, c_alive);
			}
			if (b_alive == true) {
				Bob_shoots(a_alive, c_alive);
			}
			if (c_alive == true) {
				Charlie_shoots(a_alive, b_alive);
			}
		}
		if (a_alive == true) {
			a_times2++;
		}
		else if (b_alive == true) {
			b_times2++;
		}
		else {
			c_times2++;
		}
	}
	a_prob = ((double)(a_times2) / TOTAL) * 100;
	b_prob = ((double)(b_times2) / TOTAL) * 100;
	c_prob = ((double)(c_times2) / TOTAL) * 100;
	cout << "Aaron won " << a_times2 << "/10000 duels or " << a_prob << "%" << endl;
	cout << "Bob won " << b_times2 << "/10000 duels or " << b_prob << "%" << endl;
	cout << "Charlie won " << c_times2 << "/10000 duels or " << c_prob << "%" << endl<<endl;

	if (a_times > a_times2) {
		cout << "Strategy 1 is better than strategy 2."<<endl;
	}
	else {
		cout << "Strategy 2 is better than strategy 1."<<endl;
	}
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if (A_alive == true && B_alive == true) {
		return true;
	}
	else if (A_alive == true && C_alive == true) {
		return true;
	}
	else if (B_alive == true && C_alive == true) {
		return true;
	}
	else {
		return false;
	}
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
	int shoot_target_result = rand() % 100;
	if (shoot_target_result <= APRO) {
		if (C_alive == true) {
			C_alive = false;
		}
		else {
			B_alive = false;
		}
	}
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
	int shoot_target_result = rand() % 100;
	if (shoot_target_result <= BPRO) {
		if (C_alive == true) {
			C_alive = false;
		}
		else {
			A_alive = false;
		}
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
	int shoot_target_result = rand() % 100;
	if (shoot_target_result <= CPRO) {
		if (B_alive == true) {
			B_alive = false;
		}
		else {
			A_alive = false;
		}
	}
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	if (B_alive == true && C_alive == true) {
		return;
	}
	else {
		int shoot_target_result = rand() % 100;
		if (shoot_target_result <= APRO) {
			if (C_alive) {
				C_alive = false;
			}
			else {
				B_alive = false;
			}
		}
	}
}

void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";

	cout << "	Case 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "	Case passed ...\n";

	cout << "	Case 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "	Case passed ...\n";

	cout << "	Case 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "	Case passed ...\n";

	cout << "	Case 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "	Case passed ...\n";

	cout << "	Case 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "	Case passed ...\n";

	cout << "	Case 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "	Case passed ...\n";

	cout << "	Case 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "	Case passed ...\n";

	cout << "	Case 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "	Case passed ...\n";
}