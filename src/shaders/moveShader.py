import os
import sys
import shutil






def main():

	source, dest, name = sys.argv[1], sys.argv[2], sys.argv[3]

	dirs = [name for name in os.listdir(source) if os.path.isdir(os.path.join(source, name))]
	print(dirs)
	
	shutil.rmtree(dest)
	for folder in dirs:
		shutil.copytree(source + "/" + folder, dest + "/" + folder)
	







if __name__ == "__main__":
	main()
