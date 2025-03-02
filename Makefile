EE_BIN = Installer.elf
EE_BIN_PACKED = FMCT-INSTALLER.ELF
EE_BIN_STRIPPED = stripped.elf
EE_OBJS = main.o gs.o pad.o  gs_asm.o ps2_asm.o dma_asm.o
EE_OBJS += restartdel_icn.o restarticon_sys.o restartlist_icn.o restart_elf.o powerdel_icn.o powericon_sys.o powerlist_icn.o poweroff_elf.o fmcbdninesixcopy_icn.o fmcbdninesixdel_icn.o fmcbdninesix_icn.o fmcbdninesix_elf.o fmcbdninesixicon_sys.o fmcbdninefivecopy_icn.o fmcbdninefivedel_icn.o fmcbdninefive_icn.o fmcbdninefive_elf.o fmcbdninefiveicon_sys.o fmcbdeightcopy_icn.o fmcbdeightdel_icn.o fmcbdeight_icn.o fmcbdeight_elf.o fmcbdeighticon_sys.o apps_icn.o appsdel_icn.o appsicon_sys.o  \
	title_cfg.o esr_elf.o fmcbd_elf.o boot2_elf.o boot_elf.o icon_sys.o copy_icn.o del_icn.o boot_icn.o config_ini.o OpenTuna_sys.o OpenTuna_SLIMS.o OpenTuna_FAT-170.o \
	OpenTuna_FAT-110-120-150-160.o PADMAN_irx.o SIO2MAN_irx.o MCMAN_irx.o MCSERV_irx.o ldrfmcbdicon_sys.o ldrfmcbdfmcb_icn.o ldrfmcbddel_icn.o \
	ldrfmcbdcopy_icn.o fmcbcfgcopy_icn.o fmcbcfgdel_icn.o fmcbcfgicon_sys.o fmcbcfglist_icn.o sysconffmcb_cfg_elf.o sysconffreemcb_cnf.o sysconfipconfig_dat.o \
	sysconflaunchelf_cnf.o sysconfps2bbl_ini.o sysconfusbd_irx.o sysconfusbhdfsd_irx.o sysconfcopy_icn.o sysconfdel_icn.o sysconfendvdpl_irx.o sysconficon_sys.o \
	sysconfsysconf_icn.o
EE_SRC = restartdel_icn.s restarticon_sys.s restartlist_icn.s restart_elf.s powerdel_icn.s powericon_sys.s powerlist_icn.s poweroff_elf.s \
	fmcbdninesixcopy_icn.s fmcbdninesixdel_icn.s fmcbdninesix_icn.s fmcbdninesix_elf.s fmcbdninesixicon_sys.s \
	fmcbdninefivecopy_icn.s fmcbdninefivedel_icn.s fmcbdninefive_icn.s fmcbdninefive_elf.s fmcbdninefiveicon_sys.s \
	fmcbdeightcopy_icn.s fmcbdeightdel_icn.s fmcbdeight_icn.s fmcbdeight_elf.s fmcbdeighticon_sys.s \
	apps_icn.s appsdel_icn.s appsicon_sys.s title_cfg.s esr_elf.s fmcbd_elf.s boot2_elf.s boot_elf.s icon_sys.s copy_icn.s del_icn.s \
	boot_icn.s config_ini.s OpenTuna_sys.s OpenTuna_SLIMS.s OpenTuna_FAT-170.s OpenTuna_FAT-110-120-150-160.s \
	PADMAN_irx.c SIO2MAN_irx.c MCMAN_irx.c MCSERV_irx.c \
	ldrfmcbdicon_sys.s ldrfmcbdfmcb_icn.s ldrfmcbddel_icn.s ldrfmcbdcopy_icn.s fmcbcfgcopy_icn.s fmcbcfgdel_icn.s fmcbcfgicon_sys.s \
	fmcbcfglist_icn.s sysconffmcb_cfg_elf.s sysconffreemcb_cnf.s sysconfipconfig_dat.s sysconflaunchelf_cnf.s sysconfps2bbl_ini.s \
	sysconfusbd_irx.s sysconfusbhdfsd_irx.s sysconfcopy_icn.s sysconfdel_icn.s sysconfendvdpl_irx.s sysconficon_sys.s sysconfsysconf_icn.s
	   
EE_LIBS = -ldebug -lcdvd -lpatches -lpadx -lmc

all:
	$(MAKE) $(EE_BIN_PACKED)
restartdel_icn.s:
	bin2s INSTALL/RESTART/DEL.ICN restartdel_icn.s restartdel_icn

restarticon_sys.s:
	bin2s INSTALL/RESTART/ICON.SYS restarticon_sys.s restarticon_sys

restartlist_icn.s:
	bin2s INSTALL/RESTART/LIST.ICN restartlist_icn.s restartlist_icn

restart_elf.s:
	bin2s INSTALL/RESTART/RESTART.ELF restart_elf.s restart_elf

powerdel_icn.s:
	bin2s INSTALL/POWEROFF/DEL.ICN powerdel_icn.s powerdel_icn

powericon_sys.s:
	bin2s INSTALL/POWEROFF/ICON.SYS powericon_sys.s powericon_sys

