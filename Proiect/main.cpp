#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Masina {
private:
    string Marca;
    string Model;
    float Pret;
    int An;

public:
    Masina(){
        Marca = "";
        Model = "";
        Pret = 0;
        An = 0;
    }

    Masina(string marca, string model, float pret, int an){ //masina nu este noua, punem datele corespunzatorare
        Marca = marca;
        Model = model;
        Pret = pret;
        An = an;
    }

    Masina(string marca, string model, float pret) { //cand masine este noua, putem da doar marca si modelul, anul fiind 2024
        Marca = marca;
        Model = model;
        Pret = pret;
        An = 2024;
    }

    void operator=(Masina& car){  //operator de copiere
        Marca = car.Marca;
        Model = car.Model;
        Pret = car.Pret;
        An = car.An;
    }

    Masina(const Masina& car) {  //consructor de copiere
        Marca = car.Marca;
        Model = car.Model;
        Pret = car.Pret;
        An = car.An;
    }

    ~Masina () {

    }

    int operator==(Masina& car){
        return car.Marca == Marca and car.Model == Model and car.An == An;
    }

    string GetMarca(){
        return Marca;
    }

    string GetModel() {
        return Model;
    }

    float GetPret() {
        return Pret;
    }

    int GetAn() {
        return An;
    }

    friend istream& operator>>(istream& in, Masina& car); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& out, const Masina& car); //operator de afisare supraincarcat
};

istream& operator>>(istream& in, Masina& car) {
    cout << "Marca masinii: " << endl;
    in >> car.Marca;

    cout << "Modelul masinii: " << endl;
    in >> car.Model;

    cout << "Pretul masinii: " << endl;
    in >> car.Pret;

    cout << "Anul de fabricatie: " << endl;
    in >> car.An;

    return in;
}

ostream& operator<<(ostream& out, const Masina& car) {
    out << "Marca: " << car.Marca << endl;
    out << "Model: " << car.Model << endl;;
    out << "Pret: " << car.Pret << endl;
    out << "An: " << car.An << endl;
    return out;
}


class Dealer_Auto: Masina {
private:
    float PretFinal;
    vector <Masina> Flota;
public:
    Dealer_Auto() {
        PretFinal = 0;
        Flota.push_back(Masina("AUDI", "A3", 12384.14, 2014));
        Flota.push_back(Masina("AUDI", "Q7", 32981.92 ));
        Flota.push_back(Masina("AUDI", "A8", 7899.99,2005 ));
        Flota.push_back(Masina("BMW", "M4", 82394.57, 2019 ));
        Flota.push_back(Masina("BMW", "E46", 3200.50, 1999 ));
        Flota.push_back(Masina("BMW", "F92", 12873.82, 2012 ));
        Flota.push_back(Masina("DACIA", "LOGAN", 2000.99, 2005 ));
        Flota.push_back(Masina("DACIA", "JOGGER", 16832.67 ));
        Flota.push_back(Masina("DACIA", "DUSTER", 22874.23 ));
        Flota.push_back(Masina("NISSAN", "JUKE", 16823.23, 2016 ));
        Flota.push_back(Masina("NISSAN", "ALTIMA", 20175.75, 2014 ));
        Flota.push_back(Masina("NISSAN", "QASHQAI", 38024.76 ));
        Flota.push_back(Masina("FERRARI", "812 GTS", 282983.93, 2023 ));
        Flota.push_back(Masina("FERRARI", "SF90", 482983.92 ));
        Flota.push_back(Masina("FERRARI", "F430", 180923.99, 2004 ));
        Flota.push_back(Masina("PORSCHE", "CAYENNE", 88928.72, 2013 ));
        Flota.push_back(Masina("PORSCHE", "911 GT3", 32981.92, 2007 ));
        Flota.push_back(Masina("PORSCHE", "PANAMERA", 32981.92 ));
    }

    void VerificareStocMasina(string Marca, string Model) {
        bool ok1 = 0, ok2 = 0;
        for(int i = 0; i < Flota.size(); i++)
            if (Marca == Flota[i].GetMarca())
                ok1 = 1;
        for(int i = 0; i < Flota.size(); i++)
            if (Model == Flota[i].GetModel())
                ok2 = 1;
        if (ok1 == 0 || ok2 == 0)
            cout << "Masina cautata nu este disponibila in stocul nostru!" << endl;
        else
            cout << "Masina se afla in stoc." << endl;
    }

