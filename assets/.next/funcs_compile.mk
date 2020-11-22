ALLCPPS		:= $(shell find $(SRC)/ -type f -iname *.cpp)
ALLCPPSOBJ	:= $(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(ALLCPPS)))
ALLHPPS		:= $(patsubst %$(patsubst %.cpp,%.hpp,$(MAIN)),,$(patsubst %.cpp,%.hpp,$(patsubst $(SRC)%,$(INCL)%,$(ALLCPPS))))

ALLCS		:= $(shell find $(SRC)/ -type f -iname *.c)
ALLCSOBJ	:= $(patsubst %.c,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(ALLCS)))
ALLHS		:= $(patsubst %$(patsubst %.c,%.h,$(MAIN)),,$(patsubst %.c,%.h,$(patsubst $(SRC)%,$(INCL)%,$(ALLCS))))

SUBDIRS 	:= $(shell find $(SRC) -type d)
OBJSUBDIRS 	:= $(patsubst $(SRC)%,$(OBJ)%, $(SUBDIRS))

#TEST
ALLCPPSTEST		:= $(shell find $(TEST)/ -type f -iname *.cpp)
ALLCPPSOBJTEST	:= $(patsubst %.cpp,%.o,$(patsubst $(TEST)%,$(OBJTEST)%,$(ALLCPPSTEST)))
#ALLHPPSTEST		:= $(patsubst %$(patsubst %.cpp,%.hpp,$(MAIN)),,$(patsubst %.cpp,%.hpp,$(patsubst $(TEST)%,$(INCL)%,$(ALLCPPS))))

SUBDIRSTEST 	:= $(shell find $(TEST) -type d)
OBJSUBDIRSTEST 	:= $(patsubst $(TEST)%,$(OBJTEST)%, $(SUBDIRSTEST))

.PHONY: info clean cleanall

#Make Test
$(TESTAPP) : $(OBJSUBDIRS) $(ALLCSOBJ) $(ALLCPPSOBJ) $(OBJSUBDIRSTEST) $(ALLCPPSOBJTEST)
	@echo "$(PRINT_CXX_COMPILER) -o $(BIN)/$(TESTAPP) $(PRINT_OBJS_TEST_ALL) \
	$(call PRINT_LIBS,$(LIBS)) $(call PRINT_LIBS,$(LIBSTEST))"
	@$(CC) -o $(BIN)/$(TESTAPP) $(ALLCPPSOBJ) $(ALLCPPSOBJTEST) $(LIBS) $(LIBSTEST)

$(OBJTEST)/%.o : $(TEST)/%.cpp
	@echo "$(PRINT_CXX_COMPILER_COMPILER) -o $(call PRINT_OBJ, $(patsubst $(TEST)%,$(OBJTEST)%,$@)) -c $(call PRINT_SRC,$^) \
	$(call PRINT_FLAGS,$(CCFLAGS)) \
	$(call PRINT_INCDIRS,$(INCDIRS)) \
	$(call PRINT_LIBS,$(LIBS)) \
	$(call PRINT_LIBS,$(LIBSTEST))"
	@$(CC) -o $(patsubst $(TEST)%,$(OBJTEST)%,$@) -c $^ $(CCFLAGS) $(INCDIRS) $(LIBS) $(LIBSTEST)

#Make a lib
$(APP) : $(OBJSUBDIRS) $(ALLCSOBJ) $(ALLCPPSOBJ)
	@echo "$(PRINT_CXX_COMPILER) -o $(BIN)/$(APP) $(PRINT_OBJS_ALL) \
	$(call PRINT_LIBS,$(LIBS))"
	@$(CC) -o $(BIN)/$(APP) $(ALLCPPSOBJ) $(ALLCPPSOBJTEST) $(LIBS)

$(OBJ)/%.o : $(SRC)/%.c
	@echo "$(PRINT_C_COMPILER) -o $(call PRINT_OBJ, $(patsubst $(SRC)%,$(OBJ)%,$@)) -c $(call PRINT_SRC,$^) \
	$(call PRINT_FLAGS,$(CFLAGS)) \
	$(call PRINT_INCDIRS,$(INCDIRS)) \
	$(call PRINT_LIBS,$(LIBS))"
	@$(C) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CFLAGS) $(INCDIRS) $(LIBS)

$(OBJ)/%.o : $(SRC)/%.cpp
	@echo "$(PRINT_CXX_COMPILER) -o $(call PRINT_OBJ, $(patsubst $(SRC)%,$(OBJ)%,$@)) -c $(call PRINT_SRC,$^) \
	$(call PRINT_FLAGS,$(CCFLAGS)) \
	$(call PRINT_INCDIRS,$(INCDIRS)) \
	$(call PRINT_LIBS,$(LIBS))\n"
	@$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS) $(INCDIRS) $(LIBS)

$(OBJSUBDIRS) :
	@@echo "$(MKDIR_COLOR)$(MKDIR) $(OBJSUBDIRS)$(NO_COLOR)"
	@$(MKDIR) $(OBJSUBDIRS) $(BIN)

$(OBJSUBDIRSTEST) :
	@@echo "$(MKDIR_COLOR)$(MKDIR) $(OBJSUBDIRSTEST)$(NO_COLOR)"
	@$(MKDIR) $(OBJSUBDIRSTEST) $(BIN)

clean:
	@echo "$(RM_COLOR)$(RM) -r "./$(OBJ)"$(NO_COLOR)"
	@$(RM) -r "./$(OBJ)"

clean_test:
	@echo "$(RM_COLOR)$(RM) -r "./$(OBJTEST)"$(NO_COLOR)"
	@$(RM) -r "./$(OBJTEST)"

clean_all:
	$(RM) -r "./$(OBJ)"
	$(RM) -r "./$(BIN)"