# Jatra

[![Latest Release](https://img.shields.io/github/v/release/nafismustofa/project-jatra)](https://github.com/nafismustofa/project-jatra/releases/latest)

**A flexible locomotion system for Unreal Engine, built on Motion Matching with a simple, data-driven overlay system.**

Jatra extends the Game Animation Sample Project with a ready-to-use character, an animation config data asset to tweak the animation system, and an overlay system with per-bone blending, so you can go from drop-in plugin to playable character in minutes.

---

## Features

- **Customizable motion matching locomotion**: Built on Unreal Engine's motion matching system (Game Animation Sample Project).
- **Overlay animation system**: Layer animations on top of locomotion with custom bone blending, configured through a data asset.
- **Data asset-driven animation**: Tune all movement and animation settings using data assets. Switch between different locomotion sets using data assets activated through gameplay tags.
- **Aim offset system**: Drive upper-body aiming with aim offset blend spaces activated through gameplay tags.
- **Easy retargeting**: Works with any bipedal character through IK Retargeter asset.
- **Dynamic camera system**: Adjusts the camera automatically for different locomotion states and aiming.

---

## Installation

1. Download the [latest release](../../releases/latest) for your Unreal Engine version from the [Releases page](../../releases).
2. Extract it into your project's `Plugins` folder:
   ```
   YourProject/
   └── Plugins/
       └── Jatra/
   ```
3. Open your project and enable the plugin if prompted, then restart the editor.

---

## License

Jatra is licensed for use only with Unreal Engine-based products, in accordance with the [Unreal Engine Content License Agreement](https://www.unrealengine.com/eula/content).

## Contributing

Issues and pull requests are welcome. If you find a bug or have a feature request, please [open an issue](../../issues).

---

made with <3 by nafismustofa
