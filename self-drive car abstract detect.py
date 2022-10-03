import cv2 as cv
import numpy as np
cap = cv.VideoCapture(0)
while(1):
    # Take each frame
    _, frame = cap.read()
    # Convert BGR to HSV
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    # define range of blue color in HSV
    lower_red = np.array([-10, 100, 100])
    upper_red = np.array([10, 255, 255])
    # Threshold the HSV image to get only blue colors
    mask = cv.inRange(hsv, lower_red, upper_red)
    # Bitwise-AND mask and original image
    green_lower = np.array([35, 43, 46])
    green_upper = np.array([77, 255, 255])
    mask = cv.inRange(hsv, green_lower, green_upper)
    res = cv.bitwise_and(frame,frame, mask= mask)
    cv.imshow('frame',frame)
    cv.imshow('mask',mask)
    cv.imshow('res',res)
    contours,hierarchy =cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
if Ien(contours) !=0:
    for contour in contours:
        if cv2.contourArea(contour)>500:
            x,y,w,h =cv2.boundingRect(contour)
            cv2.rectangle(img, (x,y),(x + w,y+h),(0,0,255),3)
    k = cv.waitKey(5) & 0xFF
    if k == 27:
        break
cv.destroyAllWindows()