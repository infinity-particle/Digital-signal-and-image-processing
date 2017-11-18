import matplotlib.pyplot as plt
from matplotlib import gridspec
import numpy as np
from scipy import ndimage, stats as st
import random
import sys

def remove_ticks(*axes):
    for axis in axes:
        axis.tick_params(axis='both', which='both', length=0)
        axis.set_xticklabels([])
        axis.set_yticklabels([])
	
def show_info(image, slicedImage):
        gs1 = gridspec.GridSpec(2, 2, width_ratios=[1, 1], height_ratios=[4, 1])
        gs1.update(left=0.05, wspace=0.005)
        ax1 = plt.subplot(gs1[-1, :])
        ax2 = plt.subplot(gs1[:-1, :-1])
        ax3 = plt.subplot(gs1[:-1, -1])
            
        remove_ticks(ax2, ax3)

        hist_args = dict(alpha=0.5, bins=50, range=[0, 255], normed=True)
        ax1.hist(image.ravel(), label='Before', color='b', **hist_args)
        ax1.hist(slicedImage.ravel(), label='After', color='g', **hist_args)
        ax1.legend(loc='best')

        ax2.set_xlabel('Before')
        ax2.imshow(image, plt.cm.gray)

        ax3.set_xlabel('After')
        ax3.imshow(slicedImage, plt.cm.gray)

        plt.show()

def sobel(image):
	sobelx = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]], dtype = np.float)
	sobely = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]], dtype = np.float)


	N = image.shape[0] #row 
	M = image.shape[1] #column


	row = 512
	column = 512
	sobelxImage = np.zeros((N,M))
	sobelyImage = np.zeros((N,M))
	sobelGrad = np.zeros((N,M))

	image = np.pad(image, (1,1), 'edge')

	for i in range(1, N-1):
		for j in range(1, M-1):
			gx = (sobelx[0][0] * image[i-1][j-1]) + (sobelx[0][1] * image[i-1][j]) + \
             (sobelx[0][2] * image[i-1][j+1]) + (sobelx[1][0] * image[i][j-1]) + \
             (sobelx[1][1] * image[i][j]) + (sobelx[1][2] * image[i][j+1]) + \
             (sobelx[2][0] * image[i+1][j-1]) + (sobelx[2][1] * image[i+1][j]) + \
             (sobelx[2][2] * image[i+1][j+1])

			gy = (sobely[0][0] * image[i-1][j-1]) + (sobely[0][1] * image[i-1][j]) + \
             (sobely[0][2] * image[i-1][j+1]) + (sobely[1][0] * image[i][j-1]) + \
             (sobely[1][1] * image[i][j]) + (sobely[1][2] * image[i][j+1]) + \
             (sobely[2][0] * image[i+1][j-1]) + (sobely[2][1] * image[i+1][j]) + \
             (sobely[2][2] * image[i+1][j+1])     

			sobelxImage[i-1][j-1] = gx
			sobelyImage[i-1][j-1] = gy

			g = np.sqrt(gx * gx + gy * gy)
			sobelGrad[i-1][j-1] = g
	return sobelGrad


if __name__ == "__main__":
	image = ndimage.imread ("image.jpg", mode='L');
	
	sobelImage = sobel(image)
	
	show_info(image, sobelImage)
