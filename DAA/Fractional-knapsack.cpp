#include<bits/stdc++.h>
using namespace std;

bool compare( pair <int,int> p1, pair<int,int> p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1>v2;
}


int main(){
    int n;
    cin>>n;
    vector < pair <int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(), compare);  // sort based on a custom function (which is the value/weight method)

    int W; // capacity
    cin>>W;

    int profit = 0;
    for (int i=0;i<n;i++){
        if(v[i].second <= W){
            profit += v[i].first; 
            W -= v[i].second;
            continue;
        }

        // agar aisa nahi hua toh value baat lenge

        double weight_ratio = (double) v[i].first/v[i].second;
        profit += W* weight_ratio;
        W = 0; // which is W -= V[i].second which is zero in this case
    }

    cout<<profit<<endl;

    return 0;
}