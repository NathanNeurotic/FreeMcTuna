# ![FMCT](https://github.com/user-attachments/assets/528c5349-60e6-4792-a3fd-73b40698f31a)

# OpenTuna: UMCS Installer - An Enhanced OpenTuna Installer Mod

The OpenTuna UMCS Installer is a complete installation utility designed to set up OpenTuna for use across a wide range of PlayStation 2 models, including support for specific ROM-dependent variations. This modified installer enhances compatibility, simplifies deployment, and includes safeguards to prevent corruption.

## Understanding the OpenTuna Variants
OpenTuna has three critical variants based on ROM versions:

1. **FAT** – For older PS2 consoles.
2. **FAT170** – For specific later FAT consoles.
3. **SLIMS** – For all Slim model consoles.

> **WARNING**: *Do NOT use a FAT OpenTuna variant on a Slim console, and vice versa. Doing so can cause memory card data corruption.*

## Compatibility & Multi-System Cards
**Can I install OpenTuna Slim on top of my System Update Exploit so one card works on every console?**  
Yes. However, avoid opening the memory card browser with an incompatible combination (e.g., FAT variant on a Slim console). Only when the wrong ROM and tuna combination is accessed through the memory card browser is there a risk of corruption.

## Integration with FMCB or PS2BBL
**Can I add OpenTuna to my FMCB or PS2BBL installation?**  
Yes, but be aware that it will modify `FREEMCB.CNF`, `CONFIG.INI`, and `PS2BBL.INI`, potentially removing apps or altering paths. 

