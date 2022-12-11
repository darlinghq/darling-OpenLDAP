# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
##---------------------------------------------------------------------------
#
# Top-level Makefile template
#

PACKAGE= OpenLDAP
VERSION= 2.4.28
RELEASEDATE= 2011/11/24


SHELL = /bin/sh

top_builddir = ../..

srcdir = .
top_srcdir = ../..

prefix = /usr/local
exec_prefix = ${prefix}
ldap_subdir = /openldap

bindir = ${exec_prefix}/bin
datadir = ${prefix}/share$(ldap_subdir)
includedir = ${prefix}/include
infodir = ${prefix}/share/info
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localstatedir = ${prefix}/var
mandir = ${prefix}/share/man
moduledir = ${exec_prefix}/libexec$(ldap_subdir)
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
sysconfdir = ${prefix}/etc$(ldap_subdir)
schemadir = $(sysconfdir)/schema

PLAT = UNIX
EXEEXT = 
OBJEXT = o

BUILD_LIBS_DYNAMIC = static

BUILD_SLAPD = no

SHTOOL = $(top_srcdir)/build/shtool

INSTALL = $(SHTOOL) install -c
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_SCRIPT = $(INSTALL)

STRIP = -s

LINT = lint
5LINT = 5lint

MKDEP = $(top_srcdir)/build/mkdep $(MKDEPFLAG) \
	-d "$(srcdir)" -c "$(MKDEP_CC)" -m "$(MKDEP_CFLAGS)"
MKDEP_CC	= cc
MKDEP_CFLAGS = -M

MKVERSION = $(top_srcdir)/build/mkversion -v "$(VERSION)"

LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIBRELEASE = 2.4
LIBVERSION = 10:1:8
LTVERSION = -release $(LIBRELEASE) -version-info $(LIBVERSION)

# libtool --only flag for libraries: platform specific
NT_LTONLY_LIB = # --only-$(BUILD_LIBS_DYNAMIC)
LTONLY_LIB = $(UNIX_LTONLY_LIB)

# libtool --only flag for modules: depends on linkage of module
# The BUILD_MOD macro is defined in each backend Makefile.in file
LTONLY_yes = --tag=disable-shared
LTONLY_mod = --tag=disable-static
LTONLY_MOD = $(LTONLY_$(BUILD_MOD))

# platform-specific libtool flags
NT_LTFLAGS_LIB = -no-undefined -avoid-version -rpath $(libdir)
NT_LTFLAGS_MOD = -no-undefined -avoid-version -rpath $(moduledir)
UNIX_LTFLAGS_LIB = $(LTVERSION) -rpath $(libdir)
UNIX_LTFLAGS_MOD = $(LTVERSION) -rpath $(moduledir)

# libtool flags
LTFLAGS     = $(UNIX_LTFLAGS)
LTFLAGS_LIB = $(UNIX_LTFLAGS_LIB)
LTFLAGS_MOD = $(UNIX_LTFLAGS_MOD)

# LIB_DEFS defined in liblber and libldap Makefile.in files.
# MOD_DEFS defined in backend Makefile.in files.

# platform-specific LINK_LIBS defined in various Makefile.in files.
# LINK_LIBS referenced in library and module link commands.
LINK_LIBS = $(MOD_LIBS) $(UNIX_LINK_LIBS)

LTSTATIC = -static

LTLINK   = $(LIBTOOL) --mode=link \
	$(CC) $(LTSTATIC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS)

LTCOMPILE_LIB = $(LIBTOOL) $(LTONLY_LIB) --mode=compile \
	$(CC) $(LT_CFLAGS) $(LT_CPPFLAGS) $(LIB_DEFS) -c

LTLINK_LIB = $(LIBTOOL) $(LTONLY_LIB) --mode=link \
	$(CC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS_LIB)

LTCOMPILE_MOD = $(LIBTOOL) $(LTONLY_MOD) --mode=compile \
	$(CC) $(LT_CFLAGS) $(LT_CPPFLAGS) $(MOD_DEFS) -c

LTLINK_MOD = $(LIBTOOL) $(LTONLY_MOD) --mode=link \
	$(CC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS_MOD)

LTINSTALL = $(LIBTOOL) --mode=install $(INSTALL) 
LTFINISH = $(LIBTOOL) --mode=finish

# Misc UNIX commands used in build environment
AR = ar
BASENAME = basename
CAT = cat
CHMOD = chmod
DATE = date
ECHO = $(SHTOOL) echo
HOSTNAME = $(SHTOOL) echo -e "%h%d"
LN = $(SHTOOL) mkln
LN_H = $(LN)
LN_S = $(LN) -s
MAKEINFO = ${SHELL} /Volumes/SystemRoot/home/thomasa/Documents/CodingProjects/Repository/GitHub/darling/src/external/OpenLDAP/OpenLDAP/build/missing --run makeinfo
MKDIR = $(SHTOOL) mkdir -p
MV = $(SHTOOL) move
PWD = pwd
RANLIB = ranlib
RM = rm -f
SED = sed
SUBST = $(SHTOOL) subst

# For manual pages
# MANCOMPRESS=@MANCOMPRESS@
# MANCOMPRESSSUFFIX=@MANCOMPRESSSUFFIX@
MANCOMPRESS=$(CAT)
MANCOMPRESSSUFFIX=

SOELIM=soelim

INCLUDEDIR= $(top_srcdir)/include
LDAP_INCPATH= -I$(LDAP_INCDIR) -I$(INCLUDEDIR)
LDAP_LIBDIR= $(top_builddir)/libraries

LUTIL_LIBS = 
LTHREAD_LIBS =  

BDB_LIBS = 

LDAP_LIBLBER_LA = $(LDAP_LIBDIR)/liblber/liblber.la
LDAP_LIBLDAP_LA = $(LDAP_LIBDIR)/libldap/libldap.la
LDAP_LIBLDAP_R_LA = $(LDAP_LIBDIR)/libldap_r/libldap_r.la

LDAP_LIBREWRITE_A = $(LDAP_LIBDIR)/librewrite/librewrite.a
LDAP_LIBLUNICODE_A = $(LDAP_LIBDIR)/liblunicode/liblunicode.a
LDAP_LIBLUTIL_A = $(LDAP_LIBDIR)/liblutil/liblutil.a

LDAP_L = $(LDAP_LIBLUTIL_A) \
	$(LDAP_LIBLDAP_LA) $(LDAP_LIBLBER_LA)
SLAPD_L = $(LDAP_LIBLUNICODE_A) $(LDAP_LIBREWRITE_A) \
	$(LDAP_LIBLUTIL_A) $(LDAP_LIBLDAP_R_LA) $(LDAP_LIBLBER_LA)

WRAP_LIBS = 
# AutoConfig generated 
AC_CC	= cc
AC_CFLAGS = -g -O2
AC_DEFS =  # -DHAVE_CONFIG_H
AC_LDFLAGS = 
AC_LIBS = -lresolv 

KRB4_LIBS = 
KRB5_LIBS = 
KRB_LIBS =  
SASL_LIBS = -lsasl2
TLS_LIBS = 
AUTH_LIBS = 
SECURITY_LIBS = $(SASL_LIBS) $(KRB_LIBS) $(TLS_LIBS) $(AUTH_LIBS)
ICU_LIBS = 

MODULES_CPPFLAGS = 
MODULES_LDFLAGS = 
MODULES_LIBS = 
SLAPD_PERL_LDFLAGS = 

SLAPD_SQL_LDFLAGS = 
SLAPD_SQL_INCLUDES = 
SLAPD_SQL_LIBS = 

SLAPD_LIBS =       $(ICU_LIBS)

# Our Defaults
CC = $(AC_CC)
DEFS = $(LDAP_INCPATH) $(XINCPATH) $(XDEFS) $(AC_DEFS) $(DEFINES)
CFLAGS = $(AC_CFLAGS) $(DEFS)
LDFLAGS = $(LDAP_LIBPATH) $(AC_LDFLAGS) $(XLDFLAGS)
LIBS = $(XLIBS) $(XXLIBS) $(AC_LIBS) $(XXXLIBS)

LT_CFLAGS = $(AC_CFLAGS)
LT_CPPFLAGS = $(DEFS)

all:		all-common all-local FORCE
install:	install-common install-local FORCE
clean:		clean-common clean-local FORCE
veryclean:	veryclean-common veryclean-local FORCE
depend:		depend-common depend-local FORCE

# empty common rules
all-common:
install-common:
clean-common:
veryclean-common:	clean-common FORCE
depend-common:
lint-common:
lint5-common:

# empty local rules
all-local:
install-local:
clean-local:
veryclean-local:	clean-local FORCE
depend-local:
lint-local:
lint5-local:

veryclean: FORCE
	$(RM) Makefile
	$(RM) -r .libs

Makefile: Makefile.in $(top_srcdir)/build/top.mk

pathtest:
	$(SHTOOL) --version

# empty rule for forcing rules
FORCE:

##---------------------------------------------------------------------------

# LIBREWRITE
# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##
## Copyright 2000-2001 Pierangelo Masarati <ando@sys-net.it>
##

SRCS = config.c context.c info.c ldapmap.c map.c params.c rule.c \
	session.c subst.c var.c xmap.c \
	parse.c rewrite.c
XSRCS = version.c
OBJS = config.o context.o info.o ldapmap.o map.o params.o rule.o \
	session.o subst.o var.o xmap.o

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

LIBRARY = librewrite.a
PROGRAMS	= rewrite
XLIBS = $(LIBRARY) $(LDAP_LIBLUTIL_A) \
	$(LDAP_LIBLDAP_R_LA) $(LDAP_LIBLBER_LA)
XXLIBS  = $(SECURITY_LIBS) $(LUTIL_LIBS)
XXXLIBS = $(LTHREAD_LIBS)

rewrite:	$(XLIBS) rewrite.o parse.o
	$(LTLINK) -o $@ rewrite.o parse.o $(LIBS)
# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##---------------------------------------------------------------------------
#
# Makefile Template for Libraries
#

all-common: $(LIBRARY) $(PROGRAMS)

version.c: Makefile
	$(RM) $@
	$(MKVERSION) $(LIBRARY) > $@

version.o version.lo: version.c $(OBJS)

install-common: FORCE

lint: lint-local FORCE
	$(LINT) $(DEFS) $(DEFINES) $(SRCS)

lint5: lint5-local FORCE
	$(5LINT) $(DEFS) $(DEFINES) $(SRCS)

