#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <sys/time.h>

// All these functions and structures manipulate time in seconds with precision in millisecond

// Returns the current time (since epoch 0) in seconds with millisecond precision
double gettime();


struct _timer_t {
    double start_time;
    double stop_time;
    bool stopped;
};
typedef struct _timer_t timer_t;


timer_t *init_timer();
void free_timer(timer_t *timer);

void reset_timer(timer_t *timer);
void start_timer(timer_t *timer);
void stop_timer(timer_t *timer);
double get_timer_time(timer_t *timer);


#endif