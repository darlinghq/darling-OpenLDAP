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

# Makefile.in for LDAP -llunicode
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

LIBRARY = liblunicode.a

XXDIR = $(srcdir)/ucdata/
XXHEADERS = ucdata.h ure.h uctable.h

XXSRCS	= ucdata.c ucgendat.c ure.c urestubs.c
SRCS	= ucstr.c
OBJS	= ucdata.o ure.o urestubs.o ucstr.o

XLIB = $(LIBRARY)
XLIBS = $(LDAP_LIBLUTIL_A) $(LDAP_LIBLBER_LA)
#PROGRAMS = ucgendat

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

uctable.h: $(XXDIR)/uctable.h

$(XXDIR)/uctable.h: $(XXDIR)/ucgendat.c $(srcdir)/UnicodeData.txt $(srcdir)/CompositionExclusions.txt
	$(MAKE) ucgendat
	./ucgendat $(srcdir)/UnicodeData.txt -x $(srcdir)/CompositionExclusions.txt

ucgendat: $(XLIBS) ucgendat.o
	$(LTLINK) -o $@ ucgendat.o $(LIBS)

.links :
	@for i in $(XXSRCS) $(XXHEADERS); do \
		$(RM) $$i ; \
		ii=`find $(srcdir) -name $$i` ; \
		$(LN_S) $$ii . ; \
	done
	touch .links

$(XXSRCS) $(XXHEADERS) : .links

clean-local: FORCE
	@$(RM) *.dat .links $(XXHEADERS) ucgendat

depend-common: .links
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
# files: -I../../include -I../../include ucstr.c ucdata.c ucgendat.c ure.c urestubs.c
# command: cc -M -I.  -I../../include -I../../include ucstr.c ucdata.c ucgendat.c ure.c urestubs.c
#

