kada sam prvobitno kopirao Drivers/ folder (zamenivsi time onaj koji sam imao po default-u od svog projekta) projekat se nije kompajlirao
(trazio je fajlove za tacno moj mcu, a ti fajlovi su bili za drugi), pa sam vratio svoj generisani Drivers/. nakon toga se komplajlirao.

u fajlu `App/blt_conf.h` nisam dirao nista, mozda treba nesto. nisam menjao ni `BOOT_FLASH_VECTOR_TABLE_CS_OFFSET`, vec sam ostavio onaj
koji sam kopirao iz demo projekta.

u fajlu `App/fsra_config.h` nisam menjao nista u odnosu na boilerplate iz dokumentacije.

u linker skripti sam stavio 16K za duzinu flash memorije. u primeru `https://gitlab.com/roadarrow/fsra_2025_stm32l431cctx_bootloader/-/blob/main/FSRA_2025_STM32L431CCTX_BOOT/STM32L431CCTX_FLASH.ld?ref_type=heads#L50` stoji 10K, mada u dokumentaciji pise da bi trebalo da bude
umnozak 16K. mozda treba proveriti.
