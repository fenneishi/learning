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


bool operator<(const Review & r1, const Review & r2);
bool sortTitle(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool sortRating(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);//两比较元素相对关系正确，返回true.
bool sortPrice(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);//两比较元素相对关系正确，返回true.
bool FillReview(shared_ptr<Review> &rr);
void ShowReview(const shared_ptr<Review> & rr);
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
              
        cout<< "the original sort:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(),sortTitle);
        cout << "Sorted by title:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), sortRating);
        cout << "Sorted by rating:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), sortPrice);
        cout << "Sorted by Price:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}
bool sortTitle(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
        return true;
    else
        return false;
}
bool sortRating(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool sortPrice(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
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
