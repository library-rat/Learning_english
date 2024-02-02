#include "dragable_word.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>


using namespace godot;

void DragableWord::_bind_methods(){
    ClassDB::bind_method(D_METHOD("get_speed"),&DragableWord::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed"),&DragableWord::set_speed);
    ClassDB::bind_method(D_METHOD("_on_button_up"),&DragableWord::_on_button_up);

    ClassDB::bind_method(D_METHOD("_on_button_down"),&DragableWord::_on_button_down);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
    

}


DragableWord::DragableWord(){
    this->connect("button_down",Callable(this,"_on_button_down"));
    this->connect("button_up", Callable(this,"_on_button_up"));
    selected= false;
}


DragableWord::~DragableWord(){
}


void DragableWord::_process(double delta){
    if (!Engine::get_singleton()->is_editor_hint()){
        if (selected){
            set_position(get_global_mouse_position()-this->get_size()/2);
        }
        Vector2 new_position = get_position() + Vector2(0,speed);
        set_position(new_position);
    }
}

void DragableWord::set_speed(const double new_speed){
    speed = new_speed;
}

double DragableWord::get_speed() const{
    return speed;
}

void DragableWord::_on_button_up(){
    selected=true;
}

void DragableWord::_on_button_down(){
    selected=false;
}