#include "item.h"
item::item(){
    itemid = -1;
    item_name = "エラーアイテム";
    item_text = "表示されないはず";
    active = false;
    used = false;
    rarity = COMMON;
}
item::item(int id){
    if(id == 0){
        itemid = id;
        item_name = "浮き輪";
        item_text = "攻撃力+30%、残機+2、初期ボム数+2";
        active = false;
        used = false;
        rarity = COMMON;
    } else if(id == 1){
        itemid = id;
        item_name = "きれいな硬貨";
        item_text = "残機+1";
        active = false;
        used = false;
        rarity = COMMON;
    } else if(id == 2){
        itemid = id;
        item_name = "大きな根っこ";
        item_text = "残機+2";
        active = false;
        used = false;
        rarity = RARE;
    } else if(id == 3){
        itemid = id;
        item_name = "スッポンの抜け殻";
        item_text = "残機+3";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 4){
        itemid = id;
        item_name = "謎の弾薬";
        item_text = "初期ボム数+1";
        active = false;
        used = false;
        rarity = COMMON;
    } else if(id == 5){
        itemid = id;
        item_name = "予備電池";
        item_text = "初期ボム数+2";
        active = false;
        used = false;
        rarity = RARE;
    } else if(id == 6){
        itemid = id;
        item_name = "魔力増幅器";
        item_text = "初期ボム数+3";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 7){
        itemid = id;
        item_name = "一度しか表示されないらしい商品";
        item_text = "自機の当たり判定75%(より小さい値を参照)";
        active = false;
        used = false;
        rarity = RARE;
    } else if(id == 8){
        itemid = id;
        item_name = "着やせスーツ";
        item_text = "自機の当たり判定50%(より小さい値を参照)";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 9){
        itemid = id;
        item_name = "名の知れた刀";
        item_text = "自機の攻撃力+10%";
        active = false;
        used = false;
        rarity = COMMON;
    } else if(id == 10){
        itemid = id;
        item_name = "魔法の杖";
        item_text = "自機の攻撃力+20%";
        active = false;
        used = false;
        rarity = RARE;
    } else if(id == 11){
        itemid = id;
        item_name = "希望";
        item_text = "自機の攻撃力+35%";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 12){
        itemid = id;
        item_name = "紙とペン";
        item_text = "獲得経験値+1";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 13){
        itemid = id;
        item_name = "集中力";
        item_text = "獲得経験値+2";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 14){
        itemid = id;
        item_name = "友好の証";
        item_text = "商人からの購入費用-25%";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 15){
        itemid = id;
        item_name = "商人の黒歴史";
        item_text = "商人からの購入費用-50%";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 16){
        itemid = id;
        item_name = "変顔マスク";
        item_text = "敵体力-10%";
        active = false;
        used = false;
        rarity = RARE;
    } else if(id == 17){
        itemid = id;
        item_name = "恐怖のカタチ";
        item_text = "敵体力-25%";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 18){
        itemid = id;
        item_name = "富士の煙";
        item_text = "各戦闘で一度だけ被弾を無効にする";
        active = false;
        used = false;
        rarity = EPIC;
    } else if(id == 19){
        itemid = id;
        item_name = "ありがたいお言葉";
        item_text = "減速時攻撃力+85%";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 20){
        itemid = id;
        item_name = "智の代償";
        item_text = "移動速度+150%、最終スコア+50%";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 21){
        itemid = id;
        item_name = "自我付き爆弾";
        item_text = "敵をホーミングする弾が撃てるようになる";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 22){
        itemid = id;
        item_name = "強針";
        item_text = "直上に対して強力な弾が撃てるようになる";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 23){
        itemid = id;
        item_name = "魔法タレット";
        item_text = "減速移動開始時に向いていた方向に弾を撃つ分身を設置する";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 24){
        itemid = id;
        item_name = "叢雲ソード";
        item_text = "存続時間の短い強力な弾が撃てるようになる";
        active = false;
        used = false;
        rarity = LEGEND;
    } else if(id == 25){
        itemid = id;
        item_name = "再生式装甲";
        item_text = "一定時間ごとに敵の弾を無効化するシールドを獲得する";
        active = false;
        used = false;
        rarity = LEGEND;
    }else{
        itemid = -1;
        item_name = "エラーアイテム";
        item_text = "表示されないはず";
        active = false;
        used = false;
        rarity = COMMON;
    }
}

item::~item(){
    free(this);
}
int item::get_id(){
    return itemid;
}
std::string item::get_name(){
    return item_name;
}
std::string item::get_text(){
    return item_text;
}
bool item::isActive(){
    return active;
}
bool item::get_used(){
    return used;
}
int item::get_rarity(){
    return rarity;
}
void item::set_active(bool a){
    active = a;
}
void item::set_used(bool u){
    used = u;
}
void item::test_item(){
    std::string str = "";
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "id : " <<std::to_string(itemid)<< std::endl;
    std::cout << "name : " <<item_name<< std::endl;
    std::cout << "text : " <<item_text<< std::endl;
    if(used){
        str = "true";
    }else{
        str = "false";
    }
    std::cout << "used : "<<str << std::endl;
    if(active){
        str = "true";
    }else{
        str = "false";
    }
    std::cout << "active : " <<str<< std::endl;
    std::cout << "rarity : " <<std::to_string(rarity)<< std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}