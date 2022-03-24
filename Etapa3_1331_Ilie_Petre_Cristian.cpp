#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

class Angajat{

    char* nume;
    string prenume;
    char initiala_tata;
    int varsta;
    const int id_angajat;
    bool manager;
    float calificativ_angajator;
    double nr_comenzi_realizate_in_total;
    int* nr_comenzi_efectuate_in_ultima_saptamana;
    string* cele_mai_vandute_produse;

public:
    static int contorID;
    Angajat():id_angajat(contorID++)
    {
        this->nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        this->prenume="Anonim";
        this->initiala_tata='A';
        this->varsta=0;
        this->manager=false;
        this->calificativ_angajator=0;
        this->nr_comenzi_realizate_in_total=0;
        this->nr_comenzi_efectuate_in_ultima_saptamana=new int[7];
        for (int i=0;i<7;i++)
            this->nr_comenzi_efectuate_in_ultima_saptamana[i] = 0;
        this->cele_mai_vandute_produse=new string[3];
        for (int i=0;i<3;i++)
            this->cele_mai_vandute_produse[i]="NULL";

    }

    Angajat(char* nume,string prenume,char initiala_tata,int varsta,bool manager,float calificativ_angajator,double nr_comenzi_realizate_in_total,int* nr_comenzi_efectuate_in_ultima_saptamana,string* cele_mai_vandute_produse):id_angajat(contorID++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=prenume;
        this->initiala_tata=initiala_tata;
        this->varsta=varsta;
        this->manager=manager;
        this->calificativ_angajator=calificativ_angajator;
        this->nr_comenzi_realizate_in_total=nr_comenzi_realizate_in_total;
        this->nr_comenzi_efectuate_in_ultima_saptamana=new int[7];
        for (int i=0;i<7;i++)
            this->nr_comenzi_efectuate_in_ultima_saptamana[i]=nr_comenzi_efectuate_in_ultima_saptamana[i];
        this->cele_mai_vandute_produse=new string[3];
        for (int i=0;i<3;i++)
            this->cele_mai_vandute_produse[i]=cele_mai_vandute_produse[i];
    }

    Angajat(const Angajat& ang):id_angajat(ang.id_angajat)
    {
        this->nume=new char[strlen(ang.nume)+1];
        strcpy(this->nume,ang.nume);
        this->prenume=ang.prenume;
        this->initiala_tata=ang.initiala_tata;
        this->varsta=ang.varsta;
        this->manager=ang.manager;
        this->calificativ_angajator=ang.calificativ_angajator;
        this->nr_comenzi_realizate_in_total=ang.nr_comenzi_realizate_in_total;
        this->nr_comenzi_efectuate_in_ultima_saptamana=new int[7];
        for (int i=0;i<7;i++)
            this->nr_comenzi_efectuate_in_ultima_saptamana[i]=ang.nr_comenzi_efectuate_in_ultima_saptamana[i];
        this->cele_mai_vandute_produse=new string[3];
        for (int i=0;i<3;i++)
            this->cele_mai_vandute_produse[i]=ang.cele_mai_vandute_produse[i];
    }

    Angajat(char* nume,string prenume,int varsta):id_angajat(contorID++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=prenume;
        this->initiala_tata='A';
        this->varsta=varsta;
        this->manager=false;
        this->calificativ_angajator= 0;
        this->nr_comenzi_realizate_in_total= nr_comenzi_realizate_in_total;
        this->nr_comenzi_efectuate_in_ultima_saptamana=new int[7];
        for (int i=0;i<7;i++)
            this->nr_comenzi_efectuate_in_ultima_saptamana[i]= 0;
        this->cele_mai_vandute_produse=new string[3];
        for (int i=0;i<3;i++)
            this->cele_mai_vandute_produse[i]= "NULL";
    }

    ~Angajat()
    {
        if(this->nume!=NULL)
            delete[] this->nume;

        if(this->nr_comenzi_efectuate_in_ultima_saptamana!=NULL)
            delete[] this->nr_comenzi_efectuate_in_ultima_saptamana;

        if(this->cele_mai_vandute_produse!=NULL)
            delete[] this->cele_mai_vandute_produse;

    }


    void setNume(char* nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

    }

    char* getNume()
    {
        return this->nume;
    }

    void setPrenume(string prenume)
    {
        this->prenume=prenume;
    }

    string getPrenume()
    {
        return this->prenume;
    }

    void setInitiala(char initiala_tata)
    {
        this->initiala_tata=initiala_tata;
    }

    char getInitiala()
    {
        return this->initiala_tata;
    }

    void setVarsta(int varsta)
    {
        this->varsta=varsta;
    }

    int getVarsta()
    {
        return this->varsta;
    }

    void setManager(bool manager)
    {
        this->manager=manager;
    }

    bool getManager()
    {
        return this->manager;
    }

    void setCalificativ(float calificativ_angajator)
    {
        this->calificativ_angajator=calificativ_angajator;
    }

    float getCalificativ()
    {
        return this->calificativ_angajator;
    }

    void setNrComenziTotal(double nr_comenzi_realizate_in_total)
    {
        this->nr_comenzi_realizate_in_total=nr_comenzi_realizate_in_total;
    }

    double getNrComenziTotal()
    {
        return this->nr_comenzi_realizate_in_total;
    }

    void setNrComenziSapt(int* nr_comenzi_efectuate_in_ultima_saptamana)
    {
        if (this->nr_comenzi_efectuate_in_ultima_saptamana != NULL)
            delete[] this->nr_comenzi_efectuate_in_ultima_saptamana;
        this->nr_comenzi_efectuate_in_ultima_saptamana = new int[7];
        for (int i=0;i<7;i++)
            this->nr_comenzi_efectuate_in_ultima_saptamana[i]=nr_comenzi_efectuate_in_ultima_saptamana[i];
    }

    int* getNrComenziSapt()
    {
        return this->nr_comenzi_efectuate_in_ultima_saptamana;
    }

