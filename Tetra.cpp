//Programming Technique II - Group Project
//Group: Tetra
//Project Title: Restaurant Booking System
//Member 1: NG SHU YU A22EC0228
//Member 2: YEOH CHONG YI A22EC0295
//Member 3: WONG QIAO YING
//Member 4: NICOLE LIM TZE YEE

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Reservation
{};

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

        //void setReserveNum (int num) {r.setReserveNum(num);}
        //int getReserveNum () {return r.getReserveNum();}

        //void setDate (string d) {r.setDate(d);}
        //string getDate () {return r.getDate();}

        //void setTime (string t) {r.setTime(t);}
        //string getTime () {return r.getTime();}
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

