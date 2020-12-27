build:
	gcc \
	./*.c \
	-lmingw32 \
  	-lSDL2main \
  	-lSDL2 \
	-lSDL2_image \
  	-o example.exe
