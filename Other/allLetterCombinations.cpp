/*
91919191919191919191919191919191919191919191919191919191919191919191
*/



#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int calls = 0;

char convertToLetter(string letter){
  int num = 0;
  if(letter.size() > 1)
    num = (letter[1]  - '0') + (letter[0] - '0') * 10;
  else 
    num = (letter[0] - '0');
  if(num <= 26) return (char)(num -1 + 'a');
  else return '0';
}

void generateWords(string number,unsigned int index, string word, vector<string> &bank){
  calls++;
  if(index == number.size()){
    bank.push_back(word);
    return;
  }
  
  char c = convertToLetter(number.substr(index, 1));
  if(c != '0'){
    generateWords(number, index + 1, word + c, bank);
  }
  
  if(index < number.size() - 1){
    c = convertToLetter(number.substr(index, 2));
    if(c != '0'){
      generateWords(number, index + 2, word + c, bank);
    }
  }
    
}

vector<string> generatePossibleWords(string number){
  vector<string> results;
  generateWords(number, 0, "", results);
  return results;
}


int main() {
  vector<string> result;
  result = generatePossibleWords("91919191919191919191919191919191919191919191919191919191919191919191");
  for(unsigned int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;
  cout << endl << calls << endl;
  
  return 0;
}