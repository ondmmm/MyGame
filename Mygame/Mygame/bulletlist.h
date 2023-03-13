#pragma once

class Model;
class Bullet;
class BulletList {
private:
	Bullet* b_list[50];				 // 1つのクラスで50までの弾を管理します
public:
	BulletList();                    // コンストラクタ
	BulletList(Model*);				 // コンストラクタ
	~BulletList();                   // デストラクタ
	Bullet* get_bullet(int);	   	 // 特定の弾データを取得したい場合に使用します
	Bullet* get_useful();			 // 非アクティブ状態(発射していない状態)の弾を1つ取得します
	void set_bullet(Bullet*);		 // 新たに弾データを登録したい場合に使用します
	void update(int);				 // 弾の情報を更新する際に使用します
	void reset_bullets();			 // 全ての弾を非アクティブ状態にします
};