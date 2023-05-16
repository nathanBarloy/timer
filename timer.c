#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

#include "timer.h"


double gettime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    double s = (double)t.tv_sec;
    double u = ((double)t.tv_usec) / 1000000;
    return s+u;
}


timer_t *init_timer() {
    timer_t *timer = malloc(sizeof(*timer));
    if (timer == NULL) {
        fprintf(stderr, "Error while allocating.");
        exit(1);
    }
    reset_timer(timer);
    return timer;
}

void free_timer(timer_t *timer) {
    free(timer);
}


void reset_timer(timer_t *timer) {
    timer->start_time = 0.;
    timer->stop_time = 0.;
    timer->stopped = true;
}

void start_timer(timer_t *timer) {
    if (timer->stopped) {
        timer->start_time = gettime() - timer->stop_time + timer->start_time;
        timer->stopped = false;
    }
}

void stop_timer(timer_t *timer) {
    timer->stop_time = gettime();
    timer->stopped = true;
}

double get_timer_time(timer_t *timer) {
    if (timer->stopped) {
        return timer->stop_time - timer->start_time;
    } else {
        return gettime() - timer->start_time;
    }
}