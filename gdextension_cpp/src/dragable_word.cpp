#include "dragable_word.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void DragableWord::_bind_methods(){
}
void DragableWord::_register_methods(){
    register_property<DragableWord, double> ("speed", &DragableWord::speed, 0);
}

DragableWord::DragableWord(){

}


DragableWord::~DragableWord(){
}


void DragableWord::_process(double delta){
    Vector2 new_position = get_position() + Vector2(0,speed);
    set_position(new_position);
}