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
#include <algorithm>

using namespace std;

void line() 
{
    for(int i=0; i<150; i++)
        cout<<"=";
    cout << endl;
}

void dline() 
{
    for(int i=0; i<150; i++)
        cout<<"`";
    cout << endl;
}

void aline() 
{
    for(int i=0; i<150; i++)
        cout<<"*";
    cout << endl;
}

class Meal
{
protected:
    double price;
    int code;
    string name;
    int quantity;

public:
    Meal(double p, int c, string n, int q = 0)
    {
        price = p;
        code = c;
        name = n;
        quantity = q;
    }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    void setCode(int c) { code = c; }
    int getCode() const { return code; }

    void setName(string n) { name = n; }
    string getName() const { return name; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    double getTotalPrice() const { return price * quantity; }

    virtual string getDescription() const //Polymorphism: Parent class virtual method
    {
        return "";
    }
};

class Appetizer : public Meal // Inheritance
{
private:
    string appIng;

public:
    Appetizer(double p, int c, string n, string i, int q = 0) : Meal(p, c, n, q)
    {
        appIng = i;
    }

    void setAppIng(string i) { appIng = i; }
    string getAppIng() const { return appIng; }

    string getDescription() const //Polymorphism: Child class override method
    {
        return "Appetizer ingredient: " + appIng;
    }
};

class Entree : public Meal // Inheritance
{
private:
    string entreeIng;

public:
    Entree(double p, int c, string n, string i, int q = 0) : Meal(p, c, n, q)
    {
        entreeIng = i;
    }

    void setEntreeIng(string i) { entreeIng = i; }
    string getEntreeIng() const { return entreeIng; }

    string getDescription() const //Polymorphism: Child class override method
    {
        return "Entree ingredient: " + entreeIng;
    }
};

class Dessert : public Meal // Inheritance
{
private:
    string dessIng;

public:
    Dessert(double p, int c, string n, string i, int q = 0) : Meal(p, c, n, q)
    {
        dessIng = i;
    }

    void setDessIng(string i) { dessIng = i; }
    string getDessIng() const { return dessIng; }

    string getDescription() const //Polymorphism: Child class override method
    {
        return "Dessert ingredient: " + dessIng;
    }
};

class OrderedMeals
{
private:
    Appetizer appetizer1 = Appetizer(14, 1, "Caesar Salad", "Crisp romaine lettuce, Caesar dressing, croutons.");
    Appetizer appetizer2 = Appetizer(9, 2, "Garlic Bread", "Bread toasted with garlic butter.");
    Appetizer appetizer3 = Appetizer(9, 3, "Soup of the Day", "Daily rotating soup selection.");
    Appetizer appetizer4 = Appetizer(21, 4, "Caprese Salad", "Mozzarella cheese, tomatoes, basil leaves.");
    Appetizer appetizer5 = Appetizer(28, 5, "Shrimp Cocktail", "Shrimp, cocktail sauce.");
    Appetizer appetizer6 = Appetizer(24, 6, "Bruschetta", "Bread, tomatoes, basil.");
    Appetizer appetizer7 = Appetizer(40, 7, "Escargots in Garlic Butter", "Succulent snails, garlic butter sauce, bread.");
    Appetizer appetizer8 = Appetizer(56, 8, "Lobster Bisque", "Lobster meat, herbs, spices.");
    Appetizer appetizer9 = Appetizer(38, 9, "Baked Brie with Cranberry Chutney", "Brie cheese, cranberry chutney.");

    Entree entree1 = Entree(26, 10, "Grilled Chicken Breast with Mashed Potatoes", "Grilled chicken breast, mashed potatoes, vegetables.");
    Entree entree2 = Entree(22, 11, "Spaghetti Carbonara", "Spaghetti noodles, bacon, eggs, Parmesan cheese.");
    Entree entree3 = Entree(28, 12, "Fish and Chips with Tartar Sauce", "Fish fillets, French fries, tartar sauce.");
    Entree entree4 = Entree(49, 13, "Grilled Ribeye Steak with Grilled Asparagus", "Ribeye steak, potatoes, asparagus.");
    Entree entree5 = Entree(35, 14, "Pan-Seared Salmon with Lemon Butter Sauce", "Salmon fillet, lemon sauce, vegetables.");
    Entree entree6 = Entree(32, 15, "Vegetarian Pasta Primavera", "Sauteed vegetables, pasta.");
    Entree entree7 = Entree(88, 16, "Filet Mignon with Truffle Mashed Potatoes", "Filet mignon steak, truffle mashed potatoes, vegetables.");
    Entree entree8 = Entree(65, 17, "Grilled Sea Bass with Lemon Caper Sauce", "Sea bass fillet, seafood, lemon and caper sauce.");
    Entree entree9 = Entree(53, 18, "Chicken Parmesan with Spaghetti Marinara", "Chicken cutlet, marinara sauce, spaghetti.");

