/* Hey, Emacs, this a -*-C++-*- file !
 *
 * Copyright distributed.net 1997-1999 - All Rights Reserved
 * For use in distributed.net projects only.
 * Any other distribution or use of this source violates copyright.
 *
 * ** header may be included by cores, so guard around c++ constructs **
*/ 

#ifndef __CPUTYPES_H__
#define __CPUTYPES_H__ "@(#)$Id: cputypes.h,v 1.62.2.8 1999/12/02 10:47:00 mfeiri Exp $"

/* ----------------------------------------------------------------- */

/* Major CPU architectures, we don't need (or want) very fine resolution */
#define CPU_UNKNOWN     0
#define CPU_X86         1
#define CPU_POWERPC     2
#define CPU_MIPS        3
#define CPU_ALPHA       4
#define CPU_PA_RISC     5
#define CPU_68K         6
#define CPU_SPARC       7
/* #define CPU_UNUSED_1 8 */
#define CPU_POWER       9
#define CPU_VAX         10
#define CPU_ARM         11
#define CPU_88K         12
#define CPU_KSR1        13
#define CPU_S390        14
/* #define CPU_UNUSED_2 15 */
#define CPU_DESCRACKER  16  /* eff descracker */

/* Major OS Architectures. */
#define OS_UNKNOWN      0
#define OS_WIN32        1  /* win95 + win98 + winnt */
#define OS_DOS          2  /* ms-dos, pc-dos, dr-dos, etc. */
#define OS_FREEBSD      3
#define OS_LINUX        4
#define OS_BEOS         5
#define OS_MACOS        6
#define OS_IRIX         7
#define OS_VMS          8
#define OS_DEC_UNIX     9
#define OS_UNIXWARE     10
#define OS_OS2          11
#define OS_HPUX         12
#define OS_NETBSD       13
#define OS_SUNOS        14
#define OS_SOLARIS      15
/* #define OS_UNUSED_1  16 */ /* never used. was os9 */
/* #define OS_UNUSED_2  17 */ /* never used. was java-vm */
#define OS_BSDI         18
#define OS_NEXTSTEP     19
#define OS_SCO          20
#define OS_QNX          21
/* #define OS_UNUSED_3  22 */ /* never used. was osf1 (oldname for DEC UNIX)*/
/* #define OS_UNUSED_4  23 */ /* never used. was minix */
/* #define OS_UNUSED_5  24 */ /* never used. was mach10 */
#define OS_AIX          25
/* #define OS_UNUSED_6  26 */ /* never used. was AUX */
/* #define OS_UNUSED_7  27 */ /* never used. was rhapsody */
#define OS_AMIGAOS      28
#define OS_OPENBSD      29
#define OS_NETWARE      30
#define OS_MVS          31
#define OS_ULTRIX       32
/* #define OS_UNUSED_8  33 */ /* never used. was os400 */
#define OS_RISCOS       34
#define OS_DGUX         35
/* #define OS_WIN32S    36 */ /*obsolete (32-bit Win32s) w16 client is 32bit*/
#define OS_SINIX        37
#define OS_DYNIX        38
#define OS_OS390        39
/* #define OS_UNUSED4   40 */ /* never used. was os_maspar */
#define OS_WIN16        41 /* windows 3.1, 3.11, wfw (was 16bit, now 32bit) */
#define OS_DESCRACKER   42 /* eff des cracker */

/* ----------------------------------------------------------------- */

