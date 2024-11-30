all: demo.ps-exe

core:
	$(MAKE) -C core

loader: core music
	$(MAKE) -C loader

music:
	$(MAKE) -C music

clean:
	$(MAKE) -C core clean
	rm -f demo.ps-exe
	$(MAKE) -C loader clean
	$(MAKE) -C music clean

demo.ps-exe: core loader
	cp loader/loader.ps-exe demo.ps-exe
#	ps1-packer loader/loader.ps-exe -o demo.ps-exe

.PHONY: clean core loader music
