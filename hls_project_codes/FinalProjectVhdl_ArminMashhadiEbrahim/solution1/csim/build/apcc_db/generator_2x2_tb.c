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
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void save_pgm( char *llvm_cbe_filepath,  char (*llvm_cbe_image)[371]);
signed int load_pgm( char *llvm_cbe_filepath, signed int (*llvm_cbe_image)[372]);
signed int main(void);
signed int SaveToRamAndOutput();


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[3] = "wb";
static  char aesl_internal__OC_str1[20] = "Failed to open file";
static  char aesl_internal__OC_str2[14] = "P5\n%d %d\n255\n";
static  char aesl_internal__OC_str3[21] = " Image saved to: %s\n";
static  char aesl_internal__OC_str4[3] = "rb";
static  char aesl_internal__OC_str5[31] = " Failed to open input PGM file";
static  char aesl_internal__OC_str6[4] = "%2s";
static  char aesl_internal__OC_str12[42] = "X:\\pro\\New folder (2)\\read_back_check.pgm";
static  char aesl_internal__OC_str11[18] = "Progress: %.2f%%\n";
static  char aesl_internal_str[20] = " Not a P5 PGM file.";
static  char aesl_internal__OC_str8[6] = "%d %d";
static  char aesl_internal__OC_str10[42] = "X:\\pro\\New folder (2)\\outputpgmpython.pgm";
static  char aesl_internal__OC_str13[33] = "X:\\pro\\New folder (2)\\output.pgm";
static  char aesl_internal__OC_str9[3] = "%d";
static  char aesl_internal_str1[28] = " Done writing output image.";


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

void save_pgm( char *llvm_cbe_filepath,  char (*llvm_cbe_image)[371]) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @save_pgm\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call %%struct._iobuf* @fopen(i8* %%filepath, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str, i64 0, i64 0)) nounwind, !dbg !4 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_6_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *) /*tail*/ aesl_fopen(( char *)llvm_cbe_filepath, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__9;
  } else {
    goto llvm_cbe_tmp__10;
  }

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @perror(i8* getelementptr inbounds ([20 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !7 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_14_count);
   /*tail*/ perror(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 20
#endif
])));
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__11;

llvm_cbe_tmp__10:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([14 x i8]* @aesl_internal_.str2, i64 0, i64 0), i32 371, i32 285) nounwind, !dbg !7 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_16_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 14
#endif
])), 371u, 285u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",371u);
printf("\nArgument  = 0x%X",285u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__12;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__12:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%4 ], [ %%10, %%6  for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge1 to i64, !dbg !5 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__3 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [371 x i8]* %%image, i64 %%7, i64 0, !dbg !5 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__4 = ( char *)(&llvm_cbe_image[(((signed long long )llvm_cbe_tmp__3))
#ifdef AESL_BC_SIM
 % 371
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i64 @fwrite(i8* %%8, i64 1, i64 371, %%struct._iobuf* %%1) nounwind, !dbg !5 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_24_count);
   /*tail*/ fwrite(( char *)llvm_cbe_tmp__4, 1ull, 371ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",371ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge1, 1, !dbg !7 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (285u&4294967295U))) {
    goto llvm_cbe_tmp__13;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__12;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__13:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !7 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_31_count);
   /*tail*/ fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str3, i64 0, i64 0), i8* %%filepath) nounwind, !dbg !5 for 0x%I64xth hint within @save_pgm  --> \n", ++aesl_llvm_cbe_32_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), ( char *)llvm_cbe_filepath);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__8);
}
  goto llvm_cbe_tmp__11;

llvm_cbe_tmp__11:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @save_pgm}\n");
  return;
}


