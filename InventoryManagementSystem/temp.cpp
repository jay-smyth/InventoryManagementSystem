//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <array>
//#include <algorithm>
//#include <string>
//
//using namespace std;
////initialise prototypes
//void inputScore(array< int, 5> &);
//void outputScore(array< int, 5> &);
//int calcScore(array< int, 5> &);
//int finalScore;
//
//int main_1() {
//	array <int, 5> scores;//initialise array scores
//
//	cout << "Please enter 5 Scores now: " << endl;
//	inputScore(scores);//function call 
//	calcScore(scores);//function call
//	cout << "The final score is: " << finalScore << endl;
//}
//
//// function calcScore to sort array scores then find smallest value and deduct from total for return of finalScore
//int calcScore(array <int, 5> &scores) {
//	int temp = scores[0];// Initialise variable temp, holds first element for testing of lowest number
//	int total = 0;// initialise variable and store array Scores total for return to finalScore
//
//	//sort array Scores into lowest to highest
//	for (int &score : scores) {
//		sort(scores.begin(), scores.end());
//	}
//
//	// test array Scores and find the smallest integer element
//	for (int i = 0; i < sizeof(scores) / sizeof(scores[0]); i++) {
//		if (scores[i] < temp) {
//			temp = scores[i];
//		}
//	}
//
//	//total the elements of the array Scores
//	for (size_t y = 0; y < scores.size(); y++) {
//		total += scores[y];
//	}
//
//	finalScore = total - temp; // Take the lowest Score and remove it from the total value of the elements
//	return finalScore;// return final score to the global variable finalScore
//}
//
////Take input from CMD and populate array Scores
//void inputScore(array <int, 5> &scores) {
//	for (int &score : scores) {
//		cin >> score;
//	}
//}
//
////outputScores function to display array scores
///*void outputScore(array <int, 5> &scores) {
//	for (int score : scores) {
//		cout << score << " ";
//	}
//	cout << endl;
//}*/