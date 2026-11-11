<img width="1600" height="520" alt="azoth-banner" src="https://github.com/user-attachments/assets/02820438-47a5-4be0-8b14-ab117b6596ae" />


# Azoth

**Azoth** is an experimental build system with a simple goal: make native builds explicit, predictable, and pleasant to work with.

The idea is to describe your project in **TOML**, keep dependencies and compiler flags visible, and let Azoth handle the build without unnecessary magic.

> **Status:** Early prototype. The CLI currently selects a manifest path (`-f`, defaulting to `build.toml`). TOML parsing and actual builds are not implemented yet.

## Design goals

- **TOML-first:** One readable manifest for your project.
- **Explicit by design:** Dependencies, paths, and flags should be easy to see and understand.
- **Good developer experience:** Clear diagnostics and straightforward commands.
- **Native platforms:** macOS and Linux are the initial targets.

## Try the prototype

You'll need a C++23-capable `clang++` with support for `<print>`.

```sh
make run
```

Or compile and run the CLI directly:

```sh
clang++ -std=c++23 -pedantic main.cpp -o azoth
./azoth -f build.toml
```

At this stage, the CLI only prints the selected manifest path.

## What's next?

- [ ] Parse and validate `build.toml`
- [ ] Model build targets and dependencies
- [ ] Compile and link a simple native project
- [ ] Introduce useful errors and build diagnostics

---

*From source to substance.*

