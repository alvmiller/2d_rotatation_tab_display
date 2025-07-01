#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>

//////////////////////////////////////////////////////////

#define HEIGHT_SRC UINT32_C(15)
#define HEIGHT_DST UINT32_C(15)
#define WIDTH_SRC  UINT32_C(10)
#define WIDTH_DST  UINT32_C(10)

//uint32_t src[HEIGHT_SRC * WIDTH_SRC] = { [HEIGHT_SRC * WIDTH_SRC-1] = 0x11111111 };
const uint32_t src[HEIGHT_SRC * WIDTH_SRC] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x11111111, 0x66666666, 0xbbbbbbbb, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x22222222, 0x77777777, 0xcccccccc, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x33333333, 0x88888888, 0xdddddddd, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x44444444, 0x99999999, 0xeeeeeeee, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x55555555, 0xaaaaaaaa, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};
uint32_t dst[HEIGHT_DST * WIDTH_SRC] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

#define PIXEL_SIZE (sizeof(uint32_t))
#define SURFACE_THEORETICAL_MAX_SIZE (UINT32_MAX / PIXEL_SIZE)
#define SURFACE_THEORETICAL_MAX_COORDINATE (SURFACE_THEORETICAL_MAX_SIZE - 1)

#define NO_OP      UINT32_C(0x00)
#define FLIP_V     UINT32_C(0x04)
#define FLIP_H     UINT32_C(0x08)
#define ROTATE_90  UINT32_C(0x01)
#define ROTATE_180 UINT32_C(0x02)
#define ROTATE_270 UINT32_C(0x03)
#define INVERT_R   UINT32_C(0x10)
#define INVERT_G   UINT32_C(0x20)
#define INVERT_B   UINT32_C(0x40)
#define INVERT_A   UINT32_C(0x80)

//////////////////////////////////////////////////////////

struct point_yx_t {
    int32_t y;
    int32_t x;
};

struct point_angle_t {
    int32_t sin;
    int32_t cos;
};

/* For common case (external user usage), we should add rectangle here
 * and flags for pre-calculations (is_dual_calculated, etc.)
 * or not valid default values
 * and check all input values */
struct image_processing_t {
    struct point_yx_t center;
    struct point_yx_t dual_center;
    struct point_angle_t angle;
    struct point_yx_t flip;
    struct point_yx_t rotate;
    struct point_yx_t distance;
};

struct pixel_coordinate {
    uint32_t y;
    uint32_t x;
};

struct rectangle_coordinate {
    struct pixel_coordinate top_left;
    struct pixel_coordinate bottom_right;
};

//////////////////////////////////////////////////////////

/*
 * INT32_MIN  (-2147483648)
 * INT32_MAX  (2147483647)
 * UINT32_MAX (4294967295)
 * PIXEL_SIZE (4)
 * UINT32_MAX/PIXEL_SIZE (1073741823)
 */

#define GET_INVERTED_COLOR(_inverted, _basic, _color_mask) \
    ({ \
        (_inverted) = (_basic) ^ (_color_mask); \
        \
        (_inverted); \
    })

/* 'distance.x' and 'distance.y': ({-(MAX_UINT32/PIXEL_SIZE-1),...,MAX_UINT32/PIXEL_SIZE-1},
 *                                 {-(MAX_UINT32/PIXEL_SIZE-1),...,MAX_UINT32/PIXEL_SIZE-1})
 * 'basic.x' and 'basic.y': ({-(MAX_UINT32/PIXEL_SIZE-1)/2,...,MAX_UINT32/PIXEL_SIZE-1},
 *                           {-(MAX_UINT32/PIXEL_SIZE-1)/2,...,MAX_UINT32/PIXEL_SIZE-1})
 * Move can not change rectangle geometric
 *
 * Result x and y: ({-(MAX_UINT32/PIXEL_SIZE-1)+-(MAX_UINT32/PIXEL_SIZE-1)/2,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1},
 *                  {-(MAX_UINT32/PIXEL_SIZE-1)+-(MAX_UINT32/PIXEL_SIZE-1)/2,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1})
 * int32_t could be used */
