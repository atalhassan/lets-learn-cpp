/*
  C++ uses fstream to read and write files
  In this program a file will be read line by line
  and every line will be streamed by every integer value

  For example

  1 2 3 4
  5 6 7 8 9

  the program will read the first line (1 2 3 4)
  and then every intger in that line

 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int args, char* argv[]){

  if (args != 2){
    cout << "must provide a file; ./a.out <filename>" << endl;
    return 0;
  }


  ifstream inFile;
  inFile.open(argv[1]);

  string line;
  int item;

  getline(inFile,line);
  stringstream  lineStream(line);
  while(lineStream >> item){
    cout << item << endl;
  }

  inFile.close();
  return 1;
}
