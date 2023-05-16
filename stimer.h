#ifndef STIMER_H
#define STIMER_H

#include <stdbool.h>
#include <sys/time.h>

// All these functions and structures manipulate time in seconds with precision in millisecond

// Returns the current time (since epoch 0) in seconds with millisecond precision
double gettime();


struct _stimer_t {
    double start_time;
    double stop_time;
    bool stopped;
};
typedef struct _stimer_t stimer_t;


stimer_t *init_stimer();
void free_stimer(stimer_t *timer);

void reset_stimer(stimer_t *timer);
void start_stimer(stimer_t *timer);
void stop_stimer(stimer_t *timer);
double get_stimer_time(stimer_t *timer);


#endif