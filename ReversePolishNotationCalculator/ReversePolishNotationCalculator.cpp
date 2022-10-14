#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string input;
	stack<float> stack; // USE VECTOR !!
	int prevNum = 0;
	while (true) {
		cin >> input;
		if (input == "q") break;
		if (input.rfind('n', 0) == 0) { // starts with 'n'
			if(!stack.empty())
				prevNum = stack.top(); // save top element before adding new
			input.erase(0, 1);
			float num = stoi(input);
			stack.push(num);
		}
		else if (input == "d") {
			if (!stack.empty())
				stack.pop();
		}
		else if (input == "+") {
			float sum = prevNum + stack.top();
			prevNum = stack.top();
			stack.push(sum);
			cout << sum << endl;
		}
		else if (input == "-") {
			float diff = prevNum - stack.top();
			prevNum = stack.top();
			stack.push(diff);
			cout << diff << endl;
		}
		else if (input == "*") {
			float mul = prevNum * stack.top();
			prevNum = stack.top();
			stack.push(mul);
			cout << mul << endl;
		}
		else if (input == "/") {
			float div = prevNum / stack.top();
			prevNum = stack.top();
			stack.push(div);
			cout << div << endl;
		}
	}
}