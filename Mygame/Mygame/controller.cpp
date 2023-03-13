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
		//space�L�[�̃V�O�i��
		v2mtext(" ");
	}
	if (signal == 0x0001) {
		//enter�L�[�̃V�O�i��
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
		//esc�L�[�̃V�O�i��
		if (model->getscene() == model->SHOOTING) {
			model->setscene(model->GAME);
		}
		v2mtext("esc");
	}
	if (signal == 0x0003) {
		//left�L�[�̃V�O�i��
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
		//up�L�[�̃V�O�i��
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
		//right�L�[�̃V�O�i��
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
		//down�L�[�̃V�O�i��
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
		//a�L�[�̃V�O�i��
		v2mtext("a");
	}
	if (signal == 0x0008) {
		//b�L�[�̃V�O�i��
		v2mtext("b");
	}
	if (signal == 0x0009) {
		//c�L�[�̃V�O�i��
		v2mtext("c");
	}
	if (signal == 0x000A) {
		//d�L�[�̃V�O�i��
		v2mtext("d");
	}
	if (signal == 0x000B) {
		//e�L�[�̃V�O�i��
		v2mtext("e");
	}
	if (signal == 0x000C) {
		//f�L�[�̃V�O�i��
		v2mtext("f");
	}
	if (signal == 0x000D) {
		//g�L�[�̃V�O�i��
		v2mtext("g");
	}
	if (signal == 0x000E) {
		//h�L�[�̃V�O�i��
		v2mtext("h");
	}
	if (signal == 0x000F) {
		//i�L�[�̃V�O�i��
		v2mtext("i");
	}
	if (signal == 0x0010) {
		//j�L�[�̃V�O�i��
		v2mtext("j");
	}
	if (signal == 0x0011) {
		//k�L�[�̃V�O�i��
		v2mtext("k");
	}
	if (signal == 0x0012) {
		//l�L�[�̃V�O�i��
		v2mtext("l");
	}
	if (signal == 0x0013) {
		//m�L�[�̃V�O�i��
		v2mtext("m");
	}
	if (signal == 0x0014) {
		//n�L�[�̃V�O�i��
		v2mtext("n");
	}
	if (signal == 0x0015) {
		//o�L�[�̃V�O�i��
		v2mtext("o");
	}
	if (signal == 0x0016) {
		//p�L�[�̃V�O�i��
		v2mtext("p");
	}
	if (signal == 0x0017) {
		//q�L�[�̃V�O�i��
		v2mtext("q");
	}
	if (signal == 0x0018) {
		//r�L�[�̃V�O�i��
		v2mtext("r");
	}
	if (signal == 0x0019) {
		//s�L�[�̃V�O�i��
		v2mtext("s");
	}
	if (signal == 0x001A) {
		//t�L�[�̃V�O�i��
		v2mtext("t");
	}
	if (signal == 0x001B) {
		//u�L�[�̃V�O�i��
		v2mtext("u");
	}
	if (signal == 0x001C) {
		//v�L�[�̃V�O�i��
		v2mtext("v");
	}
	if (signal == 0x001D) {
		//w�L�[�̃V�O�i��
		v2mtext("w");
	}
	if (signal == 0x001E) {
		//x�L�[�̃V�O�i��
		v2mtext("x");
	}
	if (signal == 0x001F) {
		//y�L�[�̃V�O�i��
		v2mtext("y");
	}
	if (signal == 0x0020) {
		//z�L�[�̃V�O�i��
		v2mtext("z");
	}
}
void Controller::setView(View* v) {
	view = v;
}
void Controller::setModel(Model* m) {
	model = m;
}