    void setCeleVand(string* cele_mai_vandute_produse)
    {
        if (this->cele_mai_vandute_produse != NULL)
            delete[] this->cele_mai_vandute_produse;
        this->cele_mai_vandute_produse = new string[3];
        for (int i=0;i<3;i++)
            this->cele_mai_vandute_produse[i]=cele_mai_vandute_produse[i];
    }

    string* getCeleVand()
    {
        return this->cele_mai_vandute_produse;
    }

    int getID()
    {
        return id_angajat;
    }

    Angajat& operator=(const Angajat& ang)
    {
        if (this != &ang)
        {
            this->nume=new char[strlen(ang.nume)+1];
        strcpy(this->nume,ang.nume);
        this->prenume=ang.prenume;
        this->initiala_tata=ang.initiala_tata;
        this->varsta=ang.varsta;
        this->manager=ang.manager;
        this->calificativ_angajator=ang.calificativ_angajator;
        this->nr_comenzi_realizate_in_total=ang.nr_comenzi_realizate_in_total;
        this->nr_comenzi_efectuate_in_ultima_saptamana=new int[7];
        for (int i=0;i<7;i++)
            this->nr_comenzi_efectuate_in_ultima_saptamana[i]=ang.nr_comenzi_efectuate_in_ultima_saptamana[i];
        this->cele_mai_vandute_produse=new string[3];
        for (int i=0;i<3;i++)
            this->cele_mai_vandute_produse[i]=ang.cele_mai_vandute_produse[i];
        }

        return *this;
    }

    friend istream& operator>>(istream& in,Angajat& ang);
    friend ostream& operator<<(ostream& out,const Angajat& ang);

    const Angajat& operator++()
    {
        this->nr_comenzi_realizate_in_total++;
        return *this;
    }

    const Angajat operator++(int)
    {
        Angajat aux(*this);
        this->nr_comenzi_realizate_in_total++;
        return aux;
    }


    const Angajat& operator-- ()
    {
        this->nr_comenzi_realizate_in_total--;
        return *this;
    }

    const Angajat operator--(int)
    {
        Angajat aux(*this);
        this->nr_comenzi_realizate_in_total--;
        return aux;
    }

    const Angajat operator+=(int index)
    {
        this->nr_comenzi_realizate_in_total+=index;
        return *this;
    }

    const Angajat operator-=(int index)
    {
        this->nr_comenzi_realizate_in_total-=index;
        return *this;
    }

    bool operator<(const Angajat& ang)
    {
        if (this->nr_comenzi_realizate_in_total < ang.nr_comenzi_realizate_in_total)
            return true;
        else
            return false;
    }

    bool operator>(const Angajat& ang)
    {
        if (this->nr_comenzi_realizate_in_total > ang.nr_comenzi_realizate_in_total)
            return true;
        else
            return false;
    }

    void SfarsitSaptamana()
    {
        int v = 0;
        for (int i=0;i<7;i++)
        {

            v = v + this->nr_comenzi_efectuate_in_ultima_saptamana[i];
            this->nr_comenzi_efectuate_in_ultima_saptamana[i] = 0;
        }

        this->nr_comenzi_realizate_in_total += v;
    }

    int Salariu()
    {
        int v = 0;
        v = int(this->calificativ_angajator) * 250;
        if (this->calificativ_angajator - int(calificativ_angajator) > 0.5)
            v += 100;
        return v;
    }

};

istream& operator>>(istream& in,Angajat& ang)
{
    cout<<"Nume: ";
    in>>ang.nume;
    cout<<"Prenume: ";
    in>>ang.prenume;
    cout<<"Initiala tata: ";
    in>>ang.initiala_tata;
    cout<<"Varsta: ";
    in>>ang.varsta;
    cout<<"Manager? (1/0): ";
    in>>ang.manager;
    cout<<"Calificativ acordat la angajare: ";
    in>>ang.calificativ_angajator;
    cout<<"Numar de comenzi realizate in total: ";
    in>>ang.nr_comenzi_realizate_in_total;
    cout<<"Numar de comenzi realizate in ultimele 7 zile: ";
    ang.nr_comenzi_efectuate_in_ultima_saptamana=new int[7];
    for (int i=0;i<7;i++)
        in>>ang.nr_comenzi_efectuate_in_ultima_saptamana[i];
    cout<<"Cele mai vandute 3 produse: ";
    ang.cele_mai_vandute_produse=new string[3];
    for (int i=0;i<3;i++)
        in>>ang.cele_mai_vandute_produse[i];
    return in;
}

ostream& operator<<(ostream& out,const Angajat& ang)
{
    out<<"ID Angajat: "<<ang.id_angajat<<endl;
    out<<"Nume: "<<ang.nume<<endl;
    out<<"Prenume: "<<ang.prenume<<endl;
    out<<"Initiala tata: "<<ang.initiala_tata<<endl;
    out<<"Varsta: "<<ang.varsta<<endl;
    out<<"Manager: ";
    if (ang.manager == true)
        out<<"Da"<<endl;
    else
        out<<"Nu"<<endl;
    out<<"Calificativ acordat la angajare: "<<ang.calificativ_angajator<<endl;
    out<<"Numar de comenzi realizate in total: "<<ang.nr_comenzi_realizate_in_total<<endl;
    out<<"Numar de comenzi realizate in ultimele 7 zile: ";
    for (int i=0;i<7;i++)
        out<<ang.nr_comenzi_efectuate_in_ultima_saptamana[i]<<' ';
    out<<endl<<"Cele mai vandute 3 produse: ";
    for (int i=0;i<3;i++)
        out<<ang.cele_mai_vandute_produse[i]<<' ';
    return out;
}


class Produs{

    char* denumire;
    float gramaj;
    float pret;
    float* numar_kj_si_kcal;
    const int id_produs;

public:

    static int contorID2;