/* determine current compiling platform */
#if defined(WIN32) || defined(__WIN32__) || defined(_Windows) || defined(_WIN32)
  #if defined(NTALPHA) || defined(_M_ALPHA)
    #define CLIENT_CPU    CPU_ALPHA
    #define CLIENT_OS     OS_WIN32
    #define CLIENT_OS_NAME "Win32"
  #elif defined(ASM_PPC)
    #define CLIENT_CPU    CPU_POWERPC
    #define CLIENT_OS     OS_WIN32
    #define CLIENT_OS_NAME "Win32"
  #elif !defined(WIN32) && !defined(__WIN32__) && !defined(_WIN32) /* win16 */
    #define CLIENT_CPU    CPU_X86
    #define CLIENT_OS     OS_WIN16
    #define CLIENT_OS_NAME "Win16"
  #elif defined(__WIN32S__) /* win32s gui/may need to be defined in makefile*/
    #define CLIENT_CPU    CPU_X86
    #define CLIENT_OS     OS_WIN32S
    #define CLIENT_OS_NAME "Win16"
  #elif defined(__WINDOWS386__) /* standard 32bit client built for win16 */
    #define CLIENT_CPU    CPU_X86
    #define CLIENT_OS     OS_WIN16
    #define CLIENT_OS_NAME "Win16"
  #else
    #define CLIENT_CPU    CPU_X86
    #define CLIENT_OS     OS_WIN32
    #define CLIENT_OS_NAME "Win32"
  #endif
#elif defined(DJGPP) || defined(DOS4G) || defined(__MSDOS__)
  #define CLIENT_OS     OS_DOS
  #define CLIENT_CPU    CPU_X86
  #define CLIENT_OS_NAME "x86 DOS"
#elif defined(__NETWARE__)
  #define CLIENT_OS_NAME "NetWare"
  #if defined(_M_IX86)
    #define CLIENT_OS     OS_NETWARE
    #define CLIENT_CPU    CPU_X86
  #elif defined(_M_SPARC)
    #define CLIENT_OS     OS_NETWARE
    #define CLIENT_CPU    CPU_SPARC
  #elif defined(_M_ALPHA)
    #define CLIENT_OS     OS_NETWARE
    #define CLIENT_CPU    CPU_ALPHA
  #endif
#elif defined(__EMX__) || defined(__OS2__)
  #define CLIENT_OS_NAME "OS/2"
  #define CLIENT_OS     OS_OS2
  #define CLIENT_CPU    CPU_X86
  #if defined(__EMX__) && !defined(__unix__) 
  #define __unix__  /* should already be defined */
  #endif
#elif defined(linux)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME "Linux"
  #if defined(__alpha__) || defined(ASM_ALPHA)
    #define CLIENT_OS     OS_LINUX
    #define CLIENT_CPU    CPU_ALPHA
  #elif defined(__i386__) || defined(ASM_X86)
    #define CLIENT_OS     OS_LINUX
    #define CLIENT_CPU    CPU_X86
  #elif defined(ARM)
    #define CLIENT_OS     OS_LINUX
    #define CLIENT_CPU    CPU_ARM
  #elif defined(__sparc__) || defined(ASM_SPARC)
    #define CLIENT_OS     OS_LINUX
    #define CLIENT_CPU    CPU_SPARC
  #elif defined(ASM_PPC)
    #define CLIENT_OS     OS_LINUX
    #define CLIENT_CPU    CPU_POWERPC
  #elif defined(ASM_68K)
    #define CLIENT_OS     OS_LINUX
    #define CLIENT_CPU    CPU_68K
  #endif
#elif defined(__FreeBSD__)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME "FreeBSD"
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_OS     OS_FREEBSD
    #define CLIENT_CPU    CPU_X86
  #endif
#elif defined(__NetBSD__)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "NetBSD"
  #define CLIENT_OS       OS_NETBSD
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #elif defined(ARM)
    #define CLIENT_CPU    CPU_ARM
  #elif defined(__alpha__) || defined(ASM_ALPHA)
    #define CLIENT_CPU    CPU_ALPHA
  #elif defined(__vax__) || defined(ASM_VAX)
    #define CLIENT_CPU    CPU_VAX
  #endif
#elif defined(__OpenBSD__) || defined(openbsd)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "OpenBSD"
  #define CLIENT_OS       OS_OPENBSD
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #elif defined(__alpha__) || defined(ASM_ALPHA)
    #define CLIENT_CPU    CPU_ALPHA
  #elif defined(__sparc__)
    #define CLIENT_CPU    CPU_SPARC
  #endif
#elif defined(__QNX__)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "QNX"
  #define CLIENT_OS       OS_QNX
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #endif
#elif defined(solaris) || defined(sun)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "Solaris"
  #define CLIENT_OS       OS_SOLARIS
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #elif defined(__sparc) || defined(ASM_SPARC)
    #define CLIENT_CPU    CPU_SPARC
  #endif
