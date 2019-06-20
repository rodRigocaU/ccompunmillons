#include <iostream>
#include "nodo.h"
#include "nodod.h"
#include "LE.h"
#include "LED.h"
#include "LEC.h"
#include "LEDC.h"
#include "mergesort.h"


using namespace std;

int main()
{
    cout << '\n';
    cout << "LISTA ENLAZADA SIMPLE" << '\n';
    LE<int> o;
    string s;
    /*while(true)
    {
        cout << " (a) add y (r) remove" << '\n';
        cin >> s;
        if(s == "a")
        {
            cout << '\n';
            int x;
            cin >> x;
            o.add(x);
        }
        else
        {
            cout << '\n';
            int x;
            cin >> x;
            o.remov(x);
        }
        cout << '\n';
        cout << '\n';
        o.print();
    }
    o.add(15);
    o.add(17);
    o.add(18);
    o.add(14);
    o.print();
    cout << '\n';
    o.remov(18);
    o.print();*/

    /*cout << "LISTA ENLAZADA DOBLE" << '\n';
    cout << '\n';
    LED<int> a;
    a.add(3);
    a.add(6);
    a.add(4);
    //a.add(6);
    a.print();
    cout << '\n';
    a.remov(6);
    a.print();
    cout << '\n';
    /*a.remov(4);
    a.print();*/

    /*cout << "LISTAS ENLAZADAS SIMPLES CIRCULAR" << '\n';
    cout << '\n';
    LEC<int> b;
    b.add(1);
    b.add(5);
    b.add(3);
    b.print();
    cout << '\n';
    b.add(11);
    b.print();
    cout << '\n';
    b.add(12);
    b.print();
    cout << '\n';
    b.remov(12);
    b.print();
    b.remov(1);
    b.print();
    b.remov(5);
    b.print();*/

    /*cout << "LISTAS ENLAZADAS DOBLE CIRCULAR"  << '\n';
    LEDC<int> c;
    c.add(5);
    c.add(2);
    c.add(6);
    c.add(4);
    c.print();
    cout << '\n';
    c.remov(4);
    c.print();*/

    ///JOSEPHUS
    /*LEC<int> h;
    cout << "Ingrese el tamaño : " << '\n';
    int tam;
    int kill;
    cin >> tam;
    cout << "Ingrese la rotacion de muerte : " << '\n';
    cin >> kill;
    for(int x  = 1; x <= tam; x++)
    {
        h.add(x);
    }
    h.print();
    h.josephus(tam,kill);
    cout << '\n';
    h.print();*/

    //LISTA SIMPLE CIRCULAR
    /*LEC<int> prueba;
    prueba.add(3);
    prueba.add(8);
    prueba.add(1);
    prueba.add(5);
    prueba.print();
    prueba.remov(5);
    prueba.print();*/
    ///MERGE

    /*mergesort<int> k;
    LE<int> z;
    z.add(1);
    z.add(2);
    z.add(3);
    LE<int> x;
    x.add(1);
    x.add(5);
    x.add(6);
    x.add(7);
    x.print();
    k.sorted(z,x);
    z.print();*/




    return 0;
}
