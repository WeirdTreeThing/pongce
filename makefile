# ----------------------------
# Makefile Options
# ----------------------------

NAME = PongCE
ICON = icon.png
DESCRIPTION = "Pong for CE"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
