#include <iostream>

using namespace std;

class Student {
public:
  Student(int id_val, int score_val) {
    id = id_val;
    score = score_val;
  }

  Student operator+(Student& s2) {
    Student s3(id, score + s2.score);
    return s3;
  }

  int get_id() {
    return id;
  }

  int get_score() {
    return score;
  }

  friend bool operator<(const Student& s1, const Student& s2);

private:
  int id;
  int score;
};

bool operator<(const Student& s1, const Student& s2) {
  return s1.score < s2.score;
}

int main() {
  Student s1(1, 90);
  Student s2(2, 91);
  if (s1 < s2) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  Student s3 = s1 + s2;
  cout << s3.get_score() << endl;
  return 0;
}
