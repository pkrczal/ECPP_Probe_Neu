#include <iostream>
#include "PlayField.h"

int main() {
    PlayField p("TestName",5,5);
    p.addPair("UBoot", "1 Wert");
    p.addPair("Kreuzer", "3 Werte vertikal oder horizontal");
    p.addElement(0,0,1);
    p.addElement(1,1,2);
    p.addElement(2,2,9);
    p.write("data.txt");
    return 0;
}
