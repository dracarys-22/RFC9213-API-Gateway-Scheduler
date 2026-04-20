#include <stdio.h>
#include <string.h>
#include "rfc_parser.h"

Priority parse_priority(const char *header) {
    Priority p;
    p.urgency = 3;      // default
    p.incremental = 0;  // default

    if (header == NULL) return p;

    // "u=2, i"
    char *u_ptr = strstr(header, "u=");
    if (u_ptr) {
        sscanf(u_ptr, "u=%d", &p.urgency);
    }

    if (strstr(header, "i")) {
        p.incremental = 1;
    }

    return p;
}