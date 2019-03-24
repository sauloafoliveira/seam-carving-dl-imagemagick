
MAGICK_LIB_NAME = Magick++-7.Q16HDRI
MAGICK_CORE_LIB_NAME = "MagickCore-7.Q16HDRI"
MAGICK_WAND_LIB_NAME = "MagickWand-7.Q16HDRI"
MAGICK_LIB_PATH = "/usr/local/lib/"
MAGICK_LIB_INCLUDE_PATH = "/usr/local/include/ImageMagick-7"

LQR_LIB_NAME = "lqr-1"
LQR_LIB_PATH = "/opt/local/lib/"
LQR_LIB_INCLUDE_PATH = "/opt/local/include/lqr-1/"

LIBS = -l$(MAGICK_LIB_NAME) -l$(MAGICK_CORE_LIB_NAME) -l$(MAGICK_WAND_LIB_NAME) -l$(LQR_LIB_NAME)
LIB_INCLUDE_PATH = -L$(MAGICK_LIB_PATH) -L$(LQR_LIB_PATH)  
LIBS_INCLUDE_PATH = -I$(MAGICK_LIB_INCLUDE_PATH)  -I$(LQR_LIB_INCLUDE_PATH) 


CC = /usr/bin/g++
	
clean:
	rm -rf scdlmi scdlmi.o scdlmi.exe
	
all:
	$(CC) scdlmi.cpp $(LIBS_INCLUDE_PATH) $(LIB_INCLUDE_PATH) $(LIBS) -O0 -g3 -Wall -fmessage-length=0 -o "scdlmi" 

