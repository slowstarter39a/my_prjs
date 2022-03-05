
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "library example!"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
	   file://test-lib.tar.gz \
	   "

S = "${WORKDIR}"

TARGET_CC_ARCH += "${LDFLAGS}"

#INSANE_SKIP_${PN} += "ldflags"
#INSANE_SKIP_${PN}-dev += "ldflags"

#FILES_${PN} += " \
#		${libdir}/lib*{SOLIBS} \
#		"

PATCHTOOLS = "git"
PV = "0.1"
PR = "r01"


do_install() {
	install -d ${D}${libdir}
	oe_soinstall ${S}/libmypow.so.1.0 ${D}${libdir}

	install -d ${D}${includedir}
	install -m 0644 ${S}/*.h ${D}${includedir}

}
