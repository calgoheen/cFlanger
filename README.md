# cFlanger

<p align="center"><img src="cFlanger.png"></p>

## Overview

cFlanger is a simple flanger audio effect plugin available in VST3, AU, and CLAP formats for Mac and Windows, built using C++ and JUCE.

You can find the actual DSP code for this effect in the [cgo_modules](https://github.com/calgoheen/cgo_modules/tree/main/cgo_processors/effects) repository.

This project is inspired by the flanger audio effect found in a popular DAW.

## Build Instructions

### Prerequisites

- [CMake](https://cmake.org/)
- [Ninja](https://ninja-build.org/)

### Build

```
# Clone the repo
git clone --recurse-submodules https://github.com/calgoheen/cFlanger.git
cd cFlanger

# Configure and build
cmake --preset release
cmake --build --preset release
```

## External Dependencies

- [JUCE](https://github.com/juce-framework/JUCE)
- UI is built with [foleys_gui_magic](https://github.com/ffAudio/foleys_gui_magic)
- DSP modules from [chowdsp_utils](https://github.com/Chowdhury-DSP/chowdsp_utils)
- CLAP plugin format is built with [clap-juce-extensions](https://github.com/free-audio/clap-juce-extensions)
