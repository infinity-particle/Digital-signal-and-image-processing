class HopfieldImage:
    def __init__(self, image):
        self.image = image
        self.width = image.size[0]
        self.height = image.size[1]
        self.labels = [[0] * self.height for i in range(self.width)]

    def convert_to_bin(self):
        self.image = self.image.convert('L')
        for i in range(self.width):
            for j in range(self.height):
                if self.image.getpixel((i, j)) < 150:
                    self.labels[j][i] = 1
                else:
                    self.labels[j][i] = -1
        tmp = self.labels[0]
        for i in range(1, len(self.labels)):
            tmp.extend(self.labels[i])
        return tmp

    def get_labels(self):
        return self.labels
