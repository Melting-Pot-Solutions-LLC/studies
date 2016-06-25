#ifndef BLIS_KERNEL_H
#define BLIS_KERNEL_H


#define BLIS_SIMD_ALIGN_SIZE             16

typedef enum
{
	BLIS_BUFFER_FOR_A_BLOCK = BLIS_BITVAL_BUFFER_FOR_A_BLOCK,
	BLIS_BUFFER_FOR_B_PANEL = BLIS_BITVAL_BUFFER_FOR_B_PANEL,
	BLIS_BUFFER_FOR_C_PANEL = BLIS_BITVAL_BUFFER_FOR_C_PANEL,

} packbuf_t;


typedef struct
{
	// The pack schemas of A and B.
	pack_t schema_a;
	pack_t schema_b;

	// Pointers to the micro-panels of A and B which will be used by the
	// next call to the micro-kernel.
	void*  a_next;
	void*  b_next;

	// The imaginary strides of A and B.
	inc_t  is_a;
	inc_t  is_b;

} auxinfo_t;


#define bli_obj_init_basic_shallow_copy_of( a, b ) \
{ \
	(b).root      = (a).root; \
\
	(b).off[0]    = (a).off[0]; \
	(b).off[1]    = (a).off[1]; \
	(b).dim[0]    = (a).dim[0]; \
	(b).dim[1]    = (a).dim[1]; \
	(b).diag_off  = (a).diag_off; \
\
	(b).info      = (a).info; \
	(b).elem_size = (a).elem_size; \
\
	(b).buffer    = (a).buffer; \
	(b).rs        = (a).rs; \
	(b).cs        = (a).cs; \
	(b).is        = (a).is; \
\
	(b).scalar    = (a).scalar; \
\
	/* We must NOT copy pack_mem field since this macro forms the basis of
	   bli_obj_alias_to(), which is used in packm_init(). There, we want to
	   copy the basic fields of the obj_t but PRESERVE the pack_mem field
	   of the destination object since it holds the "cached" mem_t object
	   and buffer. The other fields, such as padded dimensions, are always
	   set by bli_packm_init(), so we don't need to copy them either. */ \
}


typedef enum
{
	// Generic error codes
	BLIS_SUCCESS                               = (  -1),
	BLIS_FAILURE                               = (  -2),

	BLIS_ERROR_CODE_MIN                        = (  -9),

	// General errors
	BLIS_INVALID_ERROR_CHECKING_LEVEL          = ( -10),
	BLIS_UNDEFINED_ERROR_CODE                  = ( -11),
	BLIS_NULL_POINTER                          = ( -12),
	BLIS_NOT_YET_IMPLEMENTED                   = ( -13)
} err_t;
#endif