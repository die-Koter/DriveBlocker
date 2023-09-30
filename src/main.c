#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Usage:\n%s\t[op_size]\t[n_ops]\n\nFurther information: https://die-Koter.github.io/DriveBlocker/help.html\n", argv[0]);
		exit(EXIT_FAILURE);
	} 

	int op_size = atoi(argv[1]),
		n_ops = atoi(argv[2]);
	if (!op_size || !n_ops) {
		fprintf(stderr, "Input format error!\nProgramm will terminate...\n\nFurther information: https://die-Koter.github.io/DriveBlocker/help.html\n");
		exit(EXIT_FAILURE);
	}

	unsigned char* op_data = (unsigned char*)malloc(sizeof(unsigned char) * op_size);
	if (!op_data) {
		fprintf(stderr, "Memmory error!\nProgramm will terminate...\n\nFurther information: https://die-Koter.github.io/DriveBlocker/help.html\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp = fopen("DriveBlocker", "wb");
	if (!fp) {
		fprintf(stderr, "Cannot open DriveBlocker file for write operation!\nProgramm will terminate...\n\nFurther information: https://die-Koter.github.io/DriveBlocker/help.html\n");
		exit(EXIT_FAILURE);
	}

	for (long i = 0; i < n_ops; i += 1) {
		printf("Calculating random data for op #%ld... ", i+1);
		fflush(stdout);
		for (long x = 0; x < op_size; x += 1)
			op_data[x] = (unsigned char)(rand() % 128);
		printf("Done!\n");

		printf("Writing op #%ld... ", i+1);
		fflush(stdout);
		if (fwrite(op_data, sizeof(unsigned char), op_size, fp) != op_size) {
			fprintf(stderr, "Failed!\nProgramm will terminate...\n\nFurther information: https://die-Koter.github.io/DriveBlocker/help.html\n");
			free(op_data);
			exit(EXIT_FAILURE);
		}
		printf("Done!\n\n");
	}

	printf("\nFinished!\nNo errors occured!\nProgramm will terminate...\n");
	free(op_data);
	return 0;
}
