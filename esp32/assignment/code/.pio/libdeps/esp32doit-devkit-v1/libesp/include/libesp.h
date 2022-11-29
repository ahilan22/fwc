#pragma once

#include <esp_err.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/cdefs.h>

static __always_inline void ESP_ERROR_DISCARD(esp_err_t err) {
    // Do nothing.
}

static __always_inline bool util_unterm_str_matches(const char* st,
                                                    const char* sut,
                                                    size_t sut_len) {
    return !strncmp(st, sut, sut_len) && st[sut_len] == '\0';
}

#define UUID_BYTE_COUNT 16

typedef struct uuid {
    uint8_t b[UUID_BYTE_COUNT];
} uuid_t;

#define UUID_NIL  \
    {             \
        .b = {    \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
            0x00, \
        }         \
    }
#define UUID_NIL_STR "00000000-0000-0000-0000-000000000000"

// Generate a version 4 (random), variant 1 UUID.
void util_generate_uuid4(uuid_t* out_uuid);

// Print the given uuid to a `malloc()`'d memory buffer. The spec says that that
// hex digits should be lower case.
esp_err_t util_print_uuid(char** str, const uuid_t* uuid);

// DANGER: `micros` should be small to avoid WDT triggers.
void util_wait_micros(int64_t micros);

void util_wait_for_keypress();

void util_log_idf_version();

esp_err_t util_stack_overflow_check();

void util_stack_print_remaining();

uint64_t util_current_epoch_time_ms();

// WARNING: You must set `CONFIG_FREERTOS_RUN_TIME_STATS_USING_ESP_TIMER=y` in
// order to use this function.
void util_freertos_print_usage();
