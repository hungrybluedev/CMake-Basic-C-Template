# Template for CMake based C Projects

[![LGTM Grade](https://img.shields.io/lgtm/grade/cpp/github/hungrybluedev/CMake-Basic-C-Template)](https://lgtm.com/projects/g/hungrybluedev/CMake-Basic-C-Template/context:cpp)
[![LGTM Alerts](https://img.shields.io/lgtm/alerts/github/hungrybluedev/CMake-Basic-C-Template)](https://lgtm.com/projects/g/hungrybluedev/CMake-Basic-C-Template/alerts/)
[![GitHub](https://img.shields.io/github/license/hungrybluedev/CMake-Basic-C-Template)](LICENSE)
[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/hungrybluedev/CMake-Basic-C-Template/Cross-platform%20CMake%20Builds?label=Cross-platform%20build)](https://github.com/hungrybluedev/CMake-Basic-C-Template/actions)

## Why?

I wanted to use CMake as my default build system. However, the tutorials are mostly outdated and people share non-standard solutions online. I made this repository to avoid duplication of work and also to make use of the recommended guidelines wherever I could find them.

## Read The CMakeLists.txt File

This file is meant to be read by humans. Developers must put effort into it so that it can serve as the documentation itself.

## Commands

To generate the build files:

```bash
/path/to/src $ cmake -G"Unix Makefiles" -S . -B build
```

This generates _Unix Makefiles_ for the src (`.`) in the build directory (`build`).

- Type `cmake --help` for a list of available generators.
- (Suggestion) Change `-B build` to `-B release` for release.

To start the build:

```bash
/path/to/src $ cmake --build build
```

Note that we do not need to move into the `build` folder.

To build a release version:

```bash
/path/to/src $ cmake --build release --config Release
```

Check [this link](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html) for more information of the different configurations available.

## Reference

Almost all the material is derived from [An Introduction to Modern CMake](https://gitlab.com/CLIUtils/modern-cmake) by Henry Schreiner and others. Other sources will be mentioned as they pop up.
