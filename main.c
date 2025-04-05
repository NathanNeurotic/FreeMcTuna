//#define __DEBUG_PRINTF__
#ifdef __DEBUG_PRINTF__
#define PRINTF(arg...) printf(arg...)
#else
#define PRINTF(arg...)
#endif
/*------------------------------------------------------------*/
#include "main.h"
#include "BMP/complete.h"
#include "BMP/error.h"
#include "BMP/wait.h"
#include "BMP/MensajeA.h"
#include "BMP/MensajeB.h"
#include "BMP/MensajeC.h"
#include "BMP/MensajeD.h"
#include "BMP/MensajeE.h"
#include "BMP/MensajeF.h"
#include "BMP/NON_COMPATIBLE.h"
#include "BMP/INST_SLOT_2.h"
#include "BMP/INST_SLOT_1.h"

enum ICN
{
	SLIMS = 0,	  // fat 0x190 and every 0x2?? ROM
	FATS,		  // 0x110, 0x120, 0x150, 0x160
	FAT170,		  // 0x170
	PROTOKERNELS, // this corresponds to rom 0x100 and 0x101, parrado won´t make the icons, but i will leavi it here in case someone makes it faster than instatuna
	UNSUPPORTED,
};

char* ICONTYPE_ALIAS[4] = {"190+","110+","170 ","100 "};
char* ICONFILE_NAMES[4] = {"slims","fats","fat170","protok"};

enum STATE
{
	STATE_MC0,
	STATE_MC1,
	STATE_INSTALL,
	STATE_FINISH,
	STATE_ERROR,
	STATE_BROWSER,
	STATE_UNSUPPORTED,
};

