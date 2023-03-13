#pragma once
class item;
class itemlist{
private:
    item* i_list[26];
public:
    int ATTACK = 0;
    int ZANKI = 1;
    int BOMB = 2;
    int PLAYER_COLISION = 3;
    int EXP = 4;
    int DISCOUNT = 5;
    int ENEMY_HEALTH = 6;
    int ATTACK_LOWSPEED = 7;
    int PLAYER_SPEED = 8;
    int SCORE = 9;
    itemlist();                    // コンストラクタ、各アイテムを呼び出し、初期化します
    ~itemlist();                   // デストラクタ
    int get_boost(int);            // 第一引数で受け取ったパラメータについてアイテムによるボーナス値を取得します
    void get_items_sale(int[4]);   // 第一引数の配列に商人イベントでの売り物のリストを作成します
    int get_option();              // 保持しているオプションを取得します
    int set_option(int);           // 引数で指定したものにオプションを変更します、既に保持していたオプションは売却されます(返り値で売値を渡す)
    void test_items();             // デバッグ用関数です。各アイテムに対して50%で保有した状態にして関数の返り値を確認します
	item* get_item(int);		   // 第一引数のidのアイテムを取得します
	void reset_items();			   // アイテムの取得状況をリセットします
};