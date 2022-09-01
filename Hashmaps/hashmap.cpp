#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> m;
    // insertion
    // 1
    pair<string, int> p = make_pair("sagar", 1);
    m.insert(p);
    // 2
    pair<string, int> pair2("love", 4);
    m.insert(pair2);
    // 3
    //  single entry for a key  unique key are there in the map
    m["mera"] = 1; // first time creation
    m["mera"] = 2; // for 2nd time it's updation
    // searching
    cout << m["mera"] << endl;
    cout << m.at("mera") << endl;
    cout << m["dind"] << endl; // this will check wheather the key is there, if it's not there then it will create one entry according to it.
    cout << m.at("dind") << endl;
    // size
    cout << m.size() << endl;
    // to check presence
    cout << "sagar is"<<m.count("sadas")<<endl;
    // erase
    m.erase("mera");
    cout << m.size() << endl;
    // traverse
    for (auto i : m)
    {
        cout << i.first << " " << i.second << " \n";
    }
    // we can use iterator
    unordered_map<string, int>::iterator itr = m.begin();
    while (itr != m.end())
    {
        cout << itr->first << " " << itr->second << endl;
        itr++;
    }
    return 0;
}