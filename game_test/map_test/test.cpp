#include <iostream>
#include "map.h"

int main(){
    GameMapdata* m = new GameMapdata(5,1);
    //m->test_print();
    m->print_tree();
    //m->~GameMapdata();
    //m->test_print();
}