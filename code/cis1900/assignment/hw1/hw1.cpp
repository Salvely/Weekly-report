#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class complex {
private:
  double real, imag;

public:
  complex() : real{0}, imag{0} {}
  complex(double r, double i) : real{r}, imag{i} {}
  // a = b + c -> a = b.+(c) returns a new complex
  complex operator+(const complex &c) {
    double new_real = this->real + c.real;
    double new_imag = this->imag + c.imag;
    return complex(new_real, new_imag);
  }
  // a += b -> a.+=(b) returns the new a itself
  complex &operator+=(const complex &c) {
    this->real += c.real;
    this->imag += c.imag;
    return *this;
  }
  friend istream &operator>>(istream &is, complex &c);
  friend ostream &operator<<(ostream &os, const complex &c);
};

istream &operator>>(istream &is, complex &c) {
  string str1, str2, str3;
  is >> str1 >> c.real >> str2 >> c.imag >> str3;
  if (is.fail()) {
    is.setstate(ios_base::failbit);
  }
  return is;
}
ostream &operator<<(ostream &os, const complex &c) {
  os << "{r: " << c.real << " i: " << c.imag << "}" << endl;
  return os;
}
int main() {
  cerr << "enter 0 to read from stdin or 1 to read from a file" << endl;
  int choice;
  while (true) {
    cin >> choice;
    if (!cin.fail() && (choice == 0 || choice == 1)) {
      break;
    }
  }
  complex sum;
  if (choice == 0) {
    complex c;
    while (true) {
      cin >> c;
      if (cin.fail()) {
        break;
      }
      cout << c + complex({1, 1});
      sum += c;
    }
  } else {
    std::string filename;
    cin >> filename;
    ifstream ifs(filename);
    if (!ifs.is_open()) {
      cerr << "File could not be opened!" << endl;
      return 0;
    }
    complex c;
    string line;
    while (getline(ifs, line)) {
      istringstream is(line);
      is >> c;
      if (is.fail()) {
        cerr << "Complex format invalid!" << endl;
        break;
      }
      cout << c + complex({1, 1});
      sum += c;
    }
  }
  cout << sum;
}
