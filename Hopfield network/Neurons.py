from ImageWeights import ImageWeights
from math import sqrt
import numpy as np

MAX_COUNT_RATE = 5


class Neurons:
    def __init__(self, length, filler):
        self.length = length
        self.outputs = [filler for i in range(length)]
        self.weights = ImageWeights(length)

    def teach(self, image):
        self.weights.weights_recount(image)

    def recognize(self, image):
        counter = 0
        tmp = image
        while counter < MAX_COUNT_RATE:
            tmp = self._signum(tmp)
            tmp = np.dot(self.weights.get_weights_matrix(), tmp)
            counter += 1
            if counter == MAX_COUNT_RATE:
                break
        return self._signum(tmp)

    def _signum(self, value):
        for i in range(len(value)):
            if value[i] < 0:
                value[i] = -1
            else:
                value[i] = 1
        return value

    def print_synapses_as_abstract(self):
        values = [' ' for i in range(len(self.outputs))]
        for i in range(len(values)):
            if self.outputs[i] == 1:
                values[i] = '*'
        print()
        m = int(sqrt(self.length))
        for i in range(m):
            print(values[i * m + 0],
                  values[i * m + 1],
                  values[i * m + 2],
                  values[i * m + 3],
                  values[i * m + 4],
                  values[i * m + 5],
                  values[i * m + 6],
                  values[i * m + 7],
                  values[i * m + 8],
                  values[i * m + 9])

    def print_synapses_values(self):
        m = int(sqrt(self.length))
        for i in range(m):
            print(self.outputs[i * m + 0],
                  self.outputs[i * m + 1],
                  self.outputs[i * m + 2],
                  self.outputs[i * m + 3],
                  self.outputs[i * m + 4],
                  self.outputs[i * m + 5],
                  self.outputs[i * m + 6],
                  self.outputs[i * m + 7],
                  self.outputs[i * m + 8],
                  self.outputs[i * m + 9])
