#!/bin/bash
# Copyright (C) 2015 Google, Inc
#
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License version 2 as published by the
# Free Software Foundation.
# ---
#
# Switch to the "linux-raw" branch and download USB headers from the Linux
# kernel.
#
# The "linux-raw" branch can then be merged into master (git merge linux-raw)
# to allow git to gracefully merge the modifications we have made to the header
# files.
#
# FIXME: This should get the git revision from the Linux kernel and record it.
#

set -x
set -e

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

git stash

git checkout "linux-raw"

CODE="\
	tools/include/linux/types.h \
	include/linux/hdmi.h \
	include/drm/drm_crtc.h \
	include/drm/drm_dp_mst_helper.h \
	include/drm/drm_edid.h \
	include/drm/drm_displayid.h \
	include/drm/drm_modes.h \
	include/uapi/drm/drm_fourcc.h \
	include/uapi/drm/drm_mode.h \
	drivers/video/hdmi.c \
	drivers/gpu/drm/drm_crtc.c \
	drivers/gpu/drm/drm_edid.c \
	drivers/gpu/drm/drm_edid_load.c \
	drivers/gpu/drm/drm_probe_helper.c \
	sound/pci/hda/hda_eld.c \
	sound/pci/hda/patch_hdmi.c \
	"

DOCS="\
 	Documentation/EDID/800x600.S \
	Documentation/EDID/1024x768.S \
	Documentation/EDID/1280x1024.S \
	Documentation/EDID/1680x1050.S \
	Documentation/EDID/1920x1080.S \
	Documentation/EDID/HOWTO.txt \
	Documentation/EDID/Makefile \
	Documentation/EDID/edid.S \
	Documentation/EDID/hex
	"

for FILEPATH in $CODE; do
        FILENAME=$(basename $FILEPATH)
	DIRNAME=$(dirname $FILEPATH)
	# http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/include/uapi/linux/usb/ch9.h
	if [ -f $FILENAME ]; then
		rm $FILENAME
	fi
	wget "http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/$FILEPATH"
	git add $FILENAME
done
(
cd samples
for FILEPATH in $DOCS; do
        FILENAME=$(basename $FILEPATH)
	DIRNAME=$(dirname $FILEPATH)
	# http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/include/uapi/linux/usb/ch9.h
	if [ -f $FILENAME ]; then
		rm $FILENAME
	fi
	wget "http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/$FILEPATH"
	git add $FILENAME
done
)
git commit -m "Updating Linux imports."

git checkout $CURRENT_BRANCH

git stash pop
