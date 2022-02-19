SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "library example!"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# using gitsm for submodule
SRC_URI = "gitsm://github.com/slowstarter80/my_prjs.git;subpath=lib-example;branch=main;protocol=https;destsuffix=git/lib-example"


SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git/${PN}"

TARGET_CC_ARCH += "${LDFLAGS}"

PATCHTOOLS = "git"
PV = "0.1"
PR = "r01"

do_install() {
	install -d ${D}${libdir}
	install -m 0755 libmymath.so.1.0 ${D}${libdir}

	ln -s libmymath.so.1.0 ${D}${libdir}/libmymath.so.1
	ln -s libmymath.so.1 ${D}${libdir}/libmymath.so

	install -d ${D}${libdir}
	install -m 0755 libmylog.a ${D}${libdir}

	install -d ${D}${includedir}
	install -m 0644 *.h ${D}${includedir}
}
	