#elif defined(_SUN68K_)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "SunOS"
  #define CLIENT_OS       OS_SUNOS
  #define CLIENT_CPU      CPU_68K
#elif defined(bsdi)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "BSD/OS"
  #define CLIENT_OS       OS_BSDI
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #endif
#elif defined(sco5)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "SCO Unix"
  #define CLIENT_OS       OS_SCO
  #if defined(__i386__) || defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #endif
#elif defined(__osf__)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "DEC Unix"
  #define CLIENT_OS       OS_DEC_UNIX
  #if defined(__alpha)
    #define CLIENT_CPU    CPU_ALPHA
  #endif
#elif defined(sinix)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "Sinix"
  #define CLIENT_OS       OS_SINIX
  #if defined(ASM_MIPS) || defined(__mips)
    #define CLIENT_CPU    CPU_MIPS
  #endif
#elif defined(ultrix)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "Ultrix"
  #define CLIENT_OS       OS_ULTRIX
  #if defined(ASM_MIPS) || defined(__mips)
    #define CLIENT_CPU    CPU_MIPS
  #endif
#elif (defined(ASM_MIPS) || defined(__mips))
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  /*
   * Let the Makefile override the presentation name. This is
   * used by the MIPSpro build targets, letting us set the
   * specific platform the build was for (e.g. "Irix (IP19)").
   */
  #ifndef CLIENT_OS_NAME
    #define CLIENT_OS_NAME  "Irix"
  #endif /* ! CLIENT_OS_NAME */
  #define CLIENT_OS       OS_IRIX
  #define CLIENT_CPU    CPU_MIPS
#elif defined(__VMS)
  #define CLIENT_OS_NAME  "VMS"
  #define CLIENT_OS       OS_VMS
  #if defined(__ALPHA)
    #define CLIENT_CPU    CPU_ALPHA
  #endif
#elif defined(_HPUX) || defined(__hpux) || defined(__hpux__)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "HP/UX"
  #define CLIENT_OS       OS_HPUX
  #if defined(__hppa) || defined(__hppa__) || defined(ASM_HPPA)
    #define CLIENT_CPU    CPU_PA_RISC
  #elif defined(_HPUX_M68K)
    #define CLIENT_CPU    CPU_68K
  #endif
#elif defined(_DGUX)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME  "DG/UX"
  #define CLIENT_OS       OS_DGUX
  #define CLIENT_CPU      CPU_88K
#elif defined(_AIX)
  #ifndef __unix__ /* should already be defined */
  #define __unix__
  #endif
  #define CLIENT_OS_NAME   "AIX"
  /* AIXALL hides itself as POWER, it's more easy copy with this problem */
  /* in the POWER tree, because this is used on AIX only */
  #if defined(_ARCH_PPC) || defined(ASM_PPC) || defined(_AIXALL)
    #define CLIENT_OS     OS_AIX
    #define CLIENT_CPU    CPU_POWERPC
  #elif (defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(ASM_POWER))
    #define CLIENT_OS     OS_AIX
    #define CLIENT_CPU    CPU_POWER
  #endif
#elif defined(macintosh)
  #define CLIENT_OS_NAME   "MacOS"
  #if __POWERPC__
    #define CLIENT_OS     OS_MACOS
    #define CLIENT_CPU    CPU_POWERPC
  #elif __MC68K__
    #define CLIENT_OS     OS_MACOS
    #define CLIENT_CPU    CPU_68K
  #endif
#elif defined(__BEOS__) || defined(__be_os)
  #ifndef __unix__ /* 4.4bsd compatible or not? */
  #define __unix__ /* it ain't that special! */
  #endif
  #define CLIENT_OS_NAME   "BeOS"
  #define CLIENT_OS     OS_BEOS
  #if defined(__POWERPC__) || defined(__PPC__)
    #define CLIENT_CPU    CPU_POWERPC
  #elif defined(__INTEL__)
    #define CLIENT_CPU CPU_X86
  #endif