#define GET_MOVED_COORDINATE(_moved, _basic, _coefficient) \
    ({ \
        (_moved).y = (_basic).y + (_coefficient).distance.y; \
        (_moved).x = (_basic).x + (_coefficient).distance.x; \
        \
        (_moved); \
    })

/* 'cos' and 'sin': ({0}|{-1,1}, {-1,1}|{0})
 * 'rotate.x' and 'rotate.y': ({MAX_UINT32/PIXEL_SIZE-1-1,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1+1},
 *                             {MAX_UINT32/PIXEL_SIZE-1-1,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1+1})
 * 'basic.x' and 'basic.y': ({0,...,MAX_UINT32/PIXEL_SIZE-1}, {0,...,MAX_UINT32/PIXEL_SIZE-1})
 * Rotate can change rectangle geometric
 *
 * Result x and y: ({-1,...,MAX_UINT32/PIXEL_SIZE-1+1}, {-1,...,MAX_UINT32/PIXEL_SIZE-1+1})
 * int32_t could be used */
#define GET_ROTATED_COORDINATE(_rotated, _basic, _coefficient) \
    ({ \
        (_rotated).y = (_basic).y * (_coefficient).angle.cos \
                     + (_basic).x * (_coefficient).angle.sin \
                     + (_coefficient).rotate.y; \
        (_rotated).x = (_basic).x * (_coefficient).angle.cos \
                     - (_basic).y * (_coefficient).angle.sin \
                     + (_coefficient).rotate.x; \
        \
        (_rotated); \
    })

/* 'flip.x' and 'flip.y': ({0,1}, {0,1})
 * 'basic.x' and 'basic.y': ({0,...,MAX_UINT32/PIXEL_SIZE}, {0,...,MAX_UINT32/PIXEL_SIZE})
 * 'dual_center.x' and 'dual_center.y': ({0,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1},
 *                                       {0,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1})
 * Flip can not change rectangle geometric
 *
 * Result x and y: ({0,...,MAX_UINT32/PIXEL_SIZE-1}, {0,...,MAX_UINT32/PIXEL_SIZE-1})
 * int32_t could be used */
#define GET_FLIPPED_COORDINATE(_flipped, _basic, _coefficient) \
    ({ \
        (_flipped).y = (_basic).y \
                     * (_coefficient).flip.y \
                     + ((_coefficient).dual_center.y - (_basic).y) \
                     * (int32_t)!(_coefficient).flip.y; \
        (_flipped).x = (_basic).x \
                     * (_coefficient).flip.x \
                     + ((_coefficient).dual_center.x - (_basic).x) \
                     * (int32_t)!(_coefficient).flip.x; \
        \
        (_flipped); \
    })

#define FLOAT_CENTER_N UINT8_C(0x02)

//////////////////////////////////////////////////////////

const uint32_t full_operation = FLIP_V
                              | FLIP_H
                              | ROTATE_90
                              | ROTATE_180
                              | ROTATE_270
                              | INVERT_R
                              | INVERT_G
                              | INVERT_B
                              | INVERT_A;

//const uint32_t operation = NO_OP;
//const uint32_t operation = FLIP_V | FLIP_H | ROTATE_180 | INVERT_A;
//const uint32_t operation = FLIP_V | FLIP_H | ROTATE_90 | INVERT_A;
const uint32_t operation = FLIP_V | FLIP_H | ROTATE_180 | INVERT_A;


