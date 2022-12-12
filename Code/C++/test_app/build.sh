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
fi

cppcheck --cppcheck-build-dir="${CPPCHECK_BUILDDIR}"  inc src
