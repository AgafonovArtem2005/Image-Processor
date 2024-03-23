# Image processor

This is a simple console application. It allows you to apply various filters to images. Run main with 'image_processor' to find out more.

## Format of file

Input and output graphic files must be in BMP format. The application works with 24-bit BMP images without compression and color table. The `DIB header` must be `BITMAPINFOHEADER`.

## Command line argument format

To run this application you should write in the console:

`./image_processor {path to input file} {path to output file} [-{name of filter 1} [parameter of filter 1] [parameter of filter 2] ...] [-{name of filter 2} [parameter of filter 1] [parameter of filter 2] ...] ...`

If you run the application without any arguments, it will show you instructions.
