// Copyright 2023 fschein
// file i/o examples
#include<iostream>
#include<fstream>  // library for file stream i/o (ofstream, ifstream)
using std::ifstream;  // input file stream
using std::ofstream;  // output file stream
using std::cout;
using std::endl;

int main() {
  // opens a file or creates a file for output
  // by default the file will be overwritten,
  // send std::ofstream::app as the second argument to append
  // (add to the end of the file) if needed
  ofstream my_output_file.open("my-output.txt", std::ofstream::app);
  // the output file stream object can be used like cout
  my_output_file << "Hello World!" << endl;
  
  ifstream bingo("bingo.txt");
  char col;
  int num;
  bingo >> col >> num;
  while( bingo.good() ) {
    cout << col << "-" << num << endl;
    bingo >> col >> num;
  }
  bingo.close();

  int x, count = 0, sum = 0;
  ifstream my_input_file("some-numbers.txt");
  my_input_file >> x;
  while ( my_input_file.good() ) {
    sum += x;
    ++count;
    cout << x << endl;
    my_input_file >> x;
  }
  cout << "The average of the values in the file is "
       << static_cast<double>(sum) / count << endl;
  my_input_file.close();

  return 0;
}