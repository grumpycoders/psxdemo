all: music-upload.o

TARGET = music
TYPE = ps-exe

SRCS = \
../third_party/nugget/common/crt0/crt0.s \
upload.c \
LittleCottonPillow-v260.smp \

include ../third_party/nugget/common.mk

music-upload.bin: $(TARGET).ps-exe
	../ps1-packer $< -raw -o $@

music-upload.o: music-upload.bin
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@

%.o: %.smp
	$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@
