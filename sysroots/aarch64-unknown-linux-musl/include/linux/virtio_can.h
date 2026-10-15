/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _LINUX_VIRTIO_VIRTIO_CAN_H
#define _LINUX_VIRTIO_VIRTIO_CAN_H
#include <linux/types.h>
#include <linux/virtio_types.h>
#include <linux/virtio_ids.h>
#include <linux/virtio_config.h>
#define VIRTIO_CAN_F_CAN_CLASSIC 0
#define VIRTIO_CAN_F_CAN_FD 1
#define VIRTIO_CAN_F_RTR_FRAMES 2
#define VIRTIO_CAN_F_LATE_TX_ACK 3
#define VIRTIO_CAN_RESULT_OK 0
#define VIRTIO_CAN_RESULT_NOT_OK 1
#define VIRTIO_CAN_FLAGS_EXTENDED 0x8000
#define VIRTIO_CAN_FLAGS_FD 0x4000
#define VIRTIO_CAN_FLAGS_RTR 0x2000
#define VIRTIO_CAN_MAX_DLEN 64
struct virtio_can_config {
#define VIRTIO_CAN_S_CTRL_BUSOFF (1u << 0)
  __le16 status;
};
struct virtio_can_tx_out {
#define VIRTIO_CAN_TX 0x0001
  __le16 msg_type;
  __le16 length;
  __u8 reserved_classic_dlc;
  __u8 padding;
  __le16 reserved_xl_priority;
  __le32 flags;
  __le32 can_id;
  __u8 sdu[] __counted_by_le(length);
};
struct virtio_can_tx_in {
  __u8 result;
};
struct virtio_can_rx {
#define VIRTIO_CAN_RX 0x0101
  __le16 msg_type;
  __le16 length;
  __u8 reserved_classic_dlc;
  __u8 padding;
  __le16 reserved_xl_priority;
  __le32 flags;
  __le32 can_id;
  __u8 sdu[] __counted_by_le(length);
};
struct virtio_can_control_out {
#define VIRTIO_CAN_SET_CTRL_MODE_START 0x0201
#define VIRTIO_CAN_SET_CTRL_MODE_STOP 0x0202
  __le16 msg_type;
};
struct virtio_can_control_in {
  __u8 result;
};
#endif
