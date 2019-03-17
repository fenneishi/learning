#include <string>
#include <iostream>

using namespace std;
void pha(string &str);
bool plalindrome(const string &str); //const和引用式能用就用。
int main(int argc, char const *argv[])
{
    string str;
    cout << "input a plalindrome:";
    getline(cin, str);
    pha(str);
    plalindrome(str);
    if (false != plalindrome(str))
    {
        cout << "\"" << str << "\""
             << " is a plalindrome" << endl;
    }
    else
    {
        cout << "\"" << str << "\""
             << " is not plalindrome" << endl;
    }
    return 0;
}

bool plalindrome(const string &str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    if (str == temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void pha(string &str)
{
    string temp;
    for(int i=0;i<str.size();i++)
    {
        if(false!=isalpha(str[i]))
            {
                temp+=str[i];
            }
    }
    str=temp;
}