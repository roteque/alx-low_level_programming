#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

typedef struct {
    uint8_t  e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} ElfHeader;

/**
 * typdef struct - to list the properties of elf file header
 * get_architecture - a function to get the system architecture
 *
 * Return 0
 */

const char *get_architecture_name(uint16_t machine) {
    switch (machine) {
        case 3: return "Intel 80386";
        case 62: return "x86-64";
        default: return "Unknown";
    }
}

/**
 * main - to get the argument passed at execution
 *
 * Return 0
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 1;
    }

/**
 * Open the ELF file for reading
 *
 */
    int file = open(argv[1], O_RDONLY);
    if (file == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 98;
    }

/**
 * Read the ELF header
 *
 */
    ElfHeader header;
    if (read(file, &header, sizeof(ElfHeader)) != sizeof(ElfHeader)) {
        fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
        close(file);
        return 98;
    }

/**
 * Check if the file is a valid ELF file
 *
 */
    if (header.e_ident[0] != 0x7F || header.e_ident[1] != 'E' || header.e_ident[2] != 'L' || header.e_ident[3] != 'F') {
        fprintf(stderr, "Not a valid ELF file\n");
        close(file);
        return 98;
    }

/**
 * Seek to the beginning of the file
 *
 */
    if (lseek(file, 0, SEEK_SET) == -1) {
        fprintf(stderr, "Error seeking to the beginning of the file: %s\n", strerror(errno));
        close(file);
        return 98;
    }

/**
 * Display the ELF header information in the format matching readelf -h
 *
 */
    printf("ELF Header:\n");
    printf("  Magic: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header.e_ident[4] == 1 ? "ELF32" : (header.e_ident[4] == 2 ? "ELF64" : "Invalid"));
    printf("  Data:                              %s\n", header.e_ident[5] == 1 ? "2's complement, little endian" : (header.e_ident[5] == 2 ? "2's complement, big endian" : "Invalid"));
    printf("  Version:                           %d (current)\n", header.e_ident[6]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[7]) {
        case 0: printf("UNIX - System V\n"); break;
        case 1: printf("UNIX - HP-UX\n"); break;
        case 2: printf("UNIX - NetBSD\n"); break;
        case 3: printf("UNIX - Linux\n"); break;
/**
 * Add more OS/ABI mappings as needed
 *
 */
        default: printf("Unknown\n"); break;
    }
    printf("  ABI Version:                       %d\n", header.e_ident[8]);
    printf("  Type:                              ");
    switch (header.e_type) {
        case 0: printf("NONE (None)\n"); break;
        case 1: printf("REL (Relocatable file)\n"); break;
        case 2: printf("EXEC (Executable file)\n"); break;
        case 3: printf("DYN (Shared object file)\n"); break;
        case 4: printf("CORE (Core file)\n"); break;
        default: printf("Unknown (%d)\n", header.e_type); break;
    }
    printf("  Machine:                           %s\n", get_architecture_name(header.e_machine));
    printf("  Version:                           0x%x\n", header.e_version);
    printf("  Entry point address:               0x%lx\n", header.e_entry);

/**
 * Close the file
 *
 */
    close(file);

    return (0);
}
