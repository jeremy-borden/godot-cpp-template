# Tracker Game Design

Tracker is a rhythm game. The Car is the player, but it does not need physics simulation.

## Gameplay and rendering

- Treat player input and rhythm timing as game data; update gameplay state from those inputs and let rendering present that state.
- Keep the Car's visual representation separate from physics bodies and collision processing unless gameplay later requires them.
- Base beat timing and input offsets on Godot's audio playback clock rather than render frames or physics ticks.
- Prefer simple, batched rendering for repeated visual elements; profile before adding custom rendering infrastructure.

## Performance

- Avoid enabling physics features or creating physics objects that the game does not use, but do not expect a large performance gain from disabling an otherwise idle physics server.
- Keep VSync and the 500 FPS cap as deliberate latency, smoothness, and power choices; measure input latency and frame pacing on target hardware.
- The debug overlay reports Godot's CPU frame-process time; direct GPU frame timing is not exposed by the current OpenGL Compatibility renderer.
- Use Godot's profiler to identify actual bottlenecks before disabling engine features or optimizing code.