signed int load_pgm( char *llvm_cbe_filepath, signed int (*llvm_cbe_image)[372]) {
  static  unsigned long long aesl_llvm_cbe_magic_count = 0;
   char llvm_cbe_magic[3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_maxval_count = 0;
  signed int llvm_cbe_maxval;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_widtht_count = 0;
  signed int llvm_cbe_widtht;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_heightt_count = 0;
  signed int llvm_cbe_heightt;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__14;
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
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned char llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge13_count = 0;
  unsigned int llvm_cbe_storemerge13;
  unsigned int llvm_cbe_storemerge13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__31;
  unsigned int llvm_cbe_tmp__31__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @load_pgm\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* %%filepath, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str4, i64 0, i64 0)) nounwind, !dbg !5 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__14 = (l_struct_OC__iobuf *)aesl_fopen(( char *)llvm_cbe_filepath, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
  if (((llvm_cbe_tmp__14) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__32;
  } else {
    goto llvm_cbe_tmp__33;
  }

llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  call void @perror(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_.str5, i64 0, i64 0)) nounwind, !dbg !8 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_51_count);
  perror(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__34;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [3 x i8]* %%magic, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__15 = ( char *)(&llvm_cbe_magic[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str6, i64 0, i64 0), i8* %%5) nounwind, !dbg !7 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_58_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__14, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), ( char *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__16);
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'magic' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%5, align 1, !dbg !9 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__17 = (unsigned char )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
  if (((llvm_cbe_tmp__17&255U) == (((unsigned char )80)&255U))) {
    goto llvm_cbe_tmp__35;
  } else {
    goto llvm_cbe_tmp__36;
  }

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [3 x i8]* %%magic, i64 0, i64 1, !dbg !9 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__18 = ( char *)(&llvm_cbe_magic[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'magic' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !9 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__19 = (unsigned char )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
  if (((llvm_cbe_tmp__19&255U) == (((unsigned char )53)&255U))) {
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__36;
  }

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([20 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 20
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !7 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_66_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
  llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__34;

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32* %%widtht, i32* %%heightt) nounwind, !dbg !7 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_68_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__14, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), (signed int *)(&llvm_cbe_widtht), (signed int *)(&llvm_cbe_heightt));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32* %%maxval) nounwind, !dbg !7 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_69_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__14, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (signed int *)(&llvm_cbe_maxval));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i32 @fgetc(%%struct._iobuf* %%1) nounwind, !dbg !7 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_70_count);
  fgetc((l_struct_OC__iobuf *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__23);
}
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 0, %%15 ], [ %%27, %%26  for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%storemerge4 to i64, !dbg !5 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__24 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__24);
  llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%storemerge4, 1, !dbg !10 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  if (((llvm_cbe_tmp__29&4294967295U) == (286u&4294967295U))) {
    goto llvm_cbe_tmp__40;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13 = phi i32 [ 0, %%.preheader ], [ %%25, %%20  for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_storemerge13_count);
  llvm_cbe_storemerge13 = (unsigned int )llvm_cbe_storemerge13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%X",llvm_cbe_storemerge13);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i32 @fgetc(%%struct._iobuf* %%1) nounwind, !dbg !8 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__25 = (unsigned int )fgetc((l_struct_OC__iobuf *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%22, i32 0, i32 %%21, !dbg !10 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__25&4294967295U) == (4294967295u&4294967295U))) ? ((unsigned int )0u) : ((unsigned int )llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%storemerge13 to i64, !dbg !5 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge13);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [372 x i32]* %%image, i64 %%19, i64 %%23, !dbg !5 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_image[(((signed long long )llvm_cbe_tmp__24))
#ifdef AESL_BC_SIM
 % 372
#endif
][(((signed long long )llvm_cbe_tmp__26))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__24));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__26) < 372 && "Write access out of array 'image' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%., i32* %%24, align 4, !dbg !5 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_88_count);
  *llvm_cbe_tmp__27 = llvm_cbe__2e_;
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge13, 1, !dbg !10 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge13&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
  if (((llvm_cbe_tmp__28&4294967295U) == (372u&4294967295U))) {
    goto llvm_cbe_tmp__39;
  } else {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__28;   /* for PHI node */
    goto llvm_cbe_tmp__38;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !8 for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_101_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
  llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__34;

llvm_cbe_tmp__34:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = phi i32 [ 0, %%28 ], [ -1, %%13 ], [ -1, %%3  for 0x%I64xth hint within @load_pgm  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__31 = (unsigned int )llvm_cbe_tmp__31__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__31);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @load_pgm}\n");
  return llvm_cbe_tmp__31;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_input_image_count = 0;
  signed int llvm_cbe_input_image[286][372];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_image_count = 0;
   char llvm_cbe_output_image[285][371];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_image_copy_count = 0;
   char llvm_cbe_image_copy[285][371];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  signed int (*llvm_cbe_tmp__41)[372];
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned int llvm_cbe_storemerge5;
  unsigned int llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  double llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  double llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  double llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  signed int *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned char llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned char llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
   char *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond6_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
   char (*llvm_cbe_tmp__57)[371];
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
   char (*llvm_cbe_tmp__58)[371];
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [286 x [372 x i32]]* %%input_image, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__41 = (signed int (*)[372])(&llvm_cbe_input_image[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 286
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i32 @load_pgm(i8* getelementptr inbounds ([42 x i8]* @aesl_internal_.str10, i64 0, i64 0), [372 x i32]* %%1), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  load_pgm(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 42
#endif
])), llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
  llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__60;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__60:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i32 [ 0, %%0 ], [ %%24, %%23  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned int )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%X",llvm_cbe_storemerge5);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = and i32 %%storemerge5, 511, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__43 = (unsigned int )llvm_cbe_storemerge5 & 511u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  if (((llvm_cbe_tmp__43&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__61;
  } else {
    goto llvm_cbe_tmp__62;
  }

