#include "main/tracker_game.hpp"

#include "godot_cpp/classes/window.hpp"

void TrackerGame::_bind_methods() {}

void TrackerGame::_ready() {
	Window *window = get_window();
	window->set_flag(Window::FLAG_ALWAYS_ON_TOP, true);
	window->grab_focus();
}
