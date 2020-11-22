# define standard colors
ifdef COLORS
	#Black
	BLACK        := \e[30m
	BLACK_SUB	 := \e[4;30m
	BLACK_WEIGHT := \e[1;30m
	BLACK_ITALIC := \e[3;30m
	BLACK_ITA_WEI:= \e[1;3;30m
	BLACK_FLUSH	 := \e[5;30m
	BLACK_BACK	 := \e[7;30m
	BLACK_STRIKE := \e[9;30m
	#Red
	RED        	:= \e[31m
	RED_SUB	 	:= \e[4;31m
	RED_WEIGHT 	:= \e[1;31m
	RED_ITALIC 	:= \e[3;31m
	RED_ITA_WEI := \e[1;3;31m
	RED_FLUSH	:= \e[5;31m
	RED_BACK	:= \e[7;31m
	RED_STRIKE 	:= \e[9;31m
	#Blue
	BLUE        := \e[34m
	BLUE_SUB	:= \e[4;34m
	BLUE_WEIGHT := \e[1;34m
	BLUE_ITALIC := \e[3;34m
	BLUE_ITA_WEI:= \e[1;3;34m
	BLUE_FLUSH	:= \e[5;34m
	BLUE_BACK	:= \e[7;34m
	BLUE_STRIKE := \e[9;34m
	#Green
	GREEN        := \e[32m
	GREEN_SUB	 := \e[4;32m
	GREEN_WEIGHT := \e[1;32m
	GREEN_ITALIC := \e[3;32m
	GREEN_ITA_WEI:= \e[1;3;32m
	GREEN_FLUSH	 := \e[5;32m
	GREEN_BACK	 := \e[7;32m
	GREEN_STRIKE := \e[9;32m
	#Cyan
	CYAN        := \e[36m
	CYAN_SUB	:= \e[4;36m
	CYAN_WEIGHT := \e[1;36m
	CYAN_ITALIC := \e[3;36m
	CYAN_ITA_WEI:= \e[1;3;36m
	CYAN_FLUSH	:= \e[5;36m
	CYAN_BACK	:= \e[7;36m
	CYAN_STRIKE := \e[9;36m
	#WHITE
	WHITE        := \e[37m
	WHITE_SUB	 := \e[4;37m
	WHITE_WEIGHT := \e[1;37m
	WHITE_ITALIC := \e[3;37m
	WHITE_ITA_WEI:= \e[1;3;37m
	WHITE_FLUSH	 := \e[5;37m
	WHITE_BACK	 := \e[7;37m
	WHITE_STRIKE := \e[9;37m
	#PURPLE
	PURPLE        	:= \e[35m
	PURPLE_SUB	 	:= \e[4;35m
	PURPLE_WEIGHT 	:= \e[1;35m
	PURPLE_ITALIC 	:= \e[3;35m
	PURPLE_ITA_WEI	:= \e[1;3;35m
	PURPLE_FLUSH	:= \e[5;35m
	PURPLE_BACK	 	:= \e[7;35m
	PURPLE_STRIKE 	:= \e[9;35m

endif
# Colors
COMPILER_COLOR  := $(GREEN_ITA_WEI)
BUILD_COLOR		:= $(BLUE_SUB)
OBJ_COLOR   	:= $(CYAN)
SRC_COLOR   	:= $(RED_ITA_WEI)
FLAGS_COLOR		:= $(GREEN_SUB)
INCDIRS_COLOR	:= $(BLUE_ITALIC)
LIBS_COLOR		:= $(GREEN_WEIGHT)
RM_COLOR		:= $(RED_BACK)
MKDIR_COLOR		:= $(GREEN_BACK)
AR_COLOR		:= $(GREEN_ITA_WEI)
OK_COLOR    	:= \033[0;32m
ERROR_COLOR 	:= \033[0;31m
WARN_COLOR  	:= \033[0;33m
NO_COLOR    	:= \033[m

RESET := $(shell tput -Txterm sgr0)