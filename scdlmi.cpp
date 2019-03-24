/*
 * main.cpp
 *
 *  Created on: 21 de mar de 2019
 *      Author: sauloafoliveira
 */

#include <iostream>
#include <Magick++.h>
#include <string>
#include <dirent.h>  // compatibility with windows :)
#include <algorithm>

using namespace std;
using namespace Magick;

bool hasEnding(std::string const &fullString, std::string const &ending);
int run_on_each_file_of(const string &directory, const Geometry& newScale);
void liquid_rescale(const string &filename, const Geometry& newScale);

bool is_image(const string &filename);

/***
 * Code taken from https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
 *
 */

int run_on_each_file_of(const string &directory, const Geometry& newScale) {
	DIR *dir;
	struct dirent *ent;

	std::vector<std::string> files;

	if ((dir = opendir(directory.c_str())) != NULL) {
		/* get all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			files.push_back(ent->d_name);
		}

		closedir(dir);

		/*  process all files */
		for(std::string &file : files) {
			liquid_rescale(file, newScale);
		}

	} else {
		/* could not open directory */
		perror("Could not open directory");
		return EXIT_FAILURE;
	}
	return 0;
}


/***
 * https://stackoverflow.com/questions/874134/find-out-if-string-ends-with-another-string-in-c
 * */
bool hasEnding(std::string const &fullString, std::string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0
				== fullString.compare(fullString.length() - ending.length(),
						ending.length(), ending));
	} else {
		return false;
	}
}

bool is_image(const string &sr) {
	string data = sr;

	std::transform(data.begin(), data.end(), data.begin(), ::tolower);

	return hasEnding(data, ".jpg") || hasEnding(data, ".png")
			|| hasEnding(data, ".gif");
}

void liquid_rescale(std::string const &filename, const Geometry& newScale) {
	if (is_image(filename)) {
		std::cout << "Processing: " << filename << std::endl;

		// Construct the image object. Separating image construction from the
		// the read operation ensures that a failure to read the image file
		// doesn't render the image object useless.
		Image image;
		try {
			// Read a file into image object
			image.read(filename);

			image.liquidRescale(newScale);

			// Crop the image to specified size (width, height, xOffset, yOffset)

			// Write the image to a file
			image.write("rescaled_" + filename);
		} catch (Exception &error_) {
			std::cout << "Caught exception: " << error_.what() << std::endl;
		}


	}

}

int main(int argc, char **argv) {

	std::cout << "Liquid Rescale for DL program" << std::endl;

	std::cout << "Type the desired resolution (height)x(width)!. " << std::endl;

	std::cout << "Example: 100x200! means to resize the images to have width = 200 and height = 100." << std::endl;

	InitializeMagick(*argv);

	std::string in;
	std::cin >> in;

	std::cout << "Type the desired folder to scan: " << std::endl;

	std::string folder;
	std::cin >> folder;

	if (folder.size() == 0) {
		folder = ".";
	}

	run_on_each_file_of(folder, Geometry(in));

	return 0;
}
