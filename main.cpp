#include <iostream>
using namespace std;

#include "Double_list.h"

int main() {
	Double_list<int> list;
	Double_list<int> list2;

	cout << "Size:  " << list.size() << " ( = 0 )" << endl;
	cout << "Empty:  " << list.empty() << " ( = 1 )" << endl;

	// start with 1, then try 2, and then 3, etc.

	const int N = 5;
	const int M = 3;

	for ( int i = 0; i < N; ++i ) {
		list.push_front( i );
	}
	for ( int i = 0; i < M; ++i ) {
		list2.push_front( i );
	}
	cout << "before" << endl;
	list2 = list;
	cout << "after" << endl;
	cout << "checking overload" << endl;
	cout << list2;
//	
//	cout << "Size:  " << list.size() << " ( = N )" << endl;
//
//	cout << "Front:  " << list.front()
//	     << " ( = " << (N - 1) << " )" << endl;
//	cout << "Back:  " << list.back() << " ( = 0 )" << endl;
//	
//	for ( int i = N - 1; i >= 0; --i ) {
//		cout << "Pop front: " << list.pop_front()
//		     << " ( = " << i << ")" << endl;
//	}
//	
//	cout << "Size:  " << list.size() << " ( = N )" << endl;
//	
//	for ( int i = 0; i < 5; ++i ) {
//		list.push_front( i );
//	}
//	//cout << list;
//	cout << "Size:  " << list.size() << " ( = N )" << endl;
//	
//	for ( int i = N - 1; i >= 0; --i ) {
//		cout << "Pop back: " << list.pop_back()
//		     << " ( = " << i << ")" << endl;
//	}
//	cout << "Size:  " << list.size() << " ( = N )" << endl;
//
//	cout << list;

	return 0;
}
