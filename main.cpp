#include <iostream>
#include "include\LList.h"
#include "include\ArrayList.h"

using namespace std;

int main()
{
    LList<int> lista;
    lista.append(6);
    lista.append(8);
    lista.append(10);

    ArrayList<int> letras;
    letras.append(3);
    letras.append(4);
    letras.getSize();
    return 0;
}


