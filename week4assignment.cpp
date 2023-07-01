// cassian
// 10/2/2022
// week 4 assignment: stack implementation

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class stackSentence //declare class
{
private:
	int maxSize; // declare size of stack
	vector<char> stackVect; // create vector
	int top;
public:

	stackSentence(int x) : maxSize(x), top(-1) // constructor
	{
		stackVect.resize(maxSize); 
	}

	void push(char y) // insert item on top
	{
		stackVect[++top] = y; // increment
	}

	char pop() // get item from top
	{
		return stackVect[top--]; // decrement
	}

	char peek() // peek at top
	{
		return stackVect[top];
	}

	bool isEmpty() // true if stack = empty
	{
		return (top == -1);
	}
};

class Reverser
{
private:
	string input;
	string output;
public:

	Reverser(string in) : input(in)
	{}

	string getRev() // method to reverse stack
	{
		int stackSize = input.length(); // get length
		stackSentence theStack(stackSize); // make stack with stack size set to input length

		for (int y = 0; y < input.length(); y++) // as long as input length is > 0, loop through each letter
		{
			char c = input[y]; // assign variable c to input char
			theStack.push(c); // add letter to stack
		}
		output = "";
		while (!theStack.isEmpty()) 
		{
			char c = theStack.pop(); // get top item
			output = output + c; // append to output
		}
		return output;
	}
};
int main()
{
	string input, output;
	cout << "Enter a sentence: "; // prompt for input
	while (true)
	{
		getline(cin, input);
		if (input.length() < 2) 
			break;

		Reverser RevSentence(input); // create class object
		output = RevSentence.getRev(); // call reverse method

		cout << output << " "; // print result
	}
	return 0;
}
