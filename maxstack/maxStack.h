#ifndef MAXSTACK_H
#define MAXSTACK_H
#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

class MaxStack
{
	private:
		vector<int> theStack;
		vector<int> theMaxStack;

	public:
		bool empty() const;
		int size() const;
		int top() const;
		void push(int);
		void pop();
		int max() const;
		friend ostream& operator<<(ostream &, const MaxStack &);
};
#endif
