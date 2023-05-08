//
// Created by IamZh on 2023/5/8.
//

#include <memory.h>
#include "bsp_protocol.h"
#include "bsp_utils.h"
#include "bsp_crclib.h"

int parseFrame(const u8* frame_bytes, FrameTypeDef* frame){
    /* Parse the FrameTypeDef */
    u8 header[2] = "BI";
    if(memcmp(frame_bytes,header,2)!=0) return 0;
    // get frame type.
    frame->type = *(frame_bytes + 2);
    frame->len = bytes_to_u16(frame_bytes + 3);
    if(frame->len > FRAME_MAXLEN) return 0;

    memcpy(frame->content, frame_bytes + 5, frame->len);
    frame->verified = *(frame_bytes + 5 + frame->len); // get verified code
    u8 crc_code = crc8_maxim(frame_bytes+2, frame->len + 3);
    if(crc_code != frame->verified) return 0;
    return 1;
}

int generateFrame(const u8* content, u8 type, u8* frame_bytes, int len){
    frame_bytes[0] = 'B';
    frame_bytes[1] = 'I';
    frame_bytes[2] = type;
    u8 len_bytes[2];
    i16_to_bytes(len,len_bytes);
    memcpy(frame_bytes+3,len_bytes,2);
    memcpy(frame_bytes+5,content,len);
    frame_bytes[len+5] = crc8_maxim(frame_bytes+2,len+3);
    frame_bytes[len+6] = 'T';

    return 1;
}