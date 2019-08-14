#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

class Customer
{
public:
    Customer( const char *,const char *, const char *, int=0,int=0); //Constructor
    ~Customer(); //Destruct customer
    virtual float calcShipping() const = 0;
//Abstract class
    virtual void print() const;
    virtual void discount() const;

private:
    char *fullname;
    int homenum;
    char *street;
    char *citystate;
    int zipcode;

};
Customer::Customer(const char *name, const char *astreet, const char *ctyst, int ahomenum,int zpcd)
{
    fullname=new char[strlen(name)+1];
    strcpy(fullname,name);
    homenum=ahomenum;
    street = new char[strlen(astreet) + 1];
    strcpy(street, astreet);
    citystate = new char[strlen(ctyst) + 1];
    strcpy(citystate, ctyst);
    zipcode=zpcd;
}
void Customer::discount() const
{
    if (calcShipping()<300)
    {
        cout<<"Discount percentage is 1.9% for a discount of "<<fixed<<setprecision(2)<<"$"<<calcShipping()*0.019<<"."<<endl;
        cout<<"Total cost after discount is "<<fixed<<setprecision(2)<<"$"<<calcShipping() - calcShipping()*0.019<<".";
    }
    else if (calcShipping()>300 && calcShipping()<600)
    {

        cout<<"Discount percentage is 2.6% for a discount of "<<fixed<<setprecision(2)<<"$"<<calcShipping()*0.026<<"."<<endl;
        cout<<"Total cost after discount is "<<fixed<<setprecision(2)<<"$"<<calcShipping() - calcShipping()*0.026<<".";
    }
    else if (calcShipping()>600 && calcShipping()<1000)
    {
        cout<<"Discount percentage is 2.9% for a discount of "<<fixed<<setprecision(2)<<"$"<<calcShipping()*0.029<<"."<<endl;
        cout<<"Total cost after discount is "<<fixed<<setprecision(2)<<"$"<<calcShipping() - calcShipping()*0.029<<".";
    }
    else if (calcShipping()>1000)
    {
        cout<<"Discount percentage is 3.4% for a discount of "<<fixed<<setprecision(2)<<"$"<<calcShipping()*0.034<<"."<<endl;
        cout<<"Total cost after discount is "<<fixed<<setprecision(2)<<"$"<<calcShipping() - calcShipping()*0.034<<".";
    }
}

void Customer::print() const
{
    cout <<"Customer: " <<fullname<<"\tExpected Arrival Date: 12/12/19"<<endl<<homenum<<" "<<street<<endl<<citystate<<","<<" "<<zipcode<<endl;

}
Customer::~Customer()
{
    delete[] fullname;
}

class Video: public Customer
{
public:
    //#of games, insurance, overnight shipping in constructor
    Video(const char *, const char *, const char *, int ,int, int, int, int);
    virtual float calcShipping() const;

    virtual void print() const;
private:
    int amt, insurance, overnight,extra;
};
Video::Video(const char *name, const char *astreet, const char *ctyst, int ahomenum,int zpcd, int aamt, int ins, int over)
:Customer(name,astreet,ctyst,ahomenum,zpcd)
{
    amt=aamt;
    insurance=ins; //Make if statement: If insurance=0, then no insurance else insurance and add the fees
    overnight=over;//Make if statement: If overnight=0, then no overnight else overnight and add the fees
}
float Video::calcShipping() const
{
    if (insurance ==0 && overnight==0)
    return amt*19.99;
    else if (insurance ==0 && overnight==1)
    return amt*19.99+4.99;
    else if (insurance==1 && overnight==1)
    return amt*19.99*1.06+4.99;
    else if (insurance==1 && overnight==0)
    return amt*19.99*1.06;
}
void Video::print() const
{
    Customer::print();
    cout <<amt<<fixed<<setprecision(2)<<" video games ordered: "<<"$"<<amt*19.99<<", overnight delivery is ";
    if (overnight==1)
        cout<<"$4.99"<<endl;
        else if (overnight==0)
        cout<<"none"<<endl;
    if (insurance==1)
        cout<<fixed<<setprecision(2)<<"Insurance is 6.00%"<<endl;
        else if (insurance==0)
        cout<<"Insurance is none"<<endl;
        cout<<"Total cost is $"<<fixed<<setprecision(2)<<calcShipping()<<endl;
        Customer::discount();
}
class phone: public Customer
{
public:
    //#of games, insurance, overnight shipping in constructor
    phone(const char *, const char *, const char *, int ,int, int, int, int,int);
    virtual float calcShipping() const;
    virtual void print() const;
private:
    int amt, insurance, overnight,extra, extra2;
};

phone::phone(const char *name, const char *astreet, const char *ctyst, int ahomenum,int zpcd, int aamt, int ins, int over, int extr)
:Customer(name,astreet,ctyst,ahomenum,zpcd)
{
    amt=aamt;
    insurance=ins;
    overnight=over;
    extra=extr;
}