    Dessert dessert1 = Dessert(18, 19, "Chocolate Brownie", "Chocolate brownie served with vanilla ice cream.");
    Dessert dessert2 = Dessert(12, 20, "Fresh Fruit Salad", "Seasonal fruits.");
    Dessert dessert3 = Dessert(20, 21, "Creme Brulee", "Custard base topped with a caramelized sugar crust.");
    Dessert dessert4 = Dessert(23, 22, "New York Cheesecake", "Cheesecake, cracker crust, raspberry sauce.");
    Dessert dessert5 = Dessert(21, 23, "Tiramisu", "Coffee-soaked ladyfingers, mascarpone cheese, cocoa.");
    Dessert dessert6 = Dessert(23, 24, "Apple Pie", "Pie crust filled with spiced apple slices.");
    Dessert dessert7 = Dessert(30, 25, "Molten Chocolate Lava Cake", "Chocolate lava cake served with vanilla ice cream.");
    Dessert dessert8 = Dessert(34, 26, "Raspberry White Chocolate Mousse", "Fresh raspberries, white chocolate, whipping cream.");
    Dessert dessert9 = Dessert(34, 27, "Berry Pavlova", "Meringue dessert, fresh berries, whipped cream.");

    Meal *meals[3][9]; //Polymorphism: Array of parent class pointers

public:
    OrderedMeals()
    {
        meals[0][0] = &appetizer1;
        meals[0][1] = &appetizer2;
        meals[0][2] = &appetizer3;
        meals[0][3] = &appetizer4;
        meals[0][4] = &appetizer5;
        meals[0][5] = &appetizer6;
        meals[0][6] = &appetizer7;
        meals[0][7] = &appetizer8;
        meals[0][8] = &appetizer9;

        meals[1][0] = &entree1;
        meals[1][1] = &entree2;
        meals[1][2] = &entree3;
        meals[1][3] = &entree4;
        meals[1][4] = &entree5;
        meals[1][5] = &entree6;
        meals[1][6] = &entree7;
        meals[1][7] = &entree8;
        meals[1][8] = &entree9;

        meals[2][0] = &dessert1;
        meals[2][1] = &dessert2;
        meals[2][2] = &dessert3;
        meals[2][3] = &dessert4;
        meals[2][4] = &dessert5;
        meals[2][5] = &dessert6;
        meals[2][6] = &dessert7;
        meals[2][7] = &dessert8;
        meals[2][8] = &dessert9;
    }

    void displayMenu()
    {   
        line();
        cout << setw(77) << "MENU" << endl;
        line();
        cout << left;
        cout << "Appetizers: " << endl;
        dline();
        cout << setw(8) << "Choice " << setw(55) << "Meal" 
             << setw(12) << "Price" << "Description" << endl;
        dline();
        for (int i = 0; i < 9; i++)
        {
            cout << setw(8) << i + 1 << setw(55) << meals[0][i]->getName() 
                 << "RM" << setw(10) << showpoint << fixed << setprecision(2) << meals[0][i]->getPrice() << meals[0][i]->getDescription() << endl;
        }
        cout << endl;
        line();
        cout << "Entrees: " << endl;
        dline();
        cout << setw(8) << "Choice " << setw(55) << "Meal "
             << setw(12) << "Price" << "Description" << endl;
        dline();
        for (int i = 0; i < 9; i++)
        {
            cout << setw(8) << 9 + i + 1 << setw(55) << meals[1][i]->getName() 
                 << "RM" << setw(10) << showpoint << fixed << setprecision(2) << meals[1][i]->getPrice() << meals[1][i]->getDescription() << endl;
        }
        cout << endl;
        line();
        cout << "Desserts: " << endl;
        dline();
        cout << setw(8) << "Choice " << setw(55) << "Meal "
             << setw(12) << "Price" << "Description" << endl;
        dline();
        for (int i = 0; i < 9; i++)
        {
            cout << setw(8) << 9 + 9 + i + 1 << setw(55) << meals[2][i]->getName() 
                 << "RM" << setw(10) << showpoint << fixed << setprecision(2) << meals[2][i]->getPrice() << meals[2][i]->getDescription() << endl;
        }
    }

    void updateOrder()
    {
        bool quit = false;
        while (!quit)
        {
            int choice;
            int quantity;
            cout << "Enter the choice of the meal you would like to order: ";
            cin >> choice;
            choice = choice - 1;
            cout << "Enter the quantity of the meal you would like to order (negative number to reduce quantity): ";
            cin >> quantity;
            int currentQuantity = meals[choice / 9][choice % 9]->getQuantity();
            int updatedQuantity = max(currentQuantity + quantity, 0);
            meals[choice / 9][choice % 9]->setQuantity(updatedQuantity);

            char continueChoice;
            do
            {
                cout << "Would you like to order another meal? (y/n): ";
                cin >> continueChoice;
                if (continueChoice == 'n')
                {
                    quit = true;
                }
            } while (continueChoice != 'y' && continueChoice != 'n');
        }
    }

