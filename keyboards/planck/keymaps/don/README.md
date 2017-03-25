# Don's Planck Layout

For information on layouts and templates, see [keymap.c](./keymap.c).


## Build

To build the binary hex file (keyboard firmware): `make`


## Update keyboard

To push the firmware onto the keyboard:

* Put the keyboard in DFU mode: RAISE + LOWER + [top left corner]
* `sudo make dfu`

