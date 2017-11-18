import os
from Neurons import Neurons
from HopfieldImage import HopfieldImage
from PIL import Image
import sys


def main(imageName):
    path = os.getcwd()
    image = [[-1, -1, 1, 1, 1, 1, 1, 1, 1, -1,
              -1, -1, 1, 1, 1, 1, 1, 1, 1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1,
              -1, -1, 1, 1, -1, -1, -1, -1, -1, -1],  # G
             [-1, 1, 1, -1, -1, -1, -1, -1, 1, 1,
              -1, 1, 1, 1, -1, -1, -1, 1, 1, 1,
              -1, 1, 1, 1, 1, -1, 1, 1, 1, 1,
              -1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
              -1, 1, 1, -1, 1, 1, 1, -1, 1, 1,
              -1, 1, 1, -1, -1, 1, -1, -1, 1, 1,
              -1, 1, 1, -1, -1, -1, -1, -1, 1, 1,
              -1, 1, 1, -1, -1, -1, -1, -1, 1, 1,
              -1, 1, 1, -1, -1, -1, -1, -1, 1, 1,
              -1, 1, 1, -1, -1, -1, -1, -1, 1, 1],  # M
             [-1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
              -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
              -1, -1, 1, 1, -1, -1, 1, 1, -1, -1,
              -1, -1, 1, 1, 1, 1, 1, 1, -1, -1,
              -1, -1, 1, 1, 1, 1, 1, 1, -1, -1,
              -1, -1, -1, -1, -1, -1, 1, 1, -1, -1,
              -1, -1, -1, -1, -1, -1, 1, 1, -1, -1,
              -1, -1, -1, -1, -1, -1, 1, 1, -1, -1,
              -1, -1, 1, 1, 1, 1, 1, 1, -1, -1,
              -1, -1, 1, 1, 1, 1, 1, 1, -1, -1]]  # Y
    t_img = Image.open(path + "/hopfield/" + imageName)
    test_img = HopfieldImage(t_img)
    test = test_img.convert_to_bin()
    print(len(image[0]))
    neurons = Neurons(len(image[0]), -1)
    for i in range(len(image)):
        neurons.teach(image[i])
    tst = neurons.recognize(test)
    new_img = Image.new('L', (10, 10), 0)
    obj_list = []
    print(tst)
    for i in range(10):
        for j in range(10):
            if tst[i * 10 + j] == 1:
                tst[i * 10 + j] = 0
            else:
                tst[i * 10 + j] = 255
            #new_img.putpixel((i, j), tst[i * 10 + j])
            obj_list.append(tst[i * 10 + j])
    new_img.putdata(obj_list)
    new_img.show()


if __name__ == "__main__":
    imageName = "g_4.png"
    if(len(sys.argv) == 2):
        imageName = sys.argv[1]
    main(imageName)
