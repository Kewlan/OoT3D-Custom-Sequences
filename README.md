# OoT3D Custom Sequences
[Click here to download!](https://github.com/Kewlan/OoT3D-Custom-Sequences/archive/refs/heads/main.zip)

## How to use
These sequences can be used both with and without the randomizer.

### Randomizer
1. Start the randomizer to have the right folder structure created in the SD card. Depending on the SD card, this can take several minutes! When you're able to move the cursor in the menu, it's done and the app can be closed.
2. Extract the sound archive of the game called `QueenSound.bcsar` from the romfs and place it in `SD:/OoT3DR/Custom Music/`.  
On 3DS you can use godmode9. [Read the relevant "Extracting RomFS" section here for a how-to.](https://gist.github.com/PixelSergey/73d0a4bc1437dbaa53a1d1ce849fdda1)  
On Citra, right click the game in the game list and select `Dump RomFS`.  
The archive is found in the `sound` folder.
3. Place the sequences together with their respective cmeta file in the folder representing the music category where you want them to be able to appear.  
For example, if you want a song to be able to appear anywhere, you place it in the `/Background Music/` folder. If you want it to only be in dungeons, then you place it in `/Background Music/Area Themes/Dungeons/`. If it should only appear in the final Ganon fight, you place it in `/Background Music/Battle Themes/Ganon Battle/`, and so on.  
**Important!** At the moment the music files need to be placed directly in the music category folders. Subfolders that weren't auto-generated are not looked through yet!
4. Now they're ready to be shuffled. Remember to turn on the option!

### Vanilla
You can use [Citric Composer](https://github.com/Gota7/Citric-Composer) to manually replace sequences. You will also need to look at the cmeta files to know which sound bank, channels flags, and volume it should have. 
* The first four bytes are the sound banks. 
* The next two are the channel flags in _little endian_. 
* The seventh byte is the volume.

Once you're done and have the new sound archive, it will need to be placed in the mod folder like usual.

## Contributing
[Read here!](https://github.com/Kewlan/OoT3D-Custom-Sequences/wiki/Contributing)