#
# In the mingw/cygwin environment, the so and dll files must be
# deleted separately, instead of using the {.so*,*.dll} construct
# that was previously used. It just didn't work.
#
clean-common: 	FORCE
	$(RM) $(LIBRARY) ../$(LIBRARY) $(XLIBRARY) \
		$(PROGRAMS) $(XPROGRAMS) $(XSRCS) $(XXSRCS) \
		*.o *.lo a.out *.exe core version.c .libs/*

depend-common: FORCE
	$(MKDEP) $(DEFS) $(DEFINES) $(SRCS) $(XXSRCS)

lint-local: FORCE
lint5-local: FORCE

Makefile: $(top_srcdir)/build/lib.mk

# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##---------------------------------------------------------------------------
#
# Makefile Template for Static Libraries
#

$(LIBRARY): version.o
	$(AR) ru $@ $(OBJS) version.o
	@$(RANLIB) $@

Makefile: $(top_srcdir)/build/lib-static.mk
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


#
# files: -I../../include -I../../include config.c context.c info.c ldapmap.c map.c params.c rule.c session.c subst.c var.c xmap.c parse.c rewrite.c
# command: cc -M -I.  -I../../include -I../../include config.c context.c info.c ldapmap.c map.c params.c rule.c session.c subst.c var.c xmap.c parse.c rewrite.c
#

config.o: ../../include/portable.h
config.o: config.c
config.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
config.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
config.o: ../../include/ldap_cdefs.h
config.o: ../../include/ac/fdset.h
config.o: ../../include/ac/assert.h
config.o: ../../include/ldap_features.h
config.o: /usr/include/sys/cdefs.h
config.o: /usr/include/assert.h
config.o: /usr/include/sys/_symbol_aliasing.h
config.o: ../../include/ac/localize.h
config.o: /usr/include/sys/_posix_availability.h
config.o: ../../include/ac/stdlib.h
config.o: /usr/include/stdlib.h
config.o: rewrite-int.h
config.o: /usr/include/AvailabilityInternal.h
config.o: /usr/include/Availability.h
config.o: /usr/include/sys/_types.h
config.o: /usr/include/_types.h
config.o: /usr/include/i386/_types.h
config.o: /usr/include/machine/_types.h
config.o: /usr/include/sys/wait.h
config.o: /usr/include/sys/_pthread/_pthread_types.h
config.o: /usr/include/sys/_types/_id_t.h
config.o: /usr/include/sys/_types/_pid_t.h
config.o: /usr/include/sys/appleapiopts.h
config.o: /usr/include/sys/signal.h
config.o: /usr/include/i386/signal.h
config.o: /usr/include/machine/signal.h
config.o: /usr/include/i386/_mcontext.h
config.o: /usr/include/machine/_mcontext.h
config.o: /usr/include/mach/i386/_structs.h
config.o: /usr/include/sys/_pthread/_pthread_attr_t.h
config.o: /usr/include/sys/_types/_sigaltstack.h
config.o: /usr/include/sys/_types/_ucontext.h
config.o: /usr/include/sys/_types/_size_t.h
config.o: /usr/include/sys/_types/_sigset_t.h
config.o: /usr/include/sys/resource.h
config.o: /usr/include/sys/_types/_uid_t.h
config.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
config.o: /usr/include/sys/_types/_int8_t.h
config.o: /usr/include/stdint.h
config.o: /usr/include/sys/_types/_int32_t.h
config.o: /usr/include/sys/_types/_int16_t.h
config.o: /usr/include/_types/_uint8_t.h
config.o: /usr/include/sys/_types/_int64_t.h
config.o: /usr/include/_types/_uint32_t.h
config.o: /usr/include/_types/_uint16_t.h
config.o: /usr/include/sys/_types/_intptr_t.h
config.o: /usr/include/_types/_uint64_t.h
config.o: /usr/include/_types/_intmax_t.h
config.o: /usr/include/sys/_types/_uintptr_t.h
config.o: /usr/include/sys/_types/_timeval.h
config.o: /usr/include/_types/_uintmax_t.h
config.o: /usr/include/i386/endian.h
config.o: /usr/include/machine/endian.h
config.o: /usr/include/libkern/_OSByteOrder.h
config.o: /usr/include/sys/_endian.h
config.o: /usr/include/alloca.h
config.o: /usr/include/libkern/i386/_OSByteOrder.h
config.o: /usr/include/sys/_types/_rune_t.h
config.o: /usr/include/sys/_types/_ct_rune_t.h
config.o: /usr/include/sys/_types/_null.h
config.o: /usr/include/sys/_types/_wchar_t.h
config.o: /usr/include/i386/types.h
config.o: /usr/include/machine/types.h
config.o: /usr/include/sys/_types/_u_int8_t.h
config.o: /usr/include/sys/_types/_u_int16_t.h
config.o: /usr/include/sys/_types/_u_int32_t.h
config.o: /usr/include/sys/_types/_dev_t.h
config.o: /usr/include/sys/_types/_u_int64_t.h
config.o: /usr/include/sys/_types/_mode_t.h
config.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
config.o: /usr/include/machine/limits.h
config.o: /usr/include/limits.h
config.o: /usr/include/i386/_limits.h
config.o: /usr/include/i386/limits.h
config.o: ../../include/ac/string.h
config.o: /usr/include/sys/syslimits.h
config.o: /usr/include/sys/_types/_rsize_t.h
config.o: /usr/include/string.h
config.o: /usr/include/sys/_types/_ssize_t.h
config.o: /usr/include/sys/_types/_errno_t.h
config.o: /usr/include/secure/_string.h
config.o: /usr/include/strings.h
config.o: ../../include/ac/syslog.h
config.o: /usr/include/secure/_common.h
config.o: /usr/include/sys/syslog.h
config.o: /usr/include/syslog.h
config.o: /usr/include/sys/types.h
config.o: ../../include/ac/regex.h
config.o: /usr/include/sys/_types/_blkcnt_t.h
config.o: /usr/include/sys/_types/_gid_t.h
config.o: /usr/include/sys/_types/_blksize_t.h
config.o: /usr/include/sys/_types/_in_addr_t.h
config.o: /usr/include/sys/_types/_ino_t.h
config.o: /usr/include/sys/_types/_in_port_t.h
config.o: /usr/include/sys/_types/_key_t.h
config.o: /usr/include/sys/_types/_ino64_t.h
config.o: /usr/include/sys/_types/_off_t.h
config.o: /usr/include/sys/_types/_nlink_t.h
config.o: /usr/include/sys/_types/_time_t.h
config.o: /usr/include/sys/_types/_clock_t.h
config.o: /usr/include/sys/_types/_useconds_t.h
config.o: /usr/include/sys/_types/_suseconds_t.h
config.o: /usr/include/sys/_types/_fd_def.h
config.o: /usr/include/sys/_types/_fd_setsize.h
config.o: /usr/include/sys/_types/_fd_clr.h
config.o: /usr/include/sys/_types/_fd_set.h
config.o: /usr/include/sys/_types/_fd_isset.h
config.o: /usr/include/sys/_types/_fd_zero.h
config.o: /usr/include/sys/_types/_fd_copy.h
config.o: /usr/include/sys/_pthread/_pthread_cond_t.h
config.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
config.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
config.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
config.o: /usr/include/sys/_pthread/_pthread_once_t.h
config.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
config.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
config.o: /usr/include/sys/_pthread/_pthread_t.h
config.o: /usr/include/sys/_pthread/_pthread_key_t.h
config.o: /usr/include/sys/_types/_fsblkcnt_t.h
config.o: /usr/include/regex.h
config.o: /usr/include/sys/_types/_fsfilcnt_t.h
config.o: /usr/include/poll.h
config.o: /usr/include/sys/poll.h
config.o: ../../include/ac/socket.h
config.o: /usr/include/machine/_param.h
config.o: /usr/include/sys/socket.h
config.o: /usr/include/net/net_kev.h
config.o: /usr/include/i386/_param.h
config.o: /usr/include/sys/_types/_sa_family_t.h
config.o: /usr/include/sys/_types/_socklen_t.h
config.o: /usr/include/sys/un.h
config.o: /usr/include/sys/_types/_iovec_t.h
config.o: /usr/include/sys/_types/_timespec.h
config.o: /usr/include/sys/select.h
config.o: /usr/include/netinet/in.h
config.o: /usr/include/sys/_select.h
config.o: /usr/include/netinet/tcp.h
config.o: /usr/include/netinet6/in6.h
config.o: /usr/include/arpa/nameser.h
config.o: /usr/include/arpa/inet.h
config.o: /usr/include/machine/param.h
config.o: /usr/include/sys/param.h
config.o: /usr/include/netdb.h
config.o: /usr/include/resolv.h
config.o: /usr/include/i386/param.h
config.o: /usr/include/sys/_types/_va_list.h
config.o: /usr/include/stdio.h
config.o: /usr/include/secure/_stdio.h
config.o: /usr/include/sys/stdio.h
config.o: /usr/include/unistd.h
config.o: ../../include/ac/unistd.h
config.o: /usr/include/sys/_types/_posix_vdisable.h
config.o: /usr/include/sys/unistd.h
config.o: /usr/include/sys/_types/_uuid_t.h
config.o: /usr/include/sys/_types/_seek_set.h
config.o: /usr/include/getopt.h
config.o: /usr/include/gethostuuid.h
config.o: ../../include/ac/ctype.h
config.o: ../../include/lutil_lockf.h
config.o: /usr/include/runetype.h
config.o: /usr/include/ctype.h
config.o: ../../include/lber.h
config.o: /usr/include/sys/_types/_wint_t.h
config.o: ../../include/ldap.h
config.o: ../../include/lber_types.h
config.o: ../../include/lutil.h
config.o: ../../include/avl.h
config.o: ../../include/ldap_log.h
config.o: ../../include/ldap_pvt_thread.h
config.o: ../../include/rewrite.h
config.o: /usr/include/pthread.h
config.o: ../../include/ldap_int_thread.h
config.o: /usr/include/pthread/sched.h
config.o: /usr/include/pthread/pthread_impl.h
config.o: /usr/include/pthread/qos.h
config.o: /usr/include/sys/qos.h
config.o: /usr/include/time.h
config.o: rewrite-map.h
config.o: /usr/include/sys/_types/_mach_port_t.h
context.o: ../../include/portable.h
context.o: context.c
context.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
context.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
context.o: ../../include/ldap_cdefs.h
context.o: ../../include/ac/fdset.h
context.o: ../../include/ac/assert.h
context.o: ../../include/ldap_features.h
context.o: /usr/include/sys/cdefs.h
context.o: /usr/include/assert.h
context.o: /usr/include/sys/_symbol_aliasing.h
context.o: ../../include/ac/localize.h
context.o: /usr/include/sys/_posix_availability.h
context.o: ../../include/ac/stdlib.h
context.o: /usr/include/stdlib.h
context.o: rewrite-int.h
context.o: /usr/include/AvailabilityInternal.h
context.o: /usr/include/Availability.h
context.o: /usr/include/sys/_types.h
context.o: /usr/include/_types.h
context.o: /usr/include/i386/_types.h
context.o: /usr/include/machine/_types.h
context.o: /usr/include/sys/wait.h
context.o: /usr/include/sys/_pthread/_pthread_types.h
context.o: /usr/include/sys/_types/_id_t.h
context.o: /usr/include/sys/_types/_pid_t.h
context.o: /usr/include/sys/appleapiopts.h
context.o: /usr/include/sys/signal.h
context.o: /usr/include/i386/signal.h
context.o: /usr/include/machine/signal.h
context.o: /usr/include/i386/_mcontext.h
context.o: /usr/include/machine/_mcontext.h
context.o: /usr/include/mach/i386/_structs.h
context.o: /usr/include/sys/_pthread/_pthread_attr_t.h
context.o: /usr/include/sys/_types/_sigaltstack.h
context.o: /usr/include/sys/_types/_ucontext.h
context.o: /usr/include/sys/_types/_size_t.h
context.o: /usr/include/sys/_types/_sigset_t.h
context.o: /usr/include/sys/resource.h
context.o: /usr/include/sys/_types/_uid_t.h
context.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
context.o: /usr/include/sys/_types/_int8_t.h
context.o: /usr/include/stdint.h
context.o: /usr/include/sys/_types/_int32_t.h
context.o: /usr/include/sys/_types/_int16_t.h
context.o: /usr/include/_types/_uint8_t.h
context.o: /usr/include/sys/_types/_int64_t.h
context.o: /usr/include/_types/_uint32_t.h
context.o: /usr/include/_types/_uint16_t.h
context.o: /usr/include/sys/_types/_intptr_t.h
context.o: /usr/include/_types/_uint64_t.h
context.o: /usr/include/_types/_intmax_t.h
context.o: /usr/include/sys/_types/_uintptr_t.h
context.o: /usr/include/sys/_types/_timeval.h
context.o: /usr/include/_types/_uintmax_t.h
context.o: /usr/include/i386/endian.h
context.o: /usr/include/machine/endian.h
context.o: /usr/include/libkern/_OSByteOrder.h
context.o: /usr/include/sys/_endian.h
context.o: /usr/include/alloca.h
context.o: /usr/include/libkern/i386/_OSByteOrder.h
context.o: /usr/include/sys/_types/_rune_t.h
context.o: /usr/include/sys/_types/_ct_rune_t.h
context.o: /usr/include/sys/_types/_null.h
context.o: /usr/include/sys/_types/_wchar_t.h
context.o: /usr/include/i386/types.h
context.o: /usr/include/machine/types.h
context.o: /usr/include/sys/_types/_u_int8_t.h
context.o: /usr/include/sys/_types/_u_int16_t.h
context.o: /usr/include/sys/_types/_u_int32_t.h
context.o: /usr/include/sys/_types/_dev_t.h
context.o: /usr/include/sys/_types/_u_int64_t.h
context.o: /usr/include/sys/_types/_mode_t.h
context.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
context.o: /usr/include/machine/limits.h
context.o: /usr/include/limits.h
context.o: /usr/include/i386/_limits.h
context.o: /usr/include/i386/limits.h
context.o: ../../include/ac/string.h
context.o: /usr/include/sys/syslimits.h
context.o: /usr/include/sys/_types/_rsize_t.h
context.o: /usr/include/string.h
context.o: /usr/include/sys/_types/_ssize_t.h
context.o: /usr/include/sys/_types/_errno_t.h
context.o: /usr/include/secure/_string.h
context.o: /usr/include/strings.h
context.o: ../../include/ac/syslog.h
context.o: /usr/include/secure/_common.h
context.o: /usr/include/sys/syslog.h
context.o: /usr/include/syslog.h
context.o: /usr/include/sys/types.h
context.o: ../../include/ac/regex.h
context.o: /usr/include/sys/_types/_blkcnt_t.h
context.o: /usr/include/sys/_types/_gid_t.h
context.o: /usr/include/sys/_types/_blksize_t.h
context.o: /usr/include/sys/_types/_in_addr_t.h
context.o: /usr/include/sys/_types/_ino_t.h
context.o: /usr/include/sys/_types/_in_port_t.h
context.o: /usr/include/sys/_types/_key_t.h
context.o: /usr/include/sys/_types/_ino64_t.h
context.o: /usr/include/sys/_types/_off_t.h
context.o: /usr/include/sys/_types/_nlink_t.h
context.o: /usr/include/sys/_types/_time_t.h
context.o: /usr/include/sys/_types/_clock_t.h
context.o: /usr/include/sys/_types/_useconds_t.h
context.o: /usr/include/sys/_types/_suseconds_t.h
context.o: /usr/include/sys/_types/_fd_def.h
context.o: /usr/include/sys/_types/_fd_setsize.h
context.o: /usr/include/sys/_types/_fd_clr.h
context.o: /usr/include/sys/_types/_fd_set.h
context.o: /usr/include/sys/_types/_fd_isset.h
context.o: /usr/include/sys/_types/_fd_zero.h
context.o: /usr/include/sys/_types/_fd_copy.h
context.o: /usr/include/sys/_pthread/_pthread_cond_t.h
context.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
context.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
context.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
context.o: /usr/include/sys/_pthread/_pthread_once_t.h
context.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
context.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
context.o: /usr/include/sys/_pthread/_pthread_t.h
context.o: /usr/include/sys/_pthread/_pthread_key_t.h
context.o: /usr/include/sys/_types/_fsblkcnt_t.h
context.o: /usr/include/regex.h
context.o: /usr/include/sys/_types/_fsfilcnt_t.h
context.o: /usr/include/poll.h
context.o: /usr/include/sys/poll.h
context.o: ../../include/ac/socket.h
context.o: /usr/include/machine/_param.h
context.o: /usr/include/sys/socket.h
context.o: /usr/include/net/net_kev.h
context.o: /usr/include/i386/_param.h
context.o: /usr/include/sys/_types/_sa_family_t.h
context.o: /usr/include/sys/_types/_socklen_t.h
context.o: /usr/include/sys/un.h
context.o: /usr/include/sys/_types/_iovec_t.h
context.o: /usr/include/sys/_types/_timespec.h
context.o: /usr/include/sys/select.h
context.o: /usr/include/netinet/in.h
context.o: /usr/include/sys/_select.h
context.o: /usr/include/netinet/tcp.h
context.o: /usr/include/netinet6/in6.h
context.o: /usr/include/arpa/nameser.h
context.o: /usr/include/arpa/inet.h
context.o: /usr/include/machine/param.h
context.o: /usr/include/sys/param.h
context.o: /usr/include/netdb.h
context.o: /usr/include/resolv.h
context.o: /usr/include/i386/param.h
context.o: /usr/include/sys/_types/_va_list.h
context.o: /usr/include/stdio.h
context.o: /usr/include/secure/_stdio.h
context.o: /usr/include/sys/stdio.h
context.o: /usr/include/unistd.h
context.o: ../../include/ac/unistd.h
context.o: /usr/include/sys/_types/_posix_vdisable.h
context.o: /usr/include/sys/unistd.h
context.o: /usr/include/sys/_types/_uuid_t.h
context.o: /usr/include/sys/_types/_seek_set.h
context.o: /usr/include/getopt.h
context.o: /usr/include/gethostuuid.h
context.o: ../../include/ac/ctype.h
context.o: ../../include/lutil_lockf.h
context.o: /usr/include/runetype.h
context.o: /usr/include/ctype.h
context.o: ../../include/lber.h
context.o: /usr/include/sys/_types/_wint_t.h
context.o: ../../include/ldap.h
context.o: ../../include/lber_types.h
context.o: ../../include/lutil.h
context.o: ../../include/avl.h
context.o: ../../include/ldap_log.h
context.o: ../../include/ldap_pvt_thread.h
context.o: ../../include/rewrite.h
context.o: /usr/include/pthread.h
context.o: ../../include/ldap_int_thread.h
context.o: /usr/include/pthread/sched.h
context.o: /usr/include/pthread/pthread_impl.h
context.o: /usr/include/pthread/qos.h
context.o: /usr/include/sys/qos.h
context.o: /usr/include/time.h
context.o: /usr/include/sys/_types/_mach_port_t.h
info.o: ../../include/portable.h
info.o: info.c
info.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
info.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
info.o: ../../include/ldap_cdefs.h
info.o: ../../include/ac/fdset.h
info.o: ../../include/ac/assert.h
info.o: ../../include/ldap_features.h
info.o: /usr/include/sys/cdefs.h
info.o: /usr/include/assert.h
info.o: /usr/include/sys/_symbol_aliasing.h
info.o: ../../include/ac/localize.h
info.o: /usr/include/sys/_posix_availability.h
info.o: ../../include/ac/stdlib.h
info.o: /usr/include/stdlib.h
info.o: rewrite-int.h
info.o: /usr/include/AvailabilityInternal.h
info.o: /usr/include/Availability.h
info.o: /usr/include/sys/_types.h
info.o: /usr/include/_types.h
info.o: /usr/include/i386/_types.h
info.o: /usr/include/machine/_types.h
info.o: /usr/include/sys/wait.h
info.o: /usr/include/sys/_pthread/_pthread_types.h
info.o: /usr/include/sys/_types/_id_t.h
info.o: /usr/include/sys/_types/_pid_t.h
info.o: /usr/include/sys/appleapiopts.h
info.o: /usr/include/sys/signal.h
info.o: /usr/include/i386/signal.h
info.o: /usr/include/machine/signal.h
info.o: /usr/include/i386/_mcontext.h
info.o: /usr/include/machine/_mcontext.h
info.o: /usr/include/mach/i386/_structs.h
info.o: /usr/include/sys/_pthread/_pthread_attr_t.h
info.o: /usr/include/sys/_types/_sigaltstack.h
info.o: /usr/include/sys/_types/_ucontext.h
info.o: /usr/include/sys/_types/_size_t.h
info.o: /usr/include/sys/_types/_sigset_t.h
info.o: /usr/include/sys/resource.h
info.o: /usr/include/sys/_types/_uid_t.h
info.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
info.o: /usr/include/sys/_types/_int8_t.h
info.o: /usr/include/stdint.h
info.o: /usr/include/sys/_types/_int32_t.h
info.o: /usr/include/sys/_types/_int16_t.h
info.o: /usr/include/_types/_uint8_t.h
info.o: /usr/include/sys/_types/_int64_t.h
info.o: /usr/include/_types/_uint32_t.h
info.o: /usr/include/_types/_uint16_t.h
info.o: /usr/include/sys/_types/_intptr_t.h
info.o: /usr/include/_types/_uint64_t.h
info.o: /usr/include/_types/_intmax_t.h
info.o: /usr/include/sys/_types/_uintptr_t.h
info.o: /usr/include/sys/_types/_timeval.h
info.o: /usr/include/_types/_uintmax_t.h
info.o: /usr/include/i386/endian.h
info.o: /usr/include/machine/endian.h
info.o: /usr/include/libkern/_OSByteOrder.h
info.o: /usr/include/sys/_endian.h
info.o: /usr/include/alloca.h
info.o: /usr/include/libkern/i386/_OSByteOrder.h
info.o: /usr/include/sys/_types/_rune_t.h
info.o: /usr/include/sys/_types/_ct_rune_t.h
info.o: /usr/include/sys/_types/_null.h
info.o: /usr/include/sys/_types/_wchar_t.h
info.o: /usr/include/i386/types.h
info.o: /usr/include/machine/types.h
info.o: /usr/include/sys/_types/_u_int8_t.h
info.o: /usr/include/sys/_types/_u_int16_t.h
info.o: /usr/include/sys/_types/_u_int32_t.h
info.o: /usr/include/sys/_types/_dev_t.h
info.o: /usr/include/sys/_types/_u_int64_t.h
info.o: /usr/include/sys/_types/_mode_t.h
info.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
info.o: /usr/include/machine/limits.h
info.o: /usr/include/limits.h
info.o: /usr/include/i386/_limits.h
info.o: /usr/include/i386/limits.h
info.o: ../../include/ac/string.h
info.o: /usr/include/sys/syslimits.h
info.o: /usr/include/sys/_types/_rsize_t.h
info.o: /usr/include/string.h
info.o: /usr/include/sys/_types/_ssize_t.h
info.o: /usr/include/sys/_types/_errno_t.h
info.o: /usr/include/secure/_string.h
info.o: /usr/include/strings.h
info.o: ../../include/ac/syslog.h
info.o: /usr/include/secure/_common.h
info.o: /usr/include/sys/syslog.h
info.o: /usr/include/syslog.h
info.o: /usr/include/sys/types.h
info.o: ../../include/ac/regex.h
info.o: /usr/include/sys/_types/_blkcnt_t.h
info.o: /usr/include/sys/_types/_gid_t.h
info.o: /usr/include/sys/_types/_blksize_t.h
info.o: /usr/include/sys/_types/_in_addr_t.h
info.o: /usr/include/sys/_types/_ino_t.h
info.o: /usr/include/sys/_types/_in_port_t.h
info.o: /usr/include/sys/_types/_key_t.h
info.o: /usr/include/sys/_types/_ino64_t.h
info.o: /usr/include/sys/_types/_off_t.h
info.o: /usr/include/sys/_types/_nlink_t.h
info.o: /usr/include/sys/_types/_time_t.h
info.o: /usr/include/sys/_types/_clock_t.h
info.o: /usr/include/sys/_types/_useconds_t.h
info.o: /usr/include/sys/_types/_suseconds_t.h
info.o: /usr/include/sys/_types/_fd_def.h
info.o: /usr/include/sys/_types/_fd_setsize.h
info.o: /usr/include/sys/_types/_fd_clr.h
info.o: /usr/include/sys/_types/_fd_set.h
info.o: /usr/include/sys/_types/_fd_isset.h
info.o: /usr/include/sys/_types/_fd_zero.h
info.o: /usr/include/sys/_types/_fd_copy.h
info.o: /usr/include/sys/_pthread/_pthread_cond_t.h
info.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
info.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
info.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
info.o: /usr/include/sys/_pthread/_pthread_once_t.h
info.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
info.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
info.o: /usr/include/sys/_pthread/_pthread_t.h
info.o: /usr/include/sys/_pthread/_pthread_key_t.h
info.o: /usr/include/sys/_types/_fsblkcnt_t.h
info.o: /usr/include/regex.h
info.o: /usr/include/sys/_types/_fsfilcnt_t.h
info.o: /usr/include/poll.h
info.o: /usr/include/sys/poll.h
info.o: ../../include/ac/socket.h
info.o: /usr/include/machine/_param.h
info.o: /usr/include/sys/socket.h
info.o: /usr/include/net/net_kev.h
info.o: /usr/include/i386/_param.h
info.o: /usr/include/sys/_types/_sa_family_t.h
info.o: /usr/include/sys/_types/_socklen_t.h
info.o: /usr/include/sys/un.h
info.o: /usr/include/sys/_types/_iovec_t.h
info.o: /usr/include/sys/_types/_timespec.h
info.o: /usr/include/sys/select.h
info.o: /usr/include/netinet/in.h
info.o: /usr/include/sys/_select.h
info.o: /usr/include/netinet/tcp.h
info.o: /usr/include/netinet6/in6.h
info.o: /usr/include/arpa/nameser.h
info.o: /usr/include/arpa/inet.h
info.o: /usr/include/machine/param.h
info.o: /usr/include/sys/param.h
info.o: /usr/include/netdb.h
info.o: /usr/include/resolv.h
info.o: /usr/include/i386/param.h
info.o: /usr/include/sys/_types/_va_list.h
info.o: /usr/include/stdio.h
info.o: /usr/include/secure/_stdio.h
info.o: /usr/include/sys/stdio.h
info.o: /usr/include/unistd.h
info.o: ../../include/ac/unistd.h
info.o: /usr/include/sys/_types/_posix_vdisable.h
info.o: /usr/include/sys/unistd.h
info.o: /usr/include/sys/_types/_uuid_t.h
info.o: /usr/include/sys/_types/_seek_set.h
info.o: /usr/include/getopt.h
info.o: /usr/include/gethostuuid.h
info.o: ../../include/ac/ctype.h
info.o: ../../include/lutil_lockf.h
info.o: /usr/include/runetype.h
info.o: /usr/include/ctype.h
info.o: ../../include/lber.h
info.o: /usr/include/sys/_types/_wint_t.h
info.o: ../../include/ldap.h
info.o: ../../include/lber_types.h
info.o: ../../include/lutil.h
info.o: ../../include/avl.h
info.o: ../../include/ldap_log.h
info.o: ../../include/ldap_pvt_thread.h
info.o: ../../include/rewrite.h
info.o: /usr/include/pthread.h
info.o: ../../include/ldap_int_thread.h
info.o: /usr/include/pthread/sched.h
info.o: /usr/include/pthread/pthread_impl.h
info.o: /usr/include/pthread/qos.h
info.o: /usr/include/sys/qos.h
info.o: /usr/include/time.h
info.o: /usr/include/sys/_types/_mach_port_t.h
ldapmap.o: ../../include/portable.h
ldapmap.o: ldapmap.c
ldapmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
ldapmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
ldapmap.o: ../../include/ldap_cdefs.h
ldapmap.o: ../../include/ac/fdset.h
ldapmap.o: ../../include/ac/assert.h
ldapmap.o: ../../include/ldap_features.h
ldapmap.o: /usr/include/sys/cdefs.h
ldapmap.o: /usr/include/assert.h
ldapmap.o: /usr/include/sys/_symbol_aliasing.h
ldapmap.o: ../../include/ac/localize.h
ldapmap.o: /usr/include/sys/_posix_availability.h
ldapmap.o: ../../include/ac/stdlib.h
ldapmap.o: /usr/include/stdlib.h
ldapmap.o: rewrite-int.h
ldapmap.o: /usr/include/AvailabilityInternal.h
ldapmap.o: /usr/include/Availability.h
ldapmap.o: /usr/include/sys/_types.h
ldapmap.o: /usr/include/_types.h
ldapmap.o: /usr/include/i386/_types.h
ldapmap.o: /usr/include/machine/_types.h
ldapmap.o: /usr/include/sys/wait.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_types.h
ldapmap.o: /usr/include/sys/_types/_id_t.h
ldapmap.o: /usr/include/sys/_types/_pid_t.h
ldapmap.o: /usr/include/sys/appleapiopts.h
ldapmap.o: /usr/include/sys/signal.h
ldapmap.o: /usr/include/i386/signal.h
ldapmap.o: /usr/include/machine/signal.h
ldapmap.o: /usr/include/i386/_mcontext.h
ldapmap.o: /usr/include/machine/_mcontext.h
ldapmap.o: /usr/include/mach/i386/_structs.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_attr_t.h
ldapmap.o: /usr/include/sys/_types/_sigaltstack.h
ldapmap.o: /usr/include/sys/_types/_ucontext.h
ldapmap.o: /usr/include/sys/_types/_size_t.h
ldapmap.o: /usr/include/sys/_types/_sigset_t.h
ldapmap.o: /usr/include/sys/resource.h
ldapmap.o: /usr/include/sys/_types/_uid_t.h
ldapmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
ldapmap.o: /usr/include/sys/_types/_int8_t.h
ldapmap.o: /usr/include/stdint.h
ldapmap.o: /usr/include/sys/_types/_int32_t.h
ldapmap.o: /usr/include/sys/_types/_int16_t.h
ldapmap.o: /usr/include/_types/_uint8_t.h
ldapmap.o: /usr/include/sys/_types/_int64_t.h
ldapmap.o: /usr/include/_types/_uint32_t.h
ldapmap.o: /usr/include/_types/_uint16_t.h
ldapmap.o: /usr/include/sys/_types/_intptr_t.h
ldapmap.o: /usr/include/_types/_uint64_t.h
ldapmap.o: /usr/include/_types/_intmax_t.h
ldapmap.o: /usr/include/sys/_types/_uintptr_t.h
ldapmap.o: /usr/include/sys/_types/_timeval.h
ldapmap.o: /usr/include/_types/_uintmax_t.h
ldapmap.o: /usr/include/i386/endian.h
ldapmap.o: /usr/include/machine/endian.h
ldapmap.o: /usr/include/libkern/_OSByteOrder.h
ldapmap.o: /usr/include/sys/_endian.h
ldapmap.o: /usr/include/alloca.h
ldapmap.o: /usr/include/libkern/i386/_OSByteOrder.h
ldapmap.o: /usr/include/sys/_types/_rune_t.h
ldapmap.o: /usr/include/sys/_types/_ct_rune_t.h
ldapmap.o: /usr/include/sys/_types/_null.h
ldapmap.o: /usr/include/sys/_types/_wchar_t.h
ldapmap.o: /usr/include/i386/types.h
ldapmap.o: /usr/include/machine/types.h
ldapmap.o: /usr/include/sys/_types/_u_int8_t.h
ldapmap.o: /usr/include/sys/_types/_u_int16_t.h
ldapmap.o: /usr/include/sys/_types/_u_int32_t.h
ldapmap.o: /usr/include/sys/_types/_dev_t.h
ldapmap.o: /usr/include/sys/_types/_u_int64_t.h
ldapmap.o: /usr/include/sys/_types/_mode_t.h
ldapmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
ldapmap.o: /usr/include/machine/limits.h
ldapmap.o: /usr/include/limits.h
ldapmap.o: /usr/include/i386/_limits.h
ldapmap.o: /usr/include/i386/limits.h
ldapmap.o: ../../include/ac/string.h
ldapmap.o: /usr/include/sys/syslimits.h
ldapmap.o: /usr/include/sys/_types/_rsize_t.h
ldapmap.o: /usr/include/string.h
ldapmap.o: /usr/include/sys/_types/_ssize_t.h
ldapmap.o: /usr/include/sys/_types/_errno_t.h
ldapmap.o: /usr/include/secure/_string.h
ldapmap.o: /usr/include/strings.h
ldapmap.o: ../../include/ac/syslog.h
ldapmap.o: /usr/include/secure/_common.h
ldapmap.o: /usr/include/sys/syslog.h
ldapmap.o: /usr/include/syslog.h
ldapmap.o: /usr/include/sys/types.h
ldapmap.o: ../../include/ac/regex.h
ldapmap.o: /usr/include/sys/_types/_blkcnt_t.h
ldapmap.o: /usr/include/sys/_types/_gid_t.h
ldapmap.o: /usr/include/sys/_types/_blksize_t.h
ldapmap.o: /usr/include/sys/_types/_in_addr_t.h
ldapmap.o: /usr/include/sys/_types/_ino_t.h
ldapmap.o: /usr/include/sys/_types/_in_port_t.h
ldapmap.o: /usr/include/sys/_types/_key_t.h
ldapmap.o: /usr/include/sys/_types/_ino64_t.h
ldapmap.o: /usr/include/sys/_types/_off_t.h
ldapmap.o: /usr/include/sys/_types/_nlink_t.h
ldapmap.o: /usr/include/sys/_types/_time_t.h
ldapmap.o: /usr/include/sys/_types/_clock_t.h
ldapmap.o: /usr/include/sys/_types/_useconds_t.h
ldapmap.o: /usr/include/sys/_types/_suseconds_t.h
ldapmap.o: /usr/include/sys/_types/_fd_def.h
ldapmap.o: /usr/include/sys/_types/_fd_setsize.h
ldapmap.o: /usr/include/sys/_types/_fd_clr.h
ldapmap.o: /usr/include/sys/_types/_fd_set.h
ldapmap.o: /usr/include/sys/_types/_fd_isset.h
ldapmap.o: /usr/include/sys/_types/_fd_zero.h
ldapmap.o: /usr/include/sys/_types/_fd_copy.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_cond_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_once_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_t.h
ldapmap.o: /usr/include/sys/_pthread/_pthread_key_t.h
ldapmap.o: /usr/include/sys/_types/_fsblkcnt_t.h
ldapmap.o: /usr/include/regex.h
ldapmap.o: /usr/include/sys/_types/_fsfilcnt_t.h
ldapmap.o: /usr/include/poll.h
ldapmap.o: /usr/include/sys/poll.h
ldapmap.o: ../../include/ac/socket.h
ldapmap.o: /usr/include/machine/_param.h
ldapmap.o: /usr/include/sys/socket.h
ldapmap.o: /usr/include/net/net_kev.h
ldapmap.o: /usr/include/i386/_param.h
ldapmap.o: /usr/include/sys/_types/_sa_family_t.h
ldapmap.o: /usr/include/sys/_types/_socklen_t.h
ldapmap.o: /usr/include/sys/un.h
ldapmap.o: /usr/include/sys/_types/_iovec_t.h
ldapmap.o: /usr/include/sys/_types/_timespec.h
ldapmap.o: /usr/include/sys/select.h
ldapmap.o: /usr/include/netinet/in.h
ldapmap.o: /usr/include/sys/_select.h
ldapmap.o: /usr/include/netinet/tcp.h
ldapmap.o: /usr/include/netinet6/in6.h
ldapmap.o: /usr/include/arpa/nameser.h
ldapmap.o: /usr/include/arpa/inet.h
ldapmap.o: /usr/include/machine/param.h
ldapmap.o: /usr/include/sys/param.h
ldapmap.o: /usr/include/netdb.h
ldapmap.o: /usr/include/resolv.h
ldapmap.o: /usr/include/i386/param.h
ldapmap.o: /usr/include/sys/_types/_va_list.h
ldapmap.o: /usr/include/stdio.h
ldapmap.o: /usr/include/secure/_stdio.h
ldapmap.o: /usr/include/sys/stdio.h
ldapmap.o: /usr/include/unistd.h
ldapmap.o: ../../include/ac/unistd.h
ldapmap.o: /usr/include/sys/_types/_posix_vdisable.h
ldapmap.o: /usr/include/sys/unistd.h
ldapmap.o: /usr/include/sys/_types/_uuid_t.h
ldapmap.o: /usr/include/sys/_types/_seek_set.h
ldapmap.o: /usr/include/getopt.h
ldapmap.o: /usr/include/gethostuuid.h
ldapmap.o: ../../include/ac/ctype.h
ldapmap.o: ../../include/lutil_lockf.h
ldapmap.o: /usr/include/runetype.h
ldapmap.o: /usr/include/ctype.h
ldapmap.o: ../../include/lber.h
ldapmap.o: /usr/include/sys/_types/_wint_t.h
ldapmap.o: ../../include/ldap.h
ldapmap.o: ../../include/lber_types.h
ldapmap.o: ../../include/lutil.h
ldapmap.o: ../../include/avl.h
ldapmap.o: ../../include/ldap_log.h
ldapmap.o: ../../include/ldap_pvt_thread.h
ldapmap.o: ../../include/rewrite.h
ldapmap.o: /usr/include/pthread.h
ldapmap.o: ../../include/ldap_int_thread.h
ldapmap.o: /usr/include/pthread/sched.h
ldapmap.o: /usr/include/pthread/pthread_impl.h
ldapmap.o: /usr/include/pthread/qos.h
ldapmap.o: /usr/include/sys/qos.h
ldapmap.o: /usr/include/time.h
ldapmap.o: rewrite-map.h
ldapmap.o: /usr/include/sys/_types/_mach_port_t.h
map.o: ../../include/portable.h
map.o: map.c
map.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
map.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
map.o: ../../include/ldap_cdefs.h
map.o: ../../include/ac/fdset.h
map.o: ../../include/ac/assert.h
map.o: ../../include/ldap_features.h
map.o: /usr/include/sys/cdefs.h
map.o: /usr/include/assert.h
map.o: /usr/include/sys/_symbol_aliasing.h
map.o: ../../include/ac/localize.h
map.o: /usr/include/sys/_posix_availability.h
map.o: /usr/include/Availability.h
map.o: /usr/include/stdio.h
map.o: /usr/include/_types.h
map.o: /usr/include/AvailabilityInternal.h
map.o: /usr/include/machine/_types.h
map.o: /usr/include/sys/_types.h
map.o: /usr/include/sys/_pthread/_pthread_types.h
map.o: /usr/include/i386/_types.h
map.o: /usr/include/sys/_types/_size_t.h
map.o: /usr/include/sys/_types/_va_list.h
map.o: /usr/include/sys/stdio.h
map.o: /usr/include/sys/_types/_null.h
map.o: /usr/include/sys/_types/_ssize_t.h
map.o: /usr/include/sys/_types/_off_t.h
map.o: /usr/include/secure/_common.h
map.o: /usr/include/secure/_stdio.h
map.o: /usr/include/sys/_types/_gid_t.h
map.o: /usr/include/pwd.h
map.o: /usr/include/uuid/uuid.h
map.o: /usr/include/sys/_types/_uid_t.h
map.o: rewrite-int.h
map.o: /usr/include/sys/_types/_uuid_t.h
map.o: /usr/include/stdlib.h
map.o: ../../include/ac/stdlib.h
map.o: /usr/include/sys/_types/_pid_t.h
map.o: /usr/include/sys/wait.h
map.o: /usr/include/sys/signal.h
map.o: /usr/include/sys/_types/_id_t.h
map.o: /usr/include/machine/signal.h
map.o: /usr/include/sys/appleapiopts.h
map.o: /usr/include/machine/_mcontext.h
map.o: /usr/include/i386/signal.h
map.o: /usr/include/mach/i386/_structs.h
map.o: /usr/include/i386/_mcontext.h
map.o: /usr/include/sys/_pthread/_pthread_attr_t.h
map.o: /usr/include/sys/_types/_sigaltstack.h
map.o: /usr/include/sys/_types/_ucontext.h
map.o: /usr/include/sys/resource.h
map.o: /usr/include/sys/_types/_sigset_t.h
map.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
map.o: /usr/include/sys/_types/_int8_t.h
map.o: /usr/include/stdint.h
map.o: /usr/include/sys/_types/_int32_t.h
map.o: /usr/include/sys/_types/_int16_t.h
map.o: /usr/include/_types/_uint8_t.h
map.o: /usr/include/sys/_types/_int64_t.h
map.o: /usr/include/_types/_uint32_t.h
map.o: /usr/include/_types/_uint16_t.h
map.o: /usr/include/sys/_types/_intptr_t.h
map.o: /usr/include/_types/_uint64_t.h
map.o: /usr/include/_types/_intmax_t.h
map.o: /usr/include/sys/_types/_uintptr_t.h
map.o: /usr/include/sys/_types/_timeval.h
map.o: /usr/include/_types/_uintmax_t.h
map.o: /usr/include/i386/endian.h
map.o: /usr/include/machine/endian.h
map.o: /usr/include/libkern/_OSByteOrder.h
map.o: /usr/include/sys/_endian.h
map.o: /usr/include/alloca.h
map.o: /usr/include/libkern/i386/_OSByteOrder.h
map.o: /usr/include/sys/_types/_rune_t.h
map.o: /usr/include/sys/_types/_ct_rune_t.h
map.o: /usr/include/machine/types.h
map.o: /usr/include/sys/_types/_wchar_t.h
map.o: /usr/include/sys/_types/_u_int8_t.h
map.o: /usr/include/i386/types.h
map.o: /usr/include/sys/_types/_u_int16_t.h
map.o: /usr/include/sys/_types/_u_int32_t.h
map.o: /usr/include/sys/_types/_dev_t.h
map.o: /usr/include/sys/_types/_u_int64_t.h
map.o: /usr/include/sys/_types/_mode_t.h
map.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
map.o: /usr/include/machine/limits.h
map.o: /usr/include/limits.h
map.o: /usr/include/i386/_limits.h
map.o: /usr/include/i386/limits.h
map.o: ../../include/ac/string.h
map.o: /usr/include/sys/syslimits.h
map.o: /usr/include/sys/_types/_rsize_t.h
map.o: /usr/include/string.h
map.o: /usr/include/strings.h
map.o: /usr/include/sys/_types/_errno_t.h
map.o: ../../include/ac/syslog.h
map.o: /usr/include/secure/_string.h
map.o: /usr/include/sys/syslog.h
map.o: /usr/include/syslog.h
map.o: /usr/include/sys/types.h
map.o: ../../include/ac/regex.h
map.o: /usr/include/sys/_types/_blkcnt_t.h
map.o: /usr/include/sys/_types/_blksize_t.h
map.o: /usr/include/sys/_types/_in_addr_t.h
map.o: /usr/include/sys/_types/_ino_t.h
map.o: /usr/include/sys/_types/_in_port_t.h
map.o: /usr/include/sys/_types/_key_t.h
map.o: /usr/include/sys/_types/_ino64_t.h
map.o: /usr/include/sys/_types/_clock_t.h
map.o: /usr/include/sys/_types/_nlink_t.h
map.o: /usr/include/sys/_types/_time_t.h
map.o: /usr/include/sys/_types/_useconds_t.h
map.o: /usr/include/sys/_types/_suseconds_t.h
map.o: /usr/include/sys/_types/_fd_def.h
map.o: /usr/include/sys/_types/_fd_setsize.h
map.o: /usr/include/sys/_types/_fd_clr.h
map.o: /usr/include/sys/_types/_fd_set.h
map.o: /usr/include/sys/_types/_fd_isset.h
map.o: /usr/include/sys/_types/_fd_zero.h
map.o: /usr/include/sys/_types/_fd_copy.h
map.o: /usr/include/sys/_pthread/_pthread_cond_t.h
map.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
map.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
map.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
map.o: /usr/include/sys/_pthread/_pthread_once_t.h
map.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
map.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
map.o: /usr/include/sys/_pthread/_pthread_t.h
map.o: /usr/include/sys/_pthread/_pthread_key_t.h
map.o: /usr/include/sys/_types/_fsblkcnt_t.h
map.o: /usr/include/regex.h
map.o: /usr/include/sys/_types/_fsfilcnt_t.h
map.o: /usr/include/poll.h
map.o: /usr/include/sys/poll.h
map.o: ../../include/ac/socket.h
map.o: /usr/include/machine/_param.h
map.o: /usr/include/sys/socket.h
map.o: /usr/include/net/net_kev.h
map.o: /usr/include/i386/_param.h
map.o: /usr/include/sys/_types/_sa_family_t.h
map.o: /usr/include/sys/_types/_socklen_t.h
map.o: /usr/include/sys/un.h
map.o: /usr/include/sys/_types/_iovec_t.h
map.o: /usr/include/sys/_types/_timespec.h
map.o: /usr/include/sys/select.h
map.o: /usr/include/netinet/in.h
map.o: /usr/include/sys/_select.h
map.o: /usr/include/netinet/tcp.h
map.o: /usr/include/netinet6/in6.h
map.o: /usr/include/arpa/nameser.h
map.o: /usr/include/arpa/inet.h
map.o: /usr/include/machine/param.h
map.o: /usr/include/sys/param.h
map.o: /usr/include/netdb.h
map.o: /usr/include/resolv.h
map.o: /usr/include/i386/param.h
map.o: /usr/include/unistd.h
map.o: ../../include/ac/unistd.h
map.o: /usr/include/sys/_types/_posix_vdisable.h
map.o: /usr/include/sys/unistd.h
map.o: /usr/include/gethostuuid.h
map.o: /usr/include/sys/_types/_seek_set.h
map.o: ../../include/lutil_lockf.h
map.o: /usr/include/getopt.h
map.o: /usr/include/ctype.h
map.o: /usr/include/runetype.h
map.o: ../../include/ac/ctype.h
map.o: ../../include/lber.h
map.o: /usr/include/sys/_types/_wint_t.h
map.o: ../../include/ldap.h
map.o: ../../include/lber_types.h
map.o: ../../include/lutil.h
map.o: ../../include/avl.h
map.o: ../../include/ldap_log.h
map.o: ../../include/ldap_pvt_thread.h
map.o: ../../include/rewrite.h
map.o: /usr/include/pthread.h
map.o: ../../include/ldap_int_thread.h
map.o: /usr/include/pthread/sched.h
map.o: /usr/include/pthread/pthread_impl.h
map.o: /usr/include/pthread/qos.h
map.o: /usr/include/sys/qos.h
map.o: /usr/include/time.h
map.o: rewrite-map.h
map.o: /usr/include/sys/_types/_mach_port_t.h
params.o: ../../include/portable.h
params.o: params.c
params.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
params.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
params.o: ../../include/ldap_cdefs.h
params.o: ../../include/ac/fdset.h
params.o: ../../include/ac/assert.h
params.o: ../../include/ldap_features.h
params.o: /usr/include/sys/cdefs.h
params.o: /usr/include/assert.h
params.o: /usr/include/sys/_symbol_aliasing.h
params.o: ../../include/ac/localize.h
params.o: /usr/include/sys/_posix_availability.h
params.o: ../../include/ac/stdlib.h
params.o: /usr/include/stdlib.h
params.o: rewrite-int.h
params.o: /usr/include/AvailabilityInternal.h
params.o: /usr/include/Availability.h
params.o: /usr/include/sys/_types.h
params.o: /usr/include/_types.h
params.o: /usr/include/i386/_types.h
params.o: /usr/include/machine/_types.h
params.o: /usr/include/sys/wait.h
params.o: /usr/include/sys/_pthread/_pthread_types.h
params.o: /usr/include/sys/_types/_id_t.h
params.o: /usr/include/sys/_types/_pid_t.h
params.o: /usr/include/sys/appleapiopts.h
params.o: /usr/include/sys/signal.h
params.o: /usr/include/i386/signal.h
params.o: /usr/include/machine/signal.h
params.o: /usr/include/i386/_mcontext.h
params.o: /usr/include/machine/_mcontext.h
params.o: /usr/include/mach/i386/_structs.h
params.o: /usr/include/sys/_pthread/_pthread_attr_t.h
params.o: /usr/include/sys/_types/_sigaltstack.h
params.o: /usr/include/sys/_types/_ucontext.h
params.o: /usr/include/sys/_types/_size_t.h
params.o: /usr/include/sys/_types/_sigset_t.h
params.o: /usr/include/sys/resource.h
params.o: /usr/include/sys/_types/_uid_t.h
params.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
params.o: /usr/include/sys/_types/_int8_t.h
params.o: /usr/include/stdint.h
params.o: /usr/include/sys/_types/_int32_t.h
params.o: /usr/include/sys/_types/_int16_t.h
params.o: /usr/include/_types/_uint8_t.h
params.o: /usr/include/sys/_types/_int64_t.h
params.o: /usr/include/_types/_uint32_t.h
params.o: /usr/include/_types/_uint16_t.h
params.o: /usr/include/sys/_types/_intptr_t.h
params.o: /usr/include/_types/_uint64_t.h
params.o: /usr/include/_types/_intmax_t.h
params.o: /usr/include/sys/_types/_uintptr_t.h
params.o: /usr/include/sys/_types/_timeval.h
params.o: /usr/include/_types/_uintmax_t.h
params.o: /usr/include/i386/endian.h
params.o: /usr/include/machine/endian.h
params.o: /usr/include/libkern/_OSByteOrder.h
params.o: /usr/include/sys/_endian.h
params.o: /usr/include/alloca.h
params.o: /usr/include/libkern/i386/_OSByteOrder.h
params.o: /usr/include/sys/_types/_rune_t.h
params.o: /usr/include/sys/_types/_ct_rune_t.h
params.o: /usr/include/sys/_types/_null.h
params.o: /usr/include/sys/_types/_wchar_t.h
params.o: /usr/include/i386/types.h
params.o: /usr/include/machine/types.h
params.o: /usr/include/sys/_types/_u_int8_t.h
params.o: /usr/include/sys/_types/_u_int16_t.h
params.o: /usr/include/sys/_types/_u_int32_t.h
params.o: /usr/include/sys/_types/_dev_t.h
params.o: /usr/include/sys/_types/_u_int64_t.h
params.o: /usr/include/sys/_types/_mode_t.h
params.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
params.o: /usr/include/machine/limits.h
params.o: /usr/include/limits.h
params.o: /usr/include/i386/_limits.h
params.o: /usr/include/i386/limits.h
params.o: ../../include/ac/string.h
params.o: /usr/include/sys/syslimits.h
params.o: /usr/include/sys/_types/_rsize_t.h
params.o: /usr/include/string.h
params.o: /usr/include/sys/_types/_ssize_t.h
params.o: /usr/include/sys/_types/_errno_t.h
params.o: /usr/include/secure/_string.h
params.o: /usr/include/strings.h
params.o: ../../include/ac/syslog.h
params.o: /usr/include/secure/_common.h
params.o: /usr/include/sys/syslog.h
params.o: /usr/include/syslog.h
params.o: /usr/include/sys/types.h
params.o: ../../include/ac/regex.h
params.o: /usr/include/sys/_types/_blkcnt_t.h
params.o: /usr/include/sys/_types/_gid_t.h
params.o: /usr/include/sys/_types/_blksize_t.h
params.o: /usr/include/sys/_types/_in_addr_t.h
params.o: /usr/include/sys/_types/_ino_t.h
params.o: /usr/include/sys/_types/_in_port_t.h
params.o: /usr/include/sys/_types/_key_t.h
params.o: /usr/include/sys/_types/_ino64_t.h
params.o: /usr/include/sys/_types/_off_t.h
params.o: /usr/include/sys/_types/_nlink_t.h
params.o: /usr/include/sys/_types/_time_t.h
params.o: /usr/include/sys/_types/_clock_t.h
params.o: /usr/include/sys/_types/_useconds_t.h
params.o: /usr/include/sys/_types/_suseconds_t.h
params.o: /usr/include/sys/_types/_fd_def.h
params.o: /usr/include/sys/_types/_fd_setsize.h
params.o: /usr/include/sys/_types/_fd_clr.h
params.o: /usr/include/sys/_types/_fd_set.h
params.o: /usr/include/sys/_types/_fd_isset.h
params.o: /usr/include/sys/_types/_fd_zero.h
params.o: /usr/include/sys/_types/_fd_copy.h
params.o: /usr/include/sys/_pthread/_pthread_cond_t.h
params.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
params.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
params.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
params.o: /usr/include/sys/_pthread/_pthread_once_t.h
params.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
params.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
params.o: /usr/include/sys/_pthread/_pthread_t.h
params.o: /usr/include/sys/_pthread/_pthread_key_t.h
params.o: /usr/include/sys/_types/_fsblkcnt_t.h
params.o: /usr/include/regex.h
params.o: /usr/include/sys/_types/_fsfilcnt_t.h
params.o: /usr/include/poll.h
params.o: /usr/include/sys/poll.h
params.o: ../../include/ac/socket.h
params.o: /usr/include/machine/_param.h
params.o: /usr/include/sys/socket.h
params.o: /usr/include/net/net_kev.h
params.o: /usr/include/i386/_param.h
params.o: /usr/include/sys/_types/_sa_family_t.h
params.o: /usr/include/sys/_types/_socklen_t.h
params.o: /usr/include/sys/un.h
params.o: /usr/include/sys/_types/_iovec_t.h
params.o: /usr/include/sys/_types/_timespec.h
params.o: /usr/include/sys/select.h
params.o: /usr/include/netinet/in.h
params.o: /usr/include/sys/_select.h
params.o: /usr/include/netinet/tcp.h
params.o: /usr/include/netinet6/in6.h
params.o: /usr/include/arpa/nameser.h
params.o: /usr/include/arpa/inet.h
params.o: /usr/include/machine/param.h
params.o: /usr/include/sys/param.h
params.o: /usr/include/netdb.h
params.o: /usr/include/resolv.h
params.o: /usr/include/i386/param.h
params.o: /usr/include/sys/_types/_va_list.h
params.o: /usr/include/stdio.h
params.o: /usr/include/secure/_stdio.h
params.o: /usr/include/sys/stdio.h
params.o: /usr/include/unistd.h
params.o: ../../include/ac/unistd.h
params.o: /usr/include/sys/_types/_posix_vdisable.h
params.o: /usr/include/sys/unistd.h
params.o: /usr/include/sys/_types/_uuid_t.h
params.o: /usr/include/sys/_types/_seek_set.h
params.o: /usr/include/getopt.h
params.o: /usr/include/gethostuuid.h
params.o: ../../include/ac/ctype.h
params.o: ../../include/lutil_lockf.h
params.o: /usr/include/runetype.h
params.o: /usr/include/ctype.h
params.o: ../../include/lber.h
params.o: /usr/include/sys/_types/_wint_t.h
params.o: ../../include/ldap.h
params.o: ../../include/lber_types.h
params.o: ../../include/lutil.h
params.o: ../../include/avl.h
params.o: ../../include/ldap_log.h
params.o: ../../include/ldap_pvt_thread.h
params.o: ../../include/rewrite.h
params.o: /usr/include/pthread.h
params.o: ../../include/ldap_int_thread.h
params.o: /usr/include/pthread/sched.h
params.o: /usr/include/pthread/pthread_impl.h
params.o: /usr/include/pthread/qos.h
params.o: /usr/include/sys/qos.h
params.o: /usr/include/time.h
params.o: /usr/include/sys/_types/_mach_port_t.h
rule.o: ../../include/portable.h
rule.o: rule.c
rule.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
rule.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
rule.o: ../../include/ldap_cdefs.h
rule.o: ../../include/ac/fdset.h
rule.o: ../../include/ac/assert.h
rule.o: ../../include/ldap_features.h
rule.o: /usr/include/sys/cdefs.h
rule.o: /usr/include/assert.h
rule.o: /usr/include/sys/_symbol_aliasing.h
rule.o: ../../include/ac/localize.h
rule.o: /usr/include/sys/_posix_availability.h
rule.o: ../../include/ac/stdlib.h
rule.o: /usr/include/stdlib.h
rule.o: rewrite-int.h
rule.o: /usr/include/AvailabilityInternal.h
rule.o: /usr/include/Availability.h
rule.o: /usr/include/sys/_types.h
rule.o: /usr/include/_types.h
rule.o: /usr/include/i386/_types.h
rule.o: /usr/include/machine/_types.h
rule.o: /usr/include/sys/wait.h
rule.o: /usr/include/sys/_pthread/_pthread_types.h
rule.o: /usr/include/sys/_types/_id_t.h
rule.o: /usr/include/sys/_types/_pid_t.h
rule.o: /usr/include/sys/appleapiopts.h
rule.o: /usr/include/sys/signal.h
rule.o: /usr/include/i386/signal.h
rule.o: /usr/include/machine/signal.h
rule.o: /usr/include/i386/_mcontext.h
rule.o: /usr/include/machine/_mcontext.h
rule.o: /usr/include/mach/i386/_structs.h
rule.o: /usr/include/sys/_pthread/_pthread_attr_t.h
rule.o: /usr/include/sys/_types/_sigaltstack.h
rule.o: /usr/include/sys/_types/_ucontext.h
rule.o: /usr/include/sys/_types/_size_t.h
rule.o: /usr/include/sys/_types/_sigset_t.h
rule.o: /usr/include/sys/resource.h
rule.o: /usr/include/sys/_types/_uid_t.h
rule.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
rule.o: /usr/include/sys/_types/_int8_t.h
rule.o: /usr/include/stdint.h
rule.o: /usr/include/sys/_types/_int32_t.h
rule.o: /usr/include/sys/_types/_int16_t.h
rule.o: /usr/include/_types/_uint8_t.h
rule.o: /usr/include/sys/_types/_int64_t.h
rule.o: /usr/include/_types/_uint32_t.h
rule.o: /usr/include/_types/_uint16_t.h
rule.o: /usr/include/sys/_types/_intptr_t.h
rule.o: /usr/include/_types/_uint64_t.h
rule.o: /usr/include/_types/_intmax_t.h
rule.o: /usr/include/sys/_types/_uintptr_t.h
rule.o: /usr/include/sys/_types/_timeval.h
rule.o: /usr/include/_types/_uintmax_t.h
rule.o: /usr/include/i386/endian.h
rule.o: /usr/include/machine/endian.h
rule.o: /usr/include/libkern/_OSByteOrder.h
rule.o: /usr/include/sys/_endian.h
rule.o: /usr/include/alloca.h
rule.o: /usr/include/libkern/i386/_OSByteOrder.h
rule.o: /usr/include/sys/_types/_rune_t.h
rule.o: /usr/include/sys/_types/_ct_rune_t.h
rule.o: /usr/include/sys/_types/_null.h
rule.o: /usr/include/sys/_types/_wchar_t.h
rule.o: /usr/include/i386/types.h
rule.o: /usr/include/machine/types.h
rule.o: /usr/include/sys/_types/_u_int8_t.h
rule.o: /usr/include/sys/_types/_u_int16_t.h
rule.o: /usr/include/sys/_types/_u_int32_t.h
rule.o: /usr/include/sys/_types/_dev_t.h
rule.o: /usr/include/sys/_types/_u_int64_t.h
rule.o: /usr/include/sys/_types/_mode_t.h
rule.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
rule.o: /usr/include/machine/limits.h
rule.o: /usr/include/limits.h
rule.o: /usr/include/i386/_limits.h
rule.o: /usr/include/i386/limits.h
rule.o: ../../include/ac/string.h
rule.o: /usr/include/sys/syslimits.h
rule.o: /usr/include/sys/_types/_rsize_t.h
rule.o: /usr/include/string.h
rule.o: /usr/include/sys/_types/_ssize_t.h
rule.o: /usr/include/sys/_types/_errno_t.h
rule.o: /usr/include/secure/_string.h
rule.o: /usr/include/strings.h
rule.o: ../../include/ac/syslog.h
rule.o: /usr/include/secure/_common.h
rule.o: /usr/include/sys/syslog.h
rule.o: /usr/include/syslog.h
rule.o: /usr/include/sys/types.h
rule.o: ../../include/ac/regex.h
rule.o: /usr/include/sys/_types/_blkcnt_t.h
rule.o: /usr/include/sys/_types/_gid_t.h
rule.o: /usr/include/sys/_types/_blksize_t.h
rule.o: /usr/include/sys/_types/_in_addr_t.h
rule.o: /usr/include/sys/_types/_ino_t.h
rule.o: /usr/include/sys/_types/_in_port_t.h
rule.o: /usr/include/sys/_types/_key_t.h
rule.o: /usr/include/sys/_types/_ino64_t.h
rule.o: /usr/include/sys/_types/_off_t.h
rule.o: /usr/include/sys/_types/_nlink_t.h
rule.o: /usr/include/sys/_types/_time_t.h
rule.o: /usr/include/sys/_types/_clock_t.h
rule.o: /usr/include/sys/_types/_useconds_t.h
rule.o: /usr/include/sys/_types/_suseconds_t.h
rule.o: /usr/include/sys/_types/_fd_def.h
rule.o: /usr/include/sys/_types/_fd_setsize.h
rule.o: /usr/include/sys/_types/_fd_clr.h
rule.o: /usr/include/sys/_types/_fd_set.h
rule.o: /usr/include/sys/_types/_fd_isset.h
rule.o: /usr/include/sys/_types/_fd_zero.h
rule.o: /usr/include/sys/_types/_fd_copy.h
rule.o: /usr/include/sys/_pthread/_pthread_cond_t.h
rule.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
rule.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
rule.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
rule.o: /usr/include/sys/_pthread/_pthread_once_t.h
rule.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
rule.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
rule.o: /usr/include/sys/_pthread/_pthread_t.h
rule.o: /usr/include/sys/_pthread/_pthread_key_t.h
rule.o: /usr/include/sys/_types/_fsblkcnt_t.h
rule.o: /usr/include/regex.h
rule.o: /usr/include/sys/_types/_fsfilcnt_t.h
rule.o: /usr/include/poll.h
rule.o: /usr/include/sys/poll.h
rule.o: ../../include/ac/socket.h
rule.o: /usr/include/machine/_param.h
rule.o: /usr/include/sys/socket.h
rule.o: /usr/include/net/net_kev.h
rule.o: /usr/include/i386/_param.h
rule.o: /usr/include/sys/_types/_sa_family_t.h
rule.o: /usr/include/sys/_types/_socklen_t.h
rule.o: /usr/include/sys/un.h
rule.o: /usr/include/sys/_types/_iovec_t.h
rule.o: /usr/include/sys/_types/_timespec.h
rule.o: /usr/include/sys/select.h
rule.o: /usr/include/netinet/in.h
rule.o: /usr/include/sys/_select.h
rule.o: /usr/include/netinet/tcp.h
rule.o: /usr/include/netinet6/in6.h
rule.o: /usr/include/arpa/nameser.h
rule.o: /usr/include/arpa/inet.h
rule.o: /usr/include/machine/param.h
rule.o: /usr/include/sys/param.h
rule.o: /usr/include/netdb.h
rule.o: /usr/include/resolv.h
rule.o: /usr/include/i386/param.h
rule.o: /usr/include/sys/_types/_va_list.h
rule.o: /usr/include/stdio.h
rule.o: /usr/include/secure/_stdio.h
rule.o: /usr/include/sys/stdio.h
rule.o: /usr/include/unistd.h
rule.o: ../../include/ac/unistd.h
rule.o: /usr/include/sys/_types/_posix_vdisable.h
rule.o: /usr/include/sys/unistd.h
rule.o: /usr/include/sys/_types/_uuid_t.h
rule.o: /usr/include/sys/_types/_seek_set.h
rule.o: /usr/include/getopt.h
rule.o: /usr/include/gethostuuid.h
rule.o: ../../include/ac/ctype.h
rule.o: ../../include/lutil_lockf.h
rule.o: /usr/include/runetype.h
rule.o: /usr/include/ctype.h
rule.o: ../../include/lber.h
rule.o: /usr/include/sys/_types/_wint_t.h
rule.o: ../../include/ldap.h
rule.o: ../../include/lber_types.h
rule.o: ../../include/lutil.h
rule.o: ../../include/avl.h
rule.o: ../../include/ldap_log.h
rule.o: ../../include/ldap_pvt_thread.h
rule.o: ../../include/rewrite.h
rule.o: /usr/include/pthread.h
rule.o: ../../include/ldap_int_thread.h
rule.o: /usr/include/pthread/sched.h
rule.o: /usr/include/pthread/pthread_impl.h
rule.o: /usr/include/pthread/qos.h
rule.o: /usr/include/sys/qos.h
rule.o: /usr/include/time.h
rule.o: /usr/include/sys/_types/_mach_port_t.h
session.o: ../../include/portable.h
session.o: session.c
session.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
session.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
session.o: ../../include/ldap_cdefs.h
session.o: ../../include/ac/fdset.h
session.o: ../../include/ac/assert.h
session.o: ../../include/ldap_features.h
session.o: /usr/include/sys/cdefs.h
session.o: /usr/include/assert.h
session.o: /usr/include/sys/_symbol_aliasing.h
session.o: ../../include/ac/localize.h
session.o: /usr/include/sys/_posix_availability.h
session.o: ../../include/ac/stdlib.h
session.o: /usr/include/stdlib.h
session.o: rewrite-int.h
session.o: /usr/include/AvailabilityInternal.h
session.o: /usr/include/Availability.h
session.o: /usr/include/sys/_types.h
session.o: /usr/include/_types.h
session.o: /usr/include/i386/_types.h
session.o: /usr/include/machine/_types.h
session.o: /usr/include/sys/wait.h
session.o: /usr/include/sys/_pthread/_pthread_types.h
session.o: /usr/include/sys/_types/_id_t.h
session.o: /usr/include/sys/_types/_pid_t.h
session.o: /usr/include/sys/appleapiopts.h
session.o: /usr/include/sys/signal.h
session.o: /usr/include/i386/signal.h
session.o: /usr/include/machine/signal.h
session.o: /usr/include/i386/_mcontext.h
session.o: /usr/include/machine/_mcontext.h
session.o: /usr/include/mach/i386/_structs.h
session.o: /usr/include/sys/_pthread/_pthread_attr_t.h
session.o: /usr/include/sys/_types/_sigaltstack.h
session.o: /usr/include/sys/_types/_ucontext.h
session.o: /usr/include/sys/_types/_size_t.h
session.o: /usr/include/sys/_types/_sigset_t.h
session.o: /usr/include/sys/resource.h
session.o: /usr/include/sys/_types/_uid_t.h
session.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
session.o: /usr/include/sys/_types/_int8_t.h
session.o: /usr/include/stdint.h
session.o: /usr/include/sys/_types/_int32_t.h
session.o: /usr/include/sys/_types/_int16_t.h
session.o: /usr/include/_types/_uint8_t.h
session.o: /usr/include/sys/_types/_int64_t.h
session.o: /usr/include/_types/_uint32_t.h
session.o: /usr/include/_types/_uint16_t.h
session.o: /usr/include/sys/_types/_intptr_t.h
session.o: /usr/include/_types/_uint64_t.h
session.o: /usr/include/_types/_intmax_t.h
session.o: /usr/include/sys/_types/_uintptr_t.h
session.o: /usr/include/sys/_types/_timeval.h
session.o: /usr/include/_types/_uintmax_t.h
session.o: /usr/include/i386/endian.h
session.o: /usr/include/machine/endian.h
session.o: /usr/include/libkern/_OSByteOrder.h
session.o: /usr/include/sys/_endian.h
session.o: /usr/include/alloca.h
session.o: /usr/include/libkern/i386/_OSByteOrder.h
session.o: /usr/include/sys/_types/_rune_t.h
session.o: /usr/include/sys/_types/_ct_rune_t.h
session.o: /usr/include/sys/_types/_null.h
session.o: /usr/include/sys/_types/_wchar_t.h
session.o: /usr/include/i386/types.h
session.o: /usr/include/machine/types.h
session.o: /usr/include/sys/_types/_u_int8_t.h
session.o: /usr/include/sys/_types/_u_int16_t.h
session.o: /usr/include/sys/_types/_u_int32_t.h
session.o: /usr/include/sys/_types/_dev_t.h
session.o: /usr/include/sys/_types/_u_int64_t.h
session.o: /usr/include/sys/_types/_mode_t.h
session.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
session.o: /usr/include/machine/limits.h
session.o: /usr/include/limits.h
session.o: /usr/include/i386/_limits.h
session.o: /usr/include/i386/limits.h
session.o: ../../include/ac/string.h
session.o: /usr/include/sys/syslimits.h
session.o: /usr/include/sys/_types/_rsize_t.h
session.o: /usr/include/string.h
session.o: /usr/include/sys/_types/_ssize_t.h
session.o: /usr/include/sys/_types/_errno_t.h
session.o: /usr/include/secure/_string.h
session.o: /usr/include/strings.h
session.o: ../../include/ac/syslog.h
session.o: /usr/include/secure/_common.h
session.o: /usr/include/sys/syslog.h
session.o: /usr/include/syslog.h
session.o: /usr/include/sys/types.h
session.o: ../../include/ac/regex.h
session.o: /usr/include/sys/_types/_blkcnt_t.h
session.o: /usr/include/sys/_types/_gid_t.h
session.o: /usr/include/sys/_types/_blksize_t.h
session.o: /usr/include/sys/_types/_in_addr_t.h
session.o: /usr/include/sys/_types/_ino_t.h
session.o: /usr/include/sys/_types/_in_port_t.h
session.o: /usr/include/sys/_types/_key_t.h
session.o: /usr/include/sys/_types/_ino64_t.h
session.o: /usr/include/sys/_types/_off_t.h
session.o: /usr/include/sys/_types/_nlink_t.h
session.o: /usr/include/sys/_types/_time_t.h
session.o: /usr/include/sys/_types/_clock_t.h
session.o: /usr/include/sys/_types/_useconds_t.h
session.o: /usr/include/sys/_types/_suseconds_t.h
session.o: /usr/include/sys/_types/_fd_def.h
session.o: /usr/include/sys/_types/_fd_setsize.h
session.o: /usr/include/sys/_types/_fd_clr.h
session.o: /usr/include/sys/_types/_fd_set.h
session.o: /usr/include/sys/_types/_fd_isset.h
session.o: /usr/include/sys/_types/_fd_zero.h
session.o: /usr/include/sys/_types/_fd_copy.h
session.o: /usr/include/sys/_pthread/_pthread_cond_t.h
session.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
session.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
session.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
session.o: /usr/include/sys/_pthread/_pthread_once_t.h
session.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
session.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
session.o: /usr/include/sys/_pthread/_pthread_t.h
session.o: /usr/include/sys/_pthread/_pthread_key_t.h
session.o: /usr/include/sys/_types/_fsblkcnt_t.h
session.o: /usr/include/regex.h
session.o: /usr/include/sys/_types/_fsfilcnt_t.h
session.o: /usr/include/poll.h
session.o: /usr/include/sys/poll.h
session.o: ../../include/ac/socket.h
session.o: /usr/include/machine/_param.h
session.o: /usr/include/sys/socket.h
session.o: /usr/include/net/net_kev.h
session.o: /usr/include/i386/_param.h
session.o: /usr/include/sys/_types/_sa_family_t.h
session.o: /usr/include/sys/_types/_socklen_t.h
session.o: /usr/include/sys/un.h
session.o: /usr/include/sys/_types/_iovec_t.h
session.o: /usr/include/sys/_types/_timespec.h
session.o: /usr/include/sys/select.h
session.o: /usr/include/netinet/in.h
session.o: /usr/include/sys/_select.h
session.o: /usr/include/netinet/tcp.h
session.o: /usr/include/netinet6/in6.h
session.o: /usr/include/arpa/nameser.h
session.o: /usr/include/arpa/inet.h
session.o: /usr/include/machine/param.h
session.o: /usr/include/sys/param.h
session.o: /usr/include/netdb.h
session.o: /usr/include/resolv.h
session.o: /usr/include/i386/param.h
session.o: /usr/include/sys/_types/_va_list.h
session.o: /usr/include/stdio.h
session.o: /usr/include/secure/_stdio.h
session.o: /usr/include/sys/stdio.h
session.o: /usr/include/unistd.h
session.o: ../../include/ac/unistd.h
session.o: /usr/include/sys/_types/_posix_vdisable.h
session.o: /usr/include/sys/unistd.h
session.o: /usr/include/sys/_types/_uuid_t.h
session.o: /usr/include/sys/_types/_seek_set.h
session.o: /usr/include/getopt.h
session.o: /usr/include/gethostuuid.h
session.o: ../../include/ac/ctype.h
session.o: ../../include/lutil_lockf.h
session.o: /usr/include/runetype.h
session.o: /usr/include/ctype.h
session.o: ../../include/lber.h
session.o: /usr/include/sys/_types/_wint_t.h
session.o: ../../include/ldap.h
session.o: ../../include/lber_types.h
session.o: ../../include/lutil.h
session.o: ../../include/avl.h
session.o: ../../include/ldap_log.h
session.o: ../../include/ldap_pvt_thread.h
session.o: ../../include/rewrite.h
session.o: /usr/include/pthread.h
session.o: ../../include/ldap_int_thread.h
session.o: /usr/include/pthread/sched.h
session.o: /usr/include/pthread/pthread_impl.h
session.o: /usr/include/pthread/qos.h
session.o: /usr/include/sys/qos.h
session.o: /usr/include/time.h
session.o: /usr/include/sys/_types/_mach_port_t.h
subst.o: ../../include/portable.h
subst.o: subst.c
subst.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
subst.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
subst.o: ../../include/ldap_cdefs.h
subst.o: ../../include/ac/fdset.h
subst.o: ../../include/ac/assert.h
subst.o: ../../include/ldap_features.h
subst.o: /usr/include/sys/cdefs.h
subst.o: /usr/include/assert.h
subst.o: /usr/include/sys/_symbol_aliasing.h
subst.o: ../../include/ac/localize.h
subst.o: /usr/include/sys/_posix_availability.h
subst.o: ../../include/ac/stdlib.h
subst.o: /usr/include/stdlib.h
subst.o: rewrite-int.h
subst.o: /usr/include/AvailabilityInternal.h
subst.o: /usr/include/Availability.h
subst.o: /usr/include/sys/_types.h
subst.o: /usr/include/_types.h
subst.o: /usr/include/i386/_types.h
subst.o: /usr/include/machine/_types.h
subst.o: /usr/include/sys/wait.h
subst.o: /usr/include/sys/_pthread/_pthread_types.h
subst.o: /usr/include/sys/_types/_id_t.h
subst.o: /usr/include/sys/_types/_pid_t.h
subst.o: /usr/include/sys/appleapiopts.h
subst.o: /usr/include/sys/signal.h
subst.o: /usr/include/i386/signal.h
subst.o: /usr/include/machine/signal.h
subst.o: /usr/include/i386/_mcontext.h
subst.o: /usr/include/machine/_mcontext.h
subst.o: /usr/include/mach/i386/_structs.h
subst.o: /usr/include/sys/_pthread/_pthread_attr_t.h
subst.o: /usr/include/sys/_types/_sigaltstack.h
subst.o: /usr/include/sys/_types/_ucontext.h
subst.o: /usr/include/sys/_types/_size_t.h
subst.o: /usr/include/sys/_types/_sigset_t.h
subst.o: /usr/include/sys/resource.h
subst.o: /usr/include/sys/_types/_uid_t.h
subst.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
subst.o: /usr/include/sys/_types/_int8_t.h
subst.o: /usr/include/stdint.h
subst.o: /usr/include/sys/_types/_int32_t.h
subst.o: /usr/include/sys/_types/_int16_t.h
subst.o: /usr/include/_types/_uint8_t.h
subst.o: /usr/include/sys/_types/_int64_t.h
subst.o: /usr/include/_types/_uint32_t.h
subst.o: /usr/include/_types/_uint16_t.h
subst.o: /usr/include/sys/_types/_intptr_t.h
subst.o: /usr/include/_types/_uint64_t.h
subst.o: /usr/include/_types/_intmax_t.h
subst.o: /usr/include/sys/_types/_uintptr_t.h
subst.o: /usr/include/sys/_types/_timeval.h
subst.o: /usr/include/_types/_uintmax_t.h
subst.o: /usr/include/i386/endian.h
subst.o: /usr/include/machine/endian.h
subst.o: /usr/include/libkern/_OSByteOrder.h
subst.o: /usr/include/sys/_endian.h
subst.o: /usr/include/alloca.h
subst.o: /usr/include/libkern/i386/_OSByteOrder.h
subst.o: /usr/include/sys/_types/_rune_t.h
subst.o: /usr/include/sys/_types/_ct_rune_t.h
subst.o: /usr/include/sys/_types/_null.h
subst.o: /usr/include/sys/_types/_wchar_t.h
subst.o: /usr/include/i386/types.h
subst.o: /usr/include/machine/types.h
subst.o: /usr/include/sys/_types/_u_int8_t.h
subst.o: /usr/include/sys/_types/_u_int16_t.h
subst.o: /usr/include/sys/_types/_u_int32_t.h
subst.o: /usr/include/sys/_types/_dev_t.h
subst.o: /usr/include/sys/_types/_u_int64_t.h
subst.o: /usr/include/sys/_types/_mode_t.h
subst.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
subst.o: /usr/include/machine/limits.h
subst.o: /usr/include/limits.h
subst.o: /usr/include/i386/_limits.h
subst.o: /usr/include/i386/limits.h
subst.o: ../../include/ac/string.h
subst.o: /usr/include/sys/syslimits.h
subst.o: /usr/include/sys/_types/_rsize_t.h
subst.o: /usr/include/string.h
subst.o: /usr/include/sys/_types/_ssize_t.h
subst.o: /usr/include/sys/_types/_errno_t.h
subst.o: /usr/include/secure/_string.h
subst.o: /usr/include/strings.h
subst.o: ../../include/ac/syslog.h
subst.o: /usr/include/secure/_common.h
subst.o: /usr/include/sys/syslog.h
subst.o: /usr/include/syslog.h
subst.o: /usr/include/sys/types.h
subst.o: ../../include/ac/regex.h
subst.o: /usr/include/sys/_types/_blkcnt_t.h
subst.o: /usr/include/sys/_types/_gid_t.h
subst.o: /usr/include/sys/_types/_blksize_t.h
subst.o: /usr/include/sys/_types/_in_addr_t.h
subst.o: /usr/include/sys/_types/_ino_t.h
subst.o: /usr/include/sys/_types/_in_port_t.h
subst.o: /usr/include/sys/_types/_key_t.h
subst.o: /usr/include/sys/_types/_ino64_t.h
subst.o: /usr/include/sys/_types/_off_t.h
subst.o: /usr/include/sys/_types/_nlink_t.h
subst.o: /usr/include/sys/_types/_time_t.h
subst.o: /usr/include/sys/_types/_clock_t.h
subst.o: /usr/include/sys/_types/_useconds_t.h
subst.o: /usr/include/sys/_types/_suseconds_t.h
subst.o: /usr/include/sys/_types/_fd_def.h
subst.o: /usr/include/sys/_types/_fd_setsize.h
subst.o: /usr/include/sys/_types/_fd_clr.h
subst.o: /usr/include/sys/_types/_fd_set.h
subst.o: /usr/include/sys/_types/_fd_isset.h
subst.o: /usr/include/sys/_types/_fd_zero.h
subst.o: /usr/include/sys/_types/_fd_copy.h
subst.o: /usr/include/sys/_pthread/_pthread_cond_t.h
subst.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
subst.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
subst.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
subst.o: /usr/include/sys/_pthread/_pthread_once_t.h
subst.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
subst.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
subst.o: /usr/include/sys/_pthread/_pthread_t.h
subst.o: /usr/include/sys/_pthread/_pthread_key_t.h
subst.o: /usr/include/sys/_types/_fsblkcnt_t.h
subst.o: /usr/include/regex.h
subst.o: /usr/include/sys/_types/_fsfilcnt_t.h
subst.o: /usr/include/poll.h
subst.o: /usr/include/sys/poll.h
subst.o: ../../include/ac/socket.h
subst.o: /usr/include/machine/_param.h
subst.o: /usr/include/sys/socket.h
subst.o: /usr/include/net/net_kev.h
subst.o: /usr/include/i386/_param.h
subst.o: /usr/include/sys/_types/_sa_family_t.h
subst.o: /usr/include/sys/_types/_socklen_t.h
subst.o: /usr/include/sys/un.h
subst.o: /usr/include/sys/_types/_iovec_t.h
subst.o: /usr/include/sys/_types/_timespec.h
subst.o: /usr/include/sys/select.h
subst.o: /usr/include/netinet/in.h
subst.o: /usr/include/sys/_select.h
subst.o: /usr/include/netinet/tcp.h
subst.o: /usr/include/netinet6/in6.h
subst.o: /usr/include/arpa/nameser.h
subst.o: /usr/include/arpa/inet.h
subst.o: /usr/include/machine/param.h
subst.o: /usr/include/sys/param.h
subst.o: /usr/include/netdb.h
subst.o: /usr/include/resolv.h
subst.o: /usr/include/i386/param.h
subst.o: /usr/include/sys/_types/_va_list.h
subst.o: /usr/include/stdio.h
subst.o: /usr/include/secure/_stdio.h
subst.o: /usr/include/sys/stdio.h
subst.o: /usr/include/unistd.h
subst.o: ../../include/ac/unistd.h
subst.o: /usr/include/sys/_types/_posix_vdisable.h
subst.o: /usr/include/sys/unistd.h
subst.o: /usr/include/sys/_types/_uuid_t.h
subst.o: /usr/include/sys/_types/_seek_set.h
subst.o: /usr/include/getopt.h
subst.o: /usr/include/gethostuuid.h
subst.o: ../../include/ac/ctype.h
subst.o: ../../include/lutil_lockf.h
subst.o: /usr/include/runetype.h
subst.o: /usr/include/ctype.h
subst.o: ../../include/lber.h
subst.o: /usr/include/sys/_types/_wint_t.h
subst.o: ../../include/ldap.h
subst.o: ../../include/lber_types.h
subst.o: ../../include/lutil.h
subst.o: ../../include/avl.h
subst.o: ../../include/ldap_log.h
subst.o: ../../include/ldap_pvt_thread.h
subst.o: ../../include/rewrite.h
subst.o: /usr/include/pthread.h
subst.o: ../../include/ldap_int_thread.h
subst.o: /usr/include/pthread/sched.h
subst.o: /usr/include/pthread/pthread_impl.h
subst.o: /usr/include/pthread/qos.h
subst.o: /usr/include/sys/qos.h
subst.o: /usr/include/time.h
subst.o: /usr/include/sys/_types/_mach_port_t.h
var.o: ../../include/portable.h
var.o: var.c
var.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
var.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
var.o: ../../include/ldap_cdefs.h
var.o: ../../include/ac/fdset.h
var.o: ../../include/ac/assert.h
var.o: ../../include/ldap_features.h
var.o: /usr/include/sys/cdefs.h
var.o: /usr/include/assert.h
var.o: /usr/include/sys/_symbol_aliasing.h
var.o: ../../include/ac/localize.h
var.o: /usr/include/sys/_posix_availability.h
var.o: ../../include/ac/stdlib.h
var.o: /usr/include/stdlib.h
var.o: rewrite-int.h
var.o: /usr/include/AvailabilityInternal.h
var.o: /usr/include/Availability.h
var.o: /usr/include/sys/_types.h
var.o: /usr/include/_types.h
var.o: /usr/include/i386/_types.h
var.o: /usr/include/machine/_types.h
var.o: /usr/include/sys/wait.h
var.o: /usr/include/sys/_pthread/_pthread_types.h
var.o: /usr/include/sys/_types/_id_t.h
var.o: /usr/include/sys/_types/_pid_t.h
var.o: /usr/include/sys/appleapiopts.h
var.o: /usr/include/sys/signal.h
var.o: /usr/include/i386/signal.h
var.o: /usr/include/machine/signal.h
var.o: /usr/include/i386/_mcontext.h
var.o: /usr/include/machine/_mcontext.h
var.o: /usr/include/mach/i386/_structs.h
var.o: /usr/include/sys/_pthread/_pthread_attr_t.h
var.o: /usr/include/sys/_types/_sigaltstack.h
var.o: /usr/include/sys/_types/_ucontext.h
var.o: /usr/include/sys/_types/_size_t.h
var.o: /usr/include/sys/_types/_sigset_t.h
var.o: /usr/include/sys/resource.h
var.o: /usr/include/sys/_types/_uid_t.h
var.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
var.o: /usr/include/sys/_types/_int8_t.h
var.o: /usr/include/stdint.h
var.o: /usr/include/sys/_types/_int32_t.h
var.o: /usr/include/sys/_types/_int16_t.h
var.o: /usr/include/_types/_uint8_t.h
var.o: /usr/include/sys/_types/_int64_t.h
var.o: /usr/include/_types/_uint32_t.h
var.o: /usr/include/_types/_uint16_t.h
var.o: /usr/include/sys/_types/_intptr_t.h
var.o: /usr/include/_types/_uint64_t.h
var.o: /usr/include/_types/_intmax_t.h
var.o: /usr/include/sys/_types/_uintptr_t.h
var.o: /usr/include/sys/_types/_timeval.h
var.o: /usr/include/_types/_uintmax_t.h
var.o: /usr/include/i386/endian.h
var.o: /usr/include/machine/endian.h
var.o: /usr/include/libkern/_OSByteOrder.h
var.o: /usr/include/sys/_endian.h
var.o: /usr/include/alloca.h
var.o: /usr/include/libkern/i386/_OSByteOrder.h
var.o: /usr/include/sys/_types/_rune_t.h
var.o: /usr/include/sys/_types/_ct_rune_t.h
var.o: /usr/include/sys/_types/_null.h
var.o: /usr/include/sys/_types/_wchar_t.h
var.o: /usr/include/i386/types.h
var.o: /usr/include/machine/types.h
var.o: /usr/include/sys/_types/_u_int8_t.h
var.o: /usr/include/sys/_types/_u_int16_t.h
var.o: /usr/include/sys/_types/_u_int32_t.h
var.o: /usr/include/sys/_types/_dev_t.h
var.o: /usr/include/sys/_types/_u_int64_t.h
var.o: /usr/include/sys/_types/_mode_t.h
var.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
var.o: /usr/include/machine/limits.h
var.o: /usr/include/limits.h
var.o: /usr/include/i386/_limits.h
var.o: /usr/include/i386/limits.h
var.o: ../../include/ac/string.h
var.o: /usr/include/sys/syslimits.h
var.o: /usr/include/sys/_types/_rsize_t.h
var.o: /usr/include/string.h
var.o: /usr/include/sys/_types/_ssize_t.h
var.o: /usr/include/sys/_types/_errno_t.h
var.o: /usr/include/secure/_string.h
var.o: /usr/include/strings.h
var.o: ../../include/ac/syslog.h
var.o: /usr/include/secure/_common.h
var.o: /usr/include/sys/syslog.h
var.o: /usr/include/syslog.h
var.o: /usr/include/sys/types.h
var.o: ../../include/ac/regex.h
var.o: /usr/include/sys/_types/_blkcnt_t.h
var.o: /usr/include/sys/_types/_gid_t.h
var.o: /usr/include/sys/_types/_blksize_t.h
var.o: /usr/include/sys/_types/_in_addr_t.h
var.o: /usr/include/sys/_types/_ino_t.h
var.o: /usr/include/sys/_types/_in_port_t.h
var.o: /usr/include/sys/_types/_key_t.h
var.o: /usr/include/sys/_types/_ino64_t.h
var.o: /usr/include/sys/_types/_off_t.h
var.o: /usr/include/sys/_types/_nlink_t.h
var.o: /usr/include/sys/_types/_time_t.h
var.o: /usr/include/sys/_types/_clock_t.h
var.o: /usr/include/sys/_types/_useconds_t.h
var.o: /usr/include/sys/_types/_suseconds_t.h
var.o: /usr/include/sys/_types/_fd_def.h
var.o: /usr/include/sys/_types/_fd_setsize.h
var.o: /usr/include/sys/_types/_fd_clr.h
var.o: /usr/include/sys/_types/_fd_set.h
var.o: /usr/include/sys/_types/_fd_isset.h
var.o: /usr/include/sys/_types/_fd_zero.h
var.o: /usr/include/sys/_types/_fd_copy.h
var.o: /usr/include/sys/_pthread/_pthread_cond_t.h
var.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
var.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
var.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
var.o: /usr/include/sys/_pthread/_pthread_once_t.h
var.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
var.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
var.o: /usr/include/sys/_pthread/_pthread_t.h
var.o: /usr/include/sys/_pthread/_pthread_key_t.h
var.o: /usr/include/sys/_types/_fsblkcnt_t.h
var.o: /usr/include/regex.h
var.o: /usr/include/sys/_types/_fsfilcnt_t.h
var.o: /usr/include/poll.h
var.o: /usr/include/sys/poll.h
var.o: ../../include/ac/socket.h
var.o: /usr/include/machine/_param.h
var.o: /usr/include/sys/socket.h
var.o: /usr/include/net/net_kev.h
var.o: /usr/include/i386/_param.h
var.o: /usr/include/sys/_types/_sa_family_t.h
var.o: /usr/include/sys/_types/_socklen_t.h
var.o: /usr/include/sys/un.h
var.o: /usr/include/sys/_types/_iovec_t.h
var.o: /usr/include/sys/_types/_timespec.h
var.o: /usr/include/sys/select.h
var.o: /usr/include/netinet/in.h
var.o: /usr/include/sys/_select.h
var.o: /usr/include/netinet/tcp.h
var.o: /usr/include/netinet6/in6.h
var.o: /usr/include/arpa/nameser.h
var.o: /usr/include/arpa/inet.h
var.o: /usr/include/machine/param.h
var.o: /usr/include/sys/param.h
var.o: /usr/include/netdb.h
var.o: /usr/include/resolv.h
var.o: /usr/include/i386/param.h
var.o: /usr/include/sys/_types/_va_list.h
var.o: /usr/include/stdio.h
var.o: /usr/include/secure/_stdio.h
var.o: /usr/include/sys/stdio.h
var.o: /usr/include/unistd.h
var.o: ../../include/ac/unistd.h
var.o: /usr/include/sys/_types/_posix_vdisable.h
var.o: /usr/include/sys/unistd.h
var.o: /usr/include/sys/_types/_uuid_t.h
var.o: /usr/include/sys/_types/_seek_set.h
var.o: /usr/include/getopt.h
var.o: /usr/include/gethostuuid.h
var.o: ../../include/ac/ctype.h
var.o: ../../include/lutil_lockf.h
var.o: /usr/include/runetype.h
var.o: /usr/include/ctype.h
var.o: ../../include/lber.h
var.o: /usr/include/sys/_types/_wint_t.h
var.o: ../../include/ldap.h
var.o: ../../include/lber_types.h
var.o: ../../include/lutil.h
var.o: ../../include/avl.h
var.o: ../../include/ldap_log.h
var.o: ../../include/ldap_pvt_thread.h
var.o: ../../include/rewrite.h
var.o: /usr/include/pthread.h
var.o: ../../include/ldap_int_thread.h
var.o: /usr/include/pthread/sched.h
var.o: /usr/include/pthread/pthread_impl.h
var.o: /usr/include/pthread/qos.h
var.o: /usr/include/sys/qos.h
var.o: /usr/include/time.h
var.o: /usr/include/sys/_types/_mach_port_t.h
xmap.o: ../../include/portable.h
xmap.o: xmap.c
xmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
xmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
xmap.o: ../../include/ldap_cdefs.h
xmap.o: ../../include/ac/fdset.h
xmap.o: ../../include/ac/assert.h
xmap.o: ../../include/ldap_features.h
xmap.o: /usr/include/sys/cdefs.h
xmap.o: /usr/include/assert.h
xmap.o: /usr/include/sys/_symbol_aliasing.h
xmap.o: ../../include/ac/localize.h
xmap.o: /usr/include/sys/_posix_availability.h
xmap.o: /usr/include/Availability.h
xmap.o: /usr/include/stdio.h
xmap.o: /usr/include/_types.h
xmap.o: /usr/include/AvailabilityInternal.h
xmap.o: /usr/include/machine/_types.h
xmap.o: /usr/include/sys/_types.h
xmap.o: /usr/include/sys/_pthread/_pthread_types.h
xmap.o: /usr/include/i386/_types.h
xmap.o: /usr/include/sys/_types/_size_t.h
xmap.o: /usr/include/sys/_types/_va_list.h
xmap.o: /usr/include/sys/stdio.h
xmap.o: /usr/include/sys/_types/_null.h
xmap.o: /usr/include/sys/_types/_ssize_t.h
xmap.o: /usr/include/sys/_types/_off_t.h
xmap.o: /usr/include/secure/_common.h
xmap.o: /usr/include/secure/_stdio.h
xmap.o: /usr/include/sys/_types/_gid_t.h
xmap.o: /usr/include/pwd.h
xmap.o: /usr/include/uuid/uuid.h
xmap.o: /usr/include/sys/_types/_uid_t.h
xmap.o: rewrite-int.h
xmap.o: /usr/include/sys/_types/_uuid_t.h
xmap.o: /usr/include/stdlib.h
xmap.o: ../../include/ac/stdlib.h
xmap.o: /usr/include/sys/_types/_pid_t.h
xmap.o: /usr/include/sys/wait.h
xmap.o: /usr/include/sys/signal.h
xmap.o: /usr/include/sys/_types/_id_t.h
xmap.o: /usr/include/machine/signal.h
xmap.o: /usr/include/sys/appleapiopts.h
xmap.o: /usr/include/machine/_mcontext.h
xmap.o: /usr/include/i386/signal.h
xmap.o: /usr/include/mach/i386/_structs.h
xmap.o: /usr/include/i386/_mcontext.h
xmap.o: /usr/include/sys/_pthread/_pthread_attr_t.h
xmap.o: /usr/include/sys/_types/_sigaltstack.h
xmap.o: /usr/include/sys/_types/_ucontext.h
xmap.o: /usr/include/sys/resource.h
xmap.o: /usr/include/sys/_types/_sigset_t.h
xmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
xmap.o: /usr/include/sys/_types/_int8_t.h
xmap.o: /usr/include/stdint.h
xmap.o: /usr/include/sys/_types/_int32_t.h
xmap.o: /usr/include/sys/_types/_int16_t.h
xmap.o: /usr/include/_types/_uint8_t.h
xmap.o: /usr/include/sys/_types/_int64_t.h
xmap.o: /usr/include/_types/_uint32_t.h
xmap.o: /usr/include/_types/_uint16_t.h
xmap.o: /usr/include/sys/_types/_intptr_t.h
xmap.o: /usr/include/_types/_uint64_t.h
xmap.o: /usr/include/_types/_intmax_t.h
xmap.o: /usr/include/sys/_types/_uintptr_t.h
xmap.o: /usr/include/sys/_types/_timeval.h
xmap.o: /usr/include/_types/_uintmax_t.h
xmap.o: /usr/include/i386/endian.h
xmap.o: /usr/include/machine/endian.h
xmap.o: /usr/include/libkern/_OSByteOrder.h
xmap.o: /usr/include/sys/_endian.h
xmap.o: /usr/include/alloca.h
xmap.o: /usr/include/libkern/i386/_OSByteOrder.h
xmap.o: /usr/include/sys/_types/_rune_t.h
xmap.o: /usr/include/sys/_types/_ct_rune_t.h
xmap.o: /usr/include/machine/types.h
xmap.o: /usr/include/sys/_types/_wchar_t.h
xmap.o: /usr/include/sys/_types/_u_int8_t.h
xmap.o: /usr/include/i386/types.h
xmap.o: /usr/include/sys/_types/_u_int16_t.h
xmap.o: /usr/include/sys/_types/_u_int32_t.h
xmap.o: /usr/include/sys/_types/_dev_t.h
xmap.o: /usr/include/sys/_types/_u_int64_t.h
xmap.o: /usr/include/sys/_types/_mode_t.h
xmap.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
xmap.o: /usr/include/machine/limits.h
xmap.o: /usr/include/limits.h
xmap.o: /usr/include/i386/_limits.h
xmap.o: /usr/include/i386/limits.h
xmap.o: ../../include/ac/string.h
xmap.o: /usr/include/sys/syslimits.h
xmap.o: /usr/include/sys/_types/_rsize_t.h
xmap.o: /usr/include/string.h
xmap.o: /usr/include/strings.h
xmap.o: /usr/include/sys/_types/_errno_t.h
xmap.o: ../../include/ac/syslog.h
xmap.o: /usr/include/secure/_string.h
xmap.o: /usr/include/sys/syslog.h
xmap.o: /usr/include/syslog.h
xmap.o: /usr/include/sys/types.h
xmap.o: ../../include/ac/regex.h
xmap.o: /usr/include/sys/_types/_blkcnt_t.h
xmap.o: /usr/include/sys/_types/_blksize_t.h
xmap.o: /usr/include/sys/_types/_in_addr_t.h
xmap.o: /usr/include/sys/_types/_ino_t.h
xmap.o: /usr/include/sys/_types/_in_port_t.h
xmap.o: /usr/include/sys/_types/_key_t.h
xmap.o: /usr/include/sys/_types/_ino64_t.h
xmap.o: /usr/include/sys/_types/_clock_t.h
xmap.o: /usr/include/sys/_types/_nlink_t.h
xmap.o: /usr/include/sys/_types/_time_t.h
xmap.o: /usr/include/sys/_types/_useconds_t.h
xmap.o: /usr/include/sys/_types/_suseconds_t.h
xmap.o: /usr/include/sys/_types/_fd_def.h
xmap.o: /usr/include/sys/_types/_fd_setsize.h
xmap.o: /usr/include/sys/_types/_fd_clr.h
xmap.o: /usr/include/sys/_types/_fd_set.h
xmap.o: /usr/include/sys/_types/_fd_isset.h
xmap.o: /usr/include/sys/_types/_fd_zero.h
xmap.o: /usr/include/sys/_types/_fd_copy.h
xmap.o: /usr/include/sys/_pthread/_pthread_cond_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_once_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_t.h
xmap.o: /usr/include/sys/_pthread/_pthread_key_t.h
xmap.o: /usr/include/sys/_types/_fsblkcnt_t.h
xmap.o: /usr/include/regex.h
xmap.o: /usr/include/sys/_types/_fsfilcnt_t.h
xmap.o: /usr/include/poll.h
xmap.o: /usr/include/sys/poll.h
xmap.o: ../../include/ac/socket.h
xmap.o: /usr/include/machine/_param.h
xmap.o: /usr/include/sys/socket.h
xmap.o: /usr/include/net/net_kev.h
xmap.o: /usr/include/i386/_param.h
xmap.o: /usr/include/sys/_types/_sa_family_t.h
xmap.o: /usr/include/sys/_types/_socklen_t.h
xmap.o: /usr/include/sys/un.h
xmap.o: /usr/include/sys/_types/_iovec_t.h
xmap.o: /usr/include/sys/_types/_timespec.h
xmap.o: /usr/include/sys/select.h
xmap.o: /usr/include/netinet/in.h
xmap.o: /usr/include/sys/_select.h
xmap.o: /usr/include/netinet/tcp.h
xmap.o: /usr/include/netinet6/in6.h
xmap.o: /usr/include/arpa/nameser.h
xmap.o: /usr/include/arpa/inet.h
xmap.o: /usr/include/machine/param.h
xmap.o: /usr/include/sys/param.h
xmap.o: /usr/include/netdb.h
xmap.o: /usr/include/resolv.h
xmap.o: /usr/include/i386/param.h
xmap.o: /usr/include/unistd.h
xmap.o: ../../include/ac/unistd.h
xmap.o: /usr/include/sys/_types/_posix_vdisable.h
xmap.o: /usr/include/sys/unistd.h
xmap.o: /usr/include/gethostuuid.h
xmap.o: /usr/include/sys/_types/_seek_set.h
xmap.o: ../../include/lutil_lockf.h
xmap.o: /usr/include/getopt.h
xmap.o: /usr/include/ctype.h
xmap.o: /usr/include/runetype.h
xmap.o: ../../include/ac/ctype.h
xmap.o: ../../include/lber.h
xmap.o: /usr/include/sys/_types/_wint_t.h
xmap.o: ../../include/ldap.h
xmap.o: ../../include/lber_types.h
xmap.o: ../../include/lutil.h
xmap.o: ../../include/avl.h
xmap.o: ../../include/ldap_log.h
xmap.o: ../../include/ldap_pvt_thread.h
xmap.o: ../../include/rewrite.h
xmap.o: /usr/include/pthread.h
xmap.o: ../../include/ldap_int_thread.h
xmap.o: /usr/include/pthread/sched.h
xmap.o: /usr/include/pthread/pthread_impl.h
xmap.o: /usr/include/pthread/qos.h
xmap.o: /usr/include/sys/qos.h
xmap.o: /usr/include/time.h
xmap.o: rewrite-map.h
xmap.o: /usr/include/sys/_types/_mach_port_t.h
parse.o: ../../include/portable.h
parse.o: parse.c
parse.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
parse.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
parse.o: ../../include/ldap_cdefs.h
parse.o: ../../include/ac/fdset.h
parse.o: ../../include/ac/assert.h
parse.o: ../../include/ldap_features.h
parse.o: /usr/include/sys/cdefs.h
parse.o: /usr/include/assert.h
parse.o: /usr/include/sys/_symbol_aliasing.h
parse.o: ../../include/ac/localize.h
parse.o: /usr/include/sys/_posix_availability.h
parse.o: /usr/include/Availability.h
parse.o: /usr/include/stdio.h
parse.o: /usr/include/_types.h
parse.o: /usr/include/AvailabilityInternal.h
parse.o: /usr/include/machine/_types.h
parse.o: /usr/include/sys/_types.h
parse.o: /usr/include/sys/_pthread/_pthread_types.h
parse.o: /usr/include/i386/_types.h
parse.o: /usr/include/sys/_types/_size_t.h
parse.o: /usr/include/sys/_types/_va_list.h
parse.o: /usr/include/sys/stdio.h
parse.o: /usr/include/sys/_types/_null.h
parse.o: /usr/include/sys/_types/_ssize_t.h
parse.o: /usr/include/sys/_types/_off_t.h
parse.o: /usr/include/secure/_common.h
parse.o: /usr/include/secure/_stdio.h
parse.o: ../../include/ac/stdlib.h
parse.o: /usr/include/stdlib.h
parse.o: rewrite-int.h
parse.o: /usr/include/sys/_types/_pid_t.h
parse.o: /usr/include/sys/wait.h
parse.o: /usr/include/sys/signal.h
parse.o: /usr/include/sys/_types/_id_t.h
parse.o: /usr/include/machine/signal.h
parse.o: /usr/include/sys/appleapiopts.h
parse.o: /usr/include/machine/_mcontext.h
parse.o: /usr/include/i386/signal.h
parse.o: /usr/include/mach/i386/_structs.h
parse.o: /usr/include/i386/_mcontext.h
parse.o: /usr/include/sys/_pthread/_pthread_attr_t.h
parse.o: /usr/include/sys/_types/_sigaltstack.h
parse.o: /usr/include/sys/_types/_ucontext.h
parse.o: /usr/include/sys/_types/_uid_t.h
parse.o: /usr/include/sys/_types/_sigset_t.h
parse.o: /usr/include/sys/resource.h
parse.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
parse.o: /usr/include/sys/_types/_int8_t.h
parse.o: /usr/include/stdint.h
parse.o: /usr/include/sys/_types/_int32_t.h
parse.o: /usr/include/sys/_types/_int16_t.h
parse.o: /usr/include/_types/_uint8_t.h
parse.o: /usr/include/sys/_types/_int64_t.h
parse.o: /usr/include/_types/_uint32_t.h
parse.o: /usr/include/_types/_uint16_t.h
parse.o: /usr/include/sys/_types/_intptr_t.h
parse.o: /usr/include/_types/_uint64_t.h
parse.o: /usr/include/_types/_intmax_t.h
parse.o: /usr/include/sys/_types/_uintptr_t.h
parse.o: /usr/include/sys/_types/_timeval.h
parse.o: /usr/include/_types/_uintmax_t.h
parse.o: /usr/include/i386/endian.h
parse.o: /usr/include/machine/endian.h
parse.o: /usr/include/libkern/_OSByteOrder.h
parse.o: /usr/include/sys/_endian.h
parse.o: /usr/include/alloca.h
parse.o: /usr/include/libkern/i386/_OSByteOrder.h
parse.o: /usr/include/sys/_types/_rune_t.h
parse.o: /usr/include/sys/_types/_ct_rune_t.h
parse.o: /usr/include/machine/types.h
parse.o: /usr/include/sys/_types/_wchar_t.h
parse.o: /usr/include/sys/_types/_u_int8_t.h
parse.o: /usr/include/i386/types.h
parse.o: /usr/include/sys/_types/_u_int16_t.h
parse.o: /usr/include/sys/_types/_u_int32_t.h
parse.o: /usr/include/sys/_types/_dev_t.h
parse.o: /usr/include/sys/_types/_u_int64_t.h
parse.o: /usr/include/sys/_types/_mode_t.h
parse.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
parse.o: /usr/include/machine/limits.h
parse.o: /usr/include/limits.h
parse.o: /usr/include/i386/_limits.h
parse.o: /usr/include/i386/limits.h
parse.o: ../../include/ac/string.h
parse.o: /usr/include/sys/syslimits.h
parse.o: /usr/include/sys/_types/_rsize_t.h
parse.o: /usr/include/string.h
parse.o: /usr/include/strings.h
parse.o: /usr/include/sys/_types/_errno_t.h
parse.o: ../../include/ac/syslog.h
parse.o: /usr/include/secure/_string.h
parse.o: /usr/include/sys/syslog.h
parse.o: /usr/include/syslog.h
parse.o: /usr/include/sys/types.h
parse.o: ../../include/ac/regex.h
parse.o: /usr/include/sys/_types/_blkcnt_t.h
parse.o: /usr/include/sys/_types/_gid_t.h
parse.o: /usr/include/sys/_types/_blksize_t.h
parse.o: /usr/include/sys/_types/_in_addr_t.h
parse.o: /usr/include/sys/_types/_ino_t.h
parse.o: /usr/include/sys/_types/_in_port_t.h
parse.o: /usr/include/sys/_types/_key_t.h
parse.o: /usr/include/sys/_types/_ino64_t.h
parse.o: /usr/include/sys/_types/_clock_t.h
parse.o: /usr/include/sys/_types/_nlink_t.h
parse.o: /usr/include/sys/_types/_time_t.h
parse.o: /usr/include/sys/_types/_useconds_t.h
parse.o: /usr/include/sys/_types/_suseconds_t.h
parse.o: /usr/include/sys/_types/_fd_def.h
parse.o: /usr/include/sys/_types/_fd_setsize.h
parse.o: /usr/include/sys/_types/_fd_clr.h
parse.o: /usr/include/sys/_types/_fd_set.h
parse.o: /usr/include/sys/_types/_fd_isset.h
parse.o: /usr/include/sys/_types/_fd_zero.h
parse.o: /usr/include/sys/_types/_fd_copy.h
parse.o: /usr/include/sys/_pthread/_pthread_cond_t.h
parse.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
parse.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
parse.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
parse.o: /usr/include/sys/_pthread/_pthread_once_t.h
parse.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
parse.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
parse.o: /usr/include/sys/_pthread/_pthread_t.h
parse.o: /usr/include/sys/_pthread/_pthread_key_t.h
parse.o: /usr/include/sys/_types/_fsblkcnt_t.h
parse.o: /usr/include/regex.h
parse.o: /usr/include/sys/_types/_fsfilcnt_t.h
parse.o: /usr/include/poll.h
parse.o: /usr/include/sys/poll.h
parse.o: ../../include/ac/socket.h
parse.o: /usr/include/machine/_param.h
parse.o: /usr/include/sys/socket.h
parse.o: /usr/include/net/net_kev.h
parse.o: /usr/include/i386/_param.h
parse.o: /usr/include/sys/_types/_sa_family_t.h
parse.o: /usr/include/sys/_types/_socklen_t.h
parse.o: /usr/include/sys/un.h
parse.o: /usr/include/sys/_types/_iovec_t.h
parse.o: /usr/include/sys/_types/_timespec.h
parse.o: /usr/include/sys/select.h
parse.o: /usr/include/netinet/in.h
parse.o: /usr/include/sys/_select.h
parse.o: /usr/include/netinet/tcp.h
parse.o: /usr/include/netinet6/in6.h
parse.o: /usr/include/arpa/nameser.h
parse.o: /usr/include/arpa/inet.h
parse.o: /usr/include/machine/param.h
parse.o: /usr/include/sys/param.h
parse.o: /usr/include/netdb.h
parse.o: /usr/include/resolv.h
parse.o: /usr/include/i386/param.h
parse.o: /usr/include/unistd.h
parse.o: ../../include/ac/unistd.h
parse.o: /usr/include/sys/_types/_posix_vdisable.h
parse.o: /usr/include/sys/unistd.h
parse.o: /usr/include/sys/_types/_uuid_t.h
parse.o: /usr/include/sys/_types/_seek_set.h
parse.o: /usr/include/getopt.h
parse.o: /usr/include/gethostuuid.h
parse.o: ../../include/ac/ctype.h
parse.o: ../../include/lutil_lockf.h
parse.o: /usr/include/runetype.h
parse.o: /usr/include/ctype.h
parse.o: ../../include/lber.h
parse.o: /usr/include/sys/_types/_wint_t.h
parse.o: ../../include/ldap.h
parse.o: ../../include/lber_types.h
parse.o: ../../include/lutil.h
parse.o: ../../include/avl.h
parse.o: ../../include/ldap_log.h
parse.o: ../../include/ldap_pvt_thread.h
parse.o: ../../include/rewrite.h
parse.o: /usr/include/pthread.h
parse.o: ../../include/ldap_int_thread.h
parse.o: /usr/include/pthread/sched.h
parse.o: /usr/include/pthread/pthread_impl.h
parse.o: /usr/include/pthread/qos.h
parse.o: /usr/include/sys/qos.h
parse.o: /usr/include/time.h
parse.o: /usr/include/sys/_types/_mach_port_t.h
rewrite.o: ../../include/portable.h
rewrite.o: rewrite.c
rewrite.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
rewrite.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
rewrite.o: ../../include/ldap_cdefs.h
rewrite.o: ../../include/ac/fdset.h
rewrite.o: ../../include/ac/assert.h
rewrite.o: ../../include/ldap_features.h
rewrite.o: /usr/include/sys/cdefs.h
rewrite.o: /usr/include/assert.h
rewrite.o: /usr/include/sys/_symbol_aliasing.h
rewrite.o: ../../include/ac/localize.h
rewrite.o: /usr/include/sys/_posix_availability.h
rewrite.o: /usr/include/stdlib.h
rewrite.o: ../../include/ac/stdlib.h
rewrite.o: /usr/include/AvailabilityInternal.h
rewrite.o: /usr/include/Availability.h
rewrite.o: /usr/include/sys/_types.h
rewrite.o: /usr/include/_types.h
rewrite.o: /usr/include/i386/_types.h
rewrite.o: /usr/include/machine/_types.h
rewrite.o: /usr/include/sys/wait.h
rewrite.o: /usr/include/sys/_pthread/_pthread_types.h
rewrite.o: /usr/include/sys/_types/_id_t.h
rewrite.o: /usr/include/sys/_types/_pid_t.h
rewrite.o: /usr/include/sys/appleapiopts.h
rewrite.o: /usr/include/sys/signal.h
rewrite.o: /usr/include/i386/signal.h
rewrite.o: /usr/include/machine/signal.h
rewrite.o: /usr/include/i386/_mcontext.h
rewrite.o: /usr/include/machine/_mcontext.h
rewrite.o: /usr/include/mach/i386/_structs.h
rewrite.o: /usr/include/sys/_pthread/_pthread_attr_t.h
rewrite.o: /usr/include/sys/_types/_sigaltstack.h
rewrite.o: /usr/include/sys/_types/_ucontext.h
rewrite.o: /usr/include/sys/_types/_size_t.h
rewrite.o: /usr/include/sys/_types/_sigset_t.h
rewrite.o: /usr/include/sys/resource.h
rewrite.o: /usr/include/sys/_types/_uid_t.h
rewrite.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
rewrite.o: /usr/include/sys/_types/_int8_t.h
rewrite.o: /usr/include/stdint.h
rewrite.o: /usr/include/sys/_types/_int32_t.h
rewrite.o: /usr/include/sys/_types/_int16_t.h
rewrite.o: /usr/include/_types/_uint8_t.h
rewrite.o: /usr/include/sys/_types/_int64_t.h
rewrite.o: /usr/include/_types/_uint32_t.h
rewrite.o: /usr/include/_types/_uint16_t.h
rewrite.o: /usr/include/sys/_types/_intptr_t.h
rewrite.o: /usr/include/_types/_uint64_t.h
rewrite.o: /usr/include/_types/_intmax_t.h
rewrite.o: /usr/include/sys/_types/_uintptr_t.h
rewrite.o: /usr/include/sys/_types/_timeval.h
rewrite.o: /usr/include/_types/_uintmax_t.h
rewrite.o: /usr/include/i386/endian.h
rewrite.o: /usr/include/machine/endian.h
rewrite.o: /usr/include/libkern/_OSByteOrder.h
rewrite.o: /usr/include/sys/_endian.h
rewrite.o: /usr/include/alloca.h
rewrite.o: /usr/include/libkern/i386/_OSByteOrder.h
rewrite.o: /usr/include/sys/_types/_rune_t.h
rewrite.o: /usr/include/sys/_types/_ct_rune_t.h
rewrite.o: /usr/include/sys/_types/_null.h
rewrite.o: /usr/include/sys/_types/_wchar_t.h
rewrite.o: /usr/include/i386/types.h
rewrite.o: /usr/include/machine/types.h
rewrite.o: /usr/include/sys/_types/_u_int8_t.h
rewrite.o: /usr/include/sys/_types/_u_int16_t.h
rewrite.o: /usr/include/sys/_types/_u_int32_t.h
rewrite.o: /usr/include/sys/_types/_dev_t.h
rewrite.o: /usr/include/sys/_types/_u_int64_t.h
rewrite.o: /usr/include/sys/_types/_mode_t.h
rewrite.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
rewrite.o: /usr/include/machine/limits.h
rewrite.o: /usr/include/limits.h
rewrite.o: /usr/include/i386/_limits.h
rewrite.o: /usr/include/i386/limits.h
rewrite.o: ../../include/ac/string.h
rewrite.o: /usr/include/sys/syslimits.h
rewrite.o: /usr/include/sys/_types/_rsize_t.h
rewrite.o: /usr/include/string.h
rewrite.o: /usr/include/sys/_types/_ssize_t.h
rewrite.o: /usr/include/sys/_types/_errno_t.h
rewrite.o: /usr/include/secure/_string.h
rewrite.o: /usr/include/strings.h
rewrite.o: ../../include/ac/syslog.h
rewrite.o: /usr/include/secure/_common.h
rewrite.o: /usr/include/sys/syslog.h
rewrite.o: /usr/include/syslog.h
rewrite.o: /usr/include/sys/types.h
rewrite.o: ../../include/ac/regex.h
rewrite.o: /usr/include/sys/_types/_blkcnt_t.h
rewrite.o: /usr/include/sys/_types/_gid_t.h
rewrite.o: /usr/include/sys/_types/_blksize_t.h
rewrite.o: /usr/include/sys/_types/_in_addr_t.h
rewrite.o: /usr/include/sys/_types/_ino_t.h
rewrite.o: /usr/include/sys/_types/_in_port_t.h
rewrite.o: /usr/include/sys/_types/_key_t.h
rewrite.o: /usr/include/sys/_types/_ino64_t.h
rewrite.o: /usr/include/sys/_types/_off_t.h
rewrite.o: /usr/include/sys/_types/_nlink_t.h
rewrite.o: /usr/include/sys/_types/_time_t.h
rewrite.o: /usr/include/sys/_types/_clock_t.h
rewrite.o: /usr/include/sys/_types/_useconds_t.h
rewrite.o: /usr/include/sys/_types/_suseconds_t.h
rewrite.o: /usr/include/sys/_types/_fd_def.h
rewrite.o: /usr/include/sys/_types/_fd_setsize.h
rewrite.o: /usr/include/sys/_types/_fd_clr.h
rewrite.o: /usr/include/sys/_types/_fd_set.h
rewrite.o: /usr/include/sys/_types/_fd_isset.h
rewrite.o: /usr/include/sys/_types/_fd_zero.h
rewrite.o: /usr/include/sys/_types/_fd_copy.h
rewrite.o: /usr/include/sys/_pthread/_pthread_cond_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_once_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_t.h
rewrite.o: /usr/include/sys/_pthread/_pthread_key_t.h
rewrite.o: /usr/include/sys/_types/_fsblkcnt_t.h
rewrite.o: /usr/include/regex.h
rewrite.o: /usr/include/sys/_types/_fsfilcnt_t.h
rewrite.o: /usr/include/poll.h
rewrite.o: /usr/include/sys/poll.h
rewrite.o: ../../include/ac/socket.h
rewrite.o: /usr/include/machine/_param.h
rewrite.o: /usr/include/sys/socket.h
rewrite.o: /usr/include/net/net_kev.h
rewrite.o: /usr/include/i386/_param.h
rewrite.o: /usr/include/sys/_types/_sa_family_t.h
rewrite.o: /usr/include/sys/_types/_socklen_t.h
rewrite.o: /usr/include/sys/un.h
rewrite.o: /usr/include/sys/_types/_iovec_t.h
rewrite.o: /usr/include/sys/_types/_timespec.h
rewrite.o: /usr/include/sys/select.h
rewrite.o: /usr/include/netinet/in.h
rewrite.o: /usr/include/sys/_select.h
rewrite.o: /usr/include/netinet/tcp.h
rewrite.o: /usr/include/netinet6/in6.h
rewrite.o: /usr/include/arpa/nameser.h
rewrite.o: /usr/include/arpa/inet.h
rewrite.o: /usr/include/machine/param.h
rewrite.o: /usr/include/sys/param.h
rewrite.o: /usr/include/netdb.h
rewrite.o: /usr/include/resolv.h
rewrite.o: /usr/include/i386/param.h
rewrite.o: /usr/include/sys/_types/_va_list.h
rewrite.o: /usr/include/stdio.h
rewrite.o: /usr/include/secure/_stdio.h
rewrite.o: /usr/include/sys/stdio.h
rewrite.o: /usr/include/unistd.h
rewrite.o: ../../include/ac/unistd.h
rewrite.o: /usr/include/sys/_types/_posix_vdisable.h
rewrite.o: /usr/include/sys/unistd.h
rewrite.o: /usr/include/sys/_types/_uuid_t.h
rewrite.o: /usr/include/sys/_types/_seek_set.h
rewrite.o: /usr/include/getopt.h
rewrite.o: /usr/include/gethostuuid.h
rewrite.o: ../../include/ac/ctype.h
rewrite.o: ../../include/lutil_lockf.h
rewrite.o: /usr/include/runetype.h
rewrite.o: /usr/include/ctype.h
rewrite.o: ../../include/rewrite.h
rewrite.o: /usr/include/sys/_types/_wint_t.h
rewrite.o: ../../include/lber_types.h
rewrite.o: ../../include/ldap.h
rewrite.o: ../../include/lutil.h
rewrite.o: ../../include/lber.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
