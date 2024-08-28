all: core.o

TARGET = torus
TYPE = ps-exe

SRCS = \
torus.cpp \

CXXFLAGS = -std=c++20

LDFLAGS += -Wl,-wrap,memcpy -Wl,-wrap,memset

include ../third_party/nugget/psyqo/psyqo.mk

core.bin: $(TARGET).ps-exe
	../ps1-packer $< -raw -o $@

core.o: core.bin
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@
