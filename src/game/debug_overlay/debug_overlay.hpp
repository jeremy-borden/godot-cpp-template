#pragma once

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/font.hpp"

using namespace godot;

class DebugOverlay : public Control {
	GDCLASS(DebugOverlay, Control)

	int64_t _fps = -1;
	double _cpu_frame_ms = 0.0;
	Ref<Font> _font;

protected:
	/** @brief Registers the debug overlay class with Godot. */
	static void _bind_methods();

public:
	/** @brief Initializes the overlay and caches its fallback font. */
	void _ready() override;

	/** @brief Refreshes performance values when the update timer fires. */
	void _update_metrics();

	/** @brief Draws the cached FPS value as 2D text. */
	void _draw() override;
};
