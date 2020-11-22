COLORS := 1
UBUNTU := 1

PATH_NEXT	:= 
AR		:= ar
ARFLAGS := -crs
RANLIB 	:= ranlib
MKDIR	:= mkdir -p
RM		:= rm

ifdef DEBUG
	CCFLAGS += -g
	CFLAGS += -g
else
	CCFLAGS += -O3
	CFLAGS += -O3
endif

run_test: clean_test $(APP) $(TESTAPP)
	@echo "\n ---RUN-TEST---	\n"
	cd bin && ./$(TESTAPP)

run: build
	@echo "\n ---RUN---	\n"
	@$() cd bin && ./$(APP)

build: build_Print $(APP)

build_Print:
	@echo "\n ---BUILD---	\n"

info:
	$(info $(PATH_NEXT))

get_dependencies:
ifdef UBUNTU
		sudo apt-get update -y
		sudo apt-get install -y googletest
		sudo apt install libgtest-dev
endif