    Produs():id_produs(contorID2++)
    {
        this->denumire = new char[strlen("Anonim")+1];
        strcpy(this->denumire,"Anonim");
        this->gramaj = 0;
        this->pret = 0;
        this->numar_kj_si_kcal = new float[2];
        for (int i=0;i<2;i++)
            this->numar_kj_si_kcal[i] = 0;
    }

    Produs(char* denumire,float gramaj,float pret,float numar_kcal):id_produs(contorID2++)
    {
        this->denumire = new char[strlen(denumire)+1];
        strcpy(this->denumire,denumire);
        this->gramaj = gramaj;
        this->pret = pret;
        this->numar_kj_si_kcal = new float[2];
        this->numar_kj_si_kcal[1] = numar_kcal;
        this->numar_kj_si_kcal[0] = numar_kcal * 4.18;
    }

    Produs(float gramaj, float pret):id_produs(contorID2++)
    {
        this->denumire = new char[strlen("Anonim")+1];
        strcpy(this->denumire,"Anonim");
        this->gramaj = gramaj;
        this->pret = pret;
        this->numar_kj_si_kcal = new float[2];
        for (int i=0;i<2;i++)
            this->numar_kj_si_kcal[i] = 0;
    }

    Produs (const Produs& prod):id_produs(prod.id_produs)
    {
        this->denumire = new char[strlen(prod.denumire)+1];
        strcpy(this->denumire,prod.denumire);
        this->gramaj = prod.gramaj;
        this->pret = prod.pret;
        this->numar_kj_si_kcal = new float[2];
        for (int i=0;i<2;i++)
            this->numar_kj_si_kcal[i] = prod.numar_kj_si_kcal[i];
    }

    ~Produs()
    {
        if(this->denumire!=NULL)
            delete[] this->denumire;
        if(this->numar_kj_si_kcal!=NULL)
            delete[] this->numar_kj_si_kcal;
    }

    void setDenumire(char* denumire)
    {
        if (this->denumire != NULL)
            delete[] this->denumire;
        this->denumire = new char[strlen(denumire)+1];
        strcpy(this->denumire,denumire);
    }

    char* getDenumire()
    {
        return this->denumire;
    }

    void setGramaj(int gramaj)
    {
        this->gramaj = gramaj;
    }

    int getGramaj ()
    {
        return this->gramaj;
    }

    void setPret (float pret)
    {
        this->pret = pret;
    }

    int getPret ()
    {
        return this->pret;
    }

    void setKjKCal(float* numar_kj_si_kcal)
    {
        if (this->numar_kj_si_kcal != NULL)
            delete[] this->numar_kj_si_kcal;
        this->numar_kj_si_kcal = new float[2];
        for (int i=0;i<3;i++)
            this->numar_kj_si_kcal[i] = numar_kj_si_kcal[i];
    }

    float* getKjKCal()
    {
        return this->numar_kj_si_kcal;
    }

    int getID()
    {
        return this->id_produs;
    }

    Produs& operator=(const Produs& prod)
    {
        if (this != &prod)
        {
            this->denumire = new char[strlen(prod.denumire)+1];
            strcpy(this->denumire,prod.denumire);
            this->gramaj = prod.gramaj;
            this->pret = prod.pret;
            this->numar_kj_si_kcal = new float[2];
            for (int i=0;i<2;i++)
                this->numar_kj_si_kcal[i] = prod.numar_kj_si_kcal[i];
        }

        return *this;
    }


    friend istream& operator>>(istream& in,Produs& prod);
    friend ostream& operator<<(ostream& out,const Produs& prod);

    float& operator[](int index) // sursa preluata de pe GeeksForGeeks
    {
        if (0<=index && index<2)
            return numar_kj_si_kcal[index];
    }

    Produs operator+(Produs per)
    {
        Produs aux;
        aux.denumire = new char[strlen(per.denumire)+strlen(", ")+strlen(this->denumire)+1];
        strcpy(aux.denumire,per.denumire);
        strcat(aux.denumire,", ");
        strcat(aux.denumire,this->denumire);
        aux.gramaj = this->gramaj+per.gramaj;
        aux.pret = this->pret+per.pret;
        for (int i=0;i<2;i++)
            aux.numar_kj_si_kcal[i] = (per.numar_kj_si_kcal[i]+this->numar_kj_si_kcal[i])/2;
        return aux;
    }

    const Produs operator-(float index)
    {
        index = index / 100;
        this->pret -= index*this->pret;
        return *this;
    }

    explicit operator int(){
        return (int)this->pret;
    }

    bool operator>(const Produs& per)
    {
        if ((this->gramaj * this->numar_kj_si_kcal[1])>(per.gramaj * per.numar_kj_si_kcal[1]))
            return true;
        else
            return false;
    }

    bool operator<(const Produs& per)
    {
        if ((this->gramaj * this->numar_kj_si_kcal[1])<(per.gramaj * per.numar_kj_si_kcal[1]))
            return true;
        else
            return false;
    }

    bool operator==(const Produs& per)
    {
        if ((this->gramaj/this->pret) == (per.gramaj/per.pret))
            return true;
        else
            return false;
    }

    int KcalTotal()
    {
        int v = 0;
        v = this->numar_kj_si_kcal[1];
        v = v * (gramaj*1.0/100);
        return v;
    }


};

istream& operator>>(istream& in,Produs& prod)
{
    cout<<"Denumire produs: ";
    in>>prod.denumire;
    cout<<"Gramaj produs: ";
    in>>prod.gramaj;
    cout<<"Pret produs: ";
    in>>prod.pret;
    prod.numar_kj_si_kcal = new float[2];
    cout<<"Numar calorii per 100g produs: ";
    in>>prod.numar_kj_si_kcal[1];
    prod.numar_kj_si_kcal[0] = prod.numar_kj_si_kcal[1] * 4.18;

    return in;
}

ostream& operator<<(ostream& out,const Produs& prod)
{
    out<<"ID produs: "<<prod.id_produs<<endl;
    out<<"Denumire produs: "<<prod.denumire<<endl;
    out<<"Gramaj produs: "<<prod.gramaj<<"g\n";
    out<<"Pret produs: "<<prod.pret<<" lei\n";
    out<<"Per 100g: "<<prod.numar_kj_si_kcal[0]<<" kj , "<<prod.numar_kj_si_kcal[1]<<" kcal\n";

    return out;
}

