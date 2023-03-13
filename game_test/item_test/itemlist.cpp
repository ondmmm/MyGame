#include "itemlist.h"
#include <cstdlib> 
#include <string>
#include <time.h>
itemlist::itemlist(){
    for(int i = 0; i < 26; i++){
        i_list[i] = new item(i);
    }
}
itemlist::~itemlist(){
    for(int i = 0; i < 26; i++){
        i_list[i]->~item();
    }
    free(this);
}
int itemlist::get_boost(int i){
    int r = 0;
    if(i == ATTACK){
        if(i_list[0]->isActive()){
            r = r + 30;
        }
        if(i_list[9]->isActive()){
            r = r + 10;
        }
        if(i_list[10]->isActive()){
            r = r + 20;
        }
        if(i_list[11]->isActive()){
            r = r + 35;
        }
    }else if(i == ZANKI){
        if(i_list[1]->isActive()){
            r = r + 1;
        }
        if(i_list[2]->isActive()){
            r = r + 2;
        }
        if(i_list[3]->isActive()){
            r = r + 3;
        }
        if(i_list[0]->isActive()){
            r = r + 2;
        }
    }else if(i == BOMB){
        if(i_list[4]->isActive()){
            r = r + 1;
        }
        if(i_list[5]->isActive()){
            r = r + 2;
        }
        if(i_list[6]->isActive()){
            r = r + 3;
        }
        if(i_list[0]->isActive()){
            r = r + 2;
        }
    }else if(i == PLAYER_COLISION){
        r = 100;
        if(i_list[7]->isActive()){
            r = 75;
        }
        if(i_list[8]->isActive()){
            r = 50;
        }
    }else if(i == EXP){
        if(i_list[12]->isActive()){
            r = r + 1;
        }
        if(i_list[13]->isActive()){
            r = r + 2;
        }
    }else if(i == DISCOUNT){
        r = 100;
        if(i_list[14]->isActive()){
            r = r - 25;
        }
        if(i_list[15]->isActive()){
            r = r - 50;
        }
    }else if(i == ENEMY_HEALTH){
        r = 100;
        if(i_list[16]->isActive()){
            r = r - 10;
        }
        if(i_list[17]->isActive()){
            r = r - 25;
        }
    }else if(i == ATTACK_LOWSPEED){
        r = get_boost(ATTACK);
        if(i_list[19]->isActive()){
            r = r + 85;
        }
    }else if(i == PLAYER_SPEED){
        r = 100;
        if(i_list[20]->isActive()){
            r = 150;
        }
    }else if(i == SCORE){
        r = 100;
        if(i_list[20]->isActive()){
            r = 50;
        }
    }else {
        r = 0;
    }
    return r;
}
void itemlist::get_items_sale(int list[4]){
    srand((unsigned int)time(NULL));
    int tmp = 0;
    for(int n = 0; n < 4; n++){
        list[n]=-1;
    }
    for(int i = 0; i < 26; i++){    // 未保持のアイテム数を確認
        if(!(i_list[i]->isActive())){
            tmp++;
        }
        if(tmp >= 4){
            tmp = 4;
            break;
        }
    }
    int x;
    bool dup;
    for(int l = 0; l < tmp; l++){
        while(1){
            dup = false;
            x = rand() % 25 + 1;
            for(int i = 0; i < tmp; i++){
                if(x == list[i]){
                    dup = true;
                }
            }
            if((!(i_list[x]->isActive()))&&(!(dup))){
                list[l] = x;
                break;
            }
        }
    }
}
int itemlist::get_option(){
    int tmp = -1;
    for(int i = 21; i < 26; i++){
        if(i_list[i]->isActive()){
            tmp = i;
        }
    }
    return tmp;
}
int itemlist::set_option(int id){
    int tmp = 0;
    int i = get_option();
    if(i != -1){
        i_list[i]->set_active(false);
        tmp = 16 * (i_list[i]->LEGEND+1);
    }
    i_list[id]->set_active(true);
    return tmp;
}     
void itemlist::test_items(){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 26; i++){
        if(rand() % 2 == 0){
            i_list[i]->set_active(true);
        }
    }
    for(int i = 0; i < 26; i++){
        i_list[i]->test_item();
    }
    int l[4];
    get_items_sale(l);
    for(int i = 0; i < 4; i++){
        std::cout << std::to_string(l[i]) << std::endl;
        i_list[l[i]]->test_item();
    }
    for(int i = 0;i < 10;i++){
        std::cout << std::to_string(i)  << " : " << std::to_string(get_boost(i))<< std::endl;
    }
}