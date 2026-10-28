# Jatra

[![Latest Release](https://img.shields.io/github/v/release/nafismustofa/project-jatra)](https://github.com/nafismustofa/project-jatra/releases/latest)

**A flexible locomotion system for Unreal Engine, built on Motion Matching with a simple, data-driven overlay system.**

Jatra extends the Game Animation Sample Project with a ready-to-use character, a central configuration asset, and an overlay system with per-bone blending, so you can go from drop-in plugin to playable character in minutes.

---

## Features

- **Customizable Motion Matching locomotion**: Built on Unreal Engine's Motion Matching (Game Animation Sample Project).
- **Overlay animation system**: Layer animations on top of locomotion with custom bone blending, configured through a data asset.
- **Aim offset system**: Drive upper-body aiming with aim offset blend spaces activated through gameplay tags.
- **Central data asset settings**: Tune all movement and animation settings from a single place.
- **Easy retargeting**: Works with any bipedal character through IK Retargeter.
- **Dynamic camera system**: Adjusts the camera automatically for different locomotion states and aiming.
- **Idle break animations**: Configurable animation arrays for both standing and crouching idle breaks.

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

## Setup

### 1. Register the gameplay tags

1. In the Content Browser, duplicate the following data table:

   `Jatra/Content/Blueprints/Data/DT_Jatra_GameplayTags`

2. Go to **Project Settings → Project → GameplayTags**.
3. Under **Gameplay Tag Table List**, add your copy of the data table.

   ![Gameplay Tag Table](docs/images/gameplay-tags.png)

> **Tip:** Adding tags directly to `DT_Jatra_GameplayTags` may get overwritten when you update the plugin. To avoid this, it is advised to use a copy of the data table.

### 2. Try the default character

Set `BP_JatraCharacter` as the **Default Pawn Class** in your GameMode to test the system right away:

`Jatra/Content/Blueprints/BP_JatraCharacter`

### 3. Use your own character (Retargeting)

1. Open `BP_JatraCharacter_Retargeted`:

   `Jatra/Content/Blueprints/BP_JatraCharacter_Retargeted`

2. Set the **RetargetedMesh** to your custom character's skeletal mesh.
3. Assign your own IK Retargeter asset to the **IKRetargeter** property.

> **Tip:** Create a **Child Blueprint Class** of `BP_JatraCharacter_Retargeted` and make your changes there. This keeps the plugin content untouched and makes updating easier.

### 4. Configure animation and movement settings

1. Duplicate the default data asset:

   `Jatra/Content/Blueprints/DataAssets/DA_AnimationData_JatraCharacter`

2. Assign your copy to the **AnimationData** property of the `AC_JatraLocomotion` component attached to the character blueprint.
3. Customize the data asset to suit your needs.

   ![Animation Data Asset](docs/images/animation-data-asset.png)

### 5. Set up overlay animations

Overlays let you layer an animation (for example, holding a rifle or carrying a box) on top of the base locomotion, with per-bone control over how strongly it blends in.

1. Create a new **Data Asset** using the primary **Primary Data Asset** class:

   `Jatra/Content/Blueprints/Data/PrimaryDataAssets/PDA_OverlayAsset`

2. Open the asset, add overlay animation, enable the set of bones you want to overlay and adjust bone blend weights to control which parts of the body the overlay affects.

   ![Overlay Data Asset](docs/images/overlay-asset.png)

3. Add a new gameplay tag for the overlay to the `DT_Jatra_GameplayTags` data table.
4. Open your copy of `DA_AnimationData_JatraCharacter` and add an entry to the **Overlay Data**, linking the gameplay tag to your overlay asset.

   ![Overlay Map](docs/images/overlay-map.png)

5. Activate and deactivate the overlay at runtime with these Blueprint functions on the `AC_JatraLocomotion` component:
   - `SetLocomotionTag()`: Applies the overlay for the given gameplay tag.
   - `ResetLocomotionTag()`: Removes the overlay and returns to the default locomotion stance.

   ![Gameplay Tags Blueprint Functions](docs/images/tags-blueprint-functions.png)

### 6. Set up aim offset

1. Create an **Aim Offset** blend space asset.
2. Open your copy of `DA_AnimationData_JatraCharacter` and add an entry to the **Aim Offset Data**, linking a gameplay tag to your aim offset blend space. The blend space is activated whenever that gameplay tag is active.

   ![Aim Offset Map](docs/images/aim-offset-map.png)

3. Activate and deactivate the aim offset with the same `SetLocomotionTag()` and `ResetLocomotionTag()` Blueprint functions on the `AC_JatraLocomotion` component.

> **Tip:** The default aim offset is used when no particular gameplay tag is active.

### 7. Set up the dynamic camera

Jatra includes a dynamic camera system that adjusts the camera for different locomotion states and aiming.

1. Adjust the **Dynamic Camera Distance Factor** property to control how the camera distance responds to the character movement. Higher values keep the camera closer to the character, and lower values let it trail further behind.

2. Adjust the **Aim Camera Distance** and **Aim Camera Offset** on the `AC_JatraLocomotion` component to set the camera position while aiming.

![Camera Settings](docs/images/camera-settings.png)

> **Tip:** To turn off the dynamic camera system, uncheck **Enable Dynamic Camera** on the `AC_JatraLocomotion` component.

### 8. Set up input

Jatra includes an example input setup in the `AC_JatraInput` component. Use it as a reference for connecting Jatra to your own input system.

To disable the example input, uncheck **Enable Jatra Input** on the `AC_JatraInput` component attached to your character Blueprint.

---

## License

Jatra is licensed for use only with Unreal Engine-based products, in accordance with the [Unreal Engine Content License Agreement](https://www.unrealengine.com/eula/content).

## Contributing

Issues and pull requests are welcome. If you find a bug or have a feature request, please [open an issue](../../issues).