class Cuptor{
    string marca;
    int an_fabricatie;
    int an_achizitionare;
    int capacitate_maxima;
    const int id_cuptor;

public:

    static int contorID3;

    Cuptor():id_cuptor(contorID3++)
    {
        this->marca = "Anonim";
        this->an_fabricatie=0;
        this->an_achizitionare=0;
        this->capacitate_maxima=0;
    }

    Cuptor(string marca,int an_fabricatie,int capacitate_maxima):id_cuptor(contorID3++)
    {
        this->marca = marca;
        this->an_fabricatie = an_fabricatie;
        this->an_achizitionare = an_achizitionare;
        this->capacitate_maxima = capacitate_maxima;
    }

    Cuptor(string marca,int capacitate_maxima):id_cuptor(contorID3++)
    {
        this->marca = marca;
        this->an_fabricatie = 0;
        this->an_achizitionare = 0;
        this->capacitate_maxima = capacitate_maxima;
    }

    Cuptor (const Cuptor& cup):id_cuptor(cup.id_cuptor)
    {
        this->marca = cup.marca;
        this->an_fabricatie = cup.an_fabricatie;
        this->an_achizitionare = cup.an_achizitionare;
        this->capacitate_maxima = cup.capacitate_maxima;
    }

    ~Cuptor(){}

    Cuptor& operator=(const Cuptor& cup)
    {
        if (this != &cup)
        {
            this->marca = cup.marca;
            this->an_fabricatie = cup.an_fabricatie;
            this->an_achizitionare = cup.an_achizitionare;
            this->capacitate_maxima = cup.capacitate_maxima;
        }

        return *this;
    }

    friend istream& operator>>(istream& in,Cuptor& cup);
    friend ostream& operator<<(ostream& out,const Cuptor& cup);

    string GarantieValida()
    {
        if ((2021 - this->an_achizitionare) > 10)
            return "Nu mai este in garantie";
        else
            return "Inca in garantie";
    }

    int getID()
    {
        return this->id_cuptor;
    }

};

istream& operator>>(istream& in,Cuptor& cup)
{
    cout<<"Marca: ";
    in>>cup.marca;
    cout<<"Anul fabricarii: ";
    in>>cup.an_fabricatie;
    cout<<"Anul achizitionarii: ";
    in>>cup.an_achizitionare;
    cout<<"Capacitatea maxima in kg: ";
    in>>cup.capacitate_maxima;

    return in;
}

ostream& operator<<(ostream& out,const Cuptor& cup)
{
    out<<"ID Cuptor: "<<cup.id_cuptor<<endl;
    out<<"Marca: "<<cup.marca<<endl;
    out<<"Anul fabricarii: "<<cup.an_fabricatie<<endl;
    out<<"Anul achizitionarii: "<<cup.an_achizitionare<<endl;
    out<<"Capacitate maxima in kg: "<<cup.capacitate_maxima<<endl;

    return out;
}

class Raft{
    const int id_raft;
    string material_principal;
    string material_cadru;
    float inaltime;
    float latime;
    int capacitate_maxima;

public:
    static int contorID4;

    Raft():id_raft(contorID4++)
    {
        this->material_principal = "Anonim";
        this->material_cadru = "Anonim";
        this->inaltime = 0;
        this->latime = 0;
        this->capacitate_maxima = 0;
    }

    Raft(string material_principal,string material_cadru, float inaltime, float latime, int capacitate_maxima):id_raft(contorID4++)
    {
        this->material_principal = material_principal;
        this->material_cadru = material_cadru;
        this->inaltime = inaltime;
        this->latime = latime;
        this->capacitate_maxima = capacitate_maxima;
    }

    Raft(string material_principal,string material_cadru):id_raft(contorID4++)
    {
        this->material_principal = material_principal;
        this->material_cadru = material_cadru;
        this->inaltime = 0;
        this->latime = 0;
        this->capacitate_maxima = 0;
    }

    Raft (const Raft& raft):id_raft(raft.id_raft)
    {
        this->material_principal = raft.material_principal;
        this->material_cadru = raft.material_cadru;
        this->inaltime = raft.inaltime;
        this->latime = raft.latime;
        this->capacitate_maxima = raft.capacitate_maxima;
    }

    ~Raft (){}

    Raft& operator=(const Raft& raft)
    {
        if (this != &raft)
        {
            this->material_principal = raft.material_principal;
            this->material_cadru = raft.material_cadru;
            this->inaltime = raft.inaltime;
            this->latime = raft.latime;
            this->capacitate_maxima = raft.capacitate_maxima;
        }


        return *this;
    }

    friend istream& operator>>(istream& in,Raft& raft);
    friend ostream& operator<<(ostream& out,const Raft& raft);


    int CapacitateProdus(Produs& per)
    {
        int v = this->capacitate_maxima;
        v = v / per.getGramaj();
        return v;
    }

    int getCapacitate()
    {
        return this->capacitate_maxima;
    }

};

istream& operator>>(istream& in,Raft& raft)
{
    cout<<"Material principal: ";
    in>>raft.material_principal;
    cout<<"Material cadru: ";
    in>>raft.material_cadru;
    cout<<"Inaltime in metri: ";
    in>>raft.inaltime;
    cout<<"Latime in metri: ";
    in>>raft.latime;
    cout<<"Capacitate maxima: ";
    in>>raft.capacitate_maxima;

    return in;
}

ostream& operator<<(ostream& out,const Raft& raft)
{
    out<<"Material principal: "<<raft.material_principal<<endl;
    out<<"Material cadru: "<<raft.material_cadru<<endl;
    out<<"Inaltime: "<<raft.inaltime<<" metri"<<endl;
    out<<"Latime: "<<raft.latime<<" metri"<<endl;
    out<<"Capacitate maxima: "<<raft.capacitate_maxima<<endl;

    return out;
}

