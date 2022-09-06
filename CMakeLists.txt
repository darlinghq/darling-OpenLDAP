project(darling-openldap)

remove_sdk_framework(LDAP)

add_compile_definitions(
	LDAP_RESPONSE_RB_TREE=1
	LDAP_DEPRECATED=1
	LDAP_CONNECTIONLESS=1
	SLAP_DYNACL=1
	USES_KRBNAME=1
	TGT_OS_VERSION="${CMAKE_OSX_DEPLOYMENT_TARGET}"
	PROJVERSION="999"

	DTRACE_PROBES_DISABLED=1
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/OpenLDAP/include
	${CMAKE_CURRENT_SOURCE_DIR}/OpenLDAP/libraries/libldap
	${CMAKE_CURRENT_SOURCE_DIR}/OpenLDAP/servers/slapd
)

add_compile_options(
	-fno-common
)

add_darling_object_library(libldap_r
	# libldap_r
	OpenLDAP/libraries/libldap_r/rdwr.c
	OpenLDAP/libraries/libldap_r/rmutex.c
	OpenLDAP/libraries/libldap_r/rq.c
	OpenLDAP/libraries/libldap_r/thr_cthreads.c
	OpenLDAP/libraries/libldap_r/thr_debug.c
	OpenLDAP/libraries/libldap_r/thr_lwp.c
	OpenLDAP/libraries/libldap_r/thr_nt.c 
	OpenLDAP/libraries/libldap_r/thr_posix.c
	OpenLDAP/libraries/libldap_r/thr_pth.c
	OpenLDAP/libraries/libldap_r/thr_stub.c
	OpenLDAP/libraries/libldap_r/thr_thr.c
	OpenLDAP/libraries/libldap_r/threads.c
	OpenLDAP/libraries/libldap_r/tpool.c

	# libldap
	OpenLDAP/libraries/libldap/abandon.c
	OpenLDAP/libraries/libldap/add.c
	OpenLDAP/libraries/libldap/addentry.c
	OpenLDAP/libraries/libldap/apple_compat.c
	OpenLDAP/libraries/libldap/assertion.c
	OpenLDAP/libraries/libldap/bind.c
	OpenLDAP/libraries/libldap/cancel.c
	OpenLDAP/libraries/libldap/charray.c
	OpenLDAP/libraries/libldap/compare.c
	OpenLDAP/libraries/libldap/controls.c
	OpenLDAP/libraries/libldap/cyrus.c
	OpenLDAP/libraries/libldap/dds.c
	OpenLDAP/libraries/libldap/delete.c
	OpenLDAP/libraries/libldap/deref.c
	OpenLDAP/libraries/libldap/dnssrv.c
	OpenLDAP/libraries/libldap/error.c
	OpenLDAP/libraries/libldap/extended.c
	OpenLDAP/libraries/libldap/fetch.c
	OpenLDAP/libraries/libldap/filter.c
	OpenLDAP/libraries/libldap/free.c
	OpenLDAP/libraries/libldap/getattr.c
	OpenLDAP/libraries/libldap/getdn.c
	OpenLDAP/libraries/libldap/getentry.c
	OpenLDAP/libraries/libldap/getvalues.c
	OpenLDAP/libraries/libldap/gssapi.c
	OpenLDAP/libraries/libldap/init.c
	OpenLDAP/libraries/libldap/ldap_sync.c
	OpenLDAP/libraries/libldap/ldif.c
	OpenLDAP/libraries/libldap/messages.c
	OpenLDAP/libraries/libldap/modify.c
	OpenLDAP/libraries/libldap/modrdn.c
	OpenLDAP/libraries/libldap/open.c
	OpenLDAP/libraries/libldap/options.c
	OpenLDAP/libraries/libldap/os-ip.c
	OpenLDAP/libraries/libldap/os-local.c
	OpenLDAP/libraries/libldap/pagectrl.c
	OpenLDAP/libraries/libldap/passwd.c
	OpenLDAP/libraries/libldap/ppolicy.c
	OpenLDAP/libraries/libldap/print.c
	OpenLDAP/libraries/libldap/rb_response.c
	OpenLDAP/libraries/libldap/rb.c
	OpenLDAP/libraries/libldap/references.c
	OpenLDAP/libraries/libldap/request.c
	OpenLDAP/libraries/libldap/result.c
	OpenLDAP/libraries/libldap/sasl.c
	OpenLDAP/libraries/libldap/sbind.c
	OpenLDAP/libraries/libldap/schema.c
	OpenLDAP/libraries/libldap/search.c
	OpenLDAP/libraries/libldap/sort.c
	OpenLDAP/libraries/libldap/sortctrl.c
	OpenLDAP/libraries/libldap/stctrl.c
	OpenLDAP/libraries/libldap/string.c
	OpenLDAP/libraries/libldap/tls_g.c
	OpenLDAP/libraries/libldap/tls_m.c 
	OpenLDAP/libraries/libldap/tls_o.c
	OpenLDAP/libraries/libldap/tls_st.c
	OpenLDAP/libraries/libldap/tls2.c
	OpenLDAP/libraries/libldap/turn.c
	OpenLDAP/libraries/libldap/txn.c
	OpenLDAP/libraries/libldap/unbind.c
	OpenLDAP/libraries/libldap/url.c
	OpenLDAP/libraries/libldap/utf-8-conv.c
	OpenLDAP/libraries/libldap/utf-8.c
	OpenLDAP/libraries/libldap/util-int.c
	OpenLDAP/libraries/libldap/vlvctrl.c
	OpenLDAP/libraries/libldap/whoami.c
)

target_compile_definitions(libldap_r PRIVATE
	LDAP_R_COMPILE
	LDAP_LIBRARY
)

add_darling_object_library(liblber
	OpenLDAP/libraries/liblber/assert.c
	OpenLDAP/libraries/liblber/bprint.c
	OpenLDAP/libraries/liblber/debug.c
	OpenLDAP/libraries/liblber/decode.c
	OpenLDAP/libraries/liblber/encode.c
	OpenLDAP/libraries/liblber/io.c
	OpenLDAP/libraries/liblber/memory.c
	OpenLDAP/libraries/liblber/options.c
	OpenLDAP/libraries/liblber/sockbuf.c
	OpenLDAP/libraries/liblber/stdio.c
)

target_compile_definitions(liblber PRIVATE
	LBER_LIBRARY
)

set(FRAMEWORK_VERSION "A")

generate_sdk_framework(LDAP
    VERSION ${FRAMEWORK_VERSION}
    HEADER "darling-framework/include/LDAP"
)

add_framework(LDAP
	CURRENT_VERSION
	VERSION ${FRAMEWORK_VERSION}

	OBJECTS
		$<TARGET_OBJECTS:libldap_r>
		$<TARGET_OBJECTS:liblber>
	RESOURCES
		Info.plist    AppleExtras/Resources/Info.plist
		version.plist AppleExtras/Resources/version.plist
	DEPENDENCIES
		sasl
		CoreFoundation
		SystemConfiguration
		Security
		IOKit
		#CoreDaemon # missing
		resolv-darwin

		system
)

target_link_options(LDAP PRIVATE
	-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/AppleExtras/ldap.exp
	-Wl,-dead_strip
)