const uint32_t src_tl_y = 1;
const uint32_t src_tl_x = 1;
const uint32_t src_br_y = 3;
const uint32_t src_br_x = 3;
const uint32_t dst_tl_y = 6;
const uint32_t dst_tl_x = 6;
const uint32_t dst_br_y = 7;
const uint32_t dst_br_x = 7;
const uint32_t min_surf_tl_y = 0;
const uint32_t min_surf_tl_x = 0;
const uint32_t max_surf_br_y = SURFACE_THEORETICAL_MAX_COORDINATE;
const uint32_t max_surf_br_x = SURFACE_THEORETICAL_MAX_COORDINATE;

//////////////////////////////////////////////////////////

/* 'rectangle.x' and 'rectangle.y': ({0,...,MAX_UINT32/PIXEL_SIZE-1},
 *                                   {0,...,MAX_UINT32/PIXEL_SIZE-1})
 *
 * Result x and y: ({0,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1},
 *                  {0,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1})
 *                 ({0,...,MAX_UINT32/PIXEL_SIZE}, {0,...,MAX_UINT32/PIXEL_SIZE})
 * int32_t could be used */
static inline void prepare_center_coordinate(struct image_processing_t *coefficient,
                                             const struct rectangle_coordinate *rectangle)
{
    coefficient->dual_center.y = (int32_t)rectangle->top_left.y
                               + (int32_t)rectangle->bottom_right.y;
    coefficient->dual_center.x = (int32_t)rectangle->top_left.x
                               + (int32_t)rectangle->bottom_right.x;

    coefficient->center.y = coefficient->dual_center.y / 2;
    coefficient->center.x = coefficient->dual_center.x / 2;

    return;
}

static inline void prepare_flip_coefficient(struct image_processing_t *coefficient, uint32_t op)
{
    // All cases (with no flip)
    coefficient->flip.y = ((op & FLIP_V) != 0x0) ? 0 : 1;
    coefficient->flip.x = ((op & FLIP_H) != 0x0) ? 0 : 1;

    return;
}

/* 'center.x' and 'center.y': ({0,...,MAX_UINT32/PIXEL_SIZE-1}, {0,...,MAX_UINT32/PIXEL_SIZE-1})
 * ({-(MAX_UINT32/PIXEL_SIZE-1)/2,...,},
 *               {-(MAX_UINT32/PIXEL_SIZE-1)/2,...,})
 * 'cos' and 'sin': ({0}|{-1,1}, {-1,1}|{0})
 * 'rotate.x' and 'rotate.y': ({-1,0,1}, {-1,0,1})
 *
 * Result x and y: ({0,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1},
 *                  {0,...,MAX_UINT32/PIXEL_SIZE-1+MAX_UINT32/PIXEL_SIZE-1})
 *                 ({0,...,MAX_UINT32/PIXEL_SIZE}, {0,...,MAX_UINT32/PIXEL_SIZE})
 * int32_t could be used */