    double getOverallPrice()
    {
        double overallPrice = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                overallPrice += meals[i][j]->getTotalPrice();
            }
        }
        return overallPrice;
    }

    void displayOrderedMeals(bool v)
    {
        cout << endl;
        line();
        cout << right << setw(77) << "CART" << endl;
        line();
        int n = 1;
        for (int i = 0; i < 9; i++)
        {
            if (meals[0][i]->getQuantity() > 0)
            {
                cout << endl
                     << "Appetizers: " << endl;
                cout << setw(3) << left << n++ << " " << setw(55) << left << meals[0][i]->getName() << "x"
                     << meals[0][i]->getQuantity() << fixed << setprecision(2)
                     << " RM" << meals[0][i]->getTotalPrice() << endl;
            }
        }

        n = 1;
        for (int i = 0; i < 9; i++)
        {
            if (meals[1][i]->getQuantity() > 0)
            {
                cout << endl
                     << "Entrees: " << endl;
                cout << setw(3) << left << n++ << " " << setw(55) << left << meals[1][i]->getName() << "x"
                     << meals[1][i]->getQuantity() << fixed << setprecision(2)
                     << " RM" << meals[1][i]->getTotalPrice() << endl;
            }
        }

        n = 1;
        for (int i = 0; i < 9; i++)
        {
            if (meals[2][i]->getQuantity() > 0)
            {
                cout << endl
                     << "Desserts: " << endl;
                cout << setw(3) << left << n++ << " " << setw(55) << left << meals[2][i]->getName() << "x"
                     << meals[2][i]->getQuantity() << fixed << setprecision(2)
                     << " RM" << meals[2][i]->getTotalPrice() << endl;
            }
        }
        cout << endl;

        cout << fixed << setprecision(2) << "Overall Price: RM" << getOverallPrice() << endl;
        if (v==true)
        {
            cout << fixed << setprecision(2) << "VIP Price (10% discount): RM" << getOverallPrice()*0.9 << endl;
        }
    }
};

class Reservation
{
private:
    int reservationNum;
    string date, time;
    int quantity;
    OrderedMeals orderedMeals; //Composition

public:
    Reservation(string d = "", string t = "", int rn = 0)
    {
        date = d;
        time = t;
        reservationNum = rn;
    }
    void setReserveNum()
    {
        int a, b, c, d;
        a = (rand() % 5 + 1) * 1000;
        b = (rand() % 3 + 1) * 100;
        c = (rand() % 5) * 10;
        d = rand() % 2 + 1;
        reservationNum = a + b + c + d;
    }
    int getReserveNum() {return reservationNum;}

    void setDate(string d = "") {date = d;}
    string getDate() {return date;}

    void setTime(string t = "") {time = t;}
    string getTime() {return time;}

    void setQuantity(int q) {quantity = q;}
    int getQuantity() {return quantity;}

    void displayMenu() {orderedMeals.displayMenu();}
    void updateOrder() {orderedMeals.updateOrder();}
    void displayOrderedMeals(bool v) {orderedMeals.displayOrderedMeals(v);}
};

class Customer
{
private:
    string name;
    string phone;
    bool isVIP;
    Reservation r; //Composition

public:
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

    void setQuantity(int q) {r.setQuantity(q);}
    int getQuantity() {return r.getQuantity();}

    Reservation getReservation() { return r; }
};

int main()
{
    srand(time(NULL)); 
    char status;

    do
    {
        // input customer info
        string name, phonenum, date, time;
        char vip;
        int quantity;

        cout << endl;
        line();
        cout << setw(100) << "Good Day! Welcome to TETRA Western Restaurant." << endl;
        line();
        cout << "Make your booking... " << endl << endl;
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
        cout << "Date (dd/mm/yyyy): ";
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

        // Customer reservation
        Reservation custReservation = cust.getReservation();

        cust.setReserveNum();         // generate reservation num
        cust.setQuantity(quantity);   // set reservation pax
        cust.setDate(date);           // set reservation date
        cust.setTime(time);           // set reservation time

        // display menu
        cout << endl;
        custReservation.displayMenu();

        // input choice
        int choice;
        do
        {
            cout << endl;
            aline();
            cout << "Press 1 to order meal; Press 2 to view cart; Press 3 to checkout" << endl;
            cin >> choice;
            aline();
            switch (choice)
            {
                case 1:
                    custReservation.updateOrder();
                    break;

                case 2:
                    custReservation.displayOrderedMeals(cust.getIsVIP());
                    break;
            }
        } while (choice != 3);

        // Print Summary
        cout << endl << right;
        line();
        cout << setw(85) << "RESERVATION SUMMARY" << endl;
        line();
        cout << "Reservation Number: " << cust.getReserveNum() << endl;
        cout << "Customer Name: " << cust.getName() << endl;
        cout << "Phone Number: " << cust.getPhone() << endl;
        cout << "VIP Status: " << cust.getIsVIP() << endl;
        cout << "Reservation Date & Time: " << cust.getDate() << " at " << cust.getTime() << endl;
        cout << "Number of Pax: " << cust.getQuantity() << endl;
        custReservation.displayOrderedMeals(cust.getIsVIP());

        cout << endl;
        cout << "Do you wish to make another reservation? (Y/N): ";
        cin >> status;
        cin.ignore();
    } while (status == 'y' || status == 'Y');

    system("pause");
    return 0;
}