#include "main/example_class.hpp"

#include "godot_cpp/classes/window.hpp"

void ExampleClass::_bind_methods() {}

void ExampleClass::_ready() {
	Window *window = get_window();
	window->set_flag(Window::FLAG_ALWAYS_ON_TOP, true);
	window->grab_focus();
	print_line(vformat("Type: %d", Variant(this).get_type()));
}
