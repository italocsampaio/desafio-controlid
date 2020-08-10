DESCRIPTION = "App that parses a JSON file and prints some of its contents to the terminal"
SECTION = "examples"
DEPENDS = ""
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=8bd5c7746f23f9f0e9980139c9cfd556"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

DEPENDS = "curl jsoncpp"
RDEPENDS_${PN} = "curl jsoncpp"

#SRCREV = "7cff61dd44bb9be15176bcf3b827e579dec354e3"
#SRC_URI = "git://github.com/italocsampaio/desafio-controlid.git;branch=develop"
SRC_URI = "git://github.com/italocsampaio/desafio-controlid.git;branch=feature/adiciona-autotools"
SRCREV = "8f532e4648e92ae8014367cc58b51d0f1f9a4860"

S = "${WORKDIR}/git"

inherit autotools

# The autotools configuration I am basing this on seems to have a problem with a race condition when parallel make is enabled
PARALLEL_MAKE = ""

