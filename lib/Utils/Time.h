#ifndef TIME_H
#define TIME_H

#define F_CPU 16000000UL // 16 mhz

#define clockCyclesPerMicrosecond() (F_CPU / 1000000L)

#define clockCyclesToMicroseconds(a) ((a) / clockCyclesPerMicrosecond())
#define microsecondsToClockCycles(a) ((a) * clockCyclesPerMicrosecond())

#define usToTicks(_us) ((clockCyclesPerMicrosecond() / 16 * _us) / 4)                   // converts microseconds to ticks
#define ticksToUs(_ticks) (((unsigned)_ticks * 16) / (clockCyclesPerMicrosecond() / 4)) // converts from ticks back to microseconds

#endif