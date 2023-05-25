#!/bin/sh

set -eu

BUILDDIR=${BUILDDIR:-"./.build"}
BUILDTYPE=${BUILDTYPE:-"debug"}

rm -rf "${BUILDDIR}"

meson setup --buildtype "${BUILDTYPE}" "${BUILDDIR}" && \
meson compile -C "${BUILDDIR}"

# setup cppcheck linter
CPPCHECK_BUILDDIR=${CPPCHECK_BUILDDIR:-".cppcheckbuild"}
if [ ! -d "${CPPCHECK_BUILDDIR}" ]; then
    mkdir "${CPPCHECK_BUILDDIR}"
else
    rm -rf "${CPPCHECK_BUILDDIR}"/*
fi
cppcheck --bug-hunting --std=c++17 --cppcheck-build-dir="${CPPCHECK_BUILDDIR}" --xml 2>"${CPPCHECK_BUILDDIR}"/cppcheck_report_1.xml -I inc/ src/
cppcheck --enable=all --std=c++17 --cppcheck-build-dir="${CPPCHECK_BUILDDIR}" --xml 2>"${CPPCHECK_BUILDDIR}"/cppcheck_report_2.xml -I inc/ src/
cppcheck --check-config --std=c++17 --cppcheck-build-dir="${CPPCHECK_BUILDDIR}" --xml 2>"${CPPCHECK_BUILDDIR}"/cppcheck_report_3.xml -I inc/ src/
cppcheck-htmlreport --title="CPPCHECK TEST REPORT" --report-dir="${CPPCHECK_BUILDDIR}" \
                    --file="${CPPCHECK_BUILDDIR}"/cppcheck_report_1.xml \
                    --file="${CPPCHECK_BUILDDIR}"/cppcheck_report_2.xml \
                    --file="${CPPCHECK_BUILDDIR}"/cppcheck_report_3.xml
firefox "${CPPCHECK_BUILDDIR}"/index.html

