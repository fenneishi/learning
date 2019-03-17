
# include "string2.h"

const int Arsize=10;
const int MaxLen=81;


int main(int argc, char const *argv[])
{
    String2 name;
    cout<<"input your name:";
    cin>>name;

    cout<<name<<" please input "<<Arsize<<" short saying <empty line to quit>"<<endl;
    String2 sayings[Arsize];

    char temp[MaxLen];
    int total;
    for(int i=0;i<Arsize;i++,total++)
    {
        cout<<i+1<<": ";
        cin.get(temp,MaxLen);
        while(cin&&cin.get()!='\n')
            continue;
        if(!cin||temp[0]=='\n')
            break;//empty line,i not incremented
        else sayings[i]=temp;
    }


    if(total>0)
    {
        cout<<"here is your sayings :"<<endl;
        for(int i=0;i<total;i++)
            cout<<i<<": "<<sayings[i]<<endl;


        int shortest=0;
        int first=0;
        for(int i;i<total;i++)
        {
            if(sayings[i].getlen()<sayings[shortest].getlen())
                shortest=i;
            if(sayings[i]<sayings[first])
                first=i;
        }

        cout<<"shortest:  "<<sayings[shortest]<<endl;
        cout<<"first:  "<<sayings[first]<<endl;

    }
    
    return 0;
}
