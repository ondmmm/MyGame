#include "area.h"

area::area(){
    event_id=-1;
    model=nullptr;
    title="既定コンストラクタ";
    area_scene=-1;
    select_pointer_6 = 0;
    select_pointer_2 = 0;
}
area::area(Model* m, int id){
    model = m;
    event_id =id;
    if(id == 10){
        title = "1-boss";
    }else if(id == 11){
		title = "かき氷づくり";
    }else if(id == 12){
        title = "打ち上げ花火";
    }else if(id == 13){
        title = "波状攻撃";
    }else if(id == 14){
        title = "軽量化";
    }else if(id == 15){
        title = "掘り出し物？";
    }else if(id == 16){
        title = "命を背負って";
    }else if(id == 17){
        title = "旅商人";
    }else if(id == 18){
        title = "休憩ポイント";
    }else if(id == 19){
        title = "丁か半か";
    }else if(id == 20){
        title = "2-boss";
    }else if(id == 21){
        title = "荒滝行";
    }else if(id == 22){
        title = "阿弥陀迷宮";
    }else if(id == 23){
        title = "挟撃";
    }else if(id == 24){
        title = "軽量化";
    }else if(id == 25){
        title = "掘り出し物？";
    }else if(id == 26){
        title = "投資活動";
    }else if(id == 27){
        title = "旅商人";
    }else if(id == 28){
        title = "休憩ポイント";
    }else if(id == 29){
        title = "下手な鉄砲も...";
    }else if(id == 30){
        title = "3-boss";
    }else if(id == 31){
        title = "満員電車";
    }else if(id == 32){
        title = "特攻部隊";
    }else if(id == 33){
        title = "とげとげ要塞";
    }else if(id == 34){
        title = "軽量化";
    }else if(id == 35){
        title = "起死回生...?";
    }else if(id == 36){
        title = "捨て去る覚悟";
    }else if(id == 37){
        title = "旅商人";
    }else if(id == 38){
        title = "休憩ポイント";
    }else if(id == 39){
        title = "虎穴に入らずんば...";
    }else {
        title = "想定外のidが指定されています";
    }
    area_scene = 0;
    select_pointer_6 = 0;
    select_pointer_2 = 0;
    timer = 5;
}
area::~area(){
    free(this);
}
void area::game_event(int t){
    //std::cout << "scene : "<<std::to_string(area_scene)<<" , timer : " << std::to_string(t)<<" , "<<title << std::endl;
    if(area_scene == 0){
        if(timer <= t){
            timer = t + 10;
            area_scene = 1;
        }
    }else if(area_scene == 1){
        if(timer <= t){
            timer = t + 5;
            area_scene = 3;
        }
    }else if(area_scene == 2){

    }else if(area_scene == 3){
        if(timer <= t){
            model->set_scene(0);
        }
    }
}
int area::get_event_id(){
    return event_id;
}
std::string area::get_title(){
    return title;
}
int area::get_area_scene(){
    return area_scene;
}
int area::get_pointer_6(int d){
    if(d == 0){
        return select_pointer_6;
    }
    if(d == 1){
        select_pointer_6 = select_pointer_6 - 2;
        if(select_pointer_6 < 0){
            select_pointer_6 = select_pointer_6 + 6;
        }
    }else if(d == 2){
        if(select_pointer_6 % 2 == 0){
            select_pointer_6 = select_pointer_6 + 1;
        }else{
            select_pointer_6 = select_pointer_6 - 1;
        }
    }else if(d == 3){
        select_pointer_6 = select_pointer_6 + 2;
        if(select_pointer_6 > 6){
            select_pointer_6 = select_pointer_6 - 6;
        }
    }else if(d == 4){
        if(select_pointer_6 % 2 == 0){
            select_pointer_6 = select_pointer_6 + 1;
        }else{
            select_pointer_6 = select_pointer_6 - 1;
        }
    }else {
        select_pointer_6 = 0;
    }
    return select_pointer_6;
}
int area::get_pointer_2(int d){
    if(d == 0){
        return select_pointer_2;
    }
    if(select_pointer_2 == 0){
        select_pointer_2 = 1;
    }else if(select_pointer_2 == 1){
        select_pointer_2 = 0;
    }else{
        select_pointer_2 = 0;
    }
    return select_pointer_2;
}