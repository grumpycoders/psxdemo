TARGET = loader
TYPE = ps-exe

SRCS = \
loader.c \
font.tex \
splash.tex \
../third_party/nugget/common/crt0/crt0.s \
../core/core.o \
../music/music-upload.o \

LDFLAGS += -Xlinker --defsym=TLOAD_ADDR=0x80100000

include ../third_party/nugget/common.mk

%.o: %.tex
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@
