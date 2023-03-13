#pragma once
#include <string>
#include <tchar.h>
class Model;
class area{
private:
    int event_id;           // ステージの持つイベントの種類を管理します
    Model* model;           // ゲームを進めるために必要な自機の情報などを持つModelクラスへのポインタ
    TCHAR title[256];      // ステージのタイトルを示します
    int area_scene;         // このステージの状態を管理します(0->タイトル表示の待機状態, 
                            //                                1->シューティングゲーム
                            //                                2->ENTERキーで進む文字送り状態
							//							      3->6択を選択する状態
							//								  4->2択を選択する状態
                            //                                5->クリア表示の待機状態       )
    int select_pointer_6;   // 主に商人イベントで6つの選択肢を管理します
    int select_pointer_2;   // イベント内で発生する2択の選択肢を管理します
    int timer_s;            // 主にシューティングゲーム上で時間経過(秒単位)による処理をするために使用します
	int timer_f;			// 主にシューティングゲーム上で時間経過(フレーム単位)による処理をするために使用します
	int basetimer_s;		// ある基準となる時間から特定の秒数経ったかを確かめるときに使用
	int basetimer_f;		// ある基準となる時間から特定のフレーム数経ったかを確かめるときに使用
	int saleitems[4];		// 商人が販売するアイテムの管理に使用します
	int phase;				// イベント内での状態遷移に使用します
public:
    area();
    area(Model*, int);
	~area();
    void game_event(int,int);   // 引数で経過時間を受け取りそれに応じてイベントが起きるようにします
    int get_event_id();		// 現在起きているイベントのidを返します 
    TCHAR* get_title();
    int get_area_scene();	// イベントの受付状況を示す数値を返します
    int get_pointer_6(int); // 引数に応じて6択のポインタを更新し、指している場所を返します(0->そのまま、1->右へ移動、2->左へ移動)
    int get_pointer_2(int);
	int get_prize_id();		// 商人で購入したアイテムのidを返します
	void set_scene(int);	// 引数で得た数値に受付状態を変更します
	void set_phase(int);	// 引数で得た数値にフェーズを変更します
	int get_phase();		// 現在のフェーズ番号を返します
};