/*----------------------------------------------------------------------*/
/*                                                                      */
/*      NES Mapeers                                                     */
/*                                                           Norix      */
/*                                               written     2000/02/05 */
/*                                               last modify ----/--/-- */
/*----------------------------------------------------------------------*/
/*--------------[ INCLUDE               ]-------------------------------*/
#define	WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "DebugOut.h"
#include "typedef.h"
#include "macro.h"

#include "nes.h"
#include "mmu.h"

#include "mapper.h"

#include <string.h>
const BOARDINFO BoardInfo[]=
{
	{ "ACCLAIM-AOROM",               STD_AOROM                },
	{ "ACCLAIM-MC-ACC",              STD_TLROM                },
	{ "ACCLAIM-TLROM",               STD_TLROM                },
	{ "AGCI-47516",                  DISCRETE_74_377          },
	{ "AGCI-50282",                  AGCI_50282               },
	{ "AVE-74*161",                  UNL_CXROM                },
	{ "AVE-MB-91",                   AVE_MB_91                },
	{ "AVE-NINA-01",                 AVE_NINA001              },
	{ "AVE-NINA-02",                 AVE_NINA002              },
	{ "AVE-NINA-03",                 AVE_NINA03               },
	{ "AVE-NINA-06",                 AVE_NINA06               },
	{ "AVE-NINA-07",                 AVE_NINA07               },
	{ "BANDAI-74*161/161/32",        DISCRETE_74_161_161_32_A },
	{ "BANDAI-CNROM",                STD_CNROM                },
	{ "BANDAI-FCG-1",                BANDAI_FCG1              },
	{ "BANDAI-FCG-2",                BANDAI_FCG2              },
	{ "BANDAI-GNROM",                STD_GNROM                },
	{ "BANDAI-JUMP2",                BANDAI_BAJUMP2           },
	{ "BANDAI-LZ93D50+24C01",        BANDAI_LZ93D50_24C01     },
	{ "BANDAI-LZ93D50+24C02",        BANDAI_LZ93D50_24C02     },
	{ "BANDAI-NROM-128",             STD_NROM                 },
	{ "BANDAI-NROM-256",             STD_NROM                 },
	{ "BANDAI-PT-554",               BANDAI_AEROBICSSTUDIO    },
	{ "BMC-190IN1",                  BMC_GOLDEN_190IN1        },
	{ "BMC-42IN1RESETSWITCH",        BMC_SUPER_22GAMES        },
	{ "BMC-64IN1NOREPEAT",           BMC_Y2K_64IN1            },
	{ "BMC-70IN1",                   BMC_GAME_800IN1          },
	{ "BMC-70IN1B",                  BMC_GAME_800IN1          },
	{ "BMC-8157",                    BMC_8157                 },
	{ "BMC-A65AS",                   BMC_A65AS                },
	{ "BMC-BS-5",                    BENSHENG_BS5             },
	{ "BMC-D1038",                   BMC_VT5201               },
	{ "BMC-FK23C",                   BMC_FK23C				  },
	{ "BMC-GHOSTBUSTERS63IN1",       BMC_CTC65                },
	{ "BMC-GS-2004",                 RCM_GS2004               },
	{ "BMC-GS-2013",                 RCM_GS2013               },
	{ "BMC-N625092",                 UNL_N625092              },
	{ "BMC-NOVELDIAMOND9999999IN1",  BMC_NOVELDIAMOND         },
	{ "BMC-SUPER24IN1SC03",          BMC_SUPER_24IN1          },
	{ "BMC-SUPERHIK8IN1",            BMC_HERO                 },
	{ "BMC-SUPERVISION16IN1",        BMC_SUPERVISION_16IN1    },
	{ "BMC-T-262",                   BMC_T262                 },
	{ "BMC-WS",                      BMC_SUPER_40IN1          },
	{ "BTL-MARIO1-MALEE2",           BTL_GENIUSMERIOBROS      },
	{ "CAMERICA-ALGN",               CAMERICA_ALGNV11         },
	{ "CAMERICA-ALGQ",               CAMERICA_ALGQV11         },
	{ "CAMERICA-BF9093",             CAMERICA_BF9093          },
	{ "CAMERICA-BF9096",             CAMERICA_BF9096          },
	{ "CAMERICA-BF9097",             CAMERICA_BF9097          },
	{ "CAMERICA-GAMEGENIE",          STD_NROM                 },
	{ "COLORDREAMS-74*377",          DISCRETE_74_377          },
	{ "DREAMTECH01",                 DREAMTECH_01             },
	{ "HVC-AMROM",                   STD_AMROM                },
	{ "HVC-AN1ROM",                  STD_AN1ROM               },
	{ "HVC-ANROM",                   STD_ANROM                },
	{ "HVC-AOROM",                   STD_AOROM                },
	{ "HVC-BNROM",                   STD_BNROM                },
	{ "HVC-CNROM",                   STD_CNROM                },
	{ "HVC-CPROM",                   STD_CPROM                },
	{ "HVC-DE1ROM",                  STD_DE1ROM               },
	{ "HVC-DEROM",                   STD_DEROM                },
	{ "HVC-DRROM",                   STD_DRROM                },
	{ "HVC-EKROM",                   STD_EKROM                },
	{ "HVC-ELROM",                   STD_ELROM                },
	{ "HVC-ETROM",                   STD_ETROM                },
	{ "HVC-EWROM",                   STD_EWROM                },
	{ "HVC-FAMILYBASIC",             CUSTOM_FB02              },
	{ "HVC-FJROM",                   STD_FJROM                },
	{ "HVC-FKROM",                   STD_FKROM                },
	{ "HVC-GNROM",                   STD_GNROM                },
	{ "HVC-HKROM",                   STD_HKROM                },
	{ "HVC-HROM",                    STD_NROM                 },
	{ "HVC-JLROM",                   STD_JLROM                },
	{ "HVC-JSROM",                   STD_JSROM                },
	{ "HVC-MHROM",                   STD_MHROM                },
	{ "HVC-NROM",                    STD_NROM                 },
	{ "HVC-NROM-128",                STD_NROM                 },
	{ "HVC-NROM-256",                STD_NROM                 },
	{ "HVC-NTBROM",                  STD_NTBROM               },
	{ "HVC-PEEOROM",                 STD_PEEOROM              },
	{ "HVC-PNROM",                   STD_PNROM                },
	{ "HVC-RROM",                    STD_NROM                 },
	{ "HVC-RROM-128",                STD_NROM                 },
	{ "HVC-SAROM",                   STD_SAROM                },
	{ "HVC-SBROM",                   STD_SBROM                },
	{ "HVC-SC1ROM",                  STD_SCROM                },
	{ "HVC-SCROM",                   STD_SCROM                },
	{ "HVC-SEROM",                   STD_SEROM                },
	{ "HVC-SF1ROM",                  STD_SFROM                },
	{ "HVC-SFROM",                   STD_SFROM                },
	{ "HVC-SGROM",                   STD_SGROM                },
	{ "HVC-SH1ROM",                  STD_SHROM                },
	{ "HVC-SHROM",                   STD_SHROM                },
	{ "HVC-SJROM",                   STD_SJROM                },
	{ "HVC-SKROM",                   STD_SKROM                },
	{ "HVC-SL1ROM",                  STD_SLROM                },
	{ "HVC-SL2ROM",                  STD_SLROM                },
	{ "HVC-SL3ROM",                  STD_SLROM                },
	{ "HVC-SLROM",                   STD_SLROM                },
	{ "HVC-SLRROM",                  STD_SLROM                },
	{ "HVC-SNROM",                   STD_SNROM                },
	{ "HVC-SOROM",                   STD_SOROM                },
	{ "HVC-SROM",                    STD_NROM                 },
	{ "HVC-STROM",                   STD_NROM                 },
	{ "HVC-SUROM",                   STD_SUROM                },
	{ "HVC-SXROM",                   STD_SXROM                },
	{ "HVC-TBROM",                   STD_TBROM                },
	{ "HVC-TEROM",                   STD_TEROM                },
	{ "HVC-TFROM",                   STD_TFROM                },
	{ "HVC-TGROM",                   STD_TGROM                },
	{ "HVC-TKROM",                   STD_TKROM                },
	{ "HVC-TKSROM",                  STD_TKSROM               },
	{ "HVC-TL1ROM",                  STD_TLROM                },
	{ "HVC-TL2ROM",                  STD_TLROM                },
	{ "HVC-TLROM",                   STD_TLROM                },
	{ "HVC-TLSROM",                  STD_TLSROM               },
	{ "HVC-TNROM",                   STD_TNROM                },
	{ "HVC-TQROM",                   STD_TQROM                },
	{ "HVC-TR1ROM",                  STD_TR1ROM               },
	{ "HVC-TSROM",                   STD_TSROM                },
	{ "HVC-TVROM",                   STD_TVROM                },
	{ "HVC-UN1ROM",                  STD_UN1ROM               },
	{ "HVC-UNROM",                   STD_UNROM                },
	{ "HVC-UOROM",                   STD_UOROM                },
	{ "IREM-74*161/161/21/138",      IREM_LROG017             },
	{ "IREM-BNROM",                  STD_BNROM                },
	{ "IREM-G101",                   IREM_G101A_0             },
	{ "IREM-G101-A",                 IREM_G101A_0             },
	{ "IREM-G101-B",                 IREM_G101B_0             },
	{ "IREM-HOLYDIVER",              IREM_HOLYDIVER           },
	{ "IREM-NROM-128",               STD_NROM                 },
	{ "IREM-NROM-256",               STD_NROM                 },
	{ "IREM-UNROM",                  STD_UNROM                },
	{ "JALECO-JF-01",                JALECO_JF01              },
	{ "JALECO-JF-02",                JALECO_JF02              },
	{ "JALECO-JF-03",                JALECO_JF03              },
	{ "JALECO-JF-04",                JALECO_JF04              },
	{ "JALECO-JF-05",                JALECO_JF05              },
	{ "JALECO-JF-06",                JALECO_JF06              },
	{ "JALECO-JF-07",                JALECO_JF07              },
	{ "JALECO-JF-08",                JALECO_JF08              },
	{ "JALECO-JF-09",                JALECO_JF09              },
	{ "JALECO-JF-10",                JALECO_JF10              },
	{ "JALECO-JF-11",                JALECO_JF11              },
	{ "JALECO-JF-12",                JALECO_JF12              },
	{ "JALECO-JF-13",                JALECO_JF13              },
	{ "JALECO-JF-14",                JALECO_JF14              },
	{ "JALECO-JF-15",                JALECO_JF15              },
	{ "JALECO-JF-16",                JALECO_JF16              },
	{ "JALECO-JF-17",                JALECO_JF17              },
	{ "JALECO-JF-18",                JALECO_JF18              },
	{ "JALECO-JF-19",                JALECO_JF19              },
	{ "JALECO-JF-20",                JALECO_JF20              },
	{ "JALECO-JF-21",                JALECO_JF21              },
	{ "JALECO-JF-22",                JALECO_JF22              },
	{ "JALECO-JF-23",                JALECO_JF23              },
	{ "JALECO-JF-24",                JALECO_JF24              },
	{ "JALECO-JF-25",                JALECO_JF25              },
	{ "JALECO-JF-26",                JALECO_JF26              },
	{ "JALECO-JF-27",                JALECO_JF27              },
	{ "JALECO-JF-28",                JALECO_JF28              },
	{ "JALECO-JF-29",                JALECO_JF29              },
	{ "JALECO-JF-30",                JALECO_JF30              },
	{ "JALECO-JF-31",                JALECO_JF31              },
	{ "JALECO-JF-32",                JALECO_JF32              },
	{ "JALECO-JF-33",                JALECO_JF33              },
	{ "JALECO-JF-34",                JALECO_JF34              },
	{ "JALECO-JF-35",                JALECO_JF35              },
	{ "JALECO-JF-36",                JALECO_JF36              },
	{ "JALECO-JF-37",                JALECO_JF37              },
	{ "JALECO-JF-38",                JALECO_JF38              },
	{ "JALECO-JF-39",                JALECO_JF39              },
	{ "JALECO-JF-40",                JALECO_JF40              },
	{ "JALECO-JF-41",                JALECO_JF41              },
	{ "KONAMI-74*139/74",            DISCRETE_74_139_74       },
	{ "KONAMI-CNROM",                STD_CNROM                },
	{ "KONAMI-NROM-128",             STD_NROM                 },
	{ "KONAMI-SLROM",                STD_SLROM                },
	{ "KONAMI-TLROM",                STD_TLROM                },
	{ "KONAMI-UNROM",                STD_UNROM                },
	{ "KONAMI-VRC-1",                KONAMI_VRC1              },
	{ "KONAMI-VRC-2",                KONAMI_VRC2              },
	{ "KONAMI-VRC-3",                KONAMI_VRC3              },
	{ "KONAMI-VRC-4",                KONAMI_VRC4_0            },
	{ "KONAMI-VRC-6",                KONAMI_VRC6_0            },
	{ "KONAMI-VRC-7",                KONAMI_VRC7_0            },
	{ "MLT-ACTION52",                AE_STD                   },
	{ "MLT-CALTRON6IN1",             CALTRON_6IN1             },
	{ "MLT-MAXI15",                  AVE_D1012                },
	{ "NAMCOT-163",                  NAMCOT_163_0             },
	{ "NAMCOT-3301",                 STD_NROM                 },
	{ "NAMCOT-3302",                 STD_NROM                 },
	{ "NAMCOT-3303",                 STD_NROM                 },
	{ "NAMCOT-3305",                 STD_NROM                 },
	{ "NAMCOT-3311",                 STD_NROM                 },
	{ "NAMCOT-3401",                 STD_DE1ROM               },
	{ "NAMCOT-3405",                 STD_DE1ROM               },
	{ "NAMCOT-3406",                 STD_DE1ROM               },
	{ "NAMCOT-3407",                 STD_DE1ROM               },
	{ "NAMCOT-3411",                 STD_NROM                 },
	{ "NAMCOT-3413",                 STD_DE1ROM               },
	{ "NAMCOT-3414",                 STD_DE1ROM               },
	{ "NAMCOT-3415",                 STD_DE1ROM               },
	{ "NAMCOT-3416",                 STD_DE1ROM               },
	{ "NAMCOT-3417",                 STD_DE1ROM               },
	{ "NAMCOT-3425",                 NAMCOT_3425              },
	{ "NAMCOT-3433",                 NAMCOT_3433              },
	{ "NAMCOT-3443",                 NAMCOT_3443              },
	{ "NAMCOT-3446",                 NAMCOT_3446              },
	{ "NAMCOT-3451",                 STD_DE1ROM               },
	{ "NES-AMROM",                   STD_AMROM                },
	{ "NES-AN1ROM",                  STD_AN1ROM               },
	{ "NES-ANROM",                   STD_ANROM                },
	{ "NES-AOROM",                   STD_AOROM                },
	{ "NES-B4",                      STD_TLROM                },
	{ "NES-BNROM",                   STD_BNROM                },
	{ "NES-BTR",                     CUSTOM_BTR               },
	{ "NES-CNROM",                   STD_CNROM                },
	{ "NES-CPROM",                   STD_CPROM                },
	{ "NES-DE1ROM",                  STD_DE1ROM               },
	{ "NES-DEROM",                   STD_DEROM                },
	{ "NES-DRROM",                   STD_DRROM                },
	{ "NES-EKROM",                   STD_EKROM                },
	{ "NES-ELROM",                   STD_ELROM                },
	{ "NES-ETROM",                   STD_ETROM                },
	{ "NES-EVENT",                   CUSTOM_EVENT             },
	{ "NES-EWROM",                   STD_EWROM                },
	{ "NES-FJROM",                   STD_FJROM                },
	{ "NES-FKROM",                   STD_FKROM                },
	{ "NES-GNROM",                   STD_GNROM                },
	{ "NES-HKROM",                   STD_HKROM                },
	{ "NES-HROM",                    STD_NROM                 },
	{ "NES-JLROM",                   STD_JLROM                },
	{ "NES-JSROM",                   STD_JSROM                },
	{ "NES-MHROM",                   STD_MHROM                },
	{ "NES-NROM",                    STD_NROM                 },
	{ "NES-NROM-128",                STD_NROM                 },
	{ "NES-NROM-256",                STD_NROM                 },
	{ "NES-NTBROM",                  STD_NTBROM               },
	{ "NES-PEEOROM",                 STD_PEEOROM              },
	{ "NES-PNROM",                   STD_PNROM                },
	{ "NES-QJ",                      CUSTOM_QJ                },
	{ "NES-RROM",                    STD_NROM                 },
	{ "NES-RROM-128",                STD_NROM                 },
	{ "NES-SAROM",                   STD_SAROM                },
	{ "NES-SBROM",                   STD_SBROM                },
	{ "NES-SC1ROM",                  STD_SCROM                },
	{ "NES-SCROM",                   STD_SCROM                },
	{ "NES-SEROM",                   STD_SEROM                },
	{ "NES-SF1ROM",                  STD_SFROM                },
	{ "NES-SFROM",                   STD_SFROM                },
	{ "NES-SGROM",                   STD_SGROM                },
	{ "NES-SH1ROM",                  STD_SHROM                },
	{ "NES-SHROM",                   STD_SHROM                },
	{ "NES-SJROM",                   STD_SJROM                },
	{ "NES-SKROM",                   STD_SKROM                },
	{ "NES-SL1ROM",                  STD_SLROM                },
	{ "NES-SL2ROM",                  STD_SLROM                },
	{ "NES-SL3ROM",                  STD_SLROM                },
	{ "NES-SLROM",                   STD_SLROM                },
	{ "NES-SLRROM",                  STD_SLROM                },
	{ "NES-SNROM",                   STD_SNROM                },
	{ "NES-SOROM",                   STD_SOROM                },
	{ "NES-SROM",                    STD_NROM                 },
	{ "NES-STROM",                   STD_NROM                 },
	{ "NES-SUROM",                   STD_SUROM                },
	{ "NES-SXROM",                   STD_SXROM                },
	{ "NES-TBROM",                   STD_TBROM                },
	{ "NES-TEROM",                   STD_TEROM                },
	{ "NES-TFROM",                   STD_TFROM                },
	{ "NES-TGROM",                   STD_TGROM                },
	{ "NES-TKROM",                   STD_TKROM                },
	{ "NES-TKSROM",                  STD_TKSROM               },
	{ "NES-TL1ROM",                  STD_TLROM                },
	{ "NES-TL2ROM",                  STD_TLROM                },
	{ "NES-TLROM",                   STD_TLROM                },
	{ "NES-TLSROM",                  STD_TLSROM               },
	{ "NES-TNROM",                   STD_TNROM                },
	{ "NES-TQROM",                   STD_TQROM                },
	{ "NES-TR1ROM",                  STD_TR1ROM               },
	{ "NES-TSROM",                   STD_TSROM                },
	{ "NES-TVROM",                   STD_TVROM                },
	{ "NES-UN1ROM",                  STD_UN1ROM               },
	{ "NES-UNROM",                   STD_UNROM                },
	{ "NES-UOROM",                   STD_UOROM                },
	{ "NES-WH",                      CUSTOM_WH                },
	{ "NTDEC-N715062",               NTDEC_N715062            },
	{ "PAL-MH",                      STD_MHROM                },
	{ "PAL-ZZ",                      CUSTOM_ZZ                },
	{ "SACHEN-8259A",                SACHEN_8259A             },
	{ "SACHEN-8259B",                SACHEN_8259B             },
	{ "SACHEN-8259C",                SACHEN_8259C             },
	{ "SACHEN-8259D",                SACHEN_8259D             },
	{ "SACHEN-CNROM",                STD_CXROM                },
	{ "SETA-NROM-128",               STD_NROM                 },
	{ "SUNSOFT-1",                   SUNSOFT_1                },
	{ "SUNSOFT-2",                   SUNSOFT_2B               },
	{ "SUNSOFT-3",                   SUNSOFT_3                },
	{ "SUNSOFT-4",                   SUNSOFT_4_0              },
	{ "SUNSOFT-5B",                  SUNSOFT_5B_0             },
	{ "SUNSOFT-FME-7",               SUNSOFT_FME7_0           },
	{ "SUNSOFT-NROM-256",            STD_NROM                 },
	{ "TAITO-74*139/74",             DISCRETE_74_139_74       },
	{ "TAITO-74*161/161/32",         DISCRETE_74_161_161_32_A },
	{ "TAITO-CNROM",                 STD_CNROM                },
	{ "TAITO-NROM-128",              STD_NROM                 },
	{ "TAITO-NROM-256",              STD_NROM                 },
	{ "TAITO-TC0190FMC",             TAITO_TC0190FMC          },
	{ "TAITO-TC0190FMC+PAL16R4",     TAITO_TC0190FMC_PAL16R4  },
	{ "TAITO-UNROM",                 STD_UNROM                },
	{ "TAITO-X1-005",                TAITO_X1005              },
	{ "TAITO-X1-017",                TAITO_X1017              },
	{ "TENGEN-800002",               TENGEN_800002            },
	{ "TENGEN-800003",               STD_NROM                 },
	{ "TENGEN-800004",               TENGEN_800004            },
	{ "TENGEN-800008",               TENGEN_800008            },
	{ "TENGEN-800030",               TENGEN_800030            },
	{ "TENGEN-800032",               TENGEN_800032            },
	{ "TENGEN-800037",               TENGEN_800037            },
	{ "TENGEN-800042",               TENGEN_800042            },
	{ "UNL-22211",                   TXC_22211A               },
	{ "UNL-603-5052",                BTL_6035052              },
	{ "UNL-8237",                    SUPERGAME_POCAHONTAS2    },
	{ "UNL-A9746",                   UNL_A9746                },
	{ "UNL-AX5705",                  BTL_AX5705               },
	{ "UNL-CC-21",                   UNL_CC21                 },
	{ "UNL-EDU2000",                 UNL_EDU2000              },
	{ "UNL-H2288",                   KAY_H2288                },
	{ "UNL-KOF97",                   UNL_KINGOFFIGHTERS97     },
	{ "UNL-KS7032",                  KAISER_KS7032            },
	{ "UNL-N625092",                 UNL_N625092              },
	{ "UNL-SA-0036",                 SACHEN_SA0036            },
	{ "UNL-SA-0037",                 SACHEN_SA0037            },
	{ "UNL-SA-016-1M",               SACHEN_SA0161M           },
	{ "UNL-SA-72007",                SACHEN_SA72007           },
	{ "UNL-SA-72008",                SACHEN_SA72008           },
	{ "UNL-SA-NROM",                 SACHEN_TCA01             },
	{ "UNL-SACHEN-74LS374N",         SACHEN_74_374B           },
	{ "UNL-SACHEN-8259A",            SACHEN_8259A             },
	{ "UNL-SACHEN-8259B",            SACHEN_8259B             },
	{ "UNL-SACHEN-8259C",            SACHEN_8259C             },
	{ "UNL-SACHEN-8259D",            SACHEN_8259D             },
	{ "UNL-SHERO",                   SACHEN_STREETHEROES      },
	{ "UNL-SL1632",                  REXSOFT_SL1632           },
	{ "UNL-SMB2J",                   BTL_SMB2_C               },
	{ "UNL-T-230",                   BTL_T230                 },
	{ "UNL-TC-U01-1.5M",             SACHEN_TCU01             },
	{ "UNL-TEK90",                   JYCOMPANY_TYPE_A         },
	{ "UNL-TF1201",                  UNL_TF1201               },
	{ "VIRGIN-SNROM",                STD_SNROM                },
	{ "NES-NROM-256-CN",             NROM_256_CN              },
	{ "SUBOR_999",					 SUBOR_999				  },
	{ "SMART_GENIUS",				 SMART_GENIUS			  },
	{ "FK23CA",						 FK23CA					  },
	{ "BMC-FK23CA",					 BMC_FK23CA				  },
	{ "FK23C",						 FK23C					  },
	{ "BMC-Super24in1SC03",          BMC_SUPER_24IN1          },
	{ "CHINA_ER_SAN2",				 CHINA_ER_SAN2			  },
	{ "UNL-SA-9602B",				 UNL_SA_9602B			  },
	{ "UNL-CITYFIGHT",				 City_Fighter_IV		  },
	{ "COOLBOY",					 COOLBOY				  },
	{ "UNL-DRAGONFIGHTER",			 Dragon_Fighter			  },
	{ "UNL-YOKO",					 UNL_YOKO	    		  },
	{ "UNL-OneBus",					 OneBus		    		  },
	{ "UNL-82112C",					 UNL_82112C	    		  },
	{ "UNL-01-22110-000",			 MGC_002	    		  },
	{ "FF3_CN",						 FF3_CN		    		  },
	{ "UNL-KS7010",					 UNL_KS7010	    		  },
	{ "UNL-158B",					 UNL_158B	    		  },
	{ "UNL-KS7030",					 UNL_KS7030	    		  },
	{ "UNL-TH2131-1",				 UNL_TH2131_1	   		  },
	{ "UNL-831128C",				 UNL_831128C	   		  },
	{ "BMC-LB12IN1",				 BMC_LB12IN1	   		  },
};

