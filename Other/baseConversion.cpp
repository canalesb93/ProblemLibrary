/*

*/
#include <iostream>
#include <cmath>

using namespace std;

int digitToValue(char c){
  // Converts char to its int value
  if(c>='0' && c<='9') 
    return c-'0';
  else if(c>='A' &&c<='Z')
    return 10 + c - 'A'; 
  else if (c >= 'a' && c <= 'z') 
    return 10 + c - 'a';
  return -1;
}

char valueToDigit(int val){
  if(val < 10){
    return val + '0';
  } else {
    return (val-10) + 'a';
  }
}

string convertToBaseX(int number, int base){
  string result = "";
  while(number > 0){
    int rem = number % base;
    number /= base;
    result = valueToDigit(rem) + result;
  }
  return result;
}

int convertToBase(string number, int base){
  if(base < 2 || base > 36)
    return -1;
  
  int value = 0;
  for(int i = number.length()-1; i >= 0; i--){
    int digit = digitToValue(number[i]);
    if(digit < 0 || digit >= base)
      return -1;
    int exp = number.length() -1 -i;
    value += digit * pow(base, exp);
  }
  return value;
}



//UGLY VALIDATIONS
int main (){
  string input;

  while(cin >> input){
    int commas = 0;
    int range = 0;
    int last_comma = 0;
    string word;
    int base, to_base;
    bool valid = true;
    for(int i = 0; i < input.size(); i++){
      if(input[i] == ','){
        if(commas == 0){
          word = input.substr(last_comma,range);
          // cout << "WORD: " << word << endl; 
        } else if(commas == 1){
          base = atoi(input.substr(last_comma + 1,range).c_str());
          // cout << "base: " << base << endl; 

        }
         
        last_comma = i;
        commas++;
        range = 0;

      } else {
        range++;
      }
      if(input[i] == '-'){
        valid = false;
        break;
      }
      if(i == input.size() -1){
        to_base = atoi(input.substr(last_comma + 1,range).c_str());
        // cout << "to: " << to_base << endl;
      }
    }
    if(base < 2 || to_base > 36){
      valid = false;
    }
    char base_top = valueToDigit(base);
    for(int i = 0; i < word.size(); i++){
      if(input[i] >= '0' && input[i] <= '9'){
        if(input[i] >= base_top){
          valid = false;
          break;
        }
      } else if(input[i] >= 'a' && input[i] <= 'z'){
        if(input[i] >= base_top){
          valid = false;
          break; 
        }
      } else {
        valid = false;
        break;
      }

    }
    if(valid){
      int baseTen = convertToBase(word, base);
      cout << convertToBaseX(baseTen, to_base) << endl;
    } else {
      cout << "Invalid Input" << endl;
    }


  }  
  return 0;
}