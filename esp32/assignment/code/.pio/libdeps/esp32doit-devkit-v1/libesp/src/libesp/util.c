#include <esp_idf_version.h>
#include <esp_log.h>
#include <esp_system.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <sys/time.h>

#include "libesp.h"

static const char *TAG = "libesp";

void util_wait_micros(int64_t micros) {
    int64_t then = esp_timer_get_time();
    while (esp_timer_get_time() - then <= micros) {
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
    }
}

void util_wait_for_keypress() {
    // Clear the buffer
    while (fgetc(stdin) != EOF) {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

    // Now wait until next key
    while (fgetc(stdin) == EOF) {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void util_log_idf_version() {
    ESP_LOGW(TAG, "%d.%d.%d", ESP_IDF_VERSION_MAJOR, ESP_IDF_VERSION_MINOR,
             ESP_IDF_VERSION_PATCH);
}

esp_err_t util_stack_overflow_check() {
    UBaseType_t stack_remaining = uxTaskGetStackHighWaterMark(NULL);
    ESP_LOGD(TAG, "stack words remaining: %u", stack_remaining);

    if (stack_remaining <= 0) {
        ESP_LOGE(TAG, "stack overflow detected!");
        return ESP_FAIL;
    }

    return ESP_OK;
}

void util_stack_print_remaining() {
    ESP_LOGW(TAG, "stack words remaining: %u",
             uxTaskGetStackHighWaterMark(NULL));
}

// A UUID has the format:
//  xxxxxxxx-xxxx-Axxx-Bxxx-xxxxxxxxxxxx
// where A is a 4-bit "version", and B is a 1-to-3-bit "variant". See spec for
// the details on the encoding of B.

#define UUID_VER4_B6_VALUE 0x40
#define MASK_UUID_VER4_B6 0x0F

#define UUID_VER4_VAR1_B8_VALUE 0x80
#define MASK_UUID_VER4_VAR1_B8 0x3F

void util_generate_uuid4(uuid_t *out_uuid) {
    uint8_t *b = out_uuid->b;

    esp_fill_random(b, UUID_BYTE_COUNT);

    b[6] = UUID_VER4_B6_VALUE | (b[6] & MASK_UUID_VER4_B6);
    b[8] = (b[8] & MASK_UUID_VER4_VAR1_B8) | UUID_VER4_VAR1_B8_VALUE;
}

esp_err_t util_print_uuid(char **str, const uuid_t *uuid) {
    const uint8_t *b = uuid->b;

    int ret = asprintf(
        str,
        "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
        b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7], b[8], b[9], b[10],
        b[11], b[12], b[13], b[14], b[15]);

    return ret < 0 ? ESP_FAIL : ESP_OK;
}

uint64_t util_current_epoch_time_ms() {
    struct timeval time;
    assert(!gettimeofday(&time, NULL));

    // TODO This is susceptible to the Y2K38 bug, migrate to fix in esp-idf
    // v5.0.
    return ((uint64_t) time.tv_sec) * 1000 + ((uint64_t) time.tv_usec) / 1000;
}

void util_freertos_print_usage() {
#if configUSE_TRACE_FACILITY
    UBaseType_t num_tasks = uxTaskGetNumberOfTasks();
    TaskStatus_t *pxTaskStatusArray =
        pvPortMalloc(num_tasks * sizeof(TaskStatus_t));
    if (pxTaskStatusArray == NULL) {
        return;
    }

    ESP_LOGW(TAG, "Format: %16s | %8s | %s", "name", "run time", "usage(%)");

    uint32_t total_run_time;
    num_tasks =
        uxTaskGetSystemState(pxTaskStatusArray, num_tasks, &total_run_time);
    if (total_run_time > 0) {
        for (UBaseType_t i = 0; i < num_tasks; i++) {
            uint64_t usage_percent =
                ((uint64_t) pxTaskStatusArray[i].ulRunTimeCounter) * 100ULL
                / ((uint64_t) total_run_time);
            if (usage_percent > 0UL) {
                ESP_LOGW(TAG, "%16s   %8u   %llu%%",
                         pxTaskStatusArray[i].pcTaskName,
                         pxTaskStatusArray[i].ulRunTimeCounter, usage_percent);
            } else {
                ESP_LOGW(TAG, "%16s   %8u   <1%%",
                         pxTaskStatusArray[i].pcTaskName,
                         pxTaskStatusArray[i].ulRunTimeCounter);
            }
        }
    }

    vPortFree(pxTaskStatusArray);
#else
    ESP_LOGE(TAG,
             "You must set `CONFIG_FREERTOS_RUN_TIME_STATS_USING_ESP_TIMER=y` "
             "in order to use this function.");
    abort();
#endif
}
