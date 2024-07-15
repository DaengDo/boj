#include <iostream>
#include <string>
#include <cmath>

typedef struct {
	int sum; // 단어 ascii 합
	int count; // 단어 몇 개 인지
} EachWord;

int main() {
	EachWord* each_words = new EachWord[45];

	// each_words 초기화
	for (int i = 0; i < 45; i++) {
		each_words[i].count = 0;
		each_words[i].sum = 0;
	}

	int tries;
	std::cin >> tries;

	std::string* mean_words = new std::string[tries];

	// 단어 입력 받기
	for (int i = 0; i < tries; i++) {
		std::cin >> mean_words[i];
		const int len = mean_words[i].length();
		// 각 단어의 ascii 코드 저장하기
		for (int j = 0; j < len; j++) {
			each_words[j].sum += mean_words[i][j];
			each_words[j].count += 1;
		}
	}

	// 출력
	for (int i = 0; ; i++) {
		if (each_words[i].count == 0) break;
		std::cout << (char)floor(each_words[i].sum / each_words[i].count);
	}

	return 0;
}