int GetIconType(unsigned long int ROMVERSION)
{
	int icontype = UNSUPPORTED;

	if (ROMVERSION >= 0x190)
		icontype = SLIMS;

	if ((ROMVERSION < 0x190) && (ROMVERSION >= 0x110))
		icontype = FATS;

	if (ROMVERSION == 0x170)
		icontype = FAT170;

	return icontype;
}
//----------------------------------------//
extern u8 BOOT_BOOT_ELF[];
extern int size_BOOT_BOOT_ELF;
//----------------------------------------//
extern u8 BOOT_BOOT_ICN[];
extern int size_BOOT_BOOT_ICN;
//----------------------------------------//
extern u8 BOOT_BOOT2_ELF[];
extern int size_BOOT_BOOT2_ELF;
//----------------------------------------//
extern u8 BOOT_CONFIG_INI[];
extern int size_BOOT_CONFIG_INI;
//----------------------------------------//
extern u8 BOOT_COPY_ICN[];
extern int size_BOOT_COPY_ICN;
//----------------------------------------//
extern u8 BOOT_DEL_ICN[];
extern int size_BOOT_DEL_ICN;
//----------------------------------------//
extern u8 BOOT_ESR_ELF[];
extern int size_BOOT_ESR_ELF;
//----------------------------------------//
extern u8 BOOT_ICON_SYS[];
extern int size_BOOT_ICON_SYS;
//----------------------------------------//
extern u8 FMCBD_1_953_COPY_ICN[];
extern int size_FMCBD_1_953_COPY_ICN;
//----------------------------------------//
extern u8 FMCBD_1_953_DEL_ICN[];
extern int size_FMCBD_1_953_DEL_ICN;
//----------------------------------------//
extern u8 FMCBD_1_953_FMCB_ICN[];
extern int size_FMCBD_1_953_FMCB_ICN;
//----------------------------------------//
extern u8 FMCBD_1_953_FMCBD_1_953_ELF[];
extern int size_FMCBD_1_953_FMCBD_1_953_ELF;
//----------------------------------------//
extern u8 FMCBD_1_953_ICON_SYS[];
extern int size_FMCBD_1_953_ICON_SYS;
//----------------------------------------//
extern u8 FMCBD_1_966_COPY_ICN[];
extern int size_FMCBD_1_966_COPY_ICN;
//----------------------------------------//
extern u8 FMCBD_1_966_DEL_ICN[];
extern int size_FMCBD_1_966_DEL_ICN;
//----------------------------------------//
extern u8 FMCBD_1_966_FMCB_ICN[];
extern int size_FMCBD_1_966_FMCB_ICN;
//----------------------------------------//
extern u8 FMCBD_1_966_FMCBD_1_966_ELF[];
extern int size_FMCBD_1_966_FMCBD_1_966_ELF;
//----------------------------------------//
extern u8 FMCBD_1_966_ICON_SYS[];
extern int size_FMCBD_1_966_ICON_SYS;
//----------------------------------------//
extern u8 OPENTUNA_icon_sys[];
extern int size_OPENTUNA_icon_sys;
//----------------------------------------//
extern u8 OSDMENU_COPY_ICN[];
extern int size_OSDMENU_COPY_ICN;
//----------------------------------------//
extern u8 OSDMENU_DEL_ICN[];
extern int size_OSDMENU_DEL_ICN;
//----------------------------------------//
extern u8 OSDMENU_ICON_SYS[];
extern int size_OSDMENU_ICON_SYS;
//----------------------------------------//
extern u8 OSDMENU_LAUNCHER_ELF[];
extern int size_OSDMENU_LAUNCHER_ELF;
//----------------------------------------//
extern u8 OSDMENU_LIST_ICN[];
extern int size_OSDMENU_LIST_ICN;
//----------------------------------------//
extern u8 OSDMENU_OSDMENU_CNF[];
extern int size_OSDMENU_OSDMENU_CNF;
//----------------------------------------//
extern u8 OSDMENU_OSDMENU_ELF[];
extern int size_OSDMENU_OSDMENU_ELF;
//----------------------------------------//
extern u8 OSDMENU_PATCHER_ELF[];
extern int size_OSDMENU_PATCHER_ELF;
//----------------------------------------//
extern u8 POPSTARTER_DEL_ICN[];
extern int size_POPSTARTER_DEL_ICN;
//----------------------------------------//
extern u8 POPSTARTER_ICON_SYS[];
extern int size_POPSTARTER_ICON_SYS;
//----------------------------------------//
extern u8 POPSTARTER_IPCONFIG_DAT[];
extern int size_POPSTARTER_IPCONFIG_DAT;
//----------------------------------------//
extern u8 POPSTARTER_LIST_ICN[];
extern int size_POPSTARTER_LIST_ICN;
//----------------------------------------//
extern u8 POPSTARTER_POWEROFF_IRX[];
extern int size_POPSTARTER_POWEROFF_IRX;
//----------------------------------------//
extern u8 POPSTARTER_PS2DEV9_IRX[];
extern int size_POPSTARTER_PS2DEV9_IRX;
//----------------------------------------//
extern u8 POPSTARTER_PS2IP_IRX[];
extern int size_POPSTARTER_PS2IP_IRX;
//----------------------------------------//
extern u8 POPSTARTER_PS2SMAP_IRX[];
extern int size_POPSTARTER_PS2SMAP_IRX;
//----------------------------------------//
extern u8 POPSTARTER_SMBCONFIG_DAT[];
extern int size_POPSTARTER_SMBCONFIG_DAT;
//----------------------------------------//
extern u8 POPSTARTER_SMBMAN_IRX[];
extern int size_POPSTARTER_SMBMAN_IRX;
//----------------------------------------//
extern u8 POPSTARTER_SMSUTILS_IRX[];
extern int size_POPSTARTER_SMSUTILS_IRX;
//----------------------------------------//
extern u8 POPSTARTER_USBD_IRX[];
extern int size_POPSTARTER_USBD_IRX;
//----------------------------------------//
extern u8 POPSTARTER_USBHDFSD_IRX[];
extern int size_POPSTARTER_USBHDFSD_IRX;
//----------------------------------------//
extern u8 POWEROFF_DEL_ICN[];
extern int size_POWEROFF_DEL_ICN;
//----------------------------------------//
extern u8 POWEROFF_ICON_SYS[];
extern int size_POWEROFF_ICON_SYS;
//----------------------------------------//
extern u8 POWEROFF_LIST_ICN[];
extern int size_POWEROFF_LIST_ICN;
//----------------------------------------//
extern u8 POWEROFF_POWEROFF_ELF[];
extern int size_POWEROFF_POWEROFF_ELF;
//----------------------------------------//
extern u8 PS1_DKWDRV_COPY_ICN[];
extern int size_PS1_DKWDRV_COPY_ICN;
//----------------------------------------//
extern u8 PS1_DKWDRV_DEL_ICN[];
extern int size_PS1_DKWDRV_DEL_ICN;
//----------------------------------------//
extern u8 PS1_DKWDRV_DKWDRV_ELF[];
extern int size_PS1_DKWDRV_DKWDRV_ELF;
//----------------------------------------//
extern u8 PS1_DKWDRV_ICON_SYS[];
extern int size_PS1_DKWDRV_ICON_SYS;
//----------------------------------------//
extern u8 PS1_DKWDRV_LIST_ICN[];
extern int size_PS1_DKWDRV_LIST_ICN;
//----------------------------------------//
extern u8 PS1_DKWDRV_TITLE_CFG[];
extern int size_PS1_DKWDRV_TITLE_CFG;
//----------------------------------------//
extern u8 SYS_CONF_COPY_ICN[];
extern int size_SYS_CONF_COPY_ICN;
//----------------------------------------//
extern u8 SYS_CONF_DEL_ICN[];
extern int size_SYS_CONF_DEL_ICN;
//----------------------------------------//
extern u8 SYS_CONF_ENDVDPL_IRX[];
extern int size_SYS_CONF_ENDVDPL_IRX;
//----------------------------------------//
extern u8 SYS_CONF_FREEMCB_CNF[];
extern int size_SYS_CONF_FREEMCB_CNF;
//----------------------------------------//
extern u8 SYS_CONF_ICON_SYS[];
extern int size_SYS_CONF_ICON_SYS;
//----------------------------------------//
extern u8 SYS_CONF_IPCONFIG_DAT[];
extern int size_SYS_CONF_IPCONFIG_DAT;
//----------------------------------------//
extern u8 SYS_CONF_LAUNCHELF_CNF[];
extern int size_SYS_CONF_LAUNCHELF_CNF;
//----------------------------------------//
extern u8 SYS_CONF_PS2BBL_INI[];
extern int size_SYS_CONF_PS2BBL_INI;
//----------------------------------------//
extern u8 SYS_CONF_PSXBBL_INI[];
extern int size_SYS_CONF_PSXBBL_INI;
//----------------------------------------//
extern u8 SYS_CONF_SYSCONF_ICN[];
extern int size_SYS_CONF_SYSCONF_ICN;
//----------------------------------------//
extern u8 SYS_CONF_USBD_IRX[];
extern int size_SYS_CONF_USBD_IRX;
//----------------------------------------//
extern u8 SYS_CONF_USBHDFSD_IRX[];
extern int size_SYS_CONF_USBHDFSD_IRX;
//----------------------------------------//
extern u8 SYS_FMCB_CFG_COPY_ICN[];
extern int size_SYS_FMCB_CFG_COPY_ICN;
//----------------------------------------//
extern u8 SYS_FMCB_CFG_DEL_ICN[];
extern int size_SYS_FMCB_CFG_DEL_ICN;
//----------------------------------------//
extern u8 SYS_FMCB_CFG_FMCB_CFG_ELF[];
extern int size_SYS_FMCB_CFG_FMCB_CFG_ELF;
//----------------------------------------//
extern u8 SYS_FMCB_CFG_ICON_SYS[];
extern int size_SYS_FMCB_CFG_ICON_SYS;
//----------------------------------------//
extern u8 SYS_FMCB_CFG_LIST_ICN[];
extern int size_SYS_FMCB_CFG_LIST_ICN;
//----------------------------------------//
extern u8 SYS_FMCB_CFG_TITLE_CFG[];
extern int size_SYS_FMCB_CFG_TITLE_CFG;
//----------------------------------------//
extern u8 opentuna_slims[];
extern int size_opentuna_slims;
//----------------------------------------//
extern u8 opentuna_fats[];
extern int size_opentuna_fats;
//----------------------------------------//
extern u8 opentuna_fat170[];
extern int size_opentuna_fat170;
//----------------------------------------//
extern u8 opentuna_sys[];
extern int size_opentuna_sys;
//----------------------------------------//

