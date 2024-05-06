#include <iostream>
#include <cstdlib>

using namespace std;

class Stos
{
public:
    int* tab, wierzch, rozmiar;
    Stos(); // konstruktor domyślny
    Stos(int rozm); // konstruktor jednoparametrowy
    ~Stos(); // destruktor
    void push(int liczba);
    void pop();
    int top();
    bool empty();
    bool full();
};

Stos::Stos()
{
    tab = nullptr; // Nie alokujemy pamięci w konstruktorze domyślnym
    rozmiar = 0;
    wierzch = -1;
    cout << "Konstruktor Stos() wywolany dla obiektu o adresie: " << this << endl;
}

Stos::Stos(int rozm)
{
    tab = new int[rozm];
    rozmiar = rozm;
    wierzch = -1;
    cout << "Konstruktor Stos(" << rozm << ") wywolany dla obiektu o adresie: " << this << endl;
}

Stos::~Stos()
{
    delete[] tab;
    cout << "Destruktor Stos wywolany dla obiektu o adresie: " << this << endl;
}

void Stos::push(int liczba) 
{ 
    if (!full()) {
        tab[++wierzch] = liczba; 
    } else {
        cout << "Stack overflow!" << endl;
    }
}

void Stos::pop () 
{ 
    if (!empty()) {
        --wierzch; 
    } else {
        cout << "Stack underflow!" << endl;
    }
}

int Stos::top () 
{ 
    if (!empty()) {
        return tab[wierzch]; 
    } else {
        cout << "Stack is empty!" << endl;
        return -1;
    }
}

bool Stos::empty () 
{ 
    cout<<"STOS PUSTY";
    return wierzch == -1; 
}

bool Stos::full() 
{ 
    return wierzch == rozmiar - 1; 
}

void f(Stos s, int a) { //void f(Stos& s, int a)
    s.push(a);
}
//błędem jest przekazanie stosu przez wartość co oznacza że jest on kopiowany a operacje pop i push 
// są wykonywane na kopii obiektu. Oby poprawić program musimy zmienić powyższy kod. Oraz podać rozmiar stosu
// wywołując konstruktor
int main() {
    Stos s; //Stos s(3)
    s.push(0);
    f(s, 1);
    f(s, 2);
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}