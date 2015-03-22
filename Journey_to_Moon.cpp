// https://www.hackerrank.com/challenges/journey-to-the-moon
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

int dfs(vector<vector<int> > &p, vector<int> &v, int i){
    int returnvalue=0;
    for(vector<int>::iterator it=p[i].begin();it!=p[i].end();it++){
        if(v[*it]==0){
        v[*it]=1;
        returnvalue+=dfs(p, v, *it);
        }

    }
    return returnvalue+1;
}

int main()
{
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    long long result = 0;
    long long sum = 0;
    vector<int> visited(N,0);
    int count;

    /** Write code to compute the result using N,I,pairs **/
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            if(pairs[i].empty())
                count=1;
            else if(!pairs[i].empty()){
                visited[i]=1;
                count=dfs(pairs, visited, i);
            }
            result += sum*count;
            sum += count;
        }
    }


    cout << result << endl;
    return 0;
}
