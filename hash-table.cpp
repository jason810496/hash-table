#include<bits/stdc++.h>
using namespace std;


const int prime[26] = {
    53,97,193,389,769,
    1543,3079,6151,12289,24593,
    49157,98317,196613,393241,786433,
    1572869,3145739,6291469,12582917,25165843,
    50331653,100663319,201326611,402653189,805306457,
    1610612741
};

class hash_table{
    private:
        int Size , P;
        vector<list<int> > table;
        inline int hash(int k);

    public:
        hash_table(int sz);
        ~hash_table();
        
        void Insert(int k);
        void Delete(int k);
        bool Search(int k);
};

hash_table::hash_table(int sz){
    auto it=lower_bound(prime,prime+26,sz);
    this->P = *it;
    table.resize(sz);
}

hash_table::~hash_table(){

}

inline int hash_table::hash(int k){
    return (k%this->P);
}

void hash_table::Insert(int k){
    int idx=hash(k);
    table[idx].push_back(k);
}

void hash_table::Delete(int k){
    int idx=hash(k);
    
    for(auto it=table[idx].begin();it!=table[idx].end();it++){
        if(*it == k){
            table[idx].erase(it);
        }
    }
}

bool hash_table::Search(int k){
    int idx=hash(k);
    
    for(const auto &i:table[idx]){
        if(i==k) return true;
    }
    return false;
}

int main(){

}