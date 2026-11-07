#include "main/tracker_game.hpp"

#include "game/debug_overlay/debug_overlay.hpp"
#include "godot_cpp/classes/canvas_layer.hpp"
#include "godot_cpp/classes/display_server.hpp"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/window.hpp"

void TrackerGame::_bind_methods() {}

void TrackerGame::_ready() {
	Engine::get_singleton()->set_max_fps(500);

	Window *window = get_window();
	DisplayServer::get_singleton()->window_set_vsync_mode(DisplayServer::VSYNC_DISABLED, window->get_window_id());
	window->set_flag(Window::FLAG_ALWAYS_ON_TOP, true);
	window->grab_focus();

	auto *overlay_layer = memnew(CanvasLayer);
	add_child(overlay_layer);
	overlay_layer->add_child(memnew(DebugOverlay));
}
