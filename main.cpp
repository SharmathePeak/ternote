#include <cstdio>
#include <fstream>
#include <iostream>
// #include <iterator>
#include <string>
#include <vector>

class Notes {
public:
  std::string data;

  int newNote() {
    std::string line;

    std::ofstream ofile("test.txt", std::ios::app);
    if (!ofile.is_open()) {
      ofile.open("test.txt");
      if (!ofile.is_open()) {
        std::cout << "Cant open file!!" << std::endl;
        return 0;
      }
    }

    while (std::getline(std::cin, line)) {
      if (line == "end")
        break;
      data += line + '\n';
    }
    ofile << "--NOTE--\n";
    ofile << data;

    ofile.close();

    return 1;
  }

  void loadData(int nn) {
    int i = 0;
    std::string line;
    std::ifstream ifile("test.txt");
    while (std::getline(ifile, line)) {
      if (line == "--NOTE--") {
        i++;
      } else if (i == nn) {
        std::cout << line << std::endl;
      }
    }
  }
};

void clearAllData() { std::remove("test.txt"); }

void delNote(std::vector<Notes> &n, int i) {
  int line = 0;
  n.erase(n.begin() + i);
  std::ofstream ofile("test.txt", std::ios::trunc);
  for (auto &note : n) {
    ofile << "--NOTE--\n";
    ofile << note.data;
  }
}

void addNote(std::vector<Notes> &n) {
  n.emplace_back();
  n.back().newNote();
}

int main() {
  std::vector<Notes> n;
  clearAllData();
  addNote(n);
  addNote(n);
  addNote(n);
  std::cout << n[1].data;
  delNote(n, 1);
  std::cout << n[1].data;
  return 0;
}
