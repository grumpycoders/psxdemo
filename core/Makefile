all: core.o

TARGET = torus
TYPE = ps-exe

SRCS = \
torus.cpp \
LittleCottonPillow-v260.hit \
../third_party/nugget/modplayer/modplayer.c \

CXXFLAGS = -std=c++20

LDFLAGS += -Wl,-wrap,memcpy -Wl,-wrap,memset
LDFLAGS += -Xlinker --defsym=TLOAD_ADDR=0x80001000

include ../third_party/nugget/psyqo/psyqo.mk

core.bin: $(TARGET).ps-exe
	../ps1-packer $< -raw -nokernel -resetstack -o $@

core.o: core.bin
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@

%.o: %.hit
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@
