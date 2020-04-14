![Image of keyboard](keyboard.jpg)

# qmk-atreus62
Firmware for my Atreus62 keyboard.

If you're interested in getting yourself an Atreus62 keyboards it can be purchased from [Profet Keyboards](https://shop.profetkeyboards.com/product/atreus62-keyboard).

## About

The layout is based on a US layout with some modifications. It also allows for input of Swedish characters like `åäö` in Linux systems without switching between keyboard layouts in software. Input of these characters aswell as access to other common functions found on normal layouts are accessable while holding the `FN` key.

| Key combo     | Output        |
| ------------- |:-------------:|
| `shift` + `ESC` | `~` |
| `FN` + (`i`, `j`, `k`, `l`) | Arrow keys |
| `FN` + (`y`, `h`) | `Home`, `End` |
| `FN` + (`u`, `o`) | `Page up`, `Page down` |
| `FN` + (`ESC`, `1` ... `=` ) | `F1`, `F2`, ... `F12` |
| `FN` + (`shift`) + `[` | `å`, `Å` |
| `FN` + (`shift`) + `'` | `ä`, `Ä` |
| `FN` + (`shift`) + `;` | `ö`, `Ö` |
| `FN` + `e` | `€` |

Typing `åäö` is normally not possible while under a US layout, but is possible though to the unicode input mode available in Linux via the (`ctrl` + `shift` + `u`) combination. You can read more about unicode input at [QMKs Unicode section](https://beta.docs.qmk.fm/using-qmk/software-features/feature_unicode#input-modes).

Feel free to use any code and implement it in your own layout.

### Notice

Some applications doesn't support the (`ctrl` + `shift` + `u`) way to input unicode. As of right now, there is no known way to circumvent this. One workaround is to temporarily change the keyboard layout to Swedish in software.

## Installation

[QMK Firmware](https://github.com/qmk/qmk_firmware) is needed. It can be installed with the following command. Note that you might need to run this command as `sudo`.

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