#elif defined(AMIGA)
  #define CLIENT_OS_NAME   "AmigaOS"
  #define CLIENT_OS     OS_AMIGAOS
  #ifdef __PPC__
    #define CLIENT_CPU    CPU_POWERPC
  #else
    #define CLIENT_CPU    CPU_68K
  #endif
#elif defined(__riscos)
  #define CLIENT_OS_NAME   "RISC OS"
  #define CLIENT_OS     OS_RISCOS
  #define CLIENT_CPU    CPU_ARM
#elif defined(_NeXT_)
  #define CLIENT_OS_NAME   "NextStep"
  #if defined(ASM_X86)
    #define CLIENT_OS     OS_NEXTSTEP
    #define CLIENT_CPU    CPU_X86
  #elif defined(ASM_68K)
    #define CLIENT_OS     OS_NEXTSTEP
    #define CLIENT_CPU    CPU_68K
  #elif defined(ASM_HPPA)
    #define CLIENT_OS     OS_NEXTSTEP
    #define CLIENT_CPU    CPU_PA_RISC
  #elif defined(ASM_SPARC)
    #define CLIENT_OS     OS_NEXTSTEP
    #define CLIENT_CPU    CPU_SPARC
  #endif
#elif defined(__MVS__)
  #define CLIENT_OS_NAME   "OS390"
  #define CLIENT_OS     OS_OS390
  #define CLIENT_CPU    CPU_S390
#elif defined(_SEQUENT_)
  #ifndef __unix__ 
  #define __unix__
  #endif
  #define CLIENT_OS     OS_DYNIX
  #define CLIENT_OS_NAME   "Dynix"
  #if defined(ASM_X86)
    #define CLIENT_CPU    CPU_X86
  #endif
#endif

#if !defined(CLIENT_OS)
  #define CLIENT_OS     OS_UNKNOWN
#endif
#if !defined(CLIENT_OS_NAME)
  #define CLIENT_OS_NAME "**Unknown OS**"
#endif  
#if !defined(CLIENT_CPU)
  #define CLIENT_CPU    CPU_UNKNOWN
#endif
#if (CLIENT_OS == OS_UNKNOWN) || (CLIENT_CPU == CPU_UNKNOWN)
  /* ignoreunknowncpuos is used by the client's testplat.cpp utility. */
  #if !defined(IGNOREUNKNOWNCPUOS)
    #error "Unknown CPU/OS detected in cputypes.h"
  #endif
#endif

/* ----------------------------------------------------------------- */

#if ((CLIENT_CPU == CPU_X86) || (CLIENT_CPU == CPU_88K) || \
     (CLIENT_CPU == CPU_SPARC) || (CLIENT_CPU == CPU_POWERPC) || \
     (CLIENT_CPU == CPU_MIPS) || (CLIENT_CPU == CPU_ARM) || \
     ((CLIENT_CPU == CPU_ALPHA) && (CLIENT_OS == OS_WIN32)))
   #define CORES_SUPPORT_SMP
#endif   

#if (CLIENT_OS == OS_WIN32)
  #include <process.h>
  typedef unsigned long THREADID;
  #define OS_SUPPORTS_SMP
#elif (CLIENT_OS == OS_OS2)
  /* Headers defined elsewhere in a separate file. */
  typedef long THREADID;
  #define OS_SUPPORTS_SMP
#elif (CLIENT_OS == OS_NETWARE)
  #include <process.h>
  typedef long THREADID;
  #define OS_SUPPORTS_SMP
#elif (CLIENT_OS == OS_BEOS)
  #include <OS.h>
  typedef thread_id THREADID;
  #define OS_SUPPORTS_SMP
#elif (CLIENT_OS == OS_FREEBSD)
  typedef int /*pid_t*/ THREADID;
  #define OS_SUPPORTS_SMP
#elif defined(MULTITHREAD)
  #include <pthread.h>
  typedef pthread_t THREADID;
  #define OS_SUPPORTS_SMP
  /* egcs always includes pthreads.h, so use something other than PTHREAD_H */
  #define _POSIX_THREADS_SUPPORTED

  #if (CLIENT_OS == OS_DGUX)
    #define PTHREAD_SCOPE_SYSTEM PTHREAD_SCOPE_GLOBAL
    #define pthread_sigmask(a,b,c)
  #endif
