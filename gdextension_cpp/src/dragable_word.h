#ifndef DRAGABLE_WORD_H
#define DRAGABLE_WORD_H

#include <godot_cpp/classes/button.hpp>

namespace godot {

class DragableWord : public Button {
	GDCLASS(DragableWord, Button)

private:
	double speed;

protected:
	static void _bind_methods();

public:
    DragableWord();

    ~DragableWord();

    PROPERTY(double, speed)
	void _process(double delta) override;
};

}

#endif