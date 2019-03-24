
MAGICK_LIB_NAME = Magick++-7.Q16HDRI
MAGICK_CORE_LIB_NAME = MagickCore-7.Q16HDRI
MAGICK_WAND_LIB_NAME = MagickWand-7.Q16HDRI
MAGICK_LIB_INCLUDE_PATH = /usr/local/include/ImageMagick-7

LQR_LIB_NAME = lqr-1.0
LQR_LIB_INCLUDE_PATH = /opt/local/include/

LIBS = -l$(MAGICK_CORE_LIB_NAME) -l$(MAGICK_CORE_LIB_NAME) -l$(MAGICK_WAND_LIB_NAME) -l$(LQR_LIB_NAME)
PATH = -L$(MAGICK_INCLUDE_PATH) -L$(/opt/local/lib/)
INCLUDE_PATH = -I$(MAGICK_LIB_INCLUDE_PATH) -I$(LQR_LIB_INCLUDE_PATH)


CC = /usr/bin/g++
	
clean:
	rm -rf scdlmi scdlmi.o scdlmi.exe
	
all:
	@echo 'Building file: $<'
	$(CC) scdlmi.cpp -o "scdlmi" $(INCLUDE_PATH) $(PATH) $(LIBS) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP
	@echo 'Finished building: $<'
	@echo ' ' 
	