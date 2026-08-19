# Optional argument for `make run`
f ?=

# Package directory name
d ?= array/easy/sorted3

MOD_NAME := github.com/Bozar/data-structures-and-algorithms/geeks

FILE_MAIN := main.go
FILE_SRC := ...
FILE_EXE_LINUX := prog
FILE_EXE_WIN := prog.exe
FILE_GIT_KEEP := .gitkeep
FILE_GIT_IGNORE := .gitignore
FILE_TAGS := tags

DIR_BUILD := ./build
DIR_SRC := ./src
DIR_HIDDEN := $(DIR_SRC)/_
DIR_SHARE := ~/share
DIR_TAGS := ~/tags/geeks

PATH_MAIN := $(addprefix ./,$(FILE_MAIN))
PATH_SRC := $(addprefix $(DIR_SRC)/,$(FILE_SRC))
PATH_EXE_LINUX := $(addprefix $(DIR_BUILD)/,$(FILE_EXE_LINUX))
PATH_EXE_WIN := $(addprefix $(DIR_SHARE)/,$(FILE_EXE_WIN))
PATH_GIT_IGNORE := $(addprefix ./,$(FILE_GIT_IGNORE))
PATH_TAGS := $(addprefix $(DIR_TAGS)/,$(FILE_TAGS))

ARG_WIN := GOOS=windows GOARCH=amd64

CMD_LS_HIDDEN := printf "_: " && ls --color -p $(DIR_HIDDEN)
CMD_LS_SRC := printf "src: " && ls --color -p $(DIR_SRC)

.PHONY: all fmt vet test linux win tag \
		init npack nfile run clean show hide unhide

all: fmt vet test linux tag run

fmt:
	go fmt $(PATH_MAIN)
	go fmt $(PATH_SRC)
	go mod tidy

vet:
	go vet $(PATH_MAIN)
	go vet $(PATH_SRC)
	go-staticcheck $(PATH_MAIN)
	go-staticcheck $(PATH_SRC)

test:
	go test $(PATH_SRC)

tag:
	mkdir -p $(DIR_TAGS)
	ctags -f $(PATH_TAGS) --tag-relative=never -R .

linux:
	go build -o $(PATH_EXE_LINUX)

win:
	$(ARG_WIN) go build -o $(PATH_EXE_WIN)

init:
	mkdir -p $(DIR_TAGS)
	mkdir -p $(DIR_BUILD)
	mkdir -p $(DIR_SRC)
	mkdir -p $(DIR_HIDDEN)
	touch $(DIR_BUILD)/$(FILE_GIT_KEEP)
	touch $(DIR_HIDDEN)/$(FILE_GIT_KEEP)
	touch $(PATH_GIT_IGNORE)
	touch $(PATH_MAIN)
	go mod init $(MOD_NAME)
	git init

npack:
	mkdir -p $(DIR_SRC)/$(d)
	touch $(DIR_SRC)/$(d)/$(notdir $(d)).go
	touch $(DIR_SRC)/$(d)/$(notdir $(d))_test.go

nfile:
	mkdir -p $(DIR_SRC)/$(dir $(d))
	touch $(DIR_SRC)/$(dir $(d))$(notdir $(d)).go
	touch $(DIR_SRC)/$(dir $(d))$(notdir $(d))_test.go

run:
	$(PATH_EXE_LINUX) $(f)

clean:
	rm -rIv $(PATH_EXE_LINUX) $(PATH_EXE_WIN)

show:
	@$(CMD_LS_HIDDEN)
	@$(CMD_LS_SRC)

hide:
	@cd $(DIR_SRC) && mv $(d) ./_
	@$(CMD_LS_HIDDEN)
	@$(CMD_LS_SRC)

unhide:
	@cd $(DIR_HIDDEN) && mv $(d) ../
	@$(CMD_LS_HIDDEN)
	@$(CMD_LS_SRC)
