# Template for CMake based C Projects

## Badges

| Description | Badges                                                                                                                                                                                                                                                                                                                                                      |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| LGTM        | [![LGTM Grade](https://img.shields.io/lgtm/grade/cpp/github/hungrybluedev/CMake-Basic-C-Template)](https://lgtm.com/projects/g/hungrybluedev/CMake-Basic-C-Template/context:cpp) [![LGTM Alerts](https://img.shields.io/lgtm/alerts/github/hungrybluedev/CMake-Basic-C-Template)](https://lgtm.com/projects/g/hungrybluedev/CMake-Basic-C-Template/alerts/) |
| Codacy      | [![Codacy grade](https://img.shields.io/codacy/grade/0963bb8a14b14ddcb5e6d5cdcbe7b704)](https://www.codacy.com/)                                                                                                                                                                                                                                            |
| License     | [![GitHub](https://img.shields.io/github/license/hungrybluedev/CMake-Basic-C-Template)](LICENSE)                                                                                                                                                                                                                                                            |
| CI/CD       | [![GitHub Workflow Status](https://img.shields.io/github/workflow/status/hungrybluedev/CMake-Basic-C-Template/Cross-platform%20CMake%20Builds?label=Cross-platform%20build)](https://github.com/hungrybluedev/CMake-Basic-C-Template/actions)                                                                                                               |
| Version     | [![GitHub release (latest by date)](https://img.shields.io/github/v/release/hungrybluedev/CMake-Basic-C-Template)](https://github.com/hungrybluedev/CMake-Basic-C-Template/releases)                                                                                                                                                                        |

## Introduction

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

## Read The `.github/workflows/main.yml` File

A lot of time and effort has been invested into this file. Incrementally, I figured out the things I needed to do in order to ensure that the commits that are pushed to this repository are checked automatically. This file is also very small (comapared to existing solutions) because of a few special features available due to the Github Actions API. Briefly the steps performed are:

1. Installing CMake (using the [get-cmake action](https://github.com/marketplace/actions/get-cmake))
2. Running CMake (Build file generation and the actual building in one step) using the [run-cmake action](https://github.com/marketplace/actions/run-cmake).
3. Executing the binary that has been built.
4. Performing this for both **Debug** and **Release**.
5. Performing this for all the three operating systems: Ubuntu, MacOS and Windows (whatever the latest version happens to be).

There is also an option to skip the CI on a push if the commit message/body contains `[skip ci]`.

## Features

1. Provides a good starting point for new **C99** projects.
2. Pragmatic directory structure is suggested with the existing code.
3. Readable CMake configuration that can be customised easily.
4. Inclusion of [µnit](https://nemequ.github.io/munit/) as the recommended unit-testing framework. It can be changed easily; just read the CMake and use the given directory structture to add your own library of choice.
5. Integration with Github Actions. It ensures cross-platform builds and ensures that all unit-tests are successful (unless skipped).
6. Inclusion of suggested badges for the project's README.

## Reference

Almost all the material is derived from [An Introduction to Modern CMake](https://gitlab.com/CLIUtils/modern-cmake) by Henry Schreiner and others. Other sources will be mentioned as they pop up.
