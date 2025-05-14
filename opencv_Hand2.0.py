# for recording or capturing feed from
import cv2
import serial
# need for our hand detection
from cvzone.HandTrackingModule import HandDetector
# initialize our camera
cap = cv2.VideoCapture(0)
# set our hand tracking object
detector = HandDetector(detectionCon=0.8)
ser = serial.Serial('COM12', 9600)
# start our while loop
while True:
    success, image = cap.read()
    hands, bboxInfo = detector.findHands(image)
    if len(hands) == 1:
        data = detector.fingersUp(hands[0])+[0]
        data_string = ','.join(map(str, data))
        sentData = (data_string + '\n').encode()
        ser.write(sentData)
        print(sentData)
    cv2.imshow('image', image)
    cv2.waitKey(1)
