all: demo.ps-exe

core:
	$(MAKE) -C core

loader:
	$(MAKE) -C loader

clean:
	$(MAKE) -C core clean
	rm -f demo.ps-exe

demo.ps-exe: core loader
	cp loader/loader.ps-exe demo.ps-exe
#	ps1-packer loader/loader.ps-exe -o demo.ps-exe

.PHONY: clean core loader
