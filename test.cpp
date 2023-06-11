// Programming Technique II - Group Project
// Group: Tetra
// Project Title: Restaurant Booking System
// Member 1: NG SHU YU A22EC0228
// Member 2: YEOH CHONG YI A22EC0295
// Member 3: WONG QIAO YING A22EC0118
// Member 4: NICOLE LIM TZE YEE A22EC0123

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
    Reservation(string d = "", string t = "", int rn = 0)
    {
        date = d;
        time = t;
        reservationNum = rn;
    }
    void setDate(string d = "") { date = d; }
    void setTime(string t = "") { time = t; }
    void setReserveNum()
    {
        int a, b, c, d;
        a = (rand() % 5 + 1) * 1000;
        b = (rand() % 3 + 1) * 100;
        c = (rand() % 5) * 10;
        d = rand() % 2 + 1;
        reservationNum = a + b + c + d;
    }
    void setQuantity(int q) { quantity = q; }

    string getDate() { return date; }
    string getTime() { return time; }
    int getReserveNum() { return reservationNum; }
    int getQuantity() { return quantity; }
};

class Customer
{
private:
    string name;
    string phone;
    bool isVIP;

public:
    Reservation r;
    Customer(string n = "", string p = "", bool v = false)
    {
        name = n;
        phone = p;
        isVIP = v;
    }
    void setName(string n) { name = n; }
    string getName() { return name; }

    void setPhone(string p) { phone = p; }
    string getPhone() { return phone; }

    void setIsVIP(bool v) { isVIP = v; }
    bool getIsVIP() { return isVIP; }

    void setReserveNum() { r.setReserveNum(); }
    int getReserveNum() { return r.getReserveNum(); }

    void setDate(string d) { r.setDate(d); }
    string getDate() { return r.getDate(); }

    void setTime(string t) { r.setTime(t); }
    string getTime() { return r.getTime(); }

    void setQuantity(int q) { r.setQuantity(q); }
    int getQuantity() { return r.getQuantity(); }
};

class Meal
{
protected:
    int course;

public:
    Meal(int c) { course = c; }

    void setCourse(int c) { course = c; }
    int getCourse() const { return course; }

    virtual void displayMenu() const {}
    virtual void setCode() {}
    virtual int getCode() { return 0; }
    virtual void setName() {}
    virtual string getName() const { return 0; }
};

class Appetizer : public Meal
{
private:
    int appCode;
    string appName;
    string app100[3] = {"Caesar Salad",
                        "Garlic Bread",
                        "Soup of the Day"};
    string app150[3] = {"Caprese Salad",
                        "Shrimp Cocktail",
                        "Bruschetta"};
    string app200[3] = {"Escargots in Garlic Butter",
                        "Lobster Bisque",
                        "Baked Brie with Cranberry Chutney"};

public:
    Appetizer(int c) : Meal(c) {}
    Appetizer(int c, int code) : Meal(c) { appCode = code; }

    void setCode() 
    { 
        do
        {
            cout << "Enter 1-3 to confirm your choice: ";
            cin >> appCode;
        } while (appCode != 1 && appCode != 2 && appCode != 3);
    }
    int getCode() const { return appCode; }

    void setName()
    {
        if (course == 100)
            appName = app100[appCode];
        else if (course == 150)
            appName = app150[appCode];
        else
            appName = app200[appCode];
    }
    string getName() const { return appName; }

    void displayMenu() const
    {
        if (course == 100)
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << app100[i] << endl;
        else if (course == 150)
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << app150[i] << endl;
        else
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << app200[i] << endl;
    }
};

class Entree : public Meal
{
private:
    int entCode;
    string entName;
    string ent100[3] = {"Grilled Chicken Breast",
                        "Spaghetti Carbonara",
                        "Fish and Chips with Tartar Sauce"};
    string ent150[3] = {"Grilled Ribeye Steak with Grilled Asparagus",
                        "Pan-Seared Salmon with Lemon Butter Sauce",
                        "Vegetarian Pasta Primavera"};
    string ent200[3] = {"Filet Mignon with Truffle Mashed Potatoes",
                        "Grilled Sea Bass with Lemon Caper Sauce",
                        "Chicken Parmesan with Spaghetti Marinara"};

public:
    Entree(int c) : Meal(c) {}
    Entree(int c, int code) : Meal(c) {entCode = code;}

    void setCode() 
    { 
        do
        {
            cout << "Enter 1-3 to confirm your choice: ";
            cin >> entCode;
        } while (entCode != 1 && entCode != 2 && entCode != 3);
    }
    int getCode() const { return entCode; }

