#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return *state;
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return sum;
}

int main(void)
{
	unsigned long checksum;
	clock_t t0, t1, b0, b1, p0, p1, r0, r1;
	double k;

	k = (double)CLOCKS_PER_SEC;
	t0 = clock();

	b0 = clock();
	build_dataset();
	b1 = clock();

	p0 = clock();
	process_dataset();
	p1 = clock();

	r0 = clock();
	checksum = reduce_checksum();
	r1 = clock();

	t1 = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	printf("TOTAL seconds: %.6f\n", (double)(t1 - t0) / k);
	printf("BUILD_DATA seconds: %.6f\n", (double)(b1 - b0) / k);
	printf("PROCESS seconds: %.6f\n", (double)(p1 - p0) / k);
	printf("REDUCE seconds: %.6f\n", (double)(r1 - r0) / k);

	return 0;
}