ucstr.o: ../../include/portable.h
ucstr.o: ucstr.c
ucstr.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
ucstr.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
ucstr.o: ../../include/ldap_cdefs.h
ucstr.o: ../../include/ac/fdset.h
ucstr.o: ../../include/ac/assert.h
ucstr.o: ../../include/ldap_features.h
ucstr.o: /usr/include/sys/cdefs.h
ucstr.o: /usr/include/assert.h
ucstr.o: /usr/include/sys/_symbol_aliasing.h
ucstr.o: ../../include/ac/localize.h
ucstr.o: /usr/include/sys/_posix_availability.h
ucstr.o: ../../include/ac/ctype.h
ucstr.o: /usr/include/ctype.h
ucstr.o: ../../include/ac/bytes.h
ucstr.o: /usr/include/_types.h
ucstr.o: /usr/include/runetype.h
ucstr.o: /usr/include/machine/_types.h
ucstr.o: /usr/include/sys/_types.h
ucstr.o: /usr/include/sys/_pthread/_pthread_types.h
ucstr.o: /usr/include/i386/_types.h
ucstr.o: /usr/include/sys/_types/_ct_rune_t.h
ucstr.o: /usr/include/sys/_types/_size_t.h
ucstr.o: /usr/include/sys/_types/_wchar_t.h
ucstr.o: /usr/include/sys/_types/_rune_t.h
ucstr.o: ../../include/ac/string.h
ucstr.o: /usr/include/sys/_types/_wint_t.h
ucstr.o: /usr/include/Availability.h
ucstr.o: /usr/include/string.h
ucstr.o: /usr/include/sys/_types/_null.h
ucstr.o: /usr/include/AvailabilityInternal.h
ucstr.o: /usr/include/sys/_types/_errno_t.h
ucstr.o: /usr/include/sys/_types/_rsize_t.h
ucstr.o: /usr/include/strings.h
ucstr.o: /usr/include/sys/_types/_ssize_t.h
ucstr.o: /usr/include/secure/_common.h
ucstr.o: /usr/include/secure/_string.h
ucstr.o: /usr/include/stdlib.h
ucstr.o: ../../include/ac/stdlib.h
ucstr.o: /usr/include/sys/_types/_pid_t.h
ucstr.o: /usr/include/sys/wait.h
ucstr.o: /usr/include/sys/signal.h
ucstr.o: /usr/include/sys/_types/_id_t.h
ucstr.o: /usr/include/machine/signal.h
ucstr.o: /usr/include/sys/appleapiopts.h
ucstr.o: /usr/include/machine/_mcontext.h
ucstr.o: /usr/include/i386/signal.h
ucstr.o: /usr/include/mach/i386/_structs.h
ucstr.o: /usr/include/i386/_mcontext.h
ucstr.o: /usr/include/sys/_pthread/_pthread_attr_t.h
ucstr.o: /usr/include/sys/_types/_sigaltstack.h
ucstr.o: /usr/include/sys/_types/_ucontext.h
ucstr.o: /usr/include/sys/_types/_uid_t.h
ucstr.o: /usr/include/sys/_types/_sigset_t.h
ucstr.o: /usr/include/sys/resource.h
ucstr.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
ucstr.o: /usr/include/sys/_types/_int8_t.h
ucstr.o: /usr/include/stdint.h
ucstr.o: /usr/include/sys/_types/_int32_t.h
ucstr.o: /usr/include/sys/_types/_int16_t.h
ucstr.o: /usr/include/_types/_uint8_t.h
ucstr.o: /usr/include/sys/_types/_int64_t.h
ucstr.o: /usr/include/_types/_uint32_t.h
ucstr.o: /usr/include/_types/_uint16_t.h
ucstr.o: /usr/include/sys/_types/_intptr_t.h
ucstr.o: /usr/include/_types/_uint64_t.h
ucstr.o: /usr/include/_types/_intmax_t.h
ucstr.o: /usr/include/sys/_types/_uintptr_t.h
ucstr.o: /usr/include/sys/_types/_timeval.h
ucstr.o: /usr/include/_types/_uintmax_t.h
ucstr.o: /usr/include/i386/endian.h
ucstr.o: /usr/include/machine/endian.h
ucstr.o: /usr/include/libkern/_OSByteOrder.h
ucstr.o: /usr/include/sys/_endian.h
ucstr.o: /usr/include/alloca.h
ucstr.o: /usr/include/libkern/i386/_OSByteOrder.h
ucstr.o: /usr/include/i386/types.h
ucstr.o: /usr/include/machine/types.h
ucstr.o: /usr/include/sys/_types/_u_int8_t.h
ucstr.o: /usr/include/sys/_types/_u_int16_t.h
ucstr.o: /usr/include/sys/_types/_u_int32_t.h
ucstr.o: /usr/include/sys/_types/_dev_t.h
ucstr.o: /usr/include/sys/_types/_u_int64_t.h
ucstr.o: /usr/include/sys/_types/_mode_t.h
ucstr.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
ucstr.o: /usr/include/machine/limits.h
ucstr.o: /usr/include/limits.h
ucstr.o: /usr/include/i386/_limits.h
ucstr.o: /usr/include/i386/limits.h
ucstr.o: ../../include/lber_pvt.h
ucstr.o: /usr/include/sys/syslimits.h
ucstr.o: ../../include/lber_types.h
ucstr.o: ../../include/lber.h
ucstr.o: ../../include/ldap_pvt_uc.h
ucstr.o: ../../include/ldap_utf8.h
ucstr.o: ../../include/../libraries/liblunicode/ucdata/ucdata.h
ucdata.o: ../../include/portable.h
ucdata.o: ucdata.c
ucdata.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
ucdata.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
ucdata.o: ../../include/ldap_cdefs.h
ucdata.o: ../../include/ac/fdset.h
ucdata.o: ../../include/ac/assert.h
ucdata.o: ../../include/ldap_features.h
ucdata.o: /usr/include/sys/cdefs.h
ucdata.o: /usr/include/assert.h
ucdata.o: /usr/include/sys/_symbol_aliasing.h
ucdata.o: ../../include/ac/localize.h
ucdata.o: /usr/include/sys/_posix_availability.h
ucdata.o: /usr/include/stdio.h
ucdata.o: ../../include/ldap_config.h
ucdata.o: /usr/include/AvailabilityInternal.h
ucdata.o: /usr/include/Availability.h
ucdata.o: /usr/include/sys/_types.h
ucdata.o: /usr/include/_types.h
ucdata.o: /usr/include/i386/_types.h
ucdata.o: /usr/include/machine/_types.h
ucdata.o: /usr/include/sys/_pthread/_pthread_types.h
ucdata.o: /usr/include/sys/_types/_size_t.h
ucdata.o: /usr/include/sys/_types/_va_list.h
ucdata.o: /usr/include/sys/stdio.h
ucdata.o: /usr/include/sys/_types/_null.h
ucdata.o: /usr/include/sys/_types/_ssize_t.h
ucdata.o: /usr/include/sys/_types/_off_t.h
ucdata.o: /usr/include/secure/_common.h
ucdata.o: /usr/include/secure/_stdio.h
ucdata.o: /usr/include/stdlib.h
ucdata.o: ../../include/ac/stdlib.h
ucdata.o: /usr/include/sys/_types/_pid_t.h
ucdata.o: /usr/include/sys/wait.h
ucdata.o: /usr/include/sys/signal.h
ucdata.o: /usr/include/sys/_types/_id_t.h
ucdata.o: /usr/include/machine/signal.h
ucdata.o: /usr/include/sys/appleapiopts.h
ucdata.o: /usr/include/machine/_mcontext.h
ucdata.o: /usr/include/i386/signal.h
ucdata.o: /usr/include/mach/i386/_structs.h
ucdata.o: /usr/include/i386/_mcontext.h
ucdata.o: /usr/include/sys/_pthread/_pthread_attr_t.h
ucdata.o: /usr/include/sys/_types/_sigaltstack.h
ucdata.o: /usr/include/sys/_types/_ucontext.h
ucdata.o: /usr/include/sys/_types/_uid_t.h
ucdata.o: /usr/include/sys/_types/_sigset_t.h
ucdata.o: /usr/include/sys/resource.h
ucdata.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
ucdata.o: /usr/include/sys/_types/_int8_t.h
ucdata.o: /usr/include/stdint.h
ucdata.o: /usr/include/sys/_types/_int32_t.h
ucdata.o: /usr/include/sys/_types/_int16_t.h
ucdata.o: /usr/include/_types/_uint8_t.h
ucdata.o: /usr/include/sys/_types/_int64_t.h
ucdata.o: /usr/include/_types/_uint32_t.h
ucdata.o: /usr/include/_types/_uint16_t.h
ucdata.o: /usr/include/sys/_types/_intptr_t.h
ucdata.o: /usr/include/_types/_uint64_t.h
ucdata.o: /usr/include/_types/_intmax_t.h
ucdata.o: /usr/include/sys/_types/_uintptr_t.h
ucdata.o: /usr/include/sys/_types/_timeval.h
ucdata.o: /usr/include/_types/_uintmax_t.h
ucdata.o: /usr/include/i386/endian.h
ucdata.o: /usr/include/machine/endian.h
ucdata.o: /usr/include/libkern/_OSByteOrder.h
ucdata.o: /usr/include/sys/_endian.h
ucdata.o: /usr/include/alloca.h
ucdata.o: /usr/include/libkern/i386/_OSByteOrder.h
ucdata.o: /usr/include/sys/_types/_rune_t.h
ucdata.o: /usr/include/sys/_types/_ct_rune_t.h
ucdata.o: /usr/include/machine/types.h
ucdata.o: /usr/include/sys/_types/_wchar_t.h
ucdata.o: /usr/include/sys/_types/_u_int8_t.h
ucdata.o: /usr/include/i386/types.h
ucdata.o: /usr/include/sys/_types/_u_int16_t.h
ucdata.o: /usr/include/sys/_types/_u_int32_t.h
ucdata.o: /usr/include/sys/_types/_dev_t.h
ucdata.o: /usr/include/sys/_types/_u_int64_t.h
ucdata.o: /usr/include/sys/_types/_mode_t.h
ucdata.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
ucdata.o: /usr/include/machine/limits.h
ucdata.o: /usr/include/limits.h
ucdata.o: /usr/include/i386/_limits.h
ucdata.o: /usr/include/i386/limits.h
ucdata.o: ../../include/ac/string.h
ucdata.o: /usr/include/sys/syslimits.h
ucdata.o: /usr/include/sys/_types/_rsize_t.h
ucdata.o: /usr/include/string.h
ucdata.o: /usr/include/strings.h
ucdata.o: /usr/include/sys/_types/_errno_t.h
ucdata.o: ../../include/ac/unistd.h
ucdata.o: /usr/include/secure/_string.h
ucdata.o: /usr/include/sys/_types/_blkcnt_t.h
ucdata.o: /usr/include/sys/types.h
ucdata.o: /usr/include/sys/_types/_gid_t.h
ucdata.o: /usr/include/sys/_types/_blksize_t.h
ucdata.o: /usr/include/sys/_types/_in_addr_t.h
ucdata.o: /usr/include/sys/_types/_ino_t.h
ucdata.o: /usr/include/sys/_types/_in_port_t.h
ucdata.o: /usr/include/sys/_types/_key_t.h
ucdata.o: /usr/include/sys/_types/_ino64_t.h
ucdata.o: /usr/include/sys/_types/_clock_t.h
ucdata.o: /usr/include/sys/_types/_nlink_t.h
ucdata.o: /usr/include/sys/_types/_time_t.h
ucdata.o: /usr/include/sys/_types/_useconds_t.h
ucdata.o: /usr/include/sys/_types/_suseconds_t.h
ucdata.o: /usr/include/sys/_types/_fd_def.h
ucdata.o: /usr/include/sys/_types/_fd_setsize.h
ucdata.o: /usr/include/sys/_types/_fd_clr.h
ucdata.o: /usr/include/sys/_types/_fd_set.h
ucdata.o: /usr/include/sys/_types/_fd_isset.h
ucdata.o: /usr/include/sys/_types/_fd_zero.h
ucdata.o: /usr/include/sys/_types/_fd_copy.h
ucdata.o: /usr/include/sys/_pthread/_pthread_cond_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_once_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_t.h
ucdata.o: /usr/include/sys/_pthread/_pthread_key_t.h
ucdata.o: /usr/include/sys/_types/_fsblkcnt_t.h
ucdata.o: /usr/include/unistd.h
ucdata.o: /usr/include/sys/_types/_fsfilcnt_t.h
ucdata.o: /usr/include/sys/_types/_posix_vdisable.h
ucdata.o: /usr/include/sys/unistd.h
ucdata.o: /usr/include/sys/select.h
ucdata.o: /usr/include/sys/_types/_seek_set.h
ucdata.o: /usr/include/sys/_select.h
ucdata.o: /usr/include/sys/_types/_timespec.h
ucdata.o: /usr/include/gethostuuid.h
ucdata.o: /usr/include/sys/_types/_uuid_t.h
ucdata.o: ../../include/lutil_lockf.h
ucdata.o: /usr/include/getopt.h
ucdata.o: ../../include/lber_pvt.h
ucdata.o: ../../include/lber.h
ucdata.o: ../../include/ac/bytes.h
ucdata.o: ucdata.h
ucdata.o: uctable.h
ucdata.o: ../../include/lber_types.h
ucgendat.o: ../../include/portable.h
ucgendat.o: ucgendat.c
ucgendat.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
ucgendat.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
ucgendat.o: ../../include/ldap_cdefs.h
ucgendat.o: ../../include/ac/fdset.h
ucgendat.o: ../../include/ac/assert.h
ucgendat.o: ../../include/ldap_features.h
ucgendat.o: /usr/include/sys/cdefs.h
ucgendat.o: /usr/include/assert.h
ucgendat.o: /usr/include/sys/_symbol_aliasing.h
ucgendat.o: ../../include/ac/localize.h
ucgendat.o: /usr/include/sys/_posix_availability.h
ucgendat.o: /usr/include/stdio.h
ucgendat.o: ../../include/ldap_config.h
ucgendat.o: /usr/include/AvailabilityInternal.h
ucgendat.o: /usr/include/Availability.h
ucgendat.o: /usr/include/sys/_types.h
ucgendat.o: /usr/include/_types.h
ucgendat.o: /usr/include/i386/_types.h
ucgendat.o: /usr/include/machine/_types.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_types.h
ucgendat.o: /usr/include/sys/_types/_size_t.h
ucgendat.o: /usr/include/sys/_types/_va_list.h
ucgendat.o: /usr/include/sys/stdio.h
ucgendat.o: /usr/include/sys/_types/_null.h
ucgendat.o: /usr/include/sys/_types/_ssize_t.h
ucgendat.o: /usr/include/sys/_types/_off_t.h
ucgendat.o: /usr/include/secure/_common.h
ucgendat.o: /usr/include/secure/_stdio.h
ucgendat.o: /usr/include/ctype.h
ucgendat.o: /usr/include/runetype.h
ucgendat.o: ../../include/ac/ctype.h
ucgendat.o: /usr/include/sys/_types/_rune_t.h
ucgendat.o: /usr/include/sys/_types/_ct_rune_t.h
ucgendat.o: /usr/include/sys/_types/_wint_t.h
ucgendat.o: /usr/include/sys/_types/_wchar_t.h
ucgendat.o: /usr/include/stdlib.h
ucgendat.o: ../../include/ac/stdlib.h
ucgendat.o: /usr/include/sys/_types/_pid_t.h
ucgendat.o: /usr/include/sys/wait.h
ucgendat.o: /usr/include/sys/signal.h
ucgendat.o: /usr/include/sys/_types/_id_t.h
ucgendat.o: /usr/include/machine/signal.h
ucgendat.o: /usr/include/sys/appleapiopts.h
ucgendat.o: /usr/include/machine/_mcontext.h
ucgendat.o: /usr/include/i386/signal.h
ucgendat.o: /usr/include/mach/i386/_structs.h
ucgendat.o: /usr/include/i386/_mcontext.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_attr_t.h
ucgendat.o: /usr/include/sys/_types/_sigaltstack.h
ucgendat.o: /usr/include/sys/_types/_ucontext.h
ucgendat.o: /usr/include/sys/_types/_uid_t.h
ucgendat.o: /usr/include/sys/_types/_sigset_t.h
ucgendat.o: /usr/include/sys/resource.h
ucgendat.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
ucgendat.o: /usr/include/sys/_types/_int8_t.h
ucgendat.o: /usr/include/stdint.h
ucgendat.o: /usr/include/sys/_types/_int32_t.h
ucgendat.o: /usr/include/sys/_types/_int16_t.h
ucgendat.o: /usr/include/_types/_uint8_t.h
ucgendat.o: /usr/include/sys/_types/_int64_t.h
ucgendat.o: /usr/include/_types/_uint32_t.h
ucgendat.o: /usr/include/_types/_uint16_t.h
ucgendat.o: /usr/include/sys/_types/_intptr_t.h
ucgendat.o: /usr/include/_types/_uint64_t.h
ucgendat.o: /usr/include/_types/_intmax_t.h
ucgendat.o: /usr/include/sys/_types/_uintptr_t.h
ucgendat.o: /usr/include/sys/_types/_timeval.h
ucgendat.o: /usr/include/_types/_uintmax_t.h
ucgendat.o: /usr/include/i386/endian.h
ucgendat.o: /usr/include/machine/endian.h
ucgendat.o: /usr/include/libkern/_OSByteOrder.h
ucgendat.o: /usr/include/sys/_endian.h
ucgendat.o: /usr/include/alloca.h
ucgendat.o: /usr/include/libkern/i386/_OSByteOrder.h
ucgendat.o: /usr/include/i386/types.h
ucgendat.o: /usr/include/machine/types.h
ucgendat.o: /usr/include/sys/_types/_u_int8_t.h
ucgendat.o: /usr/include/sys/_types/_u_int16_t.h
ucgendat.o: /usr/include/sys/_types/_u_int32_t.h
ucgendat.o: /usr/include/sys/_types/_dev_t.h
ucgendat.o: /usr/include/sys/_types/_u_int64_t.h
ucgendat.o: /usr/include/sys/_types/_mode_t.h
ucgendat.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
ucgendat.o: /usr/include/machine/limits.h
ucgendat.o: /usr/include/limits.h
ucgendat.o: /usr/include/i386/_limits.h
ucgendat.o: /usr/include/i386/limits.h
ucgendat.o: ../../include/ac/string.h
ucgendat.o: /usr/include/sys/syslimits.h
ucgendat.o: /usr/include/sys/_types/_rsize_t.h
ucgendat.o: /usr/include/string.h
ucgendat.o: /usr/include/strings.h
ucgendat.o: /usr/include/sys/_types/_errno_t.h
ucgendat.o: ../../include/ac/unistd.h
ucgendat.o: /usr/include/secure/_string.h
ucgendat.o: /usr/include/sys/_types/_blkcnt_t.h
ucgendat.o: /usr/include/sys/types.h
ucgendat.o: /usr/include/sys/_types/_gid_t.h
ucgendat.o: /usr/include/sys/_types/_blksize_t.h
ucgendat.o: /usr/include/sys/_types/_in_addr_t.h
ucgendat.o: /usr/include/sys/_types/_ino_t.h
ucgendat.o: /usr/include/sys/_types/_in_port_t.h
ucgendat.o: /usr/include/sys/_types/_key_t.h
ucgendat.o: /usr/include/sys/_types/_ino64_t.h
ucgendat.o: /usr/include/sys/_types/_clock_t.h
ucgendat.o: /usr/include/sys/_types/_nlink_t.h
ucgendat.o: /usr/include/sys/_types/_time_t.h
ucgendat.o: /usr/include/sys/_types/_useconds_t.h
ucgendat.o: /usr/include/sys/_types/_suseconds_t.h
ucgendat.o: /usr/include/sys/_types/_fd_def.h
ucgendat.o: /usr/include/sys/_types/_fd_setsize.h
ucgendat.o: /usr/include/sys/_types/_fd_clr.h
ucgendat.o: /usr/include/sys/_types/_fd_set.h
ucgendat.o: /usr/include/sys/_types/_fd_isset.h
ucgendat.o: /usr/include/sys/_types/_fd_zero.h
ucgendat.o: /usr/include/sys/_types/_fd_copy.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_cond_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_once_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_t.h
ucgendat.o: /usr/include/sys/_pthread/_pthread_key_t.h
ucgendat.o: /usr/include/sys/_types/_fsblkcnt_t.h
ucgendat.o: /usr/include/unistd.h
ucgendat.o: /usr/include/sys/_types/_fsfilcnt_t.h
ucgendat.o: /usr/include/sys/_types/_posix_vdisable.h
ucgendat.o: /usr/include/sys/unistd.h
ucgendat.o: /usr/include/sys/select.h
ucgendat.o: /usr/include/sys/_types/_seek_set.h
ucgendat.o: /usr/include/sys/_select.h
ucgendat.o: /usr/include/sys/_types/_timespec.h
ucgendat.o: /usr/include/gethostuuid.h
ucgendat.o: /usr/include/sys/_types/_uuid_t.h
ucgendat.o: ../../include/lutil_lockf.h
ucgendat.o: /usr/include/getopt.h
ucgendat.o: ../../include/lutil.h
ucgendat.o: ../../include/ac/bytes.h
ucgendat.o: ../../include/lber_types.h
ure.o: ../../include/portable.h
ure.o: ure.c
ure.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
ure.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
ure.o: ../../include/ldap_cdefs.h
ure.o: ../../include/ac/fdset.h
ure.o: ../../include/ac/assert.h
ure.o: ../../include/ldap_features.h
ure.o: /usr/include/sys/cdefs.h
ure.o: /usr/include/assert.h
ure.o: /usr/include/sys/_symbol_aliasing.h
ure.o: ../../include/ac/localize.h
ure.o: /usr/include/sys/_posix_availability.h
ure.o: /usr/include/stdlib.h
ure.o: ../../include/ac/stdlib.h
ure.o: /usr/include/AvailabilityInternal.h
ure.o: /usr/include/Availability.h
ure.o: /usr/include/sys/_types.h
ure.o: /usr/include/_types.h
ure.o: /usr/include/i386/_types.h
ure.o: /usr/include/machine/_types.h
ure.o: /usr/include/sys/wait.h
ure.o: /usr/include/sys/_pthread/_pthread_types.h
ure.o: /usr/include/sys/_types/_id_t.h
ure.o: /usr/include/sys/_types/_pid_t.h
ure.o: /usr/include/sys/appleapiopts.h
ure.o: /usr/include/sys/signal.h
ure.o: /usr/include/i386/signal.h
ure.o: /usr/include/machine/signal.h
ure.o: /usr/include/i386/_mcontext.h
ure.o: /usr/include/machine/_mcontext.h
ure.o: /usr/include/mach/i386/_structs.h
ure.o: /usr/include/sys/_pthread/_pthread_attr_t.h
ure.o: /usr/include/sys/_types/_sigaltstack.h
ure.o: /usr/include/sys/_types/_ucontext.h
ure.o: /usr/include/sys/_types/_size_t.h
ure.o: /usr/include/sys/_types/_sigset_t.h
ure.o: /usr/include/sys/resource.h
ure.o: /usr/include/sys/_types/_uid_t.h
ure.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stdint.h
ure.o: /usr/include/sys/_types/_int8_t.h
ure.o: /usr/include/stdint.h
ure.o: /usr/include/sys/_types/_int32_t.h
ure.o: /usr/include/sys/_types/_int16_t.h
ure.o: /usr/include/_types/_uint8_t.h
ure.o: /usr/include/sys/_types/_int64_t.h
ure.o: /usr/include/_types/_uint32_t.h
ure.o: /usr/include/_types/_uint16_t.h
ure.o: /usr/include/sys/_types/_intptr_t.h
ure.o: /usr/include/_types/_uint64_t.h
ure.o: /usr/include/_types/_intmax_t.h
ure.o: /usr/include/sys/_types/_uintptr_t.h
ure.o: /usr/include/sys/_types/_timeval.h
ure.o: /usr/include/_types/_uintmax_t.h
ure.o: /usr/include/i386/endian.h
ure.o: /usr/include/machine/endian.h
ure.o: /usr/include/libkern/_OSByteOrder.h
ure.o: /usr/include/sys/_endian.h
ure.o: /usr/include/alloca.h
ure.o: /usr/include/libkern/i386/_OSByteOrder.h
ure.o: /usr/include/sys/_types/_rune_t.h
ure.o: /usr/include/sys/_types/_ct_rune_t.h
ure.o: /usr/include/sys/_types/_null.h
ure.o: /usr/include/sys/_types/_wchar_t.h
ure.o: /usr/include/i386/types.h
ure.o: /usr/include/machine/types.h
ure.o: /usr/include/sys/_types/_u_int8_t.h
ure.o: /usr/include/sys/_types/_u_int16_t.h
ure.o: /usr/include/sys/_types/_u_int32_t.h
ure.o: /usr/include/sys/_types/_dev_t.h
ure.o: /usr/include/sys/_types/_u_int64_t.h
ure.o: /usr/include/sys/_types/_mode_t.h
ure.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/limits.h
ure.o: /usr/include/machine/limits.h
ure.o: /usr/include/limits.h
ure.o: /usr/include/i386/_limits.h
ure.o: /usr/include/i386/limits.h
ure.o: ../../include/ac/string.h
ure.o: /usr/include/sys/syslimits.h
ure.o: /usr/include/sys/_types/_rsize_t.h
ure.o: /usr/include/string.h
ure.o: /usr/include/sys/_types/_ssize_t.h
ure.o: /usr/include/sys/_types/_errno_t.h
ure.o: /usr/include/secure/_string.h
ure.o: /usr/include/strings.h
ure.o: ../../include/ac/unistd.h
ure.o: /usr/include/secure/_common.h
ure.o: /usr/include/sys/_types/_blkcnt_t.h
ure.o: /usr/include/sys/types.h
ure.o: /usr/include/sys/_types/_gid_t.h
ure.o: /usr/include/sys/_types/_blksize_t.h
ure.o: /usr/include/sys/_types/_in_addr_t.h
ure.o: /usr/include/sys/_types/_ino_t.h
ure.o: /usr/include/sys/_types/_in_port_t.h
ure.o: /usr/include/sys/_types/_key_t.h
ure.o: /usr/include/sys/_types/_ino64_t.h
ure.o: /usr/include/sys/_types/_off_t.h
ure.o: /usr/include/sys/_types/_nlink_t.h
ure.o: /usr/include/sys/_types/_time_t.h
ure.o: /usr/include/sys/_types/_clock_t.h
ure.o: /usr/include/sys/_types/_useconds_t.h
ure.o: /usr/include/sys/_types/_suseconds_t.h
ure.o: /usr/include/sys/_types/_fd_def.h
ure.o: /usr/include/sys/_types/_fd_setsize.h
ure.o: /usr/include/sys/_types/_fd_clr.h
ure.o: /usr/include/sys/_types/_fd_set.h
ure.o: /usr/include/sys/_types/_fd_isset.h
ure.o: /usr/include/sys/_types/_fd_zero.h
ure.o: /usr/include/sys/_types/_fd_copy.h
ure.o: /usr/include/sys/_pthread/_pthread_cond_t.h
ure.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
ure.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
ure.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
ure.o: /usr/include/sys/_pthread/_pthread_once_t.h
ure.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
ure.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
ure.o: /usr/include/sys/_pthread/_pthread_t.h
ure.o: /usr/include/sys/_pthread/_pthread_key_t.h
ure.o: /usr/include/sys/_types/_fsblkcnt_t.h
ure.o: /usr/include/unistd.h
ure.o: /usr/include/sys/_types/_fsfilcnt_t.h
ure.o: /usr/include/sys/_types/_posix_vdisable.h
ure.o: /usr/include/sys/unistd.h
ure.o: /usr/include/sys/select.h
ure.o: /usr/include/sys/_types/_seek_set.h
ure.o: /usr/include/sys/_select.h
ure.o: /usr/include/sys/_types/_timespec.h
ure.o: /usr/include/gethostuuid.h
ure.o: /usr/include/sys/_types/_uuid_t.h
ure.o: ../../include/lutil_lockf.h
ure.o: ure.h
ure.o: /usr/include/getopt.h
ure.o: /usr/include/sys/_types/_va_list.h
ure.o: /usr/include/stdio.h
ure.o: /usr/include/secure/_stdio.h
ure.o: /usr/include/sys/stdio.h
urestubs.o: ../../include/portable.h
urestubs.o: urestubs.c
urestubs.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/stddef.h
urestubs.o: /Library/Developer/CommandLineTools/usr/lib/clang/9.0.0/include/__stddef_max_align_t.h
urestubs.o: ../../include/ldap_cdefs.h
urestubs.o: ../../include/ac/fdset.h
urestubs.o: ../../include/ac/assert.h
urestubs.o: ../../include/ldap_features.h
urestubs.o: /usr/include/sys/cdefs.h
urestubs.o: /usr/include/assert.h
urestubs.o: /usr/include/sys/_symbol_aliasing.h
urestubs.o: ../../include/ac/localize.h
urestubs.o: /usr/include/sys/_posix_availability.h
urestubs.o: ure.h
urestubs.o: /usr/include/stdio.h
urestubs.o: ../../include/ac/bytes.h
urestubs.o: /usr/include/AvailabilityInternal.h
urestubs.o: /usr/include/Availability.h
urestubs.o: /usr/include/sys/_types.h
urestubs.o: /usr/include/_types.h
urestubs.o: /usr/include/i386/_types.h
urestubs.o: /usr/include/machine/_types.h
urestubs.o: /usr/include/sys/_pthread/_pthread_types.h
urestubs.o: /usr/include/sys/_types/_size_t.h
urestubs.o: /usr/include/sys/_types/_va_list.h
urestubs.o: /usr/include/sys/stdio.h
urestubs.o: /usr/include/sys/_types/_null.h
urestubs.o: /usr/include/sys/_types/_ssize_t.h
urestubs.o: /usr/include/sys/_types/_off_t.h
urestubs.o: /usr/include/secure/_common.h
urestubs.o: ucdata.h
urestubs.o: /usr/include/secure/_stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
