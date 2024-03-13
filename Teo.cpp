#include <iostream>
#include <string>
#include <vector>
using namespace std;

class drink{
private:
    string drinkChoice;       //tipul bauturii
    float price;              //pretul bauturii
public:
    drink(string drinkName = "", float priceTag = 0) {
        drinkChoice = drinkName;
        price = priceTag;
    }
    friend ostream& operator<<(ostream& COUT, const drink& myDrink) {
        cout<<myDrink.drinkChoice<<" "<<myDrink.price;
        return COUT;
    }
    string drinkName() {
        return drinkChoice;
    }
    float drinkPrice() {
        return price;
    }
    ~drink(){
        drinkChoice = "";
        price = 0;
    }
};

class myCart {
private:
    vector<string> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    //int amount;                         //nr de bauturi din cos
    float price;                        //suma care urmeaza sa fie platita
    vector<float> priceList;            //lista prteurilor

public:
    myCart(){              //constructor de initializare
        myDrinks = {};
        //amount = 0;
        price = 0;
        priceList = {};
    }
    void productAdd(string drink, float productPrice){       //pentru cand adaugam un produs in cos, sa actualizam nr. de produse
        //amount ++;
        myDrinks.push_back(drink);
        price += productPrice;
        priceList.push_back(productPrice);
    };
    void productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
        if (myDrinks.size() > 0) {
            //amount --;
            myDrinks.erase(myDrinks.begin() + index);
            price -= priceList[index];
        }
    }
    float cartPrice() {
        return price;
    }
    friend ostream& operator<<(ostream& COUT, const myCart& shopping) {
        COUT<<"Your shopping cart status:"<<endl;
        for (int x = 0; x < size(shopping.myDrinks); x ++) {
            COUT << "Product "<<x + 1<<": "<<shopping.myDrinks[x] << " - " << shopping.priceList[x] << endl;
        }
        COUT<< shopping.price<<endl;
        return COUT;}
    ~myCart(){
        myDrinks = {};
        //amount = 0;
        price = 0;
        priceList = {};}
}cart;

class myAccount {
private:
    string userName;                //nume de utlizator
    string password;                //parola
public:
    myAccount(string name = "", string Password = "") {
        userName = name;
        password = Password;}
    friend ostream& operator<<(ostream& COUT, const myAccount& acc) {
        COUT<< acc.userName;
        return COUT;}           //pt afisarea numelui utilizatorului!!! parola ramane tot private!! :)

    ~myAccount(){
        userName = "";
        password = "";
    }
}user;

myAccount userRead() {
    string name, password;
    cout<<"Username: ";
    cin>>name;
    cout<<"Password: ";
    cin>>password;
    cout<<endl;
    myAccount user = myAccount(name, password);
    return user;
}


long int creditCard;
string address;

