#pragma once

class Model;
class Enemy;
class BulletList;
class EnemyList {
private:
	Enemy * e_list[20];
public:
	EnemyList();                    // 規定コンストラクタ、多分使わない
	EnemyList(Model*);				// コンストラクタ、こっちを使う
	~EnemyList();                   // デストラクタ
	Enemy* get_enemy(int);	   		// 特定の敵データを取得したい場合に使用します
	void set_enemy(Enemy*);			// 新たに敵データを登録したい場合に使用します
	void update(BulletList*);		// 敵の情報を更新する際に使用します
	void reset_enemyss();			// 全ての敵を非アクティブ状態にします
};