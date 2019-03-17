// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Review {
    string title;
    int rating;
    int price;
};

//函数对象，相当于可配置的函数
class SortBook
{
private:
    string type;
public:
    SortBook():type("title"){};
    SortBook(const string &ttype):type(ttype){};
    virtual ~SortBook(){};
    bool operator()(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2) const ;
};
bool SortBook::operator()(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2) const
{
    if(type=="original")
        return true;
    if(type=="title"&&(r1->title < r2->title))
        return true;
    if(type=="rating"&&(r1->rating < r2->rating))
        return true;
    if(type=="price"&&(r1->price < r2->price))
        return true;
    return false;
}



bool FillReview(shared_ptr<Review> &rr);
void ShowReview(const shared_ptr<Review> & rr);
void TypeShow(const vector<shared_ptr<Review> > &books,const string type);

int main()
{
    //书柜
    vector<shared_ptr<Review> > books;

    // 填充书柜
    shared_ptr<Review> temp;
    while (FillReview(temp))
        books.push_back(temp);
    

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "<< books.size() << " ratings:\n";
        cout<<"please inpute the type of show:"<<endl;
        cout<<"\"title\":Sorted by title"<<endl;
        cout<<"\"rating\":Sorted by rating"<<endl;
        cout<<"\"price\":Sorted by price"<<endl;
        cout<<"please: ";
        string type;
        cin>>type;
        // cin.get();
        TypeShow(books,type);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}


bool FillReview(shared_ptr<Review> &rr)
{
    cout << "Enter book title (quit to quit): ";

    rr=shared_ptr<Review>(new Review());//给智能指针分配空间。

    //get title
    getline(cin,rr->title);
    if (rr->title == "quit")return false;

    //get rating
    cout << "Enter book rating: ";
    if (!(cin >> rr->rating))return false;//增加了一个输入检查，如果输入流遇到是EOF或者异常，则返回false;
    while (cin.get() != '\n')continue;// get rid of rest of input line

    //get price
    cout << "Enter book price: ";
    if (!(cin >> rr->price))return false;//增加了一个输入检查，如果输入流遇到是EOF或者异常，则返回false;
    while (cin.get() != '\n')continue;// get rid of rest of input line

    return true;
}


void ShowReview(const shared_ptr<Review> & rr)
{
    cout << rr->rating << "\t" << rr->title <<"\t" << rr->price << endl; 
}


void TypeShow(const vector<shared_ptr<Review> > &books,const string type)
{
    if(type=="original")
        {
            cout<< "the original sort:\nRating\tBook\tPrice\n";
            for_each(books.begin(), books.end(), ShowReview);
        }
    if(type=="title")
        {
            sort(books.begin(), books.end(),SortBook("title"));
            cout << "Sorted by title:\nRating\tBook\tPrice\n";
            for_each(books.begin(), books.end(), ShowReview);
        }
    if(type=="rating")
        {
            sort(books.begin(), books.end(),SortBook("rating"));
            cout << "Sorted by rating:\nRating\tBook\tPrice\n";
            for_each(books.begin(), books.end(), ShowReview);
        }
    if(type=="price")
        {
            sort(books.begin(), books.end(),SortBook("price"));
            cout << "Sorted by Price:\nRating\tBook\tPrice\n";
            for_each(books.begin(), books.end(), ShowReview);
        }
}


