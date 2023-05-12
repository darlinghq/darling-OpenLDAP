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

# Makefile for -llutil
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

LIBRARY	= liblutil.a
PROGRAM = testavl

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

NT_SRCS = ntservice.c
NT_OBJS = ntservice.o slapdmsg.res

UNIX_SRCS = detach.c
UNIX_OBJS = detach.o

XLIBS = $(LIBRARY) $(LDAP_LIBLBER_LA)

SRCS	= base64.c entropy.c sasl.c signal.c hash.c passfile.c \
	md5.c passwd.c sha1.c getpass.c lockf.c utils.c uuid.c sockpair.c \
	avl.c tavl.c \
	testavl.c \
	meter.c \
	 setproctitle.c $(UNIX_SRCS)

OBJS	= base64.o entropy.o sasl.o signal.o hash.o passfile.o \
	md5.o passwd.o sha1.o getpass.o lockf.o utils.o uuid.o sockpair.o \
	avl.o tavl.o \
	meter.o \
	 ${LIBOBJDIR}setproctitle$U.o $(UNIX_OBJS)

testavl: $(XLIBS) testavl.o
	(LTLINK) -o $@ testavl.o $(LIBS)

testtavl: $(XLIBS) testtavl.o
	(LTLINK) -o $@ testtavl.o $(LIBS)

# These rules are for a Mingw32 build, specifically.
# It's ok for them to be here because the clean rule is harmless, and
# slapdmsg.res won't get built unless it's declared in OBJS.

slapdmsg.bin: FORCE
	@if [ ! -f $@ ]; then cp $(srcdir)/$@ .; fi

slapdmsg.res: slapdmsg.rc slapdmsg.bin
	windres $< -O coff -o $@

clean-local:
	$(RM) *.res

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
# files: -I../../include -I../../include base64.c entropy.c sasl.c signal.c hash.c passfile.c md5.c passwd.c sha1.c getpass.c lockf.c utils.c uuid.c sockpair.c avl.c tavl.c testavl.c meter.c setproctitle.c detach.c
# command: cc -M -I.  -I../../include -I../../include base64.c entropy.c sasl.c signal.c hash.c passfile.c md5.c passwd.c sha1.c getpass.c lockf.c utils.c uuid.c sockpair.c avl.c tavl.c testavl.c meter.c setproctitle.c detach.c
#

