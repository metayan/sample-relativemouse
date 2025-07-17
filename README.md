This sample aims to reproduce inconsistencies between the state of the relative
mouse mode and the cursor visibility on macOS, which was present in SDL 2.0.20.

It opens a SDL window (with garbage content) and toggle relative mouse mode on
pressing <kbd>Alt</kbd>.

When relative mouse mode is enabled, mouse events are logged to the console.

To build and execute:

```bash
meson setup x
ninja -Cx
x/sample-relativemouse
```

On macOS Catalina 10.15.7, with Command Line Tools 11.x installed, first do:
```bash
export SDKROOT=/Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk
```
or similar, depending on SDK version.