powerlist_icn.s:
	bin2s INSTALL/POWEROFF/LIST.ICN powerlist_icn.s powerlist_icn

poweroff_elf.s:
	bin2s INSTALL/POWEROFF/POWEROFF.ELF poweroff_elf.s poweroff_elf

fmcbdninesixcopy_icn.s:
	bin2s INSTALL/FMCBD-1.966/COPY.ICN fmcbdninesixcopy_icn.s fmcbdninesixcopy_icn

fmcbdninesixdel_icn.s:
	bin2s INSTALL/FMCBD-1.966/DEL.ICN fmcbdninesixdel_icn.s fmcbdninesixdel_icn

fmcbdninesix_icn.s:
	bin2s INSTALL/FMCBD-1.966/FMCB.ICN fmcbdninesix_icn.s fmcbdninesix_icn

fmcbdninesix_elf.s:
	bin2s INSTALL/FMCBD-1.966/FMCBD-1.966.ELF fmcbdninesix_elf.s fmcbdninesix_elf

fmcbdninesixicon_sys.s:
	bin2s INSTALL/FMCBD-1.966/ICON.SYS fmcbdninesixicon_sys.s fmcbdninesixicon_sys

fmcbdninefivecopy_icn.s:
	bin2s INSTALL/FMCBD-1.953/COPY.ICN fmcbdninefivecopy_icn.s fmcbdninefivecopy_icn

fmcbdninefivedel_icn.s:
	bin2s INSTALL/FMCBD-1.953/DEL.ICN fmcbdninefivedel_icn.s fmcbdninefivedel_icn

fmcbdninefive_icn.s:
	bin2s INSTALL/FMCBD-1.953/FMCB.ICN fmcbdninefive_icn.s fmcbdninefive_icn

fmcbdninefive_elf.s:
	bin2s INSTALL/FMCBD-1.953/FMCBD-1.953.ELF fmcbdninefive_elf.s fmcbdninefive_elf

fmcbdninefiveicon_sys.s:
	bin2s INSTALL/FMCBD-1.953/ICON.SYS fmcbdninefiveicon_sys.s fmcbdninefiveicon_sys

fmcbdeightcopy_icn.s:
	bin2s INSTALL/FMCBD-1.8C/COPY.ICN fmcbdeightcopy_icn.s fmcbdeightcopy_icn

fmcbdeightdel_icn.s:
	bin2s INSTALL/FMCBD-1.8C/DEL.ICN fmcbdeightdel_icn.s fmcbdeightdel_icn

fmcbdeight_icn.s:
	bin2s INSTALL/FMCBD-1.8C/FMCB.ICN fmcbdeight_icn.s fmcbdeight_icn

fmcbdeight_elf.s:
	bin2s INSTALL/FMCBD-1.8C/FMCBD-1.8C.ELF fmcbdeight_elf.s fmcbdeight_elf

fmcbdeighticon_sys.s:
	bin2s INSTALL/FMCBD-1.8C/ICON.SYS fmcbdeighticon_sys.s fmcbdeighticon_sys

apps_icn.s:
	bin2s INSTALL/APPS/APPS.ICN apps_icn.s apps_icn

appsdel_icn.s:
	bin2s INSTALL/APPS/DEL.ICN appsdel_icn.s appsdel_icn

appsicon_sys.s:
	bin2s INSTALL/APPS/ICON.SYS appsicon_sys.s appsicon_sys

ldrfmcbdcopy_icn.s:
	bin2s INSTALL/FMCBD-1.966/COPY.ICN ldrfmcbdcopy_icn.s ldrfmcbdcopy_icn

ldrfmcbddel_icn.s:
	bin2s INSTALL/FMCBD-1.966/DEL.ICN ldrfmcbddel_icn.s ldrfmcbddel_icn

ldrfmcbdfmcb_icn.s:
	bin2s INSTALL/FMCBD-1.966/FMCB.ICN ldrfmcbdfmcb_icn.s ldrfmcbdfmcb_icn

ldrfmcbdicon_sys.s:
	bin2s INSTALL/FMCBD-1.966/ICON.SYS ldrfmcbdicon_sys.s ldrfmcbdicon_sys

esr_elf.s:
	bin2s INSTALL/BOOT/ESR.ELF esr_elf.s esr_elf

fmcbd_elf.s:
	bin2s INSTALL/FMCBD-1.966/FMCBD-1.966.ELF fmcbd_elf.s fmcbd_elf

boot2_elf.s:
	bin2s INSTALL/BOOT/BOOT2.ELF boot2_elf.s boot2_elf

boot_elf.s:
	bin2s INSTALL/BOOT/BOOT.ELF boot_elf.s boot_elf

icon_sys.s:
	bin2s INSTALL/BOOT/ICON.SYS icon_sys.s icon_sys

copy_icn.s:
	bin2s INSTALL/BOOT/COPY.ICN copy_icn.s copy_icn

del_icn.s:
	bin2s INSTALL/BOOT/DEL.ICN del_icn.s del_icn

boot_icn.s:
	bin2s INSTALL/BOOT/BOOT.ICN boot_icn.s boot_icn

