#include<opencv2/opencv.hpp>
#include<iostream>
#include<cstdio>

/**
 * A simple program that saves video frames to separate png files. 
 */
int main(int argc, char *argv[])
{
  /* name - a variable where program keeps the name. Be aware that too long name will lead to overflow and crash.
            It is only 80 characters long. */
  char name[80]; 
  int i = 0; 		/* integer which we will increment to create new names. We start at 0 */
  cv::Mat frame; 	/* A frame that we want to save (or show) */
  
  /* cap - here we declare a special object that represents our "capture" - it can be either a video file or camera */
  cv::VideoCapture cap("/home/mati/Projects/videos/big_buck_bunny_480p_surround-fix.avi");
  
  if(!cap.isOpened()) 	/* if there is an error with our capture, return 1 */
    return 1;
  
  cv::namedWindow("Frame"); /* a window to show a current frame */
  
  while(true) /* here is where magic happens :) */
  {
    cap >> frame; /* we grab a frame from capture object and assign it to frame. */
    cv::imshow("Frame",frame); /* show a frame in a window called "Frame" */
    sprintf(name,"test_%d.png",i); /* create a name in a form of test_XXX.png, where XXX is our integer. 
				   %d shows where to put the number. */
    cv::imwrite(name,frame); /* write the current frame to file with given name. */
    if(cv::waitKey(30) >= 0) break; /* if any key is pressed, then stop the loop and finish the program. */
  }
  return 0;
}