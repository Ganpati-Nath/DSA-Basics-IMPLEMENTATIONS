#include <bits/stdc++.h>

using namespace std;

int main(){

    unordered_map<string, int> map;

    // add a value...
    // method 01...

    pair<string, int> p1 = make_pair("BMW", 10);
    map.insert(p1);

    // method 02...

    pair<string, int> p2("Maruti 800", 20);
    map.insert(p2);

    // method 03...

    map["Fortuner"] = 30; // I think it will be the best method of add a value in a hashmap out of 3 methods which are written on above...

    // access a value...
    // method 01...

    cout << map["BMW"] << endl; // I think it will be the best method of add a value in a hashmap out of 3 methods which are written on above...

    // method 02...

    cout << map.at("Fortuner") << endl;

    // search a value...
    // method 01...

    cout << map.count("Maruti 800") << endl;

    // method 02...
    // find() function always returns iterator...

    if(map.find("BMW") != map.end()){ // I think it will be the best method of add a value in a hashmap out of 2 methods which are written on above...

        cout << "Found..." << endl;

    }
    else{

        cout << "Not Found !..." << endl;

    }

    // printing...

    for(auto &i : map){

        cout << i.first << " ---->  " << i.second << endl;
        
    }

    return 0;
}