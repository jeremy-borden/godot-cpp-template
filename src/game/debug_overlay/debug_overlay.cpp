#include "game/debug_overlay/debug_overlay.hpp"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/performance.hpp"
#include "godot_cpp/classes/theme_db.hpp"
#include "godot_cpp/classes/timer.hpp"
#include "godot_cpp/variant/callable_method_pointer.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void DebugOverlay::_bind_methods() {}

void DebugOverlay::_ready() {
	set_anchors_and_offsets_preset(Control::PRESET_FULL_RECT);
	set_mouse_filter(Control::MOUSE_FILTER_IGNORE);
	_font = ThemeDB::get_singleton()->get_fallback_font();
	_fps = static_cast<int64_t>(Engine::get_singleton()->get_frames_per_second());
	queue_redraw();

	// Godot exposes FPS as a sampled value, not a change signal.
	auto *timer = memnew(Timer);
	timer->set_wait_time(1.0);
	timer->set_one_shot(false);
	if (timer->connect("timeout", callable_mp(this, &DebugOverlay::_update_metrics)) != OK) {
		memdelete(timer);
		UtilityFunctions::push_error("Failed to connect the debug overlay FPS timer.");
		return;
	}
	add_child(timer);
	timer->start();
}

void DebugOverlay::_update_metrics() {
	const Performance *performance = Performance::get_singleton();
	const int64_t fps = static_cast<int64_t>(performance->get_monitor(Performance::TIME_FPS));
	if (fps != _fps) {
		_fps = fps;
		queue_redraw();
	}
}

void DebugOverlay::_draw() {
	// CanvasItem draws text in viewport coordinates and redraws only when requested.
	const String metrics = String("FPS: ") + String::num_int64(_fps);
	draw_string(_font, Vector2(12, 24), metrics, HORIZONTAL_ALIGNMENT_LEFT, -1.0, 18, Color(1, 1, 1));
}
