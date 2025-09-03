/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
unsigned char edge_map_single_value(float llvm_cbe_val, float llvm_cbe_abs_limit, float llvm_cbe_min_strength);
void comparator(signed int (*llvm_cbe_image)[372], signed int llvm_cbe_row_idx, signed int llvm_cbe_col_idx, signed int *llvm_cbe_valid_window,  char *llvm_cbe_combined_lh_hl_hh,  char *llvm_cbe_combined_lh_hl,  char *llvm_cbe_combined_ll_hh,  char *llvm_cbe_norm_HH,  char *llvm_cbe_norm_HL,  char *llvm_cbe_norm_LH,  char *llvm_cbe_norm_LL);
signed int window_processor();


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

unsigned char edge_map_single_value(float llvm_cbe_val, float llvm_cbe_abs_limit, float llvm_cbe_min_strength) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  float llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  float llvm_cbe_tmp__2;
  float llvm_cbe_tmp__2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  float llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  float llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  float llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned char llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @edge_map_single_value\n");
  if ((llvm_fcmp_olt(llvm_cbe_val, 0x0p0))) {
    goto llvm_cbe_tmp__7;
  } else {
    llvm_cbe_tmp__2__PHI_TEMPORARY = (float )llvm_cbe_val;   /* for PHI node */
    goto llvm_cbe_tmp__8;
  }

llvm_cbe_tmp__7:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = fsub float -0.000000e+00, %%val, !dbg !3 for 0x%I64xth hint within @edge_map_single_value  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__1 = (float )((float )(-(llvm_cbe_val)));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1, *(int*)(&llvm_cbe_tmp__1));
  llvm_cbe_tmp__2__PHI_TEMPORARY = (float )llvm_cbe_tmp__1;   /* for PHI node */
  goto llvm_cbe_tmp__8;

llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi float [ %%3, %%2 ], [ %%val, %%0 ], !dbg !3 for 0x%I64xth hint within @edge_map_single_value  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__2 = (float )llvm_cbe_tmp__2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__2);
printf("\n = %f",llvm_cbe_tmp__1);
printf("\nval = %f",llvm_cbe_val);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = select i1 %%6, float %%abs_limit, float %%5, !dbg !4 for 0x%I64xth hint within @edge_map_single_value  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__3 = (float )(((llvm_fcmp_ogt(llvm_cbe_tmp__2, llvm_cbe_abs_limit))) ? ((float )llvm_cbe_abs_limit) : ((float )llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__3, *(int*)(&llvm_cbe_tmp__3));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fdiv float %%7, %%abs_limit, !dbg !4 for 0x%I64xth hint within @edge_map_single_value  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__4 = (float )((float )(llvm_cbe_tmp__3 / llvm_cbe_abs_limit));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__4, *(int*)(&llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fmul float %%8, 2.550000e+02, !dbg !4 for 0x%I64xth hint within @edge_map_single_value  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__5 = (float )((float )(llvm_cbe_tmp__4 * 0x1.fep7));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__5, *(int*)(&llvm_cbe_tmp__5));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i1 %%10 to i8, !dbg !4 for 0x%I64xth hint within @edge_map_single_value  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__6 = (unsigned char )(( char )(0-(llvm_fcmp_oge(llvm_cbe_tmp__5, llvm_cbe_min_strength))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @edge_map_single_value}\n");
  return llvm_cbe_tmp__6;
}


void comparator(signed int (*llvm_cbe_image)[372], signed int llvm_cbe_row_idx, signed int llvm_cbe_col_idx, signed int *llvm_cbe_valid_window,  char *llvm_cbe_combined_lh_hl_hh,  char *llvm_cbe_combined_lh_hl,  char *llvm_cbe_combined_ll_hh,  char *llvm_cbe_norm_HH,  char *llvm_cbe_norm_HL,  char *llvm_cbe_norm_LH,  char *llvm_cbe_norm_LL) {
  static  unsigned long long aesl_llvm_cbe_LL_val_count = 0;
  float llvm_cbe_LL_val;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_LH_val_count = 0;
  float llvm_cbe_LH_val;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_HL_val_count = 0;
  float llvm_cbe_HL_val;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_HH_val_count = 0;
  float llvm_cbe_HH_val;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  float llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned char llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned char llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  float llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned char llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  float llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned char llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  float llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned char llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  float llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned char llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  float llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  float llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  float llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned char llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned char llvm_cbe_tmp__30;
  unsigned char llvm_cbe_tmp__30__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned char llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned char llvm_cbe_tmp__32;
  unsigned char llvm_cbe_tmp__32__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned char llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned char llvm_cbe_tmp__34;
  unsigned char llvm_cbe_tmp__34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @comparator\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 bitcast (i32 (...)* @window_processor to i32 ([372 x i32]*, i32, i32, i32*, float*, float*, float*, float*)*)([372 x i32]* %%image, i32 %%row_idx, i32 %%col_idx, i32* %%valid_window, float* %%LL_val, float* %%LH_val, float* %%HL_val, float* %%HH_val) nounwind, !dbg !3 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_62_count);
  window_processor(llvm_cbe_image, llvm_cbe_row_idx, llvm_cbe_col_idx, (signed int *)llvm_cbe_valid_window, (float *)(&llvm_cbe_LL_val), (float *)(&llvm_cbe_LH_val), (float *)(&llvm_cbe_HL_val), (float *)(&llvm_cbe_HH_val));
if (AESL_DEBUG_TRACE) {
printf("\nArgument row_idx = 0x%X",llvm_cbe_row_idx);
printf("\nArgument col_idx = 0x%X",llvm_cbe_col_idx);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load float* %%LL_val, align 4, !dbg !7 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__10 = (float )*(&llvm_cbe_LL_val);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call zeroext i8 @edge_map_single_value(float %%2, float 5.100000e+02, float 4.000000e+01), !dbg !7 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__11 = (unsigned char )edge_map_single_value(llvm_cbe_tmp__10, 0x1.fep8, 0x1.4p5);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
printf("\nArgument  = %f",0x1.fep8);
printf("\nArgument  = %f",0x1.4p5);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%3, i8* %%norm_LL, align 1, !dbg !7 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_71_count);
  *llvm_cbe_norm_LL = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%LH_val, align 4, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__12 = (float )*(&llvm_cbe_LH_val);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call zeroext i8 @edge_map_single_value(float %%4, float 2.550000e+02, float 3.000000e+01), !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__13 = (unsigned char )edge_map_single_value(llvm_cbe_tmp__12, 0x1.fep7, 0x1.ep4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
printf("\nArgument  = %f",0x1.fep7);
printf("\nArgument  = %f",0x1.ep4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* %%norm_LH, align 1, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_80_count);
  *llvm_cbe_norm_LH = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%HL_val, align 4, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__14 = (float )*(&llvm_cbe_HL_val);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call zeroext i8 @edge_map_single_value(float %%6, float 2.550000e+02, float 3.000000e+01), !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__15 = (unsigned char )edge_map_single_value(llvm_cbe_tmp__14, 0x1.fep7, 0x1.ep4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
printf("\nArgument  = %f",0x1.fep7);
printf("\nArgument  = %f",0x1.ep4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%norm_HL, align 1, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_89_count);
  *llvm_cbe_norm_HL = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%HH_val, align 4, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__16 = (float )*(&llvm_cbe_HH_val);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call zeroext i8 @edge_map_single_value(float %%8, float 2.550000e+02, float 3.000000e+01), !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__17 = (unsigned char )edge_map_single_value(llvm_cbe_tmp__16, 0x1.fep7, 0x1.ep4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__16, *(int*)(&llvm_cbe_tmp__16));
printf("\nArgument  = %f",0x1.fep7);
printf("\nArgument  = %f",0x1.ep4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%norm_HH, align 1, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_98_count);
  *llvm_cbe_norm_HH = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%norm_LL, align 1, !dbg !7 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__18 = (unsigned char )*llvm_cbe_norm_LL;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = uitofp i8 %%10 to float, !dbg !7 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__19 = (float )((float )(unsigned char )llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__19, *(int*)(&llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i8* %%norm_LH, align 1, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__20 = (unsigned char )*llvm_cbe_norm_LH;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = uitofp i8 %%12 to float, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__21 = (float )((float )(unsigned char )llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__21, *(int*)(&llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8* %%norm_HL, align 1, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__22 = (unsigned char )*llvm_cbe_norm_HL;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = uitofp i8 %%14 to float, !dbg !6 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__23 = (float )((float )(unsigned char )llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = uitofp i8 %%9 to float, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__24 = (float )((float )(unsigned char )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__24, *(int*)(&llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fadd float %%11, %%16, !dbg !8 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__25 = (float )((float )(llvm_cbe_tmp__19 + llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fadd float %%13, %%15, !dbg !8 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__26 = (float )((float )(llvm_cbe_tmp__21 + llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__26, *(int*)(&llvm_cbe_tmp__26));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = fadd float %%16, %%13, !dbg !8 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__27 = (float )((float )(llvm_cbe_tmp__24 + llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__27, *(int*)(&llvm_cbe_tmp__27));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fadd float %%19, %%15, !dbg !8 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__28 = (float )((float )(llvm_cbe_tmp__27 + llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__28, *(int*)(&llvm_cbe_tmp__28));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__25, 0x1.fep7))) {
    llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned char )((unsigned char )-1);   /* for PHI node */
    goto llvm_cbe_tmp__35;
  } else {
    goto llvm_cbe_tmp__36;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fptoui float %%17 to i8, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__29 = (unsigned char )((unsigned char )llvm_cbe_tmp__25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
  llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__29;   /* for PHI node */
  goto llvm_cbe_tmp__35;

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = phi i8 [ %%23, %%22 ], [ -1, %%0 ], !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__30 = (unsigned char )llvm_cbe_tmp__30__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__30);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",((unsigned char )-1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%25, i8* %%combined_ll_hh, align 1, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_135_count);
  *llvm_cbe_combined_ll_hh = llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__26, 0x1.fep7))) {
    llvm_cbe_tmp__32__PHI_TEMPORARY = (unsigned char )((unsigned char )-1);   /* for PHI node */
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__38;
  }

llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = fptoui float %%18 to i8, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__31 = (unsigned char )((unsigned char )llvm_cbe_tmp__26&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
  llvm_cbe_tmp__32__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__31;   /* for PHI node */
  goto llvm_cbe_tmp__37;

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi i8 [ %%28, %%27 ], [ -1, %%24 ], !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__32 = (unsigned char )llvm_cbe_tmp__32__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__32);
printf("\n = 0x%X",llvm_cbe_tmp__31);
printf("\n = 0x%X",((unsigned char )-1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%combined_lh_hl, align 1, !dbg !5 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_141_count);
  *llvm_cbe_combined_lh_hl = llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__28, 0x1.fep7))) {
    llvm_cbe_tmp__34__PHI_TEMPORARY = (unsigned char )((unsigned char )-1);   /* for PHI node */
    goto llvm_cbe_tmp__39;
  } else {
    goto llvm_cbe_tmp__40;
  }

llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fptoui float %%20 to i8, !dbg !4 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__33 = (unsigned char )((unsigned char )llvm_cbe_tmp__28&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
  llvm_cbe_tmp__34__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__33;   /* for PHI node */
  goto llvm_cbe_tmp__39;

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = phi i8 [ %%33, %%32 ], [ -1, %%29 ], !dbg !4 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__34 = (unsigned char )llvm_cbe_tmp__34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__34);
printf("\n = 0x%X",llvm_cbe_tmp__33);
printf("\n = 0x%X",((unsigned char )-1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%35, i8* %%combined_lh_hl_hh, align 1, !dbg !4 for 0x%I64xth hint within @comparator  --> \n", ++aesl_llvm_cbe_147_count);
  *llvm_cbe_combined_lh_hl_hh = llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @comparator}\n");
  return;
}

