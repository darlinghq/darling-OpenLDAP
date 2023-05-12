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

# LIBLBER
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

LIBRARY = liblber.la

NT_SRCS = nt_err.c
NT_OBJS = nt_err.lo

UNIX_SRCS = stdio.c
UNIX_OBJS = stdio.lo

LIB_DEFS = -DLBER_LIBRARY

SRCS= assert.c decode.c encode.c io.c bprint.c debug.c \
	memory.c options.c sockbuf.c $(UNIX_SRCS)
OBJS= assert.lo decode.lo encode.lo io.lo bprint.lo debug.lo \
	memory.lo options.lo sockbuf.lo $(UNIX_OBJS)
XSRCS= version.c

PROGRAMS= dtest etest idtest

LDAP_INCDIR= ../../include
LDAP_LIBDIR= ../../libraries

XLIBS = $(LIBRARY) $(LDAP_LIBLUTIL_A)
XXLIBS = 
NT_LINK_LIBS = $(AC_LIBS)
UNIX_LINK_LIBS = $(AC_LIBS)

dtest:    $(XLIBS) dtest.o
	$(LTLINK) -o $@ dtest.o $(LIBS)
etest:  $(XLIBS) etest.o
	$(LTLINK) -o $@ etest.o $(LIBS)
idtest:  $(XLIBS) idtest.o
	$(LTLINK) -o $@ idtest.o $(LIBS)

install-local: FORCE
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
# Makefile Template for Shared Libraries
#

MKDEPFLAG = -l

.SUFFIXES: .c .o .lo

.c.lo:
	$(LTCOMPILE_LIB) $<

$(LIBRARY): version.lo
	$(LTLINK_LIB) -o $@ $(OBJS) version.lo $(LINK_LIBS)

Makefile: $(top_srcdir)/build/lib-shared.mk

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.


#
# files: -I../../include -I../../include assert.c decode.c encode.c io.c bprint.c debug.c memory.c options.c sockbuf.c stdio.c
# command: cc -M -I.  -I../../include -I../../include assert.c decode.c encode.c io.c bprint.c debug.c memory.c options.c sockbuf.c stdio.c
#

