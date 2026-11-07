#pragma once

#include "godot_cpp/classes/node.hpp"

using namespace godot;

class TrackerGame : public Node {
	GDCLASS(TrackerGame, Node)

protected:
	/** @brief Registers the TrackerGame class with Godot. */
	static void _bind_methods();

public:
	/** @brief Configures the game window and starts the debug overlay. */
	void _ready() override;
};