// Embedded IOP drivers
extern unsigned char SIO2MAN_irx[];
extern unsigned int size_SIO2MAN_irx;

extern unsigned char PADMAN_irx[];
extern unsigned int size_PADMAN_irx;

extern unsigned char MCMAN_irx[];
extern unsigned int size_MCMAN_irx;

extern unsigned char MCSERV_irx[];
extern unsigned int size_MCSERV_irx;

static int pad_inited = 0;

//--------------------------------------------------------------
static int file_exists(char *filepath)
{
	int fdn;

	fdn = open(filepath, O_RDONLY);
	if (fdn < 0)
		return 0;

	close(fdn);

	return 1;
}

//--------------------------------------------------------------
static void Reset_IOP(void)
{
	//parrado
	SifInitRpc(0);
	while (!SifIopReset("", 0))
	{
	};
	while (!SifIopSync())
	{
	};
	SifInitRpc(0);
}
//=============================================================
static void display_bmp(u16 W, u16 H, u32 *data)
{
	gs_print_bitmap(
		(gs_get_max_x() - W) / 2, //x
		(gs_get_max_y() - H) / 2, //y
		W,						  //w
		H,						  //h
		data					  //array
	);

	PRINTF("array displayed\n");
}
//=============================================================
/// DeleteFolder(); function was obtained from SP193's FreeMcBoot installer.
//thanks to SP193 for all his work
static int DeleteFolder(const char *folder)
{
	DIR *d = opendir(folder);
	size_t path_len = strlen(folder);
	int r = -1;

	if (d)
	{
		//scr_printf("Detected [%s], deleting...\n",folder);
		struct dirent *p;

		r = 0;
		while (!r && (p = readdir(d)))
		{
			int r2 = -1;
			char *buf;
			size_t len;

			/* Skip the names "." and ".." as we don't want to recurse on them. */
			if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
				continue;

			len = path_len + strlen(p->d_name) + 2;
			buf = malloc(len);

			if (buf)
			{
				struct stat statbuf;

				snprintf(buf, len, "%s/%s", folder, p->d_name);
				if (!stat(buf, &statbuf))
				{
					if (S_ISDIR(statbuf.st_mode))
						r2 = DeleteFolder(buf);
					else
						r2 = unlink(buf);
				}
				free(buf);
			}
			r = r2;
		}
		closedir(d);
	}

	if (!r)
		r = rmdir(folder);

	return r;
}
//=============================================================
static void InitPS2(void)
{
	Reset_IOP();
	SifInitIopHeap();
	SifLoadFileInit();
	fioInit();

	sbv_patch_enable_lmb();
	sbv_patch_disable_prefix_check();
	SifExecModuleBuffer(SIO2MAN_irx, size_SIO2MAN_irx, 0, NULL, NULL);
	SifExecModuleBuffer(PADMAN_irx, size_PADMAN_irx, 0, NULL, NULL);
	SifExecModuleBuffer(MCMAN_irx, size_MCMAN_irx, 0, NULL, NULL);
	SifExecModuleBuffer(MCSERV_irx, size_MCSERV_irx, 0, NULL, NULL);
    sbv_patch_fileio();// THANKS fjtrujy
	mcInit(MC_TYPE_XMC);
	PadInitPads();
}