static inline void prepare_rotate_coefficient(struct image_processing_t *coefficient, uint32_t op)
{
    const struct point_yx_t rotate_coefficient_270[FLOAT_CENTER_N][FLOAT_CENTER_N] = {
        { { .y = 0, .x = 0 }, { .y = 0, .x = 1 } },
        { { .y = 1, .x = -1 }, { .y = 1, .x = 0 } }
    };
    const struct point_yx_t rotate_coefficient_180[FLOAT_CENTER_N][FLOAT_CENTER_N] = {
        { { .y = 0, .x = 0 }, { .y = 0, .x = 1 } },
        { { .y = 1, .x = 0 }, { .y = 1, .x = 1 } }
    };
    const struct point_yx_t rotate_coefficient_90[FLOAT_CENTER_N][FLOAT_CENTER_N] = {
        { { .y = 0, .x = 0 }, { .y = -1, .x = 1 } },
        { { .y = 1, .x = 0 }, { .y = 0, .x = 1 } }
    };
    uint32_t rotate_op = op & ROTATE_270;
    int32_t float_center_y = 0;
    int32_t float_center_x = 0;
    struct point_yx_t rotate_tmp = {};

    float_center_y = coefficient->dual_center.y % 2;
    float_center_x = coefficient->dual_center.x % 2;

    switch (rotate_op) {
    case ROTATE_270:
        rotate_tmp = rotate_coefficient_270[float_center_y][float_center_x];
        coefficient->angle.sin = -1;
        coefficient->angle.cos = 0;
        break;
    case ROTATE_180:
        rotate_tmp = rotate_coefficient_180[float_center_y][float_center_x] ;
        coefficient->angle.sin = 0;
        coefficient->angle.cos = -1;
        break;
    case ROTATE_90:
        rotate_tmp = rotate_coefficient_90[float_center_y][float_center_x];
        coefficient->angle.sin = 1;
        coefficient->angle.cos = 0;
        break;
    default:
        // Default values have already set
        // No rotate, rotate 360, rotate 0
        rotate_tmp.y = 0;
        rotate_tmp.x = 0;
        coefficient->angle.sin = 0;
        coefficient->angle.cos = 1;
        break;
    }

    coefficient->rotate.y = coefficient->center.y
                          - coefficient->center.y * coefficient->angle.cos
                          - coefficient->center.x * coefficient->angle.sin
                          + rotate_tmp.y;
    coefficient->rotate.x = coefficient->center.x
                          - coefficient->center.x * coefficient->angle.cos
                          + coefficient->center.y * coefficient->angle.sin
                          + rotate_tmp.x;

    return;
}

static inline void prepare_move_coefficient(struct image_processing_t *coefficient,
                                            uint32_t op,
                                            const struct rectangle_coordinate *src_rectangle,
                                            const struct rectangle_coordinate *dst_rectangle)
{
    // Map ~ Move

    struct image_processing_t coefficient_tmp = {};
    struct point_yx_t src_coordinate_tmp = {
        .y = (int32_t)src_rectangle->bottom_right.y,
        .x = (int32_t)src_rectangle->top_left.x
    };
    uint32_t op_tmp = ROTATE_90;

    // FLIP_V, FLIP_H, FLIP_VH, ROTATE_180, no flip, no rotate
    struct point_yx_t src_upd_tl = {
        .y = (int32_t)src_rectangle->top_left.y,
        .x = (int32_t)src_rectangle->top_left.x
    };

    if ((op & ROTATE_270) == ROTATE_270 || (op & ROTATE_90) == ROTATE_90) {
        // For 90 and 270 degree we got the same new top left coordinates for rotated source
        // (90 degree - src bottom left -> dst top left; 270 degree - src top right -> dst top left)
        prepare_center_coordinate(&coefficient_tmp, src_rectangle);
        prepare_rotate_coefficient(&coefficient_tmp, ROTATE_90);
        GET_ROTATED_COORDINATE(src_upd_tl, src_coordinate_tmp, coefficient_tmp);
    }

    coefficient->distance.y = (int32_t)dst_rectangle->top_left.y - src_upd_tl.y;
    coefficient->distance.x = (int32_t)dst_rectangle->top_left.x - src_upd_tl.x;

    return;
}

static inline void prepare_inverted_color_mask(uint32_t *color_mask, uint32_t op)
{
    /* !X = 255 - X */

    /* No invert, invert R, invert G, invert B, invert A, invert some and/or all components */
    uint32_t mask_r = ((uint32_t)!!(op & INVERT_R)) * UINT32_C(0xFF000000);
    uint32_t mask_g = ((uint32_t)!!(op & INVERT_G)) * UINT32_C(0x00FF0000);
    uint32_t mask_b = ((uint32_t)!!(op & INVERT_B)) * UINT32_C(0x0000FF00);
    uint32_t mask_alpha = ((uint32_t)!!(op & INVERT_A)) * UINT32_C(0x000000FF);

    *color_mask = mask_r + mask_g + mask_b + mask_alpha;

    return;
}

//////////////////////////////////////////////////////////

