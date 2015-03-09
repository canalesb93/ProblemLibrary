/*
abc
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

void permute(string select, string remain){
  if(remain == ""){
    cout << select << endl;
    return;
  }
  for(int i=0;remain[i];++i){
    string wk = remain;//"" + ab c
    permute(select + remain[i], wk.erase(i, 1));
  }
}

int main(){
  string anagram;
  cout << "input character set:\n";
  cin >> anagram;
  sort(anagram.begin(), anagram.end());
  permute("", anagram);
}