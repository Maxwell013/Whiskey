# Whiskey
A lightweight windowing and I/O library for C++.

This library is part of a long term project that aims to build a small game engine and break it down into various smaller projects.
This is the third library and is still under development.

## Version 0.1.0 - Beta release
- Major: Development
- Minor: Beta release
- Patch: Beta release

## Features
- Platform agnostic implementation (windows support coming soon)
- Vulkan oriented (MoltenVK compatible)

## Usage
To get started with Whiskey, copy the `whiskey.hpp` file and the entire `whiskey` directory from the repository and add it to your project.
Make sure the compiler you are using only compiles the source files specific to your operating system!

Example:
```C++
// test.cpp

#include "whiskey.hpp"

int main() {

    wsky::Window *window = new wsky::Window();

    if (!window->create("Hello, world!", 800, 600))
        return 1; // Failed to create window

    // To start rendering with vulkan get the surface SDK as follows
    // window->getVulkanSurface(instance);

    while (!window->shouldClose()) {
        window->pollEvents();

        if (window->keyDown(wsky::KEY_ESCAPE))
            window->close();
    }

    window->cleanup();

    return 0;
}

```

## Changelog

### Version 0.1.0 - Beta release
- Added basic windowing methods for MacOS
- Added keyboard events methods for MacOS
