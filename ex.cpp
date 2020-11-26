#include <iostream>
#include <string>

class Obiect{};

class Fiinta{
    private : 
        std::string numeFiinta;
        int marime;
    // protected:
    //     Fiinta(){} //permit construirea automata a constr
    //     ~Fiinta(){}//si a destructorului
    // private :
    //     //Item 6 - prevenirea folosirii copy constructor si copy operator 
    //     //declarare fara implementare
    //     Fiinta(const Fiinta&); //previn copierea
    //     Fiinta& operator = (const Fiinta&); 
    public : 
        Fiinta(){}
        //copy constructor
        Fiinta(const Fiinta& f): numeFiinta(f.numeFiinta),marime(f.marime){}

        //copy assignment operator
        Fiinta& operator=(const Fiinta& f){

            numeFiinta = f.numeFiinta;
            marime=f.marime;
            return *this;
        }

};

class Persoana : private Fiinta{
    private:
    std:: string nume;
    std:: string prenume;
    int varsta;
    Obiect *ob;
     
    //Item 6 - prevenirea folosirii copy constructor si copy operator 
    //(puteau fi folosite de metodele membre si prietene ale clasei)
    // Persoana(const Persoana&);
    // Persoana& operator=(const Persoana&);

    public: 
        //Item4 -init cu lista de membri 
        Persoana(std::string nume, std::string prenume, int varsta,Obiect *ob)
            : nume(nume),prenume(prenume),varsta(varsta),ob(ob){}

        //copy constructor
        Persoana(const Persoana& p): Fiinta(p),nume(p.nume),prenume(p.prenume),varsta(p.varsta),ob(p.ob){}

        //copy assignment operator Item 12
        //Item 10 - have assignment operators return a reference to this
        Persoana& operator =(const Persoana& p){
        // poate fii aceeasi persoana

        //Item 11 -> Handle assignment to self operator
        if(this == &p) return *this; //pt eficienta
        std::cout<<"Nu s-au assignat obiecte identice! se poate continua executia"<<std::endl;
        
        Fiinta::operator=(p);
        nume= p.nume;
        prenume = p.prenume;
        varsta= p.varsta;
        Obiect* originalOb = ob;
        ob = new Obiect(*p.ob);
        //cand apeleze delete pot sterge ambele obiecte
        delete originalOb;
        //dc apare o execeptie
        return *this;
    }
        
        std::string getNume(){
            return nume;
        }
        std::string getPrenume(){
            return prenume;
        }
        int getVarsta(){
            return varsta;
        }
};





int main(){

    Persoana p("Benzar","Anna",22,new Obiect); 
    Persoana p2("Benzar","Eny",32,new Obiect);

    p2=p;

    std::string numeP = p.getNume();
    std::string prenumeP = p.getPrenume();
    int varstaP = p2.getVarsta();

    std::cout<<"Prima persoana: "<<std::endl;
    std::cout<< "Nume: "<<numeP<<std::endl; 
    std::cout<< "Prenume: "<<prenumeP<<std::endl;
    std::cout<< "Varsta: "<<varstaP<<std::endl;

}