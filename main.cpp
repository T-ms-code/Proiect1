#include <iostream>
#include <utility>
#include <cmath>
#include <string>
using namespace std;

class Elev{
private:
    string nume_elev;
    int* note_mate;
    int note1;
    int* note_romana;
    int note2;
    int* note_fizica;
    int note3;
    int* note_info;
    int note4;
    int nr_absente;
public:
    Elev(){
        this->nume_elev="";
        this->note_mate= nullptr;
        this->note_romana= nullptr;
        this->note_info= nullptr;
        this->note_fizica= nullptr;
        this->note1=0;
        this->note2=0;
        this->note3=0;
        this->note4=0;
        this->nr_absente=0;
    }
    explicit Elev(string nume){
        this->nume_elev=std::move(nume);
        this->note_mate= nullptr;
        this->note_romana= nullptr;
        this->note_info= nullptr;
        this->note_fizica= nullptr;
        this->note1=0;
        this->note2=0;
        this->note3=0;
        this->note4=0;
        this->nr_absente=0;
    }
    Elev(string nume, const int* notemate,int n1, const int* noteromana, int n2, const int* notefizica,int n3, const int* noteinfo,int n4, int absente){
       nume_elev=std::move(nume);
       if(notemate!=nullptr&&n1>0){
           note1=n1;
           note_mate=new int[note1];
           for(int i=0;i<note1;i++)
               note_mate[i]=notemate[i];
       }
       else{
           note_mate= nullptr;
           note1=0;
       }
        if(noteromana!=nullptr&&n2>0){
            note2=n2;
            note_romana=new int[note2];
            for(int i=0;i<note2;i++)
                note_romana[i]=noteromana[i];
        }
        else{
            note_romana= nullptr;
            note2=0;
        }
        if(notefizica!=nullptr&&n3>0){
            note3=n3;
            note_fizica=new int[note3];
            for(int i=0;i<note3;i++)
                note_fizica[i]=notefizica[i];
        }
        else{
            note_fizica= nullptr;
            note3=0;
        }
        if(noteinfo!=nullptr&&n4>0){
            note4=n4;
            note_info=new int[note4];
            for(int i=0;i<note4;i++)
                note_info[i]=noteinfo[i];
        }
        else{
            note_info= nullptr;
            note4=0;
        }
        nr_absente=absente;
    }
    ~Elev(){///Merge sters si nullptr
       delete[]note_mate;
       delete[]note_romana;
       delete[]note_info;
       delete[]note_fizica;
    }
    Elev(const Elev& e){
        this->nume_elev=e.nume_elev;
        this->nr_absente=e.nr_absente;
        this->note1=e.note1;
        this->note2=e.note2;
        this->note3=e.note3;
        this->note4=e.note4;
        if(e.note_mate!=nullptr&&this->note1>0){
            this->note_mate=new int[this->note1];
            for(int i=0;i<this->note1;i++)
                this->note_mate[i]=e.note_mate[i];
        }
        else{
            this->note_mate= nullptr;
            this->note1=0;
        }
        if(e.note_romana!=nullptr&&note2>0){
            note_romana=new int[note2];
            for(int i=0;i<note2;i++)
                note_romana[i]=e.note_romana[i];
        }
        else{
            note_romana= nullptr;
            note2=0;
        }
        if(e.note_info!=nullptr&&note4>0){
            note_info=new int[note4];
            for(int i=0;i<note4;i++)
                note_info[i]=e.note_info[i];
        }
        else{
            note_info= nullptr;
            note3=0;
        }
        if(e.note_fizica!=nullptr&&note3>0){
            note_fizica=new int[note3];
            for(int i=0;i<note3;i++)
                note_fizica[i]=e.note_fizica[i];
        }
        else{
            note_fizica= nullptr;
            note4=0;
        }
    }
    Elev& operator=(const Elev& e){
        if (this == &e)return *this;
        nume_elev=e.nume_elev;
        nr_absente=e.nr_absente;
        delete[]note_mate;
        delete[]note_romana;
        delete[]note_info;
        delete[]note_fizica;
        note1=e.note1;
        note2=e.note2;
        note3=e.note3;
        note4=e.note4;
        if(note1>0){
            note_mate=new int[note1];
            for(int i=0;i<note1;i++)
                note_mate[i]=e.note_mate[i];
        }
        if(note2>0){
            note_romana=new int[note2];
            for(int i=0;i<note2;i++)
                note_romana[i]=e.note_romana[i];
        }
        if(note4>0){
            note_info=new int[note4];
            for(int i=0;i<note4;i++)
                note_info[i]=e.note_info[i];
        }
        if(note3>0){
            note_fizica=new int[note3];
            for(int i=0;i<note3;i++)
                note_fizica[i]=e.note_fizica[i];
        }
        return *this;
    }
    float getmedie_elev(){
        float m1=0;
        int ok=1;
        for(int i=0;i<note1&&note1!=0;i++ ){
            m1+=(float)note_mate[i];}
        if(note1!=0)m1=round(m1/(float)note1);
        else ok=0;
        float m2=0;
        for(int i=0;i<note2&&note2!=0;i++ ){
            m2+=(float)note_romana[i];}
        if(note2!=0)m2=round(m2/(float)note2);
        else ok=0;
        float m3=0;
        for(int i=0;i<note3&&note3!=0;i++ ){
            m3+=(float)note_fizica[i];}
        if(note3!=0)m3=round(m3/(float)note3);
        else ok=0;
        float m4=0;
        for(int i=0;i<note4&&note4!=0;i++ ){
            m4+=(float)note_info[i];}
        if(note4!=0) m4=round(m4/(float)note4);
        else ok=0;
        if(ok==0) return 0;
        return ((float)(m1+m2+m3+m4)/4);
    }
    string getnume_elev(){
        return nume_elev;
    }
    [[nodiscard]] int getnr_absente() const{
       return nr_absente;
    }
    friend ostream& operator<<(ostream &out,const  Elev& e);
//    void dezaloca(){
//        delete[]note_mate;
//        delete[]note_romana;
//        delete[]note_info;
//        delete[]note_fizica;
//    }
    void PuneNota(const string& materie, int nota){
        if(nota>=1&&nota<=10) {
            if (materie == "Matematica") {
                 int nr=note1+1;
                 int* v=new int[nr];
                 for(int i=0;i<note1&&note1!=0;i++)
                     v[i]=note_mate[i];
                 v[note1]=nota;
                 delete[] note_mate;
                 note1=nr;
                 note_mate=new int[note1];
                for(int i=0;i<note1;i++)
                    note_mate[i]=v[i];
                delete [] v;
            }
            if (materie == "Romana") {
                int nr=note2+1;
                int* v=new int[nr];
                for(int i=0;i<note2&&note2!=0;i++)
                    v[i]=note_romana[i];
                v[note2]=nota;
                delete[] note_romana;
                note2=nr;
                note_romana=new int[note2];
                for(int i=0;i<note2;i++)
                    note_romana[i]=v[i];
                delete[] v;
            }
            if (materie == "Fizica") {
                int nr=note3+1;
                int* v=new int[nr];
                for(int i=0;i<note3&&note3!=0;i++)
                    v[i]=note_fizica[i];
                v[note3]=nota;
                delete[] note_fizica;
                note3=nr;
                note_fizica=new int[note3];
                for(int i=0;i<note3;i++)
                    note_fizica[i]=v[i];
                delete[] v;
            }
            if (materie == "Informatica") {
                int nr=note4+1;
                int* v=new int[nr];
                for(int i=0;i<note4&&note4!=0;i++)
                    v[i]=note_info[i];
                v[note4]=nota;
                delete[] note_info;
                note4=nr;
                note_info=new int[nr];
                for(int i=0;i<note4;i++)
                    note_info[i]=v[i];
                delete[] v;
            }
        }
    }
    void PuneAbsenta(){
        nr_absente++;
    }
};
ostream& operator<<(ostream &out,const Elev& e){
      int ok1=0, ok2=0, ok3=0, ok4=0;
      out<<"Numele elevului: ";
      out<<e.nume_elev;
      out<<endl;
      out<<"Note la matematica: ";
      int m1=0;
      for(int i=0;i<e.note1&&e.note1!=0;i++){cout<<e.note_mate[i]<<" ";m1+=e.note_mate[i];}
      out<<endl;
      if(e.note1!=0){ok1=1;
      out<<"Media: "<<round((float)m1/(float)e.note1);
      out<<endl;}
      out<<"Note la romana: ";
      int m2=0;
      for(int i=0;i<e.note2&&e.note2!=0;i++){cout<<e.note_romana[i]<<" ";m2+=e.note_romana[i];}
      out<<endl;
      if(e.note2!=0){ok2=1;
      out<<"Media: "<<round((float)m2/(float)e.note2);
      out<<endl;}
      out<<"Note la fizica: ";
      int m3=0;
      for(int i=0;i<e.note3&&e.note3!=0;i++){cout<<e.note_fizica[i]<<" ";m3+=e.note_fizica[i];}
      out<<endl;
      if(e.note3!=0){ok3=1;
      out<<"Media: "<<round((float)m3/(float)e.note3);
      out<<endl;}
      out<<"Note la informatica: ";
      int m4=0;
      for(int i=0;i<e.note4&&e.note4!=0;i++){cout<<e.note_info[i]<<" ";m4+=e.note_info[i];}
      out<<endl;
      if(e.note4!=0){ok4=1;
      out<<"Media: "<<round((float)m4/(float)e.note4);
      out<<endl;}
      out<<"Media generala: ";
      float m;
      if(ok1*ok2*ok3*ok4==1){
       m=round((float)m1/(float)e.note1)+round((float)m2/(float)e.note2)+round((float)m3/(float)e.note3)+round((float)m4/(float)e.note4);
      out<<m/4.0<<endl;}
      else{out<<0<<endl;}
      out<<"Absente: "<<e.nr_absente;
      return out;
}



