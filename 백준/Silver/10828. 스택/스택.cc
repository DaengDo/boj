#include <iostream>
#include <stack>
#include <string>

int main () {
  int N;
  std::cin >> N;
  std::stack<int> s;

  for (int i = 0; i < N; i++) {
    std::string command;
    std::cin >> command;

    if (command == "push") {
      int temp;
      std::cin >> temp;
      s.push(temp);
      continue;
    }

    if (command == "pop") {
      if (s.empty()) {
        std::cout << -1;
      } else {
        std::cout << s.top();
        s.pop();
      }
    } else if (command == "size") {
      std::cout << s.size();
    } else if (command == "empty") {
      std::cout << s.empty();
    } else if (command == "top") {
      if (s.empty()) {
        std::cout << -1;
      } else {
        std::cout << s.top();
      }
    }

    std::cout << '\n';
  } 

  return 0;
}