    void Vinde(string Marca, string Model) {
        float PretMasina = ObtinePretMasina(Marca, Model);
        int AnFab = ObtineAnFab(Marca, Model);
        if (Marca == "DACIA" || Marca == "NISSAN")
        {
            if (Model == "LOGAN" || Model == "JOGGER" || Model == "ALTIMA" || Model == "QASHQAI")
            {
                if (AnFab == 2024)
                    cout << "Masina nu este de cea mai inalta calitate dar pentru ca este noua veti suferi o penalizare mai mica, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.3) << endl;
                else
                    cout << "Masina nu este de cea mai inalta calitate si nu este nici noua, pretul oferit de noi este: " << PretMasina - (PretMasina * 0.35) << endl;
            }
            else if (Model == "DUSTER" || Model == "JUKE")
            {
                if (AnFab == 2024)
                    cout << "Masina este noua si este cautata pe piata, asa ca veti avea o penalizare redusa, pretul nostru este: " << PretMasina - (PretMasina * 0.25) << endl;
                else
                    cout << "Masina nu este noua, dar este cautata pe piata, asa ca veti beneficia de un pret special: " << PretMasina - (PretMasina * 0.3) << endl;
            }
        }
        else if (Marca == "AUDI" || Marca == "BMW")
        {
            if (Model == "A3" || Model == "A8" || Model == "E46" || Model == "F92")
            {
                if (AnFab == 2024)
                    cout << "Masina este de o calitate medie si pentru ca este noua veti suferi o penalizare mai mica, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.25) << endl;
                else
                    cout << "Masina este de o calitate medie, dar nu este noua, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.30) << endl;
            }
            else if (Model == "M4" || Model == "Q7")
            {
                if (AnFab == 2024)
                    cout << "Masina este noua si este cautata pe piata, asa ca veti avea o penalizare redusa, pretul nostru este: " << PretMasina - (PretMasina * 0.2);
                else
                    cout << "Masina nu este noua, dar este cautata pe piata, asa ca veti beneficia de un pret special: " << PretMasina - (PretMasina * 0.25);
            }
        }
        else if (Marca == "PORSCHE" || Marca == "FERRARI")
        {
            if (Model == "F430" || Model == "SF90" || Model == "CAYENNE" || Model == "911 GT3")
            {
                if (AnFab == 2024)
                    cout << "Masina este de o calitate premium si pentru ca este noua veti suferi o penalizare mai mica, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.2) << endl;
                else
                    cout << "Masina este de o calitate premium, dar nu este noua, iar pretul oferit de noi este: " << PretMasina - (PretMasina * 0.25) << endl;
            }
            else if (Model == "812 GTS" || Model == "PANAMERA")
            {
                if (AnFab == 2024)
                    cout << "Masina este noua si este cautata pe piata, asa ca veti avea o penalizare redusa, pretul nostru este: " << PretMasina - (PretMasina * 0.15);
                else
                    cout << "Masina nu este noua, dar este cautata pe piata, asa ca veti beneficia de un pret special: " << PretMasina - (PretMasina * 0.2);
            }
            else cout << "Nu va putem face o oferta deoarece masina nu se afla in stockul nostru in acest moment!" << endl;
        }
    }

    float GetPret(){
        return PretFinal;
    }

    int GetLungime() {
        return Flota.size();
    }

    Masina ObtineMasina(int i){
        return Flota[i];
    }

    float ObtinePretMasina(string Marca, string Model) {
        for(int i = 0; i < Flota.size(); i++)
            if(Marca == Flota[i].GetMarca() and Model == Flota[i].GetModel())
                return Flota[i].GetPret();
    }
    int ObtineAnFab(string Marca, string Model){
        for(int i = 0; i < Flota.size(); i++)
            if(Marca == Flota[i].GetMarca() and Model == Flota[i].GetModel())
                return Flota[i].GetAn();
    }

};

//class Banca {
//
//};

int main() {
    Masina car1("BMW", "M4", 30000);
    Masina car2("Audi", "A3", 50000, 2016 );
    Dealer_Auto dealer;
    string Marca, Model;
    cout << "Introduceti Marca: " << endl;
    cin >> Marca;
    cout << "Introduceti Modelul: " << endl;
    cin >> Model;
//    dealer.Vinde(Marca, Model);
    dealer.VerificareStocMasina(Marca, Model);
}
