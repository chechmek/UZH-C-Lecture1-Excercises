#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string input;
	int last_index;
	vector<float> stack; 
	while (true) {
		cin >> input;
		last_index = stack.size() - 1;
		if (input == "q") break;
		if (input == "n") {
			cin >> input;
			float num = stoi(input);
			stack.push_back(num);
		}
		else if (input == "d") {
			if (!stack.empty())
				stack.pop_back();
		}
		else if (stack.size() < 2) {
			continue;
		}
		else if (input == "+") {
			float res = stack[last_index - 1] + stack[last_index];
			stack.push_back(res);
			cout << res << endl;
		}
		else if (input == "-") {
			float res = stack[last_index - 1] - stack[last_index];
			stack.push_back(res);
			cout << res << endl;
		}
		else if (input == "*") {
			float res = stack[last_index - 1] * stack[last_index];
			stack.push_back(res);
			cout << res << endl;
		}
		else if (input == "/") {
			float res = stack[last_index - 1] / stack[last_index];
			stack.push_back(res);
			cout << res << endl;
		}
	}
}