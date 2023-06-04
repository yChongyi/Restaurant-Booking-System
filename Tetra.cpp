//Programming Technique II - Group Project
//Group: Tetra
//Project Title: Restaurant Booking System
//Member 1: NG SHU YU A22EC0228
//Member 2: YEOH CHONG YI A22EC0295
//Member 3: WONG QIAO YING
//Member 4: NICOLE LIM TZE YEE A22EC0123

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

class Reservation
{
    private:
        int reservationNum;
        string date, time;
        int quantity;

    public:
        Reservation (string d="", string t="", int rn=0){
            date=d;
            time=t;
            reservationNum=rn;
        }
        void setDate (string d=""){
            date=d;
        }
        void setTime (string t=""){
            time=t;
        }
        void setReserveNum(){
            int a,b,c,d;
            a=(rand()%5+1)*1000;
            b=(rand()%3+1)*100;
            c=(rand()%5)*10;
            d=rand()%2+1;
            reservationNum=a+b+c+d;
        }
        void setQuantity(int q){
            quantity=q;
        }
        string getDate(){
            return date;
        }
        string getTime(){
            return time;
        }
        int getReserveNum(){
            return reservationNum;
        }
        int getQuantity(){
            return quantity;
        }

};

class Customer
{
    private:
        string name;
        string phone;
        bool isVIP;

    public:
        Reservation r;
        Customer (string n="", string p="", bool v=false)
        {
            name = n;
            phone = p;
            isVIP = v;
        }
        void setName (string n) {name = n;}
        string getName () {return name;}

        void setPhone (string p) {phone = p;}
        string getPhone () {return phone;}

        void setIsVIP (bool v) {isVIP = v;}
        bool getIsVIP () {return isVIP;}

        void setReserveNum (int num) {r.setReserveNum();}
        int getReserveNum () {return r.getReserveNum();}

        void setDate (string d) {r.setDate(d);}
        string getDate () {return r.getDate();}

        void setTime (string t) {r.setTime(t);}
        string getTime () {return r.getTime();}
};

class Meal
{
    protected:
        int course;
    
    public:
        Meal(int c)
        {
            course = c;
        }

        void setCourse(int c)
        {
            course = c;
        }

        int getCourse() const
        {
            return course;
        }

        string getDescription() const
        {
            return "Meal";
        }
};

class Appetizer: public Meal
{
    private:
        int appCode;
        string appName;

    public:
        Appetizer(int c, int code, string name) : Meal(c)
        {
            appCode = code;
            appName = name;
        }

        void setAppMenuCode(int code)
        {
            appCode = code;
        }

        void setAppName(string name)
        {
            appName = name;
        }

        int getAppMenuCode() const
        {
            return appCode;
        }

        string getAppName() const
        {
            return appName;
        }

        string getDescription() const
        {
            return "Appetizer";
        }
};

class Entree: public Meal
{
    private:
        int entCode;
        string entName;

    public:
        Entree(int c, int code, string name) : Meal(c)
        {
            entCode = code;
            entName = name;
        }

        void setEntCode(int code)
        {
            entCode = code;
        }

        void setEntName(string name)
        {
            entName = name;
        }

        int getEntCode() const
        {
            return entCode;
        }

        string getEntName() const
        {
            return entName;
        }

        string getDescription() const
        {
            return "Entree";
        }
};

class Dessert: public Meal
{
    private:
        int dessCode;
        string dessName;

    public:
        Dessert(int c, int code, string name) : Meal(c)
        {
            dessCode = code;
            dessName = name;
        }

        void setDessCode(int code)
        {
            dessCode = code;
        }

        void setDessName(string name)
        {
            dessName = name;
        }

        int getDessCode() const
        {
            return dessCode;
        }

        string getDessName() const
        {
            return dessName;
        }

        string getDescription() const
        {
            return "Dessert";
        }
};

int main(){
    
    srand(time(NULL)); //recommended to be called in main before any random numbers are generated
    
    system("pause");
    return 0;
}