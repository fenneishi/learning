// hangman.cpp -- some string methods
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
using namespace std;
const int NUM=0;

int main()
{

    // 打开文件
    ifstream fin;
    fin.open("word");
    if(fin.is_open()==false)
        {
            cerr<<"can't open file. Bye.\n";
            exit(EXIT_FAILURE);
        }
    
    // 录入数据
    vector<string> wordlist;
    while(fin)
    {
        string temp;
        fin>>temp;
        wordlist.push_back(temp);
    }

    // 输入的情况检查一下
    // g++ -std=c++11  hangman.cpp
    for(auto &x:wordlist)
    {
        cout<<x<<":"<<x.length()<<"::";
        for(auto &i:x)
        {
            cout<<i<<",";
        }
        cout<<endl;
    }

    // 进行游戏
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % wordlist.size()];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout<< "---------------------------------------------"<<endl;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                    continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc]=letter;
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc]=letter;
                    loc = target.find(letter, loc + 1);
                }
           }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);

        cout<<"                        "<<endl;
        cout<<"                        "<<endl;
        cout<<"                        "<<endl;
        cout<<"                        "<<endl;
    }


    // 游戏结束
    cout << "Bye\n";
    fin.close();

    
    return 0; 
}
