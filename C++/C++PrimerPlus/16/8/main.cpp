#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    set<string> matFriend;
    set<string> patFriend;
    set<string> comFriend;

    string name; 
    cout<<"input mat friend name(\"quit\" to  quit!):";
    while(cin>>name&&name!="quit")
    {
        matFriend.insert(name);
    }
    for(auto x:matFriend)cout<<x<<" ";
    cout<<endl;

    cout<<"input pat friend name(\"quit\"  to quit!):";
    while(cin>>name&&name!="quit")
    {
        patFriend.insert(name);
    }
    for(auto x:patFriend)cout<<x<<" ";
    cout<<endl;

    comFriend.insert(matFriend.begin(),matFriend.end());
    comFriend.insert(patFriend.begin(),patFriend.end());
    for(auto x:comFriend)cout<<x<<" ";
    cout<<endl;
    

    return 0;
}
