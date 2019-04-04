#include <iostream>
// map: ordered key-value pairs, set: ordered keys
// multimap/multiset: same key, differnt val
// unordered may/set: store with hash maps
#include<map>
#include<set>
#include<iterator>
#include<vector>
#include<string>
#include<utility>
using namespace::std;
int main(){
    map<string,size_t>word_count;// string: key, size_t:val
    set<string> exclude={"the", "a"};// list initialize
    istream_iterator<string> i_iter(cin),eof;
    vector<string> wordIn(i_iter, eof);
    for(auto &word:wordIn){
        if (exclude.find(word)==exclude.end())
            ++word_count[word];// access value and increase by 1
    }
// use the iterator for map
    auto wordIt=word_count.begin();
    while (wordIt!=word_count.end()) {
        cout<<wordIt->first<<" "
           <<wordIt->second<<endl;
    }
// -------------------------------------------
//  Ex 11.12, store a pair into vector   
    vector<int> v1{1,3,6};
    vector<string>  v2{"Bob","Mary","Jack"};
    vector<pair<int,string>> vpair;// template of type with <>
    for (int i=0;i!=v1.size();++i){
// create pairs in three ways
        vpair.push_back({v1[i],v2[i]});
    }
//      vpair.push_back(make_pair(v1[i],v2[i]));
//      vpair.push_back(pair<int, string>(v1[i],v2[i]));
    for(const auto &p:vpair)
        cout<<p.first<<" "<<p.second<<endl;
//--------------------------------------------
// cound tht occured times using iterator
    map<string,size_t> wordCountNew;
    for (auto &word:wordIn){
// ret: {iterator to the pair in map, boolean isInsert}
        auto ret=wordCountNew.insert({word,1});
        if(!ret.second)// if word is not inserted
            ++ret.first->second;//++((ret.first)->second)
    }
    return 0;
}