assert.lo: ../../include/portable.h
assert.lo: assert.c
assert.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
assert.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
assert.lo: ../../include/ldap_cdefs.h
assert.lo: ../../include/ac/fdset.h
assert.lo: ../../include/ac/assert.h
assert.lo: ../../include/ldap_features.h
assert.lo: /usr/include/sys/cdefs.h
assert.lo: /usr/include/assert.h
assert.lo: /usr/include/sys/_symbol_aliasing.h
assert.lo: ../../include/ac/localize.h
assert.lo: /usr/include/sys/_posix_availability.h
decode.lo: ../../include/portable.h
decode.lo: decode.c
decode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
decode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
decode.lo: ../../include/ldap_cdefs.h
decode.lo: ../../include/ac/fdset.h
decode.lo: ../../include/ac/assert.h
decode.lo: ../../include/ldap_features.h
decode.lo: /usr/include/sys/cdefs.h
decode.lo: /usr/include/assert.h
decode.lo: /usr/include/sys/_symbol_aliasing.h
decode.lo: ../../include/ac/localize.h
decode.lo: /usr/include/sys/_posix_availability.h
decode.lo: /usr/include/Availability.h
decode.lo: /usr/include/stdio.h
decode.lo: /usr/include/_types.h
decode.lo: /usr/include/AvailabilityInternal.h
decode.lo: /usr/include/machine/_types.h
decode.lo: /usr/include/sys/_types.h
decode.lo: /usr/include/sys/_pthread/_pthread_types.h
decode.lo: /usr/include/i386/_types.h
decode.lo: /usr/include/sys/_types/_size_t.h
decode.lo: /usr/include/sys/_types/_va_list.h
decode.lo: /usr/include/sys/stdio.h
decode.lo: /usr/include/sys/_types/_null.h
decode.lo: /usr/include/sys/_types/_ssize_t.h
decode.lo: /usr/include/sys/_types/_off_t.h
decode.lo: /usr/include/secure/_common.h
decode.lo: /usr/include/secure/_stdio.h
decode.lo: /usr/include/stdlib.h
decode.lo: ../../include/ac/stdlib.h
decode.lo: /usr/include/sys/_types/_pid_t.h
decode.lo: /usr/include/sys/wait.h
decode.lo: /usr/include/sys/signal.h
decode.lo: /usr/include/sys/_types/_id_t.h
decode.lo: /usr/include/machine/signal.h
decode.lo: /usr/include/sys/appleapiopts.h
decode.lo: /usr/include/machine/_mcontext.h
decode.lo: /usr/include/i386/signal.h
decode.lo: /usr/include/mach/i386/_structs.h
decode.lo: /usr/include/i386/_mcontext.h
decode.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
decode.lo: /usr/include/sys/_types/_sigaltstack.h
decode.lo: /usr/include/sys/_types/_ucontext.h
decode.lo: /usr/include/sys/_types/_uid_t.h
decode.lo: /usr/include/sys/_types/_sigset_t.h
decode.lo: /usr/include/sys/resource.h
decode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
decode.lo: /usr/include/sys/_types/_int8_t.h
decode.lo: /usr/include/stdint.h
decode.lo: /usr/include/sys/_types/_int32_t.h
decode.lo: /usr/include/sys/_types/_int16_t.h
decode.lo: /usr/include/_types/_uint8_t.h
decode.lo: /usr/include/sys/_types/_int64_t.h
decode.lo: /usr/include/_types/_uint32_t.h
decode.lo: /usr/include/_types/_uint16_t.h
decode.lo: /usr/include/sys/_types/_intptr_t.h
decode.lo: /usr/include/_types/_uint64_t.h
decode.lo: /usr/include/_types/_intmax_t.h
decode.lo: /usr/include/sys/_types/_uintptr_t.h
decode.lo: /usr/include/sys/_types/_timeval.h
decode.lo: /usr/include/_types/_uintmax_t.h
decode.lo: /usr/include/i386/endian.h
decode.lo: /usr/include/machine/endian.h
decode.lo: /usr/include/libkern/_OSByteOrder.h
decode.lo: /usr/include/sys/_endian.h
decode.lo: /usr/include/alloca.h
decode.lo: /usr/include/libkern/i386/_OSByteOrder.h
decode.lo: /usr/include/sys/_types/_rune_t.h
decode.lo: /usr/include/sys/_types/_ct_rune_t.h
decode.lo: /usr/include/machine/types.h
decode.lo: /usr/include/sys/_types/_wchar_t.h
decode.lo: /usr/include/sys/_types/_u_int8_t.h
decode.lo: /usr/include/i386/types.h
decode.lo: /usr/include/sys/_types/_u_int16_t.h
decode.lo: /usr/include/sys/_types/_u_int32_t.h
decode.lo: /usr/include/sys/_types/_dev_t.h
decode.lo: /usr/include/sys/_types/_u_int64_t.h
decode.lo: /usr/include/sys/_types/_mode_t.h
decode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
decode.lo: /usr/include/machine/limits.h
decode.lo: /usr/include/limits.h
decode.lo: /usr/include/i386/_limits.h
decode.lo: /usr/include/i386/limits.h
decode.lo: ../../include/ac/stdarg.h
decode.lo: /usr/include/sys/syslimits.h
decode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
decode.lo: /usr/include/string.h
decode.lo: ../../include/ac/string.h
decode.lo: /usr/include/sys/_types/_errno_t.h
decode.lo: /usr/include/sys/_types/_rsize_t.h
decode.lo: /usr/include/secure/_string.h
decode.lo: /usr/include/strings.h
decode.lo: /usr/include/sys/types.h
decode.lo: ../../include/ac/socket.h
decode.lo: /usr/include/sys/_types/_blkcnt_t.h
decode.lo: /usr/include/sys/_types/_gid_t.h
decode.lo: /usr/include/sys/_types/_blksize_t.h
decode.lo: /usr/include/sys/_types/_in_addr_t.h
decode.lo: /usr/include/sys/_types/_ino_t.h
decode.lo: /usr/include/sys/_types/_in_port_t.h
decode.lo: /usr/include/sys/_types/_key_t.h
decode.lo: /usr/include/sys/_types/_ino64_t.h
decode.lo: /usr/include/sys/_types/_clock_t.h
decode.lo: /usr/include/sys/_types/_nlink_t.h
decode.lo: /usr/include/sys/_types/_time_t.h
decode.lo: /usr/include/sys/_types/_useconds_t.h
decode.lo: /usr/include/sys/_types/_suseconds_t.h
decode.lo: /usr/include/sys/_types/_fd_def.h
decode.lo: /usr/include/sys/_types/_fd_setsize.h
decode.lo: /usr/include/sys/_types/_fd_clr.h
decode.lo: /usr/include/sys/_types/_fd_set.h
decode.lo: /usr/include/sys/_types/_fd_isset.h
decode.lo: /usr/include/sys/_types/_fd_zero.h
decode.lo: /usr/include/sys/_types/_fd_copy.h
decode.lo: /usr/include/sys/_pthread/_pthread_cond_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_condattr_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_mutex_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_once_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_rwlock_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_t.h
decode.lo: /usr/include/sys/_pthread/_pthread_key_t.h
decode.lo: /usr/include/sys/_types/_fsblkcnt_t.h
decode.lo: /usr/include/poll.h
decode.lo: /usr/include/sys/_types/_fsfilcnt_t.h
decode.lo: /usr/include/sys/socket.h
decode.lo: /usr/include/sys/poll.h
decode.lo: /usr/include/i386/_param.h
decode.lo: /usr/include/machine/_param.h
decode.lo: /usr/include/sys/_types/_sa_family_t.h
decode.lo: /usr/include/net/net_kev.h
decode.lo: /usr/include/sys/_types/_socklen_t.h
decode.lo: /usr/include/sys/un.h
decode.lo: /usr/include/sys/_types/_iovec_t.h
decode.lo: /usr/include/sys/_types/_timespec.h
decode.lo: /usr/include/sys/select.h
decode.lo: /usr/include/netinet/in.h
decode.lo: /usr/include/sys/_select.h
decode.lo: /usr/include/netinet/tcp.h
decode.lo: /usr/include/netinet6/in6.h
decode.lo: /usr/include/arpa/nameser.h
decode.lo: /usr/include/arpa/inet.h
decode.lo: /usr/include/machine/param.h
decode.lo: /usr/include/sys/param.h
decode.lo: /usr/include/netdb.h
decode.lo: /usr/include/resolv.h
decode.lo: /usr/include/i386/param.h
decode.lo: ../../include/lber.h
decode.lo: ../../include/lber_types.h
decode.lo: lber-int.h
decode.lo: ../../include/lber_pvt.h
decode.lo: ../../include/ldap_log.h
decode.lo: ../../include/ldap_queue.h
encode.lo: ../../include/portable.h
encode.lo: encode.c
encode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
encode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
encode.lo: ../../include/ldap_cdefs.h
encode.lo: ../../include/ac/fdset.h
encode.lo: ../../include/ac/assert.h
encode.lo: ../../include/ldap_features.h
encode.lo: /usr/include/sys/cdefs.h
encode.lo: /usr/include/assert.h
encode.lo: /usr/include/sys/_symbol_aliasing.h
encode.lo: ../../include/ac/localize.h
encode.lo: /usr/include/sys/_posix_availability.h
encode.lo: /usr/include/runetype.h
encode.lo: /usr/include/_types.h
encode.lo: /usr/include/ctype.h
encode.lo: /usr/include/machine/_types.h
encode.lo: /usr/include/sys/_types.h
encode.lo: /usr/include/sys/_pthread/_pthread_types.h
encode.lo: /usr/include/i386/_types.h
encode.lo: /usr/include/sys/_types/_ct_rune_t.h
encode.lo: /usr/include/sys/_types/_size_t.h
encode.lo: /usr/include/sys/_types/_wchar_t.h
encode.lo: /usr/include/sys/_types/_rune_t.h
encode.lo: /usr/include/sys/_types/_wint_t.h
encode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
encode.lo: /usr/include/machine/limits.h
encode.lo: /usr/include/limits.h
encode.lo: /usr/include/i386/_limits.h
encode.lo: /usr/include/i386/limits.h
encode.lo: /usr/include/stdio.h
encode.lo: /usr/include/sys/syslimits.h
encode.lo: /usr/include/AvailabilityInternal.h
encode.lo: /usr/include/Availability.h
encode.lo: /usr/include/sys/_types/_null.h
encode.lo: /usr/include/sys/_types/_va_list.h
encode.lo: /usr/include/sys/_types/_off_t.h
encode.lo: /usr/include/sys/stdio.h
encode.lo: /usr/include/secure/_stdio.h
encode.lo: /usr/include/sys/_types/_ssize_t.h
encode.lo: ../../include/ac/stdlib.h
encode.lo: /usr/include/secure/_common.h
encode.lo: /usr/include/sys/wait.h
encode.lo: /usr/include/stdlib.h
encode.lo: /usr/include/sys/_types/_id_t.h
encode.lo: /usr/include/sys/_types/_pid_t.h
encode.lo: /usr/include/sys/appleapiopts.h
encode.lo: /usr/include/sys/signal.h
encode.lo: /usr/include/i386/signal.h
encode.lo: /usr/include/machine/signal.h
encode.lo: /usr/include/i386/_mcontext.h
encode.lo: /usr/include/machine/_mcontext.h
encode.lo: /usr/include/mach/i386/_structs.h
encode.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
encode.lo: /usr/include/sys/_types/_sigaltstack.h
encode.lo: /usr/include/sys/_types/_ucontext.h
encode.lo: /usr/include/sys/_types/_uid_t.h
encode.lo: /usr/include/sys/_types/_sigset_t.h
encode.lo: /usr/include/sys/resource.h
encode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
encode.lo: /usr/include/sys/_types/_int8_t.h
encode.lo: /usr/include/stdint.h
encode.lo: /usr/include/sys/_types/_int32_t.h
encode.lo: /usr/include/sys/_types/_int16_t.h
encode.lo: /usr/include/_types/_uint8_t.h
encode.lo: /usr/include/sys/_types/_int64_t.h
encode.lo: /usr/include/_types/_uint32_t.h
encode.lo: /usr/include/_types/_uint16_t.h
encode.lo: /usr/include/sys/_types/_intptr_t.h
encode.lo: /usr/include/_types/_uint64_t.h
encode.lo: /usr/include/_types/_intmax_t.h
encode.lo: /usr/include/sys/_types/_uintptr_t.h
encode.lo: /usr/include/sys/_types/_timeval.h
encode.lo: /usr/include/_types/_uintmax_t.h
encode.lo: /usr/include/i386/endian.h
encode.lo: /usr/include/machine/endian.h
encode.lo: /usr/include/libkern/_OSByteOrder.h
encode.lo: /usr/include/sys/_endian.h
encode.lo: /usr/include/alloca.h
encode.lo: /usr/include/libkern/i386/_OSByteOrder.h
encode.lo: /usr/include/i386/types.h
encode.lo: /usr/include/machine/types.h
encode.lo: /usr/include/sys/_types/_u_int8_t.h
encode.lo: /usr/include/sys/_types/_u_int16_t.h
encode.lo: /usr/include/sys/_types/_u_int32_t.h
encode.lo: /usr/include/sys/_types/_dev_t.h
encode.lo: /usr/include/sys/_types/_u_int64_t.h
encode.lo: ../../include/ac/stdarg.h
encode.lo: /usr/include/sys/_types/_mode_t.h
encode.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
encode.lo: /usr/include/sys/types.h
encode.lo: ../../include/ac/socket.h
encode.lo: /usr/include/sys/_types/_blkcnt_t.h
encode.lo: /usr/include/sys/_types/_gid_t.h
encode.lo: /usr/include/sys/_types/_blksize_t.h
encode.lo: /usr/include/sys/_types/_in_addr_t.h
encode.lo: /usr/include/sys/_types/_ino_t.h
encode.lo: /usr/include/sys/_types/_in_port_t.h
encode.lo: /usr/include/sys/_types/_key_t.h
encode.lo: /usr/include/sys/_types/_ino64_t.h
encode.lo: /usr/include/sys/_types/_clock_t.h
encode.lo: /usr/include/sys/_types/_nlink_t.h
encode.lo: /usr/include/sys/_types/_time_t.h
encode.lo: /usr/include/sys/_types/_useconds_t.h
encode.lo: /usr/include/sys/_types/_suseconds_t.h
encode.lo: /usr/include/sys/_types/_errno_t.h
encode.lo: /usr/include/sys/_types/_rsize_t.h
encode.lo: /usr/include/sys/_types/_fd_def.h
encode.lo: /usr/include/sys/_types/_fd_setsize.h
encode.lo: /usr/include/sys/_types/_fd_clr.h
encode.lo: /usr/include/sys/_types/_fd_set.h
encode.lo: /usr/include/sys/_types/_fd_isset.h
encode.lo: /usr/include/sys/_types/_fd_zero.h
encode.lo: /usr/include/sys/_types/_fd_copy.h
encode.lo: /usr/include/sys/_pthread/_pthread_cond_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_condattr_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_mutex_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_once_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_rwlock_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_t.h
encode.lo: /usr/include/sys/_pthread/_pthread_key_t.h
encode.lo: /usr/include/sys/_types/_fsblkcnt_t.h
encode.lo: /usr/include/poll.h
encode.lo: /usr/include/sys/_types/_fsfilcnt_t.h
encode.lo: /usr/include/sys/socket.h
encode.lo: /usr/include/sys/poll.h
encode.lo: /usr/include/i386/_param.h
encode.lo: /usr/include/machine/_param.h
encode.lo: /usr/include/sys/_types/_sa_family_t.h
encode.lo: /usr/include/net/net_kev.h
encode.lo: /usr/include/sys/_types/_socklen_t.h
encode.lo: /usr/include/sys/un.h
encode.lo: /usr/include/sys/_types/_iovec_t.h
encode.lo: /usr/include/sys/_types/_timespec.h
encode.lo: /usr/include/sys/select.h
encode.lo: /usr/include/netinet/in.h
encode.lo: /usr/include/sys/_select.h
encode.lo: /usr/include/netinet/tcp.h
encode.lo: /usr/include/netinet6/in6.h
encode.lo: /usr/include/arpa/nameser.h
encode.lo: /usr/include/arpa/inet.h
encode.lo: /usr/include/machine/param.h
encode.lo: /usr/include/sys/param.h
encode.lo: /usr/include/netdb.h
encode.lo: /usr/include/resolv.h
encode.lo: /usr/include/i386/param.h
encode.lo: /usr/include/string.h
encode.lo: /usr/include/strings.h
encode.lo: ../../include/ac/string.h
encode.lo: lber-int.h
encode.lo: ../../include/lber.h
encode.lo: /usr/include/secure/_string.h
encode.lo: ../../include/ldap_log.h
encode.lo: ../../include/lber_types.h
encode.lo: ../../include/ldap_queue.h
encode.lo: ../../include/lber_pvt.h
io.lo: ../../include/portable.h
io.lo: io.c
io.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
io.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
io.lo: ../../include/ldap_cdefs.h
io.lo: ../../include/ac/fdset.h
io.lo: ../../include/ac/assert.h
io.lo: ../../include/ldap_features.h
io.lo: /usr/include/sys/cdefs.h
io.lo: /usr/include/assert.h
io.lo: /usr/include/sys/_symbol_aliasing.h
io.lo: ../../include/ac/localize.h
io.lo: /usr/include/sys/_posix_availability.h
io.lo: /usr/include/Availability.h
io.lo: /usr/include/stdio.h
io.lo: /usr/include/_types.h
io.lo: /usr/include/AvailabilityInternal.h
io.lo: /usr/include/machine/_types.h
io.lo: /usr/include/sys/_types.h
io.lo: /usr/include/sys/_pthread/_pthread_types.h
io.lo: /usr/include/i386/_types.h
io.lo: /usr/include/sys/_types/_size_t.h
io.lo: /usr/include/sys/_types/_va_list.h
io.lo: /usr/include/sys/stdio.h
io.lo: /usr/include/sys/_types/_null.h
io.lo: /usr/include/sys/_types/_ssize_t.h
io.lo: /usr/include/sys/_types/_off_t.h
io.lo: /usr/include/secure/_common.h
io.lo: /usr/include/secure/_stdio.h
io.lo: /usr/include/stdlib.h
io.lo: ../../include/ac/stdlib.h
io.lo: /usr/include/sys/_types/_pid_t.h
io.lo: /usr/include/sys/wait.h
io.lo: /usr/include/sys/signal.h
io.lo: /usr/include/sys/_types/_id_t.h
io.lo: /usr/include/machine/signal.h
io.lo: /usr/include/sys/appleapiopts.h
io.lo: /usr/include/machine/_mcontext.h
io.lo: /usr/include/i386/signal.h
io.lo: /usr/include/mach/i386/_structs.h
io.lo: /usr/include/i386/_mcontext.h
io.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
io.lo: /usr/include/sys/_types/_sigaltstack.h
io.lo: /usr/include/sys/_types/_ucontext.h
io.lo: /usr/include/sys/_types/_uid_t.h
io.lo: /usr/include/sys/_types/_sigset_t.h
io.lo: /usr/include/sys/resource.h
io.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
io.lo: /usr/include/sys/_types/_int8_t.h
io.lo: /usr/include/stdint.h
io.lo: /usr/include/sys/_types/_int32_t.h
io.lo: /usr/include/sys/_types/_int16_t.h
io.lo: /usr/include/_types/_uint8_t.h
io.lo: /usr/include/sys/_types/_int64_t.h
io.lo: /usr/include/_types/_uint32_t.h
io.lo: /usr/include/_types/_uint16_t.h
io.lo: /usr/include/sys/_types/_intptr_t.h
io.lo: /usr/include/_types/_uint64_t.h
io.lo: /usr/include/_types/_intmax_t.h
io.lo: /usr/include/sys/_types/_uintptr_t.h
io.lo: /usr/include/sys/_types/_timeval.h
io.lo: /usr/include/_types/_uintmax_t.h
io.lo: /usr/include/i386/endian.h
io.lo: /usr/include/machine/endian.h
io.lo: /usr/include/libkern/_OSByteOrder.h
io.lo: /usr/include/sys/_endian.h
io.lo: /usr/include/alloca.h
io.lo: /usr/include/libkern/i386/_OSByteOrder.h
io.lo: /usr/include/sys/_types/_rune_t.h
io.lo: /usr/include/sys/_types/_ct_rune_t.h
io.lo: /usr/include/machine/types.h
io.lo: /usr/include/sys/_types/_wchar_t.h
io.lo: /usr/include/sys/_types/_u_int8_t.h
io.lo: /usr/include/i386/types.h
io.lo: /usr/include/sys/_types/_u_int16_t.h
io.lo: /usr/include/sys/_types/_u_int32_t.h
io.lo: /usr/include/sys/_types/_dev_t.h
io.lo: /usr/include/sys/_types/_u_int64_t.h
io.lo: /usr/include/sys/_types/_mode_t.h
io.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
io.lo: /usr/include/machine/limits.h
io.lo: /usr/include/limits.h
io.lo: /usr/include/i386/_limits.h
io.lo: /usr/include/i386/limits.h
io.lo: ../../include/ac/ctype.h
io.lo: /usr/include/sys/syslimits.h
io.lo: /usr/include/runetype.h
io.lo: /usr/include/ctype.h
io.lo: ../../include/ac/errno.h
io.lo: /usr/include/sys/_types/_wint_t.h
io.lo: /usr/include/sys/errno.h
io.lo: /usr/include/errno.h
io.lo: ../../include/ac/socket.h
io.lo: /usr/include/sys/_types/_errno_t.h
io.lo: /usr/include/sys/_types/_blkcnt_t.h
io.lo: /usr/include/sys/types.h
io.lo: /usr/include/sys/_types/_gid_t.h
io.lo: /usr/include/sys/_types/_blksize_t.h
io.lo: /usr/include/sys/_types/_in_addr_t.h
io.lo: /usr/include/sys/_types/_ino_t.h
io.lo: /usr/include/sys/_types/_in_port_t.h
io.lo: /usr/include/sys/_types/_key_t.h
io.lo: /usr/include/sys/_types/_ino64_t.h
io.lo: /usr/include/sys/_types/_clock_t.h
io.lo: /usr/include/sys/_types/_nlink_t.h
io.lo: /usr/include/sys/_types/_time_t.h
io.lo: /usr/include/sys/_types/_useconds_t.h
io.lo: /usr/include/sys/_types/_suseconds_t.h
io.lo: /usr/include/sys/_types/_fd_def.h
io.lo: /usr/include/sys/_types/_rsize_t.h
io.lo: /usr/include/sys/_types/_fd_setsize.h
io.lo: /usr/include/sys/_types/_fd_clr.h
io.lo: /usr/include/sys/_types/_fd_set.h
io.lo: /usr/include/sys/_types/_fd_isset.h
io.lo: /usr/include/sys/_types/_fd_zero.h
io.lo: /usr/include/sys/_types/_fd_copy.h
io.lo: /usr/include/sys/_pthread/_pthread_cond_t.h
io.lo: /usr/include/sys/_pthread/_pthread_condattr_t.h
io.lo: /usr/include/sys/_pthread/_pthread_mutex_t.h
io.lo: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
io.lo: /usr/include/sys/_pthread/_pthread_once_t.h
io.lo: /usr/include/sys/_pthread/_pthread_rwlock_t.h
io.lo: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
io.lo: /usr/include/sys/_pthread/_pthread_t.h
io.lo: /usr/include/sys/_pthread/_pthread_key_t.h
io.lo: /usr/include/sys/_types/_fsblkcnt_t.h
io.lo: /usr/include/poll.h
io.lo: /usr/include/sys/_types/_fsfilcnt_t.h
io.lo: /usr/include/sys/socket.h
io.lo: /usr/include/sys/poll.h
io.lo: /usr/include/i386/_param.h
io.lo: /usr/include/machine/_param.h
io.lo: /usr/include/sys/_types/_sa_family_t.h
io.lo: /usr/include/net/net_kev.h
io.lo: /usr/include/sys/_types/_socklen_t.h
io.lo: /usr/include/sys/un.h
io.lo: /usr/include/sys/_types/_iovec_t.h
io.lo: /usr/include/sys/_types/_timespec.h
io.lo: /usr/include/sys/select.h
io.lo: /usr/include/netinet/in.h
io.lo: /usr/include/sys/_select.h
io.lo: /usr/include/netinet/tcp.h
io.lo: /usr/include/netinet6/in6.h
io.lo: /usr/include/arpa/nameser.h
io.lo: /usr/include/arpa/inet.h
io.lo: /usr/include/machine/param.h
io.lo: /usr/include/sys/param.h
io.lo: /usr/include/netdb.h
io.lo: /usr/include/resolv.h
io.lo: /usr/include/i386/param.h
io.lo: /usr/include/string.h
io.lo: /usr/include/strings.h
io.lo: ../../include/ac/string.h
io.lo: ../../include/ac/unistd.h
io.lo: /usr/include/secure/_string.h
io.lo: /usr/include/sys/unistd.h
io.lo: /usr/include/unistd.h
io.lo: /usr/include/sys/_types/_posix_vdisable.h
io.lo: /usr/include/sys/_types/_uuid_t.h
io.lo: /usr/include/sys/_types/_seek_set.h
io.lo: /usr/include/getopt.h
io.lo: /usr/include/gethostuuid.h
io.lo: lber-int.h
io.lo: ../../include/lber.h
io.lo: ../../include/lutil_lockf.h
io.lo: ../../include/ldap_log.h
io.lo: ../../include/lber_types.h
io.lo: ../../include/ldap_queue.h
io.lo: ../../include/lber_pvt.h
bprint.lo: ../../include/portable.h
bprint.lo: bprint.c
bprint.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
bprint.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
bprint.lo: ../../include/ldap_cdefs.h
bprint.lo: ../../include/ac/fdset.h
bprint.lo: ../../include/ac/assert.h
bprint.lo: ../../include/ldap_features.h
bprint.lo: /usr/include/sys/cdefs.h
bprint.lo: /usr/include/assert.h
bprint.lo: /usr/include/sys/_symbol_aliasing.h
bprint.lo: ../../include/ac/localize.h
bprint.lo: /usr/include/sys/_posix_availability.h
bprint.lo: /usr/include/Availability.h
bprint.lo: /usr/include/stdio.h
bprint.lo: /usr/include/_types.h
bprint.lo: /usr/include/AvailabilityInternal.h
bprint.lo: /usr/include/machine/_types.h
bprint.lo: /usr/include/sys/_types.h
bprint.lo: /usr/include/sys/_pthread/_pthread_types.h
bprint.lo: /usr/include/i386/_types.h
bprint.lo: /usr/include/sys/_types/_size_t.h
bprint.lo: /usr/include/sys/_types/_va_list.h
bprint.lo: /usr/include/sys/stdio.h
bprint.lo: /usr/include/sys/_types/_null.h
bprint.lo: /usr/include/sys/_types/_ssize_t.h
bprint.lo: /usr/include/sys/_types/_off_t.h
bprint.lo: /usr/include/secure/_common.h
bprint.lo: /usr/include/secure/_stdio.h
bprint.lo: /usr/include/ctype.h
bprint.lo: /usr/include/runetype.h
bprint.lo: ../../include/ac/ctype.h
bprint.lo: /usr/include/sys/_types/_rune_t.h
bprint.lo: /usr/include/sys/_types/_ct_rune_t.h
bprint.lo: /usr/include/sys/_types/_wint_t.h
bprint.lo: /usr/include/sys/_types/_wchar_t.h
bprint.lo: ../../include/ac/stdarg.h
bprint.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
bprint.lo: /usr/include/string.h
bprint.lo: ../../include/ac/string.h
bprint.lo: /usr/include/sys/_types/_errno_t.h
bprint.lo: /usr/include/sys/_types/_rsize_t.h
bprint.lo: /usr/include/secure/_string.h
bprint.lo: lber-int.h
bprint.lo: /usr/include/strings.h
bprint.lo: ../../include/lber_types.h
bprint.lo: ../../include/lber.h
bprint.lo: ../../include/lber_pvt.h
bprint.lo: ../../include/ldap_log.h
bprint.lo: ../../include/ldap_queue.h
debug.lo: ../../include/portable.h
debug.lo: debug.c
debug.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
debug.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
debug.lo: ../../include/ldap_cdefs.h
debug.lo: ../../include/ac/fdset.h
debug.lo: ../../include/ac/assert.h
debug.lo: ../../include/ldap_features.h
debug.lo: /usr/include/sys/cdefs.h
debug.lo: /usr/include/assert.h
debug.lo: /usr/include/sys/_symbol_aliasing.h
debug.lo: ../../include/ac/localize.h
debug.lo: /usr/include/sys/_posix_availability.h
debug.lo: /usr/include/Availability.h
debug.lo: /usr/include/stdio.h
debug.lo: /usr/include/_types.h
debug.lo: /usr/include/AvailabilityInternal.h
debug.lo: /usr/include/machine/_types.h
debug.lo: /usr/include/sys/_types.h
debug.lo: /usr/include/sys/_pthread/_pthread_types.h
debug.lo: /usr/include/i386/_types.h
debug.lo: /usr/include/sys/_types/_size_t.h
debug.lo: /usr/include/sys/_types/_va_list.h
debug.lo: /usr/include/sys/stdio.h
debug.lo: /usr/include/sys/_types/_null.h
debug.lo: /usr/include/sys/_types/_ssize_t.h
debug.lo: /usr/include/sys/_types/_off_t.h
debug.lo: /usr/include/secure/_common.h
debug.lo: /usr/include/secure/_stdio.h
debug.lo: ../../include/ac/stdarg.h
debug.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
debug.lo: /usr/include/stdlib.h
debug.lo: ../../include/ac/stdlib.h
debug.lo: /usr/include/sys/_types/_pid_t.h
debug.lo: /usr/include/sys/wait.h
debug.lo: /usr/include/sys/signal.h
debug.lo: /usr/include/sys/_types/_id_t.h
debug.lo: /usr/include/machine/signal.h
debug.lo: /usr/include/sys/appleapiopts.h
debug.lo: /usr/include/machine/_mcontext.h
debug.lo: /usr/include/i386/signal.h
debug.lo: /usr/include/mach/i386/_structs.h
debug.lo: /usr/include/i386/_mcontext.h
debug.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
debug.lo: /usr/include/sys/_types/_sigaltstack.h
debug.lo: /usr/include/sys/_types/_ucontext.h
debug.lo: /usr/include/sys/_types/_uid_t.h
debug.lo: /usr/include/sys/_types/_sigset_t.h
debug.lo: /usr/include/sys/resource.h
debug.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
debug.lo: /usr/include/sys/_types/_int8_t.h
debug.lo: /usr/include/stdint.h
debug.lo: /usr/include/sys/_types/_int32_t.h
debug.lo: /usr/include/sys/_types/_int16_t.h
debug.lo: /usr/include/_types/_uint8_t.h
debug.lo: /usr/include/sys/_types/_int64_t.h
debug.lo: /usr/include/_types/_uint32_t.h
debug.lo: /usr/include/_types/_uint16_t.h
debug.lo: /usr/include/sys/_types/_intptr_t.h
debug.lo: /usr/include/_types/_uint64_t.h
debug.lo: /usr/include/_types/_intmax_t.h
debug.lo: /usr/include/sys/_types/_uintptr_t.h
debug.lo: /usr/include/sys/_types/_timeval.h
debug.lo: /usr/include/_types/_uintmax_t.h
debug.lo: /usr/include/i386/endian.h
debug.lo: /usr/include/machine/endian.h
debug.lo: /usr/include/libkern/_OSByteOrder.h
debug.lo: /usr/include/sys/_endian.h
debug.lo: /usr/include/alloca.h
debug.lo: /usr/include/libkern/i386/_OSByteOrder.h
debug.lo: /usr/include/sys/_types/_rune_t.h
debug.lo: /usr/include/sys/_types/_ct_rune_t.h
debug.lo: /usr/include/machine/types.h
debug.lo: /usr/include/sys/_types/_wchar_t.h
debug.lo: /usr/include/sys/_types/_u_int8_t.h
debug.lo: /usr/include/i386/types.h
debug.lo: /usr/include/sys/_types/_u_int16_t.h
debug.lo: /usr/include/sys/_types/_u_int32_t.h
debug.lo: /usr/include/sys/_types/_dev_t.h
debug.lo: /usr/include/sys/_types/_u_int64_t.h
debug.lo: /usr/include/sys/_types/_mode_t.h
debug.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
debug.lo: /usr/include/machine/limits.h
debug.lo: /usr/include/limits.h
debug.lo: /usr/include/i386/_limits.h
debug.lo: /usr/include/i386/limits.h
debug.lo: ../../include/ac/string.h
debug.lo: /usr/include/sys/syslimits.h
debug.lo: /usr/include/sys/_types/_rsize_t.h
debug.lo: /usr/include/string.h
debug.lo: /usr/include/strings.h
debug.lo: /usr/include/sys/_types/_errno_t.h
debug.lo: ../../include/ac/time.h
debug.lo: /usr/include/secure/_string.h
debug.lo: /usr/include/sys/_types/_fd_def.h
debug.lo: /usr/include/sys/time.h
debug.lo: /usr/include/sys/_types/_timespec.h
debug.lo: /usr/include/sys/_types/_time_t.h
debug.lo: /usr/include/sys/_types/_timeval64.h
debug.lo: /usr/include/sys/_types/_suseconds_t.h
debug.lo: /usr/include/sys/_types/_fd_setsize.h
debug.lo: /usr/include/sys/_types/_fd_clr.h
debug.lo: /usr/include/sys/_types/_fd_set.h
debug.lo: /usr/include/sys/_types/_fd_zero.h
debug.lo: /usr/include/sys/_types/_fd_isset.h
debug.lo: /usr/include/time.h
debug.lo: /usr/include/sys/_types/_fd_copy.h
debug.lo: /usr/include/sys/_select.h
debug.lo: /usr/include/sys/_types/_clock_t.h
debug.lo: /usr/include/ctype.h
debug.lo: /usr/include/runetype.h
debug.lo: ../../include/ac/ctype.h
debug.lo: ../../include/ac/syslog.h
debug.lo: /usr/include/sys/_types/_wint_t.h
debug.lo: /usr/include/sys/syslog.h
debug.lo: /usr/include/syslog.h
debug.lo: ../../include/ldap_defaults.h
debug.lo: ../../include/ldap_log.h
debug.lo: ../../include/lber.h
debug.lo: ../../include/ldap_config.h
debug.lo: ../../include/ldap_pvt.h
debug.lo: ../../include/lber_types.h
debug.lo: ../../include/ldap_pvt_uc.h
debug.lo: ../../include/lber_pvt.h
debug.lo: ../../include/ac/bytes.h
debug.lo: ../../include/../libraries/liblunicode/ucdata/ucdata.h
memory.lo: ../../include/portable.h
memory.lo: memory.c
memory.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
memory.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
memory.lo: ../../include/ldap_cdefs.h
memory.lo: ../../include/ac/fdset.h
memory.lo: ../../include/ac/assert.h
memory.lo: ../../include/ldap_features.h
memory.lo: /usr/include/sys/cdefs.h
memory.lo: /usr/include/assert.h
memory.lo: /usr/include/sys/_symbol_aliasing.h
memory.lo: ../../include/ac/localize.h
memory.lo: /usr/include/sys/_posix_availability.h
memory.lo: /usr/include/stdlib.h
memory.lo: ../../include/ac/stdlib.h
memory.lo: /usr/include/AvailabilityInternal.h
memory.lo: /usr/include/Availability.h
memory.lo: /usr/include/sys/_types.h
memory.lo: /usr/include/_types.h
memory.lo: /usr/include/i386/_types.h
memory.lo: /usr/include/machine/_types.h
memory.lo: /usr/include/sys/wait.h
memory.lo: /usr/include/sys/_pthread/_pthread_types.h
memory.lo: /usr/include/sys/_types/_id_t.h
memory.lo: /usr/include/sys/_types/_pid_t.h
memory.lo: /usr/include/sys/appleapiopts.h
memory.lo: /usr/include/sys/signal.h
memory.lo: /usr/include/i386/signal.h
memory.lo: /usr/include/machine/signal.h
memory.lo: /usr/include/i386/_mcontext.h
memory.lo: /usr/include/machine/_mcontext.h
memory.lo: /usr/include/mach/i386/_structs.h
memory.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
memory.lo: /usr/include/sys/_types/_sigaltstack.h
memory.lo: /usr/include/sys/_types/_ucontext.h
memory.lo: /usr/include/sys/_types/_size_t.h
memory.lo: /usr/include/sys/_types/_sigset_t.h
memory.lo: /usr/include/sys/resource.h
memory.lo: /usr/include/sys/_types/_uid_t.h
memory.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
memory.lo: /usr/include/sys/_types/_int8_t.h
memory.lo: /usr/include/stdint.h
memory.lo: /usr/include/sys/_types/_int32_t.h
memory.lo: /usr/include/sys/_types/_int16_t.h
memory.lo: /usr/include/_types/_uint8_t.h
memory.lo: /usr/include/sys/_types/_int64_t.h
memory.lo: /usr/include/_types/_uint32_t.h
memory.lo: /usr/include/_types/_uint16_t.h
memory.lo: /usr/include/sys/_types/_intptr_t.h
memory.lo: /usr/include/_types/_uint64_t.h
memory.lo: /usr/include/_types/_intmax_t.h
memory.lo: /usr/include/sys/_types/_uintptr_t.h
memory.lo: /usr/include/sys/_types/_timeval.h
memory.lo: /usr/include/_types/_uintmax_t.h
memory.lo: /usr/include/i386/endian.h
memory.lo: /usr/include/machine/endian.h
memory.lo: /usr/include/libkern/_OSByteOrder.h
memory.lo: /usr/include/sys/_endian.h
memory.lo: /usr/include/alloca.h
memory.lo: /usr/include/libkern/i386/_OSByteOrder.h
memory.lo: /usr/include/sys/_types/_rune_t.h
memory.lo: /usr/include/sys/_types/_ct_rune_t.h
memory.lo: /usr/include/sys/_types/_null.h
memory.lo: /usr/include/sys/_types/_wchar_t.h
memory.lo: /usr/include/i386/types.h
memory.lo: /usr/include/machine/types.h
memory.lo: /usr/include/sys/_types/_u_int8_t.h
memory.lo: /usr/include/sys/_types/_u_int16_t.h
memory.lo: /usr/include/sys/_types/_u_int32_t.h
memory.lo: /usr/include/sys/_types/_dev_t.h
memory.lo: /usr/include/sys/_types/_u_int64_t.h
memory.lo: /usr/include/sys/_types/_mode_t.h
memory.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
memory.lo: /usr/include/machine/limits.h
memory.lo: /usr/include/limits.h
memory.lo: /usr/include/i386/_limits.h
memory.lo: /usr/include/i386/limits.h
memory.lo: ../../include/ac/string.h
memory.lo: /usr/include/sys/syslimits.h
memory.lo: /usr/include/sys/_types/_rsize_t.h
memory.lo: /usr/include/string.h
memory.lo: /usr/include/sys/_types/_ssize_t.h
memory.lo: /usr/include/sys/_types/_errno_t.h
memory.lo: /usr/include/secure/_string.h
memory.lo: /usr/include/strings.h
memory.lo: lber-int.h
memory.lo: ../../include/lber.h
memory.lo: /usr/include/secure/_common.h
memory.lo: ../../include/ldap_log.h
memory.lo: ../../include/lber_types.h
memory.lo: /usr/include/sys/_types/_va_list.h
memory.lo: /usr/include/stdio.h
memory.lo: /usr/include/sys/_types/_off_t.h
memory.lo: /usr/include/sys/stdio.h
memory.lo: ../../include/lber_pvt.h
memory.lo: /usr/include/secure/_stdio.h
memory.lo: ../../include/ldap_queue.h
options.lo: ../../include/portable.h
options.lo: options.c
options.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
options.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
options.lo: ../../include/ldap_cdefs.h
options.lo: ../../include/ac/fdset.h
options.lo: ../../include/ac/assert.h
options.lo: ../../include/ldap_features.h
options.lo: /usr/include/sys/cdefs.h
options.lo: /usr/include/assert.h
options.lo: /usr/include/sys/_symbol_aliasing.h
options.lo: ../../include/ac/localize.h
options.lo: /usr/include/sys/_posix_availability.h
options.lo: /usr/include/stdlib.h
options.lo: ../../include/ac/stdlib.h
options.lo: /usr/include/AvailabilityInternal.h
options.lo: /usr/include/Availability.h
options.lo: /usr/include/sys/_types.h
options.lo: /usr/include/_types.h
options.lo: /usr/include/i386/_types.h
options.lo: /usr/include/machine/_types.h
options.lo: /usr/include/sys/wait.h
options.lo: /usr/include/sys/_pthread/_pthread_types.h
options.lo: /usr/include/sys/_types/_id_t.h
options.lo: /usr/include/sys/_types/_pid_t.h
options.lo: /usr/include/sys/appleapiopts.h
options.lo: /usr/include/sys/signal.h
options.lo: /usr/include/i386/signal.h
options.lo: /usr/include/machine/signal.h
options.lo: /usr/include/i386/_mcontext.h
options.lo: /usr/include/machine/_mcontext.h
options.lo: /usr/include/mach/i386/_structs.h
options.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
options.lo: /usr/include/sys/_types/_sigaltstack.h
options.lo: /usr/include/sys/_types/_ucontext.h
options.lo: /usr/include/sys/_types/_size_t.h
options.lo: /usr/include/sys/_types/_sigset_t.h
options.lo: /usr/include/sys/resource.h
options.lo: /usr/include/sys/_types/_uid_t.h
options.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
options.lo: /usr/include/sys/_types/_int8_t.h
options.lo: /usr/include/stdint.h
options.lo: /usr/include/sys/_types/_int32_t.h
options.lo: /usr/include/sys/_types/_int16_t.h
options.lo: /usr/include/_types/_uint8_t.h
options.lo: /usr/include/sys/_types/_int64_t.h
options.lo: /usr/include/_types/_uint32_t.h
options.lo: /usr/include/_types/_uint16_t.h
options.lo: /usr/include/sys/_types/_intptr_t.h
options.lo: /usr/include/_types/_uint64_t.h
options.lo: /usr/include/_types/_intmax_t.h
options.lo: /usr/include/sys/_types/_uintptr_t.h
options.lo: /usr/include/sys/_types/_timeval.h
options.lo: /usr/include/_types/_uintmax_t.h
options.lo: /usr/include/i386/endian.h
options.lo: /usr/include/machine/endian.h
options.lo: /usr/include/libkern/_OSByteOrder.h
options.lo: /usr/include/sys/_endian.h
options.lo: /usr/include/alloca.h
options.lo: /usr/include/libkern/i386/_OSByteOrder.h
options.lo: /usr/include/sys/_types/_rune_t.h
options.lo: /usr/include/sys/_types/_ct_rune_t.h
options.lo: /usr/include/sys/_types/_null.h
options.lo: /usr/include/sys/_types/_wchar_t.h
options.lo: /usr/include/i386/types.h
options.lo: /usr/include/machine/types.h
options.lo: /usr/include/sys/_types/_u_int8_t.h
options.lo: /usr/include/sys/_types/_u_int16_t.h
options.lo: /usr/include/sys/_types/_u_int32_t.h
options.lo: /usr/include/sys/_types/_dev_t.h
options.lo: /usr/include/sys/_types/_u_int64_t.h
options.lo: /usr/include/sys/_types/_mode_t.h
options.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
options.lo: /usr/include/machine/limits.h
options.lo: /usr/include/limits.h
options.lo: /usr/include/i386/_limits.h
options.lo: /usr/include/i386/limits.h
options.lo: ../../include/ac/string.h
options.lo: /usr/include/sys/syslimits.h
options.lo: /usr/include/sys/_types/_rsize_t.h
options.lo: /usr/include/string.h
options.lo: /usr/include/sys/_types/_ssize_t.h
options.lo: /usr/include/sys/_types/_errno_t.h
options.lo: /usr/include/secure/_string.h
options.lo: /usr/include/strings.h
options.lo: ../../include/ac/stdarg.h
options.lo: /usr/include/secure/_common.h
options.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
options.lo: ../../include/lber.h
options.lo: ../../include/lber_types.h
options.lo: lber-int.h
options.lo: /usr/include/stdio.h
options.lo: ../../include/ldap_log.h
options.lo: /usr/include/sys/stdio.h
options.lo: /usr/include/sys/_types/_va_list.h
options.lo: /usr/include/secure/_stdio.h
options.lo: /usr/include/sys/_types/_off_t.h
options.lo: ../../include/ldap_queue.h
options.lo: ../../include/lber_pvt.h
sockbuf.lo: ../../include/portable.h
sockbuf.lo: sockbuf.c
sockbuf.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
sockbuf.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
sockbuf.lo: ../../include/ldap_cdefs.h
sockbuf.lo: ../../include/ac/fdset.h
sockbuf.lo: ../../include/ac/assert.h
sockbuf.lo: ../../include/ldap_features.h
sockbuf.lo: /usr/include/sys/cdefs.h
sockbuf.lo: /usr/include/assert.h
sockbuf.lo: /usr/include/sys/_symbol_aliasing.h
sockbuf.lo: ../../include/ac/localize.h
sockbuf.lo: /usr/include/sys/_posix_availability.h
sockbuf.lo: /usr/include/Availability.h
sockbuf.lo: /usr/include/stdio.h
sockbuf.lo: /usr/include/_types.h
sockbuf.lo: /usr/include/AvailabilityInternal.h
sockbuf.lo: /usr/include/machine/_types.h
sockbuf.lo: /usr/include/sys/_types.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_types.h
sockbuf.lo: /usr/include/i386/_types.h
sockbuf.lo: /usr/include/sys/_types/_size_t.h
sockbuf.lo: /usr/include/sys/_types/_va_list.h
sockbuf.lo: /usr/include/sys/stdio.h
sockbuf.lo: /usr/include/sys/_types/_null.h
sockbuf.lo: /usr/include/sys/_types/_ssize_t.h
sockbuf.lo: /usr/include/sys/_types/_off_t.h
sockbuf.lo: /usr/include/secure/_common.h
sockbuf.lo: /usr/include/secure/_stdio.h
sockbuf.lo: /usr/include/stdlib.h
sockbuf.lo: ../../include/ac/stdlib.h
sockbuf.lo: /usr/include/sys/_types/_pid_t.h
sockbuf.lo: /usr/include/sys/wait.h
sockbuf.lo: /usr/include/sys/signal.h
sockbuf.lo: /usr/include/sys/_types/_id_t.h
sockbuf.lo: /usr/include/machine/signal.h
sockbuf.lo: /usr/include/sys/appleapiopts.h
sockbuf.lo: /usr/include/machine/_mcontext.h
sockbuf.lo: /usr/include/i386/signal.h
sockbuf.lo: /usr/include/mach/i386/_structs.h
sockbuf.lo: /usr/include/i386/_mcontext.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_attr_t.h
sockbuf.lo: /usr/include/sys/_types/_sigaltstack.h
sockbuf.lo: /usr/include/sys/_types/_ucontext.h
sockbuf.lo: /usr/include/sys/_types/_uid_t.h
sockbuf.lo: /usr/include/sys/_types/_sigset_t.h
sockbuf.lo: /usr/include/sys/resource.h
sockbuf.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
sockbuf.lo: /usr/include/sys/_types/_int8_t.h
sockbuf.lo: /usr/include/stdint.h
sockbuf.lo: /usr/include/sys/_types/_int32_t.h
sockbuf.lo: /usr/include/sys/_types/_int16_t.h
sockbuf.lo: /usr/include/_types/_uint8_t.h
sockbuf.lo: /usr/include/sys/_types/_int64_t.h
sockbuf.lo: /usr/include/_types/_uint32_t.h
sockbuf.lo: /usr/include/_types/_uint16_t.h
sockbuf.lo: /usr/include/sys/_types/_intptr_t.h
sockbuf.lo: /usr/include/_types/_uint64_t.h
sockbuf.lo: /usr/include/_types/_intmax_t.h
sockbuf.lo: /usr/include/sys/_types/_uintptr_t.h
sockbuf.lo: /usr/include/sys/_types/_timeval.h
sockbuf.lo: /usr/include/_types/_uintmax_t.h
sockbuf.lo: /usr/include/i386/endian.h
sockbuf.lo: /usr/include/machine/endian.h
sockbuf.lo: /usr/include/libkern/_OSByteOrder.h
sockbuf.lo: /usr/include/sys/_endian.h
sockbuf.lo: /usr/include/alloca.h
sockbuf.lo: /usr/include/libkern/i386/_OSByteOrder.h
sockbuf.lo: /usr/include/sys/_types/_rune_t.h
sockbuf.lo: /usr/include/sys/_types/_ct_rune_t.h
sockbuf.lo: /usr/include/machine/types.h
sockbuf.lo: /usr/include/sys/_types/_wchar_t.h
sockbuf.lo: /usr/include/sys/_types/_u_int8_t.h
sockbuf.lo: /usr/include/i386/types.h
sockbuf.lo: /usr/include/sys/_types/_u_int16_t.h
sockbuf.lo: /usr/include/sys/_types/_u_int32_t.h
sockbuf.lo: /usr/include/sys/_types/_dev_t.h
sockbuf.lo: /usr/include/sys/_types/_u_int64_t.h
sockbuf.lo: /usr/include/sys/_types/_mode_t.h
sockbuf.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
sockbuf.lo: /usr/include/machine/limits.h
sockbuf.lo: /usr/include/limits.h
sockbuf.lo: /usr/include/i386/_limits.h
sockbuf.lo: /usr/include/i386/limits.h
sockbuf.lo: ../../include/ac/ctype.h
sockbuf.lo: /usr/include/sys/syslimits.h
sockbuf.lo: /usr/include/runetype.h
sockbuf.lo: /usr/include/ctype.h
sockbuf.lo: ../../include/ac/errno.h
sockbuf.lo: /usr/include/sys/_types/_wint_t.h
sockbuf.lo: /usr/include/sys/errno.h
sockbuf.lo: /usr/include/errno.h
sockbuf.lo: ../../include/ac/socket.h
sockbuf.lo: /usr/include/sys/_types/_errno_t.h
sockbuf.lo: /usr/include/sys/_types/_blkcnt_t.h
sockbuf.lo: /usr/include/sys/types.h
sockbuf.lo: /usr/include/sys/_types/_gid_t.h
sockbuf.lo: /usr/include/sys/_types/_blksize_t.h
sockbuf.lo: /usr/include/sys/_types/_in_addr_t.h
sockbuf.lo: /usr/include/sys/_types/_ino_t.h
sockbuf.lo: /usr/include/sys/_types/_in_port_t.h
sockbuf.lo: /usr/include/sys/_types/_key_t.h
sockbuf.lo: /usr/include/sys/_types/_ino64_t.h
sockbuf.lo: /usr/include/sys/_types/_clock_t.h
sockbuf.lo: /usr/include/sys/_types/_nlink_t.h
sockbuf.lo: /usr/include/sys/_types/_time_t.h
sockbuf.lo: /usr/include/sys/_types/_useconds_t.h
sockbuf.lo: /usr/include/sys/_types/_suseconds_t.h
sockbuf.lo: /usr/include/sys/_types/_fd_def.h
sockbuf.lo: /usr/include/sys/_types/_rsize_t.h
sockbuf.lo: /usr/include/sys/_types/_fd_setsize.h
sockbuf.lo: /usr/include/sys/_types/_fd_clr.h
sockbuf.lo: /usr/include/sys/_types/_fd_set.h
sockbuf.lo: /usr/include/sys/_types/_fd_isset.h
sockbuf.lo: /usr/include/sys/_types/_fd_zero.h
sockbuf.lo: /usr/include/sys/_types/_fd_copy.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_cond_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_condattr_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_mutex_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_once_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_rwlock_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_t.h
sockbuf.lo: /usr/include/sys/_pthread/_pthread_key_t.h
sockbuf.lo: /usr/include/sys/_types/_fsblkcnt_t.h
sockbuf.lo: /usr/include/poll.h
sockbuf.lo: /usr/include/sys/_types/_fsfilcnt_t.h
sockbuf.lo: /usr/include/sys/socket.h
sockbuf.lo: /usr/include/sys/poll.h
sockbuf.lo: /usr/include/i386/_param.h
sockbuf.lo: /usr/include/machine/_param.h
sockbuf.lo: /usr/include/sys/_types/_sa_family_t.h
sockbuf.lo: /usr/include/net/net_kev.h
sockbuf.lo: /usr/include/sys/_types/_socklen_t.h
sockbuf.lo: /usr/include/sys/un.h
sockbuf.lo: /usr/include/sys/_types/_iovec_t.h
sockbuf.lo: /usr/include/sys/_types/_timespec.h
sockbuf.lo: /usr/include/sys/select.h
sockbuf.lo: /usr/include/netinet/in.h
sockbuf.lo: /usr/include/sys/_select.h
sockbuf.lo: /usr/include/netinet/tcp.h
sockbuf.lo: /usr/include/netinet6/in6.h
sockbuf.lo: /usr/include/arpa/nameser.h
sockbuf.lo: /usr/include/arpa/inet.h
sockbuf.lo: /usr/include/machine/param.h
sockbuf.lo: /usr/include/sys/param.h
sockbuf.lo: /usr/include/netdb.h
sockbuf.lo: /usr/include/resolv.h
sockbuf.lo: /usr/include/i386/param.h
sockbuf.lo: /usr/include/string.h
sockbuf.lo: /usr/include/strings.h
sockbuf.lo: ../../include/ac/string.h
sockbuf.lo: ../../include/ac/unistd.h
sockbuf.lo: /usr/include/secure/_string.h
sockbuf.lo: /usr/include/sys/unistd.h
sockbuf.lo: /usr/include/unistd.h
sockbuf.lo: /usr/include/sys/_types/_posix_vdisable.h
sockbuf.lo: /usr/include/sys/_types/_uuid_t.h
sockbuf.lo: /usr/include/sys/_types/_seek_set.h
sockbuf.lo: /usr/include/getopt.h
sockbuf.lo: /usr/include/gethostuuid.h
sockbuf.lo: /usr/include/fcntl.h
sockbuf.lo: ../../include/lutil_lockf.h
sockbuf.lo: /usr/include/sys/_types/_o_sync.h
sockbuf.lo: /usr/include/sys/fcntl.h
sockbuf.lo: /usr/include/sys/_types/_s_ifmt.h
sockbuf.lo: /usr/include/sys/_types/_o_dsync.h
sockbuf.lo: /usr/include/sys/filio.h
sockbuf.lo: /usr/include/sys/_types/_filesec_t.h
sockbuf.lo: lber-int.h
sockbuf.lo: ../../include/lber.h
sockbuf.lo: /usr/include/sys/ioccom.h
sockbuf.lo: ../../include/ldap_log.h
sockbuf.lo: ../../include/lber_types.h
sockbuf.lo: ../../include/ldap_queue.h
sockbuf.lo: ../../include/lber_pvt.h
stdio.lo: ../../include/portable.h
stdio.lo: stdio.c
stdio.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
stdio.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
stdio.lo: ../../include/ldap_cdefs.h
stdio.lo: ../../include/ac/fdset.h
stdio.lo: ../../include/ac/assert.h
stdio.lo: ../../include/ldap_features.h
stdio.lo: /usr/include/sys/cdefs.h
stdio.lo: /usr/include/assert.h
stdio.lo: /usr/include/sys/_symbol_aliasing.h
stdio.lo: ../../include/ac/localize.h
stdio.lo: /usr/include/sys/_posix_availability.h
stdio.lo: /usr/include/Availability.h
stdio.lo: /usr/include/stdio.h
stdio.lo: /usr/include/_types.h
stdio.lo: /usr/include/AvailabilityInternal.h
stdio.lo: /usr/include/machine/_types.h
stdio.lo: /usr/include/sys/_types.h
stdio.lo: /usr/include/sys/_pthread/_pthread_types.h
stdio.lo: /usr/include/i386/_types.h
stdio.lo: /usr/include/sys/_types/_size_t.h
stdio.lo: /usr/include/sys/_types/_va_list.h
stdio.lo: /usr/include/sys/stdio.h
stdio.lo: /usr/include/sys/_types/_null.h
stdio.lo: /usr/include/sys/_types/_ssize_t.h
stdio.lo: /usr/include/sys/_types/_off_t.h
stdio.lo: /usr/include/secure/_common.h
stdio.lo: /usr/include/secure/_stdio.h
stdio.lo: ../../include/ac/stdarg.h
stdio.lo: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
stdio.lo: /usr/include/string.h
stdio.lo: ../../include/ac/string.h
stdio.lo: /usr/include/sys/_types/_errno_t.h
stdio.lo: /usr/include/sys/_types/_rsize_t.h
stdio.lo: /usr/include/secure/_string.h
stdio.lo: /usr/include/strings.h
stdio.lo: /usr/include/ctype.h
stdio.lo: /usr/include/runetype.h
stdio.lo: ../../include/ac/ctype.h
stdio.lo: /usr/include/sys/_types/_rune_t.h
stdio.lo: /usr/include/sys/_types/_ct_rune_t.h
stdio.lo: /usr/include/sys/_types/_wint_t.h
stdio.lo: /usr/include/sys/_types/_wchar_t.h
stdio.lo: ../../include/lber_types.h
stdio.lo: ../../include/lutil.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
