#include <iostream>
#include <string>
#include <stack>

bool isVPS (std::string input) {
  int len = input.length();
  std::stack<char> s;

  for (int i = 0; i < len; i++) {
    if (input[i] == '(') {
      s.push(input[i]);
    } else if (input[i] == ')') {
      if (s.empty()) return false;
      s.pop();
    }
  }
  
  return s.empty();
}

int main () {
  int N;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;

    if (isVPS(s)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    };
  }

  return 0;
}