For a safer approach, use the [OpenTuna Standalone Addon Installer](https://github.com/NathanNeurotic/FreeMcTuna/releases/tag/OpenTunaStandAloneAddOn), which only installs:
- `mc?:/OPENTUNA/icon.icn`
- `mc?:/OPENTUNA/icon.sys`

> **NOTE**: OpenTuna is hardcoded to boot `mc?:/BOOT/BOOT.ELF`. Ensure this file exists or the system may freeze or return to the PS2 browser.

## What is Free McTuna?
Free McTuna is a full memory card exploit package utilizing OpenTuna to boot FreeMCBoot:

- Boots FMCB 1.966 (decrypted) via OpenTuna's BOOT.ELF (PS2BBL)
- Easily switchable to 1.953 or OSDMENU by deleting corresponding folders
- Launch wLaunchELF by holding **START** on boot
- Full BDMA support for exFAT compatibility
- Highly customizable: redirect launch paths, replace icons, and integrate with modchips
- Compatible with nearly all models SCPH-18000 and newer

## Getting Started with Free McTuna
If you're new, try:
- [FreeDVDBoot](https://github.com/ps2homebrew/FreeDVDBoot)
- [PFS-BatchKit-Manager](https://github.com/GDX-X/PFS-BatchKit-Manager)
- [PS2HDH](https://www.psx-place.com/resources/ps2-hdd-decryption-helper.1507/)
- [HDL-Batch-Installer](https://github.com/israpps/HDL-Batch-installer)

Or use ready-made memory cards with:
- [PSXMC2](https://www.bitfunx.com/product/psxmemcard-gen2-memory-card-for-playstation1-ps-one-playstation2-game-consoles/)
- [SD2PSX](https://sd2psx.net/ps2-exploit.html)
- [MCP2](https://qrco.de/bdiiDa)

Cards are downloadable [here](https://www.psx-place.com/threads/mmce-memcard-pro2-sd2psx-psxmemcard-gen1-2-pmc-z-ready-to-use-memory-cards.46415/).

> Once in wLaunchELF, locate your storage device and run the installer ELF. Be patient — the installation may appear stalled but will eventually complete or throw an error. It will not freeze.

**Minimum Recommended Free Space:** 6MiB  
**Warning:** The installer *will* delete folders in its paths.

---

## Files Installed by This Installer (mc?:/)
- `BOOT/BOOT.ELF` → `mc?:/BOOT/BOOT.ELF`
- `BOOT/BOOT.icn` → `mc?:/BOOT/BOOT.icn`
- `BOOT/BOOT2.ELF` → `mc?:/BOOT/BOOT2.ELF`
- `BOOT/CONFIG.INI` → `mc?:/BOOT/CONFIG.INI`
- `BOOT/ESR.ELF` → `mc?:/BOOT/ESR.ELF`
- `BOOT/copy.icn` → `mc?:/BOOT/copy.icn`
- `BOOT/del.icn` → `mc?:/BOOT/del.icn`
- `BOOT/icon.sys` → `mc?:/BOOT/icon.sys`
- `FMCBD-1.953/FMCB.icn` → `mc?:/FMCBD-1.953/FMCB.icn`
- `FMCBD-1.953/FMCBD-1.953.ELF` → `mc?:/FMCBD-1.953/FMCBD-1.953.ELF`
- `FMCBD-1.953/copy.icn` → `mc?:/FMCBD-1.953/copy.icn`
- `FMCBD-1.953/del.icn` → `mc?:/FMCBD-1.953/del.icn`
- `FMCBD-1.953/icon.sys` → `mc?:/FMCBD-1.953/icon.sys`
- `FMCBD-1.966/FMCB.icn` → `mc?:/FMCBD-1.966/FMCB.icn`
- `FMCBD-1.966/FMCBD-1.966.ELF` → `mc?:/FMCBD-1.966/FMCBD-1.966.ELF`
- `FMCBD-1.966/copy.icn` → `mc?:/FMCBD-1.966/copy.icn`
- `FMCBD-1.966/del.icn` → `mc?:/FMCBD-1.966/del.icn`
- `FMCBD-1.966/icon.sys` → `mc?:/FMCBD-1.966/icon.sys`
- `OPENTUNA/OpenTuna_FAT-110-120-150-160.psu` → `mc?:/OPENTUNA/OpenTuna_FAT-110-120-150-160.psu`
- `OPENTUNA/OpenTuna_FAT-170.psu` → `mc?:/OPENTUNA/OpenTuna_FAT-170.psu`
- `OPENTUNA/OpenTuna_Slims-190-200-220-230.psu` → `mc?:/OPENTUNA/OpenTuna_Slims-190-200-220-230.psu`
- `OPENTUNA/README.md` → `mc?:/OPENTUNA/README.md`
- `OSDMENU/OSDMENU.CNF` → `mc?:/OSDMENU/OSDMENU.CNF`
- `OSDMENU/OSDMENU.ELF` → `mc?:/OSDMENU/OSDMENU.ELF`
- `OSDMENU/copy.icn` → `mc?:/OSDMENU/copy.icn`
- `OSDMENU/del.icn` → `mc?:/OSDMENU/del.icn`
- `OSDMENU/icon.sys` → `mc?:/OSDMENU/icon.sys`
- `OSDMENU/launcher.elf` → `mc?:/OSDMENU/launcher.elf`
- `OSDMENU/list.icn` → `mc?:/OSDMENU/list.icn`
- `OSDMENU/patcher.elf` → `mc?:/OSDMENU/patcher.elf`
- `POPSTARTER/IPCONFIG.DAT` → `mc?:/POPSTARTER/IPCONFIG.DAT`
- `POPSTARTER/SMBCONFIG.DAT` → `mc?:/POPSTARTER/SMBCONFIG.DAT`
- `POPSTARTER/SMSUTILS.irx` → `mc?:/POPSTARTER/SMSUTILS.irx`
- `POPSTARTER/del.icn` → `mc?:/POPSTARTER/del.icn`
- `POPSTARTER/icon.sys` → `mc?:/POPSTARTER/icon.sys`
- `POPSTARTER/list.icn` → `mc?:/POPSTARTER/list.icn`
- `POPSTARTER/poweroff.irx` → `mc?:/POPSTARTER/poweroff.irx`
- `POWEROFF/POWEROFF.ELF` → `mc?:/POWEROFF/POWEROFF.ELF`
- `POWEROFF/copy.icn` → `mc?:/POWEROFF/copy.icn`
- `POWEROFF/del.icn` → `mc?:/POWEROFF/del.icn`
- `POWEROFF/icon.sys` → `mc?:/POWEROFF/icon.sys`
- `POWEROFF/list.icn` → `mc?:/POWEROFF/list.icn`
- `PS1_DKWDRV/DKWDRV.ELF` → `mc?:/PS1_DKWDRV/DKWDRV.ELF`
- `PS1_DKWDRV/TITLE.CFG` → `mc?:/PS1_DKWDRV/TITLE.CFG`
- `PS1_DKWDRV/copy.icn` → `mc?:/PS1_DKWDRV/copy.icn`
- `PS1_DKWDRV/del.icn` → `mc?:/PS1_DKWDRV/del.icn`
- `PS1_DKWDRV/icon.sys` → `mc?:/PS1_DKWDRV/icon.sys`
- `PS1_DKWDRV/list.icn` → `mc?:/PS1_DKWDRV/list.icn`
- `SYS-CONF/ENDVDPL.irx` → `mc?:/SYS-CONF/ENDVDPL.irx`
- `SYS-CONF/FREEMCB.CNF` → `mc?:/SYS-CONF/FREEMCB.CNF`
- `SYS-CONF/IPCONFIG.DAT` → `mc?:/SYS-CONF/IPCONFIG.DAT`
- `SYS-CONF/USBD.IRX` → `mc?:/SYS-CONF/USBD.IRX`
- `SYS-CONF/USBHDFSD.IRX` → `mc?:/SYS-CONF/USBHDFSD.IRX`
- `SYS-CONF/copy.icn` → `mc?:/SYS-CONF/copy.icn`
- `SYS-CONF/del.icn` → `mc?:/SYS-CONF/del.icn`
- `SYS-CONF/icon.sys` → `mc?:/SYS-CONF/icon.sys`
- `SYS-CONF/sysconf.icn` → `mc?:/SYS-CONF/sysconf.icn`
- `SYS_FMCB-CFG/FMCB-CFG.ELF` → `mc?:/SYS_FMCB-CFG/FMCB-CFG.ELF`
- `SYS_FMCB-CFG/title.cfg` → `mc?:/SYS_FMCB-CFG/title.cfg`
- `SYS_FMCB-CFG/copy.icn` → `mc?:/SYS_FMCB-CFG/copy.icn`
- `SYS_FMCB-CFG/del.icn` → `mc?:/SYS_FMCB-CFG/del.icn`
- `SYS_FMCB-CFG/icon.sys` → `mc?:/SYS_FMCB-CFG/icon.sys`
- `SYS_FMCB-CFG/list.icn` → `mc?:/SYS_FMCB-CFG/list.icn`

---

## Folder Deletion Notice
During installation, the following folders are **automatically deleted** to ensure clean setup:

```text
BOOT
SYS-CONF
SYS_FMCBCFG
SYS_FMCB-CFG
FMCBD-1.966
FMCBD-1.953
FMCBD-1.8C
LDR_FMCBD-1.966
BXEXEC-FUNTUNA
FUNTUNA
BXEXEC-OPENTUNA
FORTUNA
OPENTUNA
FUNTUNA-FORK
RESTART
POWEROFF
```

**Important:** Backup any folder you wish to keep by using `psuPaste` after copying them to your storage device via wLaunchELF. If you want to restore later, simply `psuPaste` them back to the memory card.

---

## Summary
OpenTuna UMCS Installer is a reliable and universal way to deploy the correct version of OpenTuna based on your PS2 model. It integrates support for Free McBoot, advanced bootloaders, and icon systems, while offering safeguards and backup options for power users. Proceed cautiously, back up important data, and enjoy a smooth exploit installation experience.