config_ini.s:
	bin2s INSTALL/BOOT/CONFIG.INI config_ini.s config_ini

sysconffmcb_cfg_elf.s:
	bin2s INSTALL/SYS_FMCB-CFG/FMCB-CFG.ELF sysconffmcb_cfg_elf.s sysconffmcb_cfg_elf

title_cfg.s:
	bin2s INSTALL/SYS_FMCB-CFG/TITLE.CFG title_cfg.s title_cfg

fmcbcfgcopy_icn.s:
	bin2s INSTALL/SYS_FMCB-CFG/COPY.ICN fmcbcfgcopy_icn.s fmcbcfgcopy_icn

fmcbcfgdel_icn.s:
	bin2s INSTALL/SYS_FMCB-CFG/DEL.ICN fmcbcfgdel_icn.s fmcbcfgdel_icn

fmcbcfgicon_sys.s:
	bin2s INSTALL/SYS_FMCB-CFG/ICON.SYS fmcbcfgicon_sys.s fmcbcfgicon_sys

fmcbcfglist_icn.s:
	bin2s INSTALL/SYS_FMCB-CFG/LIST.ICN fmcbcfglist_icn.s fmcbcfglist_icn

sysconffreemcb_cnf.s:
	bin2s INSTALL/SYS-CONF/FREEMCB.CNF sysconffreemcb_cnf.s sysconffreemcb_cnf

sysconfipconfig_dat.s:
	bin2s INSTALL/SYS-CONF/IPCONFIG.DAT sysconfipconfig_dat.s sysconfipconfig_dat

sysconflaunchelf_cnf.s:
	bin2s INSTALL/SYS-CONF/LAUNCHELF.CNF sysconflaunchelf_cnf.s sysconflaunchelf_cnf

sysconfps2bbl_ini.s:
	bin2s INSTALL/SYS-CONF/PS2BBL.INI sysconfps2bbl_ini.s sysconfps2bbl_ini

sysconfusbd_irx.s:
	bin2s INSTALL/SYS-CONF/USBD.IRX sysconfusbd_irx.s sysconfusbd_irx

sysconfusbhdfsd_irx.s:
	bin2s INSTALL/SYS-CONF/USBHDFSD.IRX sysconfusbhdfsd_irx.s sysconfusbhdfsd_irx

sysconfcopy_icn.s:
	bin2s INSTALL/SYS-CONF/COPY.ICN sysconfcopy_icn.s sysconfcopy_icn

sysconfdel_icn.s:
	bin2s INSTALL/SYS-CONF/DEL.ICN sysconfdel_icn.s sysconfdel_icn

sysconfendvdpl_irx.s:
	bin2s INSTALL/SYS-CONF/ENDVDPL.IRX sysconfendvdpl_irx.s sysconfendvdpl_irx

sysconficon_sys.s:
	bin2s INSTALL/SYS-CONF/ICON.SYS sysconficon_sys.s sysconficon_sys

sysconfsysconf_icn.s:
	bin2s INSTALL/SYS-CONF/SYSCONF.ICN sysconfsysconf_icn.s sysconfsysconf_icn

OpenTuna_sys.s:
	bin2s INSTALL/OPENTUNA/icon.sys OpenTuna_sys.s opentuna_sys

OpenTuna_SLIMS.s:
	bin2s INSTALL/OPENTUNA/OpenTuna_Slims.bin OpenTuna_SLIMS.s opentuna_slims

OpenTuna_FAT-110-120-150-160.s:
	bin2s INSTALL/OPENTUNA/OpenTuna_FAT-110-120-150-160.bin OpenTuna_FAT-110-120-150-160.s opentuna_fats

OpenTuna_FAT-170.s:
	bin2s INSTALL/OPENTUNA/OpenTuna_FAT-170.bin OpenTuna_FAT-170.s opentuna_fat170

SIO2MAN_irx.c: $(PS2SDK)/iop/irx/freesio2.irx
	bin2c $(PS2SDK)/iop/irx/freesio2.irx SIO2MAN_irx.c SIO2MAN_irx

MCMAN_irx.c: $(PS2SDK)/iop/irx/mcman.irx
	bin2c $(PS2SDK)/iop/irx/mcman.irx MCMAN_irx.c MCMAN_irx

MCSERV_irx.c: $(PS2SDK)/iop/irx/mcserv.irx
	bin2c $(PS2SDK)/iop/irx/mcserv.irx MCSERV_irx.c MCSERV_irx

PADMAN_irx.c: $(PS2SDK)/iop/irx/freepad.irx
	bin2c $(PS2SDK)/iop/irx/freepad.irx PADMAN_irx.c PADMAN_irx

clean:
	rm -fr $(EE_OBJS) $(EE_BIN_PACKED) $(EE_BIN_STRIPPED) $(EE_BIN) $(EE_SRC)

$(EE_BIN_STRIPPED): $(EE_BIN)
	$(EE_STRIP) -o $@ $<

$(EE_BIN_PACKED): $(EE_BIN_STRIPPED)
	ps2-packer $< $@ > /dev/null

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