static int all_operations(uint32_t *dst,
                          int32_t dst_height,
                          int32_t dst_width,
                          const struct rectangle_coordinate *dst_rectangle,
                          const uint32_t *src,
                          int32_t src_height,
                          int32_t src_width,
                          const struct rectangle_coordinate *src_rectangle,
                          uint32_t op)
{
    struct image_processing_t image_coefficient = {};
    struct point_yx_t src_ji = {};
    struct point_yx_t src_flipped_ji = {};
    struct point_yx_t dst_ji = {};
    struct point_yx_t src_rotated_ji = {};
    uint32_t src_val = 0x00000000;
    int32_t src_tmp_i = 0;
    int32_t src_tmp_j = 0;
    uint32_t inverted_color_mask = 0x00000000;
    const int32_t src_top_left_y = (int32_t)src_rectangle->top_left.y;
    const int32_t src_top_left_x = (int32_t)src_rectangle->top_left.x;
    const int32_t src_bottom_right_y = (int32_t)src_rectangle->bottom_right.y;
    const int32_t src_bottom_right_x = (int32_t)src_rectangle->bottom_right.x;

    (void)src_tmp_j;

    //------------------------------------------------------------------------------

    if (op != NO_OP && (op & ~full_operation) != 0) {
        printf("ERROR: bad operation (%#x)\n", op);
        return -1;
    }

    if (dst_height <= 0
     || dst_width <= 0
     || dst_height > (int32_t)SURFACE_THEORETICAL_MAX_SIZE
     || dst_width > (int32_t)SURFACE_THEORETICAL_MAX_SIZE) {
        printf("ERROR: bad coordinates\n");
        return -1;
    }

    if (src_height <= 0
     || src_width <= 0
     || src_height > (int32_t)SURFACE_THEORETICAL_MAX_SIZE
     || src_width > (int32_t)SURFACE_THEORETICAL_MAX_SIZE) {
        printf("ERROR: bad coordinates\n");
        return -2;
    }

    if (dst_rectangle->top_left.y < 0
     || dst_rectangle->top_left.x < 0
     || dst_rectangle->bottom_right.y >= dst_height
     || dst_rectangle->bottom_right.x >= dst_width) {
        printf("ERROR: bad coordinates\n");
        return -3;
    }
    if (src_rectangle->top_left.y < 0
     || src_rectangle->top_left.x < 0
     || src_rectangle->bottom_right.y >= src_height
     || src_rectangle->bottom_right.x >= src_width) {
        printf("ERROR: bad coordinates\n");
        return -4;
    }

    //------------------------------------------------------------------------------

    prepare_center_coordinate(&image_coefficient, src_rectangle);
    prepare_flip_coefficient(&image_coefficient, op);
    prepare_rotate_coefficient(&image_coefficient, op);
    prepare_move_coefficient(&image_coefficient, op, src_rectangle, dst_rectangle);

    prepare_inverted_color_mask(&inverted_color_mask, op);

    for (int32_t i = src_top_left_y; i <= src_bottom_right_y; ++i) {
        src_ji.y = i;
        src_tmp_i = i * src_width;
        for (int32_t j = src_top_left_x; j <= src_bottom_right_x; ++j) {
            src_ji.x = j;
            src_val = src[src_tmp_i + j];
//            printf(">>> Color = %8x\n", src_val);
//            printf(">>> Src (y, x) = (%lld, %lld)\n",
//                   (long long int)src_ji.y, (long long int)src_ji.x);

            GET_FLIPPED_COORDINATE(src_flipped_ji, src_ji, image_coefficient);
//            printf(">>> Flipped (y, x) = (%lld, %lld)\n",
//                   (long long int)src_flipped_ji.y, (long long int)src_flipped_ji.x);

            GET_ROTATED_COORDINATE(src_rotated_ji, src_flipped_ji, image_coefficient);
//            printf(">>> Rotated (y, x) = (%lld, %lld)\n",
//                   (long long int)src_rotated_ji.y, (long long int)src_rotated_ji.x);

            GET_MOVED_COORDINATE(dst_ji, src_rotated_ji, image_coefficient);
//            printf(">>> Moved (y, x) = (%lld, %lld)\n",
//                   (long long int)dst_ji.y, (long long int)dst_ji.x);

            if (dst_ji.y < (int32_t)dst_rectangle->top_left.y
             || dst_ji.x < (int32_t)dst_rectangle->top_left.x
             || dst_ji.y > (int32_t)dst_rectangle->bottom_right.y
             || dst_ji.x > (int32_t)dst_rectangle->bottom_right.x) {
                printf(" >>> Error coordinates (out of Dst): Src (y, x) = (%lld, %lld), Dst(y, x) = (%lld, %lld)\n",
                       (long long int)src_ji.y, (long long int)src_ji.x, (long long int)dst_ji.y, (long long int)dst_ji.x);
                continue;
            }

            GET_INVERTED_COLOR(src_val, src_val, inverted_color_mask);
//            printf(">>> Inverted color = %8x\n", src_val);

            dst[dst_ji.y * dst_width + dst_ji.x] = src_val;
        }
    }

    return 0;
}

