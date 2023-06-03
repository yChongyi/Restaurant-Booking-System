//Programming Technique II - Group Project
//Group: Tetra
//Project Title: Restaurant Booking System
//Member 1: NG SHU YU A22EC0228
//Member 2: YEOH CHONG YI
//Member 3: WONG QIAO YING
//Member 4: NICOLE LIM TZE YEE

#include <iostream>
#include <iomanip>
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

