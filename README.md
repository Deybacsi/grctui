# GrcTUI

A small **T**ext **U**ser **I**nterface for gridcoin wallet. The simplest way to view the status of your wallet from a linux terminal.  

## Disclaimer

This software is supplied "AS IS" without any warranties and support. The author will not be liable for any damages you may suffer in connection with using, modifying, or distributing it. If you use it, you are the only responsible for all of your losses.

And of course it's not associated in any shape or form with the official Gridcoin project.

## Getting started

### How to install?

Just download it to a folder, and start `./grctui.sh`

### Dependencies

There are no dependencies, you don't have to install anything. \o/

### Requirements

- bash
- terminal
- installed gridcoin wallet

### Keyboard shortcuts

- `x` - Exit

### Privacy

- Private data is stored in `tmp` directory. During every successful exit, the content of the directory is flushed. If the program terminates in an abnormal way (`CTRL-C` or by an error), then please delete the content manually, or restart GrcTUI, and exit with pressing `x`.
- No data is sent to any server 

