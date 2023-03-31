function BW = cannyDetection(outputImg)
BW = double(edge(outputImg, 'canny'));