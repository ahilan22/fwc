#pragma once

#include <cJSON.h>

#define cJSON_CREATE_ROOT_OBJ_OR_GOTO(ptr, label)   \
    do {                                            \
        cJSON* _libesp_json = cJSON_CreateObject(); \
        *(ptr) = _libesp_json;                      \
        if (!_libesp_json) {                        \
            goto label;                             \
        }                                           \
    } while (0)

#define cJSON_INSERT_OBJ_INTO_OBJ_OR_GOTO(parent, str_name, ptr, label) \
    do {                                                                \
        cJSON* _libesp_json = cJSON_CreateObject();                     \
        *(ptr) = _libesp_json;                                          \
        if (!_libesp_json) {                                            \
            goto label;                                                 \
        }                                                               \
        cJSON_AddItemToObject(parent, str_name, _libesp_json);          \
    } while (0)

#define cJSON_INSERT_OBJ_INTO_ARRAY_OR_GOTO(parent, ptr, label) \
    do {                                                        \
        cJSON* _libesp_json = cJSON_CreateObject();             \
        *(ptr) = _libesp_json;                                  \
        if (!_libesp_json) {                                    \
            goto label;                                         \
        }                                                       \
        cJSON_AddItemToArray(parent, _libesp_json);             \
    } while (0)

#define cJSON_INSERT_ARRAY_INTO_OBJ_OR_GOTO(parent, str_name, ptr, label) \
    do {                                                                  \
        cJSON* _libesp_json = cJSON_CreateArray();                        \
        *(ptr) = _libesp_json;                                            \
        if (!_libesp_json) {                                              \
            goto label;                                                   \
        }                                                                 \
        cJSON_AddItemToObject(parent, str_name, _libesp_json);            \
    } while (0)

#define cJSON_INSERT_BOOL_INTO_OBJ_OR_GOTO(parent, str_name, val, label) \
    do {                                                                 \
        cJSON* _libesp_json = cJSON_CreateBool((val));                   \
        if (!_libesp_json) {                                             \
            goto label;                                                  \
        }                                                                \
        cJSON_AddItemToObject(parent, str_name, _libesp_json);           \
    } while (0)

#define cJSON_INSERT_BOOL_INTO_ARRAY_OR_GOTO(parent, val, label) \
    do {                                                         \
        cJSON* _libesp_json = cJSON_CreateBool((val));           \
        if (!_libesp_json) {                                     \
            goto label;                                          \
        }                                                        \
        cJSON_AddItemToArray(parent, _libesp_json);              \
    } while (0)

#define cJSON_INSERT_NUMBER_INTO_OBJ_OR_GOTO(parent, str_name, val, label) \
    do {                                                                   \
        cJSON* _libesp_json = cJSON_CreateNumber((val));                   \
        if (!_libesp_json) {                                               \
            goto label;                                                    \
        }                                                                  \
        cJSON_AddItemToObject(parent, str_name, _libesp_json);             \
    } while (0)

#define cJSON_INSERT_NUMBER_INTO_ARRAY_OR_GOTO(parent, val, label) \
    do {                                                           \
        cJSON* _libesp_json = cJSON_CreateNumber((val));           \
        if (!_libesp_json) {                                       \
            goto label;                                            \
        }                                                          \
        cJSON_AddItemToArray(parent, _libesp_json);                \
    } while (0)

#define cJSON_INSERT_STRINGREF_INTO_OBJ_OR_GOTO(parent, str_name, val, label) \
    do {                                                                      \
        cJSON* _libesp_json = cJSON_CreateStringReference((val));             \
        if (!_libesp_json) {                                                  \
            goto label;                                                       \
        }                                                                     \
        cJSON_AddItemToObject(parent, str_name, _libesp_json);                \
    } while (0)

#define cJSON_INSERT_STRINGREF_INTO_ARRAY_OR_GOTO(parent, val, label) \
    do {                                                              \
        cJSON* _libesp_json = cJSON_CreateStringReference((val));     \
        if (!_libesp_json) {                                          \
            goto label;                                               \
        }                                                             \
        cJSON_AddItemToArray(parent, _libesp_json);                   \
    } while (0)

#define cJSON_INSERT_NULL_INTO_OBJ_OR_GOTO(parent, str_name, label) \
    do {                                                            \
        cJSON* _libesp_json = cJSON_CreateNull();                   \
        if (!_libesp_json) {                                        \
            goto label;                                             \
        }                                                           \
        cJSON_AddItemToObject(parent, str_name, _libesp_json);      \
    } while (0)

#define cJSON_INSERT_NULL_INTO_ARRAY_OR_GOTO(parent, label) \
    do {                                                    \
        cJSON* _libesp_json = cJSON_CreateNull();           \
        if (!_libesp_json) {                                \
            goto label;                                     \
        }                                                   \
        cJSON_AddItemToArray(parent, _libesp_json);         \
    } while (0)