int Angajat::contorID=100;
int Produs::contorID2=300;
int Cuptor::contorID3=500;
int Raft::contorID4=700;


// Etapa 2


class Brutarie:public Produs{

private:

    string alergeni;

public:

    Brutarie():Produs()
    {
        this->alergeni = "Anonim";
    }

    Brutarie(char* denumire,float gramaj,float pret,float numar_kcal,string alergeni):Produs(denumire,gramaj,pret,numar_kcal)
    {
        this->alergeni = alergeni;
    }

    Brutarie& operator=(const Brutarie& b)
    {
        if (this != &b)
        {
            Produs::operator=(b);
            this->alergeni = b.alergeni;
        }

        return *this;
    }

    ~Brutarie()
    {

    }

    friend ostream& operator<<(ostream& out,const Brutarie& b);
    friend istream& operator>>(istream& in,Brutarie& b);

};

istream& operator>>(istream& in,Brutarie& b)
{
    in>>(Produs&)b;
    cout<<"Alergeni: ";
    in>>b.alergeni;

    return in;
}

ostream& operator<<(ostream& out,const Brutarie& b)
{

    out<<(Produs&)b;
    out<<"Alergeni: "<<b.alergeni;

    return out;
}

class Cofetarie:public Produs{

private:

    int grame_zahar;

public:

    Cofetarie():Produs()
    {
        this->grame_zahar = 0;
    }

    Cofetarie(char* denumire,float gramaj,float pret,float numar_kcal,float grame_zahar):Produs(denumire,gramaj,pret,numar_kcal)
    {
        this->grame_zahar = grame_zahar;
    }

    Cofetarie& operator=(const Cofetarie& b)
    {
        if (this != &b)
        {
            Produs::operator=(b);
            this->grame_zahar = b.grame_zahar;
        }

        return *this;
    }

    ~Cofetarie()
    {

    }

    friend ostream& operator<<(ostream& out,const Cofetarie& b);
    friend istream& operator>>(istream& in,Cofetarie& b);

    void PretKilogram()
    {
        int Nr;

        Nr = this->getPret() * 1000;
        Nr = Nr / this->getGramaj();

        cout<<Nr<<" lei/Kg";
    }

};

istream& operator>>(istream& in,Cofetarie& b)
{
    in>>(Produs&)b;
    cout<<"Grame zahar: ";
    in>>b.grame_zahar;

    return in;
}

ostream& operator<<(ostream& out,const Cofetarie& b)
{

    out<<(Produs&)b;
    out<<"Zahar: "<<b.grame_zahar<<"g";

    return out;
}

class Electric:public Cuptor{

private:

    int consum_per_ora;

public:

    Electric():Cuptor()
    {
        this->consum_per_ora = 0;
    }

    Electric(string marca,int an_fabricatie,int capacitate_maxima,int consum_per_ora):Cuptor(marca,an_fabricatie,capacitate_maxima)
    {
        this->consum_per_ora = consum_per_ora;
    }

    Electric& operator=(const Electric& e)
    {
        if (this != &e)
        {
            Cuptor::operator=(e);
            this->consum_per_ora = e.consum_per_ora;
        }

        return *this;
    }

    ~Electric()
    {

    }

    friend ostream& operator<<(ostream& out,const Electric& e);
    friend istream& operator>>(istream& in,Electric& e);


    void ClasaEnergetica()
    {
        float NrRef;

        NrRef = this->consum_per_ora / 1000;
        NrRef = NrRef / 0.012;

        if (NrRef <= 70)
            cout<<"Clasa A";
        else if (NrRef <= 85)
            cout<<"Clasa B";
        else if (NrRef <= 110)
            cout<<"Clasa C";
        else if (NrRef <= 130)
            cout<<"Clasa D";
        else cout<<"Clasa E";
    }
};

ostream& operator<<(ostream& out,const Electric& e)
{
    out<<(Cuptor&)e;
    out<<"Consum: "<<e.consum_per_ora<<" Watt/Ora"<<endl;

    return out;
}

istream& operator>>(istream& in,Electric& e)
{
    in>>(Cuptor&)e;
    cout<<"Consum Watt/Ora: ";
    in>>e.consum_per_ora;

    return in;
}

class Testare{

public:

    virtual void PretFaraTVA() = 0;

};


class ElectrocasniceMici:public Testare{

protected:

    int greutate;
    int pret;

public:

    virtual float PretRevanzare() = 0;

    void SetPret(int i)
    {
        this->pret = i;
    }

    ElectrocasniceMici()
    {
        this->greutate = 0;
        this->pret = 0;
    }

    ElectrocasniceMici(int greutate, int pret)
    {
        this->greutate = greutate;
        this->pret = pret;
    }

    ElectrocasniceMici& operator=(const ElectrocasniceMici& e)
    {
        if (this != &e)
        {
            this->greutate = e.greutate;
            this->pret = e.pret;
        }

        return *this;
    }

    ~ElectrocasniceMici() {}

    friend istream& operator>>(istream& in,ElectrocasniceMici& e);
    friend ostream& operator<<(ostream& out,const ElectrocasniceMici& e);

};

istream& operator>>(istream& in,ElectrocasniceMici& e)
{
    cout<<"Greutate (in Kg): ";
    in>>e.greutate;
    cout<<"\nPret: ";
    in>>e.pret;
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out,const ElectrocasniceMici& e)
{
    out<<"Greutate: "<<e.greutate<<" Kg\n";
    out<<"Pret: "<<e.pret<<" lei\n";

    return out;
}

class Motor {

private:

    int tensiune;
    int putere;

public:

    Motor()
    {
        this->tensiune = 0;
        this->putere = 0;
    }

    Motor(int tensiune,int putere)
    {
        this->tensiune = tensiune;
        this->putere = putere;
    }

    Motor& operator=(const Motor& m)
    {
        if (this != &m)
        {
            this->tensiune = m.tensiune;
            this->putere = m.putere;
        }

        return *this;
    }

