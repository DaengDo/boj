#include <iostream>
#include <stack>

int main() {
	int tries;
	std::cin >> tries;

	std::stack<int> budget;

	for (int i = 0; i < tries; i++) {
		int temp;
		std::cin >> temp;

		if (temp == 0) {
			if (budget.empty()) continue;
			budget.pop();
		}
		else {
			budget.push(temp);
		}
	}

	int result = 0;
	while (!budget.empty()) {
		result += budget.top();
		budget.pop();
	}

	std::cout << result;

	return 0;
}