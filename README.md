# godot-cpp template
This repository is a SCons-based Godot GDExtension project for Godot 4.7+.

## Contents
* C++ GDExtension source files in [src/](./src/)
* A Godot project in [project/](./project) with a C++ main-scene node
* godot-cpp as a submodule (`godot-cpp/`)
* SCons build configuration in [SConstruct](./SConstruct)

## Usage - Template

To use this template, log in to GitHub and click the green "Use this template" button at the top of the repository page. This will let you create a copy of this repository with a clean git history.

To get started with your new GDExtension, do the following:

* clone your repository to your local computer
* initialize the godot-cpp git submodule via `git submodule update --init --recursive`
* if you rename the extension, keep the `libname` in [SConstruct](./SConstruct), the paths in [tracker.gdextension](./project/bin/tracker.gdextension), and the entry symbol in [register_types.cpp](./src/register_types.cpp) in sync

Now, you can build the project with the following command:

```shell
scons
```

If the build command worked, open the [project](./project) in Godot and launch the main scene. The scene root is the registered C++ `ExampleClass` node, so the example does not need GDScript. It prints the following line in the Godot output:

```
Type: 24
```

### Configuring an IDE
You can develop your own extension with any text editor and by invoking scons on the command line, but if you want to work with an IDE (Integrated Development Environment), you can use a compilation database file called `compile_commands.json`. Most IDEs should automatically identify this file, and self-configure appropriately.
To generate the database file, you can run one of the following commands in the project root directory:
```shell
# Generate compile_commands.json while compiling
scons compiledb=yes

# Generate compile_commands.json without compiling
scons compiledb=yes compile_commands.json
```

### Running the Godot project from VS Code

Open the repository root in VS Code so both `src/` and `project/` are available. The **Run Godot game** configuration in Run and Debug (and **F5**) first runs **Build GDExtension (SCons)**, then launches the nested Godot project. You can also run the build manually with **Terminal > Run Task > Build GDExtension (SCons)**. Choose **Open Godot project in editor** to open the editor, or **Run Godot project** to launch the game directly. These two tasks start Godot separately, so they finish immediately and can be run again without a task-termination prompt. To print the example output in the VS Code task terminal, choose **Check example output (headless)**. All Godot tasks use the executable configured in `godotTools.editorPath.godot4`.

## Usage - Actions

This repository comes with continuous integration (CI) through a GitHub action that tests building the GDExtension.
It triggers automatically for each pushed change. You can find and edit it in [ci.yml](.github/workflows/ci.yml).

There is also a workflow ([make_build.yml](.github/workflows/make_build.yml)) that builds the GDExtension for all supported platforms that you can use to create releases.
You can trigger this workflow manually from the `Actions` tab on GitHub.
After it is complete, you can find the file `godot-cpp-template.zip` in the `Artifacts` section of the workflow run.
