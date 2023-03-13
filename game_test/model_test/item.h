#pragma once
#include <string>
#include <iostream>

class item{
    /*
    ゲーム中で取得できるアイテムを管理します。
    アイテムを取得することでプレイヤーに特殊能力がついたり敵を弱体化させることができます。
    */
private:
    int itemid;                 // アイテムを管理するためのIDです
    std::string item_name;      // アイテムの名前です
    std::string item_text;      // アイテムの説明文です
    bool active;                // アイテムが有効化されているかを管理します
    bool used;                  // 一度しか効果が適用されないアイテムについて適用しているかを管理します
    int rarity;                 // アイテムのレア度を表します。主に入手するタイミングや店売りの値段を設定するために使用します 0->コモン , 1->レア , 2->エピック , 3->レジェンダリー
public:
    int COMMON = 0;
    int RARE = 1;
    int EPIC = 2;
    int LEGEND = 3;
    item();
    item(int);                 // コンストラクタ、idを引数として取得し、その他パラメータを初期化します
    ~item();                   // デストラクタ
    int get_id();              // IDのゲッタ関数です
    std::string get_name();    // アイテム名のゲッタ関数です
    std::string get_text();    // アイテムの説明文のゲッタ関数です
    bool isActive();           // アイテムが有効化されているかを取得します
    bool get_used();           // アイテムが使用済みかを取得します
    int get_rarity();          // アイテムのレア度のゲッタ関数です
    void set_active(bool);     // アイテムを有効化する際に使用します
    void set_used(bool);       // 使用済みに変更したり再使用を可能にしたり(一部アイテムのみ)します
    void test_item();          // デバッグ用関数、各種パラメータを確認します
};
