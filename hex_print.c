/**
 * Accept argv[1] from CLI and print hexdump of binary file
 *
 * Tim Osburn
 * 210711
 *
 * gcc hex_print.c -o hex_print; ./hex_print ./filenamehere
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMNWIDTH 16

int main(int argc, char *const argv[])
{
	FILE *fptr;
	unsigned char buffer[COLUMNWIDTH];
	char c;
	int linecount = 0;
	int i = 0;
	int bytesreturned = 2;

	// Open file
	fptr = fopen(argv[1], "rb");
	if (fptr == NULL) {
		printf("Cannot open file \n");
		exit(0);
	}

	while ((bytesreturned = fread(buffer,1, sizeof(buffer),fptr)) != 0) {
		printf("\n%08X (%02i): ",linecount +=COLUMNWIDTH, bytesreturned);

		// Print HEX Values
		if (bytesreturned == COLUMNWIDTH) {
			for (i = 0; i<bytesreturned; i++)
				printf("%02X ", buffer[i]);
		} else {
			for (i = 0; i<bytesreturned; i++)
				printf("%02X ", buffer[i]);
			for (i = 0; i<(COLUMNWIDTH-bytesreturned); i++)
				printf("-- ");
		}

		// Print ASCII characters
		for (int i = 0; i<bytesreturned; i++) {
			if (buffer[i] >=32 && buffer[i] <=127) {
				printf("%c", buffer[i]);
			} else {
				printf(".");
			}
		}
	}

	fclose(fptr);
	puts("");
	return 0;
}
