import matplotlib.pyplot as plt
from matplotlib import gridspec
import numpy as np
from scipy import ndimage, stats as st
import random
import sys

def binarization(image,  threshold):
	h, l, p = image.shape
	binaryImage = image.copy()
	
	for i in range(0, h):
		for j in range(0, l):
			for k in range(0, p):
				binaryImage[i][j][k] = 255 if binaryImage[i][j][k] > threshold else 0
	return binaryImage

def remove_ticks(*axes):
    for axis in axes:
        axis.tick_params(axis='both', which='both', length=0)
        axis.set_xticklabels([])
        axis.set_yticklabels([])
	
def show_info(image, binaryImage):
        gs1 = gridspec.GridSpec(2, 2, width_ratios=[1, 1], height_ratios=[4, 1])
        gs1.update(left=0.05, wspace=0.005)
        ax1 = plt.subplot(gs1[-1, :])
        ax2 = plt.subplot(gs1[:-1, :-1])
        ax3 = plt.subplot(gs1[:-1, -1])
            
        remove_ticks(ax2, ax3)

        hist_args = dict(alpha=0.5, bins=50, range=[0, 255], normed=True)
        ax1.hist(image.ravel(), label='Before', color='b', **hist_args)
        ax1.hist(binaryImage.ravel(), label='After', color='g', **hist_args)
        ax1.legend(loc='best')

        props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
                
        image1_props = dict(props, edgecolor='b')

        image2_props = dict(props, edgecolor='g')

        ax2.set_xlabel('Before')
        ax2.imshow(image, plt.cm.gray)

        ax3.set_xlabel('After')
        ax3.imshow(binaryImage, plt.cm.gray)

        plt.show()
	
	
if __name__ == "__main__":
	image = ndimage.imread("image.jpg", mode='RGB')
	
	if (len(sys.argv) == 2):
		binaryImage = binarization(image, int(sys.argv[1]))
	else:
		binaryImage = binarization(image, 156)
		
	show_info(image, binaryImage)
