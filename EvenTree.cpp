// https://www.hackerrank.com/challenges/even-tree

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Calc_Daughters(vector<int> *ver, int *daugh, int n){
    
    daugh[n]=0;
    if(ver[n].size()==0)
        daugh[n]=0;
    else{
        for(int i = 0; i < ver[n].size(); i++){
            daugh[n]+=1+Calc_Daughters(ver, daugh, ver[n][i]);
        }
    }
        
    return daugh[n];
}

int main(){
    //read # of vertices and edges to N and M
    int N, M;
    cin >> N >> M;
    int del_edges=0;
    
    //define a vector to store the daughters of every vertex i, i from 0 to N-1
    //define an array to store the # of daughters for every vertex
    vector<int> vertices[N];
    int daughters[N];
    int edge1, edge2;
    
    for(int i = 0; i < M; i++){
        cin >> edge1 >> edge2;
        edge1--;
        edge2--;
        vertices[edge2].push_back(edge1);
    }
    
    Calc_Daughters(vertices, daughters, 0);
    
    //if # of daughters is odd, return value + 1 
    for(int i = 1; i < N; i++){
        if((daughters[i]+1)%2==0)
            del_edges++;
    }
    
    cout << del_edges << endl;
    return 0;
}

