# EDID

 * https://en.wikipedia.org/wiki/Extended_Display_Identification_Data

 * EDID structure versions range from v1.0 to v1.4 (plus a v2.0 - released and deprecated)

 * HDMI 1.0 – 1.3c uses EDID structure v1.3

 * Enhanced EDID was introduced at the same time as E-DDC

 * DDC is the protocol for reading EDID data.

   - E-DDC (Enhanced Display Data Channel) is the most recent revision of the
     DDC standard.

   - DDC/CI is a control protocol for contrast / etc
     - Most DDC/CI monitors support only a small subset of MCCS commands and
       some have undocumented commands. Many manufacturers did not pay
       attention to DDC/CI in the past, but now almost all monitors support
       such general MCCS commands as brightness and contrast management.

     - Tool / Library - GPLv2
       - http://ddccontrol.sourceforge.net/
       - http://www.boichat.ch/nicolas/ddcci/specs.html

 * DisplayID is a VESA standard designed to replace E-EDID standard and EDID
   structure v1.4

| Release Date   | Standard Name                   | EDID structures
| --------------:| ------------------------------- | ---------------------------------------------------------|
|    August 1994 | DDC standard version 1          | EDID v1.0 structure                                      |
|     April 1996 | EDID standard version 2         | EDID v1.1 structure                                      |
|    ?????? 1997 | EDID standard version 3         | EDID structures v1.2 and v2.0                            |
|  February 2000 | E-EDID Standard Release A, v1.0 | EDID structure v1.3, EDID structure v2.0 deprecated      |
| September 2006 | E-EDID Standard Release A, v2.0 | EDID structure v1.4                                      |

 * EIA/CEA-861 extension block

| Version   | Spec  | Release Date     | Notes                                                    |
| ---------:| ----- | ---------------- | ---------------------------------------------------------|
| Version 1 | -861  |                  |                                                          |
| Version 2 | -861A |                  |                                                          |
| Version 3 | -861B |                  | HDMI 1.0 -1.3c uses this version                         |
|           | -861D | July 2006        |                                                          |
|           | -861E |                  |                                                          |
|           | -861F | June 4, 2013     |                                                          |

# Libraries

 * Will use Linux version.
 * Fall back is coreboot.

### Questions
 * How active is the development of the file? When was it last updated?
 * License?
 * Does it support HDMI EDID extensions?
 * Does it use malloc / etc?
 * Is it a library?
 * Can it generate EDID too? 

### Linux Kernel
 * drivers/gpu/drm/drm_edid.c
 * http://lxr.free-electrons.com/source/drivers/gpu/drm/drm_edid.c
 * Lots of active development.
 * Has lots of quirks support.

### coreboot - lib/edid.c
 * http://review.coreboot.org/gitweb?p=coreboot.git;a=blob;f=src/lib/edid.c
 * Lots, last late 2015
 * GPLv3

### openxt/libedid
 * https://github.com/OpenXT/libedid
 * 2 commits, last 2014
 * LGPLv2.1

### libminitru
 * http://cgit.freedesktop.org/~ajax/libminitru/tree/edid.c

### u-boot 
 * https://github.com/ynezz/u-boot-edid/blob/master/edid.c

### xorg edid-decode
 * http://cgit.freedesktop.org/xorg/app/edid-decode/tree/
 * MIT? X11 Maybe?

### read-edid
 * http://www.polypux.org/projects/read-edid/

 
