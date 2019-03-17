

#if !defined(CD_H_)
#define CD_H_


class Cd
{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    Cd(const char* per,const char *lab,int sel,double plti);
    Cd(const Cd & cd);
    Cd();
    Cd &operator=(const Cd &d);
    virtual ~Cd();
    virtual void report() const;
};

#endif // CD_H_
