TARGET = loader
TYPE = ps-exe

SRCS = \
loader.c \
texture.tex \
../third_party/nugget/common/crt0/crt0.s \
../core/core.o \

LDFLAGS += -Xlinker --defsym=TLOAD_ADDR=0x80100000

include ../third_party/nugget/common.mk

texture.o: texture.tex
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=16 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@