/*--------------[ DEFINE                ]-------------------------------*/
/*--------------[ EXTERNAL PROGRAM      ]-------------------------------*/
/*--------------[ EXTERNAL WORK         ]-------------------------------*/
/*--------------[ WORK                  ]-------------------------------*/
/*--------------[ PROTOTYPE             ]-------------------------------*/
/*--------------[ CONST                 ]-------------------------------*/
/*--------------[ PROGRAM               ]-------------------------------*/

//////////////////////////////////////////////////////////////////////////
// Based class implement
//////////////////////////////////////////////////////////////////////////
Mapper::Mapper( NES* parent ) : nes(parent)
{
}

Mapper::~Mapper()
{
}

// $4100-$7FFF Lower Memory read
BYTE	Mapper::ReadLow( WORD addr )
{
	// $6000-$7FFF WRAM
	if( addr >= 0x6000 && addr <= 0x7FFF ) {
		return	CPU_MEM_BANK[addr>>13][addr&0x1FFF];
	}

	return	(BYTE)(addr>>8);
}

// $4100-$7FFF Lower Memory write
void	Mapper::WriteLow( WORD addr, BYTE data )
{
	// $6000-$7FFF WRAM
	if( addr >= 0x6000 && addr <= 0x7FFF ) {
		CPU_MEM_BANK[addr>>13][addr&0x1FFF] = data;
	}
}

int NES_ROM_get_unifBoardID(char *unif_board)
{//¿ÉÒÔÓÅ»¯Ëã·¨
	int iCount=0;
	while(1)
	{
		if( iCount>=BOARD_MAX ) break;
		if(strcmp(BoardInfo[iCount].boardName,unif_board)==0)
		{
			return BoardInfo[iCount].boardID;
		}
		iCount++;
	}

	return 0;
}