from PIL import Image, ImageDraw

RCOEF = 0.2126
GCOEF = 0.7152
BCOEF = 0.0722
_MAX = 255;
_MIN = 0;

image1 = Image.open("/home/ilya/DSP/Dima.jpg")
image2 = Image.open("/home/ilya/DSP/Dima.jpg")
brush1 = ImageDraw.Draw(image1)
brush2 = ImageDraw.Draw(image2)
pix = image1.load()
#
#
# pixels = list(image1.getdata())
# width, height = image1.size
# pixels = [pixels[i * width:(i + 1) * width] for i in range(height)]
# plt.hist(pixels)
# plt.show()

max_v = int(input("Max: "))
min_v = int(input("Min: "))

for i in range(image1.size[0]):
    for j in range(image1.size[1]):
        r = pix[i, j][0]
        g = pix[i, j][1]
        b = pix[i, j][2]

        brush1.point((i, j),
                     (max(_MIN, r - min_v),
                      max(_MIN, g - min_v),
                      max(_MIN, b - min_v)))
        brush2.point((i, j),
                     (min(_MAX, r + min_v),
                      min(_MAX, g + min_v),
                      min(_MAX, b + min_v)))

image1.save("/home/ilya/DSP/algV.jpg", "JPEG")
image2.save("/home/ilya/DSP/algG.jpg", "JPEG")
#
# pixels = list(image1.getdata())
# width, height = image1.size
# pixels = [pixels[i * width:(i + 1) * width] for i in range(height)]
# plt.hist(pixels)
# plt.show()
#
# pixels = list(image2.getdata())
# pixels = [pixels[i * width:(i + 1) * width] for i in range(height)]
# plt.hist(pixels)
# plt.show()

del brush1
del brush2
