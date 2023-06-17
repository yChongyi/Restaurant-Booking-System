#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class Meal
{
protected:
    double price;
    int code;
    string name;
    int quantity;

public:
    Meal(double p, int c, string n, int q = 0) { 
        price = p;
        code = c;
        name = n;
        quantity = q;
    }

    void setPrice(double p) { price = p; }
    int getPrice() const { return price; }

    void setCode(int c) { code = c; }
    int getCode() const { return code; }

    void setName(string n) { name = n; }
    string getName() const { return name; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    double getTotalPrice() const { return price * quantity; }

    virtual string getDescription() const
    {
        return "Meal. Name: " + name + ". Price: " + to_string(price);
    }
};

class Appetizer : public Meal
{
private:
    string category;

public:
    Appetizer(double p, int c, string n, string cat, int q = 0) : Meal(p, c, n, q) {
        category = cat;
    }   

    void setCategory(string cat)
    {
        category = cat;
    }
    string getCategory() const
    {
        return category;
    }

    string getDescription() const override
    {
        return "Appetizer. Name: " + name + ". Price: " + to_string(price) + ". Category: " + category;
    }
};

class Entree : public Meal
{
private:
    string ingredients;
    double prepareTimeMinutes;
    string cuisineType;
    double calories;
    string spicinessLevel;


public:
    Entree(double p, int c, string n, string ing, double prepareT, string csineType, double calor, string spicyLevel, int q = 0) : Meal(p, c, n, q) {
        ingredients = ing;
        prepareTimeMinutes = prepareT;
        cuisineType = csineType;
        calories = calor;
        spicinessLevel = spicyLevel;
    }   

    void setIngredients(string ing)
    {
        ingredients = ing;
    }
    string getIngredients() const
    {
        return ingredients;
    }

    void setPrepareTimeMinutes(double prepareT)
    {
        prepareTimeMinutes = prepareT;
    }
    double getPrepareTimeMinutes() const
    {
        return prepareTimeMinutes;
    }

    void setCuisineType(string csineType)
    {
        cuisineType = csineType;
    }
    string getCuisineType() const
    {
        return cuisineType;
    }

    void setCalories(double calor)
    {
        calories = calor;
    }
    double getCalories() const
    {
        return calories;
    }

    void setSpicinessLevel(string spicyLevel)
    {
        spicinessLevel = spicyLevel;
    }
    string getSpicinessLevel() const
    {
        return spicinessLevel;
    }

    string getDescription() const override
    {
        return "Entree. Name: " + name + ". Price: RM" + to_string(price) + ".\n" + string(66, ' ') + " Ingredients: " 
                + ingredients + ". Time to prepare: " + to_string(prepareTimeMinutes) + " minutes.\n" + string(66, ' ') + " Cuisine type: "
                + cuisineType + ". Calories: " + to_string(calories) + ". Spiciness level: " + spicinessLevel;
    }
};

class Dessert : public Meal
{
private:
    string flavour;
    string texture;

public:
    Dessert(double p, int c, string n, string flav, string tex, int q = 0) : Meal(p, c, n, q) {
        flavour = flav;
        texture = tex;
    }   

    void setFlavour(string flav)
    {
        flavour = flav;
    }
    string getFlavour() const
    {
        return flavour;
    }

    void setTexture(string tex)
    {
        texture = tex;
    }
    string getTexture() const
    {
        return texture;
    }

    string getDescription() const override
    {
        return "Desssert. Name: " + name + ". Price: " + to_string(price) + ".\n" +  string(66, ' ') + " Flavour: "
                + flavour + ". Texture: " + texture;
    }

};

class OrderedMeals
{
    private:
        Appetizer appetizer1 = Appetizer(21, 1, "Caesar Salad", "Salad");
        Appetizer appetizer2 = Appetizer(15, 2, "Garlic Bread", "Bread");
        Appetizer appetizer3 = Appetizer(12, 3, "Soup of the Day", "Soup"); 
        Appetizer appetizer4 = Appetizer(26, 4, "Caprese Salad", "Salad");
        Appetizer appetizer5 = Appetizer(42, 5, "Shrimp Cocktail", "Seafood");
        Appetizer appetizer6 = Appetizer(25, 6, "Bruschetta", "Antipasto");
        Appetizer appetizer7 = Appetizer(50, 7, "Escargots in Garlic Butter", "Seafood");
        Appetizer appetizer8 = Appetizer(60, 8, "Lobster Bisque", "Soup");
        Appetizer appetizer9 = Appetizer(70, 9, "Baked Brie with Cranberry Chutney", "Bread"); 

        Entree entree1 = Entree(10, 10, "Grilled Chicken Breast", "", 0, "", 0, "");
        Entree entree2 = Entree(10, 11, "Spaghetti Carbonara", "", 0, "", 0, "");
        Entree entree3 = Entree(10, 12, "Fish and Chips with Tartar Sauce", "", 0, "", 0, "");
        Entree entree4 = Entree(10, 13, "Grilled Ribeye Steak with Grilled Asparagus", "", 0, "", 0, "");
        Entree entree5 = Entree(10, 14, "Pan-Seared Salmon with Lemon Butter Sauce", "", 0, "", 0, "");
        Entree entree6 = Entree(10, 15, "Vegetarian Pasta Primavera", "", 0, "", 0, "");
        Entree entree7 = Entree(10, 16, "Filet Mignon with Truffle Mashed Potatoes", "", 0, "", 0, "");
        Entree entree8 = Entree(10, 17, "Grilled Sea Bass with Lemon Caper Sauce", "", 0, "", 0, "");
        Entree entree9 = Entree(10, 18, "Chicken Parmesan with Spaghetti Marinara", "", 0, "", 0, "");

        Dessert dessert1 = Dessert(5, 19, "Chocolate Brownie with Vanilla Ice Cream", "", "");
        Dessert dessert2 = Dessert(5, 20, "Fresh Fruit Salad", "", "");
        Dessert dessert3 = Dessert(5, 21, "Crème Brûlée", "", "");
        Dessert dessert4 = Dessert(5, 22, "New York Cheesecake with Raspberry Sauce", "", "");
        Dessert dessert5 = Dessert(5, 23, "Tiramisu", "", "");
        Dessert dessert6 = Dessert(5, 24, "Apple Pie with Vanilla Sauce", "", "");
        Dessert dessert7 = Dessert(5, 25, "Molten Chocolate Lava Cake with Vanilla Bean Ice Cream", "", "");
        Dessert dessert8 = Dessert(5, 26, "Crème Brûlée Trio (Vanilla, Chocolate, and Coffee)", "", "");
        Dessert dessert9 = Dessert(5, 27, "Berry Pavlova with Whipped Cream", "", "");

        Meal *meals[3][9];

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
            cout << "Appetizers: " << endl;
            cout << setw(7) << left << "Choice " << setw(60) << left << "Meal " << "Description" << endl;
            for (int i = 0; i < 9; i++)
            {   
                cout << setw(7) << left << i + 1 << setw(60) << left << meals[0][i]->getName() << meals[0][i]->getDescription() << endl;
            }

            cout << endl << "Entrees: " << endl;
            cout << setw(7) << "Choice " << setw(60) << "Meal " << "Description" << endl;
            for (int i = 0; i < 9; i++)
            {
                cout << setw(7) << left << 9 + i + 1 << setw(60) << left << meals[1][i]->getName() << meals[1][i]->getDescription() << endl;
            }

            cout << endl << "Desserts: " << endl;
            cout << setw(7) << "Choice " << setw(60) << "Meal " << "Description" << endl;
            for (int i = 0; i < 9; i++)
            {
                cout << setw(7) << left << 9 + 9 + i + 1 << setw(60) << left << meals[2][i]->getName() << meals[2][i]->getDescription() << endl;
            }
            cout << endl;
        }

        void updateMenu()
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
        }

        void displayAndUpdate()
        {
            bool quit = false;
            while (!quit)
            {
                displayMenu();
                updateMenu();
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

        void displayOrderedMeals()
        {
            cout << "Appetizers: " << endl;
            int n = 1;
            for (int i = 0; i < 9; i++)
            {   
                if (meals[0][i]->getQuantity() > 0)
                {
                    cout << setw(3) << left << n++ << " " << setw(60) << left << meals[0][i]->getName() << "x" 
                        << meals[0][i]->getQuantity() << fixed << setprecision(2)
                        << " RM" << meals[0][i]->getTotalPrice() << endl;
                }
            }

            n = 1;
            cout << endl << "Entrees: " << endl;
            for (int i = 0; i < 9; i++)
            {
                if (meals[1][i]->getQuantity() > 0)
                {
                    cout << setw(3) << left << n++ << " " << setw(60) << left << meals[1][i]->getName() << "x" 
                        << meals[1][i]->getQuantity() << fixed << setprecision(2)
                        << " RM" << meals[1][i]->getTotalPrice() << endl;
                }
            }

            n = 1;
            cout << endl << "Desserts: " << endl;
            for (int i = 0; i < 9; i++)
            {
                if (meals[2][i]->getQuantity() > 0)
                {
                    cout << setw(3) << left << n++ << " " << setw(60) << left << meals[2][i]->getName() << "x" 
                        << meals[2][i]->getQuantity() << fixed << setprecision(2)
                        << " RM" << meals[2][i]->getTotalPrice() << endl;
                }
            }
            cout << endl;  

            cout << fixed << setprecision(2) << "Overall Price: RM" << getOverallPrice() << endl;      
        }
};

class Reservation
{
    private:
        int reservationNum;
        string date, time;
        int quantity;
        OrderedMeals orderedMeals;

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
        string getDate(){
            return date;
        }
        string getTime(){
            return time;
        }
        int getReserveNum(){
            return reservationNum;
        }

        void setQuantity(int q)
        {
            quantity = q;
        }
        int getQuantity()
        {
            return quantity;
        }
        void updateOrder()
        {
            orderedMeals.displayAndUpdate();
        }

        void displayCurrentOrder()
        {
            orderedMeals.displayOrderedMeals();
        }
};

class Customer
{
private:
    string name;
    string phone;
    bool isVIP;
    Reservation r;

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

    Reservation getReservation() { return r; }
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

            // Customer reservation
            Reservation custReservation = cust.getReservation();

            cust.setReserveNum();       // generate reservation num
            custReservation.setQuantity(quantity); // set reservation pax
            cust.setDate(date);         // set reservation date
            cust.setTime(time);         // set reservation time

            // input choice
            int choice;
            do
            {   
                cout << endl;
                cout << "Press 1 to order meal, press 2 to see cart, press 3 to checkout" << endl;
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        custReservation.updateOrder();
                        break;

                    case 2:
                        custReservation.displayCurrentOrder();
                        break;
                }
            } while (choice != 3);

            // Print Summary
            string line(15,'-');
            cout << line << endl;
            cout << "Reservation Summary" << endl;
            cout << "Reservation Number: " << cust.getReserveNum() << endl;
            cout << "Customer Name: " << cust.getName() << endl;
            cout << "Phone Number: " << cust.getPhone() << endl;
            cout << "VIP Status: " << cust.getIsVIP() << endl << endl;
            cout << "Reservation Date & Time: " << cust.getDate() << " at " << cust.getTime() << endl;
            cout << "Number of Pax: " << custReservation.getQuantity() << endl;
            custReservation.displayCurrentOrder();

            cout << "Do you wish to make another reservation? (Y/N): ";
            cin >> status;
        } while (status == 'y' || status == 'Y');

        system("pause");
        return 0;
    }