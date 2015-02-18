#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> permutations(string s){
  vector<string> myStrings;
  int len = s.length();
  char lastChar = s[len-1];

  if (len <= 1){
    myStrings.push_back(s);
    return myStrings;
  }

  string nolast = s.erase(len-1);
  vector<string> otherStrings = permutations(nolast);
  for (int i = 0; i < otherStrings.size(); i++){
    string str = otherStrings[i];
    for(int j = 0; j <= str.length(); j++){
      string newStr = str;
      newStr.insert(j, 1, lastChar);
      myStrings.push_back(newStr);
    } 
  }

  return myStrings;
}

int main ()
{
  string myString = "abcc";
  vector<string> answer = permutations(myString);
  for(int i = 0; i < answer.size();i++)
    cout << answer[i] << endl;
  cout << "Amounts to " << answer.size() << " permutations." << endl;
  return 0;
}