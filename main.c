#include "efi.h"

void efi_main(void *image_handle, EFI_SYSTEM_TABLE *system_table){
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *con_out = system_table->con_out;

	con_out->clear_screen(con_out);

	while(1){}
}
