#pragma once

#include <stdint.h>
#include <sys/cdefs.h>

///// Builder macros

#define MARSHAL_FN_QUALIFIERS static __always_inline

// Args version: 1 out arg

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT1(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,       \
                                                      in_type o0) {       \
        in_type o[1] = {o0};                                              \
        marshall_##name(v0, o);                                           \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT1(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,       \
                                                      in_type o0,         \
                                                      in_type o1) {       \
        in_type o[2] = {o0, o1};                                          \
        marshall_##name(v0, o);                                           \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT1(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2) {           \
        in_type o[3] = {o0, o1, o2};                                          \
        marshall_##name(v0, o);                                               \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT1(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2,             \
                                                      in_type o3) {           \
        in_type o[4] = {o0, o1, o2, o3};                                      \
        marshall_##name(v0, o);                                               \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT1(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2, in_type o3, \
                                                      in_type o4) {           \
        in_type o[5] = {o0, o1, o2, o3, o4};                                  \
        marshall_##name(v0, o);                                               \
    }

// Args version: 2 out args

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT2(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,       \
                                                      out_type* v1,       \
                                                      in_type o0) {       \
        in_type o[1] = {o0};                                              \
        marshall_##name(v0, v1, o);                                       \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT2(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,       \
                                                      out_type* v1,       \
                                                      in_type o0,         \
                                                      in_type o1) {       \
        in_type o[2] = {o0, o1};                                          \
        marshall_##name(v0, v1, o);                                       \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT2(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      out_type* v1,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2) {           \
        in_type o[3] = {o0, o1, o2};                                          \
        marshall_##name(v0, v1, o);                                           \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT2(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      out_type* v1,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2,             \
                                                      in_type o3) {           \
        in_type o[4] = {o0, o1, o2, o3};                                      \
        marshall_##name(v0, v1, o);                                           \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT2(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      out_type* v1,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2, in_type o3, \
                                                      in_type o4) {           \
        in_type o[5] = {o0, o1, o2, o3, o4};                                  \
        marshall_##name(v0, v1, o);                                           \
    }

// Args version: 3 out args

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT3(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,       \
                                                      out_type* v1,       \
                                                      out_type* v2,       \
                                                      in_type o0) {       \
        in_type o[1] = {o0};                                              \
        marshall_##name(v0, v1, v2, o);                                   \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT3(name, in_type, out_type)   \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(                      \
        out_type* v0, out_type* v1, out_type* v2, in_type o0, in_type o1) { \
        in_type o[2] = {o0, o1};                                            \
        marshall_##name(v0, v1, v2, o);                                     \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT3(name, in_type, out_type)     \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(out_type* v0,           \
                                                      out_type* v1,           \
                                                      out_type* v2,           \
                                                      in_type o0, in_type o1, \
                                                      in_type o2) {           \
        in_type o[3] = {o0, o1, o2};                                          \
        marshall_##name(v0, v1, v2, o);                                       \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT3(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(                    \
        out_type* v0, out_type* v1, out_type* v2, in_type o0, in_type o1, \
        in_type o2, in_type o3) {                                         \
        in_type o[4] = {o0, o1, o2, o3};                                  \
        marshall_##name(v0, v1, v2, o);                                   \
    }

#define DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT3(name, in_type, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_args(                    \
        out_type* v0, out_type* v1, out_type* v2, in_type o0, in_type o1, \
        in_type o2, in_type o3, in_type o4) {                             \
        in_type o[5] = {o0, o1, o2, o3, o4};                              \
        marshall_##name(v0, v1, v2, o);                                   \
    }

// `double` version macros

#define DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT1_CORE(name, in_type,  \
                                                             in_n, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_cast_double(                \
        double* v0, const in_type o[in_n]) {                                 \
        out_type v[1];                                                       \
        marshall_##name(&v[0], o);                                           \
                                                                             \
        *v0 = (double) v[0];                                                 \
    }

