kada sam prvobitno kopirao Drivers/ folder (zamenivsi time onaj koji sam imao po default-u od svog projekta) projekat se nije kompajlirao
(trazio je fajlove za tacno moj mcu, a ti fajlovi su bili za drugi), pa sam vratio svoj generisani Drivers/. nakon toga se komplajlirao.

u fajlu `App/blt_conf.h` nisam dirao nista, mozda treba nesto. nisam menjao ni `BOOT_FLASH_VECTOR_TABLE_CS_OFFSET`, vec sam ostavio onaj
koji sam kopirao iz demo projekta.
