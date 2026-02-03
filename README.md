# Introduction

These are the most important files for my iris keymap.

For rev4, a hex file is in the folder. You can just use that directly with QMK Toolbox on Windows.

If you need to create a new keymap, follow official instructions from QMK Firmware. Part of those instructions tell you how to create your own keymap. If you follow the instructions correctly, you will end up with a folder for your custom keymap. Replace the keymap.json file in that folder with the files in the rev4 folder in this repo (except the hex file). Running `qmk compile` should just work, but in case of errors, just correct them and try until you succeed.

Remember that you need to flash both halves separately!

Google "Iris Split Keyboard Keebio" if you're interested in more info.

## Old instructions that may no longer work

make-command (run inside the `qmk_firmware` directory):
```
make keebio/iris/rev4:samelandslaget
```
