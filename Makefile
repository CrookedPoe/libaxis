
CFLAGS = -c -Iinclude -D__LA_STANDALONE__ -Os -lm
MFLAGS = -c -Iinclude -D__LA_STANDALONE__ -Os -DMIPS -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -mno-memcpy

obj := $(patsubst %.c,%.o,$(wildcard src/*.c))
out := $(wildcard src/*.o)

default: clean
	@echo "Choose target! (setup, x64 or mips)"

setup:
	@mkdir build
	@mkdir build/x64
	@mkdir build/mips
	@mkdir dist
	@mkdir dist/x64
	@mkdir dist/mips
	@echo "Made build and dist directories..."

x64: $(obj)
	@gcc $(CFLAGS) -o x64 $(obj)
	@find src -name "*.o" -exec mv "{}" build/x64 \;
	@ar rcs dist/x64/libaxis.a build/x64/*.o

mips: $(obj)
	@mips64-gcc $(MFLAGS) -o mips $(obj)
	@find src -name "*.o" -exec mv "{}" build/mips \;
	@mips64-ar rcs dist/mips/libaxis.a build/mips/*.o

release:
	@zip -r libaxis.zip dist
	@rm -rf build dist

clean:
	@rm -rf build dist