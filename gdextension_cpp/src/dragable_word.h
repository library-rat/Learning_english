#ifndef DRAGABLE_WORD_H
#define DRAGABLE_WORD_H

#include <godot_cpp/classes/button.hpp>

namespace godot {

class DragableWord : public Button {
	GDCLASS(DragableWord, Button)

private:
	double speed;
	bool selected;

protected:
	static void _bind_methods();

public:
    DragableWord();

    ~DragableWord();

	void _process(double delta) override;
	
	void set_speed(const double new_speed);

	double get_speed()const ;

	void _on_pressed();
};

}

#endif