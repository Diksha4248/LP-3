#include<bits/stdc++.h>
using namespace std;

bool compare( pair <int,int> p1, pair<int,int> p2){
    int v1 = (double) p1.first;
    int v2 = (double) p2.first;

    return v1>v2;
}

int main()
{
    int n;
    cout<<"Enter number of jobs : ";
    cin>>n;
    
    vector < pair <int,int>> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;    //(profit, dealine pair)
    }

    sort(v.begin(),v.end(), compare);  // sort based on a custom function (which sorts based on profits)

    int max_deadline = 0;
    for(int i=0;i<n;i++){
        if(v[i].second>max_deadline) max_deadline = v[i].second;
    }

    int timeslots[max_deadline] = {-1};
    int filledtimeslots=0;
    for(int i=1;i<n;i++) // for all jobs
    {
        for(int j = min(max_deadline,v[i].second);j>=0;j--)  // for moving backwards
        {
            if(timeslots[j]==-1){
                timeslots[j] = i-1;
                filledtimeslots++;
                break;
            }
        }

        //if all time slots are filled then stop
        if(filledtimeslots == max_deadline) {
        break;
    }

    int max_profit = 0;
    for(int i=0;i<max_deadline;i++){
        max_profit += v[timeslots[i]].first;
    }


    cout<<max_profit;
    return 0;
}

}