# R4 SDHC Gold Pro Dual Storage HBMenu

This is a modified build of HBMenu with UI enhancements but setup to act as a kernel/firmware replacement to R4 SDHC Gold Pro.
This can be used with most "Demon' type DSTTi clones that use similar flash layout. Not compatible with other cart types!

The banner provided is for the Gold Pro varient. You will need to provide an alternate banner if you intend to use this on a different brand demon clone.

The program will change boot behavior based on what button is held on boot:

* Holding B button will reboot console into GBA mode with gbaframe.bmp as the frame graphic.
* Holding Y button will boot GodMode9i.
* Holding A button will boot MaxMediaDock's slot1 rom for booting into MaxMediaDock devices on slot-2.
* Holding any other button will boot into filebrowser skipping autoboot. Except for Select button which is only used to skip nrio-usb-disk autoboot if USB slot2 card is present.

Also if an N-Card or N-Card clone USB slot-2 device is present on boot, the program will auto boot into nrio-usb-disk. A open source
file transfer program that makes use of the USB slot-2 device to connect flashcart's MicroSD storage to PC.

The repo this build of nrio-usb-disk can be found at: https://github.com/ApacheThunder/nrio-usb-disk
The original repo this build was forked from: https://github.com/asiekierka/nrio-usb-disk

This new app was created courtasy of Asiekirka.


Currently the gbaframe loader is setup to load GBA-Exploader compatible BMP files. Currently only setup to load frames from internal flash fat image.
Please refer to the fat image in NitroFS folder for that file if you wish to customize this.

This menu has a special feature in the filebrowser. You will notice that on boot it will show the file listing for the files found inside internal FAT image
stored in NitroFS. This is made possible with a special "NTRO" dldi driver that I wrote. This allows this cart to boot without a MicroSD card inserted!

You can find my source to that driver here:

https://github.com/ApacheThunder/DLDI/tree/master/source/ntro

However some actions will of coarse require the presense of a MicroSD card. (some of the included apps depend on that)

Assuming a MicroSD card is present on boot you can use shoulder buttons to navigate to MicroSD storage when wanting to boot files from MicroSD.

Note unlike the EZP version of this bootstrap, once fat init is attempted on MicroSD it is no longer possible to read data from ntro mount.
Once file browser is switched to TTIO, you won't be able to switch back. If booted with no mSD present, fat init fail message will display if you do not press a button on boot and allow it to attempt standard auto boot.
If you press the X key to bring up filebrowser with no mSD present you can still make selectiosn as normal. Note though that attempting to navigate to TTIO with no SD present will halt the program as well.

# Information on layout of r4isdhc-backup.bin used by R4i-SDHC familiy of flashcarts (as described by ntrboot flasher)

Note that offsets between 0x1B3C00-0x1F0000 (with 1F0000 being where rom header starts. Data is offset in the flashrom) isn't usable for custom data as this area gets moved/mirrored to different locations in the rom space.
The flashrom data near 0x0 probably has mapping for this but no one has reversed this. The fat image has been sized perfectly to ensure there is breathing room here. You will get undefined behavior if you do anything that expands your rom past 0x1B2C00 in the flashrom so try to avoid that!

0x1F0000 is the first 0x10000 bytes of the intended rom. Ensure a split copy of it exists there. 0x1000 is where data for 0x1000 and beyond for your rom is placed. This is more or less how the layout of this flashrom works. ;)

0x800-0xFFF section of flashrom is also used for rom data but it's currently configured to for mirrored/fake data past the 2MB barrier and isn't really useful for our purposes FYI.

This familiy of flashcarts expects first 0x48 bytes of blowfish key at 0x1000 and the 0x1000 blowfish key block at 0x2000 in the rom you will be using. Please ensure this key is present and that arm9 secure area is encrypted with proper secure area CRC in header!

# License
Note: While the GPL license allows you to distribute modified versions of this program it would be appreciated if any improvements are contributed to devkitPro. Ultimately the community as a whole is better served by having a single official source for tools, applications and libraries.

The latest sources may be obtained from devkitPro git using the command: `git clone git@github.com:devkitPro/nds-hb-menu.git`

```
 Copyright (C) 2005 - 2017
	Michael "Chishm" Chisholm
	Dave "WinterMute" Murphy

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 ```
