#include "model.h"
Model::Model(){
    gametimer = 0;  // 単位秒での時間
	frame = 0;      // フレーム数の管理のための変数
    scene = 1;
    i_list = new itemlist();
	map = new GameMapdata(4,1);
    stage = new area(this, map->get_current_node()->get_event());
    map->print_tree();
}
Model::~Model(){
    stage->~area();
    free(this);
}
void Model::update(){
    if(scene == 0){
        gametimer = 0;
        frame = 0;
        map->get_current_node()->test_print();
        while(true){
            if(map->get_current_node()->get_deapth()+1 == map->get_deapth()){
                scene = -1;
                break;
            }   
            std::string line = ""; 
            getline(std::cin, line);
            int i = std::stoi(line);
            if((i==1)&&(map->get_current_node()->get_left_node() != nullptr)){
                stage->~area();
                map->node_change(i);
                stage = new area(this, map->get_current_node()->get_event());
                scene = 1;
                break;
            }else if((i==2)&&(map->get_current_node()->get_middle_node() != nullptr)){
                stage->~area();
                map->node_change(i);
                stage = new area(this, map->get_current_node()->get_event());
                scene = 1;
                break;
            }else if((i==3)&&(map->get_current_node()->get_right_node() != nullptr)){
                stage->~area();
                map->node_change(i);
                stage = new area(this, map->get_current_node()->get_event());
                scene = 1;
                break;
            }
        }     
    }else if(scene == 1){
        stage->game_event(gametimer);
        if(frame >= 60){
            frame = 0;
            gametimer++;
        }
        frame++;
    }
}
int Model::get_timer(){
    return gametimer;
}
int Model::get_scene(){
    return scene;
}
void Model::set_scene(int s){
    scene = s;
}