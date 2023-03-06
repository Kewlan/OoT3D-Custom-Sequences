# OoT3D Custom Sequences

## How to use
These sequences can be used both with and without the randomizer.

### Randomizer
1. Start the randomizer to have the right folder structure created in the SD card. Depending on the SD card, this can take several minutes! When you're able to move the cursor in the menu, it's done and the app can be closed.
2. Extract the sound archive of the game that's called `QueenSound.bcsar` and place it in `SD:/OoT3DR/Custom Music/`. On 3DS you can use godmode9. On Citra, right click the game in the game list and select `Dump RomFS`. The archive is found in the `sound` folder.
3. Place the sequences together with their respective cmeta file in the folder representing the music category where you want them to be able to appear.

### Vanilla
You can use [Citric Composer](https://github.com/Gota7/Citric-Composer) to manually replace sequences. You will also need to look at the cmeta files to know which sound bank, channels flags, and volume it should have. The first four bytes are the sound banks. The next two are the channel flags in _little endian_. The seventh byte is the volume.

## Contributing
[Read here!](https://github.com/Kewlan/OoT3D-Custom-Sequences/wiki/Contributing)
