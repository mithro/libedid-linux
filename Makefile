

all:
	gcc \
		hexdump.c \
		list_sort.c \
		kmem.c \
		\
		hdmi.c \
		drm_modes.c \
		drm_edid.c \
		\
		main.c \
		 -o edid