int main() {
    cout<<"Chamberlain Coffee - Easy Mobile & Online Ordering & Delivery"<<endl;

    cout<<"Connect to your account: "<<endl;
    user = userRead();
    cout<<"Well hello "<<user<<"! We are glad to have you back! :)"<<endl;
    cout<<"What would you like to do today? Choose one of the following options!"<<endl;
    //pana aici utilizatorul a introdus datele personale -> de cautat cum fac ca atunci cand utilizatorul scrie
    // de la tastatura sa apara * in loc de caracter??

    cout<<"1: Menu"<<endl;
    cout<<"0: Exit"<<endl<<endl;
    cout<<"Press 1 to see the menu / start adding products to your cart! :D"<<endl;
    cout<<"Press 0 to exit the app :("<<endl;
    int input;
    cin>>input;
    if (input == 1) {
        short int input2, inputDelete;
        vector<drink> coffeeMenu = {drink("Iced Latte", 5.99), drink("Cold Brew", 3.99), drink("Matcha Latte", 6.49),
                                    drink("Pink Drink Refresher", 4.59), drink("Vanilla Sweet Cream Cold Brew", 6.49),
                                    drink("Vanilla Cremè", 5.49), drink("Cinnamon Caramel Cream Cold Brew", 3.99),
                                    drink("Cold Brew", 4.99), drink("Caramel Ribbon Crunch Frappucino", 5.49),
                                    drink("Caramel Ribbon Crunch Frappucino", 6.99), drink("Espresso", 2.99),
                                    drink("Fiji Water", 3.29)};
        cout << endl << "Here are your options:" << endl;
        for (int x = 0; x < 11; x++) {
            cout << "Product " << x + 1 << ": " << coffeeMenu[x] << endl;
        }
        cout << "If you want to delete a product from your cart, press '20'." << endl;
        cout << "When you are done making your cart, just press 0! :)" << endl << endl;
        while (input != 0) {
            cin >> input2;
            if (input2 != 20) {
                if (input2 != 0) {
                    cart.productAdd(coffeeMenu[input - 1].drinkName(), coffeeMenu[input - 1].drinkPrice());
                    cout << cart;
                    input = input2;
                } else {
                    cout << "Are you sure you want to proceed to checkout? This action is irreversible!" << endl;
                    cout << "Press 1 to go back to editing your shopping cart!" << endl;
                    cout << "Press 0 to go to checkout" << endl;
                    cin >> input2;
                    input = input2;
                }
            } else {
                cout << "Choose the index of the product that you would like to delete from your cart!" << endl;
                cin >> inputDelete;       //am gasit un produs pe care vrem sa il stergem & inputDelete retine al catelea produs sa fie sters;
                cart.productDelete(inputDelete - 1);
                cout << cart;
            }
        }
        cout << "You are being redirected on the checkout page..." << endl;
        cout << "Subtotal: " << cart.cartPrice();     //de aici urmeaza partea de checkout etc!!
        cout << endl << "Are you sure you don't want to edit your cart?" << endl << "Press 1 to go ahead to order!" << endl
             << "Press 0 to exit" << endl;
        cin >> input2;
        if (input2 == 1) {
            cout << endl << "Introduce the delivery information!" << endl;
            cout << "Address: ";
            cin >> address;
            cout << endl << "Choose one of the following payment options: " << endl << "1: Credit Card" << endl
                 << "2: Cash on delivery" << endl;
            cin >> input;
            if (input == 1) {
                cout << "Press 1 to move forward to credit card information!" << endl
                     << "Press 0 to cancel and exit the app." << endl;
                cin >> input2;
                if (input2 == 0) {
                    cout << "We are sorry that you are leaving!";
                    return 0;
                } else {
                    cout << "Introduce your credit card information" << endl;
                    cout << "Card number: ";
                    cin >> creditCard;
                    cout << "CVV/CVC/CVC2: ";
                    cin >> input;
                    cout << "Press 1 to place the order!" << endl << "Press 0 to cancel and exit the app." << endl;
                    cin >> input;
                    if (input == 1) {
                        cout
                                << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible!";
                    } else {
                        cout << "We are sorry that you are living!";
                    }
                    return 0;
                }
            } else {
                cout << "Press 1 to confirm the order!" << endl << "Press 0 to cancel and exit the app." << endl;
                cin >> input;
                if (input == 0) {
                    cout << "We are sorry that you are living!";
                } else {
                    cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible!";
                }
                return 0;
            }
        }
        else {
            cout<<"We are sorry to see you leave!";
            return 0;
        }
    }
    else {
        if (input == 0){
            return 0;
        }
    }
    return 0;
}

/*idee proiect:
 * un cos de cumparaturi pentru o aplicatie -> starbucks
 * utilizatorul poate face urmatoarele lucruri: poate pune produse in cos, le poate sterge si poate finaliza plata
 * se pun 2 conditii: poate achizitiona maxim 4 produse + poate adauga doar unul din fiecare
 * pe cel mai ieftin nu il mai plateste -> urmeaza sa fie facuta partea asta
 */

/*
 * exCode:
//    void priceAdd(float drinkPrice){
//        price += drinkPrice;
//    }
//    void priceDelete(float drinkPrice){
//        price -= drinkPrice;
//    }
//    void cartPrice(float priceToAdd) {      //pentru cand adaugam un produs in cos, sa ii actaulizam pretul
//        price = price + priceToAdd;
//    }

 //    myCart(int index) {
//        myDrinks.push_back(options)
//    }
    //nu voi folosi constructori parametrizati datorita logicii aplicatiei: cosul este, la intrarea in aplicatie, gol,
    //iar pe parcursul input-urilor acesta se va umple
 */
