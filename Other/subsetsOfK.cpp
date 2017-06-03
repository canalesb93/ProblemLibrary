#include<iostream>
#include<string>
#include<vector>

using namespace std;

void print( vector<int> l){
    for(int i = 0; i < l.size(); i++)
            cout << " " << l[i];
    cout<<endl;
}

void subset(vector<int> arr, int left, int index, vector<int> l){
    if(left==0){
        print(l);
        return;
    }
    for(int i=index; i<arr.size();i++){
        vector<int> newList = l;
        newList.push_back(arr[i]);
        subset(arr,left-1,i+1,newList);
    }

}     

int main(){
    int array[4]={1,2,3,4};
    vector<int> myarr(array, array + sizeof(array) / sizeof(int));
    vector<int> v;
    subset(myarr,3,0,v);


    return 0;
}