#ifndef PPC_DARWIN_SPACELIST_H
#define PPC_DARWIN_SPACELIST_H

#if defined(LISP_FEATURE_GENCGC)
#define N_SEGMENTS_TO_PRODUCE 4
#else
#define N_SEGMENTS_TO_PRODUCE 5
#endif

unsigned int space_start_locations[N_SEGMENTS_TO_PRODUCE] =
  { READ_ONLY_SPACE_START, STATIC_SPACE_START,
#if defined(LISP_FEATURE_GENCGC)
    DYNAMIC_SPACE_START,
#else
    DYNAMIC_0_SPACE_START, DYNAMIC_1_SPACE_START,
#endif
    LINKAGE_TABLE_SPACE_START};

unsigned int space_sizes[N_SEGMENTS_TO_PRODUCE] =
  { READ_ONLY_SPACE_END - READ_ONLY_SPACE_START,
    STATIC_SPACE_END - STATIC_SPACE_START,
#if defined(LISP_FEATURE_GENCGC)
    DYNAMIC_SPACE_END - DYNAMIC_SPACE_START,
#else
    DYNAMIC_0_SPACE_END - DYNAMIC_0_SPACE_START,
    DYNAMIC_1_SPACE_END - DYNAMIC_1_SPACE_START,
#endif
    LINKAGE_TABLE_SPACE_END - LINKAGE_TABLE_SPACE_START};

#endif