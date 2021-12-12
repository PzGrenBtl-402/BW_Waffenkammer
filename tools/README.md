# Building Bundeswehr Waffenkammer from source (HEMTT)

## Requirements

- Arma 3
- Arma 3 Tools (available on Steam)
- Run Arma 3 and Arma 3 Tools directly from Steam once to install registry entries (and again after every update)
- [Windows] PowerShell v5.0+

## Setup and Building

### Initial Setup

Execute `setup.bat` in `tools` folder (Windows) or download [this HEMTT binary](https://github.com/BrettMayson/HEMTT/releases/latest) and place hemtt in project root (Linux).

### Create a Release Build

To create a complete build that you can use without the source files, execute `build_release.bat` (Windows) or run `$ hemtt build --release -f` (Linux) in the root folder. This will populate the release folder with binarized PBOs that you can redistribute. These handle like those of any other mod.