//////////////////////////////////////////////////////////

static void print_header(void)
{
    printf("\n");

    printf("Surf: TLy = %2u, TLx = %2u, BRy = %2u, BRx = %2u\n",
           min_surf_tl_y, min_surf_tl_x, max_surf_br_y, max_surf_br_x);
    printf("Src:  TLy = %2u, TLx = %2u, BRy = %2u, BRx = %2u\n",
           src_tl_y, src_tl_x, src_br_y, src_br_x);
    printf("Src:  Full Height = %2u, Width = %2u\n", HEIGHT_SRC, WIDTH_SRC);
    printf("Src:  Height = %2u, Width = %2u\n", src_br_y - src_tl_y + 1, src_br_x - src_tl_x + 1);
    printf("Dst:  TLy = %2u, TLx = %2u, BRy = %2u, BRx = %2u\n",
           dst_tl_y, dst_tl_x, dst_br_y, dst_br_x);
    printf("Dst:  Full Height = %2u, Width = %2u\n", HEIGHT_DST, WIDTH_DST);
    printf("Dst:  Height = %2u, Width = %2u\n", dst_br_y - dst_tl_y + 1, dst_br_x - dst_tl_x + 1);

    printf("Operations:\n");
    if ((operation & FLIP_V) == FLIP_V) {
        printf("    FLIP_V\n");
    }
    if ((operation & FLIP_H) == FLIP_H) {
        printf("    FLIP_H\n");
    }
    if ((operation & ROTATE_270) == ROTATE_270) {
        printf("    ROTATE_270\n");
    } else if ((operation & ROTATE_180) == ROTATE_180) {
        printf("    ROTATE_180\n");
    } else if ((operation & ROTATE_90) == ROTATE_90) {
        printf("    ROTATE_90\n");
    }
    if ((operation & INVERT_R) == INVERT_R) {
        printf("    INVERT_R\n");
    }
    if ((operation & INVERT_G) == INVERT_G) {
        printf("    INVERT_G\n");
    }
    if ((operation & INVERT_B) == INVERT_B) {
        printf("    INVERT_B\n");
    }
    if ((operation & INVERT_A) == INVERT_A) {
        printf("    INVERT_A\n");
    }
    if ((operation & full_operation) == 0) {
        printf("    NO_OP\n");
    }
    if (operation == NO_OP) {
        printf("    NO_OP\n");
    }

    printf("SRC: Center Y = %u\n", (uint32_t)((src_tl_y + src_br_y) /2));
    printf("SRC: Center X = %u\n", (uint32_t)((src_tl_x + src_br_x) /2));
    if ((src_tl_y + src_br_y) % 2 != 0) {
        printf("SRC: Floated Y\n");
    }
    if ((src_tl_x + src_br_x) % 2 != 0) {
        printf("SRC: Floated X\n");
    }

    printf("DST-SRC: Y = %lld\n", (long long int)((int32_t)dst_tl_y - (int32_t)src_tl_y));
    printf("DST-SRC: X = %lld\n", (long long int)((int32_t)dst_tl_x - (int32_t)src_tl_x));

    printf("\n");
    return;
}

