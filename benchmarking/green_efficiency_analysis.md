# Green Efficiency Analysis

## Measurement Methodology

All timings were taken with clock() from time.h and converted to seconds by dividing by CLOCKS_PER_SEC. Every program was compiled with gcc without optimization flags and executed three consecutive times in the same Holberton sandbox. The baseline program (baseline_loop.c) runs 100,000,000 iterations of a simple loop. The comparison program (comparison_algorithms.c) times two implementations that count even numbers in an array of 50,000 integers. The figures below are averages of the three runs. Note that clock() reports CPU time used by the process, so time spent waiting is not included.

## Observed Performance Differences

The baseline loop gave 0.235007, 0.228091 and 0.233837 seconds, an average of 0.232312 seconds. The spread between the fastest and slowest run is about 0.007 seconds, roughly 3 percent, so even identical code does not produce identical times.

In the comparison program, the naive algorithm took 2.806088, 2.890919 and 2.793556 seconds, an average of 2.830188 seconds. The single-pass algorithm took 0.000106 seconds in all three runs. The single-pass version was therefore about 26,700 times faster than the naive one.

The reason is the amount of work. The naive version contains a nested loop and performs 50,000 x 50,001 / 2 = 1,250,025,000 inner iterations, while the single-pass version performs only 50,000. The cost of one step is similar everywhere: about 2.3 nanoseconds per iteration for the baseline (0.232312 s for 100,000,000), about 2.3 nanoseconds for the naive version, and about 2.1 nanoseconds for the single pass. The difference comes from how many steps are executed, not from how expensive each step is.

## Relation Between Runtime and Energy Consumption

No energy measurement was made in this experiment, so no energy value can be reported. Runtime is only a proxy. A processor that is actively computing for 2.83 seconds stays busy far longer than one that computes for 0.000106 seconds. If the power drawn while computing were roughly constant, which was not verified here, energy would scale with active time, and the naive algorithm would consume on the order of 26,700 times more processor energy for this task. Confirming this would require a power meter or a hardware energy counter.

## Limitations of the Experiment

Only three runs were recorded per program, which is a small sample. The sandbox is a shared environment, so other workloads may have disturbed the timings; the baseline variation of about 3 percent shows that noise exists. No compiler optimization was used, and an optimizing compiler could change the results. The single-pass time of 0.000106 seconds is very close to the resolution of clock(), and its identical value in three runs suggests the timer granularity limits precision. Finally, the two functions did not return the same value (625,025,000 for the naive one, 25,000 for the single pass), because the naive loop recounts the same elements repeatedly. They are therefore not strictly equivalent, which weakens a direct comparison. Everything was measured on one machine only.

## Practical Engineering Takeaway

Algorithm choice dominated every other factor in these measurements. Removing a redundant nested loop produced a speedup of about 26,700, far larger than the roughly 3 percent run-to-run noise. In practice, an engineer should repeat measurements and use averages, check that the compared implementations really compute the same thing, and prefer the algorithm that performs fewer operations. Doing so saves both time and, very likely, energy, although this last point would need a direct energy measurement to be proven.
