#pragma once
#include "game_obj.h"
#include <math.h>
class Model;
class Bullet;
class BulletList;
class Enemy;
class EnemyList;
class game_obj;
class Chara : public game_obj {											// ゲーム内に登場するオブジェクトは継承を行うことで冗長になる対策を行う
private:
	Model* m;															// 制御するmodelクラスへのポインタ
	int level;															// プレイヤーレベルを示す、経験値に応じて上昇し、攻撃力が上がる
	int health;															// 残機数を表す、残機0までゲームができる、残機がマイナスになるとゲームオーバー
	int bomb;															// ボム数を表す、消費することで敵にダメージを与え、画面上の弾を消去できる
	int offensive_point[10] = {1,1,2,2,2,3,3,3,4,5};					// レベルに応じた攻撃力のマップ
	int necessary_exp[10] = {16,32,64,64,128,128,128,256,512,-1 };		// レベルアップに必要な経験値のマップ、最大レベルの時は-1を返し、この値がマイナスの際にはレベルアップがおきない様に気を付ける
	int exp;															// 獲得した経験値を示す、レベルが上がると0から貯めなおしになり、一定以上でレベルがまた上がる
	int tip;															// 保持するお金を示す、敵を倒すたびに上昇し商人と交換することで便利にゲームが進む
	int shot_delay;														// 連続で弾を発射する場合にかかる遅延管理に利用
	int opt_delay;														// オプションの遅延管理に使用します
	bool shield;														// 一回攻撃を無効にできる状態かどうかを表します
public:
	Chara();
	Chara(Model*);
	~Chara();
	void level_check();
	bool isHit(Bullet*);
	bool isHit(Enemy*);
	void add_exp();
	void add_tip();
	void sub_tip(int);
	void set_level(int);
	void set_health(int);
	void set_bomb(int);
	void set_d_timer(int);
	int get_level();
	int get_health();
	int get_bomb();
	int get_off_p();
	int get_ne_exp();
	int get_exp();
	int get_tip();
	int get_d_timer();
	void update();
	void update(BulletList*);
	void update(EnemyList*);
	void update(Enemy*);
	void reset_status();
};