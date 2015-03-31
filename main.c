#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "generator.h"
#include "analizator.h"

char *usage =
  "Usage: %s -s spline-file [-p points-file] [ -g gnuplot-file [-f from_x -t to_x -n n_points ] ]\n"
  "            if points-file is given then\n"
  "               reads discrete 2D points from points-file\n"
  "               writes spline approximation to spline-file\n"
  "               - number of points should be >= 4\n"
  "            else (points-file not given)\n"
  "               reads spline from spline-file\n"
  "            endfi\n"
  "            if gnuplot-file is given then\n"
  "               makes table of n_points within <from_x,to_x> range\n"
  "               - from_x defaults to x-coordinate of the first point in points-file,\n"
  "               - to_x defaults to x-coordinate of the last point\n"
  "               - n_points defaults to 100\n"
  "               - n_points must be > 1\n"
  "            endif\n";

int main (int argc, char ** argv){
  int opt;
  char *inp = NULL;
  char *out = NULL;
  char *gpt = NULL;
  double fromX = 0;
  double toX = 0;
  int n = 100;
	char *progname= argv[0];
	int aprox = 0;

  points_t pts;
  spline_t spl;

  pts.n = 0;
  spl.n = 0;

  while ((opt = getopt (argc, argv, "p:s:g:f:t:n:a:")) != -1) {
    switch (opt) {
    case 'p':
      inp = optarg;
      break;
    case 's':
      out = optarg;
      break;
    case 'g':
      gpt = optarg;
      break;
    case 'f':
      fromX = atof (optarg);
      break;
    case 't':
      toX = atof (optarg);
      break;
    case 'n':
      n = atoi (optarg);
      break;
    case 'a':
      aprox = atoi (optarg);
      break;
    default:                   /* '?' */
      fprintf (stderr, usage, progname);
      exit (EXIT_FAILURE);
    }
};