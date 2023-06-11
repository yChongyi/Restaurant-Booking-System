#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string line=line.assign(20,'-');

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
        string getDate(){
            return date;
        }
        string getTime(){
            return time;
        }
        int getReserveNum(){
            return reservationNum;
        }
};

class Customer {
    string name;
    string phoneNum;
    bool status;

    public:
    Reservation r;
    void set(string n="", string p="", bool v=1){
        name=n;
        phoneNum=p;
        status=v;
    }
    string getName(){
        return name;
    }
    string getPhone(){
        return phoneNum;
    }
    bool getVIP(){
        return status;
    }
    void input(){
        string line;
        line.assign(15,'-');
        cout<<line<<"Welcome to XXXX Restaurant Booking Website"<<line<<endl
            <<endl<<"Please enter the information required: "<<endl<<endl
            <<"Name: ";
        getline(cin,name);
        cout<<"Phone Number: "; //can add verification (phone number format)
        cin>>phoneNum;
        cout<<endl<<endl;
    }
};

class Meal {
    protected:
    int course;

    public:
    Meal(int c=1){
        course=c;
    }
    int getCourse(){
        return course;
    }
    string getDescription(){
        return "Meal";
    }
    virtual void input(){}
    void display(){
        string line;
        line.assign(15,'-');
        char choice='N';
        cout<<"We offer 3 set of menus where you can customize its appetizer, entree, and desert."<<endl
            <<line<<line<<endl;
        while(choice!='Y'&&choice!='y'){
            do{
                cout<<"\tMenu 1-RM100"<<endl
                <<"\tMenu 2-RM150"<<endl
                <<"\tMenu 3-RM200"<<endl<<line<<line<<endl
                <<"Press 1 to view Menu 1"<<endl
                <<"Press 2 to view Menu 2"<<endl
                <<"Press 3 to view Menu 3"<<endl;
                cin>>course;
                if(course!=1&&course!=2&&course!=3){
                    cout<<"Invalid input, please try again :)"<<endl;
                }
            }while(course!=1&&course!=2&&course!=3);
            cout<<"Are you sure to proceed to customize Menu "<<course<<"?"<<endl
                <<"Enter 'Y' to proceed \t Enter any keys to choose again ";
            cin>>choice;
            cout<<line<<line<<endl;
        }
    }
};

class Appetizer : public Meal{
    int appCode;
    string appName;
    string app100[3]={"Caesar Salad", "Garlic Bread", "Soup of the Day"};
    string app150[3]={"Caprese Salad", "Shrimp Cocktail", "Bruschetta"};
    string app200[3]={"Escargots in Garlic Butter", "Lobster Bisque", "Baked Brie with Cranberry Chutney"};

    public:
    Appetizer (int c=0, string n=""){
        appCode=c;
        appName=n;
    }
    int getAppCode(){
        return appCode;
    }
    string getAppName(){
        return appName;
    }
    string getDescription(){
        return "Appetizer: ";
    }
    void input(){
        display();
        do{
            if (course==1){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<app100[i]<<endl;
                }
            }
            else if (course==2){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<app150[i]<<endl;
                }
            }
            else if (course==3){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<app200[i]<<endl;
                }
            }
            cout<<"Enter 1-3 to confirm your choice: ";
            cin>>appCode;
            cout<<endl;
            if (appCode!=1&&appCode!=2&&appCode!=3){
                cout<<"Invalid input, please try again :)\n";
            }
        }while(appCode!=1&&appCode!=2&&appCode!=3);
    }
};

class Entree : public Meal{
    int entCode;
    string entName;
    string ent100[3]={"Grilled Chicken Breast", "Spaghetti Carbonara", "Fish and Chips with Tartar Sauce"};
    string ent150[3]={"Grilled Ribeye Steak with Grilled Asparagus", "Pan-Seared Salmon with Lemon Butter Sauce", "Vegetarian Pasta Primavera"};
    string ent200[3]={"Filet Mignon with Truffle Mashed Potatoes", "Grilled Sea Bass with Lemon Caper Sauce", "Chicken Parmesan with Spaghetti Marinara"};

    public:
    Entree (int c=0, string n=""){
        entCode=c;
        entName=n;
    }
    int getEntCode(){
        return entCode;
    }
    string getEntName(){
        return entName;
    }
    string getDescription(){
        return "Entree: ";
    }
    void input(){
        do{
            if (course==1){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<ent100[i]<<endl;
                }
            }
            else if (course==2){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<ent150[i]<<endl;
                }
            }
            else if (course==3){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<ent200[i]<<endl;
                }
            }
            cout<<"Enter 1-3 to confirm your choice: ";
            cin>>entCode;
            cout<<endl;
            if (entCode!=1&&entCode!=2&&entCode!=3){
                cout<<"Invalid input, please try again :)\n";
            }
        }while(entCode!=1&&entCode!=2&&entCode!=3);
    }
};

class Dessert : public Meal{
    int dessCode;
    string dessName;
    string set100[3]={"Chocolate Brownie with Vanilla Ice Cream", "Fresh Fruit Salad", "Crème Brûlée"};
    string set150[3]={"New York Cheesecake with Raspberry Sauce", "Tiramisu", "Apple Pie with Vanilla Sauce"};
    string set200[3]={"Molten Chocolate Lava Cake with Vanilla Bean Ice Cream", "Crème Brûlée Trio (Vanilla, Chocolate, and Coffee)", "Berry Pavlova with Whipped Cream"};

    public:
    Dessert (int c=0, string n=""){
        dessCode=c;
        dessName=n;
    }
    int getDessCode(){
        return dessCode;
    }
    string getDessName(){
        return dessName;
    }
    string getDescription(){
        return "Dessert: ";
    }
    void input(){
        do{
            if (course==1){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<set100[i]<<endl;
                }
            }
            else if (course==2){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<set150[i]<<endl;
                }
            }
            else if (course==3){
                for(int i=0; i<3; i++){
                    cout<<"\t"<<i+1<<". "<<set200[i]<<endl;
                }
            }
            cout<<"Enter 1-3 to confirm your choice: ";
            cin>>dessCode;
            cout<<endl;
            if (dessCode!=1&&dessCode!=2&&dessCode!=3){
                cout<<"Invalid input, please try again :)\n";
            }
        }while(dessCode!=1&&dessCode!=2&&dessCode!=3);
    }
};

int main(){

    Customer c;
    c.input();
    
    Appetizer a;
    cout<<a.getDescription()<<endl;
    a.input();

    Entree e;
    cout<<e.getDescription()<<endl;
    e.input();

    Dessert d;
    cout<<d.getDescription()<<endl;
    d.input();

    system("pause");
    return 0;
}