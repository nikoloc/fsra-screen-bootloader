/** \brief   Array wit the layout of the flash memory.
 *  \details Also controls what part of the flash memory is reserved for the
 * bootloader. If the bootloader size changes, the reserved sectors for the
 * bootloader might need adjustment to make sure the bootloader doesn't get
 * overwritten.
 */
static const tFlashSector flashLayout[] = {
        /* space is reserved for a bootloader configuration with all supported
         * communication interfaces enabled. when for example only UART is needed,
         * then the space required for the bootloader can be made a lot smaller
         * here.
         */
        /* { 0x08000000, 0x04000,  0},           flash sector  0 - reserved for the bootloader   */
        {0x08004000, 0x04000, 1},  // 16kB
        {0x08008000, 0x04000, 2},  // 16kB
        {0x0800c000, 0x04000, 3}, /* flash sector  3 -  16kb                     */
        {0x08010000, 0x10000, 4}, /* flash sector  4 -  64kb                     */
        {0x08020000, 0x20000, 5}, /* flash sector  5 - 128kb                     */
        {0x08040000, 0x20000, 6}, /* flash sector  6 - 128kb                     */
        {0x08060000, 0x20000, 7}, /* flash sector  7 - 128kb                     */
};