#else 
  typedef int THREADID;
#endif

/* Fix up MULTITHREAD to mean "SMP aware and thread safe" */
#if (defined(CORES_SUPPORT_SMP) && defined(OS_SUPPORTS_SMP))
   #define CLIENT_SUPPORTS_SMP
#endif  
#undef MULTITHREAD /* undef it to avoid 'unsafe' meaning */

/* ----------------------------------------------------------------- */

#ifdef PROXYTYPE
/*
 Some compilers/platforms don't yet support bool internally.
 When creating new rules here, please try to use compiler-specific
 macro tests since not all compilers on a specific platform (or even
 a newer version of your own compiler) may be missing bool.
*/
#if defined(__VMS) || defined(__SUNPRO_CC) || defined(__DECCXX) || defined(__MVS__)
  #define NEED_FAKE_BOOL
#elif defined(_HPUX) || defined(_OLD_NEXT_)
  #define NEED_FAKE_BOOL
#elif defined(__IBMCPP__)
  #define NEED_FAKE_BOOL
#elif defined(__WATCOMC__) && (__WATCOMC__ < 1100)
  /* nothing - bool is defined */
#elif defined(__xlc) || defined(__xlC) || defined(__xlC__) || defined(__XLC121__)
  #define NEED_FAKE_BOOL
#elif (defined(__mips) && __mips < 3 && !defined(__GNUC__))
  #define NEED_FAKE_BOOL
#elif (defined(__TURBOC__) && __TURBOC__ <= 0x400)
  #define NEED_FAKE_BOOL
#elif (defined(_MSC_VER) && _MSC_VER < 1100)
  #define NEED_FAKE_BOOL
#elif (defined(_SEQUENT_) && !defined(__GNUC__))
  #define NEED_FAKE_BOOL
#endif
#if defined(NEED_FAKE_BOOL)
    typedef int bool;
    #define true 1
    #define false 0
#endif
#endif

/* ----------------------------------------------------------------- */

#ifdef __cplusplus 
extern "C" {
#endif
#include <limits.h>
#ifdef __cplusplus
}
#endif

#if !defined(SIZEOF_LONG) || !defined(SIZEOF_SHORT) || !defined(SIZEOF_INT)
  #if (!defined(UINT_MAX) || !defined(ULONG_MAX))
    #error your limits.h appears to be borked (UINT_MAX or ULONG_MAX are undefined)
  #elif (ULONG_MAX < UINT_MAX)
    #error your limits.h is borked. ULONG_MAX can never be less than UINT_MAX
  #else
    #if (!defined(USHRT_MAX) && defined(USHORT_MAX))
      #define USHRT_MAX USHORT_MAX 
    #endif
    #if !defined(SIZEOF_SHORT) && defined(USHRT_MAX)
      #if (USHRT_MAX == 0xFF)
        #define SIZEOF_SHORT 1
      #elif (USHRT_MAX == 0xFFFFUL)
        #define SIZEOF_SHORT 2
      #elif (USHRT_MAX == 0xFFFFFFFFUL)
        #define SIZEOF_SHORT 4
      #elif (USHRT_MAX == 0xFFFFFFFFFFFFFFFFUL)
        #define SIZEOF_SHORT 8
      #else
        #error fixme: sizeof(unsigned short) !=1 and !=2 and !=4 and !=8?
      #endif	
    #endif
    #if defined(SIZEOF_INT)
      #ifndef SIZEOF_SHORT
        #if (SIZEOF_INT < 4)
          #define SIZEOF_SHORT SIZEOF_INT
        #elif (SIZEOF_INT > 4)
          #define SIZEOF_SHORT (SIZEOF_INT>>1)
        #else 
          #define SIZEOF_SHORT 2
        #endif
      #endif
      #ifndef SIZEOF_LONG
        #define SIZEOF_LONG (SIZEOF_INT<<1)
      #endif
    #elif (UINT_MAX == 0xFFUL)
      #ifndef SIZEOF_SHORT
        #define SIZEOF_SHORT 1
      #endif
      #define SIZEOF_INT   1
      #ifndef SIZEOF_LONG
        #if (ULONG_MAX > UINT_MAX)
          #define SIZEOF_LONG  2
        #else
          #define SIZEOF_LONG  1
        #endif
      #endif
    #elif (UINT_MAX == 0xFFFFUL)
      #ifndef SIZEOF_SHORT
        #define SIZEOF_SHORT 2
      #endif
      #define SIZEOF_INT   2
      #ifndef SIZEOF_LONG
        #if (ULONG_MAX > UINT_MAX)
          #define SIZEOF_LONG  4
        #else
          #define SIZEOF_LONG  2
        #endif
      #endif
    #elif (UINT_MAX == 0xFFFFFFFFUL)
      #ifndef SIZEOF_SHORT
        #define SIZEOF_SHORT 2
      #endif
      #define SIZEOF_INT   4
      #ifndef SIZEOF_LONG
        #if (ULONG_MAX > UINT_MAX)
          #define SIZEOF_LONG  8
        #else
          #define SIZEOF_LONG  4
        #endif
      #endif
    #elif (UINT_MAX == 0xFFFFFFFFFFFFFFFFUL)
      #ifndef SIZEOF_SHORT
        #define SIZEOF_SHORT 4
      #endif
      #define SIZEOF_INT   8
      #ifndef SIZEOF_LONG
        #if (ULONG_MAX > UINT_MAX)
          #define SIZEOF_LONG  16
        #else
          #define SIZEOF_LONG  8
        #endif
      #endif
    #else
      #error fixme: sizeof(int) > 8? what would sizeof(short) be?
    #endif
  #endif /* ULONG_MAX >= UINT_MAX */
