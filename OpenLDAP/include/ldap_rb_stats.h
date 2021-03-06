/*
 * Generated by dtrace(1M).
 */

#ifndef	_LDAP_RB_STATS_H
#define	_LDAP_RB_STATS_H

#if !defined(DTRACE_PROBES_DISABLED) || !DTRACE_PROBES_DISABLED
#include <unistd.h>

#endif /* !defined(DTRACE_PROBES_DISABLED) || !DTRACE_PROBES_DISABLED */

#ifdef	__cplusplus
extern "C" {
#endif

#define LDAP_RB_STATS_STABILITY "___dtrace_stability$ldap_rb_stats$v1$1_1_0_1_1_0_1_1_0_1_1_0_1_1_0"

#define LDAP_RB_STATS_TYPEDEFS "___dtrace_typedefs$ldap_rb_stats$v2"

#if !defined(DTRACE_PROBES_DISABLED) || !DTRACE_PROBES_DISABLED

#define	LDAP_RB_STATS_COUNT(arg0, arg1, arg2) \
do { \
	__asm__ volatile(".reference " LDAP_RB_STATS_TYPEDEFS); \
	__dtrace_probe$ldap_rb_stats$count$v1$696e74$696e74$766f6964202a(arg0, arg1, arg2); \
	__asm__ volatile(".reference " LDAP_RB_STATS_STABILITY); \
} while (0)
#define	LDAP_RB_STATS_COUNT_ENABLED() \
	({ int _r = __dtrace_isenabled$ldap_rb_stats$count$v1(); \
		__asm__ volatile(""); \
		_r; })


extern void __dtrace_probe$ldap_rb_stats$count$v1$696e74$696e74$766f6964202a(int, int, const void *);
extern int __dtrace_isenabled$ldap_rb_stats$count$v1(void);

#else

#define	LDAP_RB_STATS_COUNT(arg0, arg1, arg2) \
do { \
	} while (0)
#define	LDAP_RB_STATS_COUNT_ENABLED() (0)

#endif /* !defined(DTRACE_PROBES_DISABLED) || !DTRACE_PROBES_DISABLED */


#ifdef	__cplusplus
}
#endif

#endif	/* _LDAP_RB_STATS_H */