    ~Motor(){}

    friend istream& operator>>(istream& in,Motor& m);
    friend ostream& operator<<(ostream& out,const Motor& m);

};

istream& operator>>(istream& in,Motor& m)
{
    cout<<"\nTensiune: ";
    in>>m.tensiune;
    cout<<"\nPutere: ";
    in>>m.putere;
    cout<<"\n";

    return in;
}

ostream& operator<<(ostream& out,const Motor& m)
{
    out<<"\nTensiune: "<<m.tensiune;
    out<<"\nPutere: "<<m.putere;

    return out;
}


class Mixer:public ElectrocasniceMici{

private:

    int Capacitate_aluat;
    Motor Mot;

public:

    void PretFaraTVA()
    {

        float nr = this->pret;
        nr = nr * 81/100.0;
        cout<<nr;

    }

    float PretRevanzare()
    {
        return 6/10.0*(this->pret);
    }

    Mixer():ElectrocasniceMici()
    {
        this->Capacitate_aluat = 0;
    }

    Mixer(int greutate, int pret, int Capacitate, Motor Mot):ElectrocasniceMici(greutate,pret)
    {
        this->Capacitate_aluat = Capacitate;
        this->Mot = Mot;
    }

    Mixer& operator=(const Mixer& m)
    {
        if (this != &m)
        {
            ElectrocasniceMici::operator=(m);
            this->Capacitate_aluat = m.Capacitate_aluat;
            this->Mot = m.Mot;
        }

        return *this;
    }

    ~Mixer(){}

    setMotor(Motor K)
    {
        this->Mot = K;

        return *this;
    }

    friend istream& operator>>(istream& in,Mixer& m);
    friend ostream& operator<<(ostream& out,const Mixer& m);

};

istream& operator>>(istream& in,Mixer& m)
{
    in>>(ElectrocasniceMici&)m;
    cout<<"Capacitate Aluat (in Kg): ";
    in>>m.Capacitate_aluat;
    cout<<"\nSpeficiatii Motor:";
    in>>m.Mot;

    return in;
}

ostream& operator<<(ostream& out,const Mixer& m)
{
    out<<(ElectrocasniceMici&)m;
    out<<"Capacitate Aluat: "<<m.Capacitate_aluat<<" Kg\n";
    out<<"Specificatii Motor: \n"<<m.Mot;

    return out;
}

class Cantar:public ElectrocasniceMici{

private:

    float GreutateMaxima;

public:

    void PretFaraTVA()
    {

        float nr = this->pret;
        nr = nr * 89/100.0;
        cout<<nr;

    }

    float PretRevanzare()
    {
        return 4/10.0*(this->pret);
    }

    Cantar():ElectrocasniceMici()
    {
        this->GreutateMaxima = 0;
    }

    Cantar(int greutate, int pret, float GreutateMaxima):ElectrocasniceMici(greutate,pret)
    {
        this->GreutateMaxima = GreutateMaxima;
    }

    Cantar& operator=(const Cantar& c)
    {
        if (this != &c)
        {
            ElectrocasniceMici::operator=(c);
            this->GreutateMaxima = c.GreutateMaxima;
        }

        return *this;
    }

    ~Cantar(){}

    friend istream& operator>>(istream& in,Cantar& c);
    friend ostream& operator<<(ostream& out,const Cantar& c);


};

istream& operator>>(istream& in,Cantar& c)
{
    in>>(ElectrocasniceMici&)c;
    cout<<"Greutate maxima cantarabila (in Kg): ";
    in>>c.GreutateMaxima;

    return in;
}

ostream& operator<<(ostream& out,const Cantar& c)
{
    out<<(ElectrocasniceMici&)c;
    out<<"Greutate maxima cantarabila: "<<c.GreutateMaxima<<" Kg\n";

    return out;
}


// Etapa 3

vector<Angajat> Vect; // Vector de Angajati
set<Raft*> Set;  // Vector de adrese ale Rafturilor existente
list<Cuptor> List; // Lista de cuptoare
map<int,vector<Produs>> Dict; // Dictionar al produselor
vector<ElectrocasniceMici*> Elec[2]; // Vector cu electrocasnice

