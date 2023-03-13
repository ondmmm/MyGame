#pragma once
#include "model.h"
#include <string>
class Model;
class area{
private:
    int event_id;           // ステージの持つイベントの種類を管理します
    Model* model;           // ゲームを進めるために必要な自機の情報などを持つModelクラスへのポインタ
    std::string title;      // ステージのタイトルを示します
    int area_scene;         // このステージの状態を管理します(0->タイトル表示の待機状態, 
                            //                              1->シューティングゲーム
                            //                              2->ENTERキーで進む文字送り状態
                            //                              3->クリア表示の待機状態       )
    int select_pointer_6;   // 主に商人イベントで6つの選択肢を管理します
                            // 下記参照
                            // [0][1]
                            // [2][3]
                            // [4][5]
                            // 上記0~5について上下左右で動くようにする(0の状態で下を押したら2の位置に注目が移る)
    int select_pointer_2;   // イベント内で発生する2択の選択肢を管理します
    int timer;              // 主にシューティングゲーム上で時間経過による処理をするために使用します
public:
    area();
    area(Model*, int);
	~area();
    void game_event(int);   // 引数で経過時間を受け取りそれに応じてイベントが起きるようにします、例)10秒後に何かが起きる場合はtimer変数に基準点となる段階で引数+10の数値を代入しておく、引数 >= timerでイベントを発生させる
    int get_event_id();
    std::string get_title();
    int get_area_scene();
    int get_pointer_6(int); // 動かす方向を引数で管理、上を1として時計回りに2,3,4と続く、動かさず数値だけを取得する場合には0を指定する
    int get_pointer_2(int);
};