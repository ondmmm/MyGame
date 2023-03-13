#include "controller.h"

void Controller::v2mtext(std::string str) {
	model->settext(str);
	m2vtext();
}
void Controller::m2vtext() {
	view->settext(model->gettext());
}
void Controller::setSignal(int signal) {
	if (signal == 0x0000) {
		//spaceキーのシグナル
		v2mtext(" ");
	}
	if (signal == 0x0001) {
		//enterキーのシグナル
		v2mtext("enter");
		if ((model->getscene() == model->TITLE) && (model->get_titlep()==0)) {
			model->setscene(model->GAME);
		} else if ((model->getscene() == model->TITLE) && (model->get_titlep() == 1)) {
			//model->setscene(model->SCORE);
		} else if ((model->getscene() == model->GAME) ) {
			model->setscene(model->SHOOTING);
		}
		model->resettext();
		m2vtext();
	}
	if (signal == 0x0002) {
		//escキーのシグナル
		if (model->getscene() == model->SHOOTING) {
			model->setscene(model->GAME);
		}
		v2mtext("esc");
	}
	if (signal == 0x0003) {
		//leftキーのシグナル
		if (model->getscene() == model->TITLE) {
		}
		if (model->getscene() == model->SHOOTING) {
			model->get_chara()->set_vec_x(-1.0f);
			model->get_chara()->update();
			model->get_chara()->set_vec_x(model->get_chara()->get_vec_x() +1.0f);
		}
		v2mtext("left");
	}
	if (signal == 0x0004) {
		//upキーのシグナル
		if (model->getscene() == model->TITLE) {
			model->change_titlep(1);
		}
		if (model->getscene() == model->SHOOTING) {
			model->get_chara()->set_vec_y(-1.0f);
			model->get_chara()->update();
			model->get_chara()->set_vec_y(model->get_chara()->get_vec_y() + 1.0f);
		}
		v2mtext("up");
	}
	if (signal == 0x0005) {
		//rightキーのシグナル
		if (model->getscene() == model->TITLE) {
		}
		if (model->getscene() == model->SHOOTING) {
			model->get_chara()->set_vec_x(1.0f);
			model->get_chara()->update();
			model->get_chara()->set_vec_x(model->get_chara()->get_vec_x() - 1.0f);
		}
		v2mtext("right");
	}
	if (signal == 0x0006) {
		//downキーのシグナル
		if (model->getscene() == model->TITLE) {
			model->change_titlep(0);
		}
		if (model->getscene() == model->SHOOTING) {
			model->get_chara()->set_vec_y(1.0f);
			model->get_chara()->update();
			model->get_chara()->set_vec_y(model->get_chara()->get_vec_y() - 1.0f);
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
	}
	if (signal == 0x001F) {
		//yキーのシグナル
		v2mtext("y");
	}
	if (signal == 0x0020) {
		//zキーのシグナル
		v2mtext("z");
	}
}
void Controller::setView(View* v) {
	view = v;
}
void Controller::setModel(Model* m) {
	model = m;
}