//write &embed_file to path
// returns:
// -1 fail to open | -2 failed to write | 0 succes
static int write_embed(void *embed_file, const int embed_size, char *folder, char *filename, int mcport)
{
	char target[MAX_PATH];
	sprintf(target, "mc%d:/%s/%s", mcport, folder, filename);
	if (open(target, O_RDONLY) < 0) //if not exist
	{
		int ret, fd;
		if ((fd = open(target, O_CREAT | O_WRONLY | O_TRUNC)) < 0)
		{
			return -1;
		}
		ret = write(fd, embed_file, embed_size);
		if (ret != embed_size)
		{
			return -2;
		}
		close(fd);
	}

	PRINTF("embed file written: %s\n", target);
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//return 0 = ok, return 1 = error
static int install(int mcport, int icon_variant)
{
	char version_manifest_path[64];
    char temp_path[32];
	int ret, retorno,fd;
	static int mc_Type, mc_Free, mc_Format;
	
	sprintf(version_manifest_path, "mc%d:/OPENTUNA/icon_%s.cnf",mcport,ICONFILE_NAMES[icon_variant]);

	mcGetInfo(mcport, 0, &mc_Type, &mc_Free, &mc_Format);
	mcSync(0, NULL, &ret);
	PRINTF("mc_Type: %d\n", mc_Type);

	//If there's no MC, we have an error:
	if (ret != -1)
	{
		return 1;
	}

	//If it is not a PS2 MC, we have an error:
	if (mc_Type != sceMcTypePS2)
	{
		return 2;
	}

	//If there's no free space, we have an error:
	if (mc_Free < 20)
	{
		return 3;
	}
   sprintf(temp_path,"mc%u:BOOT", mcport);
	   DeleteFolder(temp_path);
   sprintf(temp_path,"mc%u:LDR_FMCBD-1.966", mcport);
	   DeleteFolder(temp_path);
   sprintf(temp_path,"mc%u:SYS_FMCBCFG", mcport);
	   DeleteFolder(temp_path);
   sprintf(temp_path,"mc%u:SYS_FMCB-CFG", mcport);
	   DeleteFolder(temp_path);
    sprintf(temp_path,"mc%u:FORTUNA", mcport);
		DeleteFolder(temp_path);
	sprintf(temp_path,"mc%u:OPENTUNA", mcport);
		DeleteFolder(temp_path);
sprintf(temp_path, "mc%u:SYS-CONF", mcport);
DeleteFolder(temp_path);
sprintf(temp_path, "mc%u:FUNTUNA-FORK", mcport);
DeleteFolder(temp_path);
sprintf(temp_path, "mc%u:BXEXEC-FUNTUNA", mcport);
DeleteFolder(temp_path);
sprintf(temp_path, "mc%u:FUNTUNA", mcport);
DeleteFolder(temp_path);
sprintf(temp_path, "mc%u:BXEXEC-OPENTUNA", mcport);
DeleteFolder(temp_path);
    
	//If the files exists, we have an error:
	if (mcport == 0)
	{
		if (file_exists("mc0:/OPENTUNA/icon.icn"))
		{
			return 4;
		}
		if (file_exists("mc0:/OPENTUNA/icon.sys"))
		{
			return 4;
		}
	}
	else
	{
		if (file_exists("mc1:/OPENTUNA/icon.icn"))
		{
			return 4;
		}
		if (file_exists("mc1:/OPENTUNA/icon.sys"))
		{
			return 4;
		}
	}
	ret = mcMkDir(mcport, 0, "OPENTUNA");
	mcSync(0, NULL, &ret);
	ret = mcMkDir(mcport, 0, "SYS-CONF");
	mcSync(0, NULL, &ret);

	retorno = -12; ///to ensure installation quits if none of the hacked icons are written
	if (icon_variant == SLIMS)
	{
		retorno = write_embed(&opentuna_slims, size_opentuna_slims, "OPENTUNA", "icon.icn", mcport);
	}
	else if (icon_variant == FATS)
	{
		retorno = write_embed(&opentuna_fats, size_opentuna_fats, "OPENTUNA", "icon.icn", mcport);
	}
	else if (icon_variant == FAT170)
	{
		retorno = write_embed(&opentuna_fat170, size_opentuna_fat170, "OPENTUNA", "icon.icn", mcport);
	}
	if (retorno < 0)
	{
		return 6;
	}
	// <FILES SHARED BY ALL ICONS FROM NOW ON>
	retorno = write_embed(&opentuna_sys, size_opentuna_sys, "OPENTUNA", "icon.sys", mcport);
	if (retorno < 0)
	{
		return 6;
	}
	if ((fd = open(version_manifest_path, O_CREAT | O_WRONLY | O_TRUNC)) >= 0){

	ret = write(fd, ICONTYPE_ALIAS[icon_variant], 4);//This will allow identifying the hacked icon variant without risking your mc contents
	close(fd);
	}
    retorno = write_embed(&BOOT_BOOT_ELF, size_BOOT_BOOT_ELF, "BOOT", "BOOT.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_BOOT_ICN, size_BOOT_BOOT_ICN, "BOOT", "BOOT.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_BOOT2_ELF, size_BOOT_BOOT2_ELF, "BOOT", "BOOT2.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_CONFIG_INI, size_BOOT_CONFIG_INI, "BOOT", "CONFIG.INI", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_COPY_ICN, size_BOOT_COPY_ICN, "BOOT", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_DEL_ICN, size_BOOT_DEL_ICN, "BOOT", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_ESR_ELF, size_BOOT_ESR_ELF, "BOOT", "ESR.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&BOOT_ICON_SYS, size_BOOT_ICON_SYS, "BOOT", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_953_COPY_ICN, size_FMCBD_1_953_COPY_ICN, "FMCBD-1.953", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_953_DEL_ICN, size_FMCBD_1_953_DEL_ICN, "FMCBD-1.953", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_953_FMCB_ICN, size_FMCBD_1_953_FMCB_ICN, "FMCBD-1.953", "FMCB.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_953_FMCBD_1_953_ELF, size_FMCBD_1_953_FMCBD_1_953_ELF, "FMCBD-1.953", "FMCBD-1.953.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_953_ICON_SYS, size_FMCBD_1_953_ICON_SYS, "FMCBD-1.953", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_966_COPY_ICN, size_FMCBD_1_966_COPY_ICN, "FMCBD-1.966", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_966_DEL_ICN, size_FMCBD_1_966_DEL_ICN, "FMCBD-1.966", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_966_FMCB_ICN, size_FMCBD_1_966_FMCB_ICN, "FMCBD-1.966", "FMCB.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_966_FMCBD_1_966_ELF, size_FMCBD_1_966_FMCBD_1_966_ELF, "FMCBD-1.966", "FMCBD-1.966.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&FMCBD_1_966_ICON_SYS, size_FMCBD_1_966_ICON_SYS, "FMCBD-1.966", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_COPY_ICN, size_OSDMENU_COPY_ICN, "OSDMENU", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_DEL_ICN, size_OSDMENU_DEL_ICN, "OSDMENU", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_ICON_SYS, size_OSDMENU_ICON_SYS, "OSDMENU", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_LAUNCHER_ELF, size_OSDMENU_LAUNCHER_ELF, "OSDMENU", "launcher.elf", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_LIST_ICN, size_OSDMENU_LIST_ICN, "OSDMENU", "list.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_OSDMENU_CNF, size_OSDMENU_OSDMENU_CNF, "OSDMENU", "OSDMENU.CNF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_OSDMENU_ELF, size_OSDMENU_OSDMENU_ELF, "OSDMENU", "OSDMENU.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&OSDMENU_PATCHER_ELF, size_OSDMENU_PATCHER_ELF, "OSDMENU", "patcher.elf", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_DEL_ICN, size_POPSTARTER_DEL_ICN, "POPSTARTER", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_ICON_SYS, size_POPSTARTER_ICON_SYS, "POPSTARTER", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_IPCONFIG_DAT, size_POPSTARTER_IPCONFIG_DAT, "POPSTARTER", "IPCONFIG.DAT", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_LIST_ICN, size_POPSTARTER_LIST_ICN, "POPSTARTER", "list.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_POWEROFF_IRX, size_POPSTARTER_POWEROFF_IRX, "POPSTARTER", "poweroff.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_PS2DEV9_IRX, size_POPSTARTER_PS2DEV9_IRX, "POPSTARTER", "ps2dev9.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_PS2IP_IRX, size_POPSTARTER_PS2IP_IRX, "POPSTARTER", "ps2ip.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_PS2SMAP_IRX, size_POPSTARTER_PS2SMAP_IRX, "POPSTARTER", "ps2smap.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_SMBCONFIG_DAT, size_POPSTARTER_SMBCONFIG_DAT, "POPSTARTER", "SMBCONFIG.DAT", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_SMBMAN_IRX, size_POPSTARTER_SMBMAN_IRX, "POPSTARTER", "smbman.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_SMSUTILS_IRX, size_POPSTARTER_SMSUTILS_IRX, "POPSTARTER", "SMSUTILS.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_USBD_IRX, size_POPSTARTER_USBD_IRX, "POPSTARTER", "usbd.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POPSTARTER_USBHDFSD_IRX, size_POPSTARTER_USBHDFSD_IRX, "POPSTARTER", "usbhdfsd.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POWEROFF_DEL_ICN, size_POWEROFF_DEL_ICN, "POWEROFF", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POWEROFF_ICON_SYS, size_POWEROFF_ICON_SYS, "POWEROFF", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POWEROFF_LIST_ICN, size_POWEROFF_LIST_ICN, "POWEROFF", "list.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&POWEROFF_POWEROFF_ELF, size_POWEROFF_POWEROFF_ELF, "POWEROFF", "POWEROFF.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&PS1_DKWDRV_COPY_ICN, size_PS1_DKWDRV_COPY_ICN, "PS1_DKWDRV", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&PS1_DKWDRV_DEL_ICN, size_PS1_DKWDRV_DEL_ICN, "PS1_DKWDRV", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&PS1_DKWDRV_DKWDRV_ELF, size_PS1_DKWDRV_DKWDRV_ELF, "PS1_DKWDRV", "DKWDRV.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&PS1_DKWDRV_ICON_SYS, size_PS1_DKWDRV_ICON_SYS, "PS1_DKWDRV", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&PS1_DKWDRV_LIST_ICN, size_PS1_DKWDRV_LIST_ICN, "PS1_DKWDRV", "list.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&PS1_DKWDRV_TITLE_CFG, size_PS1_DKWDRV_TITLE_CFG, "PS1_DKWDRV", "title.cfg", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_COPY_ICN, size_SYS_CONF_COPY_ICN, "SYS-CONF", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_DEL_ICN, size_SYS_CONF_DEL_ICN, "SYS-CONF", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_ENDVDPL_IRX, size_SYS_CONF_ENDVDPL_IRX, "SYS-CONF", "endvdpl.irx", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_FREEMCB_CNF, size_SYS_CONF_FREEMCB_CNF, "SYS-CONF", "FREEMCB.CNF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_ICON_SYS, size_SYS_CONF_ICON_SYS, "SYS-CONF", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_IPCONFIG_DAT, size_SYS_CONF_IPCONFIG_DAT, "SYS-CONF", "IPCONFIG.DAT", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_LAUNCHELF_CNF, size_SYS_CONF_LAUNCHELF_CNF, "SYS-CONF", "LAUNCHELF.CNF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_PS2BBL_INI, size_SYS_CONF_PS2BBL_INI, "SYS-CONF", "PS2BBL.INI", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_PSXBBL_INI, size_SYS_CONF_PSXBBL_INI, "SYS-CONF", "PSXBBL.INI", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_SYSCONF_ICN, size_SYS_CONF_SYSCONF_ICN, "SYS-CONF", "sysconf.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_USBD_IRX, size_SYS_CONF_USBD_IRX, "SYS-CONF", "USBD.IRX", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_CONF_USBHDFSD_IRX, size_SYS_CONF_USBHDFSD_IRX, "SYS-CONF", "USBHDFSD.IRX", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_FMCB_CFG_COPY_ICN, size_SYS_FMCB_CFG_COPY_ICN, "SYS_FMCB-CFG", "copy.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_FMCB_CFG_DEL_ICN, size_SYS_FMCB_CFG_DEL_ICN, "SYS_FMCB-CFG", "del.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_FMCB_CFG_FMCB_CFG_ELF, size_SYS_FMCB_CFG_FMCB_CFG_ELF, "SYS_FMCB-CFG", "FMCB-CFG.ELF", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_FMCB_CFG_ICON_SYS, size_SYS_FMCB_CFG_ICON_SYS, "SYS_FMCB-CFG", "icon.sys", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_FMCB_CFG_LIST_ICN, size_SYS_FMCB_CFG_LIST_ICN, "SYS_FMCB-CFG", "list.icn", mcport);
if (retorno < 0)
{
    return 6;
}
retorno = write_embed(&SYS_FMCB_CFG_TITLE_CFG, size_SYS_FMCB_CFG_TITLE_CFG, "SYS_FMCB-CFG", "title.cfg", mcport);
if (retorno < 0)
{
    return 6;
}

	PRINTF("installation finished\n");

	static sceMcTblGetDir mcDirAAA[64] __attribute__((aligned(64)));
	static sceMcStDateTime maximahora; //Maxium Timestamp, for the ones who does not speak Spanish

	maximahora.Resv2 = 0;
	maximahora.Sec = 59;
	maximahora.Min = 59;
	maximahora.Hour = 23;
	maximahora.Day = 31;
	maximahora.Month = 12;
	maximahora.Year = 2099;
	mcDirAAA->_Modify = maximahora;
	mcDirAAA->_Create = maximahora;
	mcSetFileInfo(mcport, 0, "OPENTUNA", mcDirAAA, 0x02);
	mcSync(0, NULL, &ret);

	PRINTF("timestamp changed\n");

	return 0;
}
//--------------------------------------------------------------

static void CleanUp(void) //trimmed from FMCB
{
	if (pad_inited)
	{
		padPortClose(0, 0);
		padPortClose(1, 0);
		padEnd();
	}

	Reset_IOP();

	// Reloads common modules
	SifLoadFileInit();
	sbv_patch_enable_lmb();
	sbv_patch_disable_prefix_check();

	SifLoadModule("rom0:SIO2MAN", 0, 0);
	SifLoadModule("rom0:CDVDFSV", 0, 0);
	SifLoadModule("rom0:CDVDMAN", 0, 0);
	SifLoadModule("rom0:MCMAN", 0, 0);
	SifLoadModule("rom0:MCSERV", 0, 0);
	SifLoadModule("rom0:PADMAN", 0, 0);

	fioExit();
	SifExitIopHeap();
	SifLoadFileExit();
	SifExitRpc();
	SifExitCmd();

	FlushCache(0);
	FlushCache(2);

	// clear the screen
	gs_set_fill_color(0, 0, 0);
	gs_fill_rect(0, 0, gs_get_max_x(), gs_get_max_y());
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//close program and go to browser
static void PS2_browser(void)
{
	CleanUp();
	LoadExecPS2("rom0:OSDSYS", 0, NULL);
}

void error_message(int iz)
{
	display_bmp(640, 448, error);
	switch (iz)
	{
	case 1:
		gs_print_bitmap(192, 343, 256, 40, MensajeA);
		break;
	case 2:
		gs_print_bitmap(192, 343, 256, 40, MensajeB);
		break;
	case 3:
		gs_print_bitmap(192, 343, 256, 40, MensajeC);
		break;
	case 4:
		gs_print_bitmap(192, 343, 256, 40, MensajeD);
		break;
	case 5:
		gs_print_bitmap(192, 343, 256, 40, MensajeE);
		break;
	case 6:
		gs_print_bitmap(192, 343, 256, 40, MensajeF);
		break;
	default:
		break;
	}
}

int wait_key(int key)
{
	while (1)
	{
		int new_pad = ReadCombinedPadStatus();
		if (new_pad & key)
			return new_pad;
	}
}

int main(int argc, char *argv[])
{
	int fdn, icontype;
	unsigned long int ROM_VERSION = 0x170;
	VMode = NTSC;
	int mcport, state;
	int key;

	// Loads Needed modules
	InitPS2();

	gs_reset();									   // Reset GS
	if ((fdn = open("rom0:ROMVER", O_RDONLY)) > 0) // Reading ROMVER
	{
		char romver[5];
		read(fdn, romver, 4);
		close(fdn);

		if (romver[4] == 'E')
			VMode = PAL;
		romver[4] = '\0';
		ROM_VERSION = strtoul(romver, NULL, 16); //convert ROM version to unsigned long int for further use on automatic Install
	}

	if (VMode == PAL)
		gs_init(PAL_640_512_32);
	else
		gs_init(NTSC_640_448_32);

	pad_inited = 1;
	icontype = GetIconType(ROM_VERSION);
	int iz = 0;

	if (icontype != UNSUPPORTED)
		state = STATE_MC0;
	else
		state = STATE_UNSUPPORTED;

	//Main menu rendering through Finite State Machine
	while (1)
	{

		switch (state)
		{
		case STATE_MC0:
			mcport = 0;
			display_bmp(640, 448, INST_SLOT_1);

			key = wait_key(-1);

			if ((key & PAD_CROSS) || (key & PAD_CIRCLE))
			{
				state = STATE_INSTALL;
				break;
			}

			if ((key & PAD_SELECT) || (key & PAD_L1))
			{
				state = STATE_MC1;
				break;
			}

			state = STATE_BROWSER;

			break;

		case STATE_MC1:
			mcport = 1;
			display_bmp(640, 448, INST_SLOT_2);

			key = wait_key(-1);

			if ((key & PAD_CROSS) || (key & PAD_CIRCLE))
			{
				state = STATE_INSTALL;
				break;
			}

			if ((key & PAD_SELECT) || (key & PAD_L1))
			{
				state = STATE_MC0;
				break;
			}

			state = STATE_BROWSER;

			break;

		case STATE_UNSUPPORTED:

			display_bmp(640, 448, NON_COMPATIBLE);
			key = wait_key(PAD_START);
			state = STATE_BROWSER;

			break;

		case STATE_INSTALL:
			display_bmp(640, 448, wait);
			iz = install(mcport, icontype);

			if (iz)
				state = STATE_ERROR;
			else
				state = STATE_FINISH;

			break;

		case STATE_FINISH:
			display_bmp(640, 448, complete);
			key = wait_key(PAD_START);
			state = STATE_BROWSER;

			break;
		case STATE_ERROR:
			error_message(iz);
			key = wait_key(PAD_START);

			state = STATE_BROWSER;

		case STATE_BROWSER:
			PS2_browser();
			break;

		default:
			break;
		}
	}

	return 0;
}
