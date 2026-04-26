# report

kada sam prvobitno kopirao Drivers/ folder (zamenivsi time onaj koji sam imao
po default-u od svog projekta) projekat se nije kompajlirao (trazio je
fajlove za tacno moj mcu, a ti fajlovi su bili za drugi), pa sam vratio
svoj generisani Drivers/. nakon toga se komplajlirao.

u fajlu `App/blt_conf.h` nisam dirao nista, mozda treba nesto. nisam menjao
ni `BOOT_FLASH_VECTOR_TABLE_CS_OFFSET`, vec sam ostavio onaj koji sam kopirao
iz demo projekta.

u fajlu `App/fsra_config.h` nisam menjao nista u odnosu na boilerplate iz dokumentacije.
u linker skripti sam stavio 16K za duzinu flash memorije. u primeru
[link](https://gitlab.com/roadarrow/fsra_2025_stm32l431cctx_bootloader/-/blob/main/FSRA_2025_STM32L431CCTX_BOOT/STM32L431CCTX_FLASH.ld?ref_type=heads#L50%60)
stoji 10K, mada u dokumentaciji pise da bi trebalo da bude umnozak 16K. mozda
treba proveriti.

> ovaj problem ispod je resen tako sto sam disablovao uart.

fali mi `stm32f4xx_ll_usart.h`. nasao sam da on postoji u demo projektru u
`Drivers/` folderu, dok kod mene postoji svi ostali osim tog.

dodao sam ga rucno.

fali mi definicija `tFlashSector` u `flash_layout.c`. nasao sam je u
`Loader/ARMCM4_STM32F4/flash.c` pa sam je prebacio u `flash.h` header i
include-ovao ga u `flash_layout.c`.

malopre sam zaboravio da stavim RCC na LL umesto HAL. sad jesam i vise se ne
kompajlira, jer u Loader/\* stvari pozivaju HAL\_\*() funkcije. vratio sam
na HAL, cini mi se da tako radi i dosadasnje napisani bootloader-i.

> resenje prethodnog

vezano za usart problem odozgo, u `App/blt_conf.h` sam promenio
`BOOT_COM_MBRTU_ENABLE` na 0, tako da mi to vise ne treba.

ostalo je jos jedan define da premestim u `flash.h` koji nisam malopre

## review

u `App/blt_conf.h` treba proveriti ove frekvencije oscilatora.

svi can parametri su isti kao u referenci.

u referenci `BOOT_FLASH_VECTOR_TABLE_CS_OFFSET` nije definisan. potrazivsi po
repou, u `Loader/ARMCM4_STM32L4/flash.c` postoji default vrednost za to, pa
necu ni ja definisati.
