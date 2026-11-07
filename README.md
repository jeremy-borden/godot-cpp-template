# Tracker Game

Tracker is a Godot game with its game logic written in C++ as a GDExtension. The Godot project is in [project/](./project), and its main scene uses the C++ `TrackerGame` node. No GDScript is required for the game code.

The main node starts the C++ debug overlay in `src/game/debug_overlay/`. It draws FPS and CPU frame-process time as 2D text, samples them via a 10 Hz timer, and redraws only when a displayed value changes. The game is capped at 500 FPS; GPU frame time is not exposed by the current OpenGL Compatibility renderer.

See [docs/game-design.md](./docs/game-design.md) for the rhythm-game architecture and performance direction.

## Build

Initialize the `godot-cpp` submodule once:

```shell
git submodule update --init --recursive
```

Build the extension from the repository root with SCons:

```shell
scons
```

Game object files are kept under `build/obj/` instead of alongside the source files.

## Run from VS Code

Open the repository root so both `src/` and `project/` are available. Choose **Run Tracker** in Run and Debug and press **F5**; it builds with SCons before launching the game. To open the editor, use **Terminal > Run Task > Open Godot project in editor**. To build manually, use **Terminal > Run Task > Build GDExtension (SCons)**.

The Godot executable path is configured by `godotTools.editorPath.godot4`.
