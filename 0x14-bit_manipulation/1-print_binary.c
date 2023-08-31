void print_binary(unsigned long int n) {
    if (n == 0) {
        printf("0b0");
        return;
    }

    int num_bits = sizeof(unsigned long int) * 8;
    int leading_zeroes = 1;

    unsigned long int mask = 1UL << (num_bits - 1);
    
    for (int i = 0; i < num_bits; i++) {
        if (leading_zeroes && (n & mask) == 0) {
		mask >>= 1;
            continue;
        }
        leading_zeroes = 0;
        printf("%d", (n & mask) != 0);
        mask >>= 1;
    }
}
