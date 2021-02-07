#include <stdint.h>

#define CHAR16		uint16_t
#define UINTN		size_t

typedef void* EFI_HANDLE;
typedef UINTN EFI_STATUS;

typedef struct {
	uint64_t signature;
	uint32_t revision;
	uint32_t size;
	uint32_t crc32;
	uint32_t reserved;
} EFI_TABLE_HEADER;

typedef struct {
	uint64_t _buf;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct SIMPLE_TEXT_OUTPUT_PROTOCOL {
	uint64_t _buf;
	EFI_STATUS (*output_string)(struct SIMPLE_TEXT_OUTPUT_PROTOCOL*, CHAR16*);
	EFI_STATUS (*test_string)(struct SIMPLE_TEXT_OUTPUT_PROTOCOL*, CHAR16*);
	EFI_STATUS (*query_mode)(struct SIMPLE_TEXT_OUTPUT_PROTOCOL*, CHAR16*, uint64_t *columns, uint64_t *rows);
	EFI_STATUS (*set_mode)(struct SIMPLE_TEXT_OUTPUT_PROTOCOL*, uint64_t);
	EFI_STATUS (*set_attribute)(struct SIMPLE_TEXT_OUTPUT_PROTOCOL*, uint64_t);
	EFI_STATUS (*clear_screen)(struct SIMPLE_TEXT_OUTPUT_PROTOCOL*);
	uint64_t _buf2[2];
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct {
	char _buf_rs1[24];
	uint64_t _buf_rs2[4];
	uint64_t _buf_rs3[2];
	uint64_t _buf_rs4[3];
	uint64_t _buf_rs5;
	size_t __fn;
} EFI_RUNTIME_SERVICES;

typedef struct {
	char _buf[24];
	uint64_t _buf2[2];
	uint64_t _buf3[2];
} EFI_BOOT_SERVICES;

typedef struct {
	EFI_TABLE_HEADER header;
	CHAR16 *firmware_vendor;
	uint32_t firmware_revision;
	EFI_HANDLE console_in_handle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *con_in;
	EFI_HANDLE console_out_handle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *con_out;
	EFI_HANDLE standard_error_handle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *std_err;
	EFI_RUNTIME_SERVICES *runtime_services;
	EFI_BOOT_SERVICES *boot_services;
	UINTN number_of_table_entries;
	//EFI_CONFIGURATION_TABLE *config_table;
} EFI_SYSTEM_TABLE;
