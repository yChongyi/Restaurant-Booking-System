//Programming Technique II - Group Project
//Group: Tetra
//Project Title: Restaurant Booking System
//Member 1: NG SHU YU A22EC0228
//Member 2: YEOH CHONG YI A22EC0295
//Member 3: WONG QIAO YING A22EC0118
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

        void setReserveNum () {r.setReserveNum();}
        int getReserveNum () {return r.getReserveNum();}

        void setDate (string d) {r.setDate(d);}
        string getDate () {return r.getDate();}

        void setTime (string t) {r.setTime(t);}
        string getTime () {return r.getTime();}

        void setQuantity(int q){r.setQuantity(q);}
        int getQuantity(){return r.getQuantity();}
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

        virtual void displayMenu(){}
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

        void displayMenu() 
        {
            if(course == 100)
                cout << "1. Caesar Salad"
               <<endl<< "2. Garlic Bread"
               <<endl<< "3. Soup of the day";
            else if(course == 150)
                cout << "1. Caprese Salad"
               <<endl<< "2. Shrimp Cocktail"
               <<endl<< "3. Bruschetta";
            else  
                cout << "1. Escargots in Garlic Butter"
               <<endl<< "2. Lobster Bisque"
               <<endl<< "3. Baked Brie with Cranberry Chutney";
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

        void displayMenu() 
        {
            if(course == 100)
                cout << "1. Grilled Chicken Breast with Mashed Potatoes and Seasonal Vegetables"
               <<endl<< "2. Spaghetti Carbonara"
               <<endl<< "3. Fish and Chips with Tartar Sauce";
            else if(course == 150)
                cout << "1. Grilled Ribeye Steak with Roasted Potatoes and Grilled Asparagus"
               <<endl<< "2. Pan-Seared Salmon with Lemon Butter Sauce"
               <<endl<< "3. Vegetarian Pasta Primavera";
            else  
                cout << "1. Filet Mignon with Truffle Mashed Potatoes and Grilled Vegetables"
               <<endl<< "2. Grilled Sea Bass with Lemon Caper Sauce"
               <<endl<< "3. Chicken Parmesan with Spaghetti Marinara";
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

        void displayMenu() 
        {
            if(course == 100)
                cout << "1. Chocolate Brownie with Vanilla Ice Cream"
               <<endl<< "2. Fresh Fruit Salad"
               <<endl<< "3. Crème Brûlée";
            else if(course == 150)
                cout << "1. New York Cheesecake with Raspberry Sauce"
               <<endl<< "2. Tiramisu"
               <<endl<< "3. Apple Pie with Vanilla Sauce";
            else  
                cout << "1. Molten Chocolate Lava Cake with Vanilla Bean Ice Cream"
               <<endl<< "2. Crème Brûlée Trio (Vanilla, Chocolate, and Coffee)"
               <<endl<< "3. Berry Pavlova with Whipped Cream";
        }
};

int main(){
    char status;

    do
    {
        //input customer info
        string name, phonenum, date, time;
        char vip;
        int quantity;
        cout << "Good Day! Welcome to Entitled Western Restaurant." << endl;
        cout << "Please enter your name: ";
        getline(cin, name);
        cout << "Please enter phone number (01X-XXXXXXX): ";
        cin >> phonenum;
        cout << "Do you have VIP membership? (Y/N): ";
        cin >> vip;
        toupper(vip);
        //input reservation details
        cout << "Number of pax: ";
        cin >> quantity;
        cout << "Date (XX/XX/XXXX): ";
        cin >> date;
        cout << "Time (eg: 1400): ";
        cin >> time;
        bool isVIP;
        if(vip == 'y' || vip == 'Y') isVIP = 1; else isVIP = 0;
        //set customer and reservation info
        Customer cust(name, phonenum, isVIP);
        cust.setReserveNum();
        cust.setQuantity(quantity);
        cust.setDate(date);
        cust.setTime(time);
       
        //input course price
        int course;
        do{
            cout << "Enter your prefered course price (RM150/200/250): ";
            cin >> course;
        }while(course != 150 && course != 200 && course != 250);
        //set course price
        Meal meaal(course);

       
        srand(time(NULL)); // recommended to be called in main before any random numbers are generated
    } while (status == 'y' || status == 'Y');

        system("pause");
    return 0;
}