static void print_surf(const uint32_t *arr,
                       uint32_t start_y,
                       uint32_t start_x,
                       uint32_t height,
                       uint32_t width,
                       uint32_t real_height,
                       uint32_t real_width,
                       char *str)
{
    const uint32_t max_size_val = 30;

    printf("\n\n");

    if (width > max_size_val) {
        printf("Too big X data....\n");
        return;
    }
    if (height > max_size_val) {
        printf("Too big Y data....\n");
        return;
    }

    printf("Surf: %s\n", str);

    printf("\n");
    printf("             ");
    for(size_t k = start_x; k < start_x + width; ++k) {
        printf("%8lu  ", k);
    }
    printf("\n           ");
    for(size_t k = start_x; k < start_x + width; ++k) {
        printf("         _");
    }
    printf("\n");
    printf("\n\n");
    for (size_t i = start_y; i < start_y + height; ++i) {
        printf("\n");
        printf("%8lu|    ", i);
        for (size_t j = start_x; j < start_x + width; ++j) {
            printf("%8x  ", arr[i * real_width + j]);
        }
    }

    printf("\n\n");
    return;
}

//////////////////////////////////////////////////////////

int main()
{
    const struct rectangle_coordinate src_rectangle = {
        .top_left = {
            .y = src_tl_y,
            .x = src_tl_x
        },
        .bottom_right = {
            .y = src_br_y,
            .x = src_br_x
        }
    };
    const struct rectangle_coordinate dst_rectangle = {
        .top_left = {
            .y = dst_tl_y,
            .x = dst_tl_x
        },
        .bottom_right = {
            .y = dst_br_y,
            .x = dst_br_x
        }
    };
    int ret = -1;

    // src - const!
    memset(dst, 0x00, sizeof(uint32_t) * WIDTH_DST * HEIGHT_DST);

    print_header();

    printf("--------------------------------------------------------------------\n");
    printf("Do Operations:\n");

    ret = all_operations(dst,
                         HEIGHT_DST,
                         WIDTH_DST,
                         &dst_rectangle,
                         src,
                         HEIGHT_SRC,
                         WIDTH_SRC,
                         &src_rectangle,
                         operation);
    if (ret != 0) {
        printf("\t>>> ERROR: all_operations issue (%d) <<<\t\n", ret);
        return -1;
    }

    printf("--------------------------------------------------------------------\n");

    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("Resulted Operations:\n");
    print_surf(src, 0, 0, HEIGHT_SRC, WIDTH_SRC, HEIGHT_SRC, WIDTH_SRC, "SRC");
    print_surf(dst, 0, 0, HEIGHT_DST, WIDTH_DST, HEIGHT_SRC, WIDTH_SRC, "DST");
    print_surf(src,
               src_tl_y,
               src_tl_x,
               src_br_y - src_tl_y + 1,
               src_br_x - src_tl_x + 1,
               HEIGHT_SRC,
               WIDTH_SRC,
               "SRC (data only)");
    print_surf(dst,
               dst_tl_y,
               dst_tl_x,
               dst_br_y - dst_tl_y + 1,
               dst_br_x - dst_tl_x + 1,
               HEIGHT_SRC,
               WIDTH_SRC,
               "DST (data only)");
    printf("--------------------------------------------------------------------\n");
    printf("\n");

    printf("\n");
    return ret;
}