void MenAng()
{
    system("CLS");

    while(1>0)
    {
        cout<<"  ____________________\n";
        cout<<" |   Meniu Angajati  |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (1) Afisare      |\n";
        cout<<" |-------------------|\n";
        cout<<" | (2) Export date   |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (3) Adaugare     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (4) Stergere     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (5) Alterare     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (6) Revenire     |\n";
        cout<<" |___________________|\n";

        int Raspuns;
        cout<<"\n> Comanda: ";
        cin>>Raspuns;

        if (Raspuns == 1)
        {
            system("CLS");
            cout<<"\n\n";

            for (int i=0;i<Vect.size();i++)
                cout<<Vect[i]<<endl<<"Salariu: "<<Vect[i].Salariu()<<"\n\n";
            cout<<"\n\n";
        }

        if (Raspuns == 2)
        {
            ofstream ofout("Angajati.out");
            for (int i=0;i<Vect.size();i++)
                ofout<<Vect[i]<<"\n\n";

            ofout.close();
            cout<<"> Datele angajatilor au fost exportate in fisierul Angajati.out\n";

        }

        if (Raspuns == 3)
        {
            system("CLS");
            Angajat Nou;
            cin>>Nou;


            Vect.push_back(Nou);

            system("CLS");
        }

        if (Raspuns == 4)
        {
            cout<<"> ID-ul Angajatului ce doresti a fi sters: ";
            int idang;
            cin>>idang;
            int k = 0;
            for (int i=0;i<Vect.size();i++)
                if (Vect[i].getID() == idang)
                {
                    Vect.erase(Vect.begin()+(idang-100));
                    k = 1;
                    break;
                }
            if (k == 0)
                cout<<"> Acest ID nu exista\n\n";
        }

        if (Raspuns == 5)
        {
            cout<<"> ID-ul Angajatului ce doresti a fi alterat: ";
            int idang;
            cin>>idang;
            int k = 0;
            for (int i=0;i<Vect.size();i++)
            {
                if (Vect[i].getID() == idang)
                {
                    cout<<"> Nume curent: "<<Vect[i].getNume()<<endl;
                    cout<<"> Nume nou: ";
                    char* a;
                    a = new char[256];
                    cin>>a;
                    Vect[i].setNume(a);
                    delete a;
                    cout<<"\n";
                    cout<<"> Prenume curent: "<<Vect[i].getPrenume()<<endl;
                    cout<<"> Prenume nou: ";
                    string b;
                    cin>>b;
                    Vect[i].setPrenume(b);
                    cout<<"> Initiala tata curent: "<<Vect[i].getInitiala()<<endl;
                    cout<<"> Initiala noua: ";
                    char c;
                    cin>>c;
                    Vect[i].setInitiala(c);
                    cout<<"> Varsta curenta: "<<Vect[i].getVarsta()<<endl;
                    cout<<"> Varsta noua: ";
                    int d;
                    cin>>d;
                    Vect[i].setVarsta(d);
                    cout<<"> Status de manager curent: ";
                    if (Vect[i].getManager() == 1)
                        cout<<"Da\n";
                    else cout<<"Nu\n";
                    cout<<"> Status de manager nou (0/1) : ";
                    bool e;
                    cin>>e;
                    Vect[i].setManager(e);
                    cout<<"> Numar comenzi realizate in total: "<<Vect[i].getNrComenziTotal()<<endl;;
                    cout<<"> Numar nou de comenzi realizate in total: ";
                    double f;
                    cin>>f;
                    Vect[i].setNrComenziTotal(f);
                    cout<<"> Numar comenzi saptamana curenta: ";
                    for (int j=0;j<7;j++)
                        cout<<Vect[i].getNrComenziSapt()[j]<<' ';
                    cout<<endl;
                    cout<<"> Numar comenzi saptamana noua: ";
                    int* g;
                    g = new int[7];
                    for (int j=0;j<7;j++)
                        cin>>g[j];
                    Vect[i].setNrComenziSapt(g);
                    delete g;
                    cout<<"> Cele mai vandute 3 produse curente: ";
                    for (int j=0;j<3;j++)
                        cout<<Vect[i].getCeleVand()[j]<<' ';
                    cout<<endl;
                    cout<<"> Cele mai vandute 3 produse noi: ";
                    string* h;
                    h = new string[3];
                    for (int j=0;j<3;j++)
                        cin>>h[j];
                    Vect[i].setCeleVand(h);
                    cout<<"\nDatele noi:\n"<<Vect[i]<<"\n\n";
                    k = 1;
                    break;
                }
            }
            if (k == 0)
                cout<<"> Acest ID nu exista\n\n";

        }

        if (Raspuns == 6)
            break;

    }
}

void MenRaft()
{
    system("CLS");

    while(1>0)
    {
        cout<<"  ____________________\n";
        cout<<" |   Meniu Rafturi   |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (1) Afisare      |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (2) Adaugare     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (3) Revenire     |\n";
        cout<<" |___________________|\n";

        int Raspuns;
        cout<<"\n> Comanda: ";
        cin>>Raspuns;

        if (Raspuns == 1)
        {
            system("CLS");
            cout<<"\n\n";

            for (Raft* const R : Set)
                cout<<*R<<"\n";

            cout<<"\n\n";
        }

        if (Raspuns == 2)
        {
            system("CLS");
            Raft Nou;
            cin>>Nou;

            Set.insert(&Nou);

            system("CLS");
        }

        if (Raspuns == 3)
            break;

    }
}

void MenCupt()
{
    system("CLS");

    while(1>0)
    {
        cout<<"  ____________________\n";
        cout<<" |   Meniu Cuptoare  |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (1) Afisare      |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (2) Adaugare     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (3) Export date  |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (4) Stergere     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (5) Revenire     |\n";
        cout<<" |___________________|\n";

        int Raspuns;
        cout<<"\n> Comanda: ";
        cin>>Raspuns;

        if (Raspuns == 1)
        {
            system("CLS");
            cout<<"\n\n";
            std::list<Cuptor>::iterator it;
            for (it = List.begin();it!=List.end();it++)
            {
                cout<<(*it)<<"\n";
            }
        }

        if (Raspuns == 2)
        {
            system("CLS");
            cout<<"> Cuptorul este Electric (1/0) : ";
            int nrel;
            cin>>nrel;
            if (nrel == 0)
            {
                Cuptor Nou;
                cin>>Nou;
                List.insert(List.end(),Nou);
            }
            else
            {
                Electric Nou;
                cin>>Nou;
                List.insert(List.end(),Nou);
            }

            system("CLS");
        }

        if (Raspuns == 3)
        {
            ofstream ofout("Cuptoare.out");
            std::list<Cuptor>::iterator it;
            for (it = List.begin();it!=List.end();it++)
            {
                ofout<<(*it)<<"\n";
            }
            cout<<"> Datele au fost exportate in fisierul Cuptoare.out\n";
            ofout.close();
        }

        if (Raspuns == 4)
        {
            cout<<"> ID-ul Cuptorului ce doresti a fi sters: ";
            int idang;
            cin>>idang;
            std::list<Cuptor>::iterator it;
            for (it = List.begin();it!=List.end();it++)
            {
                if ((*it).getID() == idang)
                    List.erase(it);
            }

        }

        if (Raspuns == 5)
            break;

    }
}

