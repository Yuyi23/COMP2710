//Yueyi Gao
//yzg0032
//hw5_yzg0032.cpp
//I received no help at all.

#include<iostream>
#include<cstdlib>
#include<string>
#include<cassert>
using namespace std;
//#define UNIT_TESTING

struct TriviaNode{
	string question;
	string answer;
	int points;
	TriviaNode *next;
};

class NodeList {
public:
	TriviaNode* head;
	TriviaNode* last;
	int count;
	NodeList() {
		head = NULL;
		last = NULL;
		count = 0;
	}
};

void initialize(NodeList &list);
void addNode(NodeList &list);
int ask(NodeList &list, int num,int &point);
void test();

int main() {
#ifdef UNIT_TESTING
	test();
#else
	NodeList list;
	initialize(list);
	cout << "*** Welcome to Yueyi Gao's trivia quiz game ***"<<endl;
	addNode(list);
	int total = 0;
	for (int i = 1; i <= list.count;i++) {
		int point = 0;
		int check = ask(list, i,point);
		total = total + point;
		cout << "Your total points: " << total<<endl<<endl; 
	}
	cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***"<<endl;
	#endif
	return 0;
}

void initialize(NodeList &list) {
	TriviaNode *q1 = new TriviaNode;
	TriviaNode *q2 = new TriviaNode;
	TriviaNode *q3 = new TriviaNode;
	q1->question = "How long was the shortest war on record? (Hint: how many minutes)";
	q1->answer = "38";
	q1->points = 100;
	q1->next = q2;

	q2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	q2->answer = "Bank of Italy";
	q2->points = 50;
	q2->next = q3;

	q3->question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
	q3->answer = "Tetris";
	q3->points = 20;
	q3->next = NULL;

	list.head = q1;
	list.last = q3;
	list.count = 3;
}

void addNode(NodeList &list) {
	string quit;
	do {
		TriviaNode *q = new TriviaNode;
		cout << "Enter a question: ";
		cin >> q->question;
		cout << "Enter a answer: ";
		cin >> q->answer;
		cout << "Enter award points: ";
		cin >> q->points;
		list.count++;
		list.last->next = q;
		list.last = q;
		cout << "Continue? (Yes/No): ";
		cin >> quit;
	} while (quit == "Yes");
	cout << endl;
}

int ask(NodeList &list, int num, int &point) {
	TriviaNode *current = list.head;
	if (num > list.count) {
		cout << "Warning - There are only three trivia in the list.";
		return 1;
	}
	if (num <= 0) {
		cout << "Warning - The number of trivia to be asked must equal to or large than 1." << endl;
		return 1;
	}
	
	else {
		for (int i = num; i > 1; i--) {
			current = current->next;
		}
		cout << "Question: " << current->question << endl;
		cout << "Answer: ";
		string ans;
		cin >> ans;
		if (current->answer == ans) {
			cout << "Your answer is correct. You recieve "
				<< current->points<<" points."<<endl;
			point = current->points;
			return 0;
		}
		else {
			cout << "Your answer is wrong. The correct answer is: "
				<< current->answer << endl; 
			return 1;
		}
	}
}

void test() {
	cout << "*** This is a debug version ***"<<endl;
	int point;
	NodeList list;
	initialize(list);
	cout << "Unit Test Case 1: Ask no question. The program should give a warning message."<<endl;
	ask(list,0,point);
	cout << endl;

	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer."<<endl;
	int check = ask(list, 1,point);
	assert(check==1);
	cout << "Case 2.1 passed..."<<endl<<endl;

	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters an correct answer." << endl;
	check = ask(list, 3, point);
	assert(check == 0);
	cout << "Case 2.2 passed..." << endl<<endl;

	cout << "Unit Test Case3: Ask the last trivia in the linked list.";
	check = ask(list, 3, point);
	assert(check == 0);
	cout << endl;

	cout << "Unit Test Case 4: Ask five questions in the linked list." << endl;
	ask(list, 5, point);
	cout << endl<<endl;

	cout << "*** End of the Debug Version ***"<<endl;
}