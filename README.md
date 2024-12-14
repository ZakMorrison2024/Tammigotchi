# Tammigotchi (Squid)

## Squid Tamagotchi on Arduino

This is a simple Tamagotchi created using an Arduino, featuring an LCD screen and basic interactive features. The user can interact with the virtual pet using two buttons to perform different actions. The virtual SQUID has two states represented by sprite frames, and the simulation includes meters for food and happiness.

## Features
- **Interactive Buttons**: Button 1 and Button 2 allow interaction with the virtual pet.
- **Food and Happiness Meters**: The pet has two primary meters: food and happiness, which decrease over time.
- **Sprite Animation**: The pet is represented by a simple animated sprite that changes every second.
- **Basic Input Handling**: Buttons can trigger actions, such as feeding or selecting options.
  
## Hardware Requirements
- **Arduino Board** (Uno, Nano, or compatible)
- **LCD Screen** (ST7920 128x64)
- **Two Push Buttons** for interaction
- **Wires for connections**

## Wiring
- **Button 1** connected to pin 2
- **Button 2** connected to pin 3
- **LCD** connected via SPI with pins:
  - Clock: Pin 13
  - Data: Pin 11
  - Chip Select (CS): Pin 9
  - Reset: Pin 8

## Libraries
- **U8g2lib**: Used for managing the graphics on the LCD screen.
  
Install the library from the Arduino Library Manager if you don't have it already.

## Code Overview

### Setup:
- The LCD is initialized, and button pins are set to `INPUT_PULLUP` mode.
- The serial communication is set up for debugging.

### Loop:
- The screen is updated every second, alternating between two sprite frames representing the pet.
- The food meter decreases over time, and if the food level drops below 50, the happiness meter also decreases.
- Button presses are detected, and actions are triggered accordingly (e.g., feeding the pet or entering/selecting an option).

### Current Meters:
- **Food**: Decreases over time. If it gets too low, happiness will decrease.
- **Happiness**: Decreases if food is low.

## Future Improvements
- Implement additional interactions with the pet.
- Add more sprite frames for animation.
- Implement sound or other feedback for user actions.

## License
This project is open-source. Feel free to modify and share it under the [MIT License](LICENSE).
