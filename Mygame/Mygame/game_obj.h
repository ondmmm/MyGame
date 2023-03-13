#pragma once
#include "texture.h"
#include "sprite.h"
#include "model.h"
class Model;
class Texture;
class game_obj {				// 自機や弾等のクラスの継承元となる基本クラス
	protected:
		Model * model;			// 管理されるModelクラスへの参照、同時に管理されるたクラスへのアクセスに使用
		float pos_x;			// オブジェクトのx座標
		float pos_y;			// オブジェクトのy座標
		float vector_x;			// オブジェクトのx方向への向き(三角関数と速さを利用で任意の向きへ)
		float vector_y;			// オブジェクトのy方向への向き(三角関数と速さを利用で任意の向きへ)
		float velocity;			// オブジェクトの速さ
		float radius;			// 当たり判定となる半径を示す、判定は円同士で行う
		bool isActive;			// アクティブ状態になっているか、ゲーム上で画面に映るべき状態になっているか
		bool delay;				// 減速状態かを判別します
	public:
		game_obj() {			// コンストラクタ
			model = nullptr;
			isActive = false;
			pos_x = 0;
			pos_y = 0;
			vector_x = 0;
			vector_y = 0;
			delay = false;
		}
		game_obj(Model* m) {	// コンストラクタ
			model = m;
			isActive = false;
			pos_x = 0;
			pos_y = 0;
			vector_x = 0;
			vector_y = 0;
			delay = false;
		}
		game_obj(Model* m, float x, float y, float v_x, float v_y, float v) {	// コンストラクタ
			model = m;
			isActive = false;
			pos_x = x;
			pos_y = y;
			vector_x = v_x;
			vector_y = v_y;
			velocity = v;
			delay = false;
		}
		~game_obj() {}					// デストラクタ
		void set_pos_x(float x) {		// 引数で得た値でx座標を更新するセッタ関数
			pos_x = x;
		}
		void set_pos_y(float y) {		// 引数で得た値でy座標を更新するセッタ関数
			pos_y = y;
		}
		void set_vec_x(float x) {		// 引数で得た値でx方向の向きを更新するセッタ関数
			vector_x = x;
		}
		void set_vec_y(float y) {		// 引数で得た値でy方向の向きを更新するセッタ関数
			vector_y = y;
		}
		void set_velocity(float v) {	// 引数で得た値でを速さ更新するセッタ関数
			velocity = v;
		}
		void set_Active(bool b) {		// 引数で得た値でアクティブ状態を更新するセッタ関数
			isActive = b;
		}
		void set_radius(float f){		// 引数で得た値で半径を更新するセッタ関数
			radius = f;
		}
		float get_pos_x() {				// x座標のゲッタ関数
			return pos_x;
		}
		float get_pos_y() {				// y座標のゲッタ関数
			return pos_y;
		}
		float get_vec_x() {				// x方向のゲッタ関数
			return vector_x;
		}
		float get_vec_y() {				// y方向のゲッタ関数
			return vector_y;
		}
		float get_velocity() {			// 速さのゲッタ関数
			return velocity;
		}
		bool get_Active() {				// アクティブ状態のゲッタ関数
			if (this == nullptr) {
				return false;
			}
			return isActive;
		}
		float get_radius() {			// 半径のゲッタ関数
			return radius;
		}
		void update() {					// パラメータによって座標を更新します
			if (isActive) {
				float d = 1;
				if (delay) {
					d = 0.5f;
				}
				pos_x = pos_x + vector_x * velocity * d;
				pos_y = pos_y + vector_y * velocity * d;
			}
		}
		void set_delay(bool d) {		// 減速状態の設定を行うセッタ関数
			delay = d;
		}
		bool get_delay() {				// 減速状態かを返すゲッタ関数
			return delay;
		}
};