#endif
      
#if (defined(SIZEOF_SHORT) && (SIZEOF_SHORT == 2))
  typedef unsigned short u16;
/* typedef signed short s16; */
#elif (defined(SIZEOF_SHORT) && (SIZEOF_INT == 2))
  typedef unsigned int u16;
/* typedef signed int s16; */
#elif (defined(SIZEOF_LONG) && (SIZEOF_LONG == 2))
  typedef unsigned long u16;
/* typedef signed long s16; */
#else
  #error types u16 is undefined (try wchar_t)
#endif
#if (defined(SIZEOF_SHORT) && (SIZEOF_SHORT == 4))
  typedef unsigned short u32;
  typedef signed short s32;
#elif (defined(SIZEOF_INT) && (SIZEOF_INT == 4))
  typedef unsigned int u32;
  typedef signed int s32;
#elif (defined(SIZEOF_LONG) && (SIZEOF_LONG == 4))
  typedef unsigned long u32;
  typedef signed long s32;
#else
  #error types u32/s32 is undefined
#endif
#if (defined(SIZEOF_SHORT) && (SIZEOF_SHORT == 8))
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned short ui64;
  typedef signed short si64;
#elif (defined(SIZEOF_INT) && (SIZEOF_INT == 8))
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned int ui64;
  typedef signed int si64;
#elif (defined(SIZEOF_LONG) && (SIZEOF_LONG == 8))
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned long ui64;
  typedef signed long si64;
#elif defined(__GCC__) || defined(__GNUC__)
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned long long ui64;
  typedef signed long long si64;
#elif (defined(__WATCOMC__) && (__WATCOMC__ >= 11))
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned __int64 ui64;
  typedef __int64 si64;
#elif (defined(_MSC_VER) && (_MSC_VER >= 11)) /* VC++ >= 5.0 */
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned __int64 ui64;
  typedef __int64 si64;
#elif defined(__MWERKS__) || defined(__MRC__) || defined(__MOTO__) /* verify these */
  #define HAVE_I64
  #define SIZEOF_LONGLONG 8
  typedef unsigned long long ui64;
  typedef signed long long si64;
#endif  

typedef unsigned char u8;
typedef struct fake_u64 { u32 hi, lo; } u64;

/*
typedef signed char s8;
typedef struct fake_u64 { s32 hi, lo; } s64;
struct u128 { u64 hi, lo; };
struct s128 { s64 hi, lo; };
*/

#endif /* __CPUTYPES_H__ */
