SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "virtual driver!"
LICENSE = "GPL"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

PV = "0.1"
PR = "r01"

# using gitsm for submodule
SRC_URI = "gitsm://github.com/slowstarter80/my_prjs.git;subpath=virt-driver;branch=main;protocol=https;destsuffix=git"

PATCHTOOLS = "git"

inherit module

SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"
DESTDIR="${D}"

EXTRA_OEMAKE:append = " INSTALL_DIR=${DESTDIR} "

KERNEL_MODULE_AUTOLOAD += "virt_driver"

RPROVIDES:${PN} += "kernel-module-virt-driver"

