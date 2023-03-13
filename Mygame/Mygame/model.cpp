#include "model.h"
#include "view.h"
#include "chara.h"
#include "enemy.h"
#include "enemylist.h"
#include "bullet.h"
#include "bulletlist.h"
#include "map.h"
#include "area.h"
#include "item.h"
#include "itemlist.h"
#include "mapnode.h"

Model::Model() {
	chara = new Chara(this);
	enemy_list = new EnemyList(this);
	boss_enemy = new Enemy(this);
	bullet_list = new BulletList(this);
	for(int i = 0; i < 50; i++) {
		bullet_list->get_bullet(i)->set_chara(chara);
	}
	enemy_bullet_list = new BulletList(this);
	i_list = new itemlist();
	mapdata = new GameMapdata(4, 1);
	stage = new area(this, mapdata->get_current_node()->get_event());
	map_num = 1;
	deapth = 0;
	titlepointer = 0;
	mappointer = 1;
}
Model::~Model() {
	if (chara != nullptr) {
		delete chara;
	}
	if (mapdata != nullptr) {
		delete mapdata;
	}
}
void Model::setView(View* v) {
	view = v;
}
void Model::settext(std::string t) {
	text = text + t;
}
std::string Model::gettext() {
	return text;
}
void Model::setscene(int i) {
	int pre_scene = scene;
	std::cout << "scene change" << std::endl;
	scene = i;
}
int Model::getscene() {
	return scene;
}
void Model::resettext() {
	text = "";
}
int Model::get_title_p(){
	if (titlepointer < 0) {
		return -1 * titlepointer % 2;
	}
	return titlepointer % 2;
}
int Model::get_map_p() {
	return mappointer;
}
void Model::change_titlep(int c){
	if (c == 0) {
		titlepointer = titlepointer + 1;
	}
	if (c == 1) {
		titlepointer = titlepointer - 1;;
	}
}
void Model::update() {
	if (scene == MAP) {
		
	}
	if (scene == SHOOTING) {
		chara->update();
		chara->update(enemy_bullet_list);
		chara->update(enemy_list);
		chara->update(boss_enemy);
		bullet_list->update(gametimer);
		enemy_bullet_list->update(gametimer);
		enemy_list->update(bullet_list);
		boss_enemy->update(bullet_list);
		frame++;

		if(frame%60==0){
			chara->set_d_timer(gametimer + 1);
			gametimer++;
			frame = 0;
		}

		stage->game_event(gametimer, frame);
		//stage_clear();
	}
}
void Model::stage_clear() {
	gametimer = 0;
	frame = 0;
	deapth++;
	if (deapth == 4) {
		deapth = 0;
		chara->reset_status();
		mapdata->~GameMapdata();
		mapdata = new GameMapdata(4, 1);
		stage->~area();
		stage = new area(this, mapdata->get_current_node()->get_event());
		setscene(TITLE);
	}
	else {
		setscene(MAP);
	}
}
Chara* Model::get_chara(){
	return chara;
}
EnemyList* Model::get_enemy_list(){
	return enemy_list;
}
Enemy* Model::get_boss_enemy(){
	return boss_enemy;
}
BulletList* Model::get_bullet_list(){
	return bullet_list;
}
BulletList* Model::get_enemy_bullet_list() {
	return enemy_bullet_list;
}
GameMapdata* Model::get_map() {
	return mapdata;
}
area* Model::get_stage() {
	return stage;
}
itemlist* Model::get_itemlist() {
	return i_list;
}
int Model::get_timer() {
	return gametimer;//シューティングゲーム中に経った時間(秒)を返す
}
void Model::v2mtext(std::string str) {
	settext(str);
	m2vtext();
}
void Model::m2vtext() {
	view->settext(gettext());
}
void Model::setSignal(int signal) {
	if (signal == 0x0000) {
		//spaceキーのシグナル
		v2mtext(" ");
	}
	if (signal == 0x0001) {
		//enterキーのシグナル
		v2mtext("enter");
		if ((getscene() == TITLE) && (get_title_p() == 0)) {
			setscene(SHOOTING);
		}
		else if ((getscene() == TITLE) && (get_title_p() == 1)) {
			//setscene(SCORE);
		}
		else if ((getscene() == MAP) && (mappointer == 0) && (mapdata->get_current_node()->get_left_node()!=nullptr)) {
			mapdata->node_change(1);
			stage->~area();
			stage = new area(this, mapdata->get_current_node()->get_event());
			setscene(SHOOTING);
		}
		else if ((getscene() == MAP) && (mappointer == 1) && (mapdata->get_current_node()->get_middle_node() != nullptr)) {
			mapdata->node_change(2);
			stage->~area();
			stage = new area(this, mapdata->get_current_node()->get_event());
			setscene(SHOOTING);
		}
		else if ((getscene() == MAP) && (mappointer == 2) && (mapdata->get_current_node()->get_right_node() != nullptr)) {
			mapdata->node_change(3);
			stage->~area();
			stage = new area(this, mapdata->get_current_node()->get_event());
			setscene(SHOOTING);
		}if (getscene() == SHOOTING) {
			if (stage->get_area_scene() == 2) {
				//文字送り状態の分岐を書く場所
				if (stage->get_event_id() == 17 && stage->get_phase() == 0) {
					stage->set_phase(1);
					stage->set_scene(3);
				}
				else if ((stage->get_event_id() == 15) && (stage->get_phase() == 0)) {
					stage->set_phase(1);
				}
				else if ((stage->get_event_id() == 15) && (stage->get_phase() == 1)) {
					chara->set_health(chara->get_health() + 1);
					stage->set_scene(5);
				}
				else if ((stage->get_event_id() == 18) && (stage->get_phase() == 0)) {
					stage->set_phase(1);
				}
				else if ((stage->get_event_id() == 18) && (stage->get_phase() == 1)) {
					chara->set_bomb(chara->get_bomb() + 1);
					stage->set_scene(5);
				}
				else if ((stage->get_event_id() == 19) && (stage->get_phase() == 0)) {
					stage->set_phase(1);
				}
				else if ((stage->get_event_id() == 19) && (stage->get_phase() == 1)) {
					chara->set_bomb(chara->get_bomb() + 3);
					stage->set_scene(5);
				}
				else if ((stage->get_event_id() == 14) && (stage->get_phase() == 1)) {
					chara->set_health(chara->get_health() + 1);
					chara->set_bomb(0);
					stage->set_scene(5);
				}
				else if ((stage->get_event_id() == 14) && (stage->get_phase() == 2)) {
					stage->set_scene(5);
				}
				else if ((stage->get_event_id() == 16) && (stage->get_phase() == 1)) {
					chara->set_health(chara->get_health() - 1);
					for (int i = 0; i < 100;i++) {
						chara->add_exp();
					}
					stage->set_scene(5);
				}
				else if ((stage->get_event_id() == 16) && (stage->get_phase() == 2)) {
					stage->set_scene(5);
				}
			}
			if (stage->get_area_scene() == 3) {
				//6択の分岐について書く
				if ((stage->get_event_id() == 17) && (stage->get_phase() == 1)) {
					if ((stage->get_pointer_6(0) < 4) && (0 < stage->get_pointer_6(0))) {
						int i = i_list->get_item(stage->get_prize_id())->get_rarity() * 16 * i_list->get_boost(i_list->DISCOUNT) / 100;
						if (chara->get_tip() >= i) {
							chara->sub_tip(i);
							i_list->get_item(stage->get_prize_id())->set_active(true);
							stage->set_scene(5);
						}
						
					}
					else if (stage->get_pointer_6(0) == 4) {
						int i = 4 * i_list->get_boost(i_list->DISCOUNT) / 100;
						if (chara->get_tip() >= i) {
							chara->sub_tip(i);
							chara->set_bomb(chara->get_bomb() + 1);
							stage->set_scene(5);
						}
					}
					else if (stage->get_pointer_6(0) == 5) {
						stage->set_scene(5);
					}
				}
			}
			if (stage->get_area_scene() == 4) {
				//2択分岐について書く
				if ((stage->get_event_id() == 14) && (stage->get_phase() == 0)) {
					if (stage->get_pointer_2(0) == 0) {
						stage->set_phase(1);
						stage->set_scene(2);
					}
					else {
						stage->set_phase(2);
						stage->set_scene(2);
					}
				}
				else if ((stage->get_event_id() == 16) && (stage->get_phase() == 0)) {
					if (stage->get_pointer_2(0) == 0) {
						stage->set_phase(1);
						stage->set_scene(2);
					}
					else {
						stage->set_phase(2);
						stage->set_scene(2);
					}
				}
			}
		}
		else if ((getscene() == SCORE)) {
			setscene(TITLE);
		}
		else if ((getscene() == PAUSE)) {
			setscene(SHOOTING);
		}
		resettext();
		m2vtext();
	}
	if (signal == 0x0002) {
		//escキーのシグナル
		if (getscene() == SHOOTING) {
			setscene(PAUSE);
		}
		v2mtext("esc");
	}
	if (signal == 0x0003) {
		//leftキーのシグナル
		if (getscene() == TITLE) {
		}
		if (getscene() == MAP) {
			mappointer--;
			if (mappointer < 0) {
				mappointer = mappointer + 3;
			}
		}
		if (getscene() == SHOOTING) {
			float v = get_chara()->get_vec_x();
			if (v > 0) {
				v = 0;
			}
			v = v - 0.5f;
			if (v > -1.5f) {
				get_chara()->set_vec_x(v);
			}
			if (stage->get_area_scene() == 3) {
				stage->get_pointer_6(2);
			}
			if (stage->get_area_scene() == 4) {
				stage->get_pointer_2(1);
			}
		}
		v2mtext("left");
	}
	if (signal == 0x0004) {
		//upキーのシグナル
		if (getscene() == TITLE) {
			change_titlep(1);
		}
		if (getscene() == SHOOTING) {
			float v = get_chara()->get_vec_y();
			if (v > 0) {
				v = 0;
			}
			v = v -0.5f;
			if (v > -1.5f) {
				get_chara()->set_vec_y(v);
			}
		}
		v2mtext("up");
	}
	if (signal == 0x0005) {
		//rightキーのシグナル
		if (getscene() == TITLE) {
		}
		if (getscene() == MAP) {
			mappointer++;
			if (mappointer > 2) {
				mappointer = mappointer - 3;
			}
		}
		if (getscene() == SHOOTING) {
			float v = get_chara()->get_vec_x();
			if (v < 0) {
				v = 0;
			}
			v = v +0.5f;
			if (v < 1.5f) {
				get_chara()->set_vec_x(v);
			}
			if (stage->get_area_scene() == 3) {
				stage->get_pointer_6(1);
			}
			if (stage->get_area_scene() == 4) {
				stage->get_pointer_2(1);
			}
		}
		v2mtext("right");
	}
	if (signal == 0x0006) {
		//downキーのシグナル
		if (getscene() == TITLE) {
			change_titlep(0);
		}
		if (getscene() == SHOOTING) {
			if (getscene() == SHOOTING) {
				float v = get_chara()->get_vec_y();
				if (v < 0) {
					v = 0;
				}
				v = v + 0.5f;
				if (v < 1.5f) {
					get_chara()->set_vec_y(v);
				}
			}
		}
		v2mtext("down");
	}
	if (signal == 0x0007) {
		//aキーのシグナル
		v2mtext("a");
	}
	if (signal == 0x0008) {
		//bキーのシグナル
		v2mtext("b");
	}
	if (signal == 0x0009) {
		//cキーのシグナル
		v2mtext("c");
	}
	if (signal == 0x000A) {
		//dキーのシグナル
		v2mtext("d");
	}
	if (signal == 0x000B) {
		//eキーのシグナル
		v2mtext("e");
	}
	if (signal == 0x000C) {
		//fキーのシグナル
		v2mtext("f");
	}
	if (signal == 0x000D) {
		//gキーのシグナル
		v2mtext("g");
	}
	if (signal == 0x000E) {
		//hキーのシグナル
		v2mtext("h");
	}
	if (signal == 0x000F) {
		//iキーのシグナル
		v2mtext("i");
	}
	if (signal == 0x0010) {
		//jキーのシグナル
		v2mtext("j");
	}
	if (signal == 0x0011) {
		//kキーのシグナル
		v2mtext("k");
	}
	if (signal == 0x0012) {
		//lキーのシグナル
		v2mtext("l");
	}
	if (signal == 0x0013) {
		//mキーのシグナル
		v2mtext("m");
	}
	if (signal == 0x0014) {
		//nキーのシグナル
		v2mtext("n");
	}
	if (signal == 0x0015) {
		//oキーのシグナル
		v2mtext("o");
	}
	if (signal == 0x0016) {
		//pキーのシグナル
		v2mtext("p");
	}
	if (signal == 0x0017) {
		//qキーのシグナル
		v2mtext("q");
	}
	if (signal == 0x0018) {
		//rキーのシグナル
		v2mtext("r");
	}
	if (signal == 0x0019) {
		//sキーのシグナル
		v2mtext("s");
	}
	if (signal == 0x001A) {
		//tキーのシグナル
		v2mtext("t");
	}
	if (signal == 0x001B) {
		//uキーのシグナル
		v2mtext("u");
	}
	if (signal == 0x001C) {
		//vキーのシグナル
		v2mtext("v");
	}
	if (signal == 0x001D) {
		//wキーのシグナル
		v2mtext("w");
	}
	if (signal == 0x001E) {
		//xキーのシグナル
		v2mtext("x");
		if ((getscene() == SHOOTING)) {
			// ボムを発動
			if (chara->get_bomb() > 0 || true) {
				enemy_bullet_list->reset_bullets();
			}
		}
	}
	if (signal == 0x001F) {
		//yキーのシグナル
		v2mtext("y");
	}
	if (signal == 0x0020) {
		//zキーのシグナル
		v2mtext("z");
		if ((getscene() == SHOOTING)&&((stage->get_area_scene()==0) || (stage->get_area_scene() == 1))) {
			// 弾を発射
			if (chara->get_d_timer() <= gametimer) {
				Bullet* b = bullet_list->get_useful();
				if (b != nullptr) {
					b->shot(chara->get_pos_x(), chara->get_pos_y(), 0, -10, 1, 0,gametimer, -1);
					chara->set_d_timer(gametimer + 1);
				}
			}
		}
		else if ((getscene() == SCORE)) {
			setscene(TITLE);
		}
	}
	if (signal == down_SHIFT) {
		chara->set_delay(true);
		v2mtext("シフト");
	}
	if (signal == 0xffff) {
		get_chara()->set_vec_x(0);
		get_chara()->set_vec_y(0);
	}
}
void Model::set_scene(int s) {
	scene = s;
}
int Model::get_deapth() {
	return deapth;
}
std::string Model::get_textbox() {
	return textbox;
}
std::string Model::get_textpeople() {
	return textpeople;
}
std::string Model::get_itemname() {
	return itemname;
}
std::string Model::get_itemtext() {
	return itemtext;
}
void Model::set_textbox(std::string s) {
	textbox = s;
}
void Model::set_textpeople(std::string s) {
	textpeople = s;
}
void Model::set_itemname(std::string s) {
	itemname = s;
}
void Model::set_itemtext(std::string s) {
	itemtext = s;
}
std::string Model::get_itemprice() {
	return itemprice;
}
void Model::set_itemprice(std::string s) {
	itemprice = s;
}