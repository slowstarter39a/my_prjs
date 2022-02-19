SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "calculator application!"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# using gitsm for submodule
SRC_URI = "gitsm://github.com/slowstarter80/my_prjs.git;subpath=calculator;branch=main;protocol=https;destsuffix=git/calculator"

SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git/${PN}"

DEPENDS += "lib-example"

TARGET_CC_ARCH += "${LDFLAGS}"

PATCHTOOLS = "git"
PV = "0.1"
PR = "r01"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 calculator ${D}${bindir}
}
	