    void setName()
    {
        if (course == 100)
            entName = ent100[entCode];
        else if (course == 150)
            entName = ent150[entCode];
        else
            entName = ent200[entCode];
    }
    string getName() const { return entName; }

    void displayMenu() const
    {
        
        if (course == 100)
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << ent100[i] << endl;
        else if (course == 150)
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << ent150[i] << endl;
        else
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << ent200[i] << endl;
    }
};

class Dessert : public Meal
{
private:
    int dessCode;
    string dessName;
    string set100[3] = {"Chocolate Brownie with Vanilla Ice Cream",
                        "Fresh Fruit Salad",
                        "Crème Brûlée"};
    string set150[3] = {"New York Cheesecake with Raspberry Sauce",
                        "Tiramisu",
                        "Apple Pie with Vanilla Sauce"};
    string set200[3] = {"Molten Chocolate Lava Cake with Vanilla Bean Ice Cream",
                        "Crème Brûlée Trio (Vanilla, Chocolate, and Coffee)",
                        "Berry Pavlova with Whipped Cream"};

public:
    Dessert(int c) : Meal(c) {}
    Dessert(int c, int code) : Meal(c) { dessCode = code; }

    void setCode() 
    {
        do
        {
            cout << "Enter 1-3 to confirm your choice: ";
            cin >> dessCode;
        } while (dessCode != 1 && dessCode != 2 && dessCode != 3);
    }
    int getCode() const { return dessCode; }

    void setName() 
    { 
        if (course == 100)
            dessName = set100[dessCode];
        else if (course == 150)
            dessName = set150[dessCode];
        else
            dessName = set200[dessCode];
    }
    string getName() const { return dessName; }

    void displayMenu() const
    {
        if (course == 100)
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << set100[i] << endl;
        else if (course == 150)
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << set150[i] << endl;
        else
            for (int i = 0; i < 3; i++)
                cout << "\t" << i + 1 << ". " << set200[i] << endl;
    }
};

int main()
    {
        srand(time(NULL)); // recommended to be called in main before any random numbers are generated
        char status;

        do
        {
            // input customer info
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
            // input reservation details
            cout << "Number of pax: ";
            cin >> quantity;
            cout << "Date (XX/XX/XXXX): ";
            cin >> date;
            cout << "Time (eg: 1400): ";
            cin >> time;
            bool isVIP;
            if (vip == 'y' || vip == 'Y')
                isVIP = 1;
            else
                isVIP = 0;
            // set customer and reservation info
            Customer cust(name, phonenum, isVIP);
            cust.setReserveNum();       // generate reservation num
            cust.setQuantity(quantity); // set reservation pax
            cust.setDate(date);         // set reservation date
            cust.setTime(time);         // set reservation time

            // input course price
            int course;
            do
            {
                cout << "Enter your prefered course price (RM100/150/200): ";
                cin >> course;
            } while (course != 100 && course != 150 && course != 200);

            // Define App, Ent, Des obj with course price
            Appetizer a(course);
            Entree e(course);
            Dessert d(course);
            Meal *m[3] = { &a, &e, &d };
            
            // Get food code for each class
            int code;
            string line(15,'-');
            for (int i = 0; i < 3; i++)
            {
                cout << line << endl;
                m[i]->displayMenu(); // Call displayMenu() for each class
                cout << line << endl;
                m[i]->setCode();
                m[i]->setName(); // Call setName() to set the name based on the chosen code
                cout << endl;
            }

            // Print Summary
            cout << line << endl;
            cout << "Reservation Summary" << endl;
            cout << "Reservation Number: " << cust.getReserveNum() << endl;
            cout << "Customer Name: " << cust.getName() << endl;
            cout << "Phone Number: " << cust.getPhone() << endl;
            cout << "VIP Status: " << cust.getIsVIP() << endl << endl;
            cout << "Reservation Date & Time: " << cust.getDate() << " at " << cust.getTime() << endl;
            cout << "Number of Pax: " << cust.getQuantity() << endl;
            cout << "Course Price: " << m[0]->getCourse() << endl;
            cout << "Appetizer: " << m[0]->getName() << endl;
            cout << "Entree: " << m[1]->getName() << endl;
            cout << "Dessert: " << m[2]->getName() << endl;

            cout << "Total Price: " << m[0]->getCourse() * cust.getQuantity() << endl;

            cout << "Do you wish to make another reservation? (Y/N): ";
            cin >> status;
        } while (status == 'y' || status == 'Y');

        system("pause");
        return 0;
    }