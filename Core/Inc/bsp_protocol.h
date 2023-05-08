//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_PROTOCOL_H
#define APARCONTROLLERSLAVE_BSP_PROTOCOL_H

#include "bsp_types.h"

/* CONSTANTS */
#define FRAME_MAXLEN 512 // the maximum length of frame.


typedef struct
{
    u8 type;
    u16 len;
    u8 content[FRAME_MAXLEN+10];
    u8 verified;
} FrameTypeDef;

/* Functions */

/**
 * parse the frame to the frame's struct g_frame.
 * @param frame the frame to be parsed.
 * @return 1 for successful, 0 for failed.
*/
int parseFrame(const u8* frame_bytes, FrameTypeDef* frame);

/**
 * generate the frame from the content and type.
 * @param content the content of the frame
 * @param type the type of the frame
 * @param frame the recv mem of the generated frame.
 * @param len the length of the content
 * @return 1 for succeed, 0 for failed.
*/
int generateFrame(const u8* content, u8 type, u8* frame_bytes, int len);


#endif //APARCONTROLLERSLAVE_BSP_PROTOCOL_H
