#include "model.h"
Model::Model(){
    gametimer = 0;  // 単位秒での時間
	frame = 0;      // フレーム数の管理のための変数
    scene = 1;
    stage = new area(this,11);
}
Model::~Model(){
    stage->~area();
    free(this);
}
void Model::update(){
    stage->game_event(gametimer);
    if(frame >= 60){
        frame = 0;
        gametimer++;
    }
    frame++;
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