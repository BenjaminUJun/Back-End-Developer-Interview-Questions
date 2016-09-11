#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int fun(vector<int> m){
    int size = m.size();
    int result;
    if(size==0) return 0;
    if(size==1) return m.front();
    if(size%2==0){
        int a,b;
        a=b=0;
        for(int i =0;i<size;i++){
            if(i%2==0) a+=m.at(i);
            else b+=m.at(i);
        }
        result = max(a,b);
    }else{
        int a,b,c;
        a=b=c=0;
        for(int i =0;i<size-1;i++){
            if(i%2==0) a+=m.at(i);
            else b+=m.at(i);
        }
        if(m.front() < m.back()) a=a-m.front()+m.back();
        result = max(a,b);
    }
    return result;
}

int main(){
    int n,tmp,result;
    char ch;
    string line,str;
    vector<int> m;
    cin>>n;
    cin.get();
    for(int i =0;i<n;i++){
        getline(cin,line);
        line+=',';
        istringstream in(line);
        while(getline(in,str,',')){
            m.push_back(atoi(str.c_str()));
        }
        
        cout<<fun(m)<<endl;
        m.clear();
    }
    return 0;
}