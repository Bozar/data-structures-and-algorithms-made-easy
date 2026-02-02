FILE_SRC := 4_1.c stack.c linked_list.c
#FILE_SRC := main.c stack.c linked_list.c
FILE_OBJ := $(subst .c,.o,$(FILE_SRC))
FILE_DEP := $(subst .c,.d,$(FILE_SRC))

#FILE_OBJ = $(patsubst %.c,%.o,$(FILE_SRC))
#FILE_SRC = $(notdir $(shell find $(DIR_SRC) -type f -name '*.c'))

FILE_EXEC := prog
FILE_MAIN := main.c
FILE_GIT_KEEP := .gitkeep
FILE_GIT_IGNORE := .gitignore
FILE_DEBUG := debug.h
FILE_TAG := tags

DIR_BUILD := ./build
DIR_INCLUDE := ./include
DIR_SRC := ./src

PATH_SRC := $(addprefix $(DIR_SRC)/,$(FILE_SRC))
PATH_OBJ := $(addprefix $(DIR_BUILD)/,$(FILE_OBJ))
PATH_DEP := $(addprefix $(DIR_BUILD)/,$(FILE_DEP))
PATH_EXEC := $(addprefix $(DIR_BUILD)/,$(FILE_EXEC))
PATH_DEBUG := $(addprefix $(DIR_INCLUDE)/,$(FILE_DEBUG))
PATH_TAG := ./$(FILE_TAG)

FLAG_INCLUDE := -I$(DIR_INCLUDE)
FLAG_WARN := -ansi -pedantic -std=c99 -Wall -Wextra \
		-Wconversion -Wshadow -Wcast-qual -fanalyzer
FLAG_MISC := -O1

CC := gcc


$(PATH_EXEC): $(PATH_OBJ)
	$(CC) $(FLAG_INCLUDE) $^ -o $@
	$(MAKE) $(PATH_TAG)


#$(PATH_OBJ): $(DIR_BUILD)/%.o: $(DIR_SRC)/%.c $(MAKEFILE_LIST)
$(PATH_OBJ): $(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	$(CC) $(FLAG_INCLUDE) $(FLAG_WARN) $(FLAG_MISC) $(CFLAGS) -c $< -o $@


# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html
$(PATH_DEP): $(DIR_BUILD)/%.d: $(DIR_SRC)/%.c
	$(CC) $(FLAG_INCLUDE) -MM -MT $(patsubst %.d,%.o,$@) $< -o $@

-include $(PATH_DEP)


$(PATH_TAG): $(PATH_SRC)
	ctags --tag-relative=never -R .


.PHONY: init
init:
	mkdir -p $(DIR_BUILD)
	mkdir -p $(DIR_INCLUDE)
	mkdir -p $(DIR_SRC)
	touch $(DIR_SRC)/$(FILE_MAIN)
	touch $(DIR_BUILD)/$(FILE_GIT_KEEP)
	touch $(FILE_GIT_IGNORE)
	git init


.PHONY: run
run:
	$(DIR_BUILD)/$(FILE_EXEC)


.PHONY: clean
clean:
	rm -rIv $(PATH_OBJ) $(PATH_DEP)


NDEBUG := \s*\#define\s\+NDEBUG\s*
.PHONY: is_not_debug
is_not_debug:
	sed -i 's;^\/\/\($(NDEBUG)\);\1;' $(PATH_DEBUG)

.PHONY: is_debug
is_debug:
	sed -i 's;^\($(NDEBUG)\);\/\/\1;' $(PATH_DEBUG)


DEF_DEBUG := \#\(define\|undef\) \(NDEBUG\|DEBUG_\)
.PHONY: print_debug_tag
print_debug_tag:
	grep -n -e '$(DEF_DEBUG)' $(DIR_INCLUDE)/$(FILE_DEBUG) | \
			sed 's;:;\t;' | sed 's;\s;\t;g'
