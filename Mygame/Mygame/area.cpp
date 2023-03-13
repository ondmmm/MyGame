#include "area.h"
#include "model.h"
#include "chara.h"
#include "enemy.h"
#include "enemylist.h"
#include "bullet.h"
#include "bulletlist.h"
#include "itemlist.h"
#include "item.h"
#include<math.h>
const double M_PI = 3.141592;
area::area(){
    event_id=-1;
    model=nullptr;
	_tcscpy_s(title, 256, "既定コンストラクタ");
    area_scene=-1;
    select_pointer_6 = 0;
    select_pointer_2 = 0;
	int phase = 0;
}
area::area(Model* m, int id){
    model = m;
    event_id =id;
    if(id == 10){
		_tcscpy_s(title, 256, "boss");
        //_tcscpy_s(title, 256, "1-boss");
    }else if(id == 11){
		_tcscpy_s(title, 256, "かき氷づくり");
    }else if(id == 12){
        _tcscpy_s(title, 256, "打ち上げ花火");
    }else if(id == 13){
        _tcscpy_s(title, 256, "波状攻撃");
    }else if(id == 14){
        _tcscpy_s(title, 256, "軽量化");
    }else if(id == 15){
        _tcscpy_s(title, 256, "掘り出し物？");
    }else if(id == 16){
        _tcscpy_s(title, 256, "命を背負って");
    }else if(id == 17){
        _tcscpy_s(title, 256, "旅商人");
    }else if(id == 18){
        _tcscpy_s(title, 256, "休憩ポイント");
    }else if(id == 19){
        _tcscpy_s(title, 256, "親切な人");
    }else if(id == 20){
        _tcscpy_s(title, 256, "2-boss");
    }else if(id == 21){
        _tcscpy_s(title, 256, "荒滝行");
    }else if(id == 22){
        _tcscpy_s(title, 256, "阿弥陀迷宮");
    }else if(id == 23){
        _tcscpy_s(title, 256, "挟撃");
    }else if(id == 24){
        _tcscpy_s(title, 256, "軽量化");
    }else if(id == 25){
        _tcscpy_s(title, 256, "掘り出し物？");
    }else if(id == 26){
        _tcscpy_s(title, 256, "投資活動");
    }else if(id == 27){
        _tcscpy_s(title, 256, "旅商人");
    }else if(id == 28){
        _tcscpy_s(title, 256, "休憩ポイント");
    }else if(id == 29){
        _tcscpy_s(title, 256, "下手な鉄砲も...");
    }else if(id == 30){
        _tcscpy_s(title, 256, "3-boss");
    }else if(id == 31){
        _tcscpy_s(title, 256, "満員電車");
    }else if(id == 32){
        _tcscpy_s(title, 256, "特攻部隊");
    }else if(id == 33){
        _tcscpy_s(title, 256, "とげとげ要塞");
    }else if(id == 34){
        _tcscpy_s(title, 256, "軽量化");
    }else if(id == 35){
        _tcscpy_s(title, 256, "起死回生...?");
    }else if(id == 36){
        _tcscpy_s(title, 256, "捨て去る覚悟");
    }else if(id == 37){
        _tcscpy_s(title, 256, "旅商人");
    }else if(id == 38){
        _tcscpy_s(title, 256, "休憩ポイント");
    }else if(id == 39){
        _tcscpy_s(title, 256, "虎穴に入らずんば...");
    }else {
        _tcscpy_s(title, 256, "想定外のidが指定されています");
    }
    area_scene = 0;
    select_pointer_6 = 0;
    select_pointer_2 = 0;
    timer_s = 0;
	timer_f = 0;
}
area::~area(){
    
}
void area::game_event(int t,int f){
	timer_s = t;
	timer_f = f;
    if(area_scene == 0){
        if((timer_s == 3)&&(timer_f == 0)){
			area_scene = 1;
			if ((event_id == 10)||(event_id == 11)||(event_id == 12)||(event_id == 13)) {
				area_scene = 1;
			}else if ((event_id == 14) || (event_id == 16)) {
				area_scene = 4;
			}else if ((event_id == 17) || (event_id == 15) || (event_id == 19) || (event_id == 18)){
				area_scene = 2;
			}
			else {
				area_scene = 5;
			}
			basetimer_s = t;
        }
    }else if(area_scene == 1){
		//シューティングゲームステージ情報を書く場所
		model->set_textbox("");
		model->set_itemname("");
		model->set_itemtext("");
		model->set_itemprice("");
		model->set_textpeople("");
		if (event_id == 10) {
			if (!(model->get_boss_enemy()->get_Active())) {
				model->get_boss_enemy()->spawn(0, 10, 1, model->WINDOW_WIDTH / 2, 200, 0, 0, 0);
			}
		}
		if (event_id == 11) {
			if (timer_s - basetimer_s >= 3) {
				area_scene = 5;
				basetimer_s = t;
			}
		}
		if (event_id == 12) {
			if (timer_s - basetimer_s >= 3) {
				area_scene = 5;
				basetimer_s = t;
			}
		}
		if (event_id == 13) {
			if (timer_s - basetimer_s >= 3) {
				area_scene = 5;
				basetimer_s = t;
			}
		}
		/*if (timer_s - basetimer_s >= 3) {
			area_scene = 5;
			basetimer_s = t;
		}*/
    }else if(area_scene == 2){
		//文字送り状態の分岐を書く場所
		if (event_id == 17 && phase == 0) {
			model->get_itemlist()->get_items_sale(saleitems);
			model->set_textbox("いらっしゃい");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("商人");
		}
		else if ((event_id == 15) && (phase == 0)) {
			model->set_textbox("ふと下を見るとそこには残機が!");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 15) && (phase == 1)) {
			model->set_textbox("残機を1獲得");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 18) && (phase == 0)) {
			model->set_textbox("少し休憩しよう");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 18) && (phase == 1)) {
			model->set_textbox("ボムを1獲得");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 19) && (phase == 0)) {
			model->set_textbox("あんたにプレゼントがあるんだ");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("見知らぬ人");
		}
		else if ((event_id == 19) && (phase == 1)) {
			model->set_textbox("ボムを3獲得");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if((event_id == 14) && (phase == 1)) {
			model->set_textbox("残機+1、残りボム数0");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 14) && (phase == 2)) {
			model->set_textbox("それを捨てるなんてとんでもない");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 16) && (phase == 1)) {
			model->set_textbox("経験値を100獲得、残機-1");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 16) && (phase == 2)) {
			model->set_textbox("命あってこその能力だ");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		basetimer_s = t;
    }
	else if (area_scene == 3) {
		//6択の分岐について書く
		if ((event_id == 17) &&( phase == 1)) {
			if ((select_pointer_6 < 4)&&(0 < select_pointer_6)) {
				model->set_textbox("それでいいのかい");
				model->set_itemname(model->get_itemlist()->get_item(saleitems[select_pointer_6])->get_name());
				model->set_itemtext(model->get_itemlist()->get_item(saleitems[select_pointer_6])->get_text());
				model->set_itemprice(std::to_string(model->get_itemlist()->get_item(saleitems[select_pointer_6])->get_rarity() * 16 * model->get_itemlist()->get_boost(model->get_itemlist()->DISCOUNT)/100));
				model->set_textpeople("商人");
			}
			else if (select_pointer_6 == 4) {
				model->set_textbox("それでいいのかい");
				model->set_itemname("ボム");
				model->set_itemtext("");
				model->set_itemprice(std::to_string(4 * model->get_itemlist()->get_boost(model->get_itemlist()->DISCOUNT) / 100));
				model->set_textpeople("商人");
			}
			else if (select_pointer_6 == 5) {
				model->set_textbox("それでいいのかい");
				model->set_itemname("立ち去る");
				model->set_itemtext("");
				model->set_itemprice("");
				model->set_textpeople("商人");
			}
		}
		basetimer_s = t;
	}
	else if (area_scene == 4) {
		//2択分岐について書く
		if ((event_id == 14) && (phase == 0)) {
			model->set_textbox("武装解除をすれば余裕を持てるかも");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}
		else if ((event_id == 16) && (phase == 0)) {
			model->set_textbox("寿命を削れば成長できるかも");
			model->set_itemname("");
			model->set_itemtext("");
			model->set_itemprice("");
			model->set_textpeople("");
		}		
		else {
			area_scene = 5;
			basetimer_s = t;
		}
		basetimer_s = t;

	}
	else if(area_scene == 5){
		//ステージが終わったときの余韻部分
		model->set_textbox("");
		model->set_itemname("");
		model->set_itemtext("");
		model->set_itemprice("");
		model->set_textpeople("");
        if(timer_s - basetimer_s >= 3){
            model->stage_clear();
        }
    }
}
int area::get_event_id(){
    return event_id;
}
TCHAR* area::get_title(){
    return title;
}
int area::get_area_scene(){
    return area_scene;
}
int area::get_pointer_6(int d){
    if(d == 0){
        return select_pointer_6;
    }
    if(d == 1){
        select_pointer_6 = select_pointer_6 + 1;
        if(select_pointer_6 > 5){
            select_pointer_6 = select_pointer_6 - 6;
        }
    }else if(d == 2){
		select_pointer_6 = select_pointer_6 - 1;
		if (select_pointer_6 < 0) {
			select_pointer_6 = select_pointer_6 + 6;
		}
    }else {
        select_pointer_6 = 0;
    }
    return select_pointer_6;
}
int area::get_pointer_2(int d){
    if(d == 0){
        return select_pointer_2;
    }
    if(select_pointer_2 == 0){
        select_pointer_2 = 1;
    }else if(select_pointer_2 == 1){
        select_pointer_2 = 0;
    }else{
        select_pointer_2 = 0;
    }
    return select_pointer_2;
}
int area::get_prize_id() {
	return saleitems[select_pointer_6];
}
void area::set_phase(int i) {
	phase = i;
}
int area::get_phase() {
	return phase;
}
void area::set_scene(int i) {
	area_scene = i;
}