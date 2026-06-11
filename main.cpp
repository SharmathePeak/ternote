#include <fstream>
#include <iostream>
#include <string>

class Notes {
public:
  std::string date;
  std::string data;

  int newNote() {
    int i = 0;
    std::string line;

    std::ofstream ofile("test.txt", std::ios::app);
    if (!ofile.is_open()) {
      ofile.open("test.txt");
      if (!ofile.is_open()) {
        std::cout << "Cant open file!!" << std::endl;
        return 0;
      }
    }

    std::ofstream mdata("otherdata.txt", std::ios::app);
    if (!mdata.is_open()) {
      mdata.open("otherdata.txt");
      if (!mdata.is_open()) {
        std::cout << "Cant open file!!" << std::endl;
        ofile.close();
        return 0;
      }
    }

    while (std::getline(std::cin, line)) {
      if (line != "end") {
        ofile << line << std::endl;
        i++;
      } else {
        break;
      }
    }

    mdata << i << std::endl;

    mdata.close();
    ofile.close();

    return 1;
  }
  void loadData(int nn) {
    int s_line = 0;
    int linesize = 0;
    std::string line;
    std::ifstream mdata("otherdata.txt");
    std::ifstream ifile("test.txt");

    for (int i = 0; i <= nn - 2; i++) {
      int l = s_line;
      mdata >> s_line >> linesize;
      s_line += l;
    }

    for (int i = 0; i < s_line; i++) {
      std::getline(ifile, line);
    }

    // this->data = "";

    while (std::getline(ifile, line)) {
      data.append(line + "\n");
    }
    std::cout << data;
    mdata.close();
    ifile.close();
  }
  void clearAllData() {
    std::remove("test.txt");
    std::remove("otherdata.txt");
  }
};

int main() {
  Notes n;
  n.clearAllData();
  n.newNote();
  n.newNote();
  n.loadData(2);
  n.clearAllData();
  return 0;
}
