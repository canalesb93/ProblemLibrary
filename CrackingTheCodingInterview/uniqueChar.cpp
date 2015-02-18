#include <iostream>
#include <cmath>

using namespace std;

bool isUnique(string word){
  if(word.length() > 256) 
    return false;

  bool uniq[256] = { false };
  for(int i = 0; i < word.length(); i++){
    int value = (int) word[i];
    if(uniq[value])
      return false;
    uniq[value]=true;
  }
  return true;
}

int main ()
{
  string word1 = "0esthello";
  string word2 = "teshlo";

  cout << isUnique(word1) << endl;
  cout << isUnique(word2) << endl;
  return 0;
}