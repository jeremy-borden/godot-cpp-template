#pragma once

#include "godot_cpp/classes/node.hpp"

using namespace godot;

class TrackerGame : public Node {
	GDCLASS(TrackerGame, Node)

protected:
	static void _bind_methods();

public:
	void _ready() override;
};
