#include <iostream>
#include <string>

class Om{
    protected:
    Om(){} //permit construirea automata a constr
    ~Om(){}//si a destructorului
    private :
        //Item 6 - prevenirea folosirii copy constructor si copy operator 
        //declarare fara implementare
        Om(const Om&); //previn copierea
        Om& operator = (const Om&); 
};

class Persoana : private Om{
    private:
    std:: string nume;
    std:: string prenume;
    int varsta;
     
    //Item 6 - prevenirea folosirii copy constructor si copy operator 
    //(puteau fi folosite de metodele membre si prietene ale clasei)
    // Persoana(const Persoana&);
    // Persoana& operator=(const Persoana&);

    public: 
        //Item4 -initi cu lista de membri 
        Persoana(std::string nume, std::string prenume, int varsta)
            : nume(nume),prenume(prenume),varsta(varsta){}

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

    Persoana p("Benzar","Anna",22); 
    Persoana p2("Ioana","Pec",33);
    //Persoana p3(p); 
    //p3 = p; 
    std::string numeP = p.getNume();
    std::string prenumeP = p.getPrenume();
    int varstaP = p.getVarsta();

    std::cout<<"Prima persoana: "<<std::endl;
    std::cout<< "Nume: "<<numeP<<std::endl; 
    std::cout<< "Prenume: "<<prenumeP<<std::endl;
    std::cout<< "Varsta: "<<varstaP<<std::endl;

}