class Profesor{
private:
    string nume_profesor;
    string materie_predata;
    int ani_vechime;
public:
    Profesor() {
        nume_profesor="";
        materie_predata="";
        ani_vechime=0;
    }
    Profesor(string nume_profesor,string materie_predata,int ani_vechime){
        this->nume_profesor=std::move(nume_profesor);
        this->materie_predata=std::move(materie_predata);
        this->ani_vechime=ani_vechime;
    }
//    Profesor(const Profesor& p){
//        nume_profesor=p.nume_profesor;
//        materie_predata=p.materie_predata;
//        ani_vechime=p.ani_vechime;
//    }
//    Profesor& operator=(const Profesor& p)= default;
//    [[nodiscard]] int getani_vechime() const{
//        return ani_vechime;
//    }
    [[nodiscard]] string getnume_profesor()const {
        return nume_profesor;
    }
    void AdaugareVchime(){
         ani_vechime++;
    }
    friend istream& operator>>(istream& in, Profesor& c);
    friend ostream& operator<<(ostream& out, const Profesor& c);
    bool operator==(Profesor& p){
        return (nume_profesor==p.nume_profesor&&materie_predata==p.materie_predata&&ani_vechime==p.ani_vechime);
    }
};
istream& operator>>(istream& in, Profesor& c){
    cout<<"Numele profesorului: ";
    getline(in,c.nume_profesor);
    cout<<endl;
    cout<<"Materia predata(cu prima litera mare): ";
    getline(in,c.materie_predata);
    cout<<endl;
    cout<<"Ani vechime: ";
    in>>c.ani_vechime;
    return in;
}
ostream& operator<<(ostream& out, const Profesor& c){
    out<<"Numele profesorului: ";
    out<<c.nume_profesor;
    out<<endl;
    out<<"Materia predata: ";
    out<<c.materie_predata;
    out<<endl;
    out<<"Ani vechime: ";
    out<<c.ani_vechime;
    return out;
}




