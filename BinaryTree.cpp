#include <iostream>
#include "BST.h"

using namespace std;

int main(){

	cout << "Hello BST" << endl;
	
	/*
	BST<int> OrderCheck;
	OrderCheck.Add(3);
	OrderCheck.Add(5);
	OrderCheck.Add(7);
	OrderCheck.Add(9);
	OrderCheck.Add(5);
	OrderCheck.Print();
	*/

	BST<int>MyTree;
	MyTree.Add(50);
	MyTree.Add(30);
	MyTree.Add(20);
	MyTree.Add(35);
	MyTree.Add(75);
	MyTree.Add(60);
	MyTree.Add(80);
	MyTree.Add(79);
	MyTree.Add(99);

	//cout << "Tree Size" << endl;
	//cout << MyTree.GetSize() << endl;

	cout << "In Order" << endl;
	MyTree.Print();
	cout << endl;

	cout << "Reverse Order Print" << endl;
	MyTree.RPrint();
	cout << endl;
	/*
	BST<string> BinaryTree;

	BinaryTree.Add("Some Website");
	BinaryTree.Add("Another site");
	BinaryTree.Add("Different site");
	
	cout << "In Order" << endl;
	BinaryTree.Print();
	cout << endl << endl;

	cout << "Tree Order Print" << endl;
	BinaryTree.TPrint();
	cout << endl << endl;

	cout << "Reverse Order Print" << endl;
	BinaryTree.RPrint();
	*/
	return 0;
}
