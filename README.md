![Image of keyboard](keyboard.jpg)

# qmk-atreus62
Firmware for my Atreus62 keyboard.

If you're interested in getting yourself an Atreus62 keyboards it can be purchased from [Profet Keyboards](https://shop.profetkeyboards.com/product/atreus62-keyboard).

## Installation

[QMK Firmware](https://github.com/qmk/qmk_firmware) is needed. It can be downloaded and setup via

```
make qmk
```

This will download QMK into a `qmk_firmware` folder. It will also create a symlink to the `zapling`
folder.

## Compile

```
make compile
```

## Flash

```
make flash
```

Put the keyboard in `RESET` mode, either via keypress or via hard reset.
