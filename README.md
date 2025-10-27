# USB Nova Firmware

* Buy USB Nova at [spacehuhn.store](https://spacehuhn.store/collections/usb)
* Get firmware updates on the [release page](/releases)
* For documentation, please visit: [docs.spacehuhn.com](https://docs.spacehuhn.com/usbnova/)

## Building with PlatformIO

Make sure you have [PlatformIO](https://platformio.org/) installed.
To compile the firmware, navigate to the project directory and run:

```bash
pio run
```

To compile for a specific board, use the `-e` flag followed by the environment name.

```bash
pio run -e usbnova_mkii
```

To compile mki firmware versions into UF2 files, you have to have `uf2conv` installed. 
To install uf2conv, install rust, then `cargo install uf2conv`