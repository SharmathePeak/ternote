#include <cstdio>
#include <fstream>
#include <iostream>
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
};

void initNotes(std::vector<Notes> &n) {
  std::ifstream ifile("test.txt");
  std::string line;
  while (std::getline(ifile, line)) {
    if (line == "--NOTE--") {
      n.emplace_back();
    } else {
      n.back().data += line + '\n';
    }
  }
}

void loadAllData() {
  int i = 0;
  int fl = false;
  std::string line;
  std::ifstream ifile("test.txt");
  while (std::getline(ifile, line)) {
    if (line == "--NOTE--") {
      fl = false;
      i++;
    } else {
      if (fl == false) {
        std::cout << i << "." << line << std::endl;
        fl = true;
      }
    }
  }
}

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

void loadData(std::vector<Notes> &n, int nn) {
  if (nn < n.size()) {
    std::cout << n[nn].data;
  }
}

int main() {
  std::vector<Notes> n;
  // clearAllData();
  initNotes(n);
  addNote(n);
  addNote(n);
  loadData(n, 1);
  delNote(n, 1);
  loadData(n, 1);
  loadAllData();
  return 0;
}
