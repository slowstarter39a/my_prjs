SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "helloworld application!"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

#SRC_URI = "git://github.com/slowstarter80/my_prjs;branch=main;protocol=ssh;"

# using gitsm for submodule
SRC_URI = "gitsm://github.com/slowstarter80/my_prjs.git;subpath=helloworld;branch=main;protocol=ssh;destsuffix=git/helloworld"

SRCREV = "92ad36b5ed9903423150ff327289ae0e7f90837a"


S = "${WORKDIR}/git/${PN}"

PATCHTOOLS = "git"
PV = "0.1"
PR = "r01"

inherit cmake

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Example recipe created by bitbake-layers   *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
