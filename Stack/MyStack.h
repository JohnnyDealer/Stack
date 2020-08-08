#pragma once

#include <stack>
#include <iostream>

using namespace std;

class MyStack
{
private:
	int N_op = 0;
	stack <int> Stack;
	int iterator = 0;
	size_t size = 0;
public:
	MyStack();
	~MyStack();
    void Pop();
	void Push(int &a);
	int Top();
	bool Empty();
	int Size();
	void ShowAllElements();
	void BinaryInsertionSort();
	void Sort();
	int Get(int& index);
	void Randomize(int& amount_of_elements);
	void Clear();
	void Sort_Optimized();
	void Insert(int& index, int& value);
};