base64.o: ../../include/portable.h
base64.o: base64.c
base64.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
base64.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
base64.o: ../../include/ldap_cdefs.h
base64.o: ../../include/ac/fdset.h
base64.o: ../../include/ac/assert.h
base64.o: ../../include/ldap_features.h
base64.o: /usr/include/sys/cdefs.h
base64.o: /usr/include/assert.h
base64.o: /usr/include/sys/_symbol_aliasing.h
base64.o: ../../include/ac/localize.h
base64.o: /usr/include/sys/_posix_availability.h
base64.o: /usr/include/stdlib.h
base64.o: ../../include/ac/stdlib.h
base64.o: /usr/include/AvailabilityInternal.h
base64.o: /usr/include/Availability.h
base64.o: /usr/include/sys/_types.h
base64.o: /usr/include/_types.h
base64.o: /usr/include/i386/_types.h
base64.o: /usr/include/machine/_types.h
base64.o: /usr/include/sys/wait.h
base64.o: /usr/include/sys/_pthread/_pthread_types.h
base64.o: /usr/include/sys/_types/_id_t.h
base64.o: /usr/include/sys/_types/_pid_t.h
base64.o: /usr/include/sys/appleapiopts.h
base64.o: /usr/include/sys/signal.h
base64.o: /usr/include/i386/signal.h
base64.o: /usr/include/machine/signal.h
base64.o: /usr/include/i386/_mcontext.h
base64.o: /usr/include/machine/_mcontext.h
base64.o: /usr/include/mach/i386/_structs.h
base64.o: /usr/include/sys/_pthread/_pthread_attr_t.h
base64.o: /usr/include/sys/_types/_sigaltstack.h
base64.o: /usr/include/sys/_types/_ucontext.h
base64.o: /usr/include/sys/_types/_size_t.h
base64.o: /usr/include/sys/_types/_sigset_t.h
base64.o: /usr/include/sys/resource.h
base64.o: /usr/include/sys/_types/_uid_t.h
base64.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
base64.o: /usr/include/sys/_types/_int8_t.h
base64.o: /usr/include/stdint.h
base64.o: /usr/include/sys/_types/_int32_t.h
base64.o: /usr/include/sys/_types/_int16_t.h
base64.o: /usr/include/_types/_uint8_t.h
base64.o: /usr/include/sys/_types/_int64_t.h
base64.o: /usr/include/_types/_uint32_t.h
base64.o: /usr/include/_types/_uint16_t.h
base64.o: /usr/include/sys/_types/_intptr_t.h
base64.o: /usr/include/_types/_uint64_t.h
base64.o: /usr/include/_types/_intmax_t.h
base64.o: /usr/include/sys/_types/_uintptr_t.h
base64.o: /usr/include/sys/_types/_timeval.h
base64.o: /usr/include/_types/_uintmax_t.h
base64.o: /usr/include/i386/endian.h
base64.o: /usr/include/machine/endian.h
base64.o: /usr/include/libkern/_OSByteOrder.h
base64.o: /usr/include/sys/_endian.h
base64.o: /usr/include/alloca.h
base64.o: /usr/include/libkern/i386/_OSByteOrder.h
base64.o: /usr/include/sys/_types/_rune_t.h
base64.o: /usr/include/sys/_types/_ct_rune_t.h
base64.o: /usr/include/sys/_types/_null.h
base64.o: /usr/include/sys/_types/_wchar_t.h
base64.o: /usr/include/i386/types.h
base64.o: /usr/include/machine/types.h
base64.o: /usr/include/sys/_types/_u_int8_t.h
base64.o: /usr/include/sys/_types/_u_int16_t.h
base64.o: /usr/include/sys/_types/_u_int32_t.h
base64.o: /usr/include/sys/_types/_dev_t.h
base64.o: /usr/include/sys/_types/_u_int64_t.h
base64.o: /usr/include/sys/_types/_mode_t.h
base64.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
base64.o: /usr/include/machine/limits.h
base64.o: /usr/include/limits.h
base64.o: /usr/include/i386/_limits.h
base64.o: /usr/include/i386/limits.h
base64.o: ../../include/ac/ctype.h
base64.o: /usr/include/sys/syslimits.h
base64.o: /usr/include/runetype.h
base64.o: /usr/include/ctype.h
base64.o: ../../include/ac/string.h
base64.o: /usr/include/sys/_types/_wint_t.h
base64.o: /usr/include/sys/_types/_rsize_t.h
base64.o: /usr/include/string.h
base64.o: /usr/include/sys/_types/_ssize_t.h
base64.o: /usr/include/sys/_types/_errno_t.h
base64.o: /usr/include/secure/_string.h
base64.o: /usr/include/strings.h
base64.o: ../../include/ac/socket.h
base64.o: /usr/include/secure/_common.h
base64.o: /usr/include/sys/_types/_blkcnt_t.h
base64.o: /usr/include/sys/types.h
base64.o: /usr/include/sys/_types/_gid_t.h
base64.o: /usr/include/sys/_types/_blksize_t.h
base64.o: /usr/include/sys/_types/_in_addr_t.h
base64.o: /usr/include/sys/_types/_ino_t.h
base64.o: /usr/include/sys/_types/_in_port_t.h
base64.o: /usr/include/sys/_types/_key_t.h
base64.o: /usr/include/sys/_types/_ino64_t.h
base64.o: /usr/include/sys/_types/_off_t.h
base64.o: /usr/include/sys/_types/_nlink_t.h
base64.o: /usr/include/sys/_types/_time_t.h
base64.o: /usr/include/sys/_types/_clock_t.h
base64.o: /usr/include/sys/_types/_useconds_t.h
base64.o: /usr/include/sys/_types/_suseconds_t.h
base64.o: /usr/include/sys/_types/_fd_def.h
base64.o: /usr/include/sys/_types/_fd_setsize.h
base64.o: /usr/include/sys/_types/_fd_clr.h
base64.o: /usr/include/sys/_types/_fd_set.h
base64.o: /usr/include/sys/_types/_fd_isset.h
base64.o: /usr/include/sys/_types/_fd_zero.h
base64.o: /usr/include/sys/_types/_fd_copy.h
base64.o: /usr/include/sys/_pthread/_pthread_cond_t.h
base64.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
base64.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
base64.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
base64.o: /usr/include/sys/_pthread/_pthread_once_t.h
base64.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
base64.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
base64.o: /usr/include/sys/_pthread/_pthread_t.h
base64.o: /usr/include/sys/_pthread/_pthread_key_t.h
base64.o: /usr/include/sys/_types/_fsblkcnt_t.h
base64.o: /usr/include/poll.h
base64.o: /usr/include/sys/_types/_fsfilcnt_t.h
base64.o: /usr/include/sys/socket.h
base64.o: /usr/include/sys/poll.h
base64.o: /usr/include/i386/_param.h
base64.o: /usr/include/machine/_param.h
base64.o: /usr/include/sys/_types/_sa_family_t.h
base64.o: /usr/include/net/net_kev.h
base64.o: /usr/include/sys/_types/_socklen_t.h
base64.o: /usr/include/sys/un.h
base64.o: /usr/include/sys/_types/_iovec_t.h
base64.o: /usr/include/sys/_types/_timespec.h
base64.o: /usr/include/sys/select.h
base64.o: /usr/include/netinet/in.h
base64.o: /usr/include/sys/_select.h
base64.o: /usr/include/netinet/tcp.h
base64.o: /usr/include/netinet6/in6.h
base64.o: /usr/include/arpa/nameser.h
base64.o: /usr/include/arpa/inet.h
base64.o: /usr/include/machine/param.h
base64.o: /usr/include/sys/param.h
base64.o: /usr/include/netdb.h
base64.o: /usr/include/resolv.h
base64.o: /usr/include/i386/param.h
base64.o: /usr/include/sys/_types/_va_list.h
base64.o: /usr/include/stdio.h
base64.o: /usr/include/secure/_stdio.h
base64.o: /usr/include/sys/stdio.h
base64.o: ../../include/lber_types.h
base64.o: ../../include/lutil.h
entropy.o: ../../include/portable.h
entropy.o: entropy.c
entropy.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
entropy.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
entropy.o: ../../include/ldap_cdefs.h
entropy.o: ../../include/ac/fdset.h
entropy.o: ../../include/ac/assert.h
entropy.o: ../../include/ldap_features.h
entropy.o: /usr/include/sys/cdefs.h
entropy.o: /usr/include/assert.h
entropy.o: /usr/include/sys/_symbol_aliasing.h
entropy.o: ../../include/ac/localize.h
entropy.o: /usr/include/sys/_posix_availability.h
entropy.o: /usr/include/string.h
entropy.o: /usr/include/_types.h
entropy.o: ../../include/ac/string.h
entropy.o: /usr/include/machine/_types.h
entropy.o: /usr/include/sys/_types.h
entropy.o: /usr/include/sys/_pthread/_pthread_types.h
entropy.o: /usr/include/i386/_types.h
entropy.o: /usr/include/AvailabilityInternal.h
entropy.o: /usr/include/Availability.h
entropy.o: /usr/include/sys/_types/_null.h
entropy.o: /usr/include/sys/_types/_size_t.h
entropy.o: /usr/include/sys/_types/_errno_t.h
entropy.o: /usr/include/sys/_types/_rsize_t.h
entropy.o: /usr/include/strings.h
entropy.o: /usr/include/sys/_types/_ssize_t.h
entropy.o: /usr/include/secure/_common.h
entropy.o: /usr/include/secure/_string.h
entropy.o: /usr/include/sys/time.h
entropy.o: ../../include/ac/time.h
entropy.o: /usr/include/sys/_types/_timespec.h
entropy.o: /usr/include/sys/_types/_fd_def.h
entropy.o: /usr/include/sys/_types/_timeval.h
entropy.o: /usr/include/sys/_types/_time_t.h
entropy.o: /usr/include/sys/_types/_timeval64.h
entropy.o: /usr/include/sys/_types/_suseconds_t.h
entropy.o: /usr/include/sys/_types/_fd_setsize.h
entropy.o: /usr/include/sys/_types/_fd_clr.h
entropy.o: /usr/include/sys/_types/_fd_set.h
entropy.o: /usr/include/sys/_types/_fd_zero.h
entropy.o: /usr/include/sys/_types/_fd_isset.h
entropy.o: /usr/include/time.h
entropy.o: /usr/include/sys/_types/_fd_copy.h
entropy.o: /usr/include/sys/_select.h
entropy.o: /usr/include/sys/_types/_clock_t.h
entropy.o: /usr/include/sys/types.h
entropy.o: ../../include/ac/unistd.h
entropy.o: /usr/include/machine/types.h
entropy.o: /usr/include/sys/appleapiopts.h
entropy.o: /usr/include/sys/_types/_int8_t.h
entropy.o: /usr/include/i386/types.h
entropy.o: /usr/include/sys/_types/_int32_t.h
entropy.o: /usr/include/sys/_types/_int16_t.h
entropy.o: /usr/include/sys/_types/_u_int8_t.h
entropy.o: /usr/include/sys/_types/_int64_t.h
entropy.o: /usr/include/sys/_types/_u_int16_t.h
entropy.o: /usr/include/sys/_types/_u_int32_t.h
entropy.o: /usr/include/sys/_types/_u_int64_t.h
entropy.o: /usr/include/sys/_types/_intptr_t.h
entropy.o: /usr/include/machine/endian.h
entropy.o: /usr/include/sys/_types/_uintptr_t.h
entropy.o: /usr/include/sys/_endian.h
entropy.o: /usr/include/i386/endian.h
entropy.o: /usr/include/libkern/_OSByteOrder.h
entropy.o: /usr/include/libkern/i386/_OSByteOrder.h
entropy.o: /usr/include/sys/_types/_blkcnt_t.h
entropy.o: /usr/include/sys/_types/_dev_t.h
entropy.o: /usr/include/sys/_types/_gid_t.h
entropy.o: /usr/include/sys/_types/_blksize_t.h
entropy.o: /usr/include/sys/_types/_in_addr_t.h
entropy.o: /usr/include/sys/_types/_ino_t.h
entropy.o: /usr/include/sys/_types/_in_port_t.h
entropy.o: /usr/include/sys/_types/_key_t.h
entropy.o: /usr/include/sys/_types/_ino64_t.h
entropy.o: /usr/include/sys/_types/_nlink_t.h
entropy.o: /usr/include/sys/_types/_mode_t.h
entropy.o: /usr/include/sys/_types/_pid_t.h
entropy.o: /usr/include/sys/_types/_id_t.h
entropy.o: /usr/include/sys/_types/_uid_t.h
entropy.o: /usr/include/sys/_types/_off_t.h
entropy.o: /usr/include/sys/_types/_useconds_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_attr_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_cond_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_once_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_t.h
entropy.o: /usr/include/sys/_pthread/_pthread_key_t.h
entropy.o: /usr/include/sys/_types/_fsblkcnt_t.h
entropy.o: /usr/include/unistd.h
entropy.o: /usr/include/sys/_types/_fsfilcnt_t.h
entropy.o: /usr/include/sys/_types/_posix_vdisable.h
entropy.o: /usr/include/sys/unistd.h
entropy.o: /usr/include/_types/_uint64_t.h
entropy.o: /usr/include/sys/_types/_seek_set.h
entropy.o: /usr/include/sys/_types/_sigset_t.h
entropy.o: /usr/include/sys/select.h
entropy.o: /usr/include/gethostuuid.h
entropy.o: /usr/include/sys/_types/_uuid_t.h
entropy.o: ../../include/lutil_lockf.h
entropy.o: /usr/include/fcntl.h
entropy.o: /usr/include/getopt.h
entropy.o: /usr/include/sys/_types/_o_sync.h
entropy.o: /usr/include/sys/fcntl.h
entropy.o: /usr/include/sys/_types/_s_ifmt.h
entropy.o: /usr/include/sys/_types/_o_dsync.h
entropy.o: ../../include/lutil.h
entropy.o: /usr/include/sys/_types/_filesec_t.h
entropy.o: ../../include/lutil_md5.h
entropy.o: ../../include/lber_types.h
sasl.o: ../../include/portable.h
sasl.o: sasl.c
sasl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
sasl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
sasl.o: ../../include/ldap_cdefs.h
sasl.o: ../../include/ac/fdset.h
sasl.o: ../../include/ac/assert.h
sasl.o: ../../include/ldap_features.h
sasl.o: /usr/include/sys/cdefs.h
sasl.o: /usr/include/assert.h
sasl.o: /usr/include/sys/_symbol_aliasing.h
sasl.o: ../../include/ac/localize.h
sasl.o: /usr/include/sys/_posix_availability.h
sasl.o: /usr/include/Availability.h
sasl.o: /usr/include/stdio.h
sasl.o: /usr/include/_types.h
sasl.o: /usr/include/AvailabilityInternal.h
sasl.o: /usr/include/machine/_types.h
sasl.o: /usr/include/sys/_types.h
sasl.o: /usr/include/sys/_pthread/_pthread_types.h
sasl.o: /usr/include/i386/_types.h
sasl.o: /usr/include/sys/_types/_size_t.h
sasl.o: /usr/include/sys/_types/_va_list.h
sasl.o: /usr/include/sys/stdio.h
sasl.o: /usr/include/sys/_types/_null.h
sasl.o: /usr/include/sys/_types/_ssize_t.h
sasl.o: /usr/include/sys/_types/_off_t.h
sasl.o: /usr/include/secure/_common.h
sasl.o: /usr/include/secure/_stdio.h
sasl.o: /usr/include/stdlib.h
sasl.o: ../../include/ac/stdlib.h
sasl.o: /usr/include/sys/_types/_pid_t.h
sasl.o: /usr/include/sys/wait.h
sasl.o: /usr/include/sys/signal.h
sasl.o: /usr/include/sys/_types/_id_t.h
sasl.o: /usr/include/machine/signal.h
sasl.o: /usr/include/sys/appleapiopts.h
sasl.o: /usr/include/machine/_mcontext.h
sasl.o: /usr/include/i386/signal.h
sasl.o: /usr/include/mach/i386/_structs.h
sasl.o: /usr/include/i386/_mcontext.h
sasl.o: /usr/include/sys/_pthread/_pthread_attr_t.h
sasl.o: /usr/include/sys/_types/_sigaltstack.h
sasl.o: /usr/include/sys/_types/_ucontext.h
sasl.o: /usr/include/sys/_types/_uid_t.h
sasl.o: /usr/include/sys/_types/_sigset_t.h
sasl.o: /usr/include/sys/resource.h
sasl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
sasl.o: /usr/include/sys/_types/_int8_t.h
sasl.o: /usr/include/stdint.h
sasl.o: /usr/include/sys/_types/_int32_t.h
sasl.o: /usr/include/sys/_types/_int16_t.h
sasl.o: /usr/include/_types/_uint8_t.h
sasl.o: /usr/include/sys/_types/_int64_t.h
sasl.o: /usr/include/_types/_uint32_t.h
sasl.o: /usr/include/_types/_uint16_t.h
sasl.o: /usr/include/sys/_types/_intptr_t.h
sasl.o: /usr/include/_types/_uint64_t.h
sasl.o: /usr/include/_types/_intmax_t.h
sasl.o: /usr/include/sys/_types/_uintptr_t.h
sasl.o: /usr/include/sys/_types/_timeval.h
sasl.o: /usr/include/_types/_uintmax_t.h
sasl.o: /usr/include/i386/endian.h
sasl.o: /usr/include/machine/endian.h
sasl.o: /usr/include/libkern/_OSByteOrder.h
sasl.o: /usr/include/sys/_endian.h
sasl.o: /usr/include/alloca.h
sasl.o: /usr/include/libkern/i386/_OSByteOrder.h
sasl.o: /usr/include/sys/_types/_rune_t.h
sasl.o: /usr/include/sys/_types/_ct_rune_t.h
sasl.o: /usr/include/machine/types.h
sasl.o: /usr/include/sys/_types/_wchar_t.h
sasl.o: /usr/include/sys/_types/_u_int8_t.h
sasl.o: /usr/include/i386/types.h
sasl.o: /usr/include/sys/_types/_u_int16_t.h
sasl.o: /usr/include/sys/_types/_u_int32_t.h
sasl.o: /usr/include/sys/_types/_dev_t.h
sasl.o: /usr/include/sys/_types/_u_int64_t.h
sasl.o: /usr/include/sys/_types/_mode_t.h
sasl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
sasl.o: /usr/include/machine/limits.h
sasl.o: /usr/include/limits.h
sasl.o: /usr/include/i386/_limits.h
sasl.o: /usr/include/i386/limits.h
sasl.o: ../../include/ac/string.h
sasl.o: /usr/include/sys/syslimits.h
sasl.o: /usr/include/sys/_types/_rsize_t.h
sasl.o: /usr/include/string.h
sasl.o: /usr/include/strings.h
sasl.o: /usr/include/sys/_types/_errno_t.h
sasl.o: ../../include/ac/unistd.h
sasl.o: /usr/include/secure/_string.h
sasl.o: /usr/include/sys/_types/_blkcnt_t.h
sasl.o: /usr/include/sys/types.h
sasl.o: /usr/include/sys/_types/_gid_t.h
sasl.o: /usr/include/sys/_types/_blksize_t.h
sasl.o: /usr/include/sys/_types/_in_addr_t.h
sasl.o: /usr/include/sys/_types/_ino_t.h
sasl.o: /usr/include/sys/_types/_in_port_t.h
sasl.o: /usr/include/sys/_types/_key_t.h
sasl.o: /usr/include/sys/_types/_ino64_t.h
sasl.o: /usr/include/sys/_types/_clock_t.h
sasl.o: /usr/include/sys/_types/_nlink_t.h
sasl.o: /usr/include/sys/_types/_time_t.h
sasl.o: /usr/include/sys/_types/_useconds_t.h
sasl.o: /usr/include/sys/_types/_suseconds_t.h
sasl.o: /usr/include/sys/_types/_fd_def.h
sasl.o: /usr/include/sys/_types/_fd_setsize.h
sasl.o: /usr/include/sys/_types/_fd_clr.h
sasl.o: /usr/include/sys/_types/_fd_set.h
sasl.o: /usr/include/sys/_types/_fd_isset.h
sasl.o: /usr/include/sys/_types/_fd_zero.h
sasl.o: /usr/include/sys/_types/_fd_copy.h
sasl.o: /usr/include/sys/_pthread/_pthread_cond_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_once_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_t.h
sasl.o: /usr/include/sys/_pthread/_pthread_key_t.h
sasl.o: /usr/include/sys/_types/_fsblkcnt_t.h
sasl.o: /usr/include/unistd.h
sasl.o: /usr/include/sys/_types/_fsfilcnt_t.h
sasl.o: /usr/include/sys/_types/_posix_vdisable.h
sasl.o: /usr/include/sys/unistd.h
sasl.o: /usr/include/sys/select.h
sasl.o: /usr/include/sys/_types/_seek_set.h
sasl.o: /usr/include/sys/_select.h
sasl.o: /usr/include/sys/_types/_timespec.h
sasl.o: /usr/include/gethostuuid.h
sasl.o: /usr/include/sys/_types/_uuid_t.h
sasl.o: ../../include/lutil_lockf.h
sasl.o: /usr/include/getopt.h
sasl.o: /usr/include/sasl/prop.h
sasl.o: ../../include/ldap.h
sasl.o: /usr/include/sasl/sasl.h
sasl.o: ../../include/lber_types.h
sasl.o: ../../include/lber.h
sasl.o: ../../include/lber_pvt.h
sasl.o: ../../include/ldap_pvt.h
sasl.o: ../../include/ac/bytes.h
sasl.o: ../../include/ldap_pvt_uc.h
sasl.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
sasl.o: ../../include/lutil_ldap.h
signal.o: ../../include/portable.h
signal.o: signal.c
signal.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
signal.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
signal.o: ../../include/ldap_cdefs.h
signal.o: ../../include/ac/fdset.h
signal.o: ../../include/ac/assert.h
signal.o: ../../include/ldap_features.h
signal.o: /usr/include/sys/cdefs.h
signal.o: /usr/include/assert.h
signal.o: /usr/include/sys/_symbol_aliasing.h
signal.o: ../../include/ac/localize.h
signal.o: /usr/include/sys/_posix_availability.h
signal.o: /usr/include/string.h
signal.o: /usr/include/_types.h
signal.o: ../../include/ac/string.h
signal.o: /usr/include/machine/_types.h
signal.o: /usr/include/sys/_types.h
signal.o: /usr/include/sys/_pthread/_pthread_types.h
signal.o: /usr/include/i386/_types.h
signal.o: /usr/include/AvailabilityInternal.h
signal.o: /usr/include/Availability.h
signal.o: /usr/include/sys/_types/_null.h
signal.o: /usr/include/sys/_types/_size_t.h
signal.o: /usr/include/sys/_types/_errno_t.h
signal.o: /usr/include/sys/_types/_rsize_t.h
signal.o: /usr/include/strings.h
signal.o: /usr/include/sys/_types/_ssize_t.h
signal.o: /usr/include/secure/_common.h
signal.o: /usr/include/secure/_string.h
signal.o: /usr/include/signal.h
signal.o: ../../include/ac/signal.h
signal.o: /usr/include/sys/appleapiopts.h
signal.o: /usr/include/sys/signal.h
signal.o: /usr/include/i386/signal.h
signal.o: /usr/include/machine/signal.h
signal.o: /usr/include/i386/_mcontext.h
signal.o: /usr/include/machine/_mcontext.h
signal.o: /usr/include/mach/i386/_structs.h
signal.o: /usr/include/sys/_pthread/_pthread_attr_t.h
signal.o: /usr/include/sys/_types/_sigaltstack.h
signal.o: /usr/include/sys/_types/_pid_t.h
signal.o: /usr/include/sys/_types/_ucontext.h
signal.o: /usr/include/sys/_types/_uid_t.h
signal.o: /usr/include/sys/_types/_sigset_t.h
signal.o: /usr/include/sys/_pthread/_pthread_t.h
hash.o: ../../include/portable.h
hash.o: hash.c
hash.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
hash.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
hash.o: ../../include/ldap_cdefs.h
hash.o: ../../include/ac/fdset.h
hash.o: ../../include/ac/assert.h
hash.o: ../../include/ldap_features.h
hash.o: /usr/include/sys/cdefs.h
hash.o: /usr/include/assert.h
hash.o: /usr/include/sys/_symbol_aliasing.h
hash.o: ../../include/ac/localize.h
hash.o: /usr/include/sys/_posix_availability.h
hash.o: ../../include/lber_types.h
hash.o: ../../include/lutil_hash.h
passfile.o: ../../include/portable.h
passfile.o: passfile.c
passfile.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
passfile.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
passfile.o: ../../include/ldap_cdefs.h
passfile.o: ../../include/ac/fdset.h
passfile.o: ../../include/ac/assert.h
passfile.o: ../../include/ldap_features.h
passfile.o: /usr/include/sys/cdefs.h
passfile.o: /usr/include/assert.h
passfile.o: /usr/include/sys/_symbol_aliasing.h
passfile.o: ../../include/ac/localize.h
passfile.o: /usr/include/sys/_posix_availability.h
passfile.o: /usr/include/Availability.h
passfile.o: /usr/include/stdio.h
passfile.o: /usr/include/_types.h
passfile.o: /usr/include/AvailabilityInternal.h
passfile.o: /usr/include/machine/_types.h
passfile.o: /usr/include/sys/_types.h
passfile.o: /usr/include/sys/_pthread/_pthread_types.h
passfile.o: /usr/include/i386/_types.h
passfile.o: /usr/include/sys/_types/_size_t.h
passfile.o: /usr/include/sys/_types/_va_list.h
passfile.o: /usr/include/sys/stdio.h
passfile.o: /usr/include/sys/_types/_null.h
passfile.o: /usr/include/sys/_types/_ssize_t.h
passfile.o: /usr/include/sys/_types/_off_t.h
passfile.o: /usr/include/secure/_common.h
passfile.o: /usr/include/secure/_stdio.h
passfile.o: /usr/include/stdlib.h
passfile.o: ../../include/ac/stdlib.h
passfile.o: /usr/include/sys/_types/_pid_t.h
passfile.o: /usr/include/sys/wait.h
passfile.o: /usr/include/sys/signal.h
passfile.o: /usr/include/sys/_types/_id_t.h
passfile.o: /usr/include/machine/signal.h
passfile.o: /usr/include/sys/appleapiopts.h
passfile.o: /usr/include/machine/_mcontext.h
passfile.o: /usr/include/i386/signal.h
passfile.o: /usr/include/mach/i386/_structs.h
passfile.o: /usr/include/i386/_mcontext.h
passfile.o: /usr/include/sys/_pthread/_pthread_attr_t.h
passfile.o: /usr/include/sys/_types/_sigaltstack.h
passfile.o: /usr/include/sys/_types/_ucontext.h
passfile.o: /usr/include/sys/_types/_uid_t.h
passfile.o: /usr/include/sys/_types/_sigset_t.h
passfile.o: /usr/include/sys/resource.h
passfile.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
passfile.o: /usr/include/sys/_types/_int8_t.h
passfile.o: /usr/include/stdint.h
passfile.o: /usr/include/sys/_types/_int32_t.h
passfile.o: /usr/include/sys/_types/_int16_t.h
passfile.o: /usr/include/_types/_uint8_t.h
passfile.o: /usr/include/sys/_types/_int64_t.h
passfile.o: /usr/include/_types/_uint32_t.h
passfile.o: /usr/include/_types/_uint16_t.h
passfile.o: /usr/include/sys/_types/_intptr_t.h
passfile.o: /usr/include/_types/_uint64_t.h
passfile.o: /usr/include/_types/_intmax_t.h
passfile.o: /usr/include/sys/_types/_uintptr_t.h
passfile.o: /usr/include/sys/_types/_timeval.h
passfile.o: /usr/include/_types/_uintmax_t.h
passfile.o: /usr/include/i386/endian.h
passfile.o: /usr/include/machine/endian.h
passfile.o: /usr/include/libkern/_OSByteOrder.h
passfile.o: /usr/include/sys/_endian.h
passfile.o: /usr/include/alloca.h
passfile.o: /usr/include/libkern/i386/_OSByteOrder.h
passfile.o: /usr/include/sys/_types/_rune_t.h
passfile.o: /usr/include/sys/_types/_ct_rune_t.h
passfile.o: /usr/include/machine/types.h
passfile.o: /usr/include/sys/_types/_wchar_t.h
passfile.o: /usr/include/sys/_types/_u_int8_t.h
passfile.o: /usr/include/i386/types.h
passfile.o: /usr/include/sys/_types/_u_int16_t.h
passfile.o: /usr/include/sys/_types/_u_int32_t.h
passfile.o: /usr/include/sys/_types/_dev_t.h
passfile.o: /usr/include/sys/_types/_u_int64_t.h
passfile.o: /usr/include/sys/_types/_mode_t.h
passfile.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
passfile.o: /usr/include/machine/limits.h
passfile.o: /usr/include/limits.h
passfile.o: /usr/include/i386/_limits.h
passfile.o: /usr/include/i386/limits.h
passfile.o: ../../include/ac/ctype.h
passfile.o: /usr/include/sys/syslimits.h
passfile.o: /usr/include/runetype.h
passfile.o: /usr/include/ctype.h
passfile.o: ../../include/ac/string.h
passfile.o: /usr/include/sys/_types/_wint_t.h
passfile.o: /usr/include/sys/_types/_rsize_t.h
passfile.o: /usr/include/string.h
passfile.o: /usr/include/strings.h
passfile.o: /usr/include/sys/_types/_errno_t.h
passfile.o: /usr/include/sys/types.h
passfile.o: /usr/include/secure/_string.h
passfile.o: /usr/include/sys/_types/_blkcnt_t.h
passfile.o: /usr/include/sys/_types/_gid_t.h
passfile.o: /usr/include/sys/_types/_blksize_t.h
passfile.o: /usr/include/sys/_types/_in_addr_t.h
passfile.o: /usr/include/sys/_types/_ino_t.h
passfile.o: /usr/include/sys/_types/_in_port_t.h
passfile.o: /usr/include/sys/_types/_key_t.h
passfile.o: /usr/include/sys/_types/_ino64_t.h
passfile.o: /usr/include/sys/_types/_clock_t.h
passfile.o: /usr/include/sys/_types/_nlink_t.h
passfile.o: /usr/include/sys/_types/_time_t.h
passfile.o: /usr/include/sys/_types/_useconds_t.h
passfile.o: /usr/include/sys/_types/_suseconds_t.h
passfile.o: /usr/include/sys/_types/_fd_def.h
passfile.o: /usr/include/sys/_types/_fd_setsize.h
passfile.o: /usr/include/sys/_types/_fd_clr.h
passfile.o: /usr/include/sys/_types/_fd_set.h
passfile.o: /usr/include/sys/_types/_fd_isset.h
passfile.o: /usr/include/sys/_types/_fd_zero.h
passfile.o: /usr/include/sys/_types/_fd_copy.h
passfile.o: /usr/include/sys/_pthread/_pthread_cond_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_once_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_t.h
passfile.o: /usr/include/sys/_pthread/_pthread_key_t.h
passfile.o: /usr/include/sys/_types/_fsblkcnt_t.h
passfile.o: /usr/include/sys/stat.h
passfile.o: /usr/include/sys/_types/_fsfilcnt_t.h
passfile.o: /usr/include/sys/_types/_s_ifmt.h
passfile.o: /usr/include/sys/_types/_timespec.h
passfile.o: ../../include/lber.h
passfile.o: /usr/include/sys/_types/_filesec_t.h
passfile.o: ../../include/lutil.h
passfile.o: ../../include/lber_types.h
md5.o: ../../include/portable.h
md5.o: md5.c
md5.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
md5.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
md5.o: ../../include/ldap_cdefs.h
md5.o: ../../include/ac/fdset.h
md5.o: ../../include/ac/assert.h
md5.o: ../../include/ldap_features.h
md5.o: /usr/include/sys/cdefs.h
md5.o: /usr/include/assert.h
md5.o: /usr/include/sys/_symbol_aliasing.h
md5.o: ../../include/ac/localize.h
md5.o: /usr/include/sys/_posix_availability.h
md5.o: /usr/include/string.h
md5.o: /usr/include/_types.h
md5.o: ../../include/ac/string.h
md5.o: /usr/include/machine/_types.h
md5.o: /usr/include/sys/_types.h
md5.o: /usr/include/sys/_pthread/_pthread_types.h
md5.o: /usr/include/i386/_types.h
md5.o: /usr/include/AvailabilityInternal.h
md5.o: /usr/include/Availability.h
md5.o: /usr/include/sys/_types/_null.h
md5.o: /usr/include/sys/_types/_size_t.h
md5.o: /usr/include/sys/_types/_errno_t.h
md5.o: /usr/include/sys/_types/_rsize_t.h
md5.o: /usr/include/strings.h
md5.o: /usr/include/sys/_types/_ssize_t.h
md5.o: /usr/include/secure/_common.h
md5.o: /usr/include/secure/_string.h
md5.o: /usr/include/sys/types.h
md5.o: ../../include/ac/socket.h
md5.o: /usr/include/machine/types.h
md5.o: /usr/include/sys/appleapiopts.h
md5.o: /usr/include/sys/_types/_int8_t.h
md5.o: /usr/include/i386/types.h
md5.o: /usr/include/sys/_types/_int32_t.h
md5.o: /usr/include/sys/_types/_int16_t.h
md5.o: /usr/include/sys/_types/_u_int8_t.h
md5.o: /usr/include/sys/_types/_int64_t.h
md5.o: /usr/include/sys/_types/_u_int16_t.h
md5.o: /usr/include/sys/_types/_u_int32_t.h
md5.o: /usr/include/sys/_types/_u_int64_t.h
md5.o: /usr/include/sys/_types/_intptr_t.h
md5.o: /usr/include/machine/endian.h
md5.o: /usr/include/sys/_types/_uintptr_t.h
md5.o: /usr/include/sys/_endian.h
md5.o: /usr/include/i386/endian.h
md5.o: /usr/include/libkern/_OSByteOrder.h
md5.o: /usr/include/libkern/i386/_OSByteOrder.h
md5.o: /usr/include/sys/_types/_blkcnt_t.h
md5.o: /usr/include/sys/_types/_dev_t.h
md5.o: /usr/include/sys/_types/_gid_t.h
md5.o: /usr/include/sys/_types/_blksize_t.h
md5.o: /usr/include/sys/_types/_in_addr_t.h
md5.o: /usr/include/sys/_types/_ino_t.h
md5.o: /usr/include/sys/_types/_in_port_t.h
md5.o: /usr/include/sys/_types/_key_t.h
md5.o: /usr/include/sys/_types/_ino64_t.h
md5.o: /usr/include/sys/_types/_nlink_t.h
md5.o: /usr/include/sys/_types/_mode_t.h
md5.o: /usr/include/sys/_types/_pid_t.h
md5.o: /usr/include/sys/_types/_id_t.h
md5.o: /usr/include/sys/_types/_uid_t.h
md5.o: /usr/include/sys/_types/_off_t.h
md5.o: /usr/include/sys/_types/_time_t.h
md5.o: /usr/include/sys/_types/_clock_t.h
md5.o: /usr/include/sys/_types/_useconds_t.h
md5.o: /usr/include/sys/_types/_suseconds_t.h
md5.o: /usr/include/sys/_types/_fd_def.h
md5.o: /usr/include/sys/_types/_fd_setsize.h
md5.o: /usr/include/sys/_types/_fd_clr.h
md5.o: /usr/include/sys/_types/_fd_set.h
md5.o: /usr/include/sys/_types/_fd_isset.h
md5.o: /usr/include/sys/_types/_fd_zero.h
md5.o: /usr/include/sys/_types/_fd_copy.h
md5.o: /usr/include/sys/_pthread/_pthread_attr_t.h
md5.o: /usr/include/sys/_pthread/_pthread_cond_t.h
md5.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
md5.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
md5.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
md5.o: /usr/include/sys/_pthread/_pthread_once_t.h
md5.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
md5.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
md5.o: /usr/include/sys/_pthread/_pthread_t.h
md5.o: /usr/include/sys/_pthread/_pthread_key_t.h
md5.o: /usr/include/sys/_types/_fsblkcnt_t.h
md5.o: /usr/include/poll.h
md5.o: /usr/include/sys/_types/_fsfilcnt_t.h
md5.o: /usr/include/sys/socket.h
md5.o: /usr/include/sys/poll.h
md5.o: /usr/include/i386/_param.h
md5.o: /usr/include/machine/_param.h
md5.o: /usr/include/sys/_types/_sa_family_t.h
md5.o: /usr/include/net/net_kev.h
md5.o: /usr/include/sys/_types/_socklen_t.h
md5.o: /usr/include/sys/un.h
md5.o: /usr/include/sys/_types/_iovec_t.h
md5.o: /usr/include/sys/_types/_timespec.h
md5.o: /usr/include/sys/select.h
md5.o: /usr/include/sys/_types/_sigset_t.h
md5.o: /usr/include/sys/_types/_timeval.h
md5.o: /usr/include/netinet/in.h
md5.o: /usr/include/sys/_select.h
md5.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
md5.o: /usr/include/_types/_uint8_t.h
md5.o: /usr/include/stdint.h
md5.o: /usr/include/_types/_uint32_t.h
md5.o: /usr/include/_types/_uint16_t.h
md5.o: /usr/include/_types/_intmax_t.h
md5.o: /usr/include/_types/_uint64_t.h
md5.o: /usr/include/netinet6/in6.h
md5.o: /usr/include/_types/_uintmax_t.h
md5.o: /usr/include/arpa/inet.h
md5.o: /usr/include/netinet/tcp.h
md5.o: /usr/include/sys/param.h
md5.o: /usr/include/arpa/nameser.h
md5.o: /usr/include/machine/param.h
md5.o: /usr/include/sys/syslimits.h
md5.o: /usr/include/i386/param.h
md5.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
md5.o: /usr/include/machine/limits.h
md5.o: /usr/include/limits.h
md5.o: /usr/include/i386/_limits.h
md5.o: /usr/include/i386/limits.h
md5.o: /usr/include/machine/signal.h
md5.o: /usr/include/sys/signal.h
md5.o: /usr/include/machine/_mcontext.h
md5.o: /usr/include/i386/signal.h
md5.o: /usr/include/mach/i386/_structs.h
md5.o: /usr/include/i386/_mcontext.h
md5.o: /usr/include/sys/_types/_sigaltstack.h
md5.o: /usr/include/netdb.h
md5.o: /usr/include/sys/_types/_ucontext.h
md5.o: /usr/include/stdio.h
md5.o: /usr/include/resolv.h
md5.o: /usr/include/sys/stdio.h
md5.o: /usr/include/sys/_types/_va_list.h
md5.o: ../../include/lutil_md5.h
md5.o: /usr/include/secure/_stdio.h
md5.o: ../../include/lber_types.h
passwd.o: ../../include/portable.h
passwd.o: passwd.c
passwd.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
passwd.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
passwd.o: ../../include/ldap_cdefs.h
passwd.o: ../../include/ac/fdset.h
passwd.o: ../../include/ac/assert.h
passwd.o: ../../include/ldap_features.h
passwd.o: /usr/include/sys/cdefs.h
passwd.o: /usr/include/assert.h
passwd.o: /usr/include/sys/_symbol_aliasing.h
passwd.o: ../../include/ac/localize.h
passwd.o: /usr/include/sys/_posix_availability.h
passwd.o: /usr/include/Availability.h
passwd.o: /usr/include/stdio.h
passwd.o: /usr/include/_types.h
passwd.o: /usr/include/AvailabilityInternal.h
passwd.o: /usr/include/machine/_types.h
passwd.o: /usr/include/sys/_types.h
passwd.o: /usr/include/sys/_pthread/_pthread_types.h
passwd.o: /usr/include/i386/_types.h
passwd.o: /usr/include/sys/_types/_size_t.h
passwd.o: /usr/include/sys/_types/_va_list.h
passwd.o: /usr/include/sys/stdio.h
passwd.o: /usr/include/sys/_types/_null.h
passwd.o: /usr/include/sys/_types/_ssize_t.h
passwd.o: /usr/include/sys/_types/_off_t.h
passwd.o: /usr/include/secure/_common.h
passwd.o: /usr/include/secure/_stdio.h
passwd.o: /usr/include/stdlib.h
passwd.o: ../../include/ac/stdlib.h
passwd.o: /usr/include/sys/_types/_pid_t.h
passwd.o: /usr/include/sys/wait.h
passwd.o: /usr/include/sys/signal.h
passwd.o: /usr/include/sys/_types/_id_t.h
passwd.o: /usr/include/machine/signal.h
passwd.o: /usr/include/sys/appleapiopts.h
passwd.o: /usr/include/machine/_mcontext.h
passwd.o: /usr/include/i386/signal.h
passwd.o: /usr/include/mach/i386/_structs.h
passwd.o: /usr/include/i386/_mcontext.h
passwd.o: /usr/include/sys/_pthread/_pthread_attr_t.h
passwd.o: /usr/include/sys/_types/_sigaltstack.h
passwd.o: /usr/include/sys/_types/_ucontext.h
passwd.o: /usr/include/sys/_types/_uid_t.h
passwd.o: /usr/include/sys/_types/_sigset_t.h
passwd.o: /usr/include/sys/resource.h
passwd.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
passwd.o: /usr/include/sys/_types/_int8_t.h
passwd.o: /usr/include/stdint.h
passwd.o: /usr/include/sys/_types/_int32_t.h
passwd.o: /usr/include/sys/_types/_int16_t.h
passwd.o: /usr/include/_types/_uint8_t.h
passwd.o: /usr/include/sys/_types/_int64_t.h
passwd.o: /usr/include/_types/_uint32_t.h
passwd.o: /usr/include/_types/_uint16_t.h
passwd.o: /usr/include/sys/_types/_intptr_t.h
passwd.o: /usr/include/_types/_uint64_t.h
passwd.o: /usr/include/_types/_intmax_t.h
passwd.o: /usr/include/sys/_types/_uintptr_t.h
passwd.o: /usr/include/sys/_types/_timeval.h
passwd.o: /usr/include/_types/_uintmax_t.h
passwd.o: /usr/include/i386/endian.h
passwd.o: /usr/include/machine/endian.h
passwd.o: /usr/include/libkern/_OSByteOrder.h
passwd.o: /usr/include/sys/_endian.h
passwd.o: /usr/include/alloca.h
passwd.o: /usr/include/libkern/i386/_OSByteOrder.h
passwd.o: /usr/include/sys/_types/_rune_t.h
passwd.o: /usr/include/sys/_types/_ct_rune_t.h
passwd.o: /usr/include/machine/types.h
passwd.o: /usr/include/sys/_types/_wchar_t.h
passwd.o: /usr/include/sys/_types/_u_int8_t.h
passwd.o: /usr/include/i386/types.h
passwd.o: /usr/include/sys/_types/_u_int16_t.h
passwd.o: /usr/include/sys/_types/_u_int32_t.h
passwd.o: /usr/include/sys/_types/_dev_t.h
passwd.o: /usr/include/sys/_types/_u_int64_t.h
passwd.o: /usr/include/sys/_types/_mode_t.h
passwd.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
passwd.o: /usr/include/machine/limits.h
passwd.o: /usr/include/limits.h
passwd.o: /usr/include/i386/_limits.h
passwd.o: /usr/include/i386/limits.h
passwd.o: ../../include/ac/string.h
passwd.o: /usr/include/sys/syslimits.h
passwd.o: /usr/include/sys/_types/_rsize_t.h
passwd.o: /usr/include/string.h
passwd.o: /usr/include/strings.h
passwd.o: /usr/include/sys/_types/_errno_t.h
passwd.o: ../../include/ac/unistd.h
passwd.o: /usr/include/secure/_string.h
passwd.o: /usr/include/sys/_types/_blkcnt_t.h
passwd.o: /usr/include/sys/types.h
passwd.o: /usr/include/sys/_types/_gid_t.h
passwd.o: /usr/include/sys/_types/_blksize_t.h
passwd.o: /usr/include/sys/_types/_in_addr_t.h
passwd.o: /usr/include/sys/_types/_ino_t.h
passwd.o: /usr/include/sys/_types/_in_port_t.h
passwd.o: /usr/include/sys/_types/_key_t.h
passwd.o: /usr/include/sys/_types/_ino64_t.h
passwd.o: /usr/include/sys/_types/_clock_t.h
passwd.o: /usr/include/sys/_types/_nlink_t.h
passwd.o: /usr/include/sys/_types/_time_t.h
passwd.o: /usr/include/sys/_types/_useconds_t.h
passwd.o: /usr/include/sys/_types/_suseconds_t.h
passwd.o: /usr/include/sys/_types/_fd_def.h
passwd.o: /usr/include/sys/_types/_fd_setsize.h
passwd.o: /usr/include/sys/_types/_fd_clr.h
passwd.o: /usr/include/sys/_types/_fd_set.h
passwd.o: /usr/include/sys/_types/_fd_isset.h
passwd.o: /usr/include/sys/_types/_fd_zero.h
passwd.o: /usr/include/sys/_types/_fd_copy.h
passwd.o: /usr/include/sys/_pthread/_pthread_cond_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_once_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_t.h
passwd.o: /usr/include/sys/_pthread/_pthread_key_t.h
passwd.o: /usr/include/sys/_types/_fsblkcnt_t.h
passwd.o: /usr/include/unistd.h
passwd.o: /usr/include/sys/_types/_fsfilcnt_t.h
passwd.o: /usr/include/sys/_types/_posix_vdisable.h
passwd.o: /usr/include/sys/unistd.h
passwd.o: /usr/include/sys/select.h
passwd.o: /usr/include/sys/_types/_seek_set.h
passwd.o: /usr/include/sys/_select.h
passwd.o: /usr/include/sys/_types/_timespec.h
passwd.o: /usr/include/gethostuuid.h
passwd.o: /usr/include/sys/_types/_uuid_t.h
passwd.o: ../../include/lutil_lockf.h
passwd.o: /usr/include/getopt.h
passwd.o: /usr/include/sys/param.h
passwd.o: ../../include/ac/param.h
passwd.o: /usr/include/i386/param.h
passwd.o: /usr/include/machine/param.h
passwd.o: ../../include/lber.h
passwd.o: /usr/include/i386/_param.h
passwd.o: ../../include/ldap_pvt.h
passwd.o: ../../include/lber_types.h
passwd.o: ../../include/ldap_pvt_uc.h
passwd.o: ../../include/lber_pvt.h
passwd.o: ../../include/ac/bytes.h
passwd.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
passwd.o: ../../include/lutil_sha1.h
passwd.o: ../../include/lutil_md5.h
passwd.o: ../../include/lutil.h
sha1.o: ../../include/portable.h
sha1.o: sha1.c
sha1.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
sha1.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
sha1.o: ../../include/ldap_cdefs.h
sha1.o: ../../include/ac/fdset.h
sha1.o: ../../include/ac/assert.h
sha1.o: ../../include/ldap_features.h
sha1.o: /usr/include/sys/cdefs.h
sha1.o: /usr/include/assert.h
sha1.o: /usr/include/sys/_symbol_aliasing.h
sha1.o: ../../include/ac/localize.h
sha1.o: /usr/include/sys/_posix_availability.h
sha1.o: /usr/include/sys/param.h
sha1.o: ../../include/ac/param.h
sha1.o: /usr/include/machine/_types.h
sha1.o: /usr/include/sys/_types.h
sha1.o: /usr/include/sys/_pthread/_pthread_types.h
sha1.o: /usr/include/i386/_types.h
sha1.o: /usr/include/sys/types.h
sha1.o: /usr/include/sys/_types/_null.h
sha1.o: /usr/include/machine/types.h
sha1.o: /usr/include/sys/appleapiopts.h
sha1.o: /usr/include/sys/_types/_int8_t.h
sha1.o: /usr/include/i386/types.h
sha1.o: /usr/include/sys/_types/_int32_t.h
sha1.o: /usr/include/sys/_types/_int16_t.h
sha1.o: /usr/include/sys/_types/_u_int8_t.h
sha1.o: /usr/include/sys/_types/_int64_t.h
sha1.o: /usr/include/sys/_types/_u_int16_t.h
sha1.o: /usr/include/sys/_types/_u_int32_t.h
sha1.o: /usr/include/sys/_types/_u_int64_t.h
sha1.o: /usr/include/sys/_types/_intptr_t.h
sha1.o: /usr/include/machine/endian.h
sha1.o: /usr/include/sys/_types/_uintptr_t.h
sha1.o: /usr/include/sys/_endian.h
sha1.o: /usr/include/i386/endian.h
sha1.o: /usr/include/libkern/_OSByteOrder.h
sha1.o: /usr/include/libkern/i386/_OSByteOrder.h
sha1.o: /usr/include/sys/_types/_blkcnt_t.h
sha1.o: /usr/include/sys/_types/_dev_t.h
sha1.o: /usr/include/sys/_types/_gid_t.h
sha1.o: /usr/include/sys/_types/_blksize_t.h
sha1.o: /usr/include/sys/_types/_in_addr_t.h
sha1.o: /usr/include/sys/_types/_ino_t.h
sha1.o: /usr/include/sys/_types/_in_port_t.h
sha1.o: /usr/include/sys/_types/_key_t.h
sha1.o: /usr/include/sys/_types/_ino64_t.h
sha1.o: /usr/include/sys/_types/_nlink_t.h
sha1.o: /usr/include/sys/_types/_mode_t.h
sha1.o: /usr/include/sys/_types/_pid_t.h
sha1.o: /usr/include/sys/_types/_id_t.h
sha1.o: /usr/include/sys/_types/_uid_t.h
sha1.o: /usr/include/sys/_types/_off_t.h
sha1.o: /usr/include/sys/_types/_size_t.h
sha1.o: /usr/include/sys/_types/_clock_t.h
sha1.o: /usr/include/sys/_types/_time_t.h
sha1.o: /usr/include/sys/_types/_ssize_t.h
sha1.o: /usr/include/sys/_types/_useconds_t.h
sha1.o: /usr/include/sys/_types/_suseconds_t.h
sha1.o: /usr/include/sys/_types/_errno_t.h
sha1.o: /usr/include/sys/_types/_rsize_t.h
sha1.o: /usr/include/sys/_types/_fd_def.h
sha1.o: /usr/include/sys/_types/_fd_setsize.h
sha1.o: /usr/include/sys/_types/_fd_clr.h
sha1.o: /usr/include/sys/_types/_fd_set.h
sha1.o: /usr/include/sys/_types/_fd_isset.h
sha1.o: /usr/include/sys/_types/_fd_zero.h
sha1.o: /usr/include/sys/_types/_fd_copy.h
sha1.o: /usr/include/sys/_pthread/_pthread_attr_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_cond_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_once_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_t.h
sha1.o: /usr/include/sys/_pthread/_pthread_key_t.h
sha1.o: /usr/include/sys/_types/_fsblkcnt_t.h
sha1.o: /usr/include/sys/syslimits.h
sha1.o: /usr/include/sys/_types/_fsfilcnt_t.h
sha1.o: /usr/include/i386/param.h
sha1.o: /usr/include/machine/param.h
sha1.o: /usr/include/i386/_param.h
sha1.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
sha1.o: /usr/include/machine/limits.h
sha1.o: /usr/include/limits.h
sha1.o: /usr/include/i386/_limits.h
sha1.o: /usr/include/i386/limits.h
sha1.o: /usr/include/Availability.h
sha1.o: /usr/include/sys/signal.h
sha1.o: /usr/include/machine/signal.h
sha1.o: /usr/include/AvailabilityInternal.h
sha1.o: /usr/include/machine/_mcontext.h
sha1.o: /usr/include/i386/signal.h
sha1.o: /usr/include/mach/i386/_structs.h
sha1.o: /usr/include/i386/_mcontext.h
sha1.o: /usr/include/sys/_types/_sigaltstack.h
sha1.o: /usr/include/sys/_types/_ucontext.h
sha1.o: ../../include/ac/unistd.h
sha1.o: /usr/include/sys/_types/_sigset_t.h
sha1.o: /usr/include/_types.h
sha1.o: /usr/include/sys/unistd.h
sha1.o: /usr/include/unistd.h
sha1.o: /usr/include/sys/_types/_posix_vdisable.h
sha1.o: /usr/include/_types/_uint64_t.h
sha1.o: /usr/include/sys/_types/_seek_set.h
sha1.o: /usr/include/sys/_types/_timespec.h
sha1.o: /usr/include/sys/select.h
sha1.o: /usr/include/sys/_select.h
sha1.o: /usr/include/sys/_types/_timeval.h
sha1.o: /usr/include/gethostuuid.h
sha1.o: /usr/include/sys/_types/_uuid_t.h
sha1.o: ../../include/lutil_lockf.h
sha1.o: /usr/include/getopt.h
sha1.o: /usr/include/string.h
sha1.o: /usr/include/strings.h
sha1.o: ../../include/ac/string.h
sha1.o: /usr/include/secure/_common.h
sha1.o: /usr/include/secure/_string.h
sha1.o: /usr/include/poll.h
sha1.o: /usr/include/sys/poll.h
sha1.o: ../../include/ac/socket.h
sha1.o: /usr/include/machine/_param.h
sha1.o: /usr/include/sys/socket.h
sha1.o: /usr/include/sys/_types/_sa_family_t.h
sha1.o: /usr/include/net/net_kev.h
sha1.o: /usr/include/sys/_types/_socklen_t.h
sha1.o: /usr/include/sys/un.h
sha1.o: /usr/include/sys/_types/_iovec_t.h
sha1.o: /usr/include/netinet/in.h
sha1.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
sha1.o: /usr/include/_types/_uint8_t.h
sha1.o: /usr/include/stdint.h
sha1.o: /usr/include/_types/_uint32_t.h
sha1.o: /usr/include/_types/_uint16_t.h
sha1.o: /usr/include/_types/_uintmax_t.h
sha1.o: /usr/include/_types/_intmax_t.h
sha1.o: /usr/include/netinet/tcp.h
sha1.o: /usr/include/netinet6/in6.h
sha1.o: /usr/include/arpa/nameser.h
sha1.o: /usr/include/arpa/inet.h
sha1.o: /usr/include/resolv.h
sha1.o: /usr/include/stdio.h
sha1.o: /usr/include/netdb.h
sha1.o: /usr/include/sys/stdio.h
sha1.o: /usr/include/sys/_types/_va_list.h
sha1.o: ../../include/ac/bytes.h
sha1.o: /usr/include/secure/_stdio.h
sha1.o: ../../include/ac/stdlib.h
sha1.o: ../../include/lutil_sha1.h
sha1.o: /usr/include/sys/wait.h
sha1.o: /usr/include/stdlib.h
sha1.o: /usr/include/alloca.h
sha1.o: /usr/include/sys/resource.h
sha1.o: /usr/include/sys/_types/_rune_t.h
sha1.o: /usr/include/sys/_types/_ct_rune_t.h
sha1.o: ../../include/ac/errno.h
sha1.o: /usr/include/sys/_types/_wchar_t.h
sha1.o: /usr/include/sys/errno.h
sha1.o: /usr/include/sys/file.h
sha1.o: /usr/include/errno.h
sha1.o: /usr/include/sys/_types/_o_sync.h
sha1.o: /usr/include/sys/fcntl.h
sha1.o: /usr/include/sys/_types/_s_ifmt.h
sha1.o: /usr/include/sys/_types/_o_dsync.h
sha1.o: /usr/include/sys/queue.h
sha1.o: /usr/include/sys/_types/_filesec_t.h
sha1.o: /usr/include/fcntl.h
getpass.o: ../../include/portable.h
getpass.o: getpass.c
getpass.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
getpass.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
getpass.o: ../../include/ldap_cdefs.h
getpass.o: ../../include/ac/fdset.h
getpass.o: ../../include/ac/assert.h
getpass.o: ../../include/ldap_features.h
getpass.o: /usr/include/sys/cdefs.h
getpass.o: /usr/include/assert.h
getpass.o: /usr/include/sys/_symbol_aliasing.h
getpass.o: ../../include/ac/localize.h
getpass.o: /usr/include/sys/_posix_availability.h
getpass.o: /usr/include/Availability.h
getpass.o: /usr/include/stdio.h
getpass.o: /usr/include/_types.h
getpass.o: /usr/include/AvailabilityInternal.h
getpass.o: /usr/include/machine/_types.h
getpass.o: /usr/include/sys/_types.h
getpass.o: /usr/include/sys/_pthread/_pthread_types.h
getpass.o: /usr/include/i386/_types.h
getpass.o: /usr/include/sys/_types/_size_t.h
getpass.o: /usr/include/sys/_types/_va_list.h
getpass.o: /usr/include/sys/stdio.h
getpass.o: /usr/include/sys/_types/_null.h
getpass.o: /usr/include/sys/_types/_ssize_t.h
getpass.o: /usr/include/sys/_types/_off_t.h
getpass.o: /usr/include/secure/_common.h
getpass.o: /usr/include/secure/_stdio.h
getpass.o: /usr/include/stdlib.h
getpass.o: ../../include/ac/stdlib.h
getpass.o: /usr/include/sys/_types/_pid_t.h
getpass.o: /usr/include/sys/wait.h
getpass.o: /usr/include/sys/signal.h
getpass.o: /usr/include/sys/_types/_id_t.h
getpass.o: /usr/include/machine/signal.h
getpass.o: /usr/include/sys/appleapiopts.h
getpass.o: /usr/include/machine/_mcontext.h
getpass.o: /usr/include/i386/signal.h
getpass.o: /usr/include/mach/i386/_structs.h
getpass.o: /usr/include/i386/_mcontext.h
getpass.o: /usr/include/sys/_pthread/_pthread_attr_t.h
getpass.o: /usr/include/sys/_types/_sigaltstack.h
getpass.o: /usr/include/sys/_types/_ucontext.h
getpass.o: /usr/include/sys/_types/_uid_t.h
getpass.o: /usr/include/sys/_types/_sigset_t.h
getpass.o: /usr/include/sys/resource.h
getpass.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
getpass.o: /usr/include/sys/_types/_int8_t.h
getpass.o: /usr/include/stdint.h
getpass.o: /usr/include/sys/_types/_int32_t.h
getpass.o: /usr/include/sys/_types/_int16_t.h
getpass.o: /usr/include/_types/_uint8_t.h
getpass.o: /usr/include/sys/_types/_int64_t.h
getpass.o: /usr/include/_types/_uint32_t.h
getpass.o: /usr/include/_types/_uint16_t.h
getpass.o: /usr/include/sys/_types/_intptr_t.h
getpass.o: /usr/include/_types/_uint64_t.h
getpass.o: /usr/include/_types/_intmax_t.h
getpass.o: /usr/include/sys/_types/_uintptr_t.h
getpass.o: /usr/include/sys/_types/_timeval.h
getpass.o: /usr/include/_types/_uintmax_t.h
getpass.o: /usr/include/i386/endian.h
getpass.o: /usr/include/machine/endian.h
getpass.o: /usr/include/libkern/_OSByteOrder.h
getpass.o: /usr/include/sys/_endian.h
getpass.o: /usr/include/alloca.h
getpass.o: /usr/include/libkern/i386/_OSByteOrder.h
getpass.o: /usr/include/sys/_types/_rune_t.h
getpass.o: /usr/include/sys/_types/_ct_rune_t.h
getpass.o: /usr/include/machine/types.h
getpass.o: /usr/include/sys/_types/_wchar_t.h
getpass.o: /usr/include/sys/_types/_u_int8_t.h
getpass.o: /usr/include/i386/types.h
getpass.o: /usr/include/sys/_types/_u_int16_t.h
getpass.o: /usr/include/sys/_types/_u_int32_t.h
getpass.o: /usr/include/sys/_types/_dev_t.h
getpass.o: /usr/include/sys/_types/_u_int64_t.h
getpass.o: /usr/include/sys/_types/_mode_t.h
getpass.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
getpass.o: /usr/include/machine/limits.h
getpass.o: /usr/include/limits.h
getpass.o: /usr/include/i386/_limits.h
getpass.o: /usr/include/i386/limits.h
getpass.o: ../../include/ac/ctype.h
getpass.o: /usr/include/sys/syslimits.h
getpass.o: /usr/include/runetype.h
getpass.o: /usr/include/ctype.h
getpass.o: ../../include/ac/signal.h
getpass.o: /usr/include/sys/_types/_wint_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_t.h
getpass.o: /usr/include/signal.h
getpass.o: /usr/include/string.h
getpass.o: ../../include/ac/string.h
getpass.o: /usr/include/sys/_types/_errno_t.h
getpass.o: /usr/include/sys/_types/_rsize_t.h
getpass.o: /usr/include/secure/_string.h
getpass.o: /usr/include/strings.h
getpass.o: /usr/include/termios.h
getpass.o: ../../include/ac/termios.h
getpass.o: /usr/include/sys/_types/_posix_vdisable.h
getpass.o: /usr/include/sys/termios.h
getpass.o: /usr/include/sys/ioccom.h
getpass.o: /usr/include/sys/ttycom.h
getpass.o: ../../include/ac/time.h
getpass.o: /usr/include/sys/ttydefaults.h
getpass.o: /usr/include/sys/_types/_fd_def.h
getpass.o: /usr/include/sys/time.h
getpass.o: /usr/include/sys/_types/_timespec.h
getpass.o: /usr/include/sys/_types/_time_t.h
getpass.o: /usr/include/sys/_types/_timeval64.h
getpass.o: /usr/include/sys/_types/_suseconds_t.h
getpass.o: /usr/include/sys/_types/_fd_setsize.h
getpass.o: /usr/include/sys/_types/_fd_clr.h
getpass.o: /usr/include/sys/_types/_fd_set.h
getpass.o: /usr/include/sys/_types/_fd_zero.h
getpass.o: /usr/include/sys/_types/_fd_isset.h
getpass.o: /usr/include/time.h
getpass.o: /usr/include/sys/_types/_fd_copy.h
getpass.o: /usr/include/sys/_select.h
getpass.o: /usr/include/sys/_types/_clock_t.h
getpass.o: /usr/include/sys/types.h
getpass.o: ../../include/ac/unistd.h
getpass.o: /usr/include/sys/_types/_blkcnt_t.h
getpass.o: /usr/include/sys/_types/_gid_t.h
getpass.o: /usr/include/sys/_types/_blksize_t.h
getpass.o: /usr/include/sys/_types/_in_addr_t.h
getpass.o: /usr/include/sys/_types/_ino_t.h
getpass.o: /usr/include/sys/_types/_in_port_t.h
getpass.o: /usr/include/sys/_types/_key_t.h
getpass.o: /usr/include/sys/_types/_ino64_t.h
getpass.o: /usr/include/sys/_types/_nlink_t.h
getpass.o: /usr/include/sys/_types/_useconds_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_cond_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_once_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
getpass.o: /usr/include/sys/_pthread/_pthread_key_t.h
getpass.o: /usr/include/sys/_types/_fsblkcnt_t.h
getpass.o: /usr/include/unistd.h
getpass.o: /usr/include/sys/_types/_fsfilcnt_t.h
getpass.o: /usr/include/sys/_types/_seek_set.h
getpass.o: /usr/include/sys/unistd.h
getpass.o: /usr/include/sys/_types/_uuid_t.h
getpass.o: /usr/include/sys/select.h
getpass.o: /usr/include/getopt.h
getpass.o: /usr/include/gethostuuid.h
getpass.o: /usr/include/fcntl.h
getpass.o: ../../include/lutil_lockf.h
getpass.o: /usr/include/sys/_types/_o_sync.h
getpass.o: /usr/include/sys/fcntl.h
getpass.o: /usr/include/sys/_types/_s_ifmt.h
getpass.o: /usr/include/sys/_types/_o_dsync.h
getpass.o: ../../include/lber.h
getpass.o: /usr/include/sys/_types/_filesec_t.h
getpass.o: ../../include/ldap.h
getpass.o: ../../include/lber_types.h
getpass.o: ../../include/ldap_config.h
getpass.o: ../../include/ldap_defaults.h
lockf.o: ../../include/portable.h
lockf.o: lockf.c
lockf.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
lockf.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
lockf.o: ../../include/ldap_cdefs.h
lockf.o: ../../include/ac/fdset.h
lockf.o: ../../include/ac/assert.h
lockf.o: ../../include/ldap_features.h
lockf.o: /usr/include/sys/cdefs.h
lockf.o: /usr/include/assert.h
lockf.o: /usr/include/sys/_symbol_aliasing.h
lockf.o: ../../include/ac/localize.h
lockf.o: /usr/include/sys/_posix_availability.h
lockf.o: /usr/include/Availability.h
lockf.o: /usr/include/stdio.h
lockf.o: /usr/include/_types.h
lockf.o: /usr/include/AvailabilityInternal.h
lockf.o: /usr/include/machine/_types.h
lockf.o: /usr/include/sys/_types.h
lockf.o: /usr/include/sys/_pthread/_pthread_types.h
lockf.o: /usr/include/i386/_types.h
lockf.o: /usr/include/sys/_types/_size_t.h
lockf.o: /usr/include/sys/_types/_va_list.h
lockf.o: /usr/include/sys/stdio.h
lockf.o: /usr/include/sys/_types/_null.h
lockf.o: /usr/include/sys/_types/_ssize_t.h
lockf.o: /usr/include/sys/_types/_off_t.h
lockf.o: /usr/include/secure/_common.h
lockf.o: /usr/include/secure/_stdio.h
lockf.o: /usr/include/sys/types.h
lockf.o: ../../include/ac/unistd.h
lockf.o: /usr/include/machine/types.h
lockf.o: /usr/include/sys/appleapiopts.h
lockf.o: /usr/include/sys/_types/_int8_t.h
lockf.o: /usr/include/i386/types.h
lockf.o: /usr/include/sys/_types/_int32_t.h
lockf.o: /usr/include/sys/_types/_int16_t.h
lockf.o: /usr/include/sys/_types/_u_int8_t.h
lockf.o: /usr/include/sys/_types/_int64_t.h
lockf.o: /usr/include/sys/_types/_u_int16_t.h
lockf.o: /usr/include/sys/_types/_u_int32_t.h
lockf.o: /usr/include/sys/_types/_u_int64_t.h
lockf.o: /usr/include/sys/_types/_intptr_t.h
lockf.o: /usr/include/machine/endian.h
lockf.o: /usr/include/sys/_types/_uintptr_t.h
lockf.o: /usr/include/sys/_endian.h
lockf.o: /usr/include/i386/endian.h
lockf.o: /usr/include/libkern/_OSByteOrder.h
lockf.o: /usr/include/libkern/i386/_OSByteOrder.h
lockf.o: /usr/include/sys/_types/_blkcnt_t.h
lockf.o: /usr/include/sys/_types/_dev_t.h
lockf.o: /usr/include/sys/_types/_gid_t.h
lockf.o: /usr/include/sys/_types/_blksize_t.h
lockf.o: /usr/include/sys/_types/_in_addr_t.h
lockf.o: /usr/include/sys/_types/_ino_t.h
lockf.o: /usr/include/sys/_types/_in_port_t.h
lockf.o: /usr/include/sys/_types/_key_t.h
lockf.o: /usr/include/sys/_types/_ino64_t.h
lockf.o: /usr/include/sys/_types/_nlink_t.h
lockf.o: /usr/include/sys/_types/_mode_t.h
lockf.o: /usr/include/sys/_types/_pid_t.h
lockf.o: /usr/include/sys/_types/_id_t.h
lockf.o: /usr/include/sys/_types/_clock_t.h
lockf.o: /usr/include/sys/_types/_uid_t.h
lockf.o: /usr/include/sys/_types/_time_t.h
lockf.o: /usr/include/sys/_types/_useconds_t.h
lockf.o: /usr/include/sys/_types/_suseconds_t.h
lockf.o: /usr/include/sys/_types/_errno_t.h
lockf.o: /usr/include/sys/_types/_rsize_t.h
lockf.o: /usr/include/sys/_types/_fd_def.h
lockf.o: /usr/include/sys/_types/_fd_setsize.h
lockf.o: /usr/include/sys/_types/_fd_clr.h
lockf.o: /usr/include/sys/_types/_fd_set.h
lockf.o: /usr/include/sys/_types/_fd_isset.h
lockf.o: /usr/include/sys/_types/_fd_zero.h
lockf.o: /usr/include/sys/_types/_fd_copy.h
lockf.o: /usr/include/sys/_pthread/_pthread_attr_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_cond_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_once_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_t.h
lockf.o: /usr/include/sys/_pthread/_pthread_key_t.h
lockf.o: /usr/include/sys/_types/_fsblkcnt_t.h
lockf.o: /usr/include/unistd.h
lockf.o: /usr/include/sys/_types/_fsfilcnt_t.h
lockf.o: /usr/include/sys/_types/_posix_vdisable.h
lockf.o: /usr/include/sys/unistd.h
lockf.o: /usr/include/_types/_uint64_t.h
lockf.o: /usr/include/sys/_types/_seek_set.h
lockf.o: /usr/include/sys/_types/_timespec.h
lockf.o: /usr/include/sys/select.h
lockf.o: /usr/include/sys/_types/_sigset_t.h
lockf.o: /usr/include/sys/_types/_timeval.h
lockf.o: /usr/include/sys/_types/_uuid_t.h
lockf.o: /usr/include/sys/_select.h
lockf.o: /usr/include/getopt.h
lockf.o: /usr/include/gethostuuid.h
lockf.o: ../../include/lutil_lockf.h
utils.o: ../../include/portable.h
utils.o: utils.c
utils.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
utils.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
utils.o: ../../include/ldap_cdefs.h
utils.o: ../../include/ac/fdset.h
utils.o: ../../include/ac/assert.h
utils.o: ../../include/ldap_features.h
utils.o: /usr/include/sys/cdefs.h
utils.o: /usr/include/assert.h
utils.o: /usr/include/sys/_symbol_aliasing.h
utils.o: ../../include/ac/localize.h
utils.o: /usr/include/sys/_posix_availability.h
utils.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
utils.o: /usr/include/machine/limits.h
utils.o: /usr/include/limits.h
utils.o: /usr/include/i386/_limits.h
utils.o: /usr/include/i386/limits.h
utils.o: /usr/include/stdio.h
utils.o: /usr/include/sys/syslimits.h
utils.o: /usr/include/AvailabilityInternal.h
utils.o: /usr/include/Availability.h
utils.o: /usr/include/sys/_types.h
utils.o: /usr/include/_types.h
utils.o: /usr/include/i386/_types.h
utils.o: /usr/include/machine/_types.h
utils.o: /usr/include/sys/_pthread/_pthread_types.h
utils.o: /usr/include/sys/_types/_size_t.h
utils.o: /usr/include/sys/_types/_va_list.h
utils.o: /usr/include/sys/stdio.h
utils.o: /usr/include/sys/_types/_null.h
utils.o: /usr/include/sys/_types/_ssize_t.h
utils.o: /usr/include/sys/_types/_off_t.h
utils.o: /usr/include/secure/_common.h
utils.o: /usr/include/secure/_stdio.h
utils.o: /usr/include/stdlib.h
utils.o: ../../include/ac/stdlib.h
utils.o: /usr/include/sys/_types/_pid_t.h
utils.o: /usr/include/sys/wait.h
utils.o: /usr/include/sys/signal.h
utils.o: /usr/include/sys/_types/_id_t.h
utils.o: /usr/include/machine/signal.h
utils.o: /usr/include/sys/appleapiopts.h
utils.o: /usr/include/machine/_mcontext.h
utils.o: /usr/include/i386/signal.h
utils.o: /usr/include/mach/i386/_structs.h
utils.o: /usr/include/i386/_mcontext.h
utils.o: /usr/include/sys/_pthread/_pthread_attr_t.h
utils.o: /usr/include/sys/_types/_sigaltstack.h
utils.o: /usr/include/sys/_types/_ucontext.h
utils.o: /usr/include/sys/_types/_uid_t.h
utils.o: /usr/include/sys/_types/_sigset_t.h
utils.o: /usr/include/sys/resource.h
utils.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
utils.o: /usr/include/sys/_types/_int8_t.h
utils.o: /usr/include/stdint.h
utils.o: /usr/include/sys/_types/_int32_t.h
utils.o: /usr/include/sys/_types/_int16_t.h
utils.o: /usr/include/_types/_uint8_t.h
utils.o: /usr/include/sys/_types/_int64_t.h
utils.o: /usr/include/_types/_uint32_t.h
utils.o: /usr/include/_types/_uint16_t.h
utils.o: /usr/include/sys/_types/_intptr_t.h
utils.o: /usr/include/_types/_uint64_t.h
utils.o: /usr/include/_types/_intmax_t.h
utils.o: /usr/include/sys/_types/_uintptr_t.h
utils.o: /usr/include/sys/_types/_timeval.h
utils.o: /usr/include/_types/_uintmax_t.h
utils.o: /usr/include/i386/endian.h
utils.o: /usr/include/machine/endian.h
utils.o: /usr/include/libkern/_OSByteOrder.h
utils.o: /usr/include/sys/_endian.h
utils.o: /usr/include/alloca.h
utils.o: /usr/include/libkern/i386/_OSByteOrder.h
utils.o: /usr/include/sys/_types/_rune_t.h
utils.o: /usr/include/sys/_types/_ct_rune_t.h
utils.o: /usr/include/machine/types.h
utils.o: /usr/include/sys/_types/_wchar_t.h
utils.o: /usr/include/sys/_types/_u_int8_t.h
utils.o: /usr/include/i386/types.h
utils.o: /usr/include/sys/_types/_u_int16_t.h
utils.o: /usr/include/sys/_types/_u_int32_t.h
utils.o: /usr/include/sys/_types/_dev_t.h
utils.o: /usr/include/sys/_types/_u_int64_t.h
utils.o: ../../include/ac/stdarg.h
utils.o: /usr/include/sys/_types/_mode_t.h
utils.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
utils.o: /usr/include/string.h
utils.o: ../../include/ac/string.h
utils.o: /usr/include/sys/_types/_errno_t.h
utils.o: /usr/include/sys/_types/_rsize_t.h
utils.o: /usr/include/secure/_string.h
utils.o: /usr/include/strings.h
utils.o: /usr/include/ctype.h
utils.o: /usr/include/runetype.h
utils.o: ../../include/ac/ctype.h
utils.o: ../../include/ac/unistd.h
utils.o: /usr/include/sys/_types/_wint_t.h
utils.o: /usr/include/sys/_types/_blkcnt_t.h
utils.o: /usr/include/sys/types.h
utils.o: /usr/include/sys/_types/_gid_t.h
utils.o: /usr/include/sys/_types/_blksize_t.h
utils.o: /usr/include/sys/_types/_in_addr_t.h
utils.o: /usr/include/sys/_types/_ino_t.h
utils.o: /usr/include/sys/_types/_in_port_t.h
utils.o: /usr/include/sys/_types/_key_t.h
utils.o: /usr/include/sys/_types/_ino64_t.h
utils.o: /usr/include/sys/_types/_clock_t.h
utils.o: /usr/include/sys/_types/_nlink_t.h
utils.o: /usr/include/sys/_types/_time_t.h
utils.o: /usr/include/sys/_types/_useconds_t.h
utils.o: /usr/include/sys/_types/_suseconds_t.h
utils.o: /usr/include/sys/_types/_fd_def.h
utils.o: /usr/include/sys/_types/_fd_setsize.h
utils.o: /usr/include/sys/_types/_fd_clr.h
utils.o: /usr/include/sys/_types/_fd_set.h
utils.o: /usr/include/sys/_types/_fd_isset.h
utils.o: /usr/include/sys/_types/_fd_zero.h
utils.o: /usr/include/sys/_types/_fd_copy.h
utils.o: /usr/include/sys/_pthread/_pthread_cond_t.h
utils.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
utils.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
utils.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
utils.o: /usr/include/sys/_pthread/_pthread_once_t.h
utils.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
utils.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
utils.o: /usr/include/sys/_pthread/_pthread_t.h
utils.o: /usr/include/sys/_pthread/_pthread_key_t.h
utils.o: /usr/include/sys/_types/_fsblkcnt_t.h
utils.o: /usr/include/unistd.h
utils.o: /usr/include/sys/_types/_fsfilcnt_t.h
utils.o: /usr/include/sys/_types/_posix_vdisable.h
utils.o: /usr/include/sys/unistd.h
utils.o: /usr/include/sys/select.h
utils.o: /usr/include/sys/_types/_seek_set.h
utils.o: /usr/include/sys/_select.h
utils.o: /usr/include/sys/_types/_timespec.h
utils.o: /usr/include/gethostuuid.h
utils.o: /usr/include/sys/_types/_uuid_t.h
utils.o: ../../include/lutil_lockf.h
utils.o: /usr/include/getopt.h
utils.o: /usr/include/sys/time.h
utils.o: ../../include/ac/time.h
utils.o: /usr/include/time.h
utils.o: /usr/include/sys/_types/_timeval64.h
utils.o: /usr/include/errno.h
utils.o: /usr/include/sys/errno.h
utils.o: ../../include/ac/errno.h
utils.o: /usr/include/sys/fcntl.h
utils.o: /usr/include/fcntl.h
utils.o: /usr/include/sys/_types/_o_dsync.h
utils.o: /usr/include/sys/_types/_o_sync.h
utils.o: /usr/include/sys/_types/_filesec_t.h
utils.o: /usr/include/sys/_types/_s_ifmt.h
utils.o: ../../include/lber_types.h
utils.o: ../../include/lutil.h
utils.o: ../../include/ldap_config.h
utils.o: ../../include/ldap_defaults.h
utils.o: ../../include/lber.h
utils.o: ../../include/lber_pvt.h
utils.o: ../../include/ldap_pvt.h
utils.o: ../../include/ac/bytes.h
utils.o: ../../include/ldap_pvt_uc.h
utils.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
uuid.o: ../../include/portable.h
uuid.o: uuid.c
uuid.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
uuid.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
uuid.o: ../../include/ldap_cdefs.h
uuid.o: ../../include/ac/fdset.h
uuid.o: ../../include/ac/assert.h
uuid.o: ../../include/ldap_features.h
uuid.o: /usr/include/sys/cdefs.h
uuid.o: /usr/include/assert.h
uuid.o: /usr/include/sys/_symbol_aliasing.h
uuid.o: ../../include/ac/localize.h
uuid.o: /usr/include/sys/_posix_availability.h
uuid.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
uuid.o: /usr/include/machine/limits.h
uuid.o: /usr/include/limits.h
uuid.o: /usr/include/i386/_limits.h
uuid.o: /usr/include/i386/limits.h
uuid.o: /usr/include/stdio.h
uuid.o: /usr/include/sys/syslimits.h
uuid.o: /usr/include/AvailabilityInternal.h
uuid.o: /usr/include/Availability.h
uuid.o: /usr/include/sys/_types.h
uuid.o: /usr/include/_types.h
uuid.o: /usr/include/i386/_types.h
uuid.o: /usr/include/machine/_types.h
uuid.o: /usr/include/sys/_pthread/_pthread_types.h
uuid.o: /usr/include/sys/_types/_size_t.h
uuid.o: /usr/include/sys/_types/_va_list.h
uuid.o: /usr/include/sys/stdio.h
uuid.o: /usr/include/sys/_types/_null.h
uuid.o: /usr/include/sys/_types/_ssize_t.h
uuid.o: /usr/include/sys/_types/_off_t.h
uuid.o: /usr/include/secure/_common.h
uuid.o: /usr/include/secure/_stdio.h
uuid.o: /usr/include/sys/appleapiopts.h
uuid.o: /usr/include/sys/types.h
uuid.o: /usr/include/i386/types.h
uuid.o: /usr/include/machine/types.h
uuid.o: /usr/include/sys/_types/_int16_t.h
uuid.o: /usr/include/sys/_types/_int8_t.h
uuid.o: /usr/include/sys/_types/_int64_t.h
uuid.o: /usr/include/sys/_types/_int32_t.h
uuid.o: /usr/include/sys/_types/_u_int8_t.h
uuid.o: /usr/include/sys/_types/_u_int16_t.h
uuid.o: /usr/include/sys/_types/_u_int32_t.h
uuid.o: /usr/include/sys/_types/_u_int64_t.h
uuid.o: /usr/include/sys/_types/_intptr_t.h
uuid.o: /usr/include/machine/endian.h
uuid.o: /usr/include/sys/_types/_uintptr_t.h
uuid.o: /usr/include/sys/_endian.h
uuid.o: /usr/include/i386/endian.h
uuid.o: /usr/include/libkern/_OSByteOrder.h
uuid.o: /usr/include/libkern/i386/_OSByteOrder.h
uuid.o: /usr/include/sys/_types/_blkcnt_t.h
uuid.o: /usr/include/sys/_types/_dev_t.h
uuid.o: /usr/include/sys/_types/_gid_t.h
uuid.o: /usr/include/sys/_types/_blksize_t.h
uuid.o: /usr/include/sys/_types/_in_addr_t.h
uuid.o: /usr/include/sys/_types/_ino_t.h
uuid.o: /usr/include/sys/_types/_in_port_t.h
uuid.o: /usr/include/sys/_types/_key_t.h
uuid.o: /usr/include/sys/_types/_ino64_t.h
uuid.o: /usr/include/sys/_types/_nlink_t.h
uuid.o: /usr/include/sys/_types/_mode_t.h
uuid.o: /usr/include/sys/_types/_pid_t.h
uuid.o: /usr/include/sys/_types/_id_t.h
uuid.o: /usr/include/sys/_types/_clock_t.h
uuid.o: /usr/include/sys/_types/_uid_t.h
uuid.o: /usr/include/sys/_types/_time_t.h
uuid.o: /usr/include/sys/_types/_useconds_t.h
uuid.o: /usr/include/sys/_types/_suseconds_t.h
uuid.o: /usr/include/sys/_types/_errno_t.h
uuid.o: /usr/include/sys/_types/_rsize_t.h
uuid.o: /usr/include/sys/_types/_fd_def.h
uuid.o: /usr/include/sys/_types/_fd_setsize.h
uuid.o: /usr/include/sys/_types/_fd_clr.h
uuid.o: /usr/include/sys/_types/_fd_set.h
uuid.o: /usr/include/sys/_types/_fd_isset.h
uuid.o: /usr/include/sys/_types/_fd_zero.h
uuid.o: /usr/include/sys/_types/_fd_copy.h
uuid.o: /usr/include/sys/_pthread/_pthread_attr_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_cond_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_once_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_t.h
uuid.o: /usr/include/sys/_pthread/_pthread_key_t.h
uuid.o: /usr/include/sys/_types/_fsblkcnt_t.h
uuid.o: ../../include/ac/stdlib.h
uuid.o: /usr/include/sys/_types/_fsfilcnt_t.h
uuid.o: /usr/include/sys/wait.h
uuid.o: /usr/include/stdlib.h
uuid.o: /usr/include/machine/signal.h
uuid.o: /usr/include/sys/signal.h
uuid.o: /usr/include/machine/_mcontext.h
uuid.o: /usr/include/i386/signal.h
uuid.o: /usr/include/mach/i386/_structs.h
uuid.o: /usr/include/i386/_mcontext.h
uuid.o: /usr/include/sys/_types/_sigaltstack.h
uuid.o: /usr/include/sys/_types/_ucontext.h
uuid.o: /usr/include/sys/resource.h
uuid.o: /usr/include/sys/_types/_sigset_t.h
uuid.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
uuid.o: /usr/include/_types/_uint8_t.h
uuid.o: /usr/include/stdint.h
uuid.o: /usr/include/_types/_uint32_t.h
uuid.o: /usr/include/_types/_uint16_t.h
uuid.o: /usr/include/_types/_intmax_t.h
uuid.o: /usr/include/_types/_uint64_t.h
uuid.o: /usr/include/sys/_types/_timeval.h
uuid.o: /usr/include/_types/_uintmax_t.h
uuid.o: /usr/include/sys/_types/_ct_rune_t.h
uuid.o: /usr/include/alloca.h
uuid.o: /usr/include/sys/_types/_wchar_t.h
uuid.o: /usr/include/sys/_types/_rune_t.h
uuid.o: /usr/include/string.h
uuid.o: /usr/include/strings.h
uuid.o: ../../include/ac/string.h
uuid.o: /usr/include/uuid/uuid.h
uuid.o: /usr/include/secure/_string.h
uuid.o: ../../include/lutil.h
uuid.o: /usr/include/sys/_types/_uuid_t.h
uuid.o: ../../include/lber_types.h
sockpair.o: ../../include/portable.h
sockpair.o: sockpair.c
sockpair.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
sockpair.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
sockpair.o: ../../include/ldap_cdefs.h
sockpair.o: ../../include/ac/fdset.h
sockpair.o: ../../include/ac/assert.h
sockpair.o: ../../include/ldap_features.h
sockpair.o: /usr/include/sys/cdefs.h
sockpair.o: /usr/include/assert.h
sockpair.o: /usr/include/sys/_symbol_aliasing.h
sockpair.o: ../../include/ac/localize.h
sockpair.o: /usr/include/sys/_posix_availability.h
sockpair.o: /usr/include/sys/types.h
sockpair.o: ../../include/ac/socket.h
sockpair.o: /usr/include/machine/types.h
sockpair.o: /usr/include/sys/appleapiopts.h
sockpair.o: /usr/include/i386/_types.h
sockpair.o: /usr/include/i386/types.h
sockpair.o: /usr/include/sys/_types/_int16_t.h
sockpair.o: /usr/include/sys/_types/_int8_t.h
sockpair.o: /usr/include/sys/_types/_int64_t.h
sockpair.o: /usr/include/sys/_types/_int32_t.h
sockpair.o: /usr/include/sys/_types/_u_int8_t.h
sockpair.o: /usr/include/sys/_types/_u_int16_t.h
sockpair.o: /usr/include/sys/_types/_u_int32_t.h
sockpair.o: /usr/include/sys/_types/_u_int64_t.h
sockpair.o: /usr/include/sys/_types/_intptr_t.h
sockpair.o: /usr/include/sys/_types.h
sockpair.o: /usr/include/sys/_types/_uintptr_t.h
sockpair.o: /usr/include/machine/_types.h
sockpair.o: /usr/include/sys/_pthread/_pthread_types.h
sockpair.o: /usr/include/i386/endian.h
sockpair.o: /usr/include/machine/endian.h
sockpair.o: /usr/include/libkern/_OSByteOrder.h
sockpair.o: /usr/include/sys/_endian.h
sockpair.o: /usr/include/libkern/i386/_OSByteOrder.h
sockpair.o: /usr/include/sys/_types/_blkcnt_t.h
sockpair.o: /usr/include/sys/_types/_dev_t.h
sockpair.o: /usr/include/sys/_types/_gid_t.h
sockpair.o: /usr/include/sys/_types/_blksize_t.h
sockpair.o: /usr/include/sys/_types/_in_addr_t.h
sockpair.o: /usr/include/sys/_types/_ino_t.h
sockpair.o: /usr/include/sys/_types/_in_port_t.h
sockpair.o: /usr/include/sys/_types/_key_t.h
sockpair.o: /usr/include/sys/_types/_ino64_t.h
sockpair.o: /usr/include/sys/_types/_nlink_t.h
sockpair.o: /usr/include/sys/_types/_mode_t.h
sockpair.o: /usr/include/sys/_types/_pid_t.h
sockpair.o: /usr/include/sys/_types/_id_t.h
sockpair.o: /usr/include/sys/_types/_uid_t.h
sockpair.o: /usr/include/sys/_types/_off_t.h
sockpair.o: /usr/include/sys/_types/_size_t.h
sockpair.o: /usr/include/sys/_types/_clock_t.h
sockpair.o: /usr/include/sys/_types/_time_t.h
sockpair.o: /usr/include/sys/_types/_ssize_t.h
sockpair.o: /usr/include/sys/_types/_useconds_t.h
sockpair.o: /usr/include/sys/_types/_suseconds_t.h
sockpair.o: /usr/include/sys/_types/_errno_t.h
sockpair.o: /usr/include/sys/_types/_rsize_t.h
sockpair.o: /usr/include/sys/_types/_fd_def.h
sockpair.o: /usr/include/sys/_types/_fd_setsize.h
sockpair.o: /usr/include/sys/_types/_fd_clr.h
sockpair.o: /usr/include/sys/_types/_fd_set.h
sockpair.o: /usr/include/sys/_types/_fd_isset.h
sockpair.o: /usr/include/sys/_types/_fd_zero.h
sockpair.o: /usr/include/sys/_types/_fd_copy.h
sockpair.o: /usr/include/sys/_pthread/_pthread_attr_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_cond_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_once_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_t.h
sockpair.o: /usr/include/sys/_pthread/_pthread_key_t.h
sockpair.o: /usr/include/sys/_types/_fsblkcnt_t.h
sockpair.o: /usr/include/poll.h
sockpair.o: /usr/include/sys/_types/_fsfilcnt_t.h
sockpair.o: /usr/include/sys/socket.h
sockpair.o: /usr/include/sys/poll.h
sockpair.o: /usr/include/i386/_param.h
sockpair.o: /usr/include/machine/_param.h
sockpair.o: /usr/include/Availability.h
sockpair.o: /usr/include/net/net_kev.h
sockpair.o: /usr/include/AvailabilityInternal.h
sockpair.o: /usr/include/sys/_types/_sa_family_t.h
sockpair.o: /usr/include/sys/_types/_socklen_t.h
sockpair.o: /usr/include/sys/un.h
sockpair.o: /usr/include/sys/_types/_iovec_t.h
sockpair.o: /usr/include/sys/_types/_timespec.h
sockpair.o: /usr/include/sys/select.h
sockpair.o: /usr/include/sys/_types/_sigset_t.h
sockpair.o: /usr/include/sys/_types/_timeval.h
sockpair.o: /usr/include/netinet/in.h
sockpair.o: /usr/include/sys/_select.h
sockpair.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
sockpair.o: /usr/include/_types/_uint8_t.h
sockpair.o: /usr/include/stdint.h
sockpair.o: /usr/include/_types/_uint32_t.h
sockpair.o: /usr/include/_types/_uint16_t.h
sockpair.o: /usr/include/_types/_intmax_t.h
sockpair.o: /usr/include/_types/_uint64_t.h
sockpair.o: /usr/include/netinet6/in6.h
sockpair.o: /usr/include/_types/_uintmax_t.h
sockpair.o: /usr/include/arpa/inet.h
sockpair.o: /usr/include/netinet/tcp.h
sockpair.o: /usr/include/sys/param.h
sockpair.o: /usr/include/arpa/nameser.h
sockpair.o: /usr/include/sys/syslimits.h
sockpair.o: /usr/include/sys/_types/_null.h
sockpair.o: /usr/include/i386/param.h
sockpair.o: /usr/include/machine/param.h
sockpair.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
sockpair.o: /usr/include/machine/limits.h
sockpair.o: /usr/include/limits.h
sockpair.o: /usr/include/i386/_limits.h
sockpair.o: /usr/include/i386/limits.h
sockpair.o: /usr/include/machine/signal.h
sockpair.o: /usr/include/sys/signal.h
sockpair.o: /usr/include/machine/_mcontext.h
sockpair.o: /usr/include/i386/signal.h
sockpair.o: /usr/include/mach/i386/_structs.h
sockpair.o: /usr/include/i386/_mcontext.h
sockpair.o: /usr/include/sys/_types/_sigaltstack.h
sockpair.o: /usr/include/netdb.h
sockpair.o: /usr/include/sys/_types/_ucontext.h
sockpair.o: /usr/include/resolv.h
sockpair.o: /usr/include/stdio.h
sockpair.o: /usr/include/_types.h
sockpair.o: /usr/include/sys/stdio.h
sockpair.o: /usr/include/sys/_types/_va_list.h
sockpair.o: /usr/include/secure/_common.h
sockpair.o: /usr/include/secure/_stdio.h
sockpair.o: /usr/include/unistd.h
sockpair.o: ../../include/ac/unistd.h
sockpair.o: /usr/include/sys/_types/_posix_vdisable.h
sockpair.o: /usr/include/sys/unistd.h
sockpair.o: /usr/include/sys/_types/_uuid_t.h
sockpair.o: /usr/include/sys/_types/_seek_set.h
sockpair.o: /usr/include/getopt.h
sockpair.o: /usr/include/gethostuuid.h
sockpair.o: ../../include/lutil.h
sockpair.o: ../../include/lutil_lockf.h
sockpair.o: ../../include/lber_types.h
avl.o: ../../include/portable.h
avl.o: avl.c
avl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
avl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
avl.o: ../../include/ldap_cdefs.h
avl.o: ../../include/ac/fdset.h
avl.o: ../../include/ac/assert.h
avl.o: ../../include/ldap_features.h
avl.o: /usr/include/sys/cdefs.h
avl.o: /usr/include/assert.h
avl.o: /usr/include/sys/_symbol_aliasing.h
avl.o: ../../include/ac/localize.h
avl.o: /usr/include/sys/_posix_availability.h
avl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
avl.o: /usr/include/machine/limits.h
avl.o: /usr/include/limits.h
avl.o: /usr/include/i386/_limits.h
avl.o: /usr/include/i386/limits.h
avl.o: /usr/include/stdio.h
avl.o: /usr/include/sys/syslimits.h
avl.o: /usr/include/AvailabilityInternal.h
avl.o: /usr/include/Availability.h
avl.o: /usr/include/sys/_types.h
avl.o: /usr/include/_types.h
avl.o: /usr/include/i386/_types.h
avl.o: /usr/include/machine/_types.h
avl.o: /usr/include/sys/_pthread/_pthread_types.h
avl.o: /usr/include/sys/_types/_size_t.h
avl.o: /usr/include/sys/_types/_va_list.h
avl.o: /usr/include/sys/stdio.h
avl.o: /usr/include/sys/_types/_null.h
avl.o: /usr/include/sys/_types/_ssize_t.h
avl.o: /usr/include/sys/_types/_off_t.h
avl.o: /usr/include/secure/_common.h
avl.o: /usr/include/secure/_stdio.h
avl.o: /usr/include/stdlib.h
avl.o: ../../include/ac/stdlib.h
avl.o: /usr/include/sys/_types/_pid_t.h
avl.o: /usr/include/sys/wait.h
avl.o: /usr/include/sys/signal.h
avl.o: /usr/include/sys/_types/_id_t.h
avl.o: /usr/include/machine/signal.h
avl.o: /usr/include/sys/appleapiopts.h
avl.o: /usr/include/machine/_mcontext.h
avl.o: /usr/include/i386/signal.h
avl.o: /usr/include/mach/i386/_structs.h
avl.o: /usr/include/i386/_mcontext.h
avl.o: /usr/include/sys/_pthread/_pthread_attr_t.h
avl.o: /usr/include/sys/_types/_sigaltstack.h
avl.o: /usr/include/sys/_types/_ucontext.h
avl.o: /usr/include/sys/_types/_uid_t.h
avl.o: /usr/include/sys/_types/_sigset_t.h
avl.o: /usr/include/sys/resource.h
avl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
avl.o: /usr/include/sys/_types/_int8_t.h
avl.o: /usr/include/stdint.h
avl.o: /usr/include/sys/_types/_int32_t.h
avl.o: /usr/include/sys/_types/_int16_t.h
avl.o: /usr/include/_types/_uint8_t.h
avl.o: /usr/include/sys/_types/_int64_t.h
avl.o: /usr/include/_types/_uint32_t.h
avl.o: /usr/include/_types/_uint16_t.h
avl.o: /usr/include/sys/_types/_intptr_t.h
avl.o: /usr/include/_types/_uint64_t.h
avl.o: /usr/include/_types/_intmax_t.h
avl.o: /usr/include/sys/_types/_uintptr_t.h
avl.o: /usr/include/sys/_types/_timeval.h
avl.o: /usr/include/_types/_uintmax_t.h
avl.o: /usr/include/i386/endian.h
avl.o: /usr/include/machine/endian.h
avl.o: /usr/include/libkern/_OSByteOrder.h
avl.o: /usr/include/sys/_endian.h
avl.o: /usr/include/alloca.h
avl.o: /usr/include/libkern/i386/_OSByteOrder.h
avl.o: /usr/include/sys/_types/_rune_t.h
avl.o: /usr/include/sys/_types/_ct_rune_t.h
avl.o: /usr/include/machine/types.h
avl.o: /usr/include/sys/_types/_wchar_t.h
avl.o: /usr/include/sys/_types/_u_int8_t.h
avl.o: /usr/include/i386/types.h
avl.o: /usr/include/sys/_types/_u_int16_t.h
avl.o: /usr/include/sys/_types/_u_int32_t.h
avl.o: /usr/include/sys/_types/_dev_t.h
avl.o: /usr/include/sys/_types/_u_int64_t.h
avl.o: ../../include/lber.h
avl.o: /usr/include/sys/_types/_mode_t.h
avl.o: /usr/include/string.h
avl.o: ../../include/lber_types.h
avl.o: /usr/include/sys/_types/_errno_t.h
avl.o: /usr/include/sys/_types/_rsize_t.h
avl.o: /usr/include/secure/_string.h
avl.o: /usr/include/strings.h
avl.o: ../../include/avl.h
tavl.o: ../../include/portable.h
tavl.o: tavl.c
tavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
tavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
tavl.o: ../../include/ldap_cdefs.h
tavl.o: ../../include/ac/fdset.h
tavl.o: ../../include/ac/assert.h
tavl.o: ../../include/ldap_features.h
tavl.o: /usr/include/sys/cdefs.h
tavl.o: /usr/include/assert.h
tavl.o: /usr/include/sys/_symbol_aliasing.h
tavl.o: ../../include/ac/localize.h
tavl.o: /usr/include/sys/_posix_availability.h
tavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
tavl.o: /usr/include/machine/limits.h
tavl.o: /usr/include/limits.h
tavl.o: /usr/include/i386/_limits.h
tavl.o: /usr/include/i386/limits.h
tavl.o: /usr/include/stdio.h
tavl.o: /usr/include/sys/syslimits.h
tavl.o: /usr/include/AvailabilityInternal.h
tavl.o: /usr/include/Availability.h
tavl.o: /usr/include/sys/_types.h
tavl.o: /usr/include/_types.h
tavl.o: /usr/include/i386/_types.h
tavl.o: /usr/include/machine/_types.h
tavl.o: /usr/include/sys/_pthread/_pthread_types.h
tavl.o: /usr/include/sys/_types/_size_t.h
tavl.o: /usr/include/sys/_types/_va_list.h
tavl.o: /usr/include/sys/stdio.h
tavl.o: /usr/include/sys/_types/_null.h
tavl.o: /usr/include/sys/_types/_ssize_t.h
tavl.o: /usr/include/sys/_types/_off_t.h
tavl.o: /usr/include/secure/_common.h
tavl.o: /usr/include/secure/_stdio.h
tavl.o: /usr/include/stdlib.h
tavl.o: ../../include/ac/stdlib.h
tavl.o: /usr/include/sys/_types/_pid_t.h
tavl.o: /usr/include/sys/wait.h
tavl.o: /usr/include/sys/signal.h
tavl.o: /usr/include/sys/_types/_id_t.h
tavl.o: /usr/include/machine/signal.h
tavl.o: /usr/include/sys/appleapiopts.h
tavl.o: /usr/include/machine/_mcontext.h
tavl.o: /usr/include/i386/signal.h
tavl.o: /usr/include/mach/i386/_structs.h
tavl.o: /usr/include/i386/_mcontext.h
tavl.o: /usr/include/sys/_pthread/_pthread_attr_t.h
tavl.o: /usr/include/sys/_types/_sigaltstack.h
tavl.o: /usr/include/sys/_types/_ucontext.h
tavl.o: /usr/include/sys/_types/_uid_t.h
tavl.o: /usr/include/sys/_types/_sigset_t.h
tavl.o: /usr/include/sys/resource.h
tavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
tavl.o: /usr/include/sys/_types/_int8_t.h
tavl.o: /usr/include/stdint.h
tavl.o: /usr/include/sys/_types/_int32_t.h
tavl.o: /usr/include/sys/_types/_int16_t.h
tavl.o: /usr/include/_types/_uint8_t.h
tavl.o: /usr/include/sys/_types/_int64_t.h
tavl.o: /usr/include/_types/_uint32_t.h
tavl.o: /usr/include/_types/_uint16_t.h
tavl.o: /usr/include/sys/_types/_intptr_t.h
tavl.o: /usr/include/_types/_uint64_t.h
tavl.o: /usr/include/_types/_intmax_t.h
tavl.o: /usr/include/sys/_types/_uintptr_t.h
tavl.o: /usr/include/sys/_types/_timeval.h
tavl.o: /usr/include/_types/_uintmax_t.h
tavl.o: /usr/include/i386/endian.h
tavl.o: /usr/include/machine/endian.h
tavl.o: /usr/include/libkern/_OSByteOrder.h
tavl.o: /usr/include/sys/_endian.h
tavl.o: /usr/include/alloca.h
tavl.o: /usr/include/libkern/i386/_OSByteOrder.h
tavl.o: /usr/include/sys/_types/_rune_t.h
tavl.o: /usr/include/sys/_types/_ct_rune_t.h
tavl.o: /usr/include/machine/types.h
tavl.o: /usr/include/sys/_types/_wchar_t.h
tavl.o: /usr/include/sys/_types/_u_int8_t.h
tavl.o: /usr/include/i386/types.h
tavl.o: /usr/include/sys/_types/_u_int16_t.h
tavl.o: /usr/include/sys/_types/_u_int32_t.h
tavl.o: /usr/include/sys/_types/_dev_t.h
tavl.o: /usr/include/sys/_types/_u_int64_t.h
tavl.o: ../../include/lber.h
tavl.o: /usr/include/sys/_types/_mode_t.h
tavl.o: /usr/include/string.h
tavl.o: ../../include/lber_types.h
tavl.o: /usr/include/sys/_types/_errno_t.h
tavl.o: /usr/include/sys/_types/_rsize_t.h
tavl.o: /usr/include/secure/_string.h
tavl.o: /usr/include/strings.h
tavl.o: ../../include/avl.h
testavl.o: ../../include/portable.h
testavl.o: testavl.c
testavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
testavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
testavl.o: ../../include/ldap_cdefs.h
testavl.o: ../../include/ac/fdset.h
testavl.o: ../../include/ac/assert.h
testavl.o: ../../include/ldap_features.h
testavl.o: /usr/include/sys/cdefs.h
testavl.o: /usr/include/assert.h
testavl.o: /usr/include/sys/_symbol_aliasing.h
testavl.o: ../../include/ac/localize.h
testavl.o: /usr/include/sys/_posix_availability.h
testavl.o: /usr/include/Availability.h
testavl.o: /usr/include/stdio.h
testavl.o: /usr/include/_types.h
testavl.o: /usr/include/AvailabilityInternal.h
testavl.o: /usr/include/machine/_types.h
testavl.o: /usr/include/sys/_types.h
testavl.o: /usr/include/sys/_pthread/_pthread_types.h
testavl.o: /usr/include/i386/_types.h
testavl.o: /usr/include/sys/_types/_size_t.h
testavl.o: /usr/include/sys/_types/_va_list.h
testavl.o: /usr/include/sys/stdio.h
testavl.o: /usr/include/sys/_types/_null.h
testavl.o: /usr/include/sys/_types/_ssize_t.h
testavl.o: /usr/include/sys/_types/_off_t.h
testavl.o: /usr/include/secure/_common.h
testavl.o: /usr/include/secure/_stdio.h
testavl.o: /usr/include/stdlib.h
testavl.o: ../../include/ac/stdlib.h
testavl.o: /usr/include/sys/_types/_pid_t.h
testavl.o: /usr/include/sys/wait.h
testavl.o: /usr/include/sys/signal.h
testavl.o: /usr/include/sys/_types/_id_t.h
testavl.o: /usr/include/machine/signal.h
testavl.o: /usr/include/sys/appleapiopts.h
testavl.o: /usr/include/machine/_mcontext.h
testavl.o: /usr/include/i386/signal.h
testavl.o: /usr/include/mach/i386/_structs.h
testavl.o: /usr/include/i386/_mcontext.h
testavl.o: /usr/include/sys/_pthread/_pthread_attr_t.h
testavl.o: /usr/include/sys/_types/_sigaltstack.h
testavl.o: /usr/include/sys/_types/_ucontext.h
testavl.o: /usr/include/sys/_types/_uid_t.h
testavl.o: /usr/include/sys/_types/_sigset_t.h
testavl.o: /usr/include/sys/resource.h
testavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
testavl.o: /usr/include/sys/_types/_int8_t.h
testavl.o: /usr/include/stdint.h
testavl.o: /usr/include/sys/_types/_int32_t.h
testavl.o: /usr/include/sys/_types/_int16_t.h
testavl.o: /usr/include/_types/_uint8_t.h
testavl.o: /usr/include/sys/_types/_int64_t.h
testavl.o: /usr/include/_types/_uint32_t.h
testavl.o: /usr/include/_types/_uint16_t.h
testavl.o: /usr/include/sys/_types/_intptr_t.h
testavl.o: /usr/include/_types/_uint64_t.h
testavl.o: /usr/include/_types/_intmax_t.h
testavl.o: /usr/include/sys/_types/_uintptr_t.h
testavl.o: /usr/include/sys/_types/_timeval.h
testavl.o: /usr/include/_types/_uintmax_t.h
testavl.o: /usr/include/i386/endian.h
testavl.o: /usr/include/machine/endian.h
testavl.o: /usr/include/libkern/_OSByteOrder.h
testavl.o: /usr/include/sys/_endian.h
testavl.o: /usr/include/alloca.h
testavl.o: /usr/include/libkern/i386/_OSByteOrder.h
testavl.o: /usr/include/sys/_types/_rune_t.h
testavl.o: /usr/include/sys/_types/_ct_rune_t.h
testavl.o: /usr/include/machine/types.h
testavl.o: /usr/include/sys/_types/_wchar_t.h
testavl.o: /usr/include/sys/_types/_u_int8_t.h
testavl.o: /usr/include/i386/types.h
testavl.o: /usr/include/sys/_types/_u_int16_t.h
testavl.o: /usr/include/sys/_types/_u_int32_t.h
testavl.o: /usr/include/sys/_types/_dev_t.h
testavl.o: /usr/include/sys/_types/_u_int64_t.h
testavl.o: /usr/include/sys/_types/_mode_t.h
testavl.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
testavl.o: /usr/include/machine/limits.h
testavl.o: /usr/include/limits.h
testavl.o: /usr/include/i386/_limits.h
testavl.o: /usr/include/i386/limits.h
testavl.o: ../../include/ac/string.h
testavl.o: /usr/include/sys/syslimits.h
testavl.o: /usr/include/sys/_types/_rsize_t.h
testavl.o: /usr/include/string.h
testavl.o: /usr/include/strings.h
testavl.o: /usr/include/sys/_types/_errno_t.h
testavl.o: ../../include/avl.h
testavl.o: /usr/include/secure/_string.h
meter.o: ../../include/portable.h
meter.o: meter.c
meter.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
meter.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
meter.o: ../../include/ldap_cdefs.h
meter.o: ../../include/ac/fdset.h
meter.o: ../../include/ac/assert.h
meter.o: ../../include/ldap_features.h
meter.o: /usr/include/sys/cdefs.h
meter.o: /usr/include/assert.h
meter.o: /usr/include/sys/_symbol_aliasing.h
meter.o: ../../include/ac/localize.h
meter.o: /usr/include/sys/_posix_availability.h
meter.o: ../../include/lutil_meter.h
meter.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
meter.o: /usr/include/machine/limits.h
meter.o: /usr/include/limits.h
meter.o: /usr/include/i386/_limits.h
meter.o: /usr/include/i386/limits.h
meter.o: /usr/include/stdio.h
meter.o: /usr/include/sys/syslimits.h
meter.o: /usr/include/AvailabilityInternal.h
meter.o: /usr/include/Availability.h
meter.o: /usr/include/sys/_types.h
meter.o: /usr/include/_types.h
meter.o: /usr/include/i386/_types.h
meter.o: /usr/include/machine/_types.h
meter.o: /usr/include/sys/_pthread/_pthread_types.h
meter.o: /usr/include/sys/_types/_size_t.h
meter.o: /usr/include/sys/_types/_va_list.h
meter.o: /usr/include/sys/stdio.h
meter.o: /usr/include/sys/_types/_null.h
meter.o: /usr/include/sys/_types/_ssize_t.h
meter.o: /usr/include/sys/_types/_off_t.h
meter.o: /usr/include/secure/_common.h
meter.o: /usr/include/secure/_stdio.h
meter.o: /usr/include/sys/appleapiopts.h
meter.o: /usr/include/sys/types.h
meter.o: /usr/include/i386/types.h
meter.o: /usr/include/machine/types.h
meter.o: /usr/include/sys/_types/_int16_t.h
meter.o: /usr/include/sys/_types/_int8_t.h
meter.o: /usr/include/sys/_types/_int64_t.h
meter.o: /usr/include/sys/_types/_int32_t.h
meter.o: /usr/include/sys/_types/_u_int8_t.h
meter.o: /usr/include/sys/_types/_u_int16_t.h
meter.o: /usr/include/sys/_types/_u_int32_t.h
meter.o: /usr/include/sys/_types/_u_int64_t.h
meter.o: /usr/include/sys/_types/_intptr_t.h
meter.o: /usr/include/machine/endian.h
meter.o: /usr/include/sys/_types/_uintptr_t.h
meter.o: /usr/include/sys/_endian.h
meter.o: /usr/include/i386/endian.h
meter.o: /usr/include/libkern/_OSByteOrder.h
meter.o: /usr/include/libkern/i386/_OSByteOrder.h
meter.o: /usr/include/sys/_types/_blkcnt_t.h
meter.o: /usr/include/sys/_types/_dev_t.h
meter.o: /usr/include/sys/_types/_gid_t.h
meter.o: /usr/include/sys/_types/_blksize_t.h
meter.o: /usr/include/sys/_types/_in_addr_t.h
meter.o: /usr/include/sys/_types/_ino_t.h
meter.o: /usr/include/sys/_types/_in_port_t.h
meter.o: /usr/include/sys/_types/_key_t.h
meter.o: /usr/include/sys/_types/_ino64_t.h
meter.o: /usr/include/sys/_types/_nlink_t.h
meter.o: /usr/include/sys/_types/_mode_t.h
meter.o: /usr/include/sys/_types/_pid_t.h
meter.o: /usr/include/sys/_types/_id_t.h
meter.o: /usr/include/sys/_types/_clock_t.h
meter.o: /usr/include/sys/_types/_uid_t.h
meter.o: /usr/include/sys/_types/_time_t.h
meter.o: /usr/include/sys/_types/_useconds_t.h
meter.o: /usr/include/sys/_types/_suseconds_t.h
meter.o: /usr/include/sys/_types/_errno_t.h
meter.o: /usr/include/sys/_types/_rsize_t.h
meter.o: /usr/include/sys/_types/_fd_def.h
meter.o: /usr/include/sys/_types/_fd_setsize.h
meter.o: /usr/include/sys/_types/_fd_clr.h
meter.o: /usr/include/sys/_types/_fd_set.h
meter.o: /usr/include/sys/_types/_fd_isset.h
meter.o: /usr/include/sys/_types/_fd_zero.h
meter.o: /usr/include/sys/_types/_fd_copy.h
meter.o: /usr/include/sys/_pthread/_pthread_attr_t.h
meter.o: /usr/include/sys/_pthread/_pthread_cond_t.h
meter.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
meter.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
meter.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
meter.o: /usr/include/sys/_pthread/_pthread_once_t.h
meter.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
meter.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
meter.o: /usr/include/sys/_pthread/_pthread_t.h
meter.o: /usr/include/sys/_pthread/_pthread_key_t.h
meter.o: /usr/include/sys/_types/_fsblkcnt_t.h
meter.o: ../../include/ac/stdlib.h
meter.o: /usr/include/sys/_types/_fsfilcnt_t.h
meter.o: /usr/include/sys/wait.h
meter.o: /usr/include/stdlib.h
meter.o: /usr/include/machine/signal.h
meter.o: /usr/include/sys/signal.h
meter.o: /usr/include/machine/_mcontext.h
meter.o: /usr/include/i386/signal.h
meter.o: /usr/include/mach/i386/_structs.h
meter.o: /usr/include/i386/_mcontext.h
meter.o: /usr/include/sys/_types/_sigaltstack.h
meter.o: /usr/include/sys/_types/_ucontext.h
meter.o: /usr/include/sys/resource.h
meter.o: /usr/include/sys/_types/_sigset_t.h
meter.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
meter.o: /usr/include/_types/_uint8_t.h
meter.o: /usr/include/stdint.h
meter.o: /usr/include/_types/_uint32_t.h
meter.o: /usr/include/_types/_uint16_t.h
meter.o: /usr/include/_types/_intmax_t.h
meter.o: /usr/include/_types/_uint64_t.h
meter.o: /usr/include/sys/_types/_timeval.h
meter.o: /usr/include/_types/_uintmax_t.h
meter.o: /usr/include/sys/_types/_ct_rune_t.h
meter.o: /usr/include/alloca.h
meter.o: /usr/include/sys/_types/_wchar_t.h
meter.o: /usr/include/sys/_types/_rune_t.h
meter.o: /usr/include/sys/time.h
meter.o: ../../include/ac/time.h
meter.o: /usr/include/sys/_types/_timespec.h
meter.o: /usr/include/time.h
meter.o: /usr/include/sys/_types/_timeval64.h
meter.o: ../../include/ac/string.h
meter.o: /usr/include/sys/_select.h
meter.o: /usr/include/strings.h
meter.o: /usr/include/string.h
meter.o: /usr/include/secure/_string.h
setproctitle.o: ../../include/portable.h
setproctitle.o: setproctitle.c
setproctitle.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
setproctitle.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
setproctitle.o: ../../include/ldap_cdefs.h
setproctitle.o: ../../include/ac/fdset.h
setproctitle.o: ../../include/ac/assert.h
setproctitle.o: ../../include/ldap_features.h
setproctitle.o: /usr/include/sys/cdefs.h
setproctitle.o: /usr/include/assert.h
setproctitle.o: /usr/include/sys/_symbol_aliasing.h
setproctitle.o: ../../include/ac/localize.h
setproctitle.o: /usr/include/sys/_posix_availability.h
setproctitle.o: /usr/include/Availability.h
setproctitle.o: /usr/include/stdio.h
setproctitle.o: /usr/include/_types.h
setproctitle.o: /usr/include/AvailabilityInternal.h
setproctitle.o: /usr/include/machine/_types.h
setproctitle.o: /usr/include/sys/_types.h
setproctitle.o: /usr/include/sys/_pthread/_pthread_types.h
setproctitle.o: /usr/include/i386/_types.h
setproctitle.o: /usr/include/sys/_types/_size_t.h
setproctitle.o: /usr/include/sys/_types/_va_list.h
setproctitle.o: /usr/include/sys/stdio.h
setproctitle.o: /usr/include/sys/_types/_null.h
setproctitle.o: /usr/include/sys/_types/_ssize_t.h
setproctitle.o: /usr/include/sys/_types/_off_t.h
setproctitle.o: /usr/include/secure/_common.h
setproctitle.o: /usr/include/secure/_stdio.h
setproctitle.o: /usr/include/stdlib.h
setproctitle.o: ../../include/ac/stdlib.h
setproctitle.o: /usr/include/sys/_types/_pid_t.h
setproctitle.o: /usr/include/sys/wait.h
setproctitle.o: /usr/include/sys/signal.h
setproctitle.o: /usr/include/sys/_types/_id_t.h
setproctitle.o: /usr/include/machine/signal.h
setproctitle.o: /usr/include/sys/appleapiopts.h
setproctitle.o: /usr/include/machine/_mcontext.h
setproctitle.o: /usr/include/i386/signal.h
setproctitle.o: /usr/include/mach/i386/_structs.h
setproctitle.o: /usr/include/i386/_mcontext.h
setproctitle.o: /usr/include/sys/_pthread/_pthread_attr_t.h
setproctitle.o: /usr/include/sys/_types/_sigaltstack.h
setproctitle.o: /usr/include/sys/_types/_ucontext.h
setproctitle.o: /usr/include/sys/_types/_uid_t.h
setproctitle.o: /usr/include/sys/_types/_sigset_t.h
setproctitle.o: /usr/include/sys/resource.h
setproctitle.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
setproctitle.o: /usr/include/sys/_types/_int8_t.h
setproctitle.o: /usr/include/stdint.h
setproctitle.o: /usr/include/sys/_types/_int32_t.h
setproctitle.o: /usr/include/sys/_types/_int16_t.h
setproctitle.o: /usr/include/_types/_uint8_t.h
setproctitle.o: /usr/include/sys/_types/_int64_t.h
setproctitle.o: /usr/include/_types/_uint32_t.h
setproctitle.o: /usr/include/_types/_uint16_t.h
setproctitle.o: /usr/include/sys/_types/_intptr_t.h
setproctitle.o: /usr/include/_types/_uint64_t.h
setproctitle.o: /usr/include/_types/_intmax_t.h
setproctitle.o: /usr/include/sys/_types/_uintptr_t.h
setproctitle.o: /usr/include/sys/_types/_timeval.h
setproctitle.o: /usr/include/_types/_uintmax_t.h
setproctitle.o: /usr/include/i386/endian.h
setproctitle.o: /usr/include/machine/endian.h
setproctitle.o: /usr/include/libkern/_OSByteOrder.h
setproctitle.o: /usr/include/sys/_endian.h
setproctitle.o: /usr/include/alloca.h
setproctitle.o: /usr/include/libkern/i386/_OSByteOrder.h
setproctitle.o: /usr/include/sys/_types/_rune_t.h
setproctitle.o: /usr/include/sys/_types/_ct_rune_t.h
setproctitle.o: /usr/include/machine/types.h
setproctitle.o: /usr/include/sys/_types/_wchar_t.h
setproctitle.o: /usr/include/sys/_types/_u_int8_t.h
setproctitle.o: /usr/include/i386/types.h
setproctitle.o: /usr/include/sys/_types/_u_int16_t.h
setproctitle.o: /usr/include/sys/_types/_u_int32_t.h
setproctitle.o: /usr/include/sys/_types/_dev_t.h
setproctitle.o: /usr/include/sys/_types/_u_int64_t.h
setproctitle.o: /usr/include/sys/_types/_mode_t.h
setproctitle.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
setproctitle.o: /usr/include/machine/limits.h
setproctitle.o: /usr/include/limits.h
setproctitle.o: /usr/include/i386/_limits.h
setproctitle.o: /usr/include/i386/limits.h
setproctitle.o: ../../include/ac/setproctitle.h
setproctitle.o: /usr/include/sys/syslimits.h
setproctitle.o: /usr/include/string.h
setproctitle.o: ../../include/ac/string.h
setproctitle.o: /usr/include/sys/_types/_errno_t.h
setproctitle.o: /usr/include/sys/_types/_rsize_t.h
setproctitle.o: /usr/include/secure/_string.h
setproctitle.o: /usr/include/strings.h
setproctitle.o: ../../include/ac/stdarg.h
setproctitle.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdarg.h
detach.o: ../../include/portable.h
detach.o: detach.c
detach.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
detach.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
detach.o: ../../include/ldap_cdefs.h
detach.o: ../../include/ac/fdset.h
detach.o: ../../include/ac/assert.h
detach.o: ../../include/ldap_features.h
detach.o: /usr/include/sys/cdefs.h
detach.o: /usr/include/assert.h
detach.o: /usr/include/sys/_symbol_aliasing.h
detach.o: ../../include/ac/localize.h
detach.o: /usr/include/sys/_posix_availability.h
detach.o: /usr/include/Availability.h
detach.o: /usr/include/stdio.h
detach.o: /usr/include/_types.h
detach.o: /usr/include/AvailabilityInternal.h
detach.o: /usr/include/machine/_types.h
detach.o: /usr/include/sys/_types.h
detach.o: /usr/include/sys/_pthread/_pthread_types.h
detach.o: /usr/include/i386/_types.h
detach.o: /usr/include/sys/_types/_size_t.h
detach.o: /usr/include/sys/_types/_va_list.h
detach.o: /usr/include/sys/stdio.h
detach.o: /usr/include/sys/_types/_null.h
detach.o: /usr/include/sys/_types/_ssize_t.h
detach.o: /usr/include/sys/_types/_off_t.h
detach.o: /usr/include/secure/_common.h
detach.o: /usr/include/secure/_stdio.h
detach.o: /usr/include/stdlib.h
detach.o: ../../include/ac/stdlib.h
detach.o: /usr/include/sys/_types/_pid_t.h
detach.o: /usr/include/sys/wait.h
detach.o: /usr/include/sys/signal.h
detach.o: /usr/include/sys/_types/_id_t.h
detach.o: /usr/include/machine/signal.h
detach.o: /usr/include/sys/appleapiopts.h
detach.o: /usr/include/machine/_mcontext.h
detach.o: /usr/include/i386/signal.h
detach.o: /usr/include/mach/i386/_structs.h
detach.o: /usr/include/i386/_mcontext.h
detach.o: /usr/include/sys/_pthread/_pthread_attr_t.h
detach.o: /usr/include/sys/_types/_sigaltstack.h
detach.o: /usr/include/sys/_types/_ucontext.h
detach.o: /usr/include/sys/_types/_uid_t.h
detach.o: /usr/include/sys/_types/_sigset_t.h
detach.o: /usr/include/sys/resource.h
detach.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
detach.o: /usr/include/sys/_types/_int8_t.h
detach.o: /usr/include/stdint.h
detach.o: /usr/include/sys/_types/_int32_t.h
detach.o: /usr/include/sys/_types/_int16_t.h
detach.o: /usr/include/_types/_uint8_t.h
detach.o: /usr/include/sys/_types/_int64_t.h
detach.o: /usr/include/_types/_uint32_t.h
detach.o: /usr/include/_types/_uint16_t.h
detach.o: /usr/include/sys/_types/_intptr_t.h
detach.o: /usr/include/_types/_uint64_t.h
detach.o: /usr/include/_types/_intmax_t.h
detach.o: /usr/include/sys/_types/_uintptr_t.h
detach.o: /usr/include/sys/_types/_timeval.h
detach.o: /usr/include/_types/_uintmax_t.h
detach.o: /usr/include/i386/endian.h
detach.o: /usr/include/machine/endian.h
detach.o: /usr/include/libkern/_OSByteOrder.h
detach.o: /usr/include/sys/_endian.h
detach.o: /usr/include/alloca.h
detach.o: /usr/include/libkern/i386/_OSByteOrder.h
detach.o: /usr/include/sys/_types/_rune_t.h
detach.o: /usr/include/sys/_types/_ct_rune_t.h
detach.o: /usr/include/machine/types.h
detach.o: /usr/include/sys/_types/_wchar_t.h
detach.o: /usr/include/sys/_types/_u_int8_t.h
detach.o: /usr/include/i386/types.h
detach.o: /usr/include/sys/_types/_u_int16_t.h
detach.o: /usr/include/sys/_types/_u_int32_t.h
detach.o: /usr/include/sys/_types/_dev_t.h
detach.o: /usr/include/sys/_types/_u_int64_t.h
detach.o: /usr/include/sys/_types/_mode_t.h
detach.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
detach.o: /usr/include/machine/limits.h
detach.o: /usr/include/limits.h
detach.o: /usr/include/i386/_limits.h
detach.o: /usr/include/i386/limits.h
detach.o: ../../include/ac/signal.h
detach.o: /usr/include/sys/syslimits.h
detach.o: /usr/include/sys/_pthread/_pthread_t.h
detach.o: /usr/include/signal.h
detach.o: /usr/include/sys/types.h
detach.o: ../../include/ac/socket.h
detach.o: /usr/include/sys/_types/_blkcnt_t.h
detach.o: /usr/include/sys/_types/_gid_t.h
detach.o: /usr/include/sys/_types/_blksize_t.h
detach.o: /usr/include/sys/_types/_in_addr_t.h
detach.o: /usr/include/sys/_types/_ino_t.h
detach.o: /usr/include/sys/_types/_in_port_t.h
detach.o: /usr/include/sys/_types/_key_t.h
detach.o: /usr/include/sys/_types/_ino64_t.h
detach.o: /usr/include/sys/_types/_clock_t.h
detach.o: /usr/include/sys/_types/_nlink_t.h
detach.o: /usr/include/sys/_types/_time_t.h
detach.o: /usr/include/sys/_types/_useconds_t.h
detach.o: /usr/include/sys/_types/_suseconds_t.h
detach.o: /usr/include/sys/_types/_errno_t.h
detach.o: /usr/include/sys/_types/_rsize_t.h
detach.o: /usr/include/sys/_types/_fd_def.h
detach.o: /usr/include/sys/_types/_fd_setsize.h
detach.o: /usr/include/sys/_types/_fd_clr.h
detach.o: /usr/include/sys/_types/_fd_set.h
detach.o: /usr/include/sys/_types/_fd_isset.h
detach.o: /usr/include/sys/_types/_fd_zero.h
detach.o: /usr/include/sys/_types/_fd_copy.h
detach.o: /usr/include/sys/_pthread/_pthread_cond_t.h
detach.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
detach.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
detach.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
detach.o: /usr/include/sys/_pthread/_pthread_once_t.h
detach.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
detach.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
detach.o: /usr/include/sys/_pthread/_pthread_key_t.h
detach.o: /usr/include/sys/_types/_fsblkcnt_t.h
detach.o: /usr/include/poll.h
detach.o: /usr/include/sys/_types/_fsfilcnt_t.h
detach.o: /usr/include/sys/socket.h
detach.o: /usr/include/sys/poll.h
detach.o: /usr/include/i386/_param.h
detach.o: /usr/include/machine/_param.h
detach.o: /usr/include/sys/_types/_sa_family_t.h
detach.o: /usr/include/net/net_kev.h
detach.o: /usr/include/sys/_types/_socklen_t.h
detach.o: /usr/include/sys/un.h
detach.o: /usr/include/sys/_types/_iovec_t.h
detach.o: /usr/include/sys/_types/_timespec.h
detach.o: /usr/include/sys/select.h
detach.o: /usr/include/netinet/in.h
detach.o: /usr/include/sys/_select.h
detach.o: /usr/include/netinet/tcp.h
detach.o: /usr/include/netinet6/in6.h
detach.o: /usr/include/arpa/nameser.h
detach.o: /usr/include/arpa/inet.h
detach.o: /usr/include/machine/param.h
detach.o: /usr/include/sys/param.h
detach.o: /usr/include/netdb.h
detach.o: /usr/include/resolv.h
detach.o: /usr/include/i386/param.h
detach.o: /usr/include/unistd.h
detach.o: ../../include/ac/unistd.h
detach.o: /usr/include/sys/_types/_posix_vdisable.h
detach.o: /usr/include/sys/unistd.h
detach.o: /usr/include/sys/_types/_uuid_t.h
detach.o: /usr/include/sys/_types/_seek_set.h
detach.o: /usr/include/getopt.h
detach.o: /usr/include/gethostuuid.h
detach.o: /usr/include/sys/stat.h
detach.o: ../../include/lutil_lockf.h
detach.o: /usr/include/sys/_types/_filesec_t.h
detach.o: /usr/include/sys/_types/_s_ifmt.h
detach.o: /usr/include/sys/fcntl.h
detach.o: /usr/include/fcntl.h
detach.o: /usr/include/sys/_types/_o_dsync.h
detach.o: /usr/include/sys/_types/_o_sync.h
detach.o: /usr/include/sys/queue.h
detach.o: /usr/include/sys/file.h
detach.o: /usr/include/sys/ttycom.h
detach.o: /usr/include/sys/ioctl.h
detach.o: /usr/include/sys/filio.h
detach.o: /usr/include/sys/ioccom.h
detach.o: ../../include/lutil.h
detach.o: /usr/include/sys/sockio.h
detach.o: ../../include/lber_types.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
