# seam-carving-dl-imagemagick

Seam Carving for DL using ImageMagick. This project performs rescaling into images through  seam carving (aka Liquid Rescale) using the ImageMagick implementation.


### Prerequisites

In order to perform the liquid rescale via ImageMagick, one must first install the [Liquid Rescale library](http://liblqr.wikidot.com) (LQR) prior to install [ImageMagick](http://www.imagemagick.org). Otherwise, after the ImageMagick installation you will not be able to perform such a resizing. 


Once you have installed all LQR and ImageMagick libraries, go to the makefile and update the following variables to reflect the libraries' location on your machine.

```
MAGICK_LIB_NAME = Magick++-7.Q16HDRI
MAGICK_CORE_LIB_NAME = "MagickCore-7.Q16HDRI"
MAGICK_WAND_LIB_NAME = "MagickWand-7.Q16HDRI"
MAGICK_LIB_PATH = "/usr/local/lib/"
MAGICK_LIB_INCLUDE_PATH = "/usr/local/include/ImageMagick-7"

LQR_LIB_NAME = "lqr-1"
LQR_LIB_PATH = "/opt/local/lib/"
LQR_LIB_INCLUDE_PATH = "/opt/local/include/lqr-1/"

```

### Usage

Just compile the project so you can run later.


```
make clean
make all

```

And run

```
./scdlmi
```


## Authors

* **Saulo Oliveira** - *Initial work* - [Saulo Oliveira](https://github.com/sauloafoliveira)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


