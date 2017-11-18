from image_processing.imagework import ImagePreHandling, ImageObjectDetector


def main():
    source = 'P0001470.jpg'
    output = 'binary1.jpg'
    binarizator = ImagePreHandling(source)
    binarizator._show()
    binarizator._min_filter()
    binarizator._convert_to_bin()
    binarizator._med_filter()
    binarizator._convert_to_bin()
    binarizator._save(output)
    binarizator._show()
    detector = ImageObjectDetector(binarizator._getimage())
    detector._labeling()
    detector._get_objects_number()
    detector._get_squares()
    detector._get_perimeters()
    detector._get_densities()
    detector._colorize()
    detector._kmeans()
    detector._colorize_clusters()
    detector._show()

if __name__ == "__main__":
    main()
