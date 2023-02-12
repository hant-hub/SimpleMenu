import cv2
import os
import sys
import numpy as np
import math
import matplotlib.pyplot as plt
import glob




def CreateSheet(folder, name, dest):
	files = glob.glob(folder + "/*.png")
	files.sort()
	rawimages = []
	scaledimages = []

	for img in files:
		rawimages.append(cv2.imread(img))


	size = int(min([val for img in rawimages for val in img.shape[:2]]))

	for img in rawimages:
		scaledimages.append(cv2.resize(img, (size, size), interpolation = cv2.INTER_AREA))


	dimy = int(len(scaledimages) ** 0.5)
	dimx = int(len(scaledimages)/dimy)


	output = np.zeros((dimy * size, dimx * size, 3), np.float32)

	for index, img in enumerate(scaledimages):
		column = index%dimx
		row = math.floor(index/dimx)

		T = np.float32([[1,0, size*column], [0,1, size*row]])
		new = cv2.warpAffine(img, T, (dimx * size, dimy * size)).astype(np.float32)

		output = cv2.addWeighted(output, 1, new, 1, 0)




	os.chdir(dest)

	cv2.imwrite(name, output)

	os.chdir("..")


def main():

	source, dest, name = sys.argv[1], sys.argv[2], sys.argv[3]

	dirs = [name for name in os.listdir(source) if os.path.isdir(os.path.join(source, name))]
	print(dirs)
	for folder in dirs:
		CreateSheet(os.path.join(source, folder), folder + ".png", dest)
	







if __name__ == "__main__":
	main()