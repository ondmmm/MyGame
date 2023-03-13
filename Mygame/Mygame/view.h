#pragma once
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>

class DirectXText;
class Controller;
class Model;
class View {
private:
	Model* model;
	std::string text;
	bool keymap[33];
public:
	View();
	~View();
	void setModel(Model*);
	void settext(std::string);
	std::string gettext();
	int getscene();
	Model* get_Model();
	void title_text(int, DirectXText);
	void awaitingInput(BYTE*);
};