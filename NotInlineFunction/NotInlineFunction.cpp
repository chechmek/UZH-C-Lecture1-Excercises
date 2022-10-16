#include <iostream>

// Although function is marked as inline, compoler won`t inline it because it is recursive
// Besides, the function does not return a value but return statement exists
inline void recursiveFunction(int a) {
	if (a == 0)
		return;
	std::cout << a << std::endl;
	recursiveFunction(a - 1);
}

int main()
{
	recursiveFunction(15);
}

