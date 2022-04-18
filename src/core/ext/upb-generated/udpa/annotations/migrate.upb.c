/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     udpa/annotations/migrate.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "udpa/annotations/migrate.upb.h"
#include "google/protobuf/descriptor.upb.h"

#include "upb/port_def.inc"

static const upb_MiniTable_Field udpa_annotations_MigrateAnnotation__fields[1] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
};

const upb_MiniTable udpa_annotations_MigrateAnnotation_msginit = {
  NULL,
  &udpa_annotations_MigrateAnnotation__fields[0],
  UPB_SIZE(8, 16), 1, upb_ExtMode_NonExtendable, 1, 255, 0,
};

static const upb_MiniTable_Field udpa_annotations_FieldMigrateAnnotation__fields[2] = {
  {1, UPB_SIZE(0, 0), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
  {2, UPB_SIZE(8, 16), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
};

const upb_MiniTable udpa_annotations_FieldMigrateAnnotation_msginit = {
  NULL,
  &udpa_annotations_FieldMigrateAnnotation__fields[0],
  UPB_SIZE(16, 32), 2, upb_ExtMode_NonExtendable, 2, 255, 0,
};

static const upb_MiniTable_Field udpa_annotations_FileMigrateAnnotation__fields[1] = {
  {2, UPB_SIZE(0, 0), 0, 0, 9, kUpb_FieldMode_Scalar | (upb_FieldRep_StringView << upb_FieldRep_Shift)},
};

const upb_MiniTable udpa_annotations_FileMigrateAnnotation_msginit = {
  NULL,
  &udpa_annotations_FileMigrateAnnotation__fields[0],
  UPB_SIZE(8, 16), 1, upb_ExtMode_NonExtendable, 0, 255, 0,
};

static const upb_MiniTable *messages_layout[3] = {
  &udpa_annotations_MigrateAnnotation_msginit,
  &udpa_annotations_FieldMigrateAnnotation_msginit,
  &udpa_annotations_FileMigrateAnnotation_msginit,
};

extern const upb_MiniTable google_protobuf_EnumOptions_msginit;
extern const upb_MiniTable google_protobuf_EnumValueOptions_msginit;
extern const upb_MiniTable google_protobuf_FieldOptions_msginit;
extern const upb_MiniTable google_protobuf_FileOptions_msginit;
extern const upb_MiniTable google_protobuf_MessageOptions_msginit;
extern const upb_MiniTable udpa_annotations_FieldMigrateAnnotation_msginit;
extern const upb_MiniTable udpa_annotations_FileMigrateAnnotation_msginit;
extern const upb_MiniTable udpa_annotations_MigrateAnnotation_msginit;
const upb_MiniTable_Extension udpa_annotations_message_migrate_ext = {
  {171962766, 0, 0, 0, 11, kUpb_FieldMode_Scalar | upb_LabelFlags_IsExtension | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
    &google_protobuf_MessageOptions_msginit,
    {.submsg = &udpa_annotations_MigrateAnnotation_msginit},

};
const upb_MiniTable_Extension udpa_annotations_field_migrate_ext = {
  {171962766, 0, 0, 0, 11, kUpb_FieldMode_Scalar | upb_LabelFlags_IsExtension | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
    &google_protobuf_FieldOptions_msginit,
    {.submsg = &udpa_annotations_FieldMigrateAnnotation_msginit},

};
const upb_MiniTable_Extension udpa_annotations_enum_migrate_ext = {
  {171962766, 0, 0, 0, 11, kUpb_FieldMode_Scalar | upb_LabelFlags_IsExtension | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
    &google_protobuf_EnumOptions_msginit,
    {.submsg = &udpa_annotations_MigrateAnnotation_msginit},

};
const upb_MiniTable_Extension udpa_annotations_enum_value_migrate_ext = {
  {171962766, 0, 0, 0, 11, kUpb_FieldMode_Scalar | upb_LabelFlags_IsExtension | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
    &google_protobuf_EnumValueOptions_msginit,
    {.submsg = &udpa_annotations_MigrateAnnotation_msginit},

};
const upb_MiniTable_Extension udpa_annotations_file_migrate_ext = {
  {171962766, 0, 0, 0, 11, kUpb_FieldMode_Scalar | upb_LabelFlags_IsExtension | (upb_FieldRep_Pointer << upb_FieldRep_Shift)},
    &google_protobuf_FileOptions_msginit,
    {.submsg = &udpa_annotations_FileMigrateAnnotation_msginit},

};

static const upb_MiniTable_Extension *extensions_layout[5] = {
  &udpa_annotations_message_migrate_ext,
  &udpa_annotations_field_migrate_ext,
  &udpa_annotations_enum_migrate_ext,
  &udpa_annotations_enum_value_migrate_ext,
  &udpa_annotations_file_migrate_ext,
};

const upb_MiniTable_File udpa_annotations_migrate_proto_upb_file_layout = {
  messages_layout,
  NULL,
  extensions_layout,
  3,
  0,
  5,
};

#include "upb/port_undef.inc"
