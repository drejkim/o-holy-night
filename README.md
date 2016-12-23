# O Holy Night

Merry Christmas!

This project uses familiar ingredients, namely the Particle Photon and NeoPixels, and some paper cutouts to recreate the Nativity Scene. The lights are controlled with a custom iOS app.

Here's a picture of the final setup:

![Final setup](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/o-holy-night-lit.png)

And here's a screenshot of the accompanying iOS app:

<img src="https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/ios.png" width="250">

Check out this [video](https://youtu.be/TUcphhJK0uM) to see the lights choreographed to "O Holy Night" using the iOS app.

## Supplies

* [Particle Photon](https://store.particle.io/)
* [NeoPixel strips](https://www.adafruit.com/product/1138)
* An iOS device
* Breadboard
* 3 spools of wire (in 3 colors)
* 1 sheet of cardstock paper (8.5 x 11 in)
* 1 sheet of regular paper (8.5 x 11 in)
* Foam board
* Wire stripper
* Soldering iron
* Precision knife
* Scissors

## Light configuration

Here's a picture of the final LED setup as viewed from the bottom of the foam board:

![Lighting setup from bottom](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/led-setup-bottom.jpg)

A total of 7 LEDs are used from the NeoPixel strip. The first 3 LEDs (top) are used to light the sky, the 4th LED (middle) lights up the manger cube, and the 6th LED (bottom middle) lights up the star / angels. The 5th and 7th LEDs (bottom right and left) were originally reserved for spotlights on the angels, but ended up not being used in the final setup.

Use a soldering iron to connect each LED section to one another with long enough pieces of wire. Note the **direction of the arrows** on the LEDs. The arrows should all be **pointing away** from the first LED as you connect the LED sections.

Use a precision knife to cut out sections of the foam board, so that the LEDs are visible from the top. This is what the LED setup looks like from the top of the foam board:

![Lighting setup from bottom](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/led-setup-top.jpg)

## Paper setup

Print the sky PDF (`pdf/sky.pdf`) on cardstock paper. Use a precision knife to cut out the star and angels. Then, cut and fold the edges of the paper, so that it looks like this:

![Sky](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/sky-final.jpg)

Next, print the manger PDF (`pdf/manger.pdf`) on regular paper. Use scissors to cut the outline of the cube. Then, use tape to fold the sides together. The final cube looks like this:

![Manger](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/manger-final.jpg)

Place the pieces of paper on the foam board like so:

![Side view](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/o-holy-night-side.jpg)

The sky is placed in front of the first 3 LEDs (left), and the manger cube goes on top of the fourth LED (middle).

## Particle setup

Wire up the NeoPixels to the board as follows:

![Scehmatic](https://raw.githubusercontent.com/drejkim/o-holy-night/master/img/schematic.png)

* Download the [Particle Dev IDE](https://www.particle.io/dev) and follow the [instructions](https://docs.particle.io/guide/tools-and-features/dev/) on how to log into your account and select your device.
* Open `ino/light.ino` in the IDE.
* Send the code to the board
  * Select the **Compile** button. If it's compiled successfully, the status bar on the bottom should say, "Success!"
  * Send the code to the board by selecting the **Flash** button. Again, if it's successful, the status bar should say, "Success!"

## iOS setup

* Open the Xcode project `ios/o-holy-night/o-holy-night.xcodeproj`
* Go to `LightingControlPanelViewController.swift` and update **particleUsername**, **particlePassword**, and **particleDeviceName** with your Particle information.
* Run the app in either the emulator or your own iOS device.

You now have all the components needed to light up the Nativity Scene! Merry Christmas!
