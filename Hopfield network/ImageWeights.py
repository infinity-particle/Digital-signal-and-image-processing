import numpy as np


class ImageWeights:
    def __init__(self, length):
        self.w = [[0 for j in range(length)] for i in range(length)]

    def weights_recount(self, hopfield_image):
        ar = np.array(hopfield_image)
        tar = ar.reshape(len(ar), 1)
        result = ar * tar
        for i in range(len(result)):
            for j in range(len(result[0])):
                if i != j:
                    self.w[i][j] += result[i][j]

    def get_weight(self, x, y):
        return self.w[x][y]

    def print_weights_matrix(self):
        print(self.w)

    def get_weights_matrix(self):
        return self.w
