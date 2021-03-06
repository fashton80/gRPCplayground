/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     udpa/annotations/versioning.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef UDPA_ANNOTATIONS_VERSIONING_PROTO_UPB_H_
#define UDPA_ANNOTATIONS_VERSIONING_PROTO_UPB_H_

#include "upb/msg_internal.h"
#include "upb/decode.h"
#include "upb/decode_fast.h"
#include "upb/encode.h"

#include "upb/port_def.inc"

#ifdef __cplusplus
extern "C" {
#endif

struct udpa_annotations_VersioningAnnotation;
typedef struct udpa_annotations_VersioningAnnotation udpa_annotations_VersioningAnnotation;
extern const upb_MiniTable udpa_annotations_VersioningAnnotation_msginit;
extern const upb_MiniTable_Extension udpa_annotations_versioning_ext;
struct google_protobuf_MessageOptions;
extern const upb_MiniTable google_protobuf_MessageOptions_msginit;



/* udpa.annotations.VersioningAnnotation */

UPB_INLINE udpa_annotations_VersioningAnnotation* udpa_annotations_VersioningAnnotation_new(upb_Arena* arena) {
  return (udpa_annotations_VersioningAnnotation*)_upb_Message_New(&udpa_annotations_VersioningAnnotation_msginit, arena);
}
UPB_INLINE udpa_annotations_VersioningAnnotation* udpa_annotations_VersioningAnnotation_parse(const char* buf, size_t size, upb_Arena* arena) {
  udpa_annotations_VersioningAnnotation* ret = udpa_annotations_VersioningAnnotation_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &udpa_annotations_VersioningAnnotation_msginit, NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE udpa_annotations_VersioningAnnotation* udpa_annotations_VersioningAnnotation_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  udpa_annotations_VersioningAnnotation* ret = udpa_annotations_VersioningAnnotation_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &udpa_annotations_VersioningAnnotation_msginit, extreg, options, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* udpa_annotations_VersioningAnnotation_serialize(const udpa_annotations_VersioningAnnotation* msg, upb_Arena* arena, size_t* len) {
  return upb_Encode(msg, &udpa_annotations_VersioningAnnotation_msginit, 0, arena, len);
}
UPB_INLINE char* udpa_annotations_VersioningAnnotation_serialize_ex(const udpa_annotations_VersioningAnnotation* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  return upb_Encode(msg, &udpa_annotations_VersioningAnnotation_msginit, options, arena, len);
}
UPB_INLINE upb_StringView udpa_annotations_VersioningAnnotation_previous_message_type(const udpa_annotations_VersioningAnnotation* msg) {
  return *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView);
}

UPB_INLINE void udpa_annotations_VersioningAnnotation_set_previous_message_type(udpa_annotations_VersioningAnnotation *msg, upb_StringView value) {
  *UPB_PTR_AT(msg, UPB_SIZE(0, 0), upb_StringView) = value;
}

UPB_INLINE bool udpa_annotations_has_versioning(const struct google_protobuf_MessageOptions *msg) { return _upb_Message_Getext(msg, &udpa_annotations_versioning_ext) != NULL; }
UPB_INLINE const udpa_annotations_VersioningAnnotation* udpa_annotations_versioning(const struct google_protobuf_MessageOptions *msg) { const upb_Message_Extension *ext = _upb_Message_Getext(msg, &udpa_annotations_versioning_ext); UPB_ASSERT(ext); return *UPB_PTR_AT(&ext->data, 0, const udpa_annotations_VersioningAnnotation*); }
extern const upb_MiniTable_File udpa_annotations_versioning_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port_undef.inc"

#endif  /* UDPA_ANNOTATIONS_VERSIONING_PROTO_UPB_H_ */
