#include <iostream>
#include "model.h"

int main(){
    Model* m = new Model();
    while(m->get_scene()==1){
        m->update();
    }
}