class Clasa{
private:
    string nume_clasa;
    Profesor diriginte;
    Elev* elevi;
    int nr_elevi;
public:
    Clasa(string nume_clasa,Profesor& diriginte,Elev* elevi,int nr_elevi) : diriginte() {
        this->nume_clasa=std::move(nume_clasa);
        this->diriginte=diriginte;
        if(elevi!= nullptr&&nr_elevi>0){
            this->nr_elevi=nr_elevi;
            this->elevi=new Elev[nr_elevi];
            for(int i=0;i<nr_elevi;i++)
                this->elevi[i]=elevi[i];
        }
        else{
            this->elevi= nullptr;
            this->nr_elevi=0;
        }
    }
//    Clasa(string& nume_clasa, Profesor& diriginte) : diriginte() {
//        this->nume_clasa=nume_clasa;
//        this->diriginte=diriginte;
//        this->elevi= nullptr;
//        this->nr_elevi=0;
//    }
    Clasa(): diriginte() {
        this->nume_clasa="";
        this->elevi= nullptr;
        this->nr_elevi=0;
    }
    ~Clasa(){
        delete[] elevi;
    }
    Clasa(const Clasa& c) : diriginte() {
        nume_clasa=c.nume_clasa;
        diriginte=c.diriginte;
        if(c.elevi!= nullptr&&c.nr_elevi>0){
            nr_elevi=c.nr_elevi;
            elevi=new Elev[nr_elevi];
            for(int i=0;i<nr_elevi;i++)
                elevi[i]=c.elevi[i];
        }
        else{
            elevi= nullptr;
            nr_elevi=0;
        }
    }
    Clasa& operator=(const Clasa &c){
        if (this!=&c){
            nume_clasa=c.nume_clasa;
            diriginte=c.diriginte;
            delete[] elevi;
            if(c.elevi!= nullptr&&c.nr_elevi>0){
                nr_elevi=c.nr_elevi;
                elevi=new Elev[nr_elevi];
                for(int i=0;i<nr_elevi;i++)
                    elevi[i]=c.elevi[i];
            }
            else{
                elevi= nullptr;
                nr_elevi=0;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out,const Clasa& c);
    friend istream& operator>>(istream& in, Clasa& c);
    bool operator==(Clasa& c){
        int ok=1;
        if(!(nume_clasa==c.nume_clasa))
            ok=0;
        if(!(diriginte==c.diriginte))
           ok=0;
        ///Elevii  nu sunt luati in calcul, intrucat pot exista elevi cu acelasi nume si aceleasi rezultate
        return ok;
    }
    friend int operator+(Clasa& c1,Clasa& c2);
    void SchimbaDiriginte(){
        Profesor p;
        cin>>p;
        diriginte=p;
    }
    void AdaugaElev(Elev& e){
        int nr=nr_elevi+1;
        Elev* v2=new Elev[nr];
//        string nume;
//        cout<<"Nume: ";
//        cin>>nume;
//        Elev e(nume);
        for(int i=0;i<nr_elevi;i++)
           v2[i]=elevi[i];
        v2[nr_elevi]=e;
//        for(int i=0;i<nr_elevi;i++)
//            elevi[i].dezaloca();
        delete[] elevi;///Sterge elevi, fara acei vectori alocati dinamici de la elevi, caci va corupe stiva!!!
        elevi=new Elev[nr];
        for(int i=0;i<nr_elevi;i++)
            elevi[i]=v2[i];
        elevi[nr_elevi]=e;
        nr_elevi=nr;
//        for(int i=0;i<nr_elevi;i++)
//            v2[i].dezaloca();
        delete[] v2;

    }
    void ExmatriculeazaElev(const string& nume){
        ///Presupunem ca vor exista elevi
        if(nr_elevi>=1){
        int nr=nr_elevi-1;
        Elev* v2=new Elev[nr];
//        string nume;
//        cout<<"Nume: ";
//        cin>>nume;
        int ok=0;
        int j=0;
        for(int i=0;i<nr_elevi;i++) {
            if (elevi[i].getnume_elev() == nume && ok == 1)
            {v2[j] = elevi[i];j++;}
            if (elevi[i].getnume_elev() == nume && ok == 0) { ok = 1; }
            if (elevi[i].getnume_elev() != nume){v2[j] = elevi[i];j++;}
        }
//        for(int i=0;i<nr_elevi;i++)
//            elevi[i].dezaloca();
        delete[] elevi;
        elevi=new Elev[nr];
        for(int i=0;i<nr;i++)
            elevi[i]=v2[i];
        nr_elevi=nr;
//        for(int i=0;i<nr_elevi;i++)
//            v2[i].dezaloca();
        delete[]v2;}
    }
    float MediaClasei(){
        float m=0;
        for (int i=0;i<nr_elevi;i++)
            m+=elevi[i].getmedie_elev();
        if(nr_elevi!=0)m=m/(float)nr_elevi;
        return m;
    }
    [[nodiscard]] int getnrelevi() const{
        return nr_elevi;
    }
    string getnume(){
        return nume_clasa;
    }
    Elev* getelevi(){
        return elevi;
    }
    Profesor getprofesor(){
        return diriginte;
    }
    void setvechime(){
        diriginte.AdaugareVchime();
    }
};
ostream& operator<<(ostream& out,const Clasa& c){
    out<<"Numele clasei: "<<c.nume_clasa<<endl;
    out<<"Diriginte: "<<c.diriginte.getnume_profesor()<<endl;
    out<<"Elevi:"<<endl;
    for(int i=0;i<c.nr_elevi;i++){
        out<<"Nr"<<i+1<<": "<<c.elevi[i].getnume_elev()<<"--"<<"medie generala: "<<c.elevi[i].getmedie_elev()<<"--"<<"absente: "<<c.elevi[i].getnr_absente()<<endl;}
    return  out;
}
istream& operator>>(istream& in, Clasa& c){
    cout<<"Numele clasei: "<<endl;
    string s1;
    cin.get();
    do{
       getline(in,s1);
       cout<<endl;
    }
    while(!(s1.size() == 2&&s1[0]=='9'&&'A'<=s1[1]&&s1[1]<='D')&&!(s1.size() == 3&&s1[0]=='1'&&'0'<=s1[1]&&s1[1]<='2'&&'A'<=s1[2]&&s1[2]<='D'));
    cout<<endl;
    cout<<" ACCEPTAT!"<<endl;
    c.nume_clasa=s1;
    cout<<"Profesor: "<<endl;
    in>>c.diriginte;
    return in;
}
int operator+(Clasa& c1,Clasa& c2){
    return c1.nr_elevi+c2.nr_elevi;
}



int main() {
    Profesor P1("Daniel Fugulin", "Matematica", 30), P2("Nicu Cristinel", "Sport", 15), P3("Fugulin Sivia", "Romana",
                                                                                           20), P4("Visenescu Valeria",
                                                                                                   "Biologie", 30);
    int v1[3] = {7, 9, 10};
    int v2[3] = {2, 10, 10};
    int v3[3] = {4, 4, 8};
    int v4[2] = {8, 8};
    int v5[3] = {10, 10, 10};
    int v6[4] = {4, 4, 5, 5};
    int v7[5] = {10, 10, 9, 10, 10};
    Elev elevi1[2], e1("Telu Andrei", v1, 3, v2, 3, v3, 3, v4, 2, 10), e2("Pandeliu Casian", v4, 2, v5, 3, v1, 3, v2, 3,
                                                                          4);
    elevi1[0] = e1;
    elevi1[1] = e2;
    Elev elevi2[2], e3("Anton Anelis", v1, 3, v7, 5, v2, 3, v6, 4, 3);
    elevi2[0] = e3;
    Elev elevi3[3], e4("Gheorghe Marius-Andrei", v5, 3, v6, 4, v5, 3, v3, 3, 20), e5("Vanocea Sebi", v4, 2, v3, 3, v3,
                                                                                     3, v3, 3, 20), e6("Bilous Vlad",
                                                                                                       v3, 3, v5, 3, v2,
                                                                                                       3, v2, 3, 5);
    elevi3[0] = e4;
    elevi3[1] = e5;
    elevi3[2] = e6;
    Elev elevi4[4], e7("Telu Mihai", v7, 5, v4, 2, v4, 2, v7, 5, 0), e8("Fugulin Victor-Gabriel", v7, 5, v7, 5, v3, 3,
                                                                        v3, 3, 0), e9("Serban Alexandru", v7, 5, v7, 5,
                                                                                      v6, 4, v7, 5, 3), e10(
            "Ciuca Teodora", v6, 4, v7, 5, v6, 4, v2, 3, 1);
    elevi4[0] = e7;
    elevi4[1] = e8;
    elevi4[2] = e9;
    elevi4[3] = e10;
    Clasa C1("9A", P1, elevi1, 2), C2("10A", P3, elevi2, 1), C3("11A", P4, elevi3, 3), C4("12A", P2, elevi4, 4  );
    Clasa clase[12];
    clase[0] = C1;
    clase[1] = C2;
    clase[2] = C3;
    clase[3] = C4;
    int nr_clase = 4;
//for(int i=0;i<4;i++){
//    cout<<clase[i]<<endl;
//}
    int n;
    do {
        cout << "          MENIU-CATALOAGELE LICEULUI X    " << endl;
        cout << "Apasa 1 pentru OPTIUNI-CLASE" << endl;
        cout << "Apasa 2 pentru OPTIUNI-ELEVI" << endl;
        cout << "Apasa 3 pentru OPTIUNI-DIRIGINTI" << endl;
        cout << "Apasa 0 pentru A IESI" << endl;
        cin >> n;
        if(n==0){break;}
        switch (n) {
            case (1): {
                int n1;
                do {
                    cout << "          OPTIUNI-CLASE    "<<endl;
                    cout << "Apasa 1 pentru a vizualiza clasele" << endl;
                    cout << "Apasa 2 pentru a adauga o clasa noua" << endl;
                    cout << "Apasa 3 pentru a vizualiza media unei clase" << endl;
                    cout << "Apasa 0 pentru a te intoarce" << endl;
                    cin>>n1;
                    if(n1==0){break;}
                    switch (n1) {
                       case (1): {
                           int x = 0;
                           for (int i = 0; i < nr_clase; i += 2)
                               x += clase[i] + clase[i + 1];
                           if (nr_clase % 2 == 1)x += clase[nr_clase - 1].getnrelevi();
                           cout << "Liceul X are in acest moment " << x << " elevi." << endl;
                           cout << "Clase: "<<endl;
                           int egal=0;
                               for(int i=0;i<nr_clase;i++)
                                   for(int j=i+1;j<nr_clase;j++)
                                       if(clase[i]==clase[j])
                                         egal=1;
                           for (int i = 0; i < nr_clase; i++) {
                               cout << clase[i] << endl;
                           }
                           if(egal==1)
                              cout<<"Exista clase ce par a fi identice!!!"<<endl;
                           cout<<endl;
                           break;
                       }

                       case (2): {
                           cout<<"Clasa noua "<<endl;
                           cout<< "Pot exista maxim 12 clase, iar denumirea unei clase va fi de forma XY, X={9,10,11,12}, Y={A,B,C,D} si ar trebui sa difere de a celorlalte(optional). Un nume valid va fi marcat prin <<ACCEPTAT!>>."<< endl;
                           cin >> clase[nr_clase];
                           nr_clase++;
                           cout<<endl<<endl;
                           break;
                       }

                       case(3):{
                           cout<<"Media unei clase "<<endl;
                           cout<<"Nume clasa(de forma XY, X={9,10,11,12}, Y={A,B,C,D}): ";
                           string s;
                           cin.get();
                           getline(cin,s);
                           int ok=0;
                           for(int i=0;i<nr_clase;i++)
                           {
                               if(clase[i].getnume()==s){
                                   cout<<clase[i].MediaClasei()<<endl;
                                   ok=1;
                                   break;
                               }
                           }
                           if(ok==0)cout<<"Nu exista aceasta clasa!!!"<<endl;
                           cout<<endl;
                           break;
                       }

                       default:{
                           cout<<endl<<endl;
                           break;
                       }
                   }

                }while(n1!=0);
                cout<<endl<<endl<<endl<<endl;
                break;
            }



            case(2): {
                int n2;
                do{
                    cout<<"        OPTIUNI-ELEVI     "<<endl;
                    cout<<"Apasa 1 pentru a vizualiza datele unui elev"<<endl;
                    cout<<"Apasa 2 pentru a adauga un nou elev"<<endl;
                    cout<<"Apasa 3 pentru a exmatricula un elev"<<endl;
                    cout<<"Apasa 4 pentru a pune o nota"<<endl;
                    cout<<"Apasa 5 pentru a pune o absenta"<<endl;
                    cout << "Apasa 0 pentru a te intoarce" << endl;
                    cin>>n2;
                    if(n2==0){break;}
                    switch (n2) {
                        case(1):{
                            cout<<"Datele unui elev"<<endl;
                            string numeElev,numeClasa;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {cout<<clase[i].getelevi()[j]<<endl;ok=1;}
                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl;
                            break;
                        }

                        case(2):{
                            cout<<"Adauga elev nou"<<endl;
                            string numeClasa,numeElev;
                            cout<<"Numele clasei in care vrem sa-l adaugam: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele noului elev: ";
                            getline(cin,numeElev);
                            Elev e(numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++)
                                if(clase[i].getnume()==numeClasa)
                                {clase[i].AdaugaElev(e);cout<<endl;ok=1;}
                            if(ok==0)cout<<"Nu exista clasa mentionata!!!"<<endl;
                            cout<<endl;
                            break;
                        }

                        case(3):{
                           cout<<"Exmatriculeaza elev"<<endl;
                            string numeClasa,numeElev;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++)
                                if(clase[i].getnume()==numeClasa)
                                {clase[i].ExmatriculeazaElev(numeElev);cout<<endl;ok=1;}
                            if(ok==0)cout<<"Nu exista clasa mentionata sau elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl;
                            break;
                        }

                        case(4):{
                            cout<<"Pune nota"<<endl;
                            string numeClasa,numeElev,materia;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            cout<<"Materia la care se pune nota(Matematica, Romana, Fizica, Informatica): ";
                            getline(cin,materia);
                            int nota;
                            cout<<"Nota: ";
                            cin>>nota;
                            cout<<endl;
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {clase[i].getelevi()[j].PuneNota(materia,nota);cout<<endl;ok=1;}

                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl;
                            break;
                        }

                        case(5):{
                            cout<<"Pune absenta"<<endl;
                            string numeClasa,numeElev;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {clase[i].getelevi()[j].PuneAbsenta();cout<<endl;ok=1;}

                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl;
                            break;
                        }

                        default:{
                            cout<<endl<<endl;
                            break;
                        }
                    }


                }while(n2!=0);
                cout<<endl<<endl<<endl<<endl;
                break;
            }



            case(3):{
                int n3;
                do{
                cout<<"          OPTIUNI-DIRIGINTE     "<<endl;
                cout<<"Apasa 1 pentru a vizualiza datele unui diriginte"<<endl;
                cout<<"Apasa 2 pentru a adauga ani vechime"<<endl;
                cout<<"Apasa 3 pentru a schimba dirigintele"<<endl;
                cout<<"Apasa 0 pentru a te intoarce"<<endl;
                cin>>n3;
                if(n3==0){break;}
                switch (n3) {
                    case(1):{
                        cout<<"Datele unui diriginte"<<endl;
                        string numeClasa;
                        cout<<"Numele clasei: ";
                        cin.get();
                        getline(cin,numeClasa);
                        int ok=0;
                        for(int i=0;i<nr_clase;i++){
                            if(clase[i].getnume()==numeClasa)
                            {cout<<clase[i].getprofesor()<<endl;ok=1;}
                        }
                        if(ok==0)cout<<"Nu exista clasa respectiva!!!"<<endl;
                        cout<<endl;
                        break;
                    }

                    case(2):{
                        cout<<"Adauga ani vechime"<<endl;
                        string numeClasa;
                        cout<<"Numele clasei: ";
                        cin.get();
                        getline(cin,numeClasa);
                        int ok=0;
                        for(int i=0;i<nr_clase;i++){
                            if(clase[i].getnume()==numeClasa)
                            {clase[i].setvechime();cout<<endl;ok=1;}
                        }
                        if(ok==0)cout<<"Nu exista clasa respectiva!!!"<<endl;
                        cout<<endl;
                        break;
                    }

                    case(3):{
                        cout<<"Schimba dirigintele"<<endl;
                        string numeClasa;
                        cout<<"Numele clasei: ";
                        cin.get();
                        getline(cin,numeClasa);
                        int ok=0;
                        for(int i=0;i<nr_clase;i++){
                            if(clase[i].getnume()==numeClasa)
                            {cout<<"Datele noului diriginte: "<<endl;clase[i].SchimbaDiriginte();cout<<endl;ok=1;}
                        }
                        if(ok==0)cout<<"Nu exista clasa respectiva!!!"<<endl;
                        cout<<endl;
                        break;
                    }

                    default:{
                        cout<<endl<<endl;
                        break;
                    }

                }
                }while(n3!=0);
                cout<<endl<<endl<<endl<<endl;
                break;
            }



            default:{
                cout<<endl<<endl<<endl<<endl;
                break;
            }

        }
    }while (n != 0);
}