void MenProd()
{
    system("CLS");

    while(1>0)
    {
        cout<<"  ____________________\n";
        cout<<" |   Meniu Produse   |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (1) Afisare      |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (2) Adaugare     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (3) Export date  |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (4) Stergere     |\n";
        cout<<" |-------------------|\n";
        cout<<" |  (5) Revenire     |\n";
        cout<<" |___________________|\n";

        int Raspuns;
        cout<<"\n> Comanda: ";
        cin>>Raspuns;

        if (Raspuns == 1)
        {
            system("CLS");
            cout<<"\n\n";

            cout<<"Produse Brutarie: \n\n";
            for (int i=0;i<Dict[1].size();i++)
                cout<<Dict[1][i]<<"\n";
            cout<<"\nProduse Cofetarie: \n\n";
            for (int i=0;i<Dict[2].size();i++)
                cout<<Dict[2][i]<<"\n";
        }

        if (Raspuns == 2)
        {
            system("CLS");
            cout<<"> Ce tip de produs este? (Brutarie/Cofetarie): ";
            string nrel;
            cin>>nrel;
            if (nrel == "Brutarie")
            {
                Brutarie Nou;
                cin>>Nou;
                Dict[1].push_back(Nou);
            }
            else
            {
                Cofetarie Nou;
                cin>>Nou;
                Dict[2].push_back(Nou);
            }

            system("CLS");
        }

        if (Raspuns == 3)
        {
            ofstream ofout("Produse.out");
            ofout<<"Produse Brutarie: \n\n";
            for (int i=0;i<Dict[1].size();i++)
                ofout<<Dict[1][i]<<"\n";
            ofout<<"\nProduse Cofetarie: \n\n";
            for (int i=0;i<Dict[2].size();i++)
                ofout<<Dict[2][i]<<"\n";

            ofout.close();
            cout<<"> Datele au fost exportate in fisierul Produse.out\n";

        }

        if (Raspuns == 4)
        {
            cout<<"> ID-ul Produsului ce doresti a fi sters: ";
            int idang;
            cin>>idang;

            for (int i=1;i<=2;i++)
                for (int j=0;j<Dict[i].size();j++)
                    if (Dict[i][j].getID() == idang)
                        Dict[i].erase(Dict[i].begin()+(idang-300));
        }

        if (Raspuns == 5)
            break;

    }

}

void MenElec()
{
    system("CLS");

    while(1>0)
    {
        cout<<"  ______________________\n";
        cout<<" | Meniu Electrocasnice |\n";
        cout<<" |----------------------|\n";
        cout<<" |    (1) Afisare       |\n";
        cout<<" |----------------------|\n";
        cout<<" |    (2) Adaugare      |\n";
        cout<<" |----------------------|\n";
        cout<<" |    (3) Revenire      |\n";
        cout<<" |______________________|\n";

        int Raspuns;
        cout<<"\n> Comanda: ";
        cin>>Raspuns;

        if (Raspuns == 1)
        {
            system("CLS");
            cout<<"\n\n";

            cout<<"Mixer: \n\n";
            for (int i=0;i<Elec[0].size();i++)
                cout<<*Elec[0][i]<<"\n\n";

            cout<<"\nCantar: \n\n";
            for (int i=0;i<Elec[1].size();i++)
                cout<<*Elec[1][i]<<"\n\n";
        }

        if (Raspuns == 2)
        {
            system("CLS");
            cout<<"> Ce tip de electrocasnic este? (Cantar/Mixer): ";
            string nrel;
            cin>>nrel;
            if (nrel == "Mixer")
            {
                Mixer Nou;
                cin>>Nou;
                Elec[0].push_back(&Nou);
            }
            else
            {
                Cantar Nou;
                cin>>Nou;
                Elec[1].push_back(&Nou);
            }

            system("CLS");
        }

        if (Raspuns == 3)
            break;

    }

}

void Meniu()
{
    system("CLS");

    while (1>0)
    {
        system("CLS");
        cout<<"  _________________________ \n";
        cout<<" |      Meniu Principal    |\n";
        cout<<" |-------------------------|\n";
        cout<<" |  (1) Meniu  Angajat     |\n";
        cout<<" |-------------------------|\n";
        cout<<" |  (2) Meniu  Produse     |\n";
        cout<<" |-------------------------|\n";
        cout<<" |  (3) Meniu  Cuptoare    |\n";
        cout<<" |-------------------------|\n";
        cout<<" |  (4) Meniu  Rafturi     |\n";
        cout<<" |-------------------------|\n";
        cout<<" |(5) Meniu Electrocasnice |\n";
        cout<<" |-------------------------|\n";
        cout<<" |       (6) Iesire        |\n";
        cout<<" |_________________________|\n";

        int Raspuns;
        cout<<"\n> Comanda: ";
        cin>>Raspuns;


        if (Raspuns == 1)
            MenAng();

        if (Raspuns == 2)
            MenProd();

        if (Raspuns == 3)
            MenCupt();

        if (Raspuns == 4)
            MenRaft();

        if (Raspuns == 5)
            MenElec();

        if (Raspuns == 6)
            break;
    }

}

int main()
{

    /*ElectrocasniceMici* A[5];

    A[1] = new Mixer();
    A[2] = new Cantar();
    A[3] = new Mixer();

    for (int i=1;i<=3;i++)
    {
        cin>>*A[i];
        cout<<*A[i]<<"Pret Revanzare: "<<A[i]->PretRevanzare()<<"\nPret fara tva: ";
        A[i]->PretFaraTVA();
        cout<<"\n\n";
    }
    */

    Angajat A,B;
    fin>>A>>B;
    Vect.push_back(A);
    Vect.push_back(B);

    Raft C,D;
    fin>>C;
    fin>>D;
    Set.insert(&C);
    Set.insert(&D);

    Cuptor E;
    Electric F;
    fin>>E>>F;
    std::list<Cuptor>::iterator it = List.begin();
    List.insert(it,E);
    List.insert(it,F);

    Brutarie G;
    Cofetarie H;
    fin>>G>>H;
    Dict[1].push_back(G);
    Dict[2].push_back(H);

    Mixer I;
    Cantar J;
    fin>>I>>J;
    Elec[0].push_back(&I);
    Elec[1].push_back(&J);


    system("CLS");

    Meniu();

    fin.close();
    fout.close();
    return 0;
}