float phone::calcShipping() const
{
    if (insurance ==0 && overnight==0 && extra==0)
    return amt*799.99;
    else if (insurance ==1 && overnight==0 && extra==0)
    return amt*799.99*1.11;
    else if (insurance==1 && overnight==1 && extra==0)
    return ((amt*799.99)+25.00)*1.11;
    else if (insurance==1 && overnight==1 && extra==1)
    return (amt*(799.99+24.99)+25.00)*1.11;
    else if (insurance == 0 && overnight ==1 && extra==1)
    return amt*(799.99+24.99);
    else if (insurance==0 && overnight==1 && extra==0)
    return (amt*799.99+25.00);
    else if (insurance==0 && overnight==0 && extra==1)
    return amt*(799.99+24.99);
    else return 0;
}
void phone::print() const
{
    Customer::print();
    cout <<amt<<" phones ordered: "<<"$"<<amt*799.99<<" "<<"overnight delivery is ";
    if (overnight==1)
        cout<<fixed<<setprecision(2)<<"$25.00";
        else
        cout<<fixed<<setprecision(2)<<"none";
    if (extra==1)
        cout<<", phone case is $24.99 "<<fixed<<setprecision(2)<<"each, $"<<amt*24.99<<" total."<<endl;
        else if (extra==0)
        cout<<". No phone cases added to order."<<endl;
    if (insurance==1)
        cout<<"Insurance is 11% of total cost, $"<<fixed<<setprecision(2)<<amt*799.99*0.11<<"."<<endl;
        else
            cout<<"No insurance specified"<<endl;

    cout<<"Total cost is $"<<fixed<<setprecision(2)<<calcShipping()<<endl;
    Customer::discount();
}

class hamburger: public Customer
{
public:
    //#of games, insurance, overnight shipping in constructor
    hamburger(const char *, const char *, const char *, int ,int, int, int, int,int, int);
    virtual float calcShipping() const;
    virtual void print() const;
private:
    int amt, insurance, overnight,extra, extra2;
};

hamburger::hamburger(const char *name, const char *astreet, const char *ctyst, int ahomenum,int zpcd, int aamt, int ins, int over, int extr, int extr2)
:Customer(name,astreet,ctyst,ahomenum,zpcd)
{
    amt=aamt;
    insurance=ins;
    overnight=over;
    extra=extr;
    extra2=extr2;
}

float hamburger::calcShipping() const
{
    if (insurance ==0 && overnight==0 && extra==0 && extra2==0)
    return amt*7.99;
    if (insurance ==1 && overnight==0 && extra==0 && extra2==0)
    return amt*1.03*7.99;
    else if (insurance ==0 && overnight==1 && extra==0 && extra2==0)
    return amt*7.99+9.00;
    else if (insurance==1 && overnight==1 && extra==0 && extra2==0)
    return ((amt*7.99)+9.00)*1.03;
    else if (insurance==1 && overnight==1 && extra==1 && extra2==0)
    return ((amt*(7.99+1.79))+9.00)*1.03;
    else if (insurance == 1 && overnight ==1 && extra==1 && extra2==1)
    return ((amt*(7.99+1.79+1.89))+9.00)*1.03;
    else if (insurance ==0 && overnight ==0 && extra==0 && extra2==1)
    return amt*(7.99+1.89);
    else if (insurance ==0 && overnight ==0 && extra==1 && extra2==1)
    return amt*(7.99+1.79+1.89);
    else if (insurance ==0 && overnight ==0 && extra==1 && extra2==0)
    return amt*(7.99+1.79);
}
void hamburger::print() const
{
    Customer::print();
    cout <<amt<<" hamburgers ordered: "<<"$"<<fixed<<setprecision(2)<<amt*7.99<<", "<<"overnight delivery is ";
    if (overnight==1)
        cout<<fixed<<setprecision(2)<<"$9.00";
        else if (overnight==0)
        cout<<fixed<<setprecision(2)<<"none";
    if (extra==1)
        cout<<", condiments are $1.79 each, $"<<fixed<<setprecision(2)<<amt*1.79<<" total";
        else if (extra==0)
        cout<<", no condiments";
    if (extra2==1)
        cout<<", buns are $1.89 "<<"each, $"<<fixed<<setprecision(2)<<amt*1.89<<" total."<<endl;
        else if (extra2==0)
        cout<<", no hamburger buns."<<endl;
    if (insurance==1)
        cout<<"Insurance is 3% of total cost, $"<<fixed<<setprecision(2)<<amt*7.99*0.03<<"."<<endl;
        else
        cout<<"No insurance specified"<<endl;
        cout<<"Total cost is $"<<fixed<<setprecision(2)<<calcShipping()<<"."<<endl;
    Customer::discount();
}

int main()
{
Hamburger f("Customer Name", "Street Name", "City State", home number, zipcode, product amount, insurance, overnight shipping, hamburger buns, condiments);
phone a("Customer Name", "Street Name", "City State", home number, zipcode, product amount, insurance, overnight shipping, phone cases)
Video c("Customer Name", "Street Name", "City State", home number, zipcode, product amount, insurance, overnight shipping);


f.print();
cout<<endl<<endl<<endl;
a.print();
cout<<endl<<endl<<endl;
c.print();
cout<<endl<<endl<<endl;



return 0;
}
