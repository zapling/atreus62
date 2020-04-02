![Image of keyboard](keyboard.jpg)

# qmk-atreus62
Layout for my Atreus62 keyboard

## Installation

* Download the [qmk_firmware](https://github.com/qmk/qmk_firmware)
* Put the `keymap.c` in `keyboards/atreus62/keymaps/zapling/` folder.

## Compile

```
qmk compile -kb atreus62 -km zapling
```

## Flash

```
qmk flash -kb atreus62 -km zapling
```

Put the keyboard in `RESET` mode, either via keypress or via hard reset.
