#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
  int x;
  int y;
};

bool compare (Point p1, Point p2) {
  if (p1.x == p2.x) {
    return p1.y < p2.y;
  }
  return p1.x < p2.x;
}

int main () {
  int length;
  std::cin >> length;

  Point* points = new Point[length];

  for (int i = 0; i < length; i++) {
    Point temp;
    std::cin >> temp.x >> temp.y;
    points[i] = temp;
  }

  std::sort(points, points + length, compare);

  for (int i = 0; i < length; i++) {
    std::cout << points[i].x << ' ' << points[i].y << '\n';
  }

  return 0;
}