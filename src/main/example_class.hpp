#pragma once

#include "godot_cpp/classes/node.hpp"

using namespace godot;

class ExampleClass : public Node {
	GDCLASS(ExampleClass, Node)

protected:
	static void _bind_methods();

public:
	void _ready() override;
};