#define DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT2_CORE(name, in_type,  \
                                                             in_n, out_type) \
    MARSHAL_FN_QUALIFIERS void marshall_##name##_cast_double(                \
        double* v0, double* v1, const in_type o[in_n]) {                     \
        out_type v[2];                                                       \
        marshall_##name(&v[0], &v[1], o);                                    \
                                                                             \
        *v0 = (double) v[0];                                                 \
        *v1 = (double) v[1];                                                 \
    }

// Aux versions: 1 out arg

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT1_CORE(name, in_type, 1, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT1(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT1(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT1(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT1_CORE(name, in_type, 2, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT1(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT1(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT1(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT1_CORE(name, in_type, 3, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT1(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT1(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN4_OUT1(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT1_CORE(name, in_type, 4, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT1(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT1(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN5_OUT1(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT1_CORE(name, in_type, 5, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT1(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT1(name##_cast_double, in_type,  \
                                             double);

// Aux versions: 2 out args

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT2(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT2_CORE(name, in_type, 1, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT2(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT2(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT2(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT2_CORE(name, in_type, 2, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT2(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT2(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT2(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT2_CORE(name, in_type, 3, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT2(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT2(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN4_OUT2(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT2_CORE(name, in_type, 4, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT2(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT2(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN5_OUT2(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT2_CORE(name, in_type, 5, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT2(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT2(name##_cast_double, in_type,  \
                                             double);

// Aux versions: 3 out args

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT3(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT3_CORE(name, in_type, 1, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT3(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN1_OUT3(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT3(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT3_CORE(name, in_type, 2, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT3(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN2_OUT3(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT3(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT3_CORE(name, in_type, 3, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT3(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN3_OUT3(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN4_OUT3(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT3_CORE(name, in_type, 4, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT3(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN4_OUT3(name##_cast_double, in_type,  \
                                             double);

#define DEFINE_MARSHALL_FNS_ALL_AUX_IN5_OUT3(name, in_type, out_type)      \
    DEFINE_MARSHALL_FN_CAST_DOUBLE_VERSION_INn_OUT3_CORE(name, in_type, 5, \
                                                         out_type);        \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT3(name, in_type, out_type);     \
    DEFINE_MARSHALL_FN_ARGS_VERSION_IN5_OUT3(name##_cast_double, in_type,  \
                                             double);

///// Marshalling functions

// Sign extension helpers
// (Required since conversion from uints to ints of strange bit-widths in two's
// complement requires setting some high bits.)

MARSHAL_FN_QUALIFIERS void marshall_1u8_sign_extend(int8_t* v0,
                                                    const uint8_t o[1]) {
    uint8_t u = o[0];
    *v0 = (int8_t) u;
}

MARSHAL_FN_QUALIFIERS void marshall_1u12_sign_extend(int16_t* v0,
                                                     const uint16_t o[1]) {
    uint16_t u = ((o[0] & 0x0800ULL) ? 0xF000ULL : 0) | o[0];
    *v0 = (int16_t) u;
}

MARSHAL_FN_QUALIFIERS void marshall_1u16_sign_extend(int16_t* v0,
                                                     const uint16_t o[1]) {
    uint16_t u = o[0];
    *v0 = (int16_t) u;
}

MARSHAL_FN_QUALIFIERS void marshall_1u20_sign_extend(int32_t* v0,
                                                     const uint32_t o[1]) {
    uint32_t u = ((o[0] & 0x00080000ULL) ? 0xFFF00000ULL : 0) | o[0];
    *v0 = (int32_t) u;
}

MARSHAL_FN_QUALIFIERS void marshall_1u24_sign_extend(int32_t* v0,
                                                     const uint32_t o[1]) {
    uint32_t u = ((o[0] & 0x00800000ULL) ? 0xFF000000ULL : 0) | o[0];
    *v0 = (int32_t) u;
}

MARSHAL_FN_QUALIFIERS void marshall_1u32_sign_extend(int32_t* v0,
                                                     const uint32_t o[1]) {
    uint32_t u = o[0];
    *v0 = (int32_t) u;
}

DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u8_sign_extend, uint8_t, int8_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u12_sign_extend, uint16_t, int16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u16_sign_extend, uint16_t, int16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u20_sign_extend, uint32_t, int32_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u24_sign_extend, uint32_t, int32_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u32_sign_extend, uint32_t, int32_t);

// No endianness

MARSHAL_FN_QUALIFIERS void marshall_1u8_to_1u8(uint8_t* v0,
                                               const uint8_t o[1]) {
    *v0 = o[0];
}

MARSHAL_FN_QUALIFIERS void marshall_1u8_to_1i8(int8_t* v0, const uint8_t o[1]) {
    uint8_t u[1];
    marshall_1u8_to_1u8(&u[0], o);
    marshall_1u8_sign_extend(v0, &u[0]);
}

DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u8_to_1u8, uint8_t, uint8_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT1(1u8_to_1i8, uint8_t, int8_t);

// Little endian

MARSHAL_FN_QUALIFIERS void marshall_2u8_to_1u16_le(uint16_t* v0,
                                                   const uint8_t o[2]) {
    *v0 = (((uint16_t) o[0]) << 0) | (((uint16_t) o[1]) << 8);
}

MARSHAL_FN_QUALIFIERS void marshall_2u8_to_1i16_le(int16_t* v0,
                                                   const uint8_t o[2]) {
    uint16_t u[1];
    marshall_2u8_to_1u16_le(&u[0], o);
    marshall_1u16_sign_extend(v0, &u[0]);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_2u12_le(uint16_t* v0, uint16_t* v1,
                                                   const uint8_t o[3]) {
    *v0 = (((uint16_t) o[2]) << 4) | ((((uint16_t) o[1]) & 0xF0) >> 4);
    *v1 = ((((uint16_t) o[1]) & 0x0F) << 8) | (((uint16_t) o[0]) >> 0);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_2i12_le(int16_t* v0, int16_t* v1,
                                                   const uint8_t o[3]) {
    uint16_t u[2];
    marshall_3u8_to_2u12_le(&u[0], &u[1], o);

    // Note that we need to perform "sign extension" to extend a 12-bit signed
    // value into a 16-bit signed value (in two's complement).
    marshall_1u12_sign_extend(v0, &u[0]);
    marshall_1u12_sign_extend(v1, &u[1]);
}

DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT1(2u8_to_1u16_le, uint8_t, uint16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT1(2u8_to_1i16_le, uint8_t, int16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT2(3u8_to_2u12_le, uint8_t, uint16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT2(3u8_to_2i12_le, uint8_t, int16_t);

// Big endian

MARSHAL_FN_QUALIFIERS void marshall_1u16_to_2u8_be(uint8_t* v0, uint8_t* v1,
                                                   const uint16_t o[1]) {
    *v0 = (o[0] & 0xFF00) >> 8;
    *v1 = (o[0] & 0x00FF) >> 0;
}

MARSHAL_FN_QUALIFIERS void marshall_2u8_to_1u16_be(uint16_t* v0,
                                                   const uint8_t o[2]) {
    *v0 = (((uint16_t) o[0]) << 8) | (((uint16_t) o[1]) << 0);
}

MARSHAL_FN_QUALIFIERS void marshall_2u8_to_1i16_be(int16_t* v0,
                                                   const uint8_t o[2]) {
    uint16_t u[0];
    marshall_2u8_to_1u16_be(u, o);
    marshall_1u16_sign_extend(v0, &u[0]);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_1u24_be(uint32_t* v0,
                                                   const uint8_t o[3]) {
    *v0 = (((uint32_t) o[0]) << 16) | (((uint32_t) o[1]) << 8)
          | (((uint32_t) o[2]) << 0);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_1i24_be(int32_t* v0,
                                                   const uint8_t o[3]) {
    uint32_t u[1];
    marshall_3u8_to_1u24_be(&u[0], o);

    // Note that we need to perform "sign extension" to extend a 24-bit signed
    // value into a 32-bit signed value (in two's complement).
    marshall_1u24_sign_extend(v0, &u[0]);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_2u12_be(uint16_t* v0, uint16_t* v1,
                                                   const uint8_t o[2]) {
    *v0 = (((uint16_t) o[0]) << 4) | (((uint16_t) o[1]) >> 4);
    *v1 = (((uint16_t) o[1] & 0x0F) << 8) | (((uint16_t) o[2]) >> 0);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_2i12_be(int16_t* v0, int16_t* v1,
                                                   const uint8_t o[2]) {
    uint16_t u[2];
    marshall_3u8_to_2u12_be(&u[0], &u[1], o);

    // Note that we need to perform "sign extension" to extend a 12-bit signed
    // value into a 16-bit signed value (in two's complement).
    marshall_1u12_sign_extend(v0, &u[0]);
    marshall_1u12_sign_extend(v1, &u[1]);
}

MARSHAL_FN_QUALIFIERS void marshall_5u8_to_2u20_be(uint32_t* v0, uint32_t* v1,
                                                   const uint8_t o[5]) {
    *v0 = (((uint32_t) o[0]) << 12) | (((uint32_t) o[1]) << 4)
          | ((((uint32_t) o[2]) & 0xF0) >> 4);
    *v1 = ((((uint32_t) o[2]) & 0x0F) << 16) | (((uint32_t) o[3]) << 8)
          | (((uint32_t) o[4]) >> 0);
}

MARSHAL_FN_QUALIFIERS void marshall_5u8_to_2i20_be(int32_t* v0, int32_t* v1,
                                                   const uint8_t o[5]) {
    uint32_t u[2];
    marshall_5u8_to_2u20_be(&u[0], &u[1], o);

    // Note that we need to perform "sign extension" to extend a 12-bit signed
    // value into a 16-bit signed value (in two's complement).
    marshall_1u20_sign_extend(v0, &u[0]);
    marshall_1u20_sign_extend(v1, &u[1]);
}

DEFINE_MARSHALL_FNS_ALL_AUX_IN1_OUT2(1u16_to_2u8_be, uint16_t, uint8_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT1(2u8_to_1u16_be, uint8_t, uint16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT1(2u8_to_1i16_be, uint8_t, int16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT1(3u8_to_1u24_be, uint8_t, uint32_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT1(3u8_to_1i24_be, uint8_t, int32_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT2(3u8_to_2u12_be, uint8_t, uint16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT2(3u8_to_2i12_be, uint8_t, int16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN5_OUT2(5u8_to_2i20_be, uint8_t, int32_t);

MARSHAL_FN_QUALIFIERS void marshall_2u16_to_1f32_be(float* v0,
                                                    const uint16_t o[2]) {
    uint32_t u0 = (((uint32_t) o[0]) << 16) | (((uint32_t) o[1]) << 0);

    union {
        uint32_t u;
        float v;
    } temp;
    temp.u = u0;

    *v0 = temp.v;
}

DEFINE_MARSHALL_FNS_ALL_AUX_IN2_OUT1(2u16_to_1f32_be, uint16_t, float);

// Estoteric endiannesses

// "Outer-Big endianness"

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_2u12_ole(uint16_t* v0, uint16_t* v1,
                                                    const uint8_t o[3]) {
    *v0 = (((uint16_t) o[0]) << 4) | ((((uint16_t) o[1]) & 0x0F) << 0);
    *v1 = (((uint16_t) o[2]) << 4) | ((((uint16_t) o[1]) & 0xF0) >> 4);
}

MARSHAL_FN_QUALIFIERS void marshall_3u8_to_2i12_ole(int16_t* v0, int16_t* v1,
                                                    const uint8_t o[3]) {
    uint16_t u[2];
    marshall_3u8_to_2u12_ole(&u[0], &u[1], o);

    // Note that we need to perform "sign extension" to extend a 12-bit signed
    // value into a 16-bit signed value (in two's complement).
    marshall_1u12_sign_extend(v0, &u[0]);
    marshall_1u12_sign_extend(v1, &u[1]);
}

DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT2(3u8_to_2u12_ole, uint8_t, uint16_t);
DEFINE_MARSHALL_FNS_ALL_AUX_IN3_OUT2(3u8_to_2i12_ole, uint8_t, int16_t);
