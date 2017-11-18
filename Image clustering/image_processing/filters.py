from PIL import Image, ImageDraw


def minimum(pix, i, j, k):
    return min(pix[i, j][k],
               pix[i + 1, j][k],
               pix[i, j + 1][k],
               pix[i + 2, j][k],
               pix[i, j + 2][k],
               pix[i + 1, j + 1][k],
               pix[i + 2, j + 1][k],
               pix[i + 1, j + 2][k],
               pix[i + 2, j + 2][k])


def maximum(pix, i, j, k):
    return max(pix[i, j][k],
               pix[i + 1, j][k],
               pix[i, j + 1][k],
               pix[i + 2, j][k],
               pix[i, j + 2][k],
               pix[i + 1, j + 1][k],
               pix[i + 2, j + 1][k],
               pix[i + 1, j + 2][k],
               pix[i + 2, j + 2][k])


image1 = Image.open("/home/ilya/DSP/ilya.jpg")
image2 = Image.open("/home/ilya/DSP/ilya.jpg")
brush1 = ImageDraw.Draw(image1)
brush2 = ImageDraw.Draw(image2)
pix = image1.load()


def minfilter(image, brush, pixel):
    for i in range(image.size[0] - 2):
        for j in range(image.size[1] - 2):
            brush.point((i, j), fill=(
                minimum(pixel, i, j, 0),
                minimum(pixel, i, j, 1),
                minimum(pixel, i, j, 2)))


minfilter(image1, brush1, pix)
image1.save("/home/ilya/DSP/minFilter.jpg", "JPEG")
image1 = Image.open("/home/ilya/DSP/minFilter.jpg")
pix = image1.load()
brush1 = ImageDraw.Draw(image1)
pix2 = image2.load()

for i in range(image1.size[0] - 2):
    for j in range(image1.size[1] - 2):
        brush2.point((i, j), fill=(
            maximum(pix2, i, j, 0),
            maximum(pix2, i, j, 1),
            maximum(pix2, i, j, 2)))
        brush1.point((i, j), fill=(
            maximum(pix, i, j, 0),
            maximum(pix, i, j, 1),
            maximum(pix, i, j, 2)))

image2.save("/home/ilya/DSP/maxFilter.jpg", "JPEG")
image1.save("/home/ilya/DSP/minMaxFilter.jpg", "JPEG")

del brush1
del brush2