llvm_cbe_tmp__63:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%storemerge5, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_storemerge5&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
  if (((llvm_cbe_tmp__56&4294967295U) == (285u&4294967295U))) {
    goto llvm_cbe_tmp__64;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__56;   /* for PHI node */
    goto llvm_cbe_tmp__60;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__65:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ 0, %%11 ], [ %%22, %%13  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__55);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%storemerge14 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__49 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [286 x [372 x i32]]* %%input_image, i64 0, i64 %%12, i64 %%14, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__50 = (signed int *)(&llvm_cbe_input_image[(((signed long long )llvm_cbe_tmp__48))
#ifdef AESL_BC_SIM
 % 286
#endif
][(((signed long long )llvm_cbe_tmp__49))
#ifdef AESL_BC_SIM
 % 372
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__49));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__48) < 286)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input_image' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__49) < 372)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input_image' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__51 = (unsigned int )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%17, i32 0, i32 %%16, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )(((((signed int )llvm_cbe_tmp__51) < ((signed int )0u))) ? ((unsigned int )0u) : ((unsigned int )llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = trunc i32 %%. to i8, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__52 = (unsigned char )((unsigned char )llvm_cbe__2e_&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = select i1 %%18, i8 -1, i8 %%19, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__53 = (unsigned char )(((((signed int )llvm_cbe__2e_) > ((signed int )255u))) ? ((unsigned char )((unsigned char )-1)) : ((unsigned char )llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [285 x [371 x i8]]* %%image_copy, i64 0, i64 %%12, i64 %%14, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__54 = ( char *)(&llvm_cbe_image_copy[(((signed long long )llvm_cbe_tmp__48))
#ifdef AESL_BC_SIM
 % 285
#endif
][(((signed long long )llvm_cbe_tmp__49))
#ifdef AESL_BC_SIM
 % 371
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__49));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__48) < 285 && "Write access out of array 'image_copy' bound?");
  assert(((signed long long )llvm_cbe_tmp__49) < 371 && "Write access out of array 'image_copy' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%20, i8* %%21, align 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_146_count);
  *llvm_cbe_tmp__54 = llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge14, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
  if (((llvm_cbe_tmp__55&4294967295U) == (371u&4294967295U))) {
    goto llvm_cbe_tmp__63;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__55;   /* for PHI node */
    goto llvm_cbe_tmp__65;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__62:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge5 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__48 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__65;

llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sitofp i32 %%storemerge5 to double, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__44 = (double )((double )(signed int )llvm_cbe_storemerge5);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__44, *(long long*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fmul double %%7, 1.000000e+02, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__45 = (double )llvm_cbe_tmp__44 * 0x1.9p6;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__45, *(long long*)(&llvm_cbe_tmp__45));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fdiv double %%8, 2.850000e+02, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__46 = (double )llvm_cbe_tmp__45 / 0x1.1dp8;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__46, *(long long*)(&llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_.str11, i64 0, i64 0), double %%9) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  printf(( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])), llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__46, *(long long*)(&llvm_cbe_tmp__46));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
  goto llvm_cbe_tmp__62;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__64:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [285 x [371 x i8]]* %%image_copy, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__57 = ( char (*)[371])(&llvm_cbe_image_copy[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 285
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @save_pgm(i8* getelementptr inbounds ([42 x i8]* @aesl_internal_.str12, i64 0, i64 0), [371 x i8]* %%26), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  save_pgm(( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 42
#endif
])), llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds [285 x [371 x i8]]* %%output_image, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__58 = ( char (*)[371])(&llvm_cbe_output_image[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 285
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call i32 bitcast (i32 (...)* @SaveToRamAndOutput to i32 ([372 x i32]*, [371 x i8]*)*)([372 x i32]* %%1, [371 x i8]* %%27) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_166_count);
  SaveToRamAndOutput(llvm_cbe_tmp__41, llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @save_pgm(i8* getelementptr inbounds ([33 x i8]* @aesl_internal_.str13, i64 0, i64 0), [371 x i8]* %%27), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_167_count);
  save_pgm(( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 33
#endif
])), llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([28 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

