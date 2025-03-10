/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _V3D_DRM_H_
#define _V3D_DRM_H_
#include "drm.h"
#ifdef __cplusplus
extern "C" {
#endif
#define DRM_V3D_SUBMIT_CL 0x00
#define DRM_V3D_WAIT_BO 0x01
#define DRM_V3D_CREATE_BO 0x02
#define DRM_V3D_MMAP_BO 0x03
#define DRM_V3D_GET_PARAM 0x04
#define DRM_V3D_GET_BO_OFFSET 0x05
#define DRM_V3D_SUBMIT_TFU 0x06
#define DRM_V3D_SUBMIT_CSD 0x07
#define DRM_V3D_PERFMON_CREATE 0x08
#define DRM_V3D_PERFMON_DESTROY 0x09
#define DRM_V3D_PERFMON_GET_VALUES 0x0a
#define DRM_V3D_SUBMIT_CPU 0x0b
#define DRM_V3D_PERFMON_GET_COUNTER 0x0c
#define DRM_IOCTL_V3D_SUBMIT_CL DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_CL, struct drm_v3d_submit_cl)
#define DRM_IOCTL_V3D_WAIT_BO DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_WAIT_BO, struct drm_v3d_wait_bo)
#define DRM_IOCTL_V3D_CREATE_BO DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_CREATE_BO, struct drm_v3d_create_bo)
#define DRM_IOCTL_V3D_MMAP_BO DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_MMAP_BO, struct drm_v3d_mmap_bo)
#define DRM_IOCTL_V3D_GET_PARAM DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_GET_PARAM, struct drm_v3d_get_param)
#define DRM_IOCTL_V3D_GET_BO_OFFSET DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_GET_BO_OFFSET, struct drm_v3d_get_bo_offset)
#define DRM_IOCTL_V3D_SUBMIT_TFU DRM_IOW(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_TFU, struct drm_v3d_submit_tfu)
#define DRM_IOCTL_V3D_SUBMIT_CSD DRM_IOW(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_CSD, struct drm_v3d_submit_csd)
#define DRM_IOCTL_V3D_PERFMON_CREATE DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_PERFMON_CREATE, struct drm_v3d_perfmon_create)
#define DRM_IOCTL_V3D_PERFMON_DESTROY DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_PERFMON_DESTROY, struct drm_v3d_perfmon_destroy)
#define DRM_IOCTL_V3D_PERFMON_GET_VALUES DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_PERFMON_GET_VALUES, struct drm_v3d_perfmon_get_values)
#define DRM_IOCTL_V3D_SUBMIT_CPU DRM_IOW(DRM_COMMAND_BASE + DRM_V3D_SUBMIT_CPU, struct drm_v3d_submit_cpu)
#define DRM_IOCTL_V3D_PERFMON_GET_COUNTER DRM_IOWR(DRM_COMMAND_BASE + DRM_V3D_PERFMON_GET_COUNTER, struct drm_v3d_perfmon_get_counter)
#define DRM_V3D_SUBMIT_CL_FLUSH_CACHE 0x01
#define DRM_V3D_SUBMIT_EXTENSION 0x02
struct drm_v3d_extension {
  __u64 next;
  __u32 id;
#define DRM_V3D_EXT_ID_MULTI_SYNC 0x01
#define DRM_V3D_EXT_ID_CPU_INDIRECT_CSD 0x02
#define DRM_V3D_EXT_ID_CPU_TIMESTAMP_QUERY 0x03
#define DRM_V3D_EXT_ID_CPU_RESET_TIMESTAMP_QUERY 0x04
#define DRM_V3D_EXT_ID_CPU_COPY_TIMESTAMP_QUERY 0x05
#define DRM_V3D_EXT_ID_CPU_RESET_PERFORMANCE_QUERY 0x06
#define DRM_V3D_EXT_ID_CPU_COPY_PERFORMANCE_QUERY 0x07
  __u32 flags;
};
struct drm_v3d_sem {
  __u32 handle;
  __u32 flags;
  __u64 point;
  __u64 mbz[2];
};
enum v3d_queue {
  V3D_BIN,
  V3D_RENDER,
  V3D_TFU,
  V3D_CSD,
  V3D_CACHE_CLEAN,
  V3D_CPU,
};
struct drm_v3d_multi_sync {
  struct drm_v3d_extension base;
  __u64 in_syncs;
  __u64 out_syncs;
  __u32 in_sync_count;
  __u32 out_sync_count;
  __u32 wait_stage;
  __u32 pad;
};
struct drm_v3d_submit_cl {
  __u32 bcl_start;
  __u32 bcl_end;
  __u32 rcl_start;
  __u32 rcl_end;
  __u32 in_sync_bcl;
  __u32 in_sync_rcl;
  __u32 out_sync;
  __u32 qma;
  __u32 qms;
  __u32 qts;
  __u64 bo_handles;
  __u32 bo_handle_count;
  __u32 flags;
  __u32 perfmon_id;
  __u32 pad;
  __u64 extensions;
};
struct drm_v3d_wait_bo {
  __u32 handle;
  __u32 pad;
  __u64 timeout_ns;
};
struct drm_v3d_create_bo {
  __u32 size;
  __u32 flags;
  __u32 handle;
  __u32 offset;
};
struct drm_v3d_mmap_bo {
  __u32 handle;
  __u32 flags;
  __u64 offset;
};
enum drm_v3d_param {
  DRM_V3D_PARAM_V3D_UIFCFG,
  DRM_V3D_PARAM_V3D_HUB_IDENT1,
  DRM_V3D_PARAM_V3D_HUB_IDENT2,
  DRM_V3D_PARAM_V3D_HUB_IDENT3,
  DRM_V3D_PARAM_V3D_CORE0_IDENT0,
  DRM_V3D_PARAM_V3D_CORE0_IDENT1,
  DRM_V3D_PARAM_V3D_CORE0_IDENT2,
  DRM_V3D_PARAM_SUPPORTS_TFU,
  DRM_V3D_PARAM_SUPPORTS_CSD,
  DRM_V3D_PARAM_SUPPORTS_CACHE_FLUSH,
  DRM_V3D_PARAM_SUPPORTS_PERFMON,
  DRM_V3D_PARAM_SUPPORTS_MULTISYNC_EXT,
  DRM_V3D_PARAM_SUPPORTS_CPU_QUEUE,
  DRM_V3D_PARAM_MAX_PERF_COUNTERS,
};
struct drm_v3d_get_param {
  __u32 param;
  __u32 pad;
  __u64 value;
};
struct drm_v3d_get_bo_offset {
  __u32 handle;
  __u32 offset;
};
struct drm_v3d_submit_tfu {
  __u32 icfg;
  __u32 iia;
  __u32 iis;
  __u32 ica;
  __u32 iua;
  __u32 ioa;
  __u32 ios;
  __u32 coef[4];
  __u32 bo_handles[4];
  __u32 in_sync;
  __u32 out_sync;
  __u32 flags;
  __u64 extensions;
  struct {
    __u32 ioc;
    __u32 pad;
  } v71;
};
struct drm_v3d_submit_csd {
  __u32 cfg[7];
  __u32 coef[4];
  __u64 bo_handles;
  __u32 bo_handle_count;
  __u32 in_sync;
  __u32 out_sync;
  __u32 perfmon_id;
  __u64 extensions;
  __u32 flags;
  __u32 pad;
};
struct drm_v3d_indirect_csd {
  struct drm_v3d_extension base;
  struct drm_v3d_submit_csd submit;
  __u32 indirect;
  __u32 offset;
  __u32 wg_size;
  __u32 wg_uniform_offsets[3];
};
struct drm_v3d_timestamp_query {
  struct drm_v3d_extension base;
  __u64 offsets;
  __u64 syncs;
  __u32 count;
  __u32 pad;
};
struct drm_v3d_reset_timestamp_query {
  struct drm_v3d_extension base;
  __u64 syncs;
  __u32 offset;
  __u32 count;
};
struct drm_v3d_copy_timestamp_query {
  struct drm_v3d_extension base;
  __u8 do_64bit;
  __u8 do_partial;
  __u8 availability_bit;
  __u8 pad;
  __u32 offset;
  __u32 stride;
  __u32 count;
  __u64 offsets;
  __u64 syncs;
};
struct drm_v3d_reset_performance_query {
  struct drm_v3d_extension base;
  __u64 syncs;
  __u32 count;
  __u32 nperfmons;
  __u64 kperfmon_ids;
};
struct drm_v3d_copy_performance_query {
  struct drm_v3d_extension base;
  __u8 do_64bit;
  __u8 do_partial;
  __u8 availability_bit;
  __u8 pad;
  __u32 offset;
  __u32 stride;
  __u32 nperfmons;
  __u32 ncounters;
  __u32 count;
  __u64 syncs;
  __u64 kperfmon_ids;
};
struct drm_v3d_submit_cpu {
  __u64 bo_handles;
  __u32 bo_handle_count;
  __u32 flags;
  __u64 extensions;
};
enum {
  V3D_PERFCNT_FEP_VALID_PRIMTS_NO_PIXELS,
  V3D_PERFCNT_FEP_VALID_PRIMS,
  V3D_PERFCNT_FEP_EZ_NFCLIP_QUADS,
  V3D_PERFCNT_FEP_VALID_QUADS,
  V3D_PERFCNT_TLB_QUADS_STENCIL_FAIL,
  V3D_PERFCNT_TLB_QUADS_STENCILZ_FAIL,
  V3D_PERFCNT_TLB_QUADS_STENCILZ_PASS,
  V3D_PERFCNT_TLB_QUADS_ZERO_COV,
  V3D_PERFCNT_TLB_QUADS_NONZERO_COV,
  V3D_PERFCNT_TLB_QUADS_WRITTEN,
  V3D_PERFCNT_PTB_PRIM_VIEWPOINT_DISCARD,
  V3D_PERFCNT_PTB_PRIM_CLIP,
  V3D_PERFCNT_PTB_PRIM_REV,
  V3D_PERFCNT_QPU_IDLE_CYCLES,
  V3D_PERFCNT_QPU_ACTIVE_CYCLES_VERTEX_COORD_USER,
  V3D_PERFCNT_QPU_ACTIVE_CYCLES_FRAG,
  V3D_PERFCNT_QPU_CYCLES_VALID_INSTR,
  V3D_PERFCNT_QPU_CYCLES_TMU_STALL,
  V3D_PERFCNT_QPU_CYCLES_SCOREBOARD_STALL,
  V3D_PERFCNT_QPU_CYCLES_VARYINGS_STALL,
  V3D_PERFCNT_QPU_IC_HIT,
  V3D_PERFCNT_QPU_IC_MISS,
  V3D_PERFCNT_QPU_UC_HIT,
  V3D_PERFCNT_QPU_UC_MISS,
  V3D_PERFCNT_TMU_TCACHE_ACCESS,
  V3D_PERFCNT_TMU_TCACHE_MISS,
  V3D_PERFCNT_VPM_VDW_STALL,
  V3D_PERFCNT_VPM_VCD_STALL,
  V3D_PERFCNT_BIN_ACTIVE,
  V3D_PERFCNT_RDR_ACTIVE,
  V3D_PERFCNT_L2T_HITS,
  V3D_PERFCNT_L2T_MISSES,
  V3D_PERFCNT_CYCLE_COUNT,
  V3D_PERFCNT_QPU_CYCLES_STALLED_VERTEX_COORD_USER,
  V3D_PERFCNT_QPU_CYCLES_STALLED_FRAGMENT,
  V3D_PERFCNT_PTB_PRIMS_BINNED,
  V3D_PERFCNT_AXI_WRITES_WATCH_0,
  V3D_PERFCNT_AXI_READS_WATCH_0,
  V3D_PERFCNT_AXI_WRITE_STALLS_WATCH_0,
  V3D_PERFCNT_AXI_READ_STALLS_WATCH_0,
  V3D_PERFCNT_AXI_WRITE_BYTES_WATCH_0,
  V3D_PERFCNT_AXI_READ_BYTES_WATCH_0,
  V3D_PERFCNT_AXI_WRITES_WATCH_1,
  V3D_PERFCNT_AXI_READS_WATCH_1,
  V3D_PERFCNT_AXI_WRITE_STALLS_WATCH_1,
  V3D_PERFCNT_AXI_READ_STALLS_WATCH_1,
  V3D_PERFCNT_AXI_WRITE_BYTES_WATCH_1,
  V3D_PERFCNT_AXI_READ_BYTES_WATCH_1,
  V3D_PERFCNT_TLB_PARTIAL_QUADS,
  V3D_PERFCNT_TMU_CONFIG_ACCESSES,
  V3D_PERFCNT_L2T_NO_ID_STALL,
  V3D_PERFCNT_L2T_COM_QUE_STALL,
  V3D_PERFCNT_L2T_TMU_WRITES,
  V3D_PERFCNT_TMU_ACTIVE_CYCLES,
  V3D_PERFCNT_TMU_STALLED_CYCLES,
  V3D_PERFCNT_CLE_ACTIVE,
  V3D_PERFCNT_L2T_TMU_READS,
  V3D_PERFCNT_L2T_CLE_READS,
  V3D_PERFCNT_L2T_VCD_READS,
  V3D_PERFCNT_L2T_TMUCFG_READS,
  V3D_PERFCNT_L2T_SLC0_READS,
  V3D_PERFCNT_L2T_SLC1_READS,
  V3D_PERFCNT_L2T_SLC2_READS,
  V3D_PERFCNT_L2T_TMU_W_MISSES,
  V3D_PERFCNT_L2T_TMU_R_MISSES,
  V3D_PERFCNT_L2T_CLE_MISSES,
  V3D_PERFCNT_L2T_VCD_MISSES,
  V3D_PERFCNT_L2T_TMUCFG_MISSES,
  V3D_PERFCNT_L2T_SLC0_MISSES,
  V3D_PERFCNT_L2T_SLC1_MISSES,
  V3D_PERFCNT_L2T_SLC2_MISSES,
  V3D_PERFCNT_CORE_MEM_WRITES,
  V3D_PERFCNT_L2T_MEM_WRITES,
  V3D_PERFCNT_PTB_MEM_WRITES,
  V3D_PERFCNT_TLB_MEM_WRITES,
  V3D_PERFCNT_CORE_MEM_READS,
  V3D_PERFCNT_L2T_MEM_READS,
  V3D_PERFCNT_PTB_MEM_READS,
  V3D_PERFCNT_PSE_MEM_READS,
  V3D_PERFCNT_TLB_MEM_READS,
  V3D_PERFCNT_GMP_MEM_READS,
  V3D_PERFCNT_PTB_W_MEM_WORDS,
  V3D_PERFCNT_TLB_W_MEM_WORDS,
  V3D_PERFCNT_PSE_R_MEM_WORDS,
  V3D_PERFCNT_TLB_R_MEM_WORDS,
  V3D_PERFCNT_TMU_MRU_HITS,
  V3D_PERFCNT_COMPUTE_ACTIVE,
  V3D_PERFCNT_NUM,
};
#define DRM_V3D_MAX_PERF_COUNTERS 32
struct drm_v3d_perfmon_create {
  __u32 id;
  __u32 ncounters;
  __u8 counters[DRM_V3D_MAX_PERF_COUNTERS];
};
struct drm_v3d_perfmon_destroy {
  __u32 id;
};
struct drm_v3d_perfmon_get_values {
  __u32 id;
  __u32 pad;
  __u64 values_ptr;
};
#define DRM_V3D_PERFCNT_MAX_NAME 64
#define DRM_V3D_PERFCNT_MAX_CATEGORY 32
#define DRM_V3D_PERFCNT_MAX_DESCRIPTION 256
struct drm_v3d_perfmon_get_counter {
  __u8 counter;
  __u8 name[DRM_V3D_PERFCNT_MAX_NAME];
  __u8 category[DRM_V3D_PERFCNT_MAX_CATEGORY];
  __u8 description[DRM_V3D_PERFCNT_MAX_DESCRIPTION];
  __u8 reserved[7];
};
#ifdef __cplusplus
}
#endif
#endif
