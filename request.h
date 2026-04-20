#ifndef REQUEST_H
#define REQUEST_H

typedef struct {
    int urgency;      // 0 (highest) - 7 (lowest)
    int incremental;  // 0 or 1
} Priority;

typedef struct {
    int id;
    Priority priority;
    char payload[256];
} Request;

#endif