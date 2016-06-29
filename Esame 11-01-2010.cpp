/*
Scrivere un semplice programma per gestire una lista ordinata di strutture con due soli campi: un intero ed il
vettore.
Il programma dovrà leggere da tastiera, attraverso un Menù, se l'utente vuole:
1. leggere da tastiera un valore intero positivo ed inserirlo in maniera ordinata (crescente) nella lista
(carattere a);
2. calcolare la somma di tutti i valori presenti nella lista (carattere b);
3. scegliere se calcolare la somma dei numeri pari o dispari presenti nella lista (carattere c);
4. stampare a video i valori contenuti nella lista (carattere d);
5. uscire dal programma (carattere e);
Fatta la scelta dal Menù il programma dovrà attraverso le apposite funzioni:
1. leggere dalla tastiera un numero intero, tale lettura si dovrà ripetere finché il valore inserito è negativo;
2. inserire nella lista il valore appena letto nella posizione opportuna secondo un ordine crescente;
3. calcolare la somma di tutti i valori presenti nella lista e stampare a video tale valore
4. calcolare la somma:
• dei soli valori pari presenti nella lista attraverso il flag = 0;
• dei soli valori dispari presenti nella lista attraverso il flag = 1;
5. stampare a video il contenuto dell'intera lista;
*/
#include <iostream>
using namespace std;
struct studente
{
int valore;
studente* succ;
};
typedef studente* lista;

void inserisci_dati(studente& s);
int somma_valori_totali(lista p0);
void somma_valori(lista p0, int flag);
void inserisci_ordinatamente(lista& inizio, studente e);
void stampa_lista(lista p0);

int main(){
    char s;
    studente elem;
    int num=0;
    lista inizio=0;
    do{
        cout << "\nMENU'\n";
        cout << "a) Inserisci un valore intero nella lista\n";
        cout << "b) Calcola la somma di tutti i valori presenti nella ";
        cout << "lista\n";
        cout << "c) Calcola la somma dei valori pari o dispari presenti";
        cout << " nella lista\n";
        cout << "d) Visualizza a schermo il contenuto della lista\n";
        cout << "e) Esci\n";
        cout << "Scelta: ";
        cin>>s;
        switch(s){
        case 'a':{
            inserisci_dati(elem);
            inserisci_ordinatamente(inizio,elem);
        break;
        }
        case 'b':{
            cout<<"la somma di tutti i valorei della lista e' "<<somma_valori_totali(inizio)<<endl;
        break;
        }
        case 'c':{
            int h;
            cout<<"inserisci 1 se vuoi sommare i numeri pari 0 se vuoi sommare i dispari"<<endl;
            cin>>h;
            switch (h){
            case 1:{
                num=1;
                somma_valori(inizio,num);
            break;
            }
            case 0:{
                num=0;
                somma_valori(inizio,num);
            break;
            }
            default:{
                cout<<"numero non concentito"<<endl;
            break;
            }
            }
        break;
        }
        case 'd':{
            stampa_lista(inizio);
        break;
        }
        case 'e':{
        break;
        }
        default :{
            cout<<"lettera non consentita"<<endl;
        break;
        }
        }
    }while(s!='e');
return 0;
}

void inserisci_dati(studente& s){
    do{
        cout<<"inserisci il valore nella lista"<<endl;
        cin>>s.valore;//copia il valore inserito nella struct
        if(s.valore<0){
            cout<<"inserisci solo valori positivi"<<endl;
        }
    }while(s.valore<0);
}

void inserisci_ordinatamente(lista& inizio, studente e){
lista p=0,q,r;
for(q=inizio;q!=0&&q->valore<e.valore;q=q->succ){
    p=q;
}
r=new studente;
*r=e;
r->succ=q;
if(q==inizio){
    inizio=r;
}
else {
    p->succ=r;
}
}

int somma_valori_totali(lista p0){
    int somma=0;
    if(p0==0){
        cout<<"lista è vuota"<<endl;
    }
    while(p0!=0){
        somma+=p0->valore;
        p0=p0->succ;
    }
    return somma;
}

void stampa_lista(lista p0){
    if(p0==0){
        cout<<"la lista è vuota"<<endl;
    }
    while(p0!=0){
        cout<<p0->valore<<endl;
        p0=p0->succ;
    }
}

void somma_valori(lista p0, int flag){
    int sommap=0;
    int sommad=0;
    if(p0==0){
        cout<<"la lista è vuota"<<endl;
    }
    while(p0!=0){
        if(p0->valore%2==0){//vede se il resto della divisione è 0 o no
            sommap+=p0->valore;//somma il valore solo se è pari
        }
        else{
            sommad+=p0->valore;//somma il valore solo se dispari
        }
        p0=p0->succ;
    }
    if(flag==1){//stampa in base al flag se pari o dispari
        cout<<"la somma dei numeri pari è "<<sommap;
    }
    if(flag==0){
        cout<<"la somma dei numeri dispari è "<<sommad;
    }
}

//Coded by DarkCerfa
