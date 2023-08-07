#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<pair<int,int>>mergelist(vector<pair<int,int>>&records)
{
    map<int,int>merged_maps;
    for(const auto& record:records)
    {
        merged_maps[record.first]+=record.second;
    }
    vector<pair<int,int>>result;
    for(const auto& merged_map:merged_maps)
    {
        result.emplace_back(merged_map);
    }

    return result;
}
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>record;
    for(int i= 0;i<n;i++){
        int first, second;
        cin>>first>>second;
        record.emplace_back(first,second);
    }
    vector<pair<int,int>>result=mergelist(record);
    for(const auto& res:result)
    {
        cout<<res.first<<" "<<res.second<<endl;
    }

}