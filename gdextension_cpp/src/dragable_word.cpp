#include "dragable_word.h"
#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void DragableWord::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_speed"),&DragableWord::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed"),&DragableWord::set_speed);
    ClassDB::bind_method(D_METHOD("_on_pressed"),&DragableWord::_on_pressed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
    

}


DragableWord::DragableWord(){
    this->connect("button_down",Callable(this,"_on_pressed"));
    selected= false;
}


DragableWord::~DragableWord(){
}


void DragableWord::_process(double delta){
    Vector2 new_position = get_position() + Vector2(0,speed);
    set_position(new_position);

    printf(selected?"true" :"false");
}

void DragableWord::set_speed(const double new_speed){
    speed = new_speed;
}

double DragableWord::get_speed() const{
    return speed;
}

void DragableWord::_on_pressed